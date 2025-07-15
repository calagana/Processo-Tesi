Aggiorno il codice per l'istogramma delle energie ma aggiungendo le incertezze. Tra l'altro il professore suggeriva di usare
TEfficiency, quindi in caso procedo con quello, rifacendo il codice.
L'efficienza messa è calcolata direttamente da TEfficiency!
*****************
TEfficiency calcola automaticamente l'incertezza statistica sull'efficienza usando metodi basati sulla distribuzione binomiale, perché l’efficienza è una probabilità (successi/sperimentazioni).
In pratica, dato un numero di eventi totali n (denominatore) e un numero di eventi "successo" k (numeratore), TEfficiency stima l’efficienza come 𝑝 =k/n e calcola l’incertezza statistica 𝜎 con metodi che includono:
Metodo Clopper-Pearson (exact binomial confidence intervals): intervalli di confidenza precisi per la binomiale;
Oppure altri metodi come Wilson, Agresti-Coull (più sofisticati, ma Clopper-Pearson è il default);
Questo permette di ottenere intervalli di confidenza (in alto e in basso) per l’efficienza, spesso più corretti rispetto alla semplice approssimazione gaussiana, che darebbe incertezza:
sigma = sqrt(p(1-p)/n).
******************

DOMANI DEVI RIUSCIRE A METTERE LE BARRE DI ERRORE. AL MOMENTO NON RIESCO E DEVO ANDARE A FARE LA SPESA CHE SE NO MUOIO DI FAME PENSO
​
 .
