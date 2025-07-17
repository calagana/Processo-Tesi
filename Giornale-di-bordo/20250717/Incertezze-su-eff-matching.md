## binvar_effmatching.cpp
Apro binvar_effmatching.cpp, bisogna mettere l'incertezza calcolata con TEfficiency come scritto ieri nel programma "per domani"

Ho messo l'incertezza e oggi ho fatto il grafico. Vorrei capire come cavolo l'ha calcolata questa incertezza. 
A quanto pare quella che usa è una binomiale più completa, cioè che prende in considerazione il fatto che se l'efficienza va ad 1, l'incertezza non può andare a 0. Questa è chiamata Clopper-Pearson, ed è il metodo base utilizzato da TEfficiency per calcolarla sostanzialmente. Che cosa sarebbe?
__________________________________________________________________________________
Perciò per riassumere clopper-pearson in due parole:\
Fisso un intervallo di confidenza che voglio per la mia epsilon, chiamandolo 1-alfa. Di base è 68.3% = 1-alfa.\
Prendo la binomiale che dà la probabilità di osservare k successi avendo n tentativi e epsilon di probabilità.\
Prendo la cdf di questa distribuzione (somme su tutte le k fino ad una k_obs). Ora questa è una funzione di distribuzione di probabilità di epsilon.\
Considero ora la epsilon come quella che devo far variare. Fisso il numero di successi. Cioè k_obs è fermo ora ed è quello che ho osservato.\
Faccio variare la epsilon. Il mio obiettivo è arrivare ad epsilon tali che le code della cdf siano pari ad alfa/2. Cioè, io cerco: CDF(k_obs|n,epsilon_high) = alfa/2 , CDF(k_obs|n,epsilon_low) = 1-alfa/2 (perchè la cdf è definita dal basso, cioè la prob di avere k<k_obs. Per avere la coda alta della distribuzione perciò prendo 1-quello).\
!!!!!! Attenzione, definisco la epsilon_low con l'imposizione sulla coda in alto e epsilon_high per quella in basso. 
Perchè mantenendo la k fissata, se voglio solo un tot (relativamente basso) sull'incertezza della coda alta, mi verrà una epsilon bassa, perchè la pdf della k si abbassa se si abbassa la probabilità di successo, cioè la epsilon. In altre parole:\
ε_low è così piccola che raramente produce ≥k_obs → coda superiore = α⁄2\
ε_high è così grande che spesso produce ≤k_obs → coda inferiore = α⁄2\

Quelli sono gli estremi della mia epsilon\
___________________________________________________________________________________
