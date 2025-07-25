Hai fatto quasi tutto per 0.8, 1.2 e 1.6. Il problema principale è ora riuscire a capire cosa devi fare con il chi2, ngdl e p value! in 0.8 ad esempio fa casino
Il punto è sostanzialmente come mettere le incertezze.
Sostanzialmente è un discorso da fare pre fit, cosa ho: Ho un istogramma delle E_jet/E_quark in un determinato intervallo di energie. 
Bin per bin per il momento l'incertezza calcolata è quella automatica di TH1F o TH1D. Che di base per ogni bin usa quella poissoniana, cioè sqrt(N).
Mo non sono sicurissimo che questo vada bene in realtà... Ma la domanda è, quanto ci interessa? In realtà a vederli quei grafici sono quelli che sembrano più corretti di tutti. Non so benissimo servirebbe parlare con i professori, più che altro per chiedere come mettere le incertezze.
Il discorso è: pure che io aumento le incertezze perchè al momento sono sottostimate (causando l'alto chi2), ma quanto importerebbe? Non le userei mai più quasi. Non è che aumentano il valore dell'incertezza del fit ad esempio, che alla fine è quello che ci interessa.
In realtà ora che ci penso potrebbe aumentarla. Il fit è fatto per minimizzare il chi2, e se la sigma aumenta, forse otterrei altri valori (anche se mi sembra difficile vengano eccessivamente lontani da quello che ho adesso).
