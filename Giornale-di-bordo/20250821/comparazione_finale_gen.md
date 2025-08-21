Allora, ho rifatto tutto il conto da capo per le incertezze calcolate in modo diverso. Prima prendevo i dati che provenivano dal fit direttamente, compresa la sigma e l'incertezza sulla sigma.
Non si vedeva benissimo però cheil metodo del thrust axis fosse migliore! perciò sto provando a fare il conto con la sigma in modo diverso. La mu rimane uguale, ma adesso come sigma prendo il valore (asimmetrico) che mi dia il 68% delle misure nell'intervallo (mu-sigma_left, mu+sigma_right). 
I grafici così fatti provengono dai dati di ejetequark_total_comparison2.cpp e thrust_energy_response1.cpp (mi pare sia l'1) e poi tutto messo insieme nel codice:

## grafico_finale_gen.cpp

E i grafici che ne escono sono:
<img width="796" height="572" alt="total_sigma" src="https://github.com/user-attachments/assets/decfd4b9-0462-4635-abbb-14dbbf31f569" />
<img width="796" height="572" alt="relative_error" src="https://github.com/user-attachments/assets/b48ec469-3df1-4061-875f-5b5d6f0e36c9" />

