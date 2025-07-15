Come si vede nel recap di oggi, il primo punto e il più facile è andare a vedere particelle che decadono in due fotoni.
Riporto il codice che uso per stampare tutto, anche se tutto ciò non è poi fondamentale.
```
#include <TFile.h>
#include <TTree.h>
#include <TSystem.h>
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <cmath>
#include "TRandom3.h"


using namespace std;

int main() {
  gSystem->mkdir("immagini_iniziali_adroni_vangelis", true);

  TFile *f = TFile::Open("HiForestMiniAOD_patjetsunsubtracted_stableonly2.root");
  if (!f || f->IsZombie()) {
    cerr << "Errore apertura file ROOT" << endl;
    return 1;
  }

  f->cd("HiMergedGenParticleAna");
  TTree *tree = (TTree*)gDirectory->Get("hi");
  if (!tree) {
    cerr << "Albero 'hi' non trovato" << endl;
    return 1;
  }

  vector<int>*    pdgVec = nullptr;
  vector<float>*  ptVec  = nullptr;
  vector<float>*  etaVec = nullptr;
  vector<float>*  phiVec = nullptr;
  vector<int>*    chgVec = nullptr;
  vector<int>*    staVec = nullptr;
  tree->SetBranchAddress("pdg", &pdgVec);
  tree->SetBranchAddress("pt",  &ptVec);
  tree->SetBranchAddress("eta", &etaVec);
  tree->SetBranchAddress("phi", &phiVec);
  tree->SetBranchAddress("chg", &chgVec);
  tree->SetBranchAddress("sta", &staVec);

  const int kStable = 1;
  int nentries = tree->GetEntries();

  map<int, int> charged_counts;
  map<int, int> neutral_counts;
  int charged = 0, neutral = 0;
  int conteggiofotoni = 0;

  for (int i = 0; i < nentries; i++) {
    tree->GetEntry(i);
    if (!pdgVec || !chgVec || !staVec) continue;

    for (size_t j = 0; j < pdgVec->size(); j++) {
      if (staVec->at(j) != kStable) {
        //      if (pdgVec->at(j) == 22) continue; 

        int pdg = pdgVec->at(j);
        int chg = chgVec->at(j);

        if (chg == 0){
          neutral_counts[pdg]++;
          neutral++;
        } else {
          charged_counts[pdg]++;
          charged++;
        }
      }
      if(pdgVec->at(j) == 111){
        conteggiofotoni+=2;
      }
      if(pdgVec->at(j) == 221){
        TRandom3 randGen;
        int randomInt = randGen.Integer(3);
        if(randomInt == 0) conteggiofotoni += 2; //eta decade in due fotoni 
        if(randomInt == 1) conteggiofotoni += 6; //eta decade in 3 pi0. Questo in realtà dà problemi mi pare proprio... perchè poi il pi0 in realtà me lo ritrovo 
        if(randomInt == 2) conteggiofotoni += 2; //eta decade in tre pi, di cui uno pi0. 
      }
    }
  }

  cout << "\n--- Particelle neutre stabili ---\n";
  for (const auto& [pdg, count] : neutral_counts) {
    cout << "PDG " << pdg << ": " << count << " occorrenze\n";
  }

  cout << "\n--- Particelle cariche stabili ---\n";
  for (const auto& [pdg, count] : charged_counts) {
    cout << "PDG " << pdg << ": " << count << " occorrenze\n";
  }

  cout << "Senza fotoni la percentuale diventa, particelle cariche: " << charged << " neutrali invece: " << neutral << " con totali: " << charged + neutral << endl;
  cout << "numero eventi " << nentries << endl;
  cout << "Ho in media " << neutral_counts[22]/nentries << " fotoni per evento." << endl;
  cout << "Le particelle che decadono in due fotoni sono: " << conteggiofotoni << endl;
  return 0;
}
```
