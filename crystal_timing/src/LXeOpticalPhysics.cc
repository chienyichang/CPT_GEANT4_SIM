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
//
// $Id$
//
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#include "globals.hh"
#include "LXeOpticalPhysics.hh"

#include "G4ParticleDefinition.hh"
#include "G4ParticleTypes.hh"
#include "G4ParticleTable.hh"

#include "G4ProcessManager.hh"

#include "G4Cerenkov.hh"
#include "G4Scintillation.hh"
#include "G4OpAbsorption.hh"
#include "G4OpRayleigh.hh"
#include "G4OpMieHG.hh"
#include "G4OpBoundaryProcess.hh"

#include "G4LossTableManager.hh"
#include "G4EmSaturation.hh"
 
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

LXeOpticalPhysics::LXeOpticalPhysics(const G4String& name)
  :  G4VPhysicsConstructor(name)
{
  theCerenkovProcess           = NULL;
  theScintillationProcess      = NULL;
  theAbsorptionProcess         = NULL;
  theRayleighScatteringProcess = NULL;
  theMieHGScatteringProcess    = NULL;
  theBoundaryProcess           = NULL;
  
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

LXeOpticalPhysics::~LXeOpticalPhysics() {}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void LXeOpticalPhysics::ConstructParticle()
{
  // In this method, static member functions should be called
  // for all particles which you want to use.
  // This ensures that objects of these particle types will be
  // created in the program.

  ConstructBosons();
  ConstructLeptons();
  ConstructMesons();
  ConstructBaryons();
  ConstructIons();

}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void LXeOpticalPhysics::ConstructBosons()
{
  // pseudo-particles
  G4Geantino::GeantinoDefinition();
  G4ChargedGeantino::ChargedGeantinoDefinition();

  // gamma
  G4Gamma::GammaDefinition();

  // optical photon
  G4OpticalPhoton::OpticalPhotonDefinition();
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void LXeOpticalPhysics::ConstructLeptons()
{
  // leptons
  //  e+/-
  G4Electron::ElectronDefinition();
  G4Positron::PositronDefinition();
  // mu+/-
  G4MuonPlus::MuonPlusDefinition();
  G4MuonMinus::MuonMinusDefinition();
  // nu_e
  G4NeutrinoE::NeutrinoEDefinition();
  G4AntiNeutrinoE::AntiNeutrinoEDefinition();
  // nu_mu
  G4NeutrinoMu::NeutrinoMuDefinition();
  G4AntiNeutrinoMu::AntiNeutrinoMuDefinition();
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void LXeOpticalPhysics::ConstructMesons()
{
  //  mesons
  G4PionPlus::PionPlusDefinition();
  G4PionMinus::PionMinusDefinition();
  G4PionZero::PionZeroDefinition();
  G4Eta::EtaDefinition();
  G4EtaPrime::EtaPrimeDefinition();
  G4KaonPlus::KaonPlusDefinition();
  G4KaonMinus::KaonMinusDefinition();
  G4KaonZero::KaonZeroDefinition();
  G4AntiKaonZero::AntiKaonZeroDefinition();
  G4KaonZeroLong::KaonZeroLongDefinition();
  G4KaonZeroShort::KaonZeroShortDefinition();
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void LXeOpticalPhysics::ConstructBaryons()
{
  //  barions
  G4Proton::ProtonDefinition();
  G4AntiProton::AntiProtonDefinition();

  G4Neutron::NeutronDefinition();
  G4AntiNeutron::AntiNeutronDefinition();
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void LXeOpticalPhysics::ConstructProcess()
{
  //  AddTransportation();
  ConstructGeneral();
  ConstructEM();
  ConstructOp();

  // AddTransportation();
  ConstructInteractions();
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#include "G4Decay.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void LXeOpticalPhysics::ConstructGeneral()
{
  // Add Decay Process
  G4Decay* theDecayProcess = new G4Decay();
  aParticleIterator->reset();
  while( (*aParticleIterator)() ){
    G4ParticleDefinition* particle = aParticleIterator->value();
    G4ProcessManager* pmanager = particle->GetProcessManager();
    if (theDecayProcess->IsApplicable(*particle)) {
      pmanager ->AddProcess(theDecayProcess);
      // set ordering for PostStepDoIt and AtRestDoIt
      pmanager ->SetProcessOrdering(theDecayProcess, idxPostStep);
      pmanager ->SetProcessOrdering(theDecayProcess, idxAtRest);
    }
  }
}

#include "G4IonConstructor.hh"
void LXeOpticalPhysics::ConstructIons()
{
  //  Construct light ions
  //  nuclei
  G4Alpha::AlphaDefinition();
  G4Deuteron::DeuteronDefinition();
  G4Triton::TritonDefinition();
  G4He3::He3Definition();
  //  generic ion
  G4GenericIon::GenericIonDefinition();
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#include "G4ComptonScattering.hh"
#include "G4GammaConversion.hh"
#include "G4PhotoElectricEffect.hh"

#include "G4eMultipleScattering.hh"
#include "G4MuMultipleScattering.hh"
#include "G4hMultipleScattering.hh"

#include "G4eIonisation.hh"
#include "G4eBremsstrahlung.hh"
#include "G4eplusAnnihilation.hh"

#include "G4MuIonisation.hh"
#include "G4MuBremsstrahlung.hh"
#include "G4MuPairProduction.hh"

#include "G4hIonisation.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void LXeOpticalPhysics::ConstructEM()
{
  aParticleIterator->reset();
  while( (*aParticleIterator)() ){
    G4ParticleDefinition* particle = aParticleIterator->value();
    G4ProcessManager* pmanager = particle->GetProcessManager();
    G4String particleName = particle->GetParticleName();

    if (particleName == "gamma") {
    // gamma
      // Construct processes for gamma
      pmanager->AddDiscreteProcess(new G4GammaConversion());
      pmanager->AddDiscreteProcess(new G4ComptonScattering());
      pmanager->AddDiscreteProcess(new G4PhotoElectricEffect());

    } else if (particleName == "e-") {
    //electron
      // Construct processes for electron
      pmanager->AddProcess(new G4eMultipleScattering(),-1, 1, 1);
      pmanager->AddProcess(new G4eIonisation(),       -1, 2, 2);
      pmanager->AddProcess(new G4eBremsstrahlung(),   -1, 3, 3);

    } else if (particleName == "e+") {
    //positron
      // Construct processes for positron
      pmanager->AddProcess(new G4eMultipleScattering(),-1, 1, 1);
      pmanager->AddProcess(new G4eIonisation(),       -1, 2, 2);
      pmanager->AddProcess(new G4eBremsstrahlung(),   -1, 3, 3);
      pmanager->AddProcess(new G4eplusAnnihilation(),  0,-1, 4);

    } else if( particleName == "mu+" ||
               particleName == "mu-"    ) {
    //muon
     // Construct processes for muon
     pmanager->AddProcess(new G4MuMultipleScattering(),-1, 1, 1);
     pmanager->AddProcess(new G4MuIonisation(),      -1, 2, 2);
     pmanager->AddProcess(new G4MuBremsstrahlung(),  -1, 3, 3);
     pmanager->AddProcess(new G4MuPairProduction(),  -1, 4, 4);

    } else {
      if ((particle->GetPDGCharge() != 0.0) &&
          (particle->GetParticleName() != "chargedgeantino")) {
       // all others charged particles except geantino
       pmanager->AddProcess(new G4hMultipleScattering(),-1,1,1);
       pmanager->AddProcess(new G4hIonisation(),       -1,2,2);
     }
    }
  }
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void LXeOpticalPhysics::ConstructOp()
{
  theCerenkovProcess           = new G4Cerenkov("Cerenkov");
  theScintillationProcess      = new G4Scintillation("Scintillation");
  theAbsorptionProcess         = new G4OpAbsorption();
  theRayleighScatteringProcess = new G4OpRayleigh();
  theMieHGScatteringProcess    = new G4OpMieHG();
  theBoundaryProcess           = new G4OpBoundaryProcess();

//  theCerenkovProcess->DumpPhysicsTable();
//  theScintillationProcess->DumpPhysicsTable();
//  theRayleighScatteringProcess->DumpPhysicsTable();

  theCerenkovProcess->SetMaxNumPhotonsPerStep(300);
  theCerenkovProcess->SetMaxBetaChangePerStep(10.0);
  theCerenkovProcess->SetTrackSecondariesFirst(true);
  
  theScintillationProcess->SetScintillationYieldFactor(1.);
  theScintillationProcess->SetTrackSecondariesFirst(true);

  // Use Birks Correction in the Scintillation process

  G4EmSaturation* emSaturation = G4LossTableManager::Instance()->EmSaturation();
  theScintillationProcess->AddSaturation(emSaturation);

  aParticleIterator->reset();
  while( (*aParticleIterator)() ){
    G4ParticleDefinition* particle = aParticleIterator->value();
    G4ProcessManager* pmanager = particle->GetProcessManager();
    G4String particleName = particle->GetParticleName();
    if (theCerenkovProcess->IsApplicable(*particle)) {
      pmanager->AddProcess(theCerenkovProcess);
      pmanager->SetProcessOrdering(theCerenkovProcess,idxPostStep);
    }
    if (theScintillationProcess->IsApplicable(*particle)) {
      pmanager->AddProcess(theScintillationProcess);
      pmanager->SetProcessOrderingToLast(theScintillationProcess, idxAtRest);
      pmanager->SetProcessOrderingToLast(theScintillationProcess, idxPostStep);
    }
    if (particleName == "opticalphoton") {
      G4cout << " AddDiscreteProcess to OpticalPhoton " << G4endl;
      pmanager->AddDiscreteProcess(theAbsorptionProcess);
      pmanager->AddDiscreteProcess(theRayleighScatteringProcess);
      pmanager->AddDiscreteProcess(theMieHGScatteringProcess);
      pmanager->AddDiscreteProcess(theBoundaryProcess);
    }
  }
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

//----------------------------------------------------------------------------//
// Define electromagnetic transportation processes
//----------------------------------------------------------------------------//
// gamma
#include "G4PhotoElectricEffect.hh" 
#include "G4ComptonScattering.hh"  
#include "G4PolarizedCompton.hh"
#include "G4GammaConversion.hh" 
// e-
// e+
#include "G4eMultipleScattering.hh"
#include "G4eIonisation.hh"
#include "G4eBremsstrahlung.hh"
#include "G4eplusAnnihilation.hh"
// muon
#include "G4MuMultipleScattering.hh"
#include "G4MuIonisation.hh" 
#include "G4MuBremsstrahlung.hh" 
#include "G4MuPairProduction.hh" 
// neutron
#include "G4HadronElasticProcess.hh"
#include "G4HadronElasticPhysics.hh"
#include "G4HadronFissionProcess.hh"
#include "G4HadronCaptureProcess.hh"
#include "G4NeutronInelasticProcess.hh"
#include "G4AntiNeutronInelasticProcess.hh"

#include "G4hMultipleScattering.hh"
#include "G4hIonisation.hh"

// Low-energy Models

#include "G4HadronElastic.hh"
#include "G4NeutronRadCapture.hh"
#include "G4LFission.hh"

// -- generator models
#include "G4TheoFSGenerator.hh"
#include "G4ExcitationHandler.hh"
#include "G4Evaporation.hh"
#include "G4CompetitiveFission.hh"
#include "G4FermiBreakUp.hh"
#include "G4StatMF.hh"
#include "G4GeneratorPrecompoundInterface.hh"
#include "G4Fancy3DNucleus.hh"
#include "G4CascadeInterface.hh"
#include "G4StringModel.hh"
#include "G4PreCompoundModel.hh"
#include "G4FTFModel.hh"
#include "G4QGSMFragmentation.hh"
#include "G4LundStringFragmentation.hh"
#include "G4ExcitedStringDecay.hh"
#include "G4QMDReaction.hh"
#include "G4BinaryLightIonReaction.hh"

//----------------------------------------------------------------------------//
void LXeOpticalPhysics::ConstructInteractions()
{
  aParticleIterator->reset();
  while( (*aParticleIterator)() ){
    G4ParticleDefinition* particle = aParticleIterator->value();
    G4ProcessManager* pmanager = particle->GetProcessManager();
    G4String particleName = particle->GetParticleName();
     
    if (particleName == "gamma") {
      // Standard classes
      pmanager->AddDiscreteProcess(new G4PhotoElectricEffect());
      pmanager->AddDiscreteProcess(new G4ComptonScattering());
      pmanager->AddDiscreteProcess(new G4PolarizedCompton());
      pmanager->AddDiscreteProcess(new G4GammaConversion());
    } else if (particleName == "e-") {
      // Standard classes:
      pmanager->AddProcess(new G4eMultipleScattering(),-1, 1,1);
      pmanager->AddProcess(new G4eIonisation(),       -1, 2,2);
      pmanager->AddProcess(new G4eBremsstrahlung(),   -1,-1,3); 

    } else if (particleName == "e+") {
      // Standard classes:
      pmanager->AddProcess(new G4eMultipleScattering(),-1, 1,1);
      pmanager->AddProcess(new G4eIonisation(),       -1, 2,2);
      pmanager->AddProcess(new G4eBremsstrahlung(),   -1,-1,3);
      pmanager->AddProcess(new G4eplusAnnihilation(),  0,-1,4);
      
    } else if (particleName == "neutron") {

      G4HadronElasticProcess* theElasticProcess = new G4HadronElasticProcess;
      G4HadronElastic* theElasticModel = new G4HadronElastic;
      theElasticProcess->RegisterMe(theElasticModel);

      // elastic scattering
      pmanager->AddDiscreteProcess(theElasticProcess);

      // all models for treatment of thermal nucleus
      G4Evaporation* theEvaporation = new G4Evaporation;
      G4FermiBreakUp* theFermiBreakUp = new G4FermiBreakUp;
      G4StatMF* theMF = new G4StatMF;

      // Evaporation logic
      G4ExcitationHandler* theHandler = new G4ExcitationHandler;
      theHandler->SetEvaporation(theEvaporation);
      theHandler->SetFermiModel(theFermiBreakUp);
      theHandler->SetMultiFragmentation(theMF);
      theHandler->SetMaxAandZForFermiBreakUp(12, 6);
      theHandler->SetMinEForMultiFrag(3*MeV);

      // Pre equilibrium stage
      G4PreCompoundModel* thePreEquilib = new G4PreCompoundModel(theHandler);

      // a no-cascade generator-precompound interaface
      G4GeneratorPrecompoundInterface* theCascade =
	new G4GeneratorPrecompoundInterface;
      theCascade->SetDeExcitation(thePreEquilib);

      // inelastic scattering
      // Bertini cascade
      G4CascadeInterface* bertini = new G4CascadeInterface;
      bertini->SetMaxEnergy(22*MeV);
      
      // this will be the model class for high energies
      G4TheoFSGenerator* theTheoModel = new G4TheoFSGenerator;
      G4TheoFSGenerator* antiBHighEnergyModel = new G4TheoFSGenerator;

      // here come the high energy parts
      G4VPartonStringModel* theStringModel;
      theStringModel = new G4FTFModel;
      theTheoModel->SetTransport(theCascade);
      theTheoModel->SetHighEnergyGenerator(theStringModel);
      theTheoModel->SetMinEnergy(19*GeV);
      theTheoModel->SetMaxEnergy(100*TeV);

      G4NeutronInelasticProcess* theInelasticProcess =
                                    new G4NeutronInelasticProcess("inelastic");
      theInelasticProcess->RegisterMe(bertini);
      theInelasticProcess->RegisterMe(theTheoModel);
      pmanager->AddDiscreteProcess(theInelasticProcess);

      // fission
      G4HadronFissionProcess* theFissionProcess = new G4HadronFissionProcess;
      G4LFission* theFissionModel = new G4LFission;
      theFissionProcess->RegisterMe(theFissionModel);
      pmanager->AddDiscreteProcess(theFissionProcess);

      // capture
      G4HadronCaptureProcess* theCaptureProcess = new G4HadronCaptureProcess;
      G4NeutronRadCapture* theCaptureModel = new G4NeutronRadCapture;
      theCaptureProcess->RegisterMe(theCaptureModel);
      pmanager->AddDiscreteProcess(theCaptureProcess);

    } // else if( particleName == "mu+" ||
    //            particleName == "mu-"    ) {
    // //muon  
    //  // Construct processes for muon+
    //  pmanager->AddProcess(new G4MuMultipleScattering(),-1,1,1);
    //  pmanager->AddProcess(new G4MuIonisation(),-1,2,2);
    //  pmanager->AddProcess(new G4MuBremsstrahlung(),-1,-1,3);
    //  pmanager->AddProcess(new G4MuPairProduction(),-1,-1,4);

    // } 
    else if( particleName == "GenericIon" ) {
      pmanager->AddProcess(new G4hMultipleScattering(),-1,1,1);
      pmanager->AddProcess(new G4hIonisation(),-1,2,2);
    } else {
      if ((particle->GetPDGCharge() != 0.0) &&
          (particle->GetParticleName() != "chargedgeantino")&&
          (!particle->IsShortLived()) ) {
     // all others charged particles except geantino
       pmanager->AddProcess(new G4hMultipleScattering(),-1,1,1);
       pmanager->AddProcess(new G4hIonisation(),-1,2,2);
      }
    }
  }
}
