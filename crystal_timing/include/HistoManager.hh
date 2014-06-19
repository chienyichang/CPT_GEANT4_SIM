#ifndef HistoManager_h
#define HistoManager_h 1

#include "LXeRecorderBase.hh"
#include "HistoMessenger.hh"
#include "G4UserRunAction.hh"

// Include files for ROOT.
#include "TROOT.h"
#include "TFile.h"
#include "TH1.h"
#include "TH2.h"
#include "TProfile.h"
#include "TNtuple.h"
#include "TTree.h"
#include "TBranch.h"
#include "TRandom.h"

#include <iostream>

#include "globals.hh"

#include "G4Step.hh"
#include "G4Event.hh"

#include "G4VProcess.hh"
#include "G4OpBoundaryProcess.hh"
#include "G4ProcessManager.hh"
#include "LXePMTSD.hh"
#include "Data.hh"


class HistoMessenger;
class G4Run;
static const int dimOfHitVector = 500 ;

class HistoManager: public LXeRecorderBase 

{
public:
  HistoManager();
  ~HistoManager();

  
  void RecordBeginOfRun(const G4Run *); 
  void RecordEndOfRun(const G4Run *); 

  
  void RecordBeginOfEvent(const G4Event *); 
  void RecordEndOfEvent(const G4Event * );

  
  void RecordStep(const G4Step *);
  void SethistName(G4String name);
  
  static bool compareByTime(const trackData &a, const trackData &b){
    return a.time < b.time;
}
  
private:
  TFile * hfile;
  G4String histName;
 
  TTree *tree;

  std::vector<Double_t> electronEne;
  std::vector<Int_t> electronCreator;

  Double_t primEdepX;
  Double_t primEdepY;
  Double_t primEdepZ;

  Double_t eWeightPosX;
  Double_t eWeightPosY;
  Double_t eWeightPosZ;

  Double_t posMaxX;
  Double_t posMaxY;
  Double_t posMaxZ;

  Double_t convPosX;
  Double_t convPosY;
  Double_t convPosZ;

  Double_t edep;
  Double_t edepMax;

  Double_t EvTime;
  Double_t MuEnergy;

  Int_t run;
  Int_t NOptPhotons;
  Int_t NOptPhotons_Scint;
  Int_t NOptPhotons_Ceren;
  Int_t NAbsorbed;
  Int_t NBoundaryAbsorbed;
  Int_t NPMTAboveThld;
  Int_t NPhotonsPMT;

  std::vector<trackData> trackVectorNegZ;
  std::vector<trackData> trackVectorPosZ;

  std::vector<stepData> g4step;


  HistoMessenger* fHistoMessenger;
};

#endif
