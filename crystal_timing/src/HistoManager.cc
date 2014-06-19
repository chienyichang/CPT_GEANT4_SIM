// Include the CLHEP Histogram classes
//#include "CLHEP/Hist/Histogram.h"
//#include "CLHEP/Hist/Tuple.h"
//#include "CLHEP/Hist/HBookFile.h"
// Include files for ROOT.
#include "Rtypes.h"
#include "TROOT.h"
#include "TFile.h"
#include "TH1.h"
#include "TH2.h"
#include "TProfile.h"
#include "TNtuple.h"
#include "TTree.h"
#include "TBranch.h"
#include "TRandom.h"
#include "G4TrackStatus.hh"

#include "globals.hh"

#include "G4Event.hh"
#include "G4Run.hh"
#include "G4Step.hh"
#include "LXeRecorderBase.hh"
#include "G4ios.hh"
#include <iomanip>
#include "G4SDManager.hh"
#include "Randomize.hh"
#include "G4VVisManager.hh"
#include "G4UImanager.hh"
#include "G4VProcess.hh"
#include "G4HCofThisEvent.hh"
#include "LXeDetectorMessenger.hh"
#include "LXeUserEventInformation.hh"
#include "LXeUserTrackInformation.hh"
#include "HistoManager.hh"
#include "G4ParticleTypes.hh"



#include "CLHEP/Random/RanecuEngine.h"

HistoManager::HistoManager()
: histName("histfile")
{
  fHistoMessenger = new HistoMessenger(this);
  hfile = NULL ;
  static TROOT rootBase("simple","Test of histogramming and I/O");
  
}

HistoManager::~HistoManager(){    
    delete fHistoMessenger;
}

void HistoManager::RecordBeginOfRun(const G4Run* r)
{
    
  hfile = new TFile(histName,"RECREATE"); 
   
  run = 0;
  
  // the tree
  tree = new TTree("T", "Tree");

  tree->Branch("NOptPhotons",&NOptPhotons,"NOptPhotons/I"); 
  tree->Branch("NOptPhotons_Scint",&NOptPhotons_Scint,"NOptPhotons_Scint/I"); 
  tree->Branch("NOptPhotons_Ceren",&NOptPhotons_Ceren,"NOptPhotons_Ceren/I"); 

  tree->Branch("NAbsorbed",&NAbsorbed,"NAbsorbed/I"); 
  tree->Branch("NBoundaryAbsorbed",&NBoundaryAbsorbed,"NBoundaryAbsorbed/I"); 

  tree->Branch("NPMTAboveThld",&NPMTAboveThld,"NPMTAboveThld/I"); 
  tree->Branch("run",&run,"run/I"); 

  tree->Branch("NPhotonsPMT",&NPhotonsPMT,"NPhotonsPMT/I"); 
  tree->Branch("EvTime",&EvTime,"EvTime/D"); 

  tree->Branch("edep",&edep,"edep/D"); 

  tree->Branch("MuEnergy",&MuEnergy,"MuEnergy/D"); 

  // tree->Branch("electronEne",&electronEne); 
  // tree->Branch("electronCreator",&electronCreator); 

  tree->Branch("primEdepX",&primEdepX,"primEdepX/D"); 
  tree->Branch("primEdepY",&primEdepY,"primEdepY/D"); 
  tree->Branch("primEdepZ",&primEdepZ,"primEdepZ/D"); 

  tree->Branch("eWeightPosX",&eWeightPosX,"eWeightPosX/D"); 
  tree->Branch("eWeightPosY",&eWeightPosY,"eWeightPosY/D"); 
  tree->Branch("eWeightPosZ",&eWeightPosZ,"eWeightPosZ/D"); 

  tree->Branch("posMaxX",&posMaxX,"posMaxX/D"); 
  tree->Branch("posMaxY",&posMaxY,"posMaxY/D"); 
  tree->Branch("posMaxZ",&posMaxZ,"posMaxZ/D"); 

  tree->Branch("convPosX",&convPosX,"convPosX/D"); 
  tree->Branch("convPosY",&convPosY,"convPosY/D"); 
  tree->Branch("convPosZ",&convPosZ,"convPosZ/D"); 

  tree->Branch("trackVectorNegZ",&trackVectorNegZ); 
  tree->Branch("trackVectorPosZ",&trackVectorPosZ); 

  tree->Branch("g4step",&g4step); 

  G4UImanager* UI = G4UImanager::GetUIpointer();
   
  G4VVisManager* pVVisManager = G4VVisManager::GetConcreteInstance();

  if(pVVisManager)
  {
    UI->ApplyCommand("/vis/scene/notifyHandlers");
  }
  
  
}


