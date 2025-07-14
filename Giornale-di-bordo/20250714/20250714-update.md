TUTTO GEN DATA ANCORA

efficienza_vs_energia.cpp \
Mattinata di oggi in primis voglio migliorare l'istogramma dell'efficienza in funzione dell'energia che la scorsa volta faceva cagare. Fatto questo vorrei studiare il rapporto tra l'energia misurata e l'energia del quark iniziale in funzione proprio dell'energia del quark iniziale, così da capire come funziona.\
Ok, aggiornato il grafico e sto facendo la presentazione 4 se non sbaglio. Voglio mettere anche il numero di eventi matchati per bin di energia. Lo stampa il codice in modo abbastanza semplice, faccio la tabella su overleaf e pace.
Energie: 2.5 - 0, conteggio: (matched/totali) 0/0 -nan%\
Energie: 5 - 2.5, conteggio: (matched/totali) 0/2050 0%\
Energie: 8 - 5, conteggio: (matched/totali) 520/14405 3.60986%\
Energie: 11.5 - 8, conteggio: (matched/totali) 841/2657 31.6522%\
Energie: 15.5 - 11.5, conteggio: (matched/totali) 341/645 52.8682%\
Energie: 20 - 15.5, conteggio: (matched/totali) 122/177 68.9266%\
Energie: 25 - 20, conteggio: (matched/totali) 33/48 68.75%\
Energie: 31 - 25, conteggio: (matched/totali) 7/10 70%\
Energie: 38 - 31, conteggio: (matched/totali) 1/2 50%\
Energie: 46 - 38, conteggio: (matched/totali) 2/2 100%\
Energie: 55 - 46, conteggio: (matched/totali) 4/4 100%\



Rimango ancora in efficienza_vs_energia.cpp
Adesso procedo a studiare la percentuale di energia ricostruita dal jet per bin di energia. Come riporto il risultato?\
In primis la percentuale di energia ricostruita è:\
% = E_jet / E_matched_quark \
Quindi poi quello che riporto nel codice è la media di queste percentuali bin per bin:\
media = Somma(%1 + %2 ...) / N_elementi_bin\
Ottengo il grafico che però ha più o meno efficienza di ricostruzione più o meno costante sui 80%. Per migliorarla questa dovrei aumentare la R (ed è quello che farò in effetti).\

Nel pomeriggio devi andare a rivedere come funziona l'algoritmo per la ricostruzione che stai usando. Fa strano che in tutti i casi si ricostruisca (quando prende) circa l'80% dell'energia.


