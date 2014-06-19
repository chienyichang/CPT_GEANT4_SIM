gStyle->SetOptStat(0)
T->Draw("trackVectorPosZ.energy>>h1(100,200,700)","trackVectorPosZ.creator==1","")
T->Draw("trackVectorPosZ.energy>>h2(100,200,700)","trackVectorPosZ.creator==2","")
h1->SetLineColor(2)
h1->GetXaxis()->SetTitle("Wavelength [nm]")
h1->Draw()
h2->Draw("same")

TLegend* leg = new TLegend(0.7, 0.7, .9, .9);
leg->AddEntry(h1, "Scintillator", "l");
leg->AddEntry(h2, "Cerenkov", "l");
leg->SetFillColor(0)
leg->Draw()

///////////////////////////////////
gStyle->SetOptStat(0)
T->Draw("trackVectorNegZ.energy>>h1(100,200,700)","trackVectorNegZ.creator==1","")
T->Draw("trackVectorNegZ.energy>>h2(100,200,700)","trackVectorNegZ.creator==2","")
h1->GetXaxis()->SetTitle("Wavelength [nm]")
h1->SetLineColor(2)
h1->Draw()
h2->Draw("same")

TLegend* leg = new TLegend(0.7, 0.7, .9, .9);
leg->AddEntry(h1, "Scintillator", "l");
leg->AddEntry(h2, "Cerenkov", "l");
leg->SetFillColor(0)
leg->Draw()

///////////////////////////////////
gStyle->SetOptStat(0)
T->Draw("trackVectorPosZ.time>>h1(200,500,5000)","trackVectorPosZ.creator==1","")
T->Draw("trackVectorPosZ.time>>h2(200,500,5000)","trackVectorPosZ.creator==2","")
h1->SetLineColor(2)
h1->GetXaxis()->SetTitle("time [psec]")
h1->Draw()
h2->Draw("same")

TLegend* leg = new TLegend(0.7, 0.7, .9, .9);
leg->AddEntry(h1, "Scintillator", "l");
leg->AddEntry(h2, "Cerenkov", "l");
leg->SetFillColor(0)
leg->Draw()

///////////////////////////////////
gStyle->SetOptStat(0)
T->Draw("trackVectorNegZ.time>>h1(100,500,5000)","trackVectorNegZ.creator==1","")
T->Draw("trackVectorNegZ.time>>h2(100,500,5000)","trackVectorNegZ.creator==2","")
h1->GetXaxis()->SetTitle("time [psec]")
h1->SetLineColor(2)
h1->Draw()
h2->Draw("same")

TLegend* leg = new TLegend(0.7, 0.7, .9, .9);
leg->AddEntry(h1, "Scintillator", "l");
leg->AddEntry(h2, "Cerenkov", "l");
leg->SetFillColor(0)
leg->Draw()
