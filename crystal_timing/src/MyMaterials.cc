#include "MyMaterials.hh"

MyMaterials::MyMaterials()
{

}

MyMaterials::~MyMaterials()
{
    ;
}

G4Material *MyMaterials::Air()
{
    G4double a, z, density;
    G4int nelements;

    G4Element *N = new G4Element ("Nitrogen", "N", z = 7 , a = 14.01 * CLHEP::g / CLHEP::mole);
    G4Element *O = new G4Element ("Oxygen"  , "O", z = 8 , a = 16.00 * CLHEP::g / CLHEP::mole);

    G4Material *Air = new G4Material ("Air", density = 1.29 * CLHEP::mg / CLHEP::cm3, nelements = 2);
    Air->AddElement (N, 70.*CLHEP::cm3);
    Air->AddElement (O, 30.*CLHEP::cm3);

    const G4int nEntries = 34;

    G4double PhotonEnergy[nEntries] = {
        0.0001 * CLHEP::eV, 1.00 * CLHEP::eV,  2.034 * CLHEP::eV, 2.068 * CLHEP::eV, 2.103 * CLHEP::eV, 2.139 * CLHEP::eV,
        2.177 * CLHEP::eV, 2.216 * CLHEP::eV, 2.256 * CLHEP::eV, 2.298 * CLHEP::eV,
        2.341 * CLHEP::eV, 2.386 * CLHEP::eV, 2.433 * CLHEP::eV, 2.481 * CLHEP::eV,
        2.532 * CLHEP::eV, 2.585 * CLHEP::eV, 2.640 * CLHEP::eV, 2.697 * CLHEP::eV,
        2.757 * CLHEP::eV, 2.820 * CLHEP::eV, 2.885 * CLHEP::eV, 2.954 * CLHEP::eV,
        3.026 * CLHEP::eV, 3.102 * CLHEP::eV, 3.181 * CLHEP::eV, 3.265 * CLHEP::eV,
        3.353 * CLHEP::eV, 3.446 * CLHEP::eV, 3.545 * CLHEP::eV, 3.649 * CLHEP::eV,
        3.760 * CLHEP::eV, 3.877 * CLHEP::eV, 4.002 * CLHEP::eV, 4.136 * CLHEP::eV
    };

    G4double RefractiveIndex[nEntries] = {
        1.0003, 1.0003, 1.0003, 1.0003, 1.0003, 1.0003, 1.0003, 1.0003,
        1.0003, 1.0003, 1.0003, 1.0003, 1.0003, 1.0003, 1.0003,
        1.0003, 1.0003, 1.0003, 1.0003, 1.0003, 1.0003, 1.0003,
        1.0003, 1.0003, 1.0003, 1.0003, 1.0003, 1.0003, 1.0003,
        1.0003, 1.0003, 1.0003, 1.0003, 1.0003
    };

    G4MaterialPropertiesTable *myMPT = new G4MaterialPropertiesTable();
    myMPT->AddProperty ("RINDEX", PhotonEnergy, RefractiveIndex, nEntries);

    Air->SetMaterialPropertiesTable (myMPT);

    return Air;
}


G4Material *MyMaterials::Water()
{
    G4double a, z, density;
    G4int nelements;

    G4Element *H = new G4Element ("Hydrogen", "H", z = 1 , a = 1.01 * CLHEP::g / CLHEP::mole);
    G4Element *O = new G4Element ("Oxygen"  , "O", z = 8 , a = 16.00 * CLHEP::g / CLHEP::mole);
    G4Material *Water = new G4Material ("Water", density = 1.0 * CLHEP::g / CLHEP::cm3, nelements = 2);
    Water->AddElement (H, 2);
    Water->AddElement (O, 1);

    const G4int nEntries = 33;

    G4double PhotonEnergy[nEntries] = {
        0.1 * CLHEP::eV, 2.034 * CLHEP::eV, 2.068 * CLHEP::eV, 2.103 * CLHEP::eV, 2.139 * CLHEP::eV,
        2.177 * CLHEP::eV, 2.216 * CLHEP::eV, 2.256 * CLHEP::eV, 2.298 * CLHEP::eV,
        2.341 * CLHEP::eV, 2.386 * CLHEP::eV, 2.433 * CLHEP::eV, 2.481 * CLHEP::eV,
        2.532 * CLHEP::eV, 2.585 * CLHEP::eV, 2.640 * CLHEP::eV, 2.697 * CLHEP::eV,
        2.757 * CLHEP::eV, 2.820 * CLHEP::eV, 2.885 * CLHEP::eV, 2.954 * CLHEP::eV,
        3.026 * CLHEP::eV, 3.102 * CLHEP::eV, 3.181 * CLHEP::eV, 3.265 * CLHEP::eV,
        3.353 * CLHEP::eV, 3.446 * CLHEP::eV, 3.545 * CLHEP::eV, 3.649 * CLHEP::eV,
        3.760 * CLHEP::eV, 3.877 * CLHEP::eV, 4.002 * CLHEP::eV, 4.136 * CLHEP::eV
    };

    G4double RefractiveIndex[nEntries] = {
        1.3435, 1.3435, 1.344,  1.3445, 1.345,  1.3455,
        1.346,  1.3465, 1.347,  1.3475, 1.348,
        1.3485, 1.3492, 1.35,   1.3505, 1.351,
        1.3518, 1.3522, 1.3530, 1.3535, 1.354,
        1.3545, 1.355,  1.3555, 1.356,  1.3568,
        1.3572, 1.358,  1.3585, 1.359,  1.3595,
        1.36,   1.3608
    };

    G4double Absorption[nEntries] = {
        3.448, 3.448 * CLHEP::m,  4.082 * CLHEP::m,  6.329 * CLHEP::m,  9.174 * CLHEP::m, 12.346 * CLHEP::m, 13.889 * CLHEP::m,
        15.152 * CLHEP::m, 17.241 * CLHEP::m, 18.868 * CLHEP::m, 20.000 * CLHEP::m, 26.316 * CLHEP::m, 35.714 * CLHEP::m,
        45.455 * CLHEP::m, 47.619 * CLHEP::m, 52.632 * CLHEP::m, 52.632 * CLHEP::m, 55.556 * CLHEP::m, 52.632 * CLHEP::m,
        52.632 * CLHEP::m, 47.619 * CLHEP::m, 45.455 * CLHEP::m, 41.667 * CLHEP::m, 37.037 * CLHEP::m, 33.333 * CLHEP::m,
        30.000 * CLHEP::m, 28.500 * CLHEP::m, 27.000 * CLHEP::m, 24.500 * CLHEP::m, 22.000 * CLHEP::m, 19.500 * CLHEP::m,
        17.500 * CLHEP::m, 14.500 * CLHEP::m
    };

    G4double ScintilFast[nEntries] = {
        1.00,   1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00,
        1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00,
        1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00,
        1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00,
        1.00, 1.00, 1.00, 1.00
    };
    G4double ScintilSlow[nEntries] = {
        0.01,   0.01, 1.00, 2.00, 3.00, 4.00, 5.00, 6.00,
        7.00, 8.00, 9.00, 8.00, 7.00, 6.00, 4.00,
        3.00, 2.00, 1.00, 0.01, 1.00, 2.00, 3.00,
        4.00, 5.00, 6.00, 7.00, 8.00, 9.00, 8.00,
        7.00, 6.00, 5.00, 4.00
    };

    G4MaterialPropertiesTable *myMPT = new G4MaterialPropertiesTable();
    myMPT->AddProperty ("RINDEX",       PhotonEnergy, RefractiveIndex, nEntries);
    myMPT->AddProperty ("ABSLENGTH",    PhotonEnergy, Absorption,      nEntries);
    myMPT->AddProperty ("FASTCOMPONENT", PhotonEnergy, ScintilFast,     nEntries);
    myMPT->AddProperty ("SLOWCOMPONENT", PhotonEnergy, ScintilSlow,     nEntries);

    myMPT->AddConstProperty ("SCINTILLATIONYIELD", 50. / CLHEP::MeV);
    myMPT->AddConstProperty ("RESOLUTIONSCALE", 1.0);
    myMPT->AddConstProperty ("FASTTIMECONSTANT", 1.*CLHEP::ns);
    myMPT->AddConstProperty ("SLOWTIMECONSTANT", 10.*CLHEP::ns);
    myMPT->AddConstProperty ("YIELDRATIO", 0.8);

    Water->SetMaterialPropertiesTable (myMPT);

    return Water;
}
G4Material *MyMaterials::Vacuum()
{
    G4double a, z, density;
    G4int nelements;

    G4Element *N = new G4Element ("Nitrogen", "N", z = 7 , a = 14.01 * CLHEP::g / CLHEP::mole);
    G4Element *O = new G4Element ("Oxygen"  , "O", z = 8 , a = 16.00 * CLHEP::g / CLHEP::mole);

    G4Material *Air = new G4Material ("Air", density = 0.001 * CLHEP::mg / CLHEP::cm3, nelements = 2);
    Air->AddElement (N, 70.*CLHEP::cm3);
    Air->AddElement (O, 30.*CLHEP::cm3);

    const G4int nEntries = 3;

    G4double PhotonEnergy[nEntries] =
    { 0.0001 * CLHEP::eV, 1.00 * CLHEP::eV, 100.00 * CLHEP::eV };

    G4double RefractiveIndex[nEntries] =
    { 1.00, 1.00, 1.00 };

    G4MaterialPropertiesTable *myMPT = new G4MaterialPropertiesTable();
    myMPT->AddProperty ("RINDEX", PhotonEnergy, RefractiveIndex, nEntries);

    Air->SetMaterialPropertiesTable (myMPT);

    return Air;
}
G4Material *MyMaterials::Silicon()
{
    G4double a, z, density;

    G4Element *Si = new G4Element ("Silicon",    "Si", z = 14., a = 28.09 * CLHEP::g / CLHEP::mole);
    G4Material *Silicon = new G4Material ("Silicon", density = 2.33 * CLHEP::g / CLHEP::cm3, 1);
    Silicon->AddElement (Si, 1);

    const G4int NUM = 4;

    G4double Energy[NUM]         = { 0.0001 * CLHEP::eV, 1.0 * CLHEP::eV, 1.84 * CLHEP::eV, 4.08 * CLHEP::eV };
    G4double RIND_INDEX[NUM]     = { 4.0, 4.0, 4.0, 4.0 };
    G4double ABS_LENGTH[NUM]     = { 0.1 * CLHEP::mm, 0.1 * CLHEP::mm, 0.1 * CLHEP::mm, 0.1 * CLHEP::mm};

    G4MaterialPropertiesTable *Si_mt = new G4MaterialPropertiesTable();
    Si_mt->AddProperty ("RINDEX",        Energy,  RIND_INDEX,     NUM);
    Si_mt->AddProperty ("ABSLENGTH",     Energy,  ABS_LENGTH,     NUM);

    Silicon->SetMaterialPropertiesTable (Si_mt);

    return Silicon;

}
G4Material *MyMaterials::OpticalGrease()
{
    G4double a, z, density;
    G4Element *H = new G4Element ("Hydrogen", "H", z = 1 , a = 1.01 * CLHEP::g / CLHEP::mole);
    G4Element *O = new G4Element ("Oxygen"  , "O", z = 8 , a = 16.00 * CLHEP::g / CLHEP::mole);
    G4Element *C = new G4Element ("Carbon"  , "C", z = 6 , a = 12.01 * CLHEP::g / CLHEP::mole);

    G4Material *Grease = new G4Material ("Grease", density = 1.0 * CLHEP::g / CLHEP::cm3, 3);
    Grease->AddElement (C, 1);
    Grease->AddElement (H, 1);
    Grease->AddElement (O, 1);

    const G4int nEntries = 34;

    G4double PhotonEnergy[nEntries] = {
        0.0001 * CLHEP::eV, 1.0 * CLHEP::eV, 2.034 * CLHEP::eV, 2.068 * CLHEP::eV, 2.103 * CLHEP::eV, 2.139 * CLHEP::eV,
        2.177 * CLHEP::eV, 2.216 * CLHEP::eV, 2.256 * CLHEP::eV, 2.298 * CLHEP::eV,
        2.341 * CLHEP::eV, 2.386 * CLHEP::eV, 2.433 * CLHEP::eV, 2.481 * CLHEP::eV,
        2.532 * CLHEP::eV, 2.585 * CLHEP::eV, 2.640 * CLHEP::eV, 2.697 * CLHEP::eV,
        2.757 * CLHEP::eV, 2.820 * CLHEP::eV, 2.885 * CLHEP::eV, 2.954 * CLHEP::eV,
        3.026 * CLHEP::eV, 3.102 * CLHEP::eV, 3.181 * CLHEP::eV, 3.265 * CLHEP::eV,
        3.353 * CLHEP::eV, 3.446 * CLHEP::eV, 3.545 * CLHEP::eV, 3.649 * CLHEP::eV,
        3.760 * CLHEP::eV, 3.877 * CLHEP::eV, 4.002 * CLHEP::eV, 4.136 * CLHEP::eV
    };

    G4double RefractiveIndex[nEntries] = {
        1.50, 1.50, 1.50, 1.50, 1.50, 1.50, 1.50, 1.50, 1.50,
        1.50, 1.50, 1.50, 1.50, 1.50, 1.50, 1.50,
        1.50, 1.50, 1.50, 1.50, 1.50, 1.50, 1.50,
        1.50, 1.50, 1.50, 1.50, 1.50, 1.50, 1.50,
        1.50, 1.50, 1.50, 1.50
    };

//   G4double Absorption[nEntries] =
//    { 3.448*m, 3.448*m,  4.082*m,  6.329*m,  9.174*m, 12.346*m, 13.889*m,
//            15.152*m, 17.241*m, 18.868*m, 20.000*m, 26.316*m, 35.714*m,
//            45.455*m, 47.619*m, 52.632*m, 52.632*m, 55.556*m, 52.632*m,
//            52.632*m, 47.619*m, 45.455*m, 41.667*m, 37.037*m, 33.333*m,
//            30.000*m, 28.500*m, 27.000*m, 24.500*m, 22.000*m, 19.500*m,
//            17.500*m, 14.500*m };

    G4MaterialPropertiesTable *myMPT = new G4MaterialPropertiesTable();
    myMPT->AddProperty ("RINDEX",       PhotonEnergy, RefractiveIndex, nEntries);
//   myMPT->AddProperty("ABSLENGTH",    PhotonEnergy, Absorption,      nEntries);
    Grease->SetMaterialPropertiesTable (myMPT);
    return Grease;
}


