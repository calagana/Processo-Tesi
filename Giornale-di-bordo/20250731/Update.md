Allora, sto rifacendo i grafici con i fit di CB invece di DCB. 
Sto inoltre analizzando bene anche i file cc e uu, perchè evidentemente ci sono delle differenze che causano problemi nelle efficienze di matching.
Sostanzialmente in cc ho un taglio a 5GeV, mentre in uu questo taglio non esiste.
Il problema principale mi pare di capire che raggruppando con R=0.4, a energie così basse ho problemi seri perchè la R non è ottimale. Di fatti, aumentando la R, i grafici fatti bin per bin migliorano e con essi i fit, e il motivo è che si considerano maggiormente l'apertura delle particelle di stato finale, quindi migliorando matching e energy response.
La soluzione per me è (dopo aver fatto sti fit con la cb invece della dcb) andare a vedere cosa succede andando a prendere l'asse di thrust, perchè se migliora molto evidentemente era un problema legato a quello.

Ok ho beccato un problema!!!
Praticamente, l'asse lo hai con eta,phi. Ma potrebbe essere in direzione opposta rispetto all'asse del quark che sto paragonando (l'asse lo sto calcolando come la media tra la q1 e q2, ma quindi potrebbe essere che q1 ha direzione opposta a quello dell'asse).\
Quindi, devo confrontarlo sia con la direzione che con la stessa ma verso opposto, sto confrontando vettori più che assi. Ottengo almeno il picco vicino a 0, ma un botto di eventi hanno la deltaR che arriva fino a tipo 10 e passa, il che non ha senso. Quindi di base è quessto che devi risolvere, cercare di capire perchè alcune volte ci sono questi problemi. aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa



<img width="796" height="572" alt="deltaR_thrust_axis" src="https://github.com/user-attachments/assets/ecc69502-fdcf-4010-927e-112aa3dc4dc8" />
