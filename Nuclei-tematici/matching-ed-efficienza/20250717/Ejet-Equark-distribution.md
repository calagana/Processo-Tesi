### ejetequark.cpp (grafici bin per bin) ejetequark_total.cpp (costruzione grafico totale, a partire dai fit o mediana)
Finito di mettere le incertezze nel plot delle efficienze di matching. Adesso voglio rifare lo studio per vedere quanta energia in percentuale è ricostruita bin per bin. Devo prima vedere le distribuzioni stesse bin per bin!
Quindi:
I grafici sono fatti, sono in Desktop/immagini_bin_energia_ricostruite_20250717. Il problema vero è che riesco a fare i fit bene solo per alcuni di questi grafici, mica per tutti. Siccome sono asimmetrici quello che userò sono le mediane in caso non riesca a fare i fit. Il processo algoritmico è:
###### ejetequark.cpp
1) matching per avere i dati
2) Calcolo per quelli matchati del rapporto E_jet/E_quark . Bin per bin faccio l'istogramma del rapporto E_jet/E_quark ed è il mio asse x, da cui l'isto
3) Avendo l'istogramma vado a fare i fit.
4) inizialmente avevo fatto gaussiano e double crystalball, ma Santanastasio suggerisce di levare la gaussiana, tanto alla fine la DCB è quello con le code prensili diciamo.
5) Faccio fit e stampo i valori. !!!!!!!! Occhio! molti bin hanno troppi pochi eventi per il momento! quindi non posso fare il fit per tutti i bin. Per quelli con troppi pochi eventi (mo devo vedere quanto sia troppi pochi), calcolo direttamente la mediana senza fare tutto ciò, tanto non ha senso.

###### ejetequark_total.cpp
... (inizio è uguale fino al punto 4 del codice precedente)\
5) Preso o il mu del fit o la mediana, costruisco il plot. 
6) Nel caso abbia il fit per quel bin, l'incertezza associata al bin è quella del fit (suppongo l'ampiezza sigma della gaussiana centrale della dcb). Per la mediana probabilmente metterò la deviazione standard. Ora guarderò e farò sapere!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