G4Material *MyMaterials::LUAGCE()  // Lutetium Aluminum Garnet
{
    G4double a, z, density;
    G4Element  *O = new G4Element ("Oxygen",    "O",   z = 8,  a = 16.00 * CLHEP::g / CLHEP::mole);
    G4Element *Lu = new G4Element ("Lutetium",  "Lu",  z = 71, a = 174.97 * CLHEP::g / CLHEP::mole);
    G4Element *Al = new G4Element ("Aluminum",  "Al",  z = 27, a = 28.09 * CLHEP::g / CLHEP::mole);

    G4Material *mat = new G4Material ("LUAG", density = 6.7 * CLHEP::g / CLHEP::cm3, 3);
    mat->AddElement (Lu, 3);
    mat->AddElement (Al, 12);
    mat->AddElement (O, 5);


    // large band between 470 (2.64 CLHEP::eV) and 630 nm (1.97 CLHEP::eV) (mean 535 nm, 2.32)
    const G4int NUMENTRIES_1 = 6;
    G4double FAST_Energy[NUMENTRIES_1]    = {1.0 * CLHEP::eV, 1.90 * CLHEP::eV, 1.97 * CLHEP::eV, 2.64 * CLHEP::eV, 2.70 * CLHEP::eV, 4.08 * CLHEP::eV};
    G4double FAST_COMPONENT[NUMENTRIES_1] = {0.00, 0.00, 1.0, 1.0, 0.00, 0.00};


    const G4int NUMENTRIES_2 = 3;
    G4double RIND_Energy[NUMENTRIES_2]    = { 1.0 * CLHEP::eV, 1.84 * CLHEP::eV, 4.08 * CLHEP::eV };
    G4double RIND_INDEX[NUMENTRIES_2]     = { 1.82, 1.82, 1.82 };
    G4double ABS_Energy[NUMENTRIES_2]     = { 1.0 * CLHEP::eV, 1.84 * CLHEP::eV, 4.08 * CLHEP::eV };
    //G4double ABS_LENGTH[NUMENTRIES_2]     = { 50.*m, 50.*m, 50.*m};
    G4double ABS_LENGTH[NUMENTRIES_2]       = { 138.*CLHEP::mm, 138.*CLHEP::mm, 138.*CLHEP::mm };
    //G4double Rayleigh[NUMENTRIES_2]       = { 138.*mm, 138.*mm, 138.*mm};

    G4MaterialPropertiesTable *mt = new G4MaterialPropertiesTable();
    mt->AddProperty ("FASTCOMPONENT", FAST_Energy, FAST_COMPONENT, NUMENTRIES_1);
    mt->AddProperty ("RINDEX",        RIND_Energy, RIND_INDEX,     NUMENTRIES_2);
    mt->AddProperty ("ABSLENGTH",     ABS_Energy,  ABS_LENGTH,     NUMENTRIES_2);
    //mt->AddProperty("RAYLEIGH",      ABS_Energy,  Rayleigh,     NUMENTRIES_2);
    mt->AddConstProperty ("SCINTILLATIONYIELD", 15000 / CLHEP::MeV);
    mt->AddConstProperty ("RESOLUTIONSCALE", 8.5);
    mt->AddConstProperty ("FASTTIMECONSTANT", 60.*CLHEP::ns);
    mt->AddConstProperty ("YIELDRATIO", 1.0);
    mt->AddConstProperty ("FASTSCINTILLATIONRISETIME", 0.5 * CLHEP::ns);
    mat->SetMaterialPropertiesTable (mt);


    return mat;
}
G4Material *MyMaterials::LUAGPR()
{
    G4double a, z, density;
    G4Element  *O = new G4Element ("Oxygen",    "O",   z = 8,  a = 16.00 * CLHEP::g / CLHEP::mole);
    G4Element *Lu = new G4Element ("Lutetium",  "Lu",  z = 71, a = 174.97 * CLHEP::g / CLHEP::mole);
    G4Element *Al = new G4Element ("Aluminum",  "Al",  z = 27, a = 28.09 * CLHEP::g / CLHEP::mole);

    G4Material *mat = new G4Material ("LUAG", density = 6.7 * CLHEP::g / CLHEP::cm3, 3);
    mat->AddElement (Lu, 3);
    mat->AddElement (Al, 12);
    mat->AddElement (O, 5);

    //  2 bands at 290nm (4.28CLHEP::eV) and 350nm (3.54CLHEP::eV) about 50% of the light in each.
    const G4int NUMENTRIES_1 = 8;
    G4double FAST_Energy[NUMENTRIES_1]    = {1.0 * CLHEP::eV, 3.4 * CLHEP::eV, 3.5 * CLHEP::eV, 3.60 * CLHEP::eV, 3.90 * CLHEP::eV, 3.91 * CLHEP::eV, 4.07 * CLHEP::eV, 4.08 * CLHEP::eV};
    G4double FAST_COMPONENT[NUMENTRIES_1] = {0.00  , 0.00,  1.00,  0.0,    0.0,    1.0,    0.0,    0.0    };

    const G4int NUMENTRIES_2 = 3;
    G4double RIND_Energy[NUMENTRIES_2]    = { 1.0 * CLHEP::eV, 1.84 * CLHEP::eV, 4.08 * CLHEP::eV };
    G4double RIND_INDEX[NUMENTRIES_2]     = { 1.82, 1.82, 1.82 };
    G4double ABS_Energy[NUMENTRIES_2]     = { 1.0 * CLHEP::eV, 1.84 * CLHEP::eV, 4.08 * CLHEP::eV };
    G4double ABS_LENGTH[NUMENTRIES_2]       = { 138.*CLHEP::mm, 138.*CLHEP::mm, 138.*CLHEP::mm };
    //G4double Rayleigh[NUMENTRIES_2]       = { 138.*mm, 138.*mm, 138.*mm};

    G4MaterialPropertiesTable *mt = new G4MaterialPropertiesTable();
    mt->AddProperty ("FASTCOMPONENT", FAST_Energy, FAST_COMPONENT, NUMENTRIES_1);
    mt->AddProperty ("RINDEX",        RIND_Energy, RIND_INDEX,     NUMENTRIES_2);
    mt->AddProperty ("ABSLENGTH",     ABS_Energy,  ABS_LENGTH,     NUMENTRIES_2);
    //mt->AddProperty("RAYLEIGH",      ABS_Energy,  Rayleigh,     NUMENTRIES_2);
    mt->AddConstProperty ("SCINTILLATIONYIELD", 7000 / CLHEP::MeV);
    mt->AddConstProperty ("RESOLUTIONSCALE", 6.4);
    mt->AddConstProperty ("FASTTIMECONSTANT", 20.*CLHEP::ns);
    mt->AddConstProperty ("YIELDRATIO", 1.0);
    mt->AddConstProperty ("FASTSCINTILLATIONRISETIME", 0.5 * CLHEP::ns);
    mat->SetMaterialPropertiesTable (mt);


    return mat;
}
G4Material *MyMaterials::LYSO()
{
    G4double a, z, density;
    G4Element  *O = new G4Element ("Oxygen",    "O",   z = 8.,  a = 16.00 * CLHEP::g / CLHEP::mole);
    G4Element *Lu = new G4Element ("Lutetium",  "Lu",  z = 71., a = 174.97 * CLHEP::g / CLHEP::mole);
    G4Element *Si = new G4Element ("Silicon",   "Si",  z = 14., a = 28.09 * CLHEP::g / CLHEP::mole);

    G4Material *mat = new G4Material ("LYSO", density = 7.1 * CLHEP::g / CLHEP::cm3, 3, kStateSolid);
    mat->AddElement (Lu, 2);
    mat->AddElement (Si, 1);
    mat->AddElement (O, 5);

    const G4int NUMENTRIES_1 = 261;
    G4double FAST_Energy[NUMENTRIES_1] = {
        1.77169 * CLHEP::eV,
        1.77266 * CLHEP::eV,
        1.77558 * CLHEP::eV,
        1.77851 * CLHEP::eV,
        1.78145 * CLHEP::eV,
        1.78539 * CLHEP::eV,
        1.79033 * CLHEP::eV,
        1.7963 * CLHEP::eV,
        1.80231 * CLHEP::eV,
        1.80836 * CLHEP::eV,
        1.81445 * CLHEP::eV,
        1.82058 * CLHEP::eV,
        1.82882 * CLHEP::eV,
        1.83401 * CLHEP::eV,
        1.84553 * CLHEP::eV,
        1.85293 * CLHEP::eV,
        1.86147 * CLHEP::eV,
        1.869 * CLHEP::eV,
        1.87769 * CLHEP::eV,
        1.89308 * CLHEP::eV,
        1.90536 * CLHEP::eV,
        1.92007 * CLHEP::eV,
        1.93039 * CLHEP::eV,
        1.94901 * CLHEP::eV,
        1.95846 * CLHEP::eV,
        1.9668 * CLHEP::eV,
        1.97884 * CLHEP::eV,
        1.99102 * CLHEP::eV,
        2.00088 * CLHEP::eV,
        2.01209 * CLHEP::eV,
        2.02596 * CLHEP::eV,
        2.03617 * CLHEP::eV,
        2.04519 * CLHEP::eV,
        2.0569 * CLHEP::eV,
        2.06611 * CLHEP::eV,
        2.0794 * CLHEP::eV,
        2.09151 * CLHEP::eV,
        2.10239 * CLHEP::eV,
        2.112 * CLHEP::eV,
        2.1231 * CLHEP::eV,
        2.13431 * CLHEP::eV,
        2.14565 * CLHEP::eV,
        2.15566 * CLHEP::eV,
        2.16868 * CLHEP::eV,
        2.18038 * CLHEP::eV,
        2.19519 * CLHEP::eV,
        2.21171 * CLHEP::eV,
        2.2193 * CLHEP::eV,
        2.23619 * CLHEP::eV,
        2.23464 * CLHEP::eV,
        2.24395 * CLHEP::eV,
        2.25806 * CLHEP::eV,
        2.27234 * CLHEP::eV,
        2.28358 * CLHEP::eV,
        2.29493 * CLHEP::eV,
        2.30475 * CLHEP::eV,
        2.31631 * CLHEP::eV,
        2.32463 * CLHEP::eV,
        2.33134 * CLHEP::eV,
        2.33809 * CLHEP::eV,
        2.34487 * CLHEP::eV,
        2.35856 * CLHEP::eV,
        2.36719 * CLHEP::eV,
        2.37939 * CLHEP::eV,
        2.38642 * CLHEP::eV,
        2.40238 * CLHEP::eV,
        2.41134 * CLHEP::eV,
        2.424 * CLHEP::eV,
        2.43312 * CLHEP::eV,
        2.44047 * CLHEP::eV,
        2.44786 * CLHEP::eV,
        2.46278 * CLHEP::eV,
        2.47788 * CLHEP::eV,
        2.48741 * CLHEP::eV,
        2.49317 * CLHEP::eV,
        2.49702 * CLHEP::eV,
        2.50282 * CLHEP::eV,
        2.50865 * CLHEP::eV,
        2.5145 * CLHEP::eV,
        2.52038 * CLHEP::eV,
        2.52432 * CLHEP::eV,
        2.53223 * CLHEP::eV,
        2.5362 * CLHEP::eV,
        2.54619 * CLHEP::eV,
        2.55424 * CLHEP::eV,
        2.56031 * CLHEP::eV,
        2.56437 * CLHEP::eV,
        2.57049 * CLHEP::eV,
        2.57663 * CLHEP::eV,
        2.58487 * CLHEP::eV,
        2.59317 * CLHEP::eV,
        2.59734 * CLHEP::eV,
        2.60571 * CLHEP::eV,
        2.61414 * CLHEP::eV,
        2.61414 * CLHEP::eV,
        2.61837 * CLHEP::eV,
        2.62262 * CLHEP::eV,
        2.62475 * CLHEP::eV,
        2.62902 * CLHEP::eV,
        2.63331 * CLHEP::eV,
        2.63545 * CLHEP::eV,
        2.63976 * CLHEP::eV,
        2.64191 * CLHEP::eV,
        2.64841 * CLHEP::eV,
        2.65493 * CLHEP::eV,
        2.6593 * CLHEP::eV,
        2.66149 * CLHEP::eV,
        2.66588 * CLHEP::eV,
        2.67914 * CLHEP::eV,
        2.67914 * CLHEP::eV,
        2.68136 * CLHEP::eV,
        2.68136 * CLHEP::eV,
        2.68359 * CLHEP::eV,
        2.68805 * CLHEP::eV,
        2.68805 * CLHEP::eV,
        2.68805 * CLHEP::eV,
        2.69477 * CLHEP::eV,
        2.69477 * CLHEP::eV,
        2.69702 * CLHEP::eV,
        2.70153 * CLHEP::eV,
        2.70605 * CLHEP::eV,
        2.71286 * CLHEP::eV,
        2.71742 * CLHEP::eV,
        2.71971 * CLHEP::eV,
        2.722 * CLHEP::eV,
        2.722 * CLHEP::eV,
        2.72429 * CLHEP::eV,
        2.72889 * CLHEP::eV,
        2.72889 * CLHEP::eV,
        2.73351 * CLHEP::eV,
        2.73814 * CLHEP::eV,
        2.74279 * CLHEP::eV,
        2.74512 * CLHEP::eV,
        2.74979 * CLHEP::eV,
        2.75213 * CLHEP::eV,
        2.75447 * CLHEP::eV,
        2.75917 * CLHEP::eV,
        2.75682 * CLHEP::eV,
        2.76389 * CLHEP::eV,
        2.76626 * CLHEP::eV,
        2.76389 * CLHEP::eV,
        2.76626 * CLHEP::eV,
        2.77338 * CLHEP::eV,
        2.77576 * CLHEP::eV,
        2.78533 * CLHEP::eV,
        2.79255 * CLHEP::eV,
        2.79738 * CLHEP::eV,
        2.80223 * CLHEP::eV,
        2.80466 * CLHEP::eV,
        2.80709 * CLHEP::eV,
        2.80953 * CLHEP::eV,
        2.80953 * CLHEP::eV,
        2.81934 * CLHEP::eV,
        2.8218 * CLHEP::eV,
        2.82673 * CLHEP::eV,
        2.83168 * CLHEP::eV,
        2.84164 * CLHEP::eV,
        2.84916 * CLHEP::eV,
        2.85419 * CLHEP::eV,
        2.8643 * CLHEP::eV,
        2.86684 * CLHEP::eV,
        2.87449 * CLHEP::eV,
        2.87705 * CLHEP::eV,
        2.87961 * CLHEP::eV,
        2.88475 * CLHEP::eV,
        2.88733 * CLHEP::eV,
        2.8925 * CLHEP::eV,
        2.89509 * CLHEP::eV,
        2.90028 * CLHEP::eV,
        2.90549 * CLHEP::eV,
        2.90811 * CLHEP::eV,
        2.91073 * CLHEP::eV,
        2.91335 * CLHEP::eV,
        2.91335 * CLHEP::eV,
        2.91335 * CLHEP::eV,
        2.91861 * CLHEP::eV,
        2.92125 * CLHEP::eV,
        2.92125 * CLHEP::eV,
        2.92389 * CLHEP::eV,
        2.92654 * CLHEP::eV,
        2.92654 * CLHEP::eV,
        2.92919 * CLHEP::eV,
        2.92919 * CLHEP::eV,
        2.93185 * CLHEP::eV,
        2.93451 * CLHEP::eV,
        2.93717 * CLHEP::eV,
        2.93985 * CLHEP::eV,
        2.94252 * CLHEP::eV,
        2.9452 * CLHEP::eV,
        2.94789 * CLHEP::eV,
        2.94789 * CLHEP::eV,
        2.94789 * CLHEP::eV,
        2.95058 * CLHEP::eV,
        2.95868 * CLHEP::eV,
        2.96411 * CLHEP::eV,
        2.96955 * CLHEP::eV,
        2.97228 * CLHEP::eV,
        2.97228 * CLHEP::eV,
        2.96955 * CLHEP::eV,
        2.97228 * CLHEP::eV,
        2.97502 * CLHEP::eV,
        2.97776 * CLHEP::eV,
        2.97502 * CLHEP::eV,
        2.9805 * CLHEP::eV,
        2.9805 * CLHEP::eV,
        2.9805 * CLHEP::eV,
        2.98601 * CLHEP::eV,
        2.99154 * CLHEP::eV,
        2.99431 * CLHEP::eV,
        2.99431 * CLHEP::eV,
        2.99708 * CLHEP::eV,
        2.99431 * CLHEP::eV,
        2.99708 * CLHEP::eV,
        3.00544 * CLHEP::eV,
        3.00824 * CLHEP::eV,
        3.00824 * CLHEP::eV,
        3.00824 * CLHEP::eV,
        3.00824 * CLHEP::eV,
        3.01385 * CLHEP::eV,
        3.0223 * CLHEP::eV,
        3.02797 * CLHEP::eV,
        3.03081 * CLHEP::eV,
        3.02797 * CLHEP::eV,
        3.03365 * CLHEP::eV,
        3.03081 * CLHEP::eV,
        3.03081 * CLHEP::eV,
        3.0365 * CLHEP::eV,
        3.03935 * CLHEP::eV,
        3.04221 * CLHEP::eV,
        3.04795 * CLHEP::eV,
        3.04795 * CLHEP::eV,
        3.05083 * CLHEP::eV,
        3.05371 * CLHEP::eV,
        3.05949 * CLHEP::eV,
        3.06239 * CLHEP::eV,
        3.06529 * CLHEP::eV,
        3.0682 * CLHEP::eV,
        3.06529 * CLHEP::eV,
        3.07112 * CLHEP::eV,
        3.0682 * CLHEP::eV,
        3.07696 * CLHEP::eV,
        3.08283 * CLHEP::eV,
        3.0976 * CLHEP::eV,
        3.09464 * CLHEP::eV,
        3.09464 * CLHEP::eV,
        3.10653 * CLHEP::eV,
        3.11252 * CLHEP::eV,
        3.11852 * CLHEP::eV,
        3.12757 * CLHEP::eV,
        3.13668 * CLHEP::eV,
        3.14583 * CLHEP::eV,
        3.15813 * CLHEP::eV,
        3.16741 * CLHEP::eV,
        3.17675 * CLHEP::eV,
        3.20828 * CLHEP::eV,
        3.23719 * CLHEP::eV,
        3.26664 * CLHEP::eV,
        3.28656 * CLHEP::eV,
        3.31351 * CLHEP::eV,
        3.34783 * CLHEP::eV,
        3.38287 * CLHEP::eV,
    };
    G4double FAST_COMPONENT[NUMENTRIES_1] = {
        0.011691,
        0.011691,
        0.011691,
        0.0146138,
        0.0146138,
        0.0146138,
        0.011691,
        0.011691,
        0.00876827,
        0.00876827,
        0.00584551,
        0.00584551,
        0.00584551,
        0.00292276,
        0.00876827,
        0.0146138,
        0.0146138,
        0.0146138,
        0.0204593,
        0.023382,
        0.0263048,
        0.0204593,
        0.0204593,
        0.023382,
        0.0292276,
        0.0321503,
        0.0350731,
        0.0379958,
        0.0379958,
        0.0379958,
        0.0350731,
        0.0379958,
        0.0409186,
        0.0438413,
        0.0526096,
        0.0584551,
        0.0643006,
        0.0730689,
        0.0730689,
        0.0818372,
        0.0906054,
        0.0964509,
        0.0993737,
        0.105219,
        0.111065,
        0.122756,
        0.125678,
        0.146138,
        0.146138,
        0.160752,
        0.157829,
        0.163674,
        0.184134,
        0.192902,
        0.20167,
        0.219207,
        0.230898,
        0.242589,
        0.25428,
        0.265971,
        0.274739,
        0.292276,
        0.306889,
        0.315658,
        0.321503,
        0.350731,
        0.368267,
        0.385804,
        0.397495,
        0.415031,
        0.432568,
        0.458873,
        0.482255,
        0.496868,
        0.514405,
        0.529019,
        0.549478,
        0.564092,
        0.581628,
        0.593319,
        0.602088,
        0.616701,
        0.637161,
        0.660543,
        0.681002,
        0.71023,
        0.736534,
        0.756994,
        0.777453,
        0.806681,
        0.844676,
        0.868058,
        0.891441,
        0.9119,
        0.938205,
        0.955741,
        0.984969,
        1.0142,
        1.03173,
        1.05511,
        1.07557,
        1.11649,
        1.13695,
        1.15741,
        1.17495,
        1.19248,
        1.21002,
        1.22756,
        1.27432,
        1.2977,
        1.31524,
        1.32985,
        1.36785,
        1.40292,
        1.39415,
        1.4,
        1.41754,
        1.44092,
        1.47015,
        1.48476,
        1.50814,
        1.5286,
        1.54906,
        1.56952,
        1.58998,
        1.61921,
        1.63967,
        1.66597,
        1.68935,
        1.71566,
        1.73904,
        1.76242,
        1.77996,
        1.80042,
        1.8238,
        1.83549,
        1.85303,
        1.8618,
        1.87933,
        1.89979,
        1.91733,
        1.92902,
        1.95825,
        1.98163,
        2.01378,
        2.03424,
        2.0547,
        2.07808,
        2.09562,
        2.11023,
        2.12484,
        2.13361,
        2.15407,
        2.15699,
        2.15992,
        2.16576,
        2.16868,
        2.16868,
        2.16284,
        2.15699,
        2.14823,
        2.13946,
        2.12484,
        2.11023,
        2.08977,
        2.06639,
        2.04593,
        2.02839,
        2.01086,
        1.98455,
        1.96409,
        1.94948,
        1.93194,
        1.91733,
        1.90271,
        1.87641,
        1.86472,
        1.8501,
        1.83841,
        1.82088,
        1.79749,
        1.77119,
        1.75073,
        1.73027,
        1.70689,
        1.68058,
        1.65428,
        1.6309,
        1.60167,
        1.57244,
        1.55491,
        1.53152,
        1.50522,
        1.47891,
        1.45261,
        1.43215,
        1.40877,
        1.38831,
        1.362,
        1.33862,
        1.31232,
        1.28601,
        1.27432,
        1.25678,
        1.21587,
        1.19541,
        1.17203,
        1.14864,
        1.12234,
        1.10772,
        1.08434,
        1.06096,
        1.0142,
        0.987891,
        0.967432,
        0.938205,
        0.9119,
        0.879749,
        0.853445,
        0.82714,
        0.786221,
        0.765762,
        0.739457,
        0.716075,
        0.681002,
        0.660543,
        0.637161,
        0.60501,
        0.581628,
        0.552401,
        0.531942,
        0.505637,
        0.485177,
        0.458873,
        0.435491,
        0.412109,
        0.379958,
        0.356576,
        0.336117,
        0.309812,
        0.280585,
        0.25428,
        0.207516,
        0.175365,
        0.157829,
        0.13737,
        0.119833,
        0.0993737,
        0.0759916,
        0.0613779,
        0.0526096,
        0.0350731,
        0.0263048,
        0.011691,
        0.00876827,
        0.00876827,
        0.011691,
        0.011691,
        0.011691,
        0.00876827,
        0.011691,
    };



    const G4int NUMENTRIES_2 = 3;
    G4double RIND_Energy[NUMENTRIES_2]    = { 1.0 * CLHEP::eV, 1.84 * CLHEP::eV, 4.08 * CLHEP::eV };
    G4double RIND_INDEX[NUMENTRIES_2]     = { 1.82, 1.82, 1.82 };

    const G4int NUMENTRIES_3 = 9;
    G4double ABS_Energy[NUMENTRIES_3]     = { 1.00 * CLHEP::eV , 2.82 * CLHEP::eV , 2.88 * CLHEP::eV , 2.95 * CLHEP::eV , 3.02 * CLHEP::eV  , 3.10 * CLHEP::eV  , 3.18 * CLHEP::eV  , 3.26 * CLHEP::eV , 4.08 * CLHEP::eV };
    G4double ABS_LENGTH[NUMENTRIES_3]     = { 438.*CLHEP::mm , 438.*CLHEP::mm , 413.*CLHEP::mm , 375.*CLHEP::mm , 263.*CLHEP::mm  , 87.5 * CLHEP::mm  , 11.5 * CLHEP::mm  , 1.0 * CLHEP::mm  , 1.0 * CLHEP::mm  };

//const G4int NUMENTRIES_3 = 3;
//G4double ABS_Energy[NUMENTRIES_3]     = { 1.0*CLHEP::eV, 1.84*CLHEP::eV, 4.08*CLHEP::eV };
//G4double ABS_LENGTH[NUMENTRIES_3]       = { 138000.*CLHEP::mm, 138000.*CLHEP::mm, 138000.*CLHEP::mm };
//G4double ABS_LENGTH[NUMENTRIES_3]       = { 500.*CLHEP::mm, 500.*CLHEP::mm, 500.*CLHEP::mm };


    //G4double Rayleigh[NUMENTRIES_2]       = { 138.*CLHEP::mm, 138.*CLHEP::mm, 138.*CLHEP::mm};


    G4MaterialPropertiesTable *mt = new G4MaterialPropertiesTable();
    mt->AddProperty ("FASTCOMPONENT", FAST_Energy, FAST_COMPONENT, NUMENTRIES_1);
    mt->AddProperty ("RINDEX",        RIND_Energy, RIND_INDEX,     NUMENTRIES_2);
    mt->AddProperty ("ABSLENGTH",     ABS_Energy,  ABS_LENGTH,     NUMENTRIES_3);
    //mt->AddProperty("RAYLEIGH",      ABS_Energy,  Rayleigh,     NUMENTRIES_2);
    mt->AddConstProperty ("SCINTILLATIONYIELD", 40000. / CLHEP::MeV);
    mt->AddConstProperty ("RESOLUTIONSCALE", 3.4);
    mt->AddConstProperty ("FASTTIMECONSTANT", 40.*CLHEP::ns);
    mt->AddConstProperty ("YIELDRATIO", 1.0);
    mt->AddConstProperty ("FASTSCINTILLATIONRISETIME", 0.1 * CLHEP::ns);
    mat->SetMaterialPropertiesTable (mt);


    return mat;
}
G4Material *MyMaterials::LSO()
{
    G4double a, z, density;
    G4Element  *O = new G4Element ("Oxygen",    "O",   z = 8.,  a = 16.00 * CLHEP::g / CLHEP::mole);
    G4Element *Lu = new G4Element ("Lutetium",  "Lu",  z = 71., a = 174.97 * CLHEP::g / CLHEP::mole);
    G4Element *Si = new G4Element ("Silicon",   "Si",  z = 14., a = 28.09 * CLHEP::g / CLHEP::mole);

    G4Material *LSO = new G4Material ("LSO", density = 7.4 * CLHEP::g / CLHEP::cm3, 3);
    LSO->AddElement (Lu, 2);
    LSO->AddElement (Si, 1);
    LSO->AddElement (O, 5);

    const G4int LSO_NUMENTRIES_1 = 193;
    G4double LSO_FAST_Energy[LSO_NUMENTRIES_1] = {
        1.83966 * CLHEP::eV,
        1.84948 * CLHEP::eV,
        1.86274 * CLHEP::eV,
        1.87507 * CLHEP::eV,
        1.88413 * CLHEP::eV,
        1.90369 * CLHEP::eV,
        1.91187 * CLHEP::eV,
        1.92129 * CLHEP::eV,
        1.92962 * CLHEP::eV,
        1.93922 * CLHEP::eV,
        1.95258 * CLHEP::eV,
        1.96365 * CLHEP::eV,
        1.97986 * CLHEP::eV,
        1.99124 * CLHEP::eV,
        2.00533 * CLHEP::eV,
        2.02618 * CLHEP::eV,
        2.04747 * CLHEP::eV,
        2.06101 * CLHEP::eV,
        2.07472 * CLHEP::eV,
        2.09424 * CLHEP::eV,
        2.11269 * CLHEP::eV,
        2.12565 * CLHEP::eV,
        2.14466 * CLHEP::eV,
        2.16251 * CLHEP::eV,
        2.17914 * CLHEP::eV,
        2.19602 * CLHEP::eV,
        2.21317 * CLHEP::eV,
        2.22422 * CLHEP::eV,
        2.24021 * CLHEP::eV,
        2.25479 * CLHEP::eV,
        2.26462 * CLHEP::eV,
        2.27785 * CLHEP::eV,
        2.29462 * CLHEP::eV,
        2.30821 * CLHEP::eV,
        2.32024 * CLHEP::eV,
        2.33588 * CLHEP::eV,
        2.34643 * CLHEP::eV,
        2.35529 * CLHEP::eV,
        2.37322 * CLHEP::eV,
        2.38594 * CLHEP::eV,
        2.3896 * CLHEP::eV,
        2.39879 * CLHEP::eV,
        2.40805 * CLHEP::eV,
        2.41365 * CLHEP::eV,
        2.4268 * CLHEP::eV,
        2.44009 * CLHEP::eV,
        2.45161 * CLHEP::eV,
        2.46518 * CLHEP::eV,
        2.47693 * CLHEP::eV,
        2.48483 * CLHEP::eV,
        2.49477 * CLHEP::eV,
        2.50479 * CLHEP::eV,
        2.51692 * CLHEP::eV,
        2.53123 * CLHEP::eV,
        2.5457 * CLHEP::eV,
        2.54986 * CLHEP::eV,
        2.55613 * CLHEP::eV,
        2.56033 * CLHEP::eV,
        2.56665 * CLHEP::eV,
        2.58796 * CLHEP::eV,
        2.59658 * CLHEP::eV,
        2.60091 * CLHEP::eV,
        2.60309 * CLHEP::eV,
        2.60744 * CLHEP::eV,
        2.614 * CLHEP::eV,
        2.62059 * CLHEP::eV,
        2.62943 * CLHEP::eV,
        2.6361 * CLHEP::eV,
        2.64057 * CLHEP::eV,
        2.64729 * CLHEP::eV,
        2.65632 * CLHEP::eV,
        2.66085 * CLHEP::eV,
        2.6654 * CLHEP::eV,
        2.66997 * CLHEP::eV,
        2.67684 * CLHEP::eV,
        2.67684 * CLHEP::eV,
        2.68839 * CLHEP::eV,
        2.69303 * CLHEP::eV,
        2.70237 * CLHEP::eV,
        2.70471 * CLHEP::eV,
        2.71177 * CLHEP::eV,
        2.72124 * CLHEP::eV,
        2.72362 * CLHEP::eV,
        2.73077 * CLHEP::eV,
        2.73077 * CLHEP::eV,
        2.73317 * CLHEP::eV,
        2.73797 * CLHEP::eV,
        2.74279 * CLHEP::eV,
        2.74762 * CLHEP::eV,
        2.7549 * CLHEP::eV,
        2.7549 * CLHEP::eV,
        2.75978 * CLHEP::eV,
        2.75978 * CLHEP::eV,
        2.76468 * CLHEP::eV,
        2.76713 * CLHEP::eV,
        2.77205 * CLHEP::eV,
        2.77699 * CLHEP::eV,
        2.77699 * CLHEP::eV,
        2.77947 * CLHEP::eV,
        2.78941 * CLHEP::eV,
        2.79692 * CLHEP::eV,
        2.80195 * CLHEP::eV,
        2.80699 * CLHEP::eV,
        2.8146 * CLHEP::eV,
        2.81714 * CLHEP::eV,
        2.8248 * CLHEP::eV,
        2.8325 * CLHEP::eV,
        2.83507 * CLHEP::eV,
        2.85063 * CLHEP::eV,
        2.85847 * CLHEP::eV,
        2.86635 * CLHEP::eV,
        2.86899 * CLHEP::eV,
        2.87428 * CLHEP::eV,
        2.87959 * CLHEP::eV,
        2.88225 * CLHEP::eV,
        2.89027 * CLHEP::eV,
        2.89295 * CLHEP::eV,
        2.89833 * CLHEP::eV,
        2.90103 * CLHEP::eV,
        2.90915 * CLHEP::eV,
        2.91186 * CLHEP::eV,
        2.91731 * CLHEP::eV,
        2.92278 * CLHEP::eV,
        2.92278 * CLHEP::eV,
        2.92553 * CLHEP::eV,
        2.93103 * CLHEP::eV,
        2.93103 * CLHEP::eV,
        2.93103 * CLHEP::eV,
        2.94487 * CLHEP::eV,
        2.94487 * CLHEP::eV,
        2.94766 * CLHEP::eV,
        2.95324 * CLHEP::eV,
        2.95604 * CLHEP::eV,
        2.95885 * CLHEP::eV,
        2.95604 * CLHEP::eV,
        2.96166 * CLHEP::eV,
        2.96447 * CLHEP::eV,
        2.97012 * CLHEP::eV,
        2.96166 * CLHEP::eV,
        2.97295 * CLHEP::eV,
        2.98434 * CLHEP::eV,
        2.98434 * CLHEP::eV,
        2.98148 * CLHEP::eV,
        2.98434 * CLHEP::eV,
        2.99006 * CLHEP::eV,
        2.9872 * CLHEP::eV,
        2.99006 * CLHEP::eV,
        2.9872 * CLHEP::eV,
        2.99006 * CLHEP::eV,
        2.99869 * CLHEP::eV,
        3.00447 * CLHEP::eV,
        3.00737 * CLHEP::eV,
        3.0161 * CLHEP::eV,
        3.01902 * CLHEP::eV,
        3.0161 * CLHEP::eV,
        3.0161 * CLHEP::eV,
        3.01318 * CLHEP::eV,
        3.01318 * CLHEP::eV,
        3.02194 * CLHEP::eV,
        3.02781 * CLHEP::eV,
        3.03666 * CLHEP::eV,
        3.03666 * CLHEP::eV,
        3.03666 * CLHEP::eV,
        3.04556 * CLHEP::eV,
        3.05152 * CLHEP::eV,
        3.05152 * CLHEP::eV,
        3.05451 * CLHEP::eV,
        3.05451 * CLHEP::eV,
        3.05451 * CLHEP::eV,
        3.06051 * CLHEP::eV,
        3.05751 * CLHEP::eV,
        3.07258 * CLHEP::eV,
        3.07258 * CLHEP::eV,
        3.07561 * CLHEP::eV,
        3.08169 * CLHEP::eV,
        3.09085 * CLHEP::eV,
        3.08779 * CLHEP::eV,
        3.09085 * CLHEP::eV,
        3.09699 * CLHEP::eV,
        3.10935 * CLHEP::eV,
        3.10625 * CLHEP::eV,
        3.1218 * CLHEP::eV,
        3.12807 * CLHEP::eV,
        3.13121 * CLHEP::eV,
        3.14067 * CLHEP::eV,
        3.15657 * CLHEP::eV,
        3.16941 * CLHEP::eV,
        3.19213 * CLHEP::eV,
        3.21849 * CLHEP::eV,
        3.24529 * CLHEP::eV,
        3.27255 * CLHEP::eV,
        3.28981 * CLHEP::eV,
    };
    G4double LSO_FAST_COMPONENT[LSO_NUMENTRIES_1] = {
        0.0121475,
        0.0121475,
        0.0151844,
        0.0151844,
        0.0151844,
        0.0182213,
        0.0182213,
        0.0182213,
        0.024295,
        0.024295,
        0.0212581,
        0.0212581,
        0.0303688,
        0.0303688,
        0.0303688,
        0.0425163,
        0.0516269,
        0.0607375,
        0.0698482,
        0.072885,
        0.0850325,
        0.0941432,
        0.106291,
        0.127549,
        0.130586,
        0.142733,
        0.163991,
        0.179176,
        0.19436,
        0.212581,
        0.224729,
        0.239913,
        0.252061,
        0.273319,
        0.297614,
        0.318872,
        0.34013,
        0.355315,
        0.376573,
        0.38872,
        0.413015,
        0.4282,
        0.440347,
        0.458568,
        0.47679,
        0.507158,
        0.531453,
        0.567896,
        0.595228,
        0.628633,
        0.652928,
        0.68026,
        0.71974,
        0.759219,
        0.77744,
        0.813883,
        0.835141,
        0.859436,
        0.886768,
        0.920174,
        0.956616,
        0.990022,
        1.00521,
        1.01735,
        1.04165,
        1.06898,
        1.09328,
        1.11757,
        1.15098,
        1.17223,
        1.2026,
        1.23297,
        1.26334,
        1.29067,
        1.32104,
        1.37874,
        1.40304,
        1.43341,
        1.46074,
        1.49414,
        1.52451,
        1.56095,
        1.60043,
        1.63991,
        1.67028,
        1.69761,
        1.72191,
        1.7462,
        1.77354,
        1.81605,
        1.84946,
        1.88286,
        1.88286,
        1.88894,
        1.9102,
        1.94056,
        1.98308,
        2.00434,
        2.03167,
        2.07419,
        2.10759,
        2.13189,
        2.15315,
        2.16833,
        2.17744,
        2.19566,
        2.20781,
        2.20781,
        2.21996,
        2.21692,
        2.20477,
        2.18959,
        2.16833,
        2.14403,
        2.11367,
        2.08026,
        2.04685,
        2.01649,
        1.98308,
        1.94056,
        1.90716,
        1.87679,
        1.84642,
        1.80998,
        1.77354,
        1.73406,
        1.70369,
        1.66421,
        1.60651,
        1.53362,
        1.5154,
        1.49111,
        1.46985,
        1.44252,
        1.4243,
        1.39696,
        1.36356,
        1.318,
        1.26941,
        1.21171,
        1.16616,
        1.13275,
        1.09935,
        1.12972,
        1.11453,
        1.08416,
        1.05683,
        1.02343,
        0.993059,
        0.956616,
        0.929284,
        0.895879,
        0.87462,
        0.835141,
        0.801735,
        0.77744,
        0.747072,
        0.704555,
        0.67115,
        0.640781,
        0.595228,
        0.570933,
        0.540564,
        0.510195,
        0.473753,
        0.443384,
        0.419089,
        0.394794,
        0.373536,
        0.34013,
        0.318872,
        0.276356,
        0.252061,
        0.203471,
        0.185249,
        0.163991,
        0.142733,
        0.127549,
        0.112364,
        0.0911063,
        0.072885,
        0.0577007,
        0.0425163,
        0.0303688,
        0.024295,
        0.00911063,
        0.00607375,
        0.00607375,
        0.00303688,
        0.00303688,
        0.00911063,
        0.00911063,
    };


    const G4int LSO_NUMENTRIES_2 = 4;
    G4double LSO_RIND_Energy[LSO_NUMENTRIES_2]      = { 0.0001 * CLHEP::eV, 1.0 * CLHEP::eV, 1.84 * CLHEP::eV, 4.08 * CLHEP::eV };
    G4double LSO_RIND_INDEX[LSO_NUMENTRIES_2]       = { 1.82, 1.82, 1.82, 1.82 };
    G4double LSO_ABS_Energy[LSO_NUMENTRIES_2]       = { 0.0001 * CLHEP::eV, 1.0 * CLHEP::eV, 1.84 * CLHEP::eV, 4.08 * CLHEP::eV };
    //G4double LSO_ABS_LENGTH[LSO_NUMENTRIES_2]     = { 50.*m, 50.*m, 50.*m};
    G4double LSO_ABS_LENGTH[LSO_NUMENTRIES_2]       = { 1 * CLHEP::mm, 138.*CLHEP::mm, 138.*CLHEP::mm, 138.*CLHEP::mm };
    //G4double LSO_Rayleigh[LSO_NUMENTRIES_2]       = { 138.*CLHEP::mm, 138.*CLHEP::mm, 138.*CLHEP::mm};

    G4MaterialPropertiesTable *LSO_mt = new G4MaterialPropertiesTable();
    LSO_mt->AddProperty ("FASTCOMPONENT", LSO_FAST_Energy, LSO_FAST_COMPONENT, LSO_NUMENTRIES_1);
    LSO_mt->AddProperty ("RINDEX",        LSO_RIND_Energy, LSO_RIND_INDEX,     LSO_NUMENTRIES_2);
    LSO_mt->AddProperty ("ABSLENGTH",     LSO_ABS_Energy,  LSO_ABS_LENGTH,     LSO_NUMENTRIES_2);
    //LSO_mt->AddProperty("RAYLEIGH",      LSO_ABS_Energy,  LSO_Rayleigh,     LSO_NUMENTRIES_2);
    LSO_mt->AddConstProperty ("SCINTILLATIONYIELD", 60000. / CLHEP::MeV);
    LSO_mt->AddConstProperty ("RESOLUTIONSCALE", 3.2);
    LSO_mt->AddConstProperty ("FASTTIMECONSTANT", 40.*CLHEP::ns);
    LSO_mt->AddConstProperty ("YIELDRATIO", 1.0);
    LSO_mt->AddConstProperty ("FASTSCINTILLATIONRISETIME", 0.1 * CLHEP::ns);

    const G4int LSO_SCY_NUMENTRIES = 12;
    G4double LSO_SCY_Energy[LSO_SCY_NUMENTRIES] = { 0.000 * CLHEP::MeV, 0.015 * CLHEP::MeV, 0.020 * CLHEP::MeV, 0.030 * CLHEP::MeV, 0.040 * CLHEP::MeV, 0.060 * CLHEP::MeV,
						    0.080 * CLHEP::MeV, 0.090 * CLHEP::MeV, 0.105 * CLHEP::MeV, 0.300 * CLHEP::MeV, 0.500 * CLHEP::MeV, 1.000 * CLHEP::MeV
    };
    G4double LSO_SCY[LSO_SCY_NUMENTRIES]        = { 0.10, 0.46, 0.60, 0.68, 0.74, 0.80, 0.82,
						    0.84, 0.87,  0.96,  0.98,  1.00
    };
    for (int i = 0; i < LSO_SCY_NUMENTRIES; i++) {
      LSO_SCY[i] = 60000.0 * CLHEP::MeV * LSO_SCY[i] * LSO_SCY_Energy[i];
    }
    LSO_mt->AddProperty ("ELECTRONSCINTILLATIONYIELD", LSO_SCY_Energy, LSO_SCY, LSO_SCY_NUMENTRIES);

    LSO->SetMaterialPropertiesTable (LSO_mt);


    return LSO;
}


