# Lesson 02 - 

stampa la somma nella funzione main.
Spiga cosa vuol dire printf - print formatted - e cosa fa, spampa in maniera formattata.

Definizione di funzione variatica, ovvero che prende un numero non determinato di argomenti come variabili.

Spiega cosa è il main, che a differenza delle altre funzioni, questo è il punto di partenza per il programma C e il programma C senza il main va in errore durante la compilazione.

Spiega come funzionano le variabili in C e come queste differiscono dalla dichiarazione del tipo di ritorno di una funzione. Spiega che le variabvili in C devono essere tipizzato.

Spiega cosa è l'inizializzazione di una variabile. Differenza tra inizializzazione e assegnazione.

Spiega come funzioni all'effettivo lo stack delle funzioni in C e fa vedere a livello assemby come vengano effettuate le chiamate delle funzioni.

Definizione di variabile locale, come vengono create ogni volta che viene chiamata una funzione che le dichiara internamente come la memoria viene gestita nelle funzioni e come venga liberata una volta che la funzione ritorna. Anche gli argomenti della funzione in C sono variabili locali.

Spiega a cosa serve il valore di ritorno del main, ovvero a segnalare all' OS se il programma ha avuto buon esito o meno. La convenzione su Unix è che se ritorna 0 ha avuto successo, alternativamente la compilazione ha fallito. ./a.ou; echo $? stampa il valore di ritorno del main.

Spiega il concetto di short circuit per l'and logico nella programmazione. E di come se la prima fallisca le altre non vengano eseguite e come questo sia utilizzato insieme al fatto che il main ritorni qualcosa.


Parte 2: "video link"

Spiega come funziona il garbage collector nella heap memory di javascript. E come nel C questo non sia analogo.

Spiega per cui come funziona il microprocessore 6502, processore del commodor 64 per via della sua semplicità.
Link di referenza: https://skilldrick.github.io/easy6502/

I micropocessori hanno all'interno un set di registri, sui quali operano, i registri sono delle piccole variabili che possono contenere solo numeri e sono altamente veloci. Queste stanno dentro il core del processore stesso.
Oltre ad operare sui registri i microprocessori questi utilizzano delle istruzioni che muovono i contenuti di una data locazione di memoria della RAM, da questa a uno dei registri o da un registro alla RAM.

I CISC, hanno una grande capacità di indirizzare la memoria e istruzioni complesse riescono ad allocare la memoria senza dover passare per i registri come step intermedio.

In generale comunque i microporocessori possono salvare e caricare informazioni attraverso i registri e la memoria.

Il 6502 ha pochissimi registri. Spiega una funzione di esempio del 6502. Fare riferimento al file 6502_program.txt.


Utilizza questo programma quindi per relazionarsi con le variabili locali dicendo come un determinato registro, che viene utilizzato per un programma specifico, nel momento in cui si salta ad un altra istruzione potrebbe essere riutilizzato, e si perde quindi il valore assegnato precedentemente al registro, se la memoria non viene gestita correttamente. Anche C usa spesso i registri per fare le computazioni. Per evitare problemi, viene utilizzato lo stack, ovvero un pezzo di memoria riservato a tale funzione.
*Inserire un immagine dello stack*.

Il C, dato il prototipo di una funzione, sa come dorvà chiamare quella funziona, basta che ne conosca l'indirizzo.

Spiega lo stack utilizzando come esempio l'intel 386.
Viene utilizzato un registro speciale, chiamato SP (stack pointer), che punta in una data posizione dello stack, questo contiene un indirizzo di memoria al suo interno(definizione di reference).
Ci sono istruzioni chiamate PUSH e POP che rispettivamente prendone un registro del microprocessore e lo salva direttamente nello stack in un unica istruzione molto veloce e l'opposto.
Per fare queste due operazioni viene utilizzato l'SP. La push decrementa lo SP di una "cella" mentre la POP incremente l'SP. Spiega che il registro BP è il base pointer, variabile. Fa vedere come lo stack si riempie al procedere delle istruzioni.
Parla del registro PC (program counter) che salva dove l'esecuzione del programma è.
Fare riferimento al file x86_msvc_v19.14.s.

In conclusione definisce le variabili locali in c come dei registri o valori temporanei nello stack.