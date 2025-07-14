Come funziona l'algoritmo antiKT che sto utilizzando: Parte da una collezione di particelle ovviamente. In primis, calcola due grandezze, la
"distanza" tra una particella e l'altra: d_{ij} = min(1/P_Ti^2 , 1/P_Tj^2) * DeltaR^2/R^2
"distanza" tra la particella e il quark: d_{iB} = 1/P_Ti^2
Lo calcola per tutte le particelle e tutte le coppie di particelle.
Trova il minimo tra queste, e qui possono succedere due cose: \

Il minimo è un d_{ij}. Questo vuol dire che nella nostra strana metrica le due particelle ij sono molto vicine, quindi le considera come un primo pseudojet. Le accorpa sostanzialmente, sommandone i momenti.\
Il minimo è un d_{iB}. In questo caso invece la particella i non è vicina sostanzialmente a nulla, quindi la considera un jet isolato. Perciò la prende come singolo jet e la rimuove dal dataset. Non è più accorpabile a niente.
Fatto questo, ha un dataset aggiornato, quindi riparte, ricalcola il d_{ij}, d_{iB} e si ricomincia, finchè non ottiene jet accorpati e particelle singole.
Notare che nel caso in cui in effetti il minimo è un d_{ij}, allora per le particelle i e j ho: d_{ij} < d_{iB} e d_{ij} < d_{jB}. Prendendo quella con momento più alto tra i e j, l'eq a cui si risponde è: DeltaR^2/R^2 < 1 perciò DeltaR^2 < R^2, dove R è l'apertura del cono! Quindi le particelle sono effettivamente interne al cono
