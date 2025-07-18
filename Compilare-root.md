# Compile-root
Compilare con root, per ricordarsi velocemente i comandi e in caso dia problemi per vec&lt;vec&lt;int>>
Iniziando molto velocemente con i codici, nel caso in cui dovessi semplicemente compilare con g++ un file in root, il codice è:

g++ -o test_mothers test_mothers.cpp $(root-config --cflags --libs)

Altrimenti, se nel codice ci sono delle inizializzazioni che possano dare problemi, tipo:
Error in <TTree::SetBranchAddress>: The class requested (vector<vector<int> >) for the branch "motherIdx" is an instance of an stl collection and does not have a compiled CollectionProxy. Please generate the dictionary for this collection (vector<vector<int> >) to avoid to write corrupted data.
A cui segue un segmentation fault, devi creare dei file: 
dict.h

#include <vector>
#ifdef __CLING__
#pragma link C++ class std::vector<int>+;
#pragma link C++ class std::vector<std::vector<int>>+;
#endif

Purtroppo non mi ricordo come va runnato, ma dopo averlo fatto dorebbe averti creato un .cxx. Con quest compili con:

g++ nome_programma.cpp dict.cxx `root-config --cflags --libs` -o nome_programma



Se necessario anche pquark.cpp:
<pre>g++ nome_programma.cpp pquark.cpp dict_vectorvectorint.cxx `root-config --cflags --libs` -o nome_programma </pre>


Compilare per fastjet invece devi fare:
<pre> g++ reclustering_R_07.cpp -o reclustering_R_07     `root-config --cflags --libs`     `fastjet-install/bin/fastjet-config --cxxflags --libs --plugins` </pre>
