Oggi devo calcolare l'efficienza della ricostruzione a in funzione dell'energia. 
Non essendo un istogramma, faccio un array di n valori che arrivi all'energia max dei quark primari. Poi per ogni quark vedo se ci sta un jet. Se ci sta faccio ++ a quel bin e così ottengo un array in cui ho stesso numero di bin del precedente contenente, una volta diviso per il numero di quark, l'efficienza a quell'energia.

Fine della mattinata. Sto scrivendo il codice per calcolare l'efficienza al variare dell'energia. Ho preso il codice vecchio e sto trasformando tutto in vettori di base. Ho concluso studiando se un quark viene ricostruito in quale bin deve essere messo. lo faccio con il codice:

if(dR < 0.1) {
            //Se matchato, devo aumentare di uno l'elemento del vettore che mi interessa. Devo prima capire qual è l'elemento che mi interessa 
            int closest_idx = 0;
            for(size_t l= 1; l<nBins; l++){
              float Ediff = ptVec[qidx] - l * maxE/(float)nBins + 0.5;
              float Ediffm = ptVec[qidx] - (l-1) * maxE/(float)nBins + 0.5;
              if(abs(Ediff) < abs(Ediffm)) {     
                closest_idx = l;
              }                                  
            }                                    
            matched[closest_idx]++;
            foundMatch = true;
            break;                               
          }                                      
        }

Scorre su tutti gli indici, trova il bin (l*maxE/... è il centro di ogni bin) più vicino energeticamente (IN PT!!) in modulo e quello diventa il nuovo closest idx, che poi uso per incrementare il contatore. 
Ora devi dividere per il numero di matched+unmatched per quel pt (ANCHE UNMATCHED DEVE ESSERE RESO UN VETTORE) e hai ottenuto l'efficienza con cui fare il nuovo grafico

Pomeriggio.\
Ho fatto (dopo diversi bug) il codice per l'efficienza in funzione dell'energia. è in efficienza_vs_energia.cpp . Crea sia un grafico con bin tutti di stessa dimensione, sia uno con bin variabili. Domani devi modificare questo secondo perchè per qualche motivo arriva ad energie più alte di quelle dell'altro grafico, anche se dovrebbero essere uguali. Poi voglio il grafico di energia ricostruita/energia quark, che mi sembra molto interessante. \
###########################################################################################################\
IMPORTANTE ho cambiato il codice per ricostruire i quark primari, perchè dava problemi compilare due volte un vettore di vettori. Ora lavora evento per evento! Dal main del codice principale devi passare pdgVec e motherIdx ma inizializzati in un ciclo con GetEntry(i)!!! E ti restituisce un vettore delle posizioni dei quark per quell'evento. Con questi fai pushback per un vettore di vettori e hai i quark primari che volevi. \
########################################################################################################### 