void HistoManager::RecordEndOfRun(const G4Run* r)
{   
  
  tree->Write();
  hfile->Write();
  hfile->Close();   
}



void HistoManager::RecordBeginOfEvent(const G4Event* event)
{
  G4cout<<"Event number: "<<event->GetEventID()<<G4endl;
  
  NOptPhotons  = 0; // Total number of optical photons produced
  NOptPhotons_Scint = 0;
  NOptPhotons_Ceren = 0;
  NAbsorbed = 0;
  NBoundaryAbsorbed = 0;
  NPMTAboveThld = 0;
  NPhotonsPMT = 0;

  EvTime = 0.;
  MuEnergy = 0.;

  edep = 0.0;
  edepMax = 0.;

  primEdepX = 0.;
  primEdepY = 0.;
  primEdepZ = 0.;

  eWeightPosX = 0.;
  eWeightPosY = 0.;
  eWeightPosZ = 0.;

  posMaxX = 0.;
  posMaxY = 0.;
  posMaxZ = 0.;

  convPosX = 0.; 
  convPosY = 0.; 
  convPosZ = 0.; 

  // electronEne.clear();
  // electronCreator.clear(); 

  trackVectorNegZ.clear();
  trackVectorPosZ.clear();

  g4step.clear();
}


void HistoManager::RecordEndOfEvent(const G4Event* event )
{

  LXeUserEventInformation* eventInformation
    =(LXeUserEventInformation*)event->GetUserInformation();

  NOptPhotons = eventInformation->GetPhotonCount();
  NOptPhotons_Scint = eventInformation->GetPhotonCount_Scint();
  NOptPhotons_Ceren = eventInformation->GetPhotonCount_Ceren();
  NAbsorbed = eventInformation->GetAbsorptionCount();
  NBoundaryAbsorbed = eventInformation->GetBoundaryAbsorptionCount();
  NPMTAboveThld = eventInformation->GetPMTSAboveThreshold();
  NPhotonsPMT = eventInformation->GetHitCount();
  EvTime = eventInformation->GetEventTime();
  MuEnergy = eventInformation->GetMuonEnergy();
  run=event->GetEventID();

  edep = eventInformation->GetEDep();
  edepMax = eventInformation->GetEDepMax();

  // fill in the position of energy weighted position of hits
  eWeightPosX =  eventInformation->GetEWeightPos().x()/CLHEP::cm;
  eWeightPosY =  eventInformation->GetEWeightPos().y()/CLHEP::cm;
  eWeightPosZ =  eventInformation->GetEWeightPos().z()/CLHEP::cm;

  // fill in the position of the largest energy deposit
  posMaxX = eventInformation->GetPosMax().x()/CLHEP::cm;
  posMaxY = eventInformation->GetPosMax().y()/CLHEP::cm;
  posMaxZ = eventInformation->GetPosMax().z()/CLHEP::cm;

  // fill in the conversion position 
  convPosX = eventInformation->GetConvPos().x()/CLHEP::cm;
  convPosY = eventInformation->GetConvPos().y()/CLHEP::cm;
  convPosZ = eventInformation->GetConvPos().z()/CLHEP::cm;

  std::sort(trackVectorNegZ.begin(), trackVectorNegZ.end(), compareByTime);
  std::sort(trackVectorPosZ.begin(), trackVectorPosZ.end(), compareByTime);
  
  tree->Fill(); 
}


