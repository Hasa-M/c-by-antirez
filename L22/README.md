Lesson 22 - Link: https://www.youtube.com/watch?v=OIseV5lcx8w&t=74s

Lesson 22 - Transcript:
0:40
Nella scorsa puntata avevo annunciato che avrei  parlato di Union, di Bitfield e di puntatori  
0:49
a funzioni, ma invece poi la puntata è stata  abbastanza lunga già di per sé con i primi due  
0:56
argomenti e siamo andati oltre. Ma pensavo che,  in effetti, il concetto di puntatore a funzione,  
1:03
per chi ha seguito finora questo corso, può  sembrare strano per il fatto che i puntatori  
1:11
che abbiamo visto per ora sono puntatori a  dei dati che sono registrati in memoria. I  
1:15
puntatori sono indirizzi di memoria. Quindi,  in che modo si può puntare a una funzione? Beh,  
1:22
il fatto è che anche le funzioni sono registrate  in memoria da qualche parte. Quello che ci  
1:26
trovi a quell'indirizzo è appunto il codice  macchina eseguibile che implementa la funzione.
1:35
Andiamo a vedere, tanto per iniziare, se è vero.  Allora, la main è una funzione. Vediamo se io  
1:49
posso stampare l'indirizzo di memoria della  main. Il nome di una funzione, così come il  
1:57
nome di un array, è un puntatore in C. Return  0. Compiliamo funkptr.c. Vedete, la funzione  
2:10
main è registrata a uno specifico indirizzo di  memoria che, tra l'altro, cambia ogni volta che  
2:16
io eseguo il programma. Non è che è fisso, ma  durante l'esecuzione del programma è fisso.
2:24
Vi faccio vedere una cosa. Se io chiamassi  la funzione main dalla funzione main,  
2:29
avrei un loop infinito. Ci siamo? Perché la  main chiama la main, e quello che succede è che  
2:35
stampa sempre di continuo l'indirizzo di memoria  della funzione main, perché la funzione main solo  
2:42
questo contiene, e poi va in segmentation fault.  Perché va in segmentation fault? Perché queste  
2:50
chiamate... vi ricordate quando abbiamo parlato di  ottimizzazione della funzione ricorsiva di coda?  
2:57
Siccome qua non abbiamo usato un livello  di ottimizzazione abbastanza alto da far  
3:07
sì che ci pensasse il compilatore... vediamo  se ci pensa lui in questo caso. Sì, guardate,  
3:12
appena io abilito le ottimizzazioni non  crasha più, ma in questo caso invece  
3:18
sì. A noi ci interessa il caso in cui va in  segmentation fault. La main chiama la main,  
3:22
chiama la main, chiama la main. Siccome usa ogni  volta per registrare, diciamo, lo stack pointer,  
3:28
vi ricordate? Abbiamo proprio fatto vedere come  succede l'invocazione di una funzione in C. Viene  
3:35
registrato l'indirizzo di ritorno, ci sono le  variabili locali e così via che vivono nello  
3:40
stack, quindi ogni volta si prende memoria in  un segmento di memoria che viene chiamato stack.  
3:47
Alla fine questo stack finisce. Di default è,  non lo so, 2 MB, 4 MB, 8 MB in base al sistema,  
3:53
ma ci sono persino delle chiamate per configurare  la grandezza dello stack. A quel punto vai a  
4:00
toccare una pagina... lo stack funziona a  ritroso. Si parte da indirizzi alti e si va  
4:05
sempre a ritroso. Quando finiscono praticamente  le pagine di stack che il sistema operativo ha  
4:11
allocato per questo processo, prima di eseguirlo,  si va a toccare un indirizzo che non è mappato e  
4:18
viene generata un'eccezione, il programma viene  interrotto e il sistema operativo ti dice che  
4:24
il programma ha toccato un indirizzo che non è  valido, un indirizzo di memoria che non è valido.
4:31
Ma al di là di questo excursus, il punto è che  noi possiamo stampare l'indirizzo di main. Ora  
4:42
facciamo una funzione diversa... anzi, sempre  usiamo main, che è il motivo per cui avevo  
4:49
usato questo trucco. Allora, vi dico come si fa un  puntatore a funzione. Uno prende praticamente la  
4:54
definizione della funzione, il prototipo, che non  è altro che questo: int main. Guardate, vedete?  
5:00
Si mette tra parentesi il nome della funzione e  si prepende al nome della funzione un asterisco.  
5:10
È una questione proprio meccanica. A  questo punto, questa definizione qui  
5:17
non è più il prototipo di una funzione, ma  è il puntatore a una funzione. Il prototipo  
5:23
è proprio il modo in cui si definisce.  Il prototipo può servire a due cose: o,  
5:26
appunto, a iniziare la definizione di una funzione  come in questo caso. Questa è, in questo caso,  
5:33
la definizione della funzione che inizia col  prototipo della funzione. O io il prototipo  
5:37
lo posso usare a parte e scriverlo qui per dire a  questo pezzo di programma: "Guarda che esiste una  
5:44
funzione main che è dichiarata così e così".  Magari 'sta funzione main è in un altro file,  
5:49
ma a questo ci arriveremo più avanti. Se per  caso non avete capito bene questo concetto di  
5:53
prototipo, non preoccupatevi, ma il punto è che,  ecco, sappiate comunque che il prototipo della  
5:59
funzione è anche presente nella definizione  della funzione prima della parentesi graffa.
6:04
Quindi, voi prendete l'indirizzo di ritorno della  funzione, il nome della funzione che era così,  
6:10
poi aperta parentesi tutti i parametri, avvolgete  il nome della funzione in due parentesi tonde,  
6:18
ci mettete prima un asterisco e questo è  diventato un puntatore a funzione. Ma non  
6:22
lo possiamo chiamare main perché main già  ce l'abbiamo, chiamiamolo my_f. A questo  
6:31
punto io posso scrivere my_f = main. Questo è un  puntatore a funzione e questa è una funzione. Ora,  
6:39
se io stampo main e poi stampo anche my_f,  vedo due volte lo stesso numero, perché uno  
6:48
punta all'altro. Ma la cosa interessante è  che my_f è chiamabile. Né più... no, scusate,  
6:55
void qua non devo scrivere... né più né meno come  se fosse una normalissima funzione. Guardate:  
7:01
f(). Qua noi avremo di nuovo il loop infinito,  perché stiamo chiamando la main dalla main.
7:09
Vedete? Scriviamo una nuova  funzione, void hello(void).  
7:21
Hello. E qua scriviamo una nuova funzione che  si chiama invece bau. Questa funzione è come la  
7:34
funzione hello che stampa "Hello!",  ma in realtà stamperà "Bau Bau!".
7:42
Stavolta togliamo tutto di qua. Allora, qual  è il prototipo? Il prototipo della mia hello  
7:49
e della mia baubau è uguale. Guardate,  queste due funzioni non ritornano niente,  
7:53
non prendono nessun parametro. Quindi io  posso scrivere un puntatore a funzione  
7:59
usando la nostra regoletta: tra parentesi ci  metto il nome e prima ci metto un asterisco,  
8:06
e void. Ok, questo x lo setto a hello e chiamo x.  Poi, guardate, X, che è sempre il mio puntatore a  
8:17
funzione, lo setto a baubau e chiamo di nuovo  X. Io sto chiamando sempre X, ma una volta X  
8:27
punta a hello e chiamerà hello, una seconda volta  X punta a baubau e chiamerà baubau. Compiliamo.
8:35
Fin qui mi sembra abbastanza semplice, ma  ora faremo il passaggio che vi farà dire:  
8:43
"Ah, ecco perché i puntatori a funzione sono così  utili". Scriviamo ora una funzione che chiamiamo  
8:52
call_n_times, "chiama n volte", che prende due  argomenti: un numero e un puntatore a funzione,  
9:05
e chiamerà quel puntatore a funzione n volte,  le volte che io specifico qua come argomento.  
9:13
Quindi deve prendere un puntatore a funzione.  Ma così come l'ho definita qua, questo qui  
9:18
può essere anche un argomento di una funzione. Le  funzioni possono prendere come argomenti puntatori  
9:24
a funzioni. Questo spazio togliamolo, che io di  solito non lo metto, era per chiarezza. Possono  
9:30
prendere benissimo puntatori a funzione o anche  restituirli. Io anche qua, come valore di ritorno,  
9:35
potrei avere un puntatore a funzione. Allora,  io qua ora faccio un ciclo for... vabbè,  
9:46
avrei potuto fare while(n--). Eh, ma sì, infatti  è meglio. while(n--). Quello che succede qui è che  
10:02
n è controllato per vedere se è zero, poi viene  decrementato, perché siccome non ho usato --n ma  
10:10
n--, il left value n viene decrementato, però il  valore di ritorno di questa espressione è n prima  
10:18
del decremento. Ok? In C ci sono due operatori  di incremento e di decremento, ++ e --. Uno è  
10:25
prefisso e l'altro postfisso. Quindi, in  base al fatto che lo mettete prima o dopo,  
10:29
il valore di ritorno dell'espressione sarà  o n prima dell'incremento/decremento o dopo.
10:41
E io chiamo la mia x n volte.  Ora guardate: call_n_times(10,  
10:52
hello) e poi call_n_times(10, baubau). Compiliamo.
11:02
Prima è stata chiamata 10 volte la mia funzione  hello, scusate. E poi 10 volte la mia funzione  
11:11
bau bau. Allora, vediamo com'è che funziona  'sto programma di nuovo. Siccome i prototipi  
11:16
di queste due funzioni sono uguali, dal punto  di vista di call_n_times, vale il prototipo  
11:25
della funzione. Se la funzione non mi ritorna  niente e io non gli devo passare parametri,  
11:29
quindi ha la stessa, diciamo, impronta, non ho  problemi. Posso chiamare X sia che X punti a hello  
11:41
o punti a bau bau, non mi interessa. Perché  questa roba qua è così importante, potente,  
11:48
utile? Lo vedete che abbiamo fatto un salto di  qualità incredibile? Possiamo fare funzioni che  
11:55
fanno delle cose con delle funzioni che noi  passiamo. Questo è un livello di astrazione  
11:59
che i linguaggi ad alto livello hanno in maniera  ovvia, ma che il C, senza i puntatori a funzione,  
12:07
non potrebbe avere mai e sarebbe limitato  nel fare una quantità di cose enorme.
12:13
Cosa direte voi? cp function_pointer.c  function_pointer2.c.
12:21
Togliamo 'sta roba qua, ci teniamo  sostanzialmente solo la main. Ma sì,  
12:26
andiamo a guardare una chiamata di  libreria della libc: qsort. Scusate,  
12:34
guardate, è inclusa in stdlib.h, che noi  andiamo a mettere nel nostro programma.  
12:43
Guardate come funziona. Io gli passo... ci sono  heapsort, mergesort... no, ma noi usiamo qsort.  
12:50
Gli passo un puntatore a una base dove io  ho degli elementi da ordinare, qualcosa da  
12:55
ordinare. Poi gli dico il numero di elementi che  devo ordinare, la dimensione di ognuno di questi  
13:02
elementi e gli passo un puntatore a funzione  che deve fare da comparatore per vedere se  
13:08
il mio elemento è maggiore o minore, perché per  fare il sorting di qualcosa bisogna che sia così.
13:18
Allora, guardate, io dichiaro un array a di  10 elementi, poi scrivo for(int j = 0; j < 10;  
13:30
j++) a[j] = rand(), un numero casuale.  Poi ripeto 'sto ciclo for e mi faccio  
13:40
stampare questi elementi qua. Qua mettiamo il  newline, perché qui ho messo solo lo spazio,  
13:51
altrimenti diventa tutto di fila, invece  me lo faccio stampare in una singola  
13:54
riga. Quindi questo programma prima con un  ciclo for riempie l'array e poi lo stampa.  
14:00
Compiliamo. Si chiamava function_pointer2.  Vedete? Allora, facciamo una cosa. Siccome  
14:07
questi numeri sono troppo grandi e sono  inestetici, limitiamoli a un po' di bit.  
14:18
Esattamente. Vabbè, qua ho usato una maschera con  15 perché vi faccio vedere una cosa. In binario,  
14:33
quindi, è i primi 4 bit a 1. Ok? Quindi  qualsiasi numero randomico viene fuori da rand,  
14:45
io poi faccio l'operatore di bitwise AND che mi  fa passare solo i bit che sono veri sia da questa  
14:54
parte che da questa. Siccome a destra ci sono solo  i 4 bit meno significativi settati a uno, io mi  
15:01
prenderò solo quelli da ciò che mi esce da rand.  Ok? È una maschera e quindi avrò numeri da 0 a 15.
15:09
Ma questi numeri sono, come avete visto,  disordinati. Guardate, 7 e così via. Lo  
15:16
vedete che poi sono sempre gli stessi? Le  funzioni di generazione di numeri casuali  
15:22
in C sono di default deterministiche, perché  se io ho un bug alla centesima iterazione,  
15:30
voglio che sia sempre uguale. C'è il modo  con srand(), ma qualche volta lo vedremo  
15:38
più avanti. Di solito, per mettere un seme  diverso nel generatore di numeri casuali,  
15:46
qua si mette, per dire, il tempo attuale in  millisecondi o, ancora meglio, in microsecondi,  
15:55
in modo che ad ogni avvio sarà diverso. Ma a  noi ci interessa per ora... noi stiamo usando  
16:00
la chiamata di libreria rand(), man 3 rand, che  è molto semplice, ritorna un intero casuale,  
16:08
sempre nella stdlib, e fa parte della libc. Non  l'avevamo mai usata, forse, non me lo ricordo.
16:15
Bene, se io volessi ordinare questo array,  posso usare proprio qsort. Allora, guardate,  
16:23
io gli devo dare come primo argomento la base, che  è a, perché ricordate, il nome dell'array è anche  
16:30
il puntatore all'inizio dell'array. Poi gli devo  dire il numero di elementi che ho, che sono 10,  
16:35
la dimensione di ogni elemento, sizeof(int)  (qua io lo so che è 4 byte, potevo scrivere 4),  
16:43
e poi una funzione di comparatore che devo  scrivere io, e io la chiamo compare_integers.
16:50
Guardiamo in qsort questo comparatore... vabbè, è  sempre uguale qua. Copiamocelo. compare_integers.  
17:07
Allora, guardate qua, gli serve un puntatore  al primo elemento e un puntatore al secondo  
17:15
elemento. `const`. Poi vi dico cos'è. Significa,  praticamente, che la funzione si impegna a non  
17:24
modificare quello a cui punta A e quello a  cui punta B. Quindi si riceve il puntatore,  
17:29
questo puntatore si può usare in lettura. Se noi  scriviamo in questo puntatore e non abbiamo fatto  
17:35
casting e altre cose per cui il C non se ne  può accorgere più, ma se proviamo a scrivere  
17:39
in questo puntatore in maniera, diciamo,  limpida e lineare, il C ci dà un errore.
17:45
Allora, che cosa sta succedendo qui?  Guardate, l'array è questo qua. Allora,  
17:50
io c'ho il primo elemento che occupa 4  byte, il secondo, il terzo, il quarto,  
17:56
il quinto e così via, fino al decimo elemento.  Ok? Ho usato 0... 1... perché sono 0-based,  
18:04
a[0] è questo qua. Prima, dicendogli come base, io  gli ho dato questo elemento, questo byte iniziale,  
18:12
ok? L'indirizzo di memoria a cui parte tutto  'sto array. Dopodiché, ogni volta che ci sarà  
18:18
da comparare due elementi, io mi becco,  guardate, un puntatore... per dire, vuole  
18:22
comparare questo e questo, vuole sapere se uno  è maggiore dell'altro. Io mi becco una callback,  
18:28
quindi qsort chiamerà diverse volte, man mano  che fa l'ordinamento, questo compare_integers,  
18:35
passandomi il puntatore all'elemento che vuole  comparare, A, con l'altro elemento che vuole  
18:40
comparare, B. Ma sempre puntatori, perché lui  non sa dentro come sono strutturati 'sti dati,  
18:46
che tipi sono. Lui mi passa i puntatori. E com'è  che mi può passare i puntatori? Beh, sa il numero  
18:51
di elementi, sa quanto è grande ogni elemento,  sa esattamente come passarmi i puntatori. Quando  
18:56
ci sarà da fare gli swap, lui sa le dimensioni,  quindi potrà fare queste cose. La funzione qsort  
19:03
può fare queste cose senza sapere la struttura  dei miei dati, purché io gli dia una funzione che  
19:10
serve per comparare i dati, visto che qsort non  ha idea di che c'è registrato dentro questi dati.
19:17
Allora, l'interfaccia con cui qsort si è accordata  col programmatore è che questa funzione di  
19:24
comparazione ritorna < 0 se A è minore di B, 0  se sono uguali, > 0 se A è maggiore di B. Tanto  
19:38
per iniziare, mi serve estrarre i valori di questi  dati, perché questi sono puntatori a void. Quindi  
19:47
io dichiaro un puntatore a intero che chiamo ap,  uguale ad a. Essendo int*, ce li ho del giusto  
20:05
tipo. Dopodiché, io potrei fare banalmente *ap  - *bp. Qua stiamo dereferenziando il puntatore,  
20:30
quindi dal puntatore io arrivo all'intero. O, se  preferite e vi viene più facile pensarci, possiamo  
20:36
fare anche in questi termini, vi ricordate?  L'abbiamo detto tante volte che è equivalente.  
20:40
Allora, perché ho fatto questa sottrazione? Ho  fatto questa sottrazione perché se i numeri sono  
20:46
uguali, la sottrazione viene zero. Ok? Se il mio  primo numero è minore del mio secondo numero,  
21:02
verrà meno di 0, altrimenti verrà più di 0.  Quindi questo è un modo più veloce per dire  
21:09
"if a > if b". Però, in base ai range numerici che  noi stiamo utilizzando, a volte questo sistema qui  
21:19
può creare un overflow. Se noi compiliamo questo  programma... eh, che ho sbagliato? Ah, scusate,  
21:32
qui ho messo il puntatore a funzione. Anche qui  non ha senso nella dichiarazione della funzione.  
21:38
Eh, quindi se noi ora compiliamo questo programma  qua... eh, allora qua dobbiamo usare il casting.  
21:50
E `const int*` più che altro, perché non stiamo  usando... o meglio, invece di questo casting qua,  
21:56
dobbiamo dichiararli const, così il compilatore  è contento. E un'altra cosa che dobbiamo fare è  
22:02
di spostare la funzione qsort qui, prima che  ci facciamo stampare i valori, altrimenti  
22:09
becchiamo i valori già prima dell'ordinamento.  Vedete che ora sono perfettamente ordinati.
22:15
Ma questo programma funziona perché  i valori sono piccoli. Altrimenti,  
22:20
immaginate qua cosa succede se, per esempio,  io ho qua 10 a ap[0] e bp[0] è INT_MAX,  
22:26
quindi il valore più grande. Una volta che io  sottraggo da 10 INT_MAX, ho un wrap-around,  
22:34
mi ritrovo con un valore positivo e quindi  non funziona. Quindi il modo in cui questo  
22:39
codice si può scrivere correttamente  è: if (ap[0] > bp[0]) return 1;  
22:48
else if (ap[0] < bp[0]) return -1; else return  0. Questo codice invece è ok con gli overflow e  
23:05
dovrebbe funzionare senza problemi. Infatti,  io per vedere se ciò è vero, posso fare che,  
23:11
anche se riempio 'sti array con questi valori, poi  qua gli mettiamo a[2] = INT_MAX e a[5] = INT_MIN.  
23:23
Qua devo includere limits.h... e vedrò... no,  non sta funzionando. Ah, perché l'ho messo dopo  
23:35
il qsort, scusatemi. Mettiamolo in maniera  corretta. Come vedete, funziona. L'INT_MIN è  
23:44
qui e l'INT_MAX è qui, e quindi non ci sono stati  problemi con la comparazione degli altri numeri.
23:53
Il qsort ci ha mostrato la potenza dei  puntatori a funzione. Anche la funzione  
23:58
stupidissima che avevo fatto io, quella  call_n_times, già aveva questo concetto,  
24:03
ma questa è una delle applicazioni più  interessanti dei puntatori a funzione:  
24:08
qsort. Ma, indovinate? Queste cose qua  si possono mischiare con le strutture,  
24:14
perché le strutture possono avere anche  puntatori a funzione. Pensateci su. Allora,  
24:18
le strutture hanno dei dati, possono contenere  anche puntatori a funzione. La struttura,  
24:23
vista da quest'ottica nuova, somiglia abbastanza a  una cosa che conosciamo bene, ovvero a un oggetto.
24:30
Quindi, nella prossima puntata, magari affrontiamo  questa idea di puntatore a funzione che vive nelle  
24:37
strutture, non però per fare cose tipo un sistema  di oggetti in C. Io lo so che in questo momento  
24:42
voi siete felici di vedere una cosa del genere,  però noi qua in questo corso dobbiamo... sapete  
24:48
la premessa che ho fatto la prima puntata, non è  qua per far vedere che sono figo, ma piuttosto,  
24:52
io sbaglio, vi faccio vedere gli errori... è  per darvi il massimo. E per darvi il massimo,  
24:57
io vi faccio vedere come si usano i puntatori a  funzione dentro le strutture quando si fanno le  
25:02
cose serie, e non quando si fanno i sistemi a  oggetti in C, che sono fighissimi, ma siccome  
25:06
non li usa quasi nessuno ed è un approccio molto  specializzato, magari ci arriveremo pure. Però,  
25:11
io vi vorrei far vedere invece un  approccio più reale. Ciao, alla prossima.