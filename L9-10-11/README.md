Lessons 9-10-11

Lesson 9 - video link: https://www.youtube.com/watch?v=BBgZs-jd_QY&list=PLrEMgOSrS_3cFJpM2gdw8EGFyRBZOyAKY&index=10

Transcript:
0:40
Prima o poi, ci dovevamo arrivare ai puntatori.
0:45
Ci siamo andati finora vicini, li abbiamo  sfiorati, li abbiamo salutati da lontano e  
0:53
oggi ci siamo arrivati. Questa lezione sarà breve  e servirà per comunicarvi l'idea fondamentale che  
1:02
c'è dietro i puntatori, perché i puntatori sono  facili, ma vanno presi a piccole dosi e con una  
1:08
certa propedeuticità della trattazione, altrimenti  diventano un casino. Ma in realtà sono poche idee.
1:16
Iniziamo con il nostro main. Con il nostro solito  main, io dichiaro una variabile intera che chiamo  
1:25
`x` e le assegno il valore di 5 e la stampo.  Quindi ho il `main`, `return 0;`. Questa è una  
1:37
variabile locale intera, si chiama `x` e vale 5.  Questa è una `printf` che stampa il valore di `x`.  
1:50
Compilo, eseguo, mi stampa 5.
2:01
Questo, invece, è un puntatore. Per dichiarare  un puntatore a un tipo intero (e ora vedremo  
2:11
perché i puntatori hanno un tipo), io  devo aggiungere l'asterisco prima del  
2:17
nome della variabile che sto dichiarando. Ora,  questo è un puntatore. Se fosse stato così,  
2:23
era una variabile intera che si chiama `y`.  Facendo precedere un asterisco al nome,  
2:32
`y` è un puntatore, ma la variabile si chiamerà  sempre `y`. Ok? È `y`, non è "puntatore y". Questo  
2:40
è solo un simbolo che modifica il tipo. C'è chi  preferisce, a tal proposito, mettere l'asterisco  
2:51
prima di `int`. Secondo me è un errore. Vi dico  perché. Se io faccio così, `int *y, z;`, siccome  
3:02
in realtà l'asterisco a livello grammaticale per  il C si riferisce al singolo nome della variabile,  
3:09
questo sarà un puntatore (`y` sarà un puntatore  di tipo intero), `z` invece sarà un intero,  
3:16
perché altrimenti dovrei mettere l'asterisco  pure qua. Quindi, secondo me, questa cosa di dire  
3:20
"intero puntatore", che sembra in qualche modo  chiarire, non è coerente con la grammatica del  
3:26
C. Quindi se uno vuole dichiarare due puntatori,  invece, scrive così. Se ne vuole dichiarare uno,  
3:31
scrive così. Questo è quello che io vi suggerisco  di fare. Poi decidete voi ciò che vorrete.
3:38
Così come ho stampato `x`, qui posso  stampare `y`, ma non devo usare `%d`,  
3:46
devo usare `%p`, perché `y` è un puntatore.  Questo puntatore lo inizializzo a zero,  
3:53
che è un indirizzo speciale che viene detto nullo,  l'indirizzo nullo. Compiliamo questo programma.
4:03
Quindi, questa è la mia variabile che vale 5  e questo è il mio puntatore che viene stampato  
4:09
in esadecimale. Per questo vedete `0x0`.  Ora, il C, quando un puntatore vale 0,  
4:16
ha una keyword specifica definita `NULL`, che è il  puntatore che vale zero. Quindi quando lo vogliamo  
4:25
settare a zero, scriviamo `NULL`. Se compiliamo,  l'effetto è identico, non cambia niente.
4:36
Ma qui viene il bello. Così come io posso  dichiarare un puntatore, all'inizio lo assegno  
4:45
a `NULL`, poi stampo il valore della `x`, poi  qua scrivo `y = &x;`. L'operatore `&` prima del  
4:55
nome di una variabile significa: non voglio il  valore della variabile, voglio l'indirizzo di  
5:03
memoria al quale la variabile è registrata.  Quindi voglio il puntatore alla variabile,  
5:08
perché i puntatori sono indirizzi di memoria.  Quindi ora possiamo scrivere qui: "x is stored  
5:17
at the address" e stampare `y`. Perché ora `y`  l'ho assegnato all'indirizzo di memoria dove  
5:26
`x` è registrato. Perché questo `x` deve essere  da qualche parte registrato (o meglio, potrebbe  
5:31
essere anche in un registro del microprocessore,  come abbiamo visto nella puntata 2, specialmente  
5:36
nell'approfondimento alla puntata 2). Ma se io  uso questo operatore, il compilatore sa che non  
5:44
può mettere `x` in un registro, perché se io  chiedo un puntatore, `x` deve essere per forza  
5:49
da qualche parte nella memoria. Vediamo dov'è.  Compilo, eseguo. `x` è registrato all'indirizzo...  
5:59
questo indirizzo qua, un indirizzo di  memoria come un altro del nostro processo.
6:04
Ora vi faccio vedere una cosa. Così  come l'asterisco serviva durante la  
6:14
definizione di un puntatore a dire che questo è  un puntatore e non una normale variabile intera...  
6:19
E poi vedremo perché. Comunque, uno potrebbe  dire: i puntatori sono indirizzi di memoria,  
6:24
gli indirizzi di memoria sono tutti uguali.  Perché mi fai specificare il tipo? Che  
6:30
differenza c'è tra un puntatore a intero, un  puntatore a char, un puntatore a una struttura?  
6:35
È sempre un indirizzo di memoria.  Se questa è una macchina a 64 bit,  
6:38
è un indirizzo di memoria a 64 bit. In effetti è  vero. Per ora, vi faccio vedere perché è utile,  
6:48
anche se tutti i puntatori sono  tutti numeri, indirizzi di memoria.
6:52
Stavamo dicendo: se invece io utilizzo l'asterisco  in una espressione normale (quindi non sono più  
7:00
qua che sto definendo una variabile), qui  io dico `*y = 10;`. In questo momento,  
7:10
io non sto scrivendo `y = 10`. In quel caso,  `y` (che è un puntatore e quindi memorizza degli  
7:18
indirizzi di memoria), se io scrivo `y = 10`,  vuol dire che il mio puntatore a questo punto  
7:23
punta all'indirizzo di memoria 10. No, io gli dico  con l'asterisco: all'indirizzo di memoria che è  
7:31
contenuto in `y` (che abbiamo visto qual era,  questo qui), a quell'indirizzo di memoria dove  
7:39
c'è un intero... e questo, come fa il compilatore  a sapere che c'è un intero? Perché il puntatore è  
7:44
di tipo intero! Ecco a cosa serve dichiarare il  tipo del puntatore. Quindi, a questo indirizzo  
7:50
di memoria `y`, dove c'è un intero, vagli a  scrivere 10. A questo punto, se io scrivo 10 a  
7:59
questo indirizzo di memoria, e a questo indirizzo  di memoria cos'è che c'è registrata? La variabile  
8:07
`x`. Quindi: "X was [valore]", "X now is  [nuovo valore]". Compiliamo. "X was 5".  
8:24
"X is at the address...", quello che è l'indirizzo  di memoria a cui è registrato. Ma ora `x` vale 10.
8:33
Io non mi illudo che voi abbiate capito  completamente questo esempio immediatamente,  
8:41
quindi ora noi lo ripercorreremo da capo. `x`  è una variabile intera che è registrata da  
8:47
qualche parte nella memoria. `y`,  invece, è sempre una variabile,  
8:53
ma che contiene l'indirizzo di memoria di un  intero. Quindi, attenzione che `y` non è largo  
9:05
quanto un intero, ma è largo quanto un tipo che  rappresenta un puntatore (come `uintptr_t`).  
9:10
Per dire, qua nel mio computer, `x` sarà un numero  a 32 bit, invece `y` è un numero a 64 bit. Cioè,  
9:19
questo "intero" mi sta dicendo solo che questo  indirizzo di memoria, questo puntatore, punta a  
9:25
un intero come tipo, ok? Quindi punta a qualcosa  che prende 4 byte in memoria, ma `y` stesso non è  
9:34
4 byte, è 8 byte, perché gli indirizzi su questa  mia macchina, che è un MacBook, sono a 8 byte.
9:41
Quindi io ho questo puntatore `y` e lo  setto a `NULL`, quindi all'indirizzo zero,  
9:46
che è un indirizzo speciale in C, che significa  che non c'è registrato niente, per capirci.  
9:52
Qui stampo il valore di `x`. Poi dico: `y`,  che può registrare indirizzi di memoria di  
10:00
tipi interi, è uguale all'indirizzo di  memoria a cui `x` è registrato. Quindi,  
10:07
dov'è che abita `x` dentro la memoria del mio  computer? Con l'operatore `&` io posso estrarre  
10:13
questo indirizzo di memoria. Quindi `y` ora vale  un numero che è l'indirizzo di memoria al quale  
10:19
è registrato `x`. E questo l'abbiamo visto  qua. Guardate questo indirizzo di memoria.
10:24
A questo punto, con l'asterisco prima di `y` e  con l'operatore di assegnamento, io gli dico: "Ora  
10:32
voglio che tu mi vada a scrivere il valore intero  10 nell'intero che nella memoria è memorizzato  
10:43
laddove ti dice `y`". Questa stessa cosa, per  rendere la cosa più chiara, potrei scriverla  
10:51
così: `y[0] = 10;`, perché c'è una strana  equivalenza in C tra i puntatori e gli array.  
10:57
Quindi è come se `y` contenesse l'indirizzo base  in cui c'è un array di interi, uno dopo l'altro, 4  
11:05
byte dopo l'altro. Ma in realtà, siccome `y` punta  a un singolo intero (perché qua `x`, poverino,  
11:13
ha un solo intero), io potrò usare solo l'indice  zero. Ma questa operazione qua fa capire meglio il  
11:22
modo in cui avviene in C questa operazione, che  è identica a scrivere `*y`. Quindi io ti dico:  
11:33
`y` è un indirizzo di memoria che avrà al  suo indice 0 un intero, al suo indice 1 un  
11:41
altro intero... vagli a scrivere 10. Guardate,  funziona allo stesso identico modo. `x` era 5,  
11:49
ora `x` è 10. Se io avessi scritto `y[1] = 10;`,  sto scrivendo fuori dalla memoria. Guardate,  
12:01
`x` rimane 5, perché sto scrivendo  nell'intero immediatamente dopo `x`,  
12:08
che chissà cosa c'è dentro. Poteva  benissimo andare in crash il programma.
12:13
E uno potrebbe essere tentato di dire:  "Ma questa cosa, perché è utile? Perché  
12:17
ho assegnato a `y` l'indirizzo di memoria  in cui è registrato `x` e poi ho utilizzato  
12:24
il puntatore per andare a modificare  `x`. Non potevo scrivere `x = 10`?".  
12:29
Beh, in questo caso sì, ma ci sono altri casi in  cui ciò non è possibile. E vi faccio un esempio. 
12:36
Per dire, questo era il vecchio valore di `x`,  questo era il nuovo valore di `x`. In questo  
12:44
caso è uguale, perché non abbiamo fatto niente.  Ora io scrivo una funzione `incr` che incrementa,  
12:51
a cui passo `y`. Questa funzione, guardate come  la definisco: `void`, quindi non ritorna niente,  
12:58
`incr` prende come unico argomento un puntatore  che chiamo `p` e scrivo `*p = *p + 1;`. Questo  
13:13
asterisco prima di `p` non funziona solo in  scrittura, funziona anche in lettura. Quindi:  
13:19
l'intero che c'è all'indirizzo `p` è uguale  all'intero che c'è all'indirizzo `p` + 1. Non  
13:26
ritorno niente, perché questa funzione è `void`.  Praticamente `y` incrementa il valore di `x`. Ah,  
13:36
però prima dobbiamo scrivere, ovviamente,  `y = &x;`, quindi a `y` dobbiamo assegnare  
13:45
l'indirizzo di memoria di `x`, e allora poi  a `incr` passerà questo indirizzo di memoria.  
13:57
La funzione `incr` prenderà quello che c'è  attualmente a questo indirizzo di memoria,  
14:01
ci aggiungerà uno e lo registrerà nello stesso  indirizzo di memoria dov'era prima. Compiliamo.
14:11
Prima valeva 5 e ora vale 6.
14:16
Questa funzione la posso chiamare  più volte. Ora vale 9. Guardate,  
14:23
io qua non ho fatto più riferimenti a `x`,  eppure il valore aumenta. C'è da dire una cosa:  
14:31
io questa funzione `incr` la potrei anche  chiamare così, non è che il puntatore lo  
14:37
devo per forza prima mettere dentro una  variabile puntatore a intero. Posso,  
14:42
visto che questa funzione accetta... che tipo è  il parametro `p`? È un puntatore a intero. Quindi  
14:53
lo prendo direttamente con `&` e il nome della  variabile di cui io voglio ottenere il puntatore.  
15:00
Quindi se compilo questo programma, l'effetto sarà  esattamente uguale. Prima valeva 5 e ora vale 6.
15:11
Secondo me, per oggi è abbastanza. Provate  a rivedere questo video e ditemi se finora  
15:18
avete capito che cos'è che succede,  perché è molto importante. Quindi,  
15:23
rivediamolo l'ultima volta in questa nuova forma.  `x` è una variabile intera registrata da qualche  
15:31
parte in memoria. La stampiamo. Poi passiamo  alla funzione `incr` l'indirizzo di memoria a  
15:37
cui è registrata `x`. Quindi saltiamo qui dentro  il programma. Ora `p` sarà l'indirizzo di memoria  
15:45
dove è registrato `x`, ma il compilatore sa  che questo indirizzo di memoria è l'indirizzo  
15:52
al quale è registrato un intero. Questo è il  motivo per cui i puntatori in C hanno un tipo,  
15:57
perché altrimenti sarebbero sempre numeri a 64  bit in questa piattaforma, a 32 bit in un'altra.
16:03
Questa espressione, utilizzando l'asterisco,  dice: prendi l'intero che è registrato  
16:10
all'indirizzo `p`, ci aggiungi uno e poi assegni  in quella locazione di memoria a cui punta `p` il  
16:21
risultato di questa espressione. Ok, abbiamo  visto che funziona e abbiamo visto pure che  
16:29
potremmo scriverlo allo stesso identico modo  così: `p[0] = p[0] + 1;`, per questa bizzarra  
16:36
analogia che c'è in C tra puntatori e array, che  è un'analogia molto semplice e utile. In realtà,  
16:45
in questo caso, è molto più chiaro quello che sta  avvenendo, secondo me, perché `p` è l'indirizzo  
16:49
base di memoria e `0` sarà il primo intero che  è registrato a partire da quell'indirizzo di  
16:57
memoria. `1` sarà il secondo intero e così via.  Compiliamo di nuovo: funziona come prima. Yeah.