void HistoManager::RecordStep(const G4Step* s) 
{
  G4Track* track = s->GetTrack();
  G4double EdepStep = s->GetTotalEnergyDeposit()/CLHEP::eV;

  G4Material* material = track->GetMaterial();
  G4String name = material->GetName();
  
  G4int nbr_photon = track -> GetTrackID();

  LXeUserTrackInformation* trackInformation
    =(LXeUserTrackInformation*)track->GetUserInformation();

  G4StepPoint* thePrePoint = s->GetPreStepPoint();
  G4VPhysicalVolume* thePrePV = thePrePoint->GetPhysicalVolume();

  G4StepPoint* thePostPoint = s->GetPostStepPoint();
  G4VPhysicalVolume* thePostPV = thePostPoint->GetPhysicalVolume();

  
  if( trackInformation->GetTrackStatus() == 2)
    {
      trackData tmp;
      tmp.time     = 1000*track->GetGlobalTime()/CLHEP::ns; //convert to ps
      tmp.position = track->GetPosition().z()/CLHEP::cm;    //convert to cm
      tmp.energy   = 1239.84187 / (track->GetKineticEnergy()/CLHEP::eV); //convert to ev to nm

      // optical photon creator
      G4String CPName;
      Int_t CPInex;

      if(track->GetCreatorProcess()!=0)
	{
	  CPName = track->GetCreatorProcess()->GetProcessName();
	  if(CPName == "Scintillation")
	    CPInex = 1;
	  if(CPName == "Cerenkov")
	    CPInex = 2;
	  
	  tmp.creator = CPInex;
	}
      
      if(tmp.position<0)
	trackVectorNegZ.push_back(tmp);
      else
	trackVectorPosZ.push_back(tmp);
    }
  
  stepData tmpstep;

  G4ParticleDefinition* particleType = track->GetDefinition();

  tmpstep.time      = 1000*s->GetPreStepPoint()->GetGlobalTime()/CLHEP::ns; //convert to ps
  tmpstep.positionX = s->GetPreStepPoint()->GetPosition().x()/CLHEP::cm;    //convert to cm
  tmpstep.positionY = s->GetPreStepPoint()->GetPosition().y()/CLHEP::cm;    //convert to cm
  tmpstep.positionZ = s->GetPreStepPoint()->GetPosition().z()/CLHEP::cm;    //convert to cm
  tmpstep.energy    = s->GetTotalEnergyDeposit()/CLHEP::eV;
  
  if(particleType==G4OpticalPhoton::OpticalPhotonDefinition())
    tmpstep.particle  = 0;
  if(particleType==G4Electron::ElectronDefinition())
    tmpstep.particle  = 1;
  if(particleType==G4Positron::PositronDefinition())
    tmpstep.particle  = 2;
  if(particleType==G4MuonPlus::MuonPlusDefinition())
    tmpstep.particle  = 3;
  if(particleType==G4MuonMinus::MuonMinusDefinition())
    tmpstep.particle  = 4;
  if(particleType->GetParticleName()=="gamma")
    tmpstep.particle  = 5;
      
  G4String CPName;
  Int_t CPInex = -1;
  if(track->GetCreatorProcess()!=0)
    {
      CPName = track->GetCreatorProcess()->GetProcessName();
	  
      if(CPName == "muIoni")
	CPInex = 1;
      else if(CPName == "eIoni")
	CPInex = 2;
      else if(CPName == "conv")
	CPInex = 3;
      else if(CPName == "phot")
	CPInex = 4;
      else if(CPName == "compt")
	CPInex = 5;
      else if(CPName == "pol-compt")
	CPInex = 6;
      else if(CPName == "Scintillation")
	CPInex = 7;
      else if(CPName == "Cerenkov")
	CPInex = 8;

      else  CPInex = 9;
    }

  tmpstep.creator  = CPInex;

  //  Was the photon absorbed by the absorption process
  // if(thePostPoint->GetProcessDefinedStep()->GetProcessName() == "OpAbsorption") 
  //   {
  //     tmpstep.absorbed = 1;     
  //   }      
  // else 
  //   tmpstep.absorbed = 0;     

  

  g4step.push_back(tmpstep);     
} 
 
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

void HistoManager::SethistName(G4String name)
{
  histName = name;
  G4cout << " hist file = " << histName << G4endl;
}