G4Material *MyMaterials::lowLYLYSO()
{
    G4double a, z, density;
    G4Element  *O = new G4Element ("Oxygen",    "O",   z = 8.,  a = 16.00 * CLHEP::g / CLHEP::mole);
    G4Element *Lu = new G4Element ("Lutetium",  "Lu",  z = 71., a = 174.97 * CLHEP::g / CLHEP::mole);
    G4Element *Si = new G4Element ("Silicon",   "Si",  z = 14., a = 28.09 * CLHEP::g / CLHEP::mole);

    G4Material *mat = new G4Material ("LYSO", density = 7.1 * CLHEP::g / CLHEP::cm3, 3, kStateSolid);
    mat->AddElement (Lu, 2);
    mat->AddElement (Si, 1);
    mat->AddElement (O, 5);

    const G4int NUMENTRIES_1 = 261;
    G4double FAST_Energy[NUMENTRIES_1] = {
        1.77169 * CLHEP::eV,
        1.77266 * CLHEP::eV,
        1.77558 * CLHEP::eV,
        1.77851 * CLHEP::eV,
        1.78145 * CLHEP::eV,
        1.78539 * CLHEP::eV,
        1.79033 * CLHEP::eV,
        1.7963 * CLHEP::eV,
        1.80231 * CLHEP::eV,
        1.80836 * CLHEP::eV,
        1.81445 * CLHEP::eV,
        1.82058 * CLHEP::eV,
        1.82882 * CLHEP::eV,
        1.83401 * CLHEP::eV,
        1.84553 * CLHEP::eV,
        1.85293 * CLHEP::eV,
        1.86147 * CLHEP::eV,
        1.869 * CLHEP::eV,
        1.87769 * CLHEP::eV,
        1.89308 * CLHEP::eV,
        1.90536 * CLHEP::eV,
        1.92007 * CLHEP::eV,
        1.93039 * CLHEP::eV,
        1.94901 * CLHEP::eV,
        1.95846 * CLHEP::eV,
        1.9668 * CLHEP::eV,
        1.97884 * CLHEP::eV,
        1.99102 * CLHEP::eV,
        2.00088 * CLHEP::eV,
        2.01209 * CLHEP::eV,
        2.02596 * CLHEP::eV,
        2.03617 * CLHEP::eV,
        2.04519 * CLHEP::eV,
        2.0569 * CLHEP::eV,
        2.06611 * CLHEP::eV,
        2.0794 * CLHEP::eV,
        2.09151 * CLHEP::eV,
        2.10239 * CLHEP::eV,
        2.112 * CLHEP::eV,
        2.1231 * CLHEP::eV,
        2.13431 * CLHEP::eV,
        2.14565 * CLHEP::eV,
        2.15566 * CLHEP::eV,
        2.16868 * CLHEP::eV,
        2.18038 * CLHEP::eV,
        2.19519 * CLHEP::eV,
        2.21171 * CLHEP::eV,
        2.2193 * CLHEP::eV,
        2.23619 * CLHEP::eV,
        2.23464 * CLHEP::eV,
        2.24395 * CLHEP::eV,
        2.25806 * CLHEP::eV,
        2.27234 * CLHEP::eV,
        2.28358 * CLHEP::eV,
        2.29493 * CLHEP::eV,
        2.30475 * CLHEP::eV,
        2.31631 * CLHEP::eV,
        2.32463 * CLHEP::eV,
        2.33134 * CLHEP::eV,
        2.33809 * CLHEP::eV,
        2.34487 * CLHEP::eV,
        2.35856 * CLHEP::eV,
        2.36719 * CLHEP::eV,
        2.37939 * CLHEP::eV,
        2.38642 * CLHEP::eV,
        2.40238 * CLHEP::eV,
        2.41134 * CLHEP::eV,
        2.424 * CLHEP::eV,
        2.43312 * CLHEP::eV,
        2.44047 * CLHEP::eV,
        2.44786 * CLHEP::eV,
        2.46278 * CLHEP::eV,
        2.47788 * CLHEP::eV,
        2.48741 * CLHEP::eV,
        2.49317 * CLHEP::eV,
        2.49702 * CLHEP::eV,
        2.50282 * CLHEP::eV,
        2.50865 * CLHEP::eV,
        2.5145 * CLHEP::eV,
        2.52038 * CLHEP::eV,
        2.52432 * CLHEP::eV,
        2.53223 * CLHEP::eV,
        2.5362 * CLHEP::eV,
        2.54619 * CLHEP::eV,
        2.55424 * CLHEP::eV,
        2.56031 * CLHEP::eV,
        2.56437 * CLHEP::eV,
        2.57049 * CLHEP::eV,
        2.57663 * CLHEP::eV,
        2.58487 * CLHEP::eV,
        2.59317 * CLHEP::eV,
        2.59734 * CLHEP::eV,
        2.60571 * CLHEP::eV,
        2.61414 * CLHEP::eV,
        2.61414 * CLHEP::eV,
        2.61837 * CLHEP::eV,
        2.62262 * CLHEP::eV,
        2.62475 * CLHEP::eV,
        2.62902 * CLHEP::eV,
        2.63331 * CLHEP::eV,
        2.63545 * CLHEP::eV,
        2.63976 * CLHEP::eV,
        2.64191 * CLHEP::eV,
        2.64841 * CLHEP::eV,
        2.65493 * CLHEP::eV,
        2.6593 * CLHEP::eV,
        2.66149 * CLHEP::eV,
        2.66588 * CLHEP::eV,
        2.67914 * CLHEP::eV,
        2.67914 * CLHEP::eV,
        2.68136 * CLHEP::eV,
        2.68136 * CLHEP::eV,
        2.68359 * CLHEP::eV,
        2.68805 * CLHEP::eV,
        2.68805 * CLHEP::eV,
        2.68805 * CLHEP::eV,
        2.69477 * CLHEP::eV,
        2.69477 * CLHEP::eV,
        2.69702 * CLHEP::eV,
        2.70153 * CLHEP::eV,
        2.70605 * CLHEP::eV,
        2.71286 * CLHEP::eV,
        2.71742 * CLHEP::eV,
        2.71971 * CLHEP::eV,
        2.722 * CLHEP::eV,
        2.722 * CLHEP::eV,
        2.72429 * CLHEP::eV,
        2.72889 * CLHEP::eV,
        2.72889 * CLHEP::eV,
        2.73351 * CLHEP::eV,
        2.73814 * CLHEP::eV,
        2.74279 * CLHEP::eV,
        2.74512 * CLHEP::eV,
        2.74979 * CLHEP::eV,
        2.75213 * CLHEP::eV,
        2.75447 * CLHEP::eV,
        2.75917 * CLHEP::eV,
        2.75682 * CLHEP::eV,
        2.76389 * CLHEP::eV,
        2.76626 * CLHEP::eV,
        2.76389 * CLHEP::eV,
        2.76626 * CLHEP::eV,
        2.77338 * CLHEP::eV,
        2.77576 * CLHEP::eV,
        2.78533 * CLHEP::eV,
        2.79255 * CLHEP::eV,
        2.79738 * CLHEP::eV,
        2.80223 * CLHEP::eV,
        2.80466 * CLHEP::eV,
        2.80709 * CLHEP::eV,
        2.80953 * CLHEP::eV,
        2.80953 * CLHEP::eV,
        2.81934 * CLHEP::eV,
        2.8218 * CLHEP::eV,
        2.82673 * CLHEP::eV,
        2.83168 * CLHEP::eV,
        2.84164 * CLHEP::eV,
        2.84916 * CLHEP::eV,
        2.85419 * CLHEP::eV,
        2.8643 * CLHEP::eV,
        2.86684 * CLHEP::eV,
        2.87449 * CLHEP::eV,
        2.87705 * CLHEP::eV,
        2.87961 * CLHEP::eV,
        2.88475 * CLHEP::eV,
        2.88733 * CLHEP::eV,
        2.8925 * CLHEP::eV,
        2.89509 * CLHEP::eV,
        2.90028 * CLHEP::eV,
        2.90549 * CLHEP::eV,
        2.90811 * CLHEP::eV,
        2.91073 * CLHEP::eV,
        2.91335 * CLHEP::eV,
        2.91335 * CLHEP::eV,
        2.91335 * CLHEP::eV,
        2.91861 * CLHEP::eV,
        2.92125 * CLHEP::eV,
        2.92125 * CLHEP::eV,
        2.92389 * CLHEP::eV,
        2.92654 * CLHEP::eV,
        2.92654 * CLHEP::eV,
        2.92919 * CLHEP::eV,
        2.92919 * CLHEP::eV,
        2.93185 * CLHEP::eV,
        2.93451 * CLHEP::eV,
        2.93717 * CLHEP::eV,
        2.93985 * CLHEP::eV,
        2.94252 * CLHEP::eV,
        2.9452 * CLHEP::eV,
        2.94789 * CLHEP::eV,
        2.94789 * CLHEP::eV,
        2.94789 * CLHEP::eV,
        2.95058 * CLHEP::eV,
        2.95868 * CLHEP::eV,
        2.96411 * CLHEP::eV,
        2.96955 * CLHEP::eV,
        2.97228 * CLHEP::eV,
        2.97228 * CLHEP::eV,
        2.96955 * CLHEP::eV,
        2.97228 * CLHEP::eV,
        2.97502 * CLHEP::eV,
        2.97776 * CLHEP::eV,
        2.97502 * CLHEP::eV,
        2.9805 * CLHEP::eV,
        2.9805 * CLHEP::eV,
        2.9805 * CLHEP::eV,
        2.98601 * CLHEP::eV,
        2.99154 * CLHEP::eV,
        2.99431 * CLHEP::eV,
        2.99431 * CLHEP::eV,
        2.99708 * CLHEP::eV,
        2.99431 * CLHEP::eV,
        2.99708 * CLHEP::eV,
        3.00544 * CLHEP::eV,
        3.00824 * CLHEP::eV,
        3.00824 * CLHEP::eV,
        3.00824 * CLHEP::eV,
        3.00824 * CLHEP::eV,
        3.01385 * CLHEP::eV,
        3.0223 * CLHEP::eV,
        3.02797 * CLHEP::eV,
        3.03081 * CLHEP::eV,
        3.02797 * CLHEP::eV,
        3.03365 * CLHEP::eV,
        3.03081 * CLHEP::eV,
        3.03081 * CLHEP::eV,
        3.0365 * CLHEP::eV,
        3.03935 * CLHEP::eV,
        3.04221 * CLHEP::eV,
        3.04795 * CLHEP::eV,
        3.04795 * CLHEP::eV,
        3.05083 * CLHEP::eV,
        3.05371 * CLHEP::eV,
        3.05949 * CLHEP::eV,
        3.06239 * CLHEP::eV,
        3.06529 * CLHEP::eV,
        3.0682 * CLHEP::eV,
        3.06529 * CLHEP::eV,
        3.07112 * CLHEP::eV,
        3.0682 * CLHEP::eV,
        3.07696 * CLHEP::eV,
        3.08283 * CLHEP::eV,
        3.0976 * CLHEP::eV,
        3.09464 * CLHEP::eV,
        3.09464 * CLHEP::eV,
        3.10653 * CLHEP::eV,
        3.11252 * CLHEP::eV,
        3.11852 * CLHEP::eV,
        3.12757 * CLHEP::eV,
        3.13668 * CLHEP::eV,
        3.14583 * CLHEP::eV,
        3.15813 * CLHEP::eV,
        3.16741 * CLHEP::eV,
        3.17675 * CLHEP::eV,
        3.20828 * CLHEP::eV,
        3.23719 * CLHEP::eV,
        3.26664 * CLHEP::eV,
        3.28656 * CLHEP::eV,
        3.31351 * CLHEP::eV,
        3.34783 * CLHEP::eV,
        3.38287 * CLHEP::eV,
    };
    G4double FAST_COMPONENT[NUMENTRIES_1] = {
        0.011691,
        0.011691,
        0.011691,
        0.0146138,
        0.0146138,
        0.0146138,
        0.011691,
        0.011691,
        0.00876827,
        0.00876827,
        0.00584551,
        0.00584551,
        0.00584551,
        0.00292276,
        0.00876827,
        0.0146138,
        0.0146138,
        0.0146138,
        0.0204593,
        0.023382,
        0.0263048,
        0.0204593,
        0.0204593,
        0.023382,
        0.0292276,
        0.0321503,
        0.0350731,
        0.0379958,
        0.0379958,
        0.0379958,
        0.0350731,
        0.0379958,
        0.0409186,
        0.0438413,
        0.0526096,
        0.0584551,
        0.0643006,
        0.0730689,
        0.0730689,
        0.0818372,
        0.0906054,
        0.0964509,
        0.0993737,
        0.105219,
        0.111065,
        0.122756,
        0.125678,
        0.146138,
        0.146138,
        0.160752,
        0.157829,
        0.163674,
        0.184134,
        0.192902,
        0.20167,
        0.219207,
        0.230898,
        0.242589,
        0.25428,
        0.265971,
        0.274739,
        0.292276,
        0.306889,
        0.315658,
        0.321503,
        0.350731,
        0.368267,
        0.385804,
        0.397495,
        0.415031,
        0.432568,
        0.458873,
        0.482255,
        0.496868,
        0.514405,
        0.529019,
        0.549478,
        0.564092,
        0.581628,
        0.593319,
        0.602088,
        0.616701,
        0.637161,
        0.660543,
        0.681002,
        0.71023,
        0.736534,
        0.756994,
        0.777453,
        0.806681,
        0.844676,
        0.868058,
        0.891441,
        0.9119,
        0.938205,
        0.955741,
        0.984969,
        1.0142,
        1.03173,
        1.05511,
        1.07557,
        1.11649,
        1.13695,
        1.15741,
        1.17495,
        1.19248,
        1.21002,
        1.22756,
        1.27432,
        1.2977,
        1.31524,
        1.32985,
        1.36785,
        1.40292,
        1.39415,
        1.4,
        1.41754,
        1.44092,
        1.47015,
        1.48476,
        1.50814,
        1.5286,
        1.54906,
        1.56952,
        1.58998,
        1.61921,
        1.63967,
        1.66597,
        1.68935,
        1.71566,
        1.73904,
        1.76242,
        1.77996,
        1.80042,
        1.8238,
        1.83549,
        1.85303,
        1.8618,
        1.87933,
        1.89979,
        1.91733,
        1.92902,
        1.95825,
        1.98163,
        2.01378,
        2.03424,
        2.0547,
        2.07808,
        2.09562,
        2.11023,
        2.12484,
        2.13361,
        2.15407,
        2.15699,
        2.15992,
        2.16576,
        2.16868,
        2.16868,
        2.16284,
        2.15699,
        2.14823,
        2.13946,
        2.12484,
        2.11023,
        2.08977,
        2.06639,
        2.04593,
        2.02839,
        2.01086,
        1.98455,
        1.96409,
        1.94948,
        1.93194,
        1.91733,
        1.90271,
        1.87641,
        1.86472,
        1.8501,
        1.83841,
        1.82088,
        1.79749,
        1.77119,
        1.75073,
        1.73027,
        1.70689,
        1.68058,
        1.65428,
        1.6309,
        1.60167,
        1.57244,
        1.55491,
        1.53152,
        1.50522,
        1.47891,
        1.45261,
        1.43215,
        1.40877,
        1.38831,
        1.362,
        1.33862,
        1.31232,
        1.28601,
        1.27432,
        1.25678,
        1.21587,
        1.19541,
        1.17203,
        1.14864,
        1.12234,
        1.10772,
        1.08434,
        1.06096,
        1.0142,
        0.987891,
        0.967432,
        0.938205,
        0.9119,
        0.879749,
        0.853445,
        0.82714,
        0.786221,
        0.765762,
        0.739457,
        0.716075,
        0.681002,
        0.660543,
        0.637161,
        0.60501,
        0.581628,
        0.552401,
        0.531942,
        0.505637,
        0.485177,
        0.458873,
        0.435491,
        0.412109,
        0.379958,
        0.356576,
        0.336117,
        0.309812,
        0.280585,
        0.25428,
        0.207516,
        0.175365,
        0.157829,
        0.13737,
        0.119833,
        0.0993737,
        0.0759916,
        0.0613779,
        0.0526096,
        0.0350731,
        0.0263048,
        0.011691,
        0.00876827,
        0.00876827,
        0.011691,
        0.011691,
        0.011691,
        0.00876827,
        0.011691,
    };



    const G4int NUMENTRIES_2 = 3;
    G4double RIND_Energy[NUMENTRIES_2]    = { 1.0 * CLHEP::eV, 1.84 * CLHEP::eV, 4.08 * CLHEP::eV };
    G4double RIND_INDEX[NUMENTRIES_2]     = { 1.82, 1.82, 1.82 };

    const G4int NUMENTRIES_3 = 9;
    G4double ABS_Energy[NUMENTRIES_3]     = { 1.00 * CLHEP::eV , 2.82 * CLHEP::eV , 2.88 * CLHEP::eV , 2.95 * CLHEP::eV , 3.02 * CLHEP::eV  , 3.10 * CLHEP::eV  , 3.18 * CLHEP::eV  , 3.26 * CLHEP::eV , 4.08 * CLHEP::eV };
    G4double ABS_LENGTH[NUMENTRIES_3]     = { 438.*CLHEP::mm , 438.*CLHEP::mm , 413.*CLHEP::mm , 375.*CLHEP::mm , 263.*CLHEP::mm  , 87.5 * CLHEP::mm  , 11.5 * CLHEP::mm  , 1.0 * CLHEP::mm  , 1.0 * CLHEP::mm  };

//const G4int NUMENTRIES_3 = 3;
//G4double ABS_Energy[NUMENTRIES_3]     = { 1.0*CLHEP::eV, 1.84*CLHEP::eV, 4.08*CLHEP::eV };
//G4double ABS_LENGTH[NUMENTRIES_3]       = { 138000.*CLHEP::mm, 138000.*CLHEP::mm, 138000.*CLHEP::mm };
//G4double ABS_LENGTH[NUMENTRIES_3]       = { 500.*CLHEP::mm, 500.*CLHEP::mm, 500.*CLHEP::mm };


    //G4double Rayleigh[NUMENTRIES_2]       = { 138.*CLHEP::mm, 138.*CLHEP::mm, 138.*CLHEP::mm};


    G4MaterialPropertiesTable *mt = new G4MaterialPropertiesTable();
    mt->AddProperty ("FASTCOMPONENT", FAST_Energy, FAST_COMPONENT, NUMENTRIES_1);
    mt->AddProperty ("RINDEX",        RIND_Energy, RIND_INDEX,     NUMENTRIES_2);
    mt->AddProperty ("ABSLENGTH",     ABS_Energy,  ABS_LENGTH,     NUMENTRIES_3);
    //mt->AddProperty("RAYLEIGH",      ABS_Energy,  Rayleigh,     NUMENTRIES_2);
    mt->AddConstProperty ("SCINTILLATIONYIELD", 10. / CLHEP::MeV);
    mt->AddConstProperty ("RESOLUTIONSCALE", 3.4);
    mt->AddConstProperty ("FASTTIMECONSTANT", 40.*CLHEP::ns);
    mt->AddConstProperty ("YIELDRATIO", 1.0);
    mt->AddConstProperty ("FASTSCINTILLATIONRISETIME", 0.1 * CLHEP::ns);
    mat->SetMaterialPropertiesTable (mt);


    return mat;
}