My notes:
#include <stdio.h>

void incr(int *p) {
    *p = *p + 1; // il contenuto dell'inrizzo p = contenuto indirizzo p +1
}

int main(void) {
    int x = 5;
    int *n = 0; // indirizzo nullo
    printf("X: %d\n", x);
    printf("%p\n", n);

    int *y = NULL;
    y = &x; /* &var prende il puntatore alla variabile
    * in questo caso è necessariamente in un indirizzo della mamoria
    * non in un registro */
    printf("x is stored at the address: %p\n", y);

    // y = 10; // y punta all'indirizzo di memoria .N.
    *y = 10; // scrivo 10 dentro l'indirizzo di memoria a cui punta y
    printf("X changed by pointer: %d\n", x);
    
    y[0] = 11; // equivalente a *y = 10,
    printf("X changed by pointer[array style]: %d\n", x);


    //-----esempio utilizzo puntatori-----
    int z = 5;
    printf("Z: %d\n", z);

    int *w = &z;
    incr(w);
    printf("Z post incr: %d\n", z);

    return 0;
}



Lesson 10, video link: https://www.youtube.com/watch?v=lc7hL9Wt-ho&list=PLrEMgOSrS_3cFJpM2gdw8EGFyRBZOyAKY&index=11

Transcripts L10: 

