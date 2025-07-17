PER DOMANI. 
Devi capire come mettere le incertezze sull'efficienza di matching. In teoria il tutto potrebbe esserer visto come binomiale di base (probabilità p, numero di successi k, numero di eventi totali n ad esempio). Ma l'incertezza viene una cosa tipo sqrt(p(1-p)/n), che se calcolo la p come p = k/n, se p=1 come per gli eventi a più alta energia non funziona più niente e l'incertezza viene 0. 
ChatGPT dice che in questi casi solitamente si usano altri tipi di incertezze, come Clopper-Pearson! Si calcola direttamente da TEfficiency come dice Santanstasio, e la calcoli direttametne come
________________________________________________
TEfficiency* eff = new TEfficiency(num_matched, num_total);  // histogram numeratore, denominatore
eff->SetStatisticOption(TEfficiency::kFCP);  // Frequentist Clopper–Pearson

eff->Draw("AP");  // Mostra efficienza con intervalli a barre
________________________________________________

Inseriscilo nel codice che stavi scrivendo ieri per solo la parte con bin variabili, cioè il codice chiamato: binvar_effmatching.cpp   
Vedi quello! inserita queesto e fatto questo benedetto grafico, poi vai su bin per bin della percentuale di energia ricostruita per guardare le mediane e le distribuzioni invece delle medie. 
E poi tutto ciò l'hai finito. sembra veloce ma non funziona mai un cazzo aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