/*============PbWO===================*/
G4Material *MyMaterials::PbWO()
{
    G4double a, z, density;
    G4Element *O = new G4Element ("Oxygen",    "O",   z = 8.,  a = 16.00 * CLHEP::g / CLHEP::mole);
    G4Element *Pb = new G4Element ("Lead",     "Pb",  z = 82., a = 207.21 * CLHEP::g / CLHEP::mole);
    G4Element *W = new G4Element ("Tungsten",  "W",   z = 74., a = 183.85 * CLHEP::g / CLHEP::mole);

    G4Material *PbWO = new G4Material ("PbWO", density = 8.28 * CLHEP::g / CLHEP::cm3, 3);
    PbWO->AddElement (Pb, 1);
    PbWO->AddElement (W, 1);
    PbWO->AddElement (O, 4);

    const G4int PbWO_NUMENTRIES_1 = 193;
    G4double PbWO_FAST_Energy[PbWO_NUMENTRIES_1] = {
        1.83966 * CLHEP::eV,
        1.84948 * CLHEP::eV,
        1.86274 * CLHEP::eV,
        1.87507 * CLHEP::eV,
        1.88413 * CLHEP::eV,
        1.90369 * CLHEP::eV,
        1.91187 * CLHEP::eV,
        1.92129 * CLHEP::eV,
        1.92962 * CLHEP::eV,
        1.93922 * CLHEP::eV,
        1.95258 * CLHEP::eV,
        1.96365 * CLHEP::eV,
        1.97986 * CLHEP::eV,
        1.99124 * CLHEP::eV,
        2.00533 * CLHEP::eV,
        2.02618 * CLHEP::eV,
        2.04747 * CLHEP::eV,
        2.06101 * CLHEP::eV,
        2.07472 * CLHEP::eV,
        2.09424 * CLHEP::eV,
        2.11269 * CLHEP::eV,
        2.12565 * CLHEP::eV,
        2.14466 * CLHEP::eV,
        2.16251 * CLHEP::eV,
        2.17914 * CLHEP::eV,
        2.19602 * CLHEP::eV,
        2.21317 * CLHEP::eV,
        2.22422 * CLHEP::eV,
        2.24021 * CLHEP::eV,
        2.25479 * CLHEP::eV,
        2.26462 * CLHEP::eV,
        2.27785 * CLHEP::eV,
        2.29462 * CLHEP::eV,
        2.30821 * CLHEP::eV,
        2.32024 * CLHEP::eV,
        2.33588 * CLHEP::eV,
        2.34643 * CLHEP::eV,
        2.35529 * CLHEP::eV,
        2.37322 * CLHEP::eV,
        2.38594 * CLHEP::eV,
        2.3896 * CLHEP::eV,
        2.39879 * CLHEP::eV,
        2.40805 * CLHEP::eV,
        2.41365 * CLHEP::eV,
        2.4268 * CLHEP::eV,
        2.44009 * CLHEP::eV,
        2.45161 * CLHEP::eV,
        2.46518 * CLHEP::eV,
        2.47693 * CLHEP::eV,
        2.48483 * CLHEP::eV,
        2.49477 * CLHEP::eV,
        2.50479 * CLHEP::eV,
        2.51692 * CLHEP::eV,
        2.53123 * CLHEP::eV,
        2.5457 * CLHEP::eV,
        2.54986 * CLHEP::eV,
        2.55613 * CLHEP::eV,
        2.56033 * CLHEP::eV,
        2.56665 * CLHEP::eV,
        2.58796 * CLHEP::eV,
        2.59658 * CLHEP::eV,
        2.60091 * CLHEP::eV,
        2.60309 * CLHEP::eV,
        2.60744 * CLHEP::eV,
        2.614 * CLHEP::eV,
        2.62059 * CLHEP::eV,
        2.62943 * CLHEP::eV,
        2.6361 * CLHEP::eV,
        2.64057 * CLHEP::eV,
        2.64729 * CLHEP::eV,
        2.65632 * CLHEP::eV,
        2.66085 * CLHEP::eV,
        2.6654 * CLHEP::eV,
        2.66997 * CLHEP::eV,
        2.67684 * CLHEP::eV,
        2.67684 * CLHEP::eV,
        2.68839 * CLHEP::eV,
        2.69303 * CLHEP::eV,
        2.70237 * CLHEP::eV,
        2.70471 * CLHEP::eV,
        2.71177 * CLHEP::eV,
        2.72124 * CLHEP::eV,
        2.72362 * CLHEP::eV,
        2.73077 * CLHEP::eV,
        2.73077 * CLHEP::eV,
        2.73317 * CLHEP::eV,
        2.73797 * CLHEP::eV,
        2.74279 * CLHEP::eV,
        2.74762 * CLHEP::eV,
        2.7549 * CLHEP::eV,
        2.7549 * CLHEP::eV,
        2.75978 * CLHEP::eV,
        2.75978 * CLHEP::eV,
        2.76468 * CLHEP::eV,
        2.76713 * CLHEP::eV,
        2.77205 * CLHEP::eV,
        2.77699 * CLHEP::eV,
        2.77699 * CLHEP::eV,
        2.77947 * CLHEP::eV,
        2.78941 * CLHEP::eV,
        2.79692 * CLHEP::eV,
        2.80195 * CLHEP::eV,
        2.80699 * CLHEP::eV,
        2.8146 * CLHEP::eV,
        2.81714 * CLHEP::eV,
        2.8248 * CLHEP::eV,
        2.8325 * CLHEP::eV,
        2.83507 * CLHEP::eV,
        2.85063 * CLHEP::eV,
        2.85847 * CLHEP::eV,
        2.86635 * CLHEP::eV,
        2.86899 * CLHEP::eV,
        2.87428 * CLHEP::eV,
        2.87959 * CLHEP::eV,
        2.88225 * CLHEP::eV,
        2.89027 * CLHEP::eV,
        2.89295 * CLHEP::eV,
        2.89833 * CLHEP::eV,
        2.90103 * CLHEP::eV,
        2.90915 * CLHEP::eV,
        2.91186 * CLHEP::eV,
        2.91731 * CLHEP::eV,
        2.92278 * CLHEP::eV,
        2.92278 * CLHEP::eV,
        2.92553 * CLHEP::eV,
        2.93103 * CLHEP::eV,
        2.93103 * CLHEP::eV,
        2.93103 * CLHEP::eV,
        2.94487 * CLHEP::eV,
        2.94487 * CLHEP::eV,
        2.94766 * CLHEP::eV,
        2.95324 * CLHEP::eV,
        2.95604 * CLHEP::eV,
        2.95885 * CLHEP::eV,
        2.95604 * CLHEP::eV,
        2.96166 * CLHEP::eV,
        2.96447 * CLHEP::eV,
        2.97012 * CLHEP::eV,
        2.96166 * CLHEP::eV,
        2.97295 * CLHEP::eV,
        2.98434 * CLHEP::eV,
        2.98434 * CLHEP::eV,
        2.98148 * CLHEP::eV,
        2.98434 * CLHEP::eV,
        2.99006 * CLHEP::eV,
        2.9872 * CLHEP::eV,
        2.99006 * CLHEP::eV,
        2.9872 * CLHEP::eV,
        2.99006 * CLHEP::eV,
        2.99869 * CLHEP::eV,
        3.00447 * CLHEP::eV,
        3.00737 * CLHEP::eV,
        3.0161 * CLHEP::eV,
        3.01902 * CLHEP::eV,
        3.0161 * CLHEP::eV,
        3.0161 * CLHEP::eV,
        3.01318 * CLHEP::eV,
        3.01318 * CLHEP::eV,
        3.02194 * CLHEP::eV,
        3.02781 * CLHEP::eV,
        3.03666 * CLHEP::eV,
        3.03666 * CLHEP::eV,
        3.03666 * CLHEP::eV,
        3.04556 * CLHEP::eV,
        3.05152 * CLHEP::eV,
        3.05152 * CLHEP::eV,
        3.05451 * CLHEP::eV,
        3.05451 * CLHEP::eV,
        3.05451 * CLHEP::eV,
        3.06051 * CLHEP::eV,
        3.05751 * CLHEP::eV,
        3.07258 * CLHEP::eV,
        3.07258 * CLHEP::eV,
        3.07561 * CLHEP::eV,
        3.08169 * CLHEP::eV,
        3.09085 * CLHEP::eV,
        3.08779 * CLHEP::eV,
        3.09085 * CLHEP::eV,
        3.09699 * CLHEP::eV,
        3.10935 * CLHEP::eV,
        3.10625 * CLHEP::eV,
        3.1218 * CLHEP::eV,
        3.12807 * CLHEP::eV,
        3.13121 * CLHEP::eV,
        3.14067 * CLHEP::eV,
        3.15657 * CLHEP::eV,
        3.16941 * CLHEP::eV,
        3.19213 * CLHEP::eV,
        3.21849 * CLHEP::eV,
        3.24529 * CLHEP::eV,
        3.27255 * CLHEP::eV,
        3.28981 * CLHEP::eV,
    };
    G4double PbWO_FAST_COMPONENT[PbWO_NUMENTRIES_1] = {
        0.0121475,
        0.0121475,
        0.0151844,
        0.0151844,
        0.0151844,
        0.0182213,
        0.0182213,
        0.0182213,
        0.024295,
        0.024295,
        0.0212581,
        0.0212581,
        0.0303688,
        0.0303688,
        0.0303688,
        0.0425163,
        0.0516269,
        0.0607375,
        0.0698482,
        0.072885,
        0.0850325,
        0.0941432,
        0.106291,
        0.127549,
        0.130586,
        0.142733,
        0.163991,
        0.179176,
        0.19436,
        0.212581,
        0.224729,
        0.239913,
        0.252061,
        0.273319,
        0.297614,
        0.318872,
        0.34013,
        0.355315,
        0.376573,
        0.38872,
        0.413015,
        0.4282,
        0.440347,
        0.458568,
        0.47679,
        0.507158,
        0.531453,
        0.567896,
        0.595228,
        0.628633,
        0.652928,
        0.68026,
        0.71974,
        0.759219,
        0.77744,
        0.813883,
        0.835141,
        0.859436,
        0.886768,
        0.920174,
        0.956616,
        0.990022,
        1.00521,
        1.01735,
        1.04165,
        1.06898,
        1.09328,
        1.11757,
        1.15098,
        1.17223,
        1.2026,
        1.23297,
        1.26334,
        1.29067,
        1.32104,
        1.37874,
        1.40304,
        1.43341,
        1.46074,
        1.49414,
        1.52451,
        1.56095,
        1.60043,
        1.63991,
        1.67028,
        1.69761,
        1.72191,
        1.7462,
        1.77354,
        1.81605,
        1.84946,
        1.88286,
        1.88286,
        1.88894,
        1.9102,
        1.94056,
        1.98308,
        2.00434,
        2.03167,
        2.07419,
        2.10759,
        2.13189,
        2.15315,
        2.16833,
        2.17744,
        2.19566,
        2.20781,
        2.20781,
        2.21996,
        2.21692,
        2.20477,
        2.18959,
        2.16833,
        2.14403,
        2.11367,
        2.08026,
        2.04685,
        2.01649,
        1.98308,
        1.94056,
        1.90716,
        1.87679,
        1.84642,
        1.80998,
        1.77354,
        1.73406,
        1.70369,
        1.66421,
        1.60651,
        1.53362,
        1.5154,
        1.49111,
        1.46985,
        1.44252,
        1.4243,
        1.39696,
        1.36356,
        1.318,
        1.26941,
        1.21171,
        1.16616,
        1.13275,
        1.09935,
        1.12972,
        1.11453,
        1.08416,
        1.05683,
        1.02343,
        0.993059,
        0.956616,
        0.929284,
        0.895879,
        0.87462,
        0.835141,
        0.801735,
        0.77744,
        0.747072,
        0.704555,
        0.67115,
        0.640781,
        0.595228,
        0.570933,
        0.540564,
        0.510195,
        0.473753,
        0.443384,
        0.419089,
        0.394794,
        0.373536,
        0.34013,
        0.318872,
        0.276356,
        0.252061,
        0.203471,
        0.185249,
        0.163991,
        0.142733,
        0.127549,
        0.112364,
        0.0911063,
        0.072885,
        0.0577007,
        0.0425163,
        0.0303688,
        0.024295,
        0.00911063,
        0.00607375,
        0.00607375,
        0.00303688,
        0.00303688,
        0.00911063,
        0.00911063,
    };

    G4double PbWO_indexZero     = 1.5861;
    G4double PbWO_nVec[1]       = { 1.1062 };
    G4double PbWO_lVec[1]       = { 270.63 };

    const G4int PbWO_NUMENTRIES_2 = 4;
    G4double PbWO_RIND_Energy[PbWO_NUMENTRIES_2]      = { 0.0001 * CLHEP::eV, 1.0 * CLHEP::eV, 1.84 * CLHEP::eV, 4.08 * CLHEP::eV };
    G4double PbWO_RIND_INDEX[PbWO_NUMENTRIES_2]       = { 2.325, 2.325, 2.325, 2.325};
    /*G4double PbWO_RIND_INDEX[PbWO_NUMENTRIES_2]       = {
    CalculateSellmeier(PbWO_indexZero,PbWO_nVec,PbWO_lVec,fromEvToNm(0.0001)),
    CalculateSellmeier(PbWO_indexZero,PbWO_nVec,PbWO_lVec,fromEvToNm(1.0)),
    CalculateSellmeier(PbWO_indexZero,PbWO_nVec,PbWO_lVec,fromEvToNm(1.84)),
    CalculateSellmeier(PbWO_indexZero,PbWO_nVec,PbWO_lVec,fromEvToNm(4.08)),
    };*/
/*
    const G4int PbWO_ABS_entries = 70;
    G4double PbWO_ABS_Energy[PbWO_ABS_entries]       = {
        1.25237 * CLHEP::eV, 1.26514 * CLHEP::eV, 1.27819 * CLHEP::eV, 1.2915 * CLHEP::eV, 1.3051 * CLHEP::eV, 1.31898 * CLHEP::eV, 1.33316 * CLHEP::eV, 1.34765 * CLHEP::eV, 1.36246 * CLHEP::eV, 1.3776 * CLHEP::eV,
        1.39308 * CLHEP::eV, 1.40891 * CLHEP::eV, 1.42511 * CLHEP::eV, 1.44168 * CLHEP::eV, 1.45864 * CLHEP::eV, 1.476 * CLHEP::eV, 1.49379 * CLHEP::eV, 1.512 * CLHEP::eV, 1.53067 * CLHEP::eV, 1.5498 * CLHEP::eV,
        1.56942 * CLHEP::eV, 1.58954 * CLHEP::eV, 1.61018 * CLHEP::eV, 1.63137 * CLHEP::eV, 1.65312 * CLHEP::eV, 1.67546 * CLHEP::eV, 1.69841 * CLHEP::eV, 1.722 * CLHEP::eV, 1.74626 * CLHEP::eV, 1.7712 * CLHEP::eV,
        1.79687 * CLHEP::eV, 1.8233 * CLHEP::eV, 1.85051 * CLHEP::eV, 1.87855 * CLHEP::eV, 1.90745 * CLHEP::eV, 1.93725 * CLHEP::eV, 1.968 * CLHEP::eV, 1.99974 * CLHEP::eV, 2.03253 * CLHEP::eV, 2.0664 * CLHEP::eV,
        2.10143 * CLHEP::eV, 2.13766 * CLHEP::eV, 2.17516 * CLHEP::eV, 2.214 * CLHEP::eV, 2.25426 * CLHEP::eV, 2.296 * CLHEP::eV, 2.33932 * CLHEP::eV, 2.38431 * CLHEP::eV, 2.43106 * CLHEP::eV, 2.47968 * CLHEP::eV,
        2.53029 * CLHEP::eV, 2.583 * CLHEP::eV, 2.63796 * CLHEP::eV, 2.69531 * CLHEP::eV, 2.7552 * CLHEP::eV, 2.81782 * CLHEP::eV, 2.88335 * CLHEP::eV, 2.952 * CLHEP::eV, 3.024 * CLHEP::eV, 3.0996 * CLHEP::eV,
        3.17908 * CLHEP::eV, 3.26274 * CLHEP::eV, 3.35092 * CLHEP::eV, 3.44401 * CLHEP::eV, 3.54241 * CLHEP::eV, 3.64659 * CLHEP::eV, 3.7571 * CLHEP::eV, 3.87451 * CLHEP::eV, 3.99949 * CLHEP::eV, 4.13281 * CLHEP::eV,


    };

    G4double PbWO_ABS_LENGTH[PbWO_ABS_entries] = {
        3110 * CLHEP::mm, 3110 * CLHEP::mm, 3110 * CLHEP::mm, 3110 * CLHEP::mm, 3110 * CLHEP::mm, 3105 * CLHEP::mm, 3105 * CLHEP::mm, 3105 * CLHEP::mm, 3105 * CLHEP::mm, 3105 * CLHEP::mm,
        3105 * CLHEP::mm, 2745 * CLHEP::mm, 2460 * CLHEP::mm, 2230 * CLHEP::mm, 2039 * CLHEP::mm, 1877 * CLHEP::mm, 1859 * CLHEP::mm, 1826 * CLHEP::mm, 1764 * CLHEP::mm, 1760 * CLHEP::mm,
        1664 * CLHEP::mm, 1585 * CLHEP::mm, 1471 * CLHEP::mm, 1376 * CLHEP::mm, 1272 * CLHEP::mm, 1187 * CLHEP::mm, 1114 * CLHEP::mm, 1046 * CLHEP::mm, 993.2 * CLHEP::mm, 942.9 * CLHEP::mm,
        898.8 * CLHEP::mm, 856.9 * CLHEP::mm, 821.7 * CLHEP::mm, 794.2 * CLHEP::mm, 767.7 * CLHEP::mm, 746.5 * CLHEP::mm, 725.6 * CLHEP::mm, 710.7 * CLHEP::mm, 695.3 * CLHEP::mm, 686.2 * CLHEP::mm,
        674.8 * CLHEP::mm, 663.5 * CLHEP::mm, 648.3 * CLHEP::mm, 633.4 * CLHEP::mm, 622.3 * CLHEP::mm, 607.8 * CLHEP::mm, 590.9 * CLHEP::mm, 568.9 * CLHEP::mm, 541.4 * CLHEP::mm, 502.9 * CLHEP::mm,
        467 * CLHEP::mm, 430.2 * CLHEP::mm, 390.1 * CLHEP::mm, 345.3 * CLHEP::mm, 298.9 * CLHEP::mm, 256.7 * CLHEP::mm, 219.8 * CLHEP::mm, 185.4 * CLHEP::mm, 150.9 * CLHEP::mm, 116.4 * CLHEP::mm,
        84.8 * CLHEP::mm, 59.4 * CLHEP::mm, 41.1 * CLHEP::mm, 27.5 * CLHEP::mm, 24.2 * CLHEP::mm, 24.2 * CLHEP::mm, 24.3 * CLHEP::mm, 24.3 * CLHEP::mm, 24.4 * CLHEP::mm, 24.6 * CLHEP::mm
    };
    */


    const G4int PbWO_ABS_entries = 4;
    G4double PbWO_ABS_Energy[PbWO_ABS_entries]       = { 0.0001 * CLHEP::eV, 1.0 * CLHEP::eV, 1.84 * CLHEP::eV, 4.08 * CLHEP::eV };
    G4double PbWO_ABS_LENGTH[PbWO_ABS_entries] 	= { 185.4 * CLHEP::mm, 185.4 * CLHEP::mm, 185.4 * CLHEP::mm, 185.4 * CLHEP::mm};

    G4MaterialPropertiesTable *PbWO_mt = new G4MaterialPropertiesTable();
    PbWO_mt->AddProperty ("FASTCOMPONENT", PbWO_FAST_Energy, PbWO_FAST_COMPONENT, PbWO_NUMENTRIES_1);
    PbWO_mt->AddProperty ("RINDEX",        PbWO_RIND_Energy, PbWO_RIND_INDEX,     PbWO_NUMENTRIES_2);
    PbWO_mt->AddProperty ("ABSLENGTH",      PbWO_ABS_Energy,  PbWO_ABS_LENGTH,  PbWO_ABS_entries);

    PbWO_mt->AddConstProperty ("SCINTILLATIONYIELD", 60000. / CLHEP::MeV);
    PbWO_mt->AddConstProperty ("RESOLUTIONSCALE", 3.2);
    PbWO_mt->AddConstProperty ("FASTTIMECONSTANT", 40.*CLHEP::ns);
    PbWO_mt->AddConstProperty ("YIELDRATIO", 1.0);
    PbWO_mt->AddConstProperty ("FASTSCINTILLATIONRISETIME", 0.1 * CLHEP::ns);

    const G4int PbWO_SCY_NUMENTRIES = 12;
    G4double PbWO_SCY_Energy[PbWO_SCY_NUMENTRIES] = { 0.000 * CLHEP::MeV, 0.015 * CLHEP::MeV, 0.020 * CLHEP::MeV, 0.030 * CLHEP::MeV, 0.040 * CLHEP::MeV, 0.060 * CLHEP::MeV,
            0.080 * CLHEP::MeV, 0.090 * CLHEP::MeV, 0.105 * CLHEP::MeV, 0.300 * CLHEP::MeV, 0.500 * CLHEP::MeV, 1.000 * CLHEP::MeV
                                                    };
    G4double PbWO_SCY[PbWO_SCY_NUMENTRIES]        = { 0.10, 0.46, 0.60, 0.68, 0.74, 0.80, 0.82,
            0.84, 0.87,  0.96,  0.98,  1.00
                                                    };
    for (int i = 0; i < PbWO_SCY_NUMENTRIES; i++) {
        PbWO_SCY[i] = 60000.0 * CLHEP::MeV * PbWO_SCY[i] * PbWO_SCY_Energy[i];
    }
    PbWO_mt->AddProperty ("ELECTRONSCINTILLATIONYIELD", PbWO_SCY_Energy, PbWO_SCY, PbWO_SCY_NUMENTRIES);

    PbWO->SetMaterialPropertiesTable (PbWO_mt);

    return PbWO;
}

G4double MyMaterials::CalculateSellmeier (G4double indexZero, G4double *nVec, G4double *lVec, G4double wavelength)
{

    /*------http://gentitfx.fr/SLitrani/code/SLitraniCode/TLitSellmeier.html----*/

    int nVecSize = sizeof (nVec) / sizeof (G4double);
    int lVecSize = sizeof (lVec) / sizeof (G4double);

    if (nVecSize != lVecSize) {
        G4cout << G4endl << "========== ERROR ============" << G4endl;
        G4cout << "nVec and lVec have different size... check!" << G4endl;
        G4cout << "========== ERROR ============" << G4endl << G4endl;
        return 0;
    }

    float partial = indexZero * indexZero;
    float sum = 0;
    for (int i = 0; i < nVecSize; i++) {

        sum += nVec[i] * nVec[i] / (1 - lVec[i] * lVec[i] / wavelength);

    }

    partial += sum;
    partial += 1;

    G4cout << "Wavelength: " << wavelength << " -> rifr. index: " << sqrt (partial) << G4endl;

    return sqrt (partial);
}

G4double MyMaterials::fromEvToNm (G4double energy)
{

    return 1239.84187 / energy;

}

G4double MyMaterials::fromNmToEv (G4double wavelength)
{


    return 1239.84187 / wavelength;

}