Benvenuti amici a questo corso di programmazione  in linguaggio C. Questa è la decima lezione,  
0:49
la seconda lezione che parla dei puntatori, non  è l'ultima lezione che parla dei puntatori. Ehm,  
0:56
e che dire? Forse questo oltre un corso  di programmazione in linguaggio C è più  
1:02
in generale un corso di programmazione  eh un corso che si occupa, diciamo,  
1:10
e che si occuperà specialmente di programmazione a  basso livello, di programmazione di sistema e poi  
1:15
anche dell'interfaccia di programmazione  che ci dà Unix, l'interfaccia POSX.  
1:21
Però per ora dobbiamo costruire le basi e l'ultima  volta ci abbiamo provato eh con questo programma  
1:28
qua che eh dichiarava una variabile X di  tipo intero, passava alla funzione inc,  
1:37
un puntatore alla variabile, quindi l'indirizzo  di memoria della variabile invece che la della  
1:41
variabile stessa, perché la variabile vale 5. il  suo indirizzo di memoria varrà un numero 64 bit  
1:48
in questa macchina che è l'indirizzo di memoria e  la funzione Incr utilizza l'indirizzo di memoria  
1:54
per accedere alla variabile e modificarla  al posto della funzione chiamante perché  
2:00
in teoria questo X dovrebbe essere visibile  solo dalla main perché è una variabile locale,  
2:09
quindi non non dovrebbe avere visibilità fuori  dalla main, ma se io passo l'indirizzo di memoria  
2:15
un'altra funzione. La funzione tramite questo  indirizzo di memoria può accedere effettivamente  
2:20
a dove è memorizzata questa variabile e fare  quel che vuole, incrementarla. In questo caso  
2:27
accennavamo l'ultima volta al fatto che sia la  sintassi P di 0 che la sintassi asterisco P sono  
2:37
eh equivalenti e tutte e due leggono il valore  della variabile memorizzata dentro P. Queste  
2:45
due operazioni P di 0 o asterisco P si chiamano  differenziazione di P. Defferenziare significa  
2:55
semplicemente accedere ad un valore attraverso  il suo indirizzo di memoria. Questa operazione è  
3:03
possibile farla sia in lettura che in scrittura.  Per esempio, io posso scrivere qui print f,
3:13
qui posso scrivere prima di before incr
3:20
e eh utilizziamo asterisco P. invece  potremmo utilizzare pure joesto,  
3:26
sono equivalenti, ma per utilizzare  le due forme nello stesso programma  
3:29
uso questo e quindi sto accedendo in  lettura al puntatore P per leggerne  
3:36
l'intero e vi ricordo che il tipo di dato  che ritornerà all'operazione di differenza
3:43
è relativo al modo in cui è stato dichiarato il  puntatore, perché i puntatori sono tutti uguali,  
3:49
sono tutti interi della grandezza del bass  degli indirizzi del microprocessore che stiamo  
3:54
utilizzando. Quindi in teoria sono tutti interi.  Quindi a che serve il tipo? Solo a capire il  
4:00
programma, il C, il compilatore C deve capire cosa  deve ritornare quando questi puntatori vengono,  
4:05
diciamo, manipolati o differenziati e così  via. Quindi io scrivo questa cosa qui,
4:15
compilo before incrviamo
4:24
un po' perché questo a noi non ci basta. Io  dichiaro un puntatore a un intero e chiamo  
4:35
questa variabile y. y è un puntatore intero  e scrivo è uguale a X, cioè da X la l'END,  
4:47
come vi ricordate trasforma una variabile  nel suo estrae dalle variabili l'indirizzo di  
4:53
memoria alla quale essa è registrata. Io quindi  posso stampare X vive in P e vale dollaro D.  
5:06
Quindi vive in Y e vale X. Compiliamo
5:21
X vive nel senso di è registrata, vive, stiamo  scherzando, ha questo indirizzo qui e vale 5.  
5:30
Questo programma io potrei sostituirlo, cioè  qui Y in questo programma potrei sostituirlo  
5:35
scrivendo qui end x. Questo lo commento sennò mi  dà il warning che la variabile non è utilizzata.  
5:43
il risultato sarà uguale identico. Ovviamente  non è garantito che diverse esecuzioni dello  
5:52
stesso programma facciano sì che, guarda caso,  l'indirizzo di memoria è uguale. In questo caso  
5:57
sì, in altri sistemi non potrebbe non esserci  questa garanzia. In particolare, di solito,  
6:05
complicare un po' gli indirizzi memoria, eh, fare  lo stack ad una posizione casuale, l'ippin ad una  
6:13
posizione casuale, i vari blocchi di memoria che  il sistema operativo alloca per un nuovo processo,  
6:18
può essere anche una layer di sicurezza in più  contro certe vulnerabilità di corruzione della  
6:24
memoria. Ma ora noi faremo di più. Dichiariamo  anche una variabile Z che è un puntatore ha un  
6:35
puntatore di tipo intero perché la variabile  y sarà anch'essa registrata da qualche parte  
6:42
e io posso prendere l'indirizzo di y, quindi,  ma non posso usare il puntatore a un intero  
6:50
come questo, devo usare il puntatore a un  puntatore un intero. Quindi X vive in P.
7:00
E Y vive in questi commenti.  Facciamoli tutti in inglese.
7:08
stored in P and Mil is stored in
7:20
quindi uno in Y c'è registrato X, in Z c'è  registrato l'indirizzo memoria di Y. Compiliamo
7:33
quindi una variabile registrata qua e una  variabile registrata qua. Tutte e due queste  
7:39
variabili sono di tipo intero di cioè sono due  numeri, scusate, sono due puntatori, uno un  
7:44
puntatore un intero e uno un puntatore, ma tutti i  puntatori saranno sempre dei numeri, numeri della  
7:49
dimensione del basso indirizzi del processore.  Andiamo a vedere la loro dimensione. size of di y,  
7:59
size of di z. Facciamo il cast a intero. Allora,  a che cosa serve questa parentesi col tipo? Gli  
8:10
dice al C di convertire il il valore di ritorno  di quello che c'è a destra, cioè l'espressione  
8:17
che c'è a destra, gli dice di convertirla in un  tipo intero. Si chiama casting. Poi lo vedremo in  
8:23
dettaglio. Questo in questo caso è un escamotage  per evitare il warning qua della print f.
8:31
Ecco qui, 8 e 8 sono due numeri grandi  8 bit, quindi 64 8 byte, quindi 64 bit.  
8:41
Peraltro vi faccio vedere una  cosa. Se noi ci mettiamo qua pure
8:50
X, X non è 64 bit, è 32 bit 4 byte,  perché X è un intero. D'accordo?  
9:03
Se fosse stato un long in questa macchina  sarebbe stato eh puresso 64 bit, ma a noi  
9:09
quello che interessa è che tutti i puntatori sono  grandi uguali, sono larghi uguali. Poi eh se lo  
9:15
lo standard del C non garantisce questa cosa,  in questo momento fregatemene, sappiate che i  
9:21
puntatori normalmente sono sempre di della stessa  dimensione perché è così che funziona la C+ che ci  
9:27
sta sotto. Ehm, facciamo ora un altro esperimento  interessante. Poi abbiamo detto che le stringhe
9:42
my stray
9:47
di caratteri. Hello world. Io  posso stampare questa stringa
10:01
e mi stampa il World. Dopodiché io, siccome so  che questa è un array di tipi char, potrei dire,  
10:13
quindi c'è da una parte della memoria del  mio processo, del mio programma dove saranno  
10:19
registrati a partire da un certo indirizzo di  memoria tutti questi caratteri dopo l'altro e  
10:25
io quindi posso dichiarare un puntatore che  chiamo P di tipo char, quindi Questo P può  
10:34
contenere l'indirizzo di memoria di un carattere,  di un tipo numerico di con segno di un solo byte.  
10:46
E guarda caso in C il nome di un array è anche  un puntatore, quindi io posso scrivere char  
10:54
asterisco P è uguale mystr. In C tutti tutte  le variabili che sono dichiarate come rey  
11:02
possono essere utilizzate anche direttamente  come indirizzi di memoria, come puntatori di  
11:06
quel tipo. Non mi serve a me scrivere end my  str, anzi sarebbe un errore in questo caso  
11:13
perché proprio il nome stesso dell'array è il  puntatore a quell'array. Quindi guardate atrate,
11:29
io utilizzo due volte qua my str e  my str prima ancora di utilizzare P.  
11:35
Una volta lo stampo come un puntatore, una  volta lo stampo come una stringa, perché in  
11:40
realtà percentuale S che stampa le stringhe prende  proprio in questo caso la print F un puntatore un  
11:48
puntatore all'inizio della stringa. Quindi io  compilo questo programma, lo eseguo e io posso  
11:54
vedere che questo è l'indirizzo memoria a cui è  registrata la stringa e questa è la stringa in sé.  
12:00
Ma a questo punto io potrei provare a scrivere  la print F da me, o meglio tolgo la print F,  
12:12
anzi la rimetto. Vi ricordate che eh  percentuale C stampava il carattere dell'intero,  
12:22
il corrispondente nella tabella aschi all'intero  che io do qui per esempio 65 la maiuscola.  
12:29
Quindi compilo e stampo mi stampa la. Ma a  questo punto io posso stampare P di 0? Beh, p  
12:35
0 che cos'è? P è il puntatore all'inizio di questa  stringa. Se io faccio la differenziaazione della  
12:47
del puntatore P, quindi se prendo praticamente il  il char che c'è registrato a questo puntatore qua,  
12:54
dovrei avere la h, il primo carattere, perché my  string my stratore all'inizio di questa stringa,  
13:04
quindi io vedrò nel primo byte la h, nel secondo  byte la e, poi la h, la l, la l, la o e così via.  
13:10
Quindi stampiamo. Ed ecco la H. Ma c'è una cosa  interessante. Io posso fare anche percentuale C  
13:20
percentuale C e mi faccio stampare P di  0 e P di 1 e vedrò la H e la E. Quindi,  
13:31
quando io praticamente accedo al dato contenuto  in un puntatore utilizzando asterisco P, io posso  
13:38
accedere solo al primo degli elementi. Se invece  io utilizzo questa annotazione qua, quella con le  
13:44
parentesi quadre, io posso accedere al primo, al  secondo, al terzo, il che è molto comodo. Ma ci  
13:53
sarebbe un modo per me per accedere utilizzando  questa notazione qua al primo e questo sì, è  
13:59
facile, così funziona. E poi al secondo? Beh, sì,  io posso fare p + 1 perché i puntatori, essendo  
14:09
che sono interi numeri, io li posso incrementare,  li posso decrementare, posso fare ciò che  
14:17
farei coi numeri e quindi se io prima di fare  l'operazione che estrae il valore eh a cui punta  
14:26
il puntatore, io prima aggiungo uno al puntatore,  questo puntatore punterà esattamente un byte dopo.
14:35
Faccio così e ancora mi stampa he, quindi  sono due modi assolutamente equivalenti  
14:43
per fare questa cosa qua. Ora però vi voglio fare  vedere una cosa. Vi voglio fare vedere una cosa.
14:53
Io potrei fare una pazzia e dichiarare un  puntatore short P. Gli short sono interi a 16 bit,  
15:06
grandi 2 byte. E faccio short ugale my string.  E io qua mi faccio stampare come intero P,  
15:20
quello che c'è dentro P. Quindi i primi due  byte sono la H e la E. Ma io per comodità qua ci  
15:26
metto A a A a A, anzi B C D e E f. Vediamo che mi  stampa sto programma. Quindi guardate che faccio.  
15:38
Io dichiaro un array di interi di tipo char, di  caratteri, insomma. Ma noi sappiamo che in C i  
15:45
caratteri non sono altro che interi con segno di  8 bit da -250 da -128 a + 127 il loro range. Poi  
15:55
dichiaro un puntatore, però a un tipo non davvero  del tipo base. Qua sbaglio, diciamo, ma lo faccio  
16:01
apposta. Infatti io credo che riceverò un bel  warning perché, scusami, dice il compilatore C,  
16:09
ma tra l'altro da bravo Mariuolo quale è? Mica mi  dà un errore e mi non mi permette di compilarlo,  
16:16
mi dà un warning. Mi ha detto "Lo vuoi fare?  Fallo". Per citare sempre lo stesso meme. Ma  
16:24
guarda che qua c'è sbaglio perché sono due tipi  diversi. Allora io per zittirlo uso quel famoso  
16:30
casting. Quindi io dico questo, lo so, è un  puntatore a un tipo char. Io voglio però che  
16:38
tu me lo trasformi in un puntatore di tipo short.  Peraltro questa sarà un'operazione nulla perché  
16:44
il puntatore di tipo short e il puntatore di  tipo char indirizzi di memoria numeri 64 bit.  
16:50
È lo stesso indirizzo di memoria perché sempre  my string è. Quindi non farà niente questa  
16:56
operazione se non quello di di silenziare  il mio warning. E guardate mi stampa 16705.
17:08
Guarda caso, se io apro qua Python 0x a aa
17:16
eh No, scusate, 0x 65
17:22
No, devo andare a vedere quanto vale.  Vabbè, posso fare 65 + 65* 256, per capirci.  
17:31
Quindi io ho convertito i 265 che c'ho  nel primo byte e nel secondo byte nel  
17:36
numero a 16 bit che rappresentano.  D'accordo? Quindi praticamente a me  
17:40
mi è stampato sta cosa qui. Ora andiamo  al nostro programma. Che succede se io  
17:48
prima di stampare questo intero faccio P++?  Quindi io incremento di uno il puntatore P.  
17:56
In teoria sono qui col puntatore perché all'inizio  del puntatore punta my string. Se lo incremento  
18:01
di uno dovrei essere qui e quindi dovrei vedere  l'intero AB. Quindi dovrei vedere, per capirci,
18:12
dovrei vedere quindi il numero meno significativo,  
18:16
il byte meno significativo è 65. 66 * 256  dovrei vedere 16.961. 1961. E invece no,  
18:27
cari amici, io non vedrò questo numero, ne  vedrò un altro. Compiliamo ed eseguiamo.
18:34
Io vedo invece di 16.961.962.
18:39
Sapete perché? Perché questo è 66 + 66 * 256. E  sapete perché? Perché la matematica dei puntatori  
18:50
segue una regola molto particolare e utile, ovvero  quando io incremento o decremento un puntatore di  
18:58
1, in realtà questo 1 prima verrà moltiplicato per  la grandezza del tipo base del puntatore. Allora,  
19:05
se short vale 2 byte, ogni volta che io incremento  il puntatore sono qui. Quindi all'inizio di  
19:11
questi 2 byte, se lo incremento di uno vado qui,  perché uno short è 2 byte, lo incremento ancora,  
19:16
vado qui, lo incremento di quattro, vado 1 2 3 4,  vado dove c'è la E. Proviamoci. P = 4. Più uguale  
19:25
è un modo breve in C di scrivere più = p + 4. Ma  noi abituiamoci a queste cose comode. È uguale,  
19:34
no? Si può usare col per, col diviso, c'è  anche in altri linguaggi di programmazione,  
19:37
probabilmente lo sapete già. Compiliamo.  Oh, questo è il numero che becco che  
19:43
è A B C D. Eravamo alla E. Stavamo  puntando alla E, giusto? Quindi 65 66*
19:53
+ 69 * 256 può essere esatto 1773.
20:05
Inutile dire che questo trucchetto  vale pure, togliamo questo incremento  
20:09
e scriviamo pale pure in questo caso, cioè io  ho peglio perché è così utile che sia così.  
20:18
Io se qua c'ho dei short, quindi dei numeri  a 16 bit uno dopo l'altro, non è che poi se  
20:24
scrivo PD4 voglio andare 1 0 1 2 3 4 qua.  No, io voglio andare qua perché ognuno è un  
20:33
un numero a 16 bit 2 byte, quindi prime 2 byte  sono il primo. P0 PD1 PD2 PD3 PD4. D'accordo?
20:48
Non dimenticate mai che il Cene  fotte di voi e se scrivete PD40,  
20:53
che è completamente sbagliato  perché è fuori dalla nostra memoria,  
20:57
scriverà la memoria qualcosa che trova là  in quella memoria o andrà in segmentation  
21:03
fault. Se andiamo fuori dallo spazio di  indirizzo del programma, però dobbiamo  
21:08
trovare come andarci. Andiamoci con un numero  negativo qua. Eccoci qua. Segmentation fault.
21:20
Benissimo. E io tutto questo lo posso usare per  dichiarare un puntatore di tipo char a my string  
21:29
e scrivo while p non è zero. Vi ricordate che al  termine di una stringa c'è sempre un byte che vale  
21:41
zer? si chiama null term e segnala fine della  stringa. Quindi, fin quando io non incontro il  
21:48
carattere di terminazione della stringa che  mi dice che la mia stringa C è finita, uso
22:01
questa funzione che è la funzione  più No, scusate, si chiama putar.  
22:08
putar che prende soltanto un carattere e lo  stampa senza new line, senza niente. Quindi non  
22:15
sto più utilizzando la printf, sto utilizzando una  funzione molto più semplice put shar di quello che  
22:21
c'è in questo momento in P++. Quindi io incremento  il puntatore, alla fine devo stampare un new line,  
22:33
così vado a capo. Anzi, però non ce lo  mettiamo, tanto la mia ascella è furba  
22:37
e quando è così me lo fa vedere, gli mette un  eh una percentuale alla fine e mi fa vedere,  
22:43
guarda che questo output non aveva il new line  alla fine. Compiliamo. Guardate, mi stampa la  
22:51
mia stringa e qui mi stampa. Guarda che ti  manda ti manca l'invio mi dice la mia shell.
23:00
Ma a questo punto io posso scrivere at  the beginning P is il valore del puntatore
23:11
at the end P is. Compiliamo. Guardate, il  mio puntatore inizia a e E28 e finisce a  
23:25
E34 perché mentre io continuavo a incrementarlo  mano che stampavo i miei caratteri. E qua c'è il  
23:31
messaggio che che è appiccicato qui perché  qui mi manca la mia print f del new line,  
23:39
così si capisce meglio. Andiamo a vedere  di nuovo che cos'è che fa questo programma.  
23:45
Quindi dichiara un array di interi caratteri, lo  inizializza a un dato valore, usa il fatto che si  
23:55
può dichiarare un erray senza specificare la sua  grandezza e il C lo capirà dall'inizializzazione.  
24:02
Poi dichiara un puntatore che punta all'inizio  di questo array di piccoli interi di un byte,  
24:08
i miei caratteri. poi stamperà qual è in quel  momento l'indirizzo di memoria a cui il puntatore  
24:14
P punta e il puntatore è un numero, quindi io  avrò un numero. L'unica cosa è che eh percentuale  
24:22
P stampa il numero in esadecimale, ma io tra  l'altro potrei anche farmelo stampare in come  
24:31
unsigned long. Ora faccio questo casting  mostruoso anche qui. Anzi no, basta su.  
24:39
Un esempio ci basta. Ecco qui. Io qua lo vedo in  esadecciale indirizzo memoria, ma l'indirizzo di  
24:45
memoria è un numero eh, e quindi lo puoi stampare  come te pare, però di solito si stampano in  
24:50
esadecimale. Quindi io poi dico fino a quando  il valore che tu puoi estrarre dal puntatore  
24:57
P in questo momento, quindi fino a quando l'inore  memorizzato all'indirizzo di memoria P non è zero,  
25:04
stampami questo valore memorizzato all'indirizzo  di memoria P. E tra l'altro che valore è?  
25:08
il puntatore di tipo char, quindi quando io scrivo  asterisco P o quando scrivo Pentesi quad un numero  
25:15
mi verrò mi vedrò ritornare il tipo base, un char.  Se questo fosse stato puntatore di puntatore AP,  
25:21
io mi vedevo ritornare un puntatore AP. Quindi, in  pratica, ogni volta che voi fate eh differenziate  
25:29
il puntatore è come se toglieste un un asterisco,  quindi se puntatore di puntatore di puntatore,  
25:37
allora il tipo che ritorna è un puntatore a  puntatore a P. Siccome era già un puntatore a P,  
25:44
vi ritorna P che è cosa? Un char. Quindi io stampo  il carattere, potrei sostituire con questo, non  
25:52
cambia niente e poi scrivo P++ per incrementare  il puntatore. Quindi prima puntava all'inizio la  
25:58
stringa, poi punta al prossimo carattere e così  via, fino a quando poi alla fine punta a dove c'è  
26:03
il byte zero e il while esce. Così ora che abbiamo  messo il l'altra forma P0 funziona allo stesso  
26:13
modo. Ovviamente a me nulla mi vieta, per esempio,  di stampare PD1 se è uno use case in cui io voglio  
26:19
stampare sempre quello che c'è oltre il puntatore  e qua per rendere il program corretto gli dico  
26:25
continua fino a quando il valore non è per esempio  qua, ecco, qua mettiamoci un punto fino a quando  
26:34
non è punto il carattere nel quale sei, stampami  il carattere dopo. Quindi io compilo questo  
26:42
programma e guardate, mi stampa tutto fino al  punto perché quando c'è il punto in realtà esce,  
26:47
ma siccome quando ancora era sulla e entrava nel  loop e poi stampava il carattere successivo mi  
26:54
stampa il punto. Bene, io direi che con questa  lezione abbiamo messo abbastanza carne sul  
27:00
fuoco e abbiamo visto i puntatori un po' meglio  rispetto all'altra volta nella loro reale potenza  
27:07
e in maniera un po' più applicata perché per  esempio io grazie a questo ciclo che contiene un  
27:12
puntatore sono riuscito effettivamente a stampare  una stringa. Per finire vi voglio dire una cosa,  
27:18
che nulla vieta di prendere questa roba qua e  metterla in una funzione che si chiama printstr().
27:31
a io non cambio di una virgola il codice che c'è  dentro, ma qua rimetto lo zero perché sennò non va  
27:38
bene. E io qua chiamo print str e posso chiamare  pure print string perché sono la stessa roba,  
27:47
sono sempre puntatori a un tipo di carattere  e io vedo stampare la mia stringa due volte,  
27:54
ma nulla mi vieta anche di scrivere print string +  3 e quindi la terza volta io prima stampo a B CDE,  
28:03
AB CDE, BCDE perché parto da tre  caratteri dopo perché in questo  
28:07
modo ho passato il mio indirizzo  di memoria però 3 by avanti. L'ho  
28:12
incrementato prima di passarlo. Spero  di essere stato chiaro. Un salutone.


