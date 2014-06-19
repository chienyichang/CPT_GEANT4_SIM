
#include "G4Material.hh"
#include "G4MaterialTable.hh"
#include "G4Element.hh"
#include "G4ElementTable.hh"

class MyMaterials
{
private:

public:

    MyMaterials();
    ~MyMaterials();

    static G4Material *Air();
    static G4Material *Water();
    static G4Material *LSO();
    static G4Material *LYSO();
    static G4Material *LUAGCE();
    static G4Material *LUAGPR();
    static G4Material *Vacuum();
    static G4Material *Silicon();
    static G4Material *OpticalGrease();
    static G4Material *lowLYLYSO();

    static G4Material *PbWO();
    static G4double fromNmToEv(G4double wavelength);
    static G4double fromEvToNm(G4double energy);
    static G4double CalculateSellmeier(G4double indexZero, G4double *nVec, G4double *lVec, G4double wavelength);

};
