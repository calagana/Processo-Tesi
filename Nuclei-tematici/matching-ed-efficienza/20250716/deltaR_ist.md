Prima di vedere il codice di federico nello specifico, devo studiare la distribuzione di DeltaR. Il codice in c++ che lo fa è il seguente. molto base ma funzionale. Nota che ho iniziato a lavorare direttamente con gli istogrammi e non con i vettori
```
#include <TH1F.h>
#include "pquark.h"
#include <TFile.h>
#include <TTree.h>
#include <TVector2.h>
#include <TCanvas.h>
#include <TEfficiency.h>
#include <TGraphErrors.h>
#include <iostream>
#include <vector>
#include <cmath>
#include <TAxis.h>
#include "dict_vectorvectorint.h"
#include <TGraphAsymmErrors.h>

using namespace std;

int main() {
  // Apro il file e il primo TTree 
  TFile *f = TFile::Open("HiForestMiniAOD_patjetsunsubtracted_stableonly2.root");
  if (!f || f->IsZombie()) return 1;
  f->cd("HiMergedGenParticleAna");
  TTree *tree = (TTree*)gDirectory->Get("hi");
  if (!tree) return 1;

  // Branches per particelle generiche 
  vector<int>* pdgVec = nullptr;
  vector<float>* ptVec  = nullptr;
  vector<float>* etaVec = nullptr;
  vector<float>* phiVec = nullptr;
  vector<vector<int>>* motherIdx = nullptr;
  tree->SetBranchAddress("pdg", &pdgVec);
  tree->SetBranchAddress("pt",  &ptVec);
  tree->SetBranchAddress("eta", &etaVec);
  tree->SetBranchAddress("phi", &phiVec);
  tree->SetBranchAddress("custom_motherIdx", &motherIdx);

  // Trovo indici dei quark primari e maxE 
  vector<vector<int>> quarkIndices;
  float maxE = 0;
  Long64_t nGenEntries = tree->GetEntries();
  for (Long64_t i = 0; i < nGenEntries; ++i) {
    tree->GetEntry(i);
    auto quarks = getPrimaryQuarkIndices(pdgVec, motherIdx);
    quarkIndices.push_back(quarks);
    for (int qidx : quarks) {
      if (qidx >= 0 && (size_t)qidx < ptVec->size()) {
        maxE = max(maxE, ptVec->at(qidx));
      }
    }
  }

  // Apro il secondo TTree per i jet 
  f->cd("ak4PFJetAnalyzer");
  TTree *tjet = (TTree*)gDirectory->Get("t");
  if (!tjet) return 1;
  const int MAXN = 10000;
  int ngen = 0;
  float genpt[MAXN], geneta[MAXN], genphi[MAXN], genm[MAXN];
  tjet->SetBranchAddress("ngen",   &ngen);
  tjet->SetBranchAddress("genpt",  genpt);
  tjet->SetBranchAddress("geneta", geneta);
  tjet->SetBranchAddress("genphi", genphi);
  tjet->SetBranchAddress("genm",   genm);

  vector<float> dRvec;
  TH1F* isto = new TH1F("isto", "Matched #Delta R; <#DeltaR>; Counts/0.005", 100, 0.0 ,0.5);

  // Loop sui due alberi 
  //cout << "np.vec(["; 
  for (Long64_t i = 0; i < nGenEntries; ++i) {
    tree->GetEntry(i);
    tjet->GetEntry(i);
    if (!ptVec || !etaVec || !phiVec) continue;
    for (int qidx : quarkIndices[i]) {
      if (qidx < 0 || (size_t)qidx >= ptVec->size()) continue;
      float pt  = ptVec->at(qidx);
      float eta = etaVec->at(qidx);
      float phi = phiVec->at(qidx);
      // matching 
      if (ngen > 0) {
        for (int k = 0; k < ngen; ++k) {
          float dphi = TVector2::Phi_mpi_pi(genphi[k] - phi);
          float deta = geneta[k] - eta;
          if (sqrt(dphi*dphi + deta*deta) < 0.5) {
            //qua devo fillare un canvas direi per fare il grafico della deltaR 
            isto->Fill(sqrt(dphi*dphi + deta*deta));
            //cout << sqrt(dphi*dphi + deta*deta) << ", "; 
            break;

          }
        }
      }
    }
  }
  //cout << "])" << endl; 

  //Ora devo solo disegnare l'istogramma: 
  TCanvas* c1 = new TCanvas("c1", "c1", 800, 600);
  isto->Draw();
  c1->SaveAs("immagini_iniziali_quark/deltaR_hist.png");


  return 0;
}
```

Successivamente ho fatto una cosa più bruttarella ma volevo vedere. Il grafico va bene, ma volevo provare a fittarlo, per vedere il valore massimo. In realtà non so se serva necessariamente, con 0.1 pare un valore ragionevole. Comunque ho copiato i deltaR facendomeli stampare, li ho copiati in python nel file Fit delta R , e lì ho fittato con una gaussiana. non viene esattamente benissimo diciamo... 