Lesson 11 - link: https://www.youtube.com/watch?v=msGzuneFpDU&list=PLrEMgOSrS_3cFJpM2gdw8EGFyRBZOyAKY&index=12

Transcript Lesson 11:
Bene, bene, bene. Eccoci arrivati addirittura  all'11ª puntata di questo corso di programmazione  
0:06
in C. E 11ª puntata vuol dire che sono già  trascorsi quasi 3 mesi dall'inizio del corso,  
0:15
il che è interessante e significa  che questo tipo di tentativo di  
0:21
divulgazione dell'informatica sta producendo  dei frutti. Perché il corso è seguito? Perché  
0:26
io continuo ad avere voglia di fare queste  lezioni e quindi qualcosa sta funzionando.
0:32
Nella scorsa puntata avevamo visto un programma.  Allora, questo è quello che avevamo fatto alla  
0:41
fine, ma le cose che avevano creato delle  perplessità, e l'ho letto poi nei commenti,  
0:46
e in effetti vi do atto che chi ha espresso  queste perplessità ha avuto ragione.
0:55
Erano dovute queste perplessità a questo tipo di  programma. Per esempio, io dichiaravo un array di  
1:07
caratteri, quindi una stringa in C, dove c'era  scritto per esempio "AABB", poi dichiaravo un  
1:15
puntatore a short a cui assegnavo... quindi il  puntatore a short è un indirizzo di memoria a  
1:24
numeri che sono di 2 byte ognuno. Gli assegnavo  in realtà l'indirizzo di memoria della stringa.  
1:32
Quindi ora sia `str` che `s` puntano allo stesso  indirizzo di memoria, ma quando io ci accedo  
1:38
col puntatore `str` (perché vi ricordo che per  l'equivalenza che c'è tra puntatori e nomi degli  
1:47
array in C, questo è anche un puntatore  oltre ad essere il nome dell'array)...  
1:54
quindi sia `s` che `str` puntano  allo stesso indirizzo di memoria,  
1:57
ma quando io accedo a questo indirizzo di memoria  attraverso `str`, sto prendendo caratteri,  
2:04
quindi il primo carattere, il secondo, il terzo,  il quarto, il quinto, eccetera. Mentre invece  
2:11
quando ci accedo tramite il puntatore `s` che è  di tipo short, prelevo con `s[0]` l'intero a 16  
2:17
bit che c'è nei primi 2 byte (quindi AA), e poi  con `s[1]` il secondo intero (che è BB). Questa  
2:24
cosa la possiamo verificare in maniera molto  semplice, facendoci stampare prima i due short.
2:44
Qua devo scrivere `short`, ovviamente, perché  il casting — quello che si mette tra parentesi  
2:49
che vuol dire "voglio che tu converta il tipo  dell'espressione a destra in questo tipo di  
2:57
dato di C" — ovviamente deve essere uno `short`  perché io poi assegno a un puntatore a `short`,  
3:03
ma il warning ci aiuta a non commettere questi  errori. Quindi, come vedete, prima praticamente  
3:10
qui ho lo short che equivale ad AA e qui ho lo  short che equivale a BB. Tra l'altro, questa  
3:16
cosa qui possiamo vederla meglio. Allora, io qua  ho scritto "AA" e "BB". Ma voi vi dovete ricordare  
3:33
che questi caratteri corrispondono a determinati  caratteri nel charset ASCII. E allora guardate,  
3:42
se io vado nel charset, in decimale, la 'a' a che  numero corrisponde? A 97. E la 'b' a 98. Quindi,  
3:54
anzi, facciamo una cosa più interessante:  guardiamolo in esadecimale. La 'a' minuscola è 61  
4:00
e la 'b' minuscola è 62. Se io lancio l'interprete  Python e scrivo `0x6161` e `0x6262`, qui ho dato  
4:11
esattamente i 2 byte che compongono il numero,  perché ho scritto il numero in esadecimale,  
4:17
quindi in base 16. Guardate, non è assolutamente  un caso che questi due numeri coincidano.
4:24
Allora, facciamo ora un altro test, un po'  diverso. Quando io ora inizializzo questo  
4:35
array di caratteri, io in realtà ci scrivo  1, 2, 2. Attenzione, non sono più caratteri,  
4:41
sono numeri. Quindi ora veramente i byte  varranno 1 e 2. Che possiamo vederlo con Python:  
4:48
`0x0101` e `0x0202` equivalgono a  un certo numero di 16 bit. Infatti,  
4:57
se io compilo il mio programma vedrete che  mi scrive 257 e 514. Ma perché accade questo?
5:07
Allora, io qui mi sposto dal C e vado a trattare,  diciamo così, un argomento di programmazione che  
5:15
è veramente basilare. Se io ho un numero a 8  bit, quindi un `char`, avrò dei bit: il bit 7,  
5:26
6, 5, 4, 3, 2, 1, 0. Ok? Ora, se io per dire ho  questi, ognuno di questi bit può valere 0 o 1.  
5:38
Ammettiamo che io abbia questi bit qui. Allora,  il bit meno significativo può valere 0 o 1. Il  
5:47
bit leggermente più significativo può valere 0  o 2, 0 o 4, 0 o 8. Ognuno vale una potenza del  
5:58
due. Questa cosa è molto semplice da vedere con  i numeri che tutti conosciamo, i numeri decimali.  
6:04
Allora, 2032 è lo stesso di scrivere 2*10^0  + 3*10^1 + 0*10^2 + 2*10^3. 10^0 fa 1,  
6:29
quindi è uguale a 2; più 10^1 fa 10, per 3  fa 30; più vabbè, 0 per qualsiasi cosa fa 0;  
6:41
più 2000, perché 10^3 fa 1000, per  2 fa 2000. Quindi 2000 + 30 + 2 fa  
6:48
2032. Questa cosa vale per tutte le basi,  non è una cosa speciale della base 10.
6:55
Allora, tanto per iniziare, se io ho un certo  numero di simboli, per esempio nei numeri  
7:02
normali in base 10 (quelli che scriviamo tutti,  per capirci, per chi non avesse la concezione  
7:07
di che cos'è la base nei sistemi numerici), ho 10  numeri, da 0 a 9. Se io ho 10 simboli e ho quattro  
7:14
posizioni in tutto, come nel caso di 2032, io  posso rappresentare massimo 10.000 simboli,  
7:21
ma siccome c'è anche lo zero, il range numerico  che potrò rappresentare è da 0 a 9999. Ok?  
7:30
Vabbè, qua, scusate, è come se avessi fatto una  sottrazione, volevo scrivere appunto l'intervallo.
7:36
Se io ho dei numeri in base due, quindi se  ho due simboli (0 e 1) e ho otto posizioni,  
7:46
posso rappresentare 256 diversi  pattern, quindi diversi, diciamo,  
7:53
elementi unici composti da questi 8 bit. E quindi  posso rappresentare un numero che va da 0 a 255.  
8:00
Infatti, questa cosa la si può vedere molto  facilmente: se tutti questi bit sono posti a 1,  
8:06
allora il valore sarebbe 1 + 2 + 4 +  8 + 16 + 32 + 64 + 128, che fa 255.
8:28
Ma che succede nel caso in cui io ho due byte,  un byte qui e un byte qui? In questo caso,  
8:35
praticamente io ho questo intero che è  rappresentato da 2 byte: 01 e 01. Allora,  
8:41
questo vale un valore da 0 a 255. Anche questo  vale un valore da 0 a 255, ma moltiplicato per  
8:51
256. E vi dico perché. Uno dei tanti modi per  capirlo è questo: abbiamo detto che quando io  
9:02
ho un numero a 8 bit, se lo moltiplico per 2  è come aggiungere uno zero qui e far scorrere  
9:14
sulla sinistra tutti gli altri bit. Visto  che sono tutte potenze di due che si sommano,  
9:21
se io moltiplico per 2, quello che era nel bit che  vale 2 diventa 4, quello che era nel bit che vale  
9:28
4 diventa 8 e così via. Quindi è come shiftare  tutto a sinistra. Ora, evidentemente, se questo  
9:33
bit qua è spostato di otto posizioni a sinistra,  ogni bit lo devo moltiplicare per 2^8, che è 256.  
9:55
Quindi, se io praticamente ho [0x01, 0x01],  allora avrò 1 * 256 + 1, che fa 257. Se ho [0x02,  
10:07
0x02] avrò 2 * 256 + 2, che fa 514. Che sono,  come potete vedere... forse non l'ho compilato,  
10:17
non me lo ricordo. Ah, scusate,  devo togliere questi commenti qui.
10:25
Come vedete sono i numeri, appunto, che avevamo  detto. Quindi è da lì che veniva questo 2 * 256,  
10:32
eccetera eccetera. Questa cosa qui, probabilmente  chi non ha idea di che cosa siano le basi  
10:37
numeriche (che è un argomento che si fa, credo,  addirittura alle scuole elementari ormai e poi  
10:41
si rifà forse alle scuole medie), comunque è un  argomento molto semplice. Però siccome è fuori,  
10:47
diciamo, dagli scopi di questa lezione, l'ho  spiegato giusto per darvi l'aggancio dal punto  
10:54
di vista di quello che succede nel computer.  Però è un argomento che, se non conoscete,  
10:59
vi dovete andare a studiare in un video su  YouTube di qualcuno che si occupa di matematica.
11:04
Mi sembra invece più interessante soffermarsi su  un altro dubbio. Se io ho questa stringa che vale  
11:11
"hello00123", avevo poi fatto una funzione che mi  stampava tutti i caratteri. Allora io dicevo `char  
11:21
*p = str`, quindi un puntatore di tipo `char`,  gli assegno un puntatore di tipo `char`, non mi  
11:27
serve il casting, qui sono lo stesso tipo, non sto  violando niente. E poi dicevo, fino a quando il  
11:39
carattere a cui `p` punta non è uguale a 0. Quindi  io dovrei scrivere `while (*p != 0)`, ma è uguale  
11:46
in C se scrivo solo `while (*p)`. E poi `p++`, e  incremento l'indirizzo al quale sta puntando `p`,  
12:08
e poi faccio stampare un carattere di invio  per terminare il programma in maniera pulita.
12:15
Allora, qualcuno mi diceva: "Scusa, ma come mai  qua che ci sono gli zero il programma non si  
12:21
ferma?". Ma questi non sono zero, e ve lo faccio  vedere subito. Ora io, invece di fare `putchar`,  
12:27
stampo il valore numerico di `*p`. Non  me lo faccio stampare come carattere,  
12:40
mi faccio stampare l'intero che quel `char`  rappresenta. Perché il `char`, ricordatevi,  
12:45
sì, sono caratteri, ma è un tipo numerico (da  -128 a +127). Ricordate quei 256 simboli che ho  
12:54
a disposizione? Se è un intero senza segno, li uso  per andare da 0 a 255. Se è un intero con segno,  
13:03
viene rappresentato in complemento  a due e quindi va da -128 a +127.
13:10
Come vedete, questi '0' valgono 48. Quindi io  vado a modificare il mio programma e dove qua  
13:19
io vedo "00", a un certo punto ci metto  davvero uno 0. Allora, questo zero come  
13:25
glielo posso mettere? Glielo posso mettere  in ottale, quindi lo trasformo in `\0`.
13:36
Ok? Stavolta il programma si è bloccato.  Qua mettiamoci di nuovo `putchar(*p)`.
13:53
Guardate, appena arriva al nullo si blocca.  Qua ci posso mettere altri due '0' che però  
13:58
sono caratteri e non un byte a valore zero, e  si fermerà dopo il primo byte nullo. Perché un  
14:05
conto è il carattere '0', che non vale zero  dal punto di vista dell'intero rappresentato  
14:11
dentro il mio array di numeri. Questo (`\0`) è  davvero invece uno zero, e qui si ferma tutto.
14:19
Com'è che potremmo avere delle stringhe che invece  sono "safe" dal punto di vista della lunghezza?  
14:25
Beh, per dire, ecco, teniamoci questa stringa.  Quanti byte sono? 1, 2, 3, 4, 5, 6, 7, 8, 9,  
14:33
10, 11, 12, 13, 14, 15 byte. Benissimo. Allora,  un byte che ha il valore di 15, quale sarebbe?  
14:57
Convertiamolo in base 8: 15 decimale è 17  ottale, quindi qua ci mettiamo `\017`. Qui  
15:12
ci ho messo un byte che vale 15. Quindi  ora trasformiamo la nostra funzione che  
15:23
stampa la stringa in questo modo. Si prende  prima con `int len` la lunghezza da `p`,  
15:32
e avrà quindi dentro `len` il numero di byte che  ci sono. A questo punto facciamo un ciclo `for  
15:41
(int j = 0; j < len; j++)` e stampiamo con  `putchar(p[j])`, e poi stampo il new line.
15:56
Quindi io prima mi prendo la lunghezza e però  devo avanzare il puntatore `p`. Guardate qua,  
16:00
posso fare sia la dereferenziazione del puntatore  `p` (quindi mi prendo il valore) e poi anche,  
16:08
come effetto collaterale, lo incremento di uno.  E quindi sono già al byte successivo. Quindi io  
16:19
posso scrivere "My string len is..."  e stampare il valore del primo byte.
16:37
Guardate: "my string length is 15".  E ora mi stampa tutto. Ovviamente il  
16:54
byte nullo che c'era prima non viene  stampato, perché la `putchar` non produce  
17:01
alcun output per il carattere nullo.  Ma stavolta ho implementato quelle  
17:04
che si chiamano "prefixed-length strings",  quindi le stringhe con lunghezza prefissa.  
17:11
La lunghezza non è più segnalata da un carattere  speciale, il null-terminator (cioè da un byte a  
17:20
zero), ma è prefissa, proprio qui all'inizio  della stringa. Ovviamente le stringhe prefisse  
17:30
fatte così avrebbero soltanto la possibilità di  essere lunghe al massimo 255 byte, perché ho usato  
17:37
un solo byte. Se avessi usato 2 byte, avrei avuto  stringhe fino a 65.535 di lunghezza, e così via.
17:49
In realtà pensavo di parlare di tutt'altro  in questa puntata del corso di C,  
17:55
ma è andata così. Possiamo  però fare una cosa in più.  
18:02
Questo era il programma che noi avevamo scritto  in una lezione precedente per far vedere almeno  
18:07
un utilizzo dei puntatori. Vi ricordo che  noi abbiamo avuto bisogno di utilizzare i  
18:16
puntatori perché passavamo la nostra griglia  con un puntatore. Allora ancora non li avevamo  
18:21
studiati i puntatori in C, ma mi è sembrato utile  introdurli. Ora possiamo capire finalmente perché  
18:28
queste cose funzionano. Guardate, `set_cell`  prende un puntatore alla griglia e, siccome c'è  
18:33
questa interessante equivalenza tra gli array e i  puntatori, quando ho il puntatore a `grid` posso  
18:39
utilizzare l'operatore delle parentesi quadre per  accedere agli elementi mettendo dentro l'indice.
19:17
Mi toccava raddoppiare la computazione  qui: `compute_new_state`, `print_grid` e  
19:22
la `sleep`. E se io questa cosa la voglio fare  solo una volta invece? Perché devo ripetere il  
19:27
codice? Solo perché poi il nuovo stato diventa  il secondo array e lo stato di output diventa  
19:34
il primo. Guardate, qua avevo `grid` e  poi avevo `new_grid`. Poi mi è toccato  
19:38
fare la computazione tra `new_grid` e `grid`. Ma  se la logica fosse stata più complessa che facevo,  
19:42
mi mettevo a replicare due volte una  logica complicata? Non mi pare il caso.
19:47
E allora vi faccio vedere una  cosa. Io avrei potuto fare:  
19:53
`char *old = old_grid;` e `char *new = new_grid;`.  
20:03
Quindi guardate, ora ho due puntatori,  un puntatore `old` e un puntatore `new`,  
20:07
che puntano all'inizio alla vecchia griglia e alla  nuova griglia. A questo punto, `compute_new_state`  
20:15
io lo faccio da `old` a `new`. Stampo la nuova  griglia, poi faccio la `sleep`, cancello quello  
20:25
che c'è sotto e ora che cosa posso fare? Inverto  i due puntatori. Quindi guardate, ora faccio:  
20:34
`char *temp`, mi serve un puntatore temporaneo per  salvarmi `old`. Così `old = new` e `new = temp`.  
20:45
Questo è lo swap banalissimo tra due variabili.  In questo modo io la mia computazione l'ho resa  
20:51
unica. Siccome ho la potenza, l'astrazione dei  puntatori, che è molto potente, io posso puntare  
20:57
con le mie variabili a qualsiasi parte della  memoria che voglio. Li inverto e quindi la mia  
21:02
logica è sempre uguale, ma ogni volta questi  due saranno scambiati uno rispetto all'altro.  
21:09
Compiliamo il programma e il programma funziona  come prima, ma ho evitato quella duplicazione.
21:18
Bene, volevo parlare di altro,  
21:19
ho parlato di questo. Spero che  comunque sia stato utile. A presto.

My Notes for both L 10 and L11:
#include <stdio.h>

/* accddere ad un valore tramite il suo indirizzo
 * di memoria è detto Deferenziazione */
void def_methods_incr(int *p)
{
    printf("Before incr: %d\n", *p);
    p[0] = p[0] + 1;
}

int main(void)
{

    int x = 5;
    int *y = &x;
    printf("x is stored in %p and is %d\n", y, x);

    int **z = &y;
    printf("x is stored in %p and y is stored in %p\n", y, z);
    printf("sizeof y %d, sizeof z %d\n", (int)sizeof(y), (int)sizeof(z)); // casting del sizeof a intero ad intero

    // -----------------
    char mystr[] = "Hello World";
    char *p = mystr;

    printf("At %p I can see: %s\n", mystr, mystr);

    printf("%c %c\n", p[2], *(p + 2)); // l l

    //------------------

    char *strPtr = mystr;

    printf("A the the beginning the string Pts is: %p\n", strPtr);
    while (*strPtr != 0)
    {
        putchar(*strPtr);
        strPtr++;
    }
    printf("\n");
    printf("A the the end the string Pts is: %p\n", strPtr);

    //-----------------
    /* Nel min 18 viene inserito un puntatore short su un "array" di tipo char.
     *  Mentre è stata allocata memoria per essere acceduta ad un byte verrà
     * acceduta a 2 byte con quel puntatore. Si legge in memoria 0x41 0x41 anzichè 0x41 e
     * stampa 16705 al posto di 65 - ...  01000001 01000001 .... -
     * di conseguenza incrementando di 1 il puntaotre avremo un
     * incremento reale di 16 bit e non 8 bit. Quindi il nostro nuovo
     * puntatore incrementato punterà a 0x42 0x42 - BB e non più AA
     * stampando quindi in decimale 16962, tra virgolette di seguito il
     * numero preso dalla memoria  ... 01000001 01000001 "01000010 01000010" ... */
    char str[] = "AABBCCDDEEFF";

    short *ptr = (short *)str;

    printf("First Ptr: %d\n", *ptr);

    ptr++;

    printf("After one add Ptr: %d\n", *ptr);

    //---------Prefix length string----------
    // p[0] è 15 in ottale
    char str1[] = "\017Hello00\0000000123";

    // facendo *p++ avrei dereferenziato il puntatore a aggiunto +1 a AA
    // ogni asterisco aggiunto è fondamentalmente un "go to pointed value"
    char *p1 = str1;
    printf("My string len is: %d\n", *p1);

    int len = *p1++;
    for (int j = 0; j < len; j++)
    {
        putchar(p1[j]);
    }
    printf("\n");

    return 0;
}