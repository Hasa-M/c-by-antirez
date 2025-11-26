# Lesson 3:

Creazione di una funzione incr, che torna void e non ha argomenti. La quale incrementa una variabile locale di 1 e la stampa a video. Spiega che questa funzione viene definita come side effect, ovvero che non ha un valore funzionale, non modifica nulla, ma ha l'effetto collaterale in questo caso di far succedere qualcosa.

Breve spiegazione differenza tra = e == (assegnazione e comparazione)
Spiega brevemente che C è un linguaggio imperativo.

Fa vedere che chiamando N volte incr dentro il main, comunque stampa sempre lo stesso risultato, perchè X è locale.

Introduce a questo punto il concetto di variabile locale, e definisce X globalmente. E definisce come il compilatore ragiona, passando alla ricerca delle variabili tra i vari scope. Non trovando X dichirata dentro la funzione la cerca a livello globale (in questo caso).

Spiega come X globale non perda lo stato ma venga creata ad inizio programma ed esisterà per tutta la durata del programma stesso.
A questo punto fa vedere che per ogni chiamata di incr nel main viene incrementata la variabile x.

A questo punto definisce la variabile globale definita dentro una funzione, attraverso l'utilizzo della keyword static. E come in questo caso sia effettivamente globale, ma visualizzabile solo fa function incr. E fa vedere come il programma non compili se X viene acceduta da un altra funzione.

Fa vedere come passando una variabile ad una funzione come argomento, questa non venga modificata anche se dentro la funzione c'è una modifica. Fino a quando si tratta di variabili locali.

Successivamente fa l'assegnazione e fa vedere come la variabile locale della main sia effettivamente cambiata.

Spiega spindi che in c per default gli argomenti vengono passati alle funzioni per valore e non per riferimento. Ovvero ricevono una copia del valore passato alla funzione. E spiega come tutto il C sia basato su questo concetto, anche per le strutture.

Spiega quindi che l'unico modo per il C di passare dei riferimenti è attraverso i puntatori.
Chiusa la questione passaggio variabili.


Passa adesso all'argomento dei tipi.

Parla di float. Stampoa il float utilizzando %.3f. 
Spiega che anche che se si utilizza lo specificatore sbagliato per stampare un determinato elemento, C comunque compila ma in questo caso la printf stampa cose impreviste.

Spiega la differenza tra fload e double e inizia a parlare dei tipi del c e definirli, int, double, float, chart, short(non garantito da specifica) etc. (inserire piccola tabella riassuntiva dei tipi e della memoria che utilizzano).
Spiega la fp32 che la rappresentazione è a mantissa ed esponente.

Spiega che il C ha delle regole di promozione delle variabili automatico, e fa l'esempio negli argomenti delle funzioni variatiche short to int, float to double.
Spiega che in C le regole di conversione automatica si applicano pure alle espressioni. Ma che sugli interi con segno non definisce un comportamento standard. Quindi bisogna stare attenti a non andare in overflow con gli interi con segno. Spiega cosa fa la keyword unsigned su un intero e che in questo caso un unsigned char = 255 va in overflow e diventa 0 e non -N come nel caso di quello con il segno.
(piccola lista delle regole di conversione)

Spiega a cosa serve il ++ in c per fare l'incremento.

nota: Consiglia di utilizzare un LLM come uno stack overflow evoluto in caso di dubbi.

