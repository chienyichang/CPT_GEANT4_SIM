#----------------------------------------------------------------------------
# Setup the project
cmake_minimum_required(VERSION 2.6 FATAL_ERROR)
project(LXe)

#----------------------------------------------------------------------------
# Find Geant4 package, activating all available UI and Vis drivers by default
# You can set WITH_GEANT4_UIVIS to OFF via the command line or ccmake/cmake-gui
# to build a batch mode only executable
#
option(WITH_GEANT4_UIVIS "Build example with Geant4 UI and Vis drivers" ON)
if(WITH_GEANT4_UIVIS)
  find_package(Geant4 REQUIRED ui_all vis_all)
else()
  find_package(Geant4 REQUIRED)
endif()

# Load some basic macros which are needed later on
include(FindROOT.cmake)

# set everything needed for the root dictonary and create the
# dictionary
set(LXe_LINKDEF LXeLinkDef.h )
set(LXe_DICTIONARY ${CMAKE_CURRENT_BINARY_DIR}/LXeDict.cxx) 
ROOT_GENERATE_DICTIONARY("../include/Data.hh" "${LXe_LINKDEF}" "${LXe_DICTIONARY}" "${INCLUDE_DIRECTORIES}")

# add the dictionary to the list of source files
SET(LXe_SRCS ${LXe_DICTIONARY}) 


#----------------------------------------------------------------------------
# Setup Geant4 include directories and compile definitions
#
include(${Geant4_USE_FILE})

#----------------------------------------------------------------------------
# Find ROOT (required package)
#
find_package(ROOT QUIET)
if(NOT ROOT_FOUND)
	  message(STATUS "G4 Examples: ROOT package not found. --> AnaEx02 example disabled")
	    return()
    endif()

#----------------------------------------------------------------------------
# Locate sources and headers for this project
#
include_directories(${PROJECT_SOURCE_DIR}/include 
	            ${ROOT_INCLUDE_DIR}
                    ${Geant4_INCLUDE_DIR})
file(GLOB sources ${PROJECT_SOURCE_DIR}/src/*.cc)
file(GLOB headers ${PROJECT_SOURCE_DIR}/include/*.hh)

# set everything needed for the root dictonary 
set(LXe_LINKDEF LXeLinkDef.h)
set(LXe_DICTIONARY ${CMAKE_CURRENT_BINARY_DIR}/LXeDict.cxx)

# add the dictionary to the list of source files
SET(LXe_SRCS ${LXe_DICTIONARY})

#----------------------------------------------------------------------------
# Add the executable, and link it to the Geant4 libraries
#
add_executable(LXe LXe.cc ${LXe_SRCS} ${sources} ${headers})
target_link_libraries(LXe ${Geant4_LIBRARIES} ${ROOT_LIBRARIES})

#----------------------------------------------------------------------------
# Copy all scripts to the build directory, i.e. the directory in which we
# build LXe. This is so that we can run the executable directly because it
# relies on these scripts being in the current working directory.
#
set(LXe_SCRIPTS
    cerenkov.mac defaults.mac LXe.in LXe.out photon.mac reviewEvent.mac vis.mac wls.mac
  )

foreach(_script ${LXe_SCRIPTS})
  configure_file(
    ${PROJECT_SOURCE_DIR}/${_script}
    ${PROJECT_BINARY_DIR}/${_script}
    COPYONLY
    )
endforeach()

#----------------------------------------------------------------------------
# Install the executable to 'bin' directory under CMAKE_INSTALL_PREFIX
#
install(TARGETS LXe DESTINATION bin)

