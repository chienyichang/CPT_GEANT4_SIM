#ifndef ROOT_TREE_VECTOR_LINKDEF_H 
#define ROOT_TREE_VECTOR_LINKDEF_H 1

#ifdef __CINT__
#include <vector>
#pragma link off all classes;

#pragma link C++ class trackData+;
#pragma link C++ class std::vector<trackData>+;
#pragma link C++ class stepData+;
#pragma link C++ class std::vector<stepData>+;

#endif

#endif // ROOT_TREE_VECTOR_LINKDEF_H

