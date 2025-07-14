Ora inizio a capire se riesco a riclusterizzare con un nuovo R i file. 
Le indicazioni provengono dal codice tutorial per usare fastjet tramite antikt, che ormai sappiamo come funziona. Dopo aver installato il tutto, il codice dà: 
``` #include "fastjet/ClusterSequence.hh"
#include <iostream>
using namespace fastjet;
using namespace std;

int main () {
  vector<PseudoJet> particles;
  // an event with three particles:   px    py  pz      E
  particles.push_back( PseudoJet(   99.0,  0.1,  0, 100.0) ); 
  particles.push_back( PseudoJet(    4.0, -0.1,  0,   5.0) ); 
  particles.push_back( PseudoJet(  -99.0,    0,  0,  99.0) );

  // choose a jet definition
  double R = 0.7;
  JetDefinition jet_def(antikt_algorithm, R);

  // run the clustering, extract the jets
  ClusterSequence cs(particles, jet_def);
  vector<PseudoJet> jets = sorted_by_pt(cs.inclusive_jets());

  // print out some infos
  cout << "Clustering with " << jet_def.description() << endl;

  // print the jets
  cout <<   "        pt y phi" << endl;
  for (unsigned i = 0; i < jets.size(); i++) {
    cout << "jet " << i << ": "<< jets[i].pt() << " " 
                   << jets[i].rap() << " " << jets[i].phi() << endl;
    vector<PseudoJet> constituents = jets[i].constituents();
    for (unsigned j = 0; j < constituents.size(); j++) {
      cout << "    constituent " << j << "'s pt: " << constituents[j].pt()
           << endl;
    }
  }
}
```

Qui usa tre particelle!!! create sul momento. Il codice usa `PseudoJet(px,py,pz,E)` Dovrà quindi estrarre le particelle dal file root e con esso prendere px, py,pz, E della particella e inserirla. Ora riporto il codice che ho usato (Se riesco a farlo ovviamente).
Il codice che ho scritto e che fa in realtà il reclustering con R = 0.7 è:
```
#include <TFile.h>
#include <TTree.h>
#include <TVector2.h>
#include <iostream>
#include <vector>
#include <cmath>
#include <set>
#include "fastjet/ClusterSequence.hh"

using namespace std;
using namespace fastjet;

double getMassFromPDG(int pdg) {
  switch (abs(pdg)) {
  case 12:    return 0.0;       // neutrino_e 
  case 14:    return 0.0;       // neutrino_mu 
  case 16:    return 0.0;       // neutrino_tau 
  case 211:   return 0.13957;   // pion 
  case 321:   return 0.49367;   // kaon 
  case 130:   return 0.4976;    // K0_L 
  case 310:   return 0.4976;    // K0_S 
  case 2212:  return 0.93827;   // proton 
  case 2112:  return 0.93957;   // neutron 
  case 3112:  return 1.197;     // Sigma- 
  case 3222:  return 1.189;     // Sigma+ 
  case 3122:  return 1.1157;    // Lambda 
  case 3312:  return 1.323;     // Xi- 
  case 3322:  return 1.315;     // Xi0 
  case 3334:  return 1.672;     // Omega- 
  case 2214:  return 1.232;     // Delta+ (risonanza, approssimazione) 
  case 2114:  return 1.232;     // Delta0 
  case 3114:  return 1.232;     // Delta- 
    // Neutrini e fotoni 
  case 22:    return 0.0;       // photon 
  default:    return 0.0;       // default per masse sconosciute 
  }
}


int main() {
  TFile *f = TFile::Open("HiForestMiniAOD_patjetsunsubtracted_stableonly2.root");
  if (!f || f->IsZombie()) return 1;

  f->cd("HiMergedGenParticleAna");
  TTree *tree = (TTree*)gDirectory->Get("hi");
  if (!tree) return 1;

  vector<int>* pdgVec = nullptr;
  vector<float>* ptVec = nullptr;
  vector<float>* etaVec = nullptr;
  vector<float>* phiVec = nullptr;
  vector<int>* staVec = nullptr;
  vector<float>* vx = nullptr;
  vector<float>* vy = nullptr;
  vector<float>* vz = nullptr;

  tree->SetBranchAddress("pdg", &pdgVec);
  tree->SetBranchAddress("pt", &ptVec);
  tree->SetBranchAddress("eta", &etaVec);
  tree->SetBranchAddress("phi", &phiVec);
  tree->SetBranchAddress("sta", &staVec);
  tree->SetBranchAddress("vx", &vx);
  tree->SetBranchAddress("vy", &vy);
  tree->SetBranchAddress("vz", &vz);

  set<int> printed_pdgs;

  int nentries = tree->GetEntries();
  for (int i = 0; i < nentries; i++) {
    tree->GetEntry(i);

    vector<PseudoJet> particles;
    for (size_t j = 0; j < pdgVec->size(); j++) {
      if (staVec->at(j) == 1) {
        int pdg = pdgVec->at(j);
        double pt = ptVec->at(j);
        double eta = etaVec->at(j);
        double phi = phiVec->at(j);
        double px = pt * cos(phi);
        double py = pt * sin(phi);
        double pz = pt * sinh(eta);
        double mass = getMassFromPDG(pdg);

        if (mass == 0.0 && printed_pdgs.find(pdg) == printed_pdgs.end()) {
          cout << pdg << endl;
          printed_pdgs.insert(pdg);
        }

        double energy = sqrt(px*px + py*py + pz*pz + mass*mass);
        particles.emplace_back(px, py, pz, energy);
      }
    }

    double R = 0.7;
    JetDefinition jet_def(antikt_algorithm, R);
    ClusterSequence cs(particles, jet_def);
    vector<PseudoJet> jets = sorted_by_pt(cs.inclusive_jets());

    cout << "Clustering con R = " << R << ", algoritmo anti-kt\n";
    cout << "Numero di jet trovati: " << jets.size() << "\n";
    cout << "   pt          y          phi\n";
    for (size_t i = 0; i < jets.size(); ++i) {
      cout << "jet " << i << ": "
           << jets[i].pt() << " "
           << jets[i].rap() << " "
           << jets[i].phi() << "\n";

      auto constituents = jets[i].constituents();
      for (size_t j = 0; j < constituents.size(); ++j) {
        cout << "    costituente " << j << " pt: " << constituents[j].pt() << "\n";
      }
    }
  }
}
```
