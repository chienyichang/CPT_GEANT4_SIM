//
// ********************************************************************
// * License and Disclaimer                                           *
// *                                                                  *
// * The  Geant4 software  is  copyright of the Copyright Holders  of *
// * the Geant4 Collaboration.  It is provided  under  the terms  and *
// * conditions of the Geant4 Software License,  included in the file *
// * LICENSE and available at  http://cern.ch/geant4/license .  These *
// * include a list of copyright holders.                             *
// *                                                                  *
// * Neither the authors of this software system, nor their employing *
// * institutes,nor the agencies providing financial support for this *
// * work  make  any representation or  warranty, express or implied, *
// * regarding  this  software system or assume any liability for its *
// * use.  Please see the license in the file  LICENSE  and URL above *
// * for the full disclaimer and the limitation of liability.         *
// *                                                                  *
// * This  code  implementation is the result of  the  scientific and *
// * technical work of the GEANT4 collaboration.                      *
// * By using,  copying,  modifying or  distributing the software (or *
// * any work based  on the software)  you  agree  to acknowledge its *
// * use  in  resulting  scientific  publications,  and indicate your *
// * acceptance of all terms of the Geant4 Software license.          *
// ********************************************************************
//
/// \file optical/LXe/LXe.cc
/// \brief Main program of the optical/LXe example
//
#include "G4RunManager.hh"
#include "G4UImanager.hh"
#include "G4String.hh"

#include "LXeDetectorConstruction.hh"
#include "LXePhysicsList.hh"
#include "LXePrimaryGeneratorAction.hh"
#include "LXeEventAction.hh"
#include "LXeStackingAction.hh"
#include "LXeSteppingAction.hh"
#include "LXeTrackingAction.hh"
#include "LXeRunAction.hh"
#include "LXeSteppingVerbose.hh"
#include "HistoManager.hh"
#include "HistoMessenger.hh"

#include "LXeRecorderBase.hh"

#ifdef G4VIS_USE
#include "G4VisExecutive.hh"
#endif

#ifdef G4UI_USE
#include "G4UIExecutive.hh"
#endif

int main(int argc, char** argv)
{
  // Seed the random number generator manually
  //
  // G4long myseed = 345354;
  // CLHEP::HepRandom::setTheSeed(myseed);

  //////////////
  // make random seed different 
  //choose the Random engine
  CLHEP::HepRandom::setTheEngine(new CLHEP::RanecuEngine());
  //set random seed with system time
  G4long seed = time(NULL);
  CLHEP::HepRandom::setTheSeed(seed);
  // END make random seed different in each run
  //////////////

  G4VSteppingVerbose::SetInstance(new LXeSteppingVerbose);

  G4RunManager* runManager = new G4RunManager;

  runManager->SetUserInitialization(new LXeDetectorConstruction);
  runManager->SetUserInitialization(new LXePhysicsList);

#ifdef G4VIS_USE
  G4VisManager* visManager = new G4VisExecutive;
  visManager->Initialize();
#endif

  LXeRecorderBase* recorder = new HistoManager; // Record using HistoManager

  LXePrimaryGeneratorAction* gen_action = new LXePrimaryGeneratorAction();
  runManager->SetUserAction(gen_action);

  runManager->SetUserAction(new LXeStackingAction);

  runManager->SetUserAction(new LXeRunAction(recorder));
  runManager->SetUserAction(new LXeEventAction(recorder));
  runManager->SetUserAction(new LXeTrackingAction(recorder));
  runManager->SetUserAction(new LXeSteppingAction(recorder));

  // runManager->Initialize();
 
  // get the pointer to the UI manager and set verbosities
  G4UImanager* UImanager = G4UImanager::GetUIpointer();

  if(argc==1){//....no command file specified, Start interactive session
#ifdef G4UI_USE
    G4UIExecutive* ui = new G4UIExecutive(argc, argv);
#ifdef G4VIS_USE
    UImanager->ApplyCommand("/control/execute vis.mac");
#endif
    ui->SessionStart();
    delete ui;
#endif
  }//....geant command file specified on command line
  else{
    setenv("G4VIS_NONE","Y",1);
    G4String command = "/control/execute ";
    G4String filename = argv[1];
    UImanager->ApplyCommand(command+filename);
  }

  if(recorder)delete recorder;

#ifdef G4VIS_USE
  delete visManager;
#endif

  // job termination
  delete runManager;
  return 0;
}
