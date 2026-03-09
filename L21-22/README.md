Lesson 21 - Link: https://www.youtube.com/watch?v=TM4jgODgdFY&t=320s

Lesson 21 - Transcript:
0:42
Noi, nel corso di questo viaggio nel  linguaggio di programmazione C, abbiamo  
0:51
sempre cercato (o, meglio, ho sempre cercato,  ma questo è anche il mood generale di quelli che  
0:56
guardano queste lezioni) di alternare la teoria  con la pratica; di combinare, direi piuttosto,  
1:04
la teoria con la pratica. Solo che ogni tanto  bisogna necessariamente fare degli approfondimenti  
1:10
proprio sulla struttura del linguaggio C, che poi  sono propedeutici per andare avanti. Quindi alcune  
1:19
volte, come in questa lezione, non possiamo più  di tanto scrivere dei programmi piccoli, utili,  
1:24
interessanti, che ci facciano capire non solo il C  com'è fatto, ma proprio la struttura dei programmi  
1:31
in C, qual è la logica, qual è l'approccio.  Dobbiamo invece parlare di feature, feature pure.
1:40
Nelle scorse puntate abbiamo parlato di strutture  senza parlare di union. Abbiamo parlato di  
1:51
strutture senza parlare di bitfield e, infine,  non abbiamo parlato di puntatori a funzione quando  
2:02
abbiamo parlato di puntatori. Queste tre cose —  le unioni, i bitfield e i puntatori a funzione —  
2:10
iniziano a diventare, per il proseguire del corso,  un debito tecnico pesante che incide con quello  
2:20
che si può e non si può fare. Quindi, questa  puntata servirà a recuperare tale debito tecnico.
2:25
Iniziamo dalle unioni (union).
2:33
Iniziamo col nostro semplicissimo,  diciamo, "hello world". Neanche,  
2:38
non c'è proprio niente. La base, giusto per far  vedere qualcosa. Allora, io posso dichiarare una  
2:49
struttura che ha due campi: un campo `int i`  e un campo `unsigned char a` come array di 4.
3:09
Nella memoria del computer, questo array  di quattro caratteri e questo intero,  
3:17
che layout avranno in questa macchina? L'intero è  4 byte. Quindi io mi beccherò questi primi 4 byte  
3:25
di intero e poi ogni elemento di `a`. Allora, `a`  sarà i prossimi 4 byte. Non ci sono problemi di  
3:34
allineamento qui, perché siccome il tipo è `a`,  è allineato in maniera naturale. Pure questo è  
3:40
al multiplo di un indirizzo grande quanto il  tipo base, perché questo tipo base qua è 4  
3:45
byte e l'offset 0 è il primo elemento. Quel tipo  base è grande 1, quindi può andare dovunque senza  
3:53
padding. Quindi qua non ci sono spazi, non succede  niente di strano. Ora, di questo `a`, qua ci sarà  
3:58
`a[0]`, qua `a[1]`, qua `a[2]` e qua `a[3]`.  Quindi questi due elementi sono sequenziali.
4:05
Io ovviamente posso... io questa struttura  la chiamo `foo`. Quando non si sa nella  
4:14
programmazione come chiamare le cose perché sono  solo banali esempi, si possono chiamare `foo`,  
4:20
`bar`, `zap` o mnemonici del genere. `foo` non  significa niente. Quindi io poi dichiaro una  
4:28
variabile di tipo `struct foo` che chiamo `f`.  `f.i = 10`, `f.a`... qua inizializziamo `{1,  
4:38
2, 3, 4}` e poi io posso stampare, per esempio,  `f.i` e poi posso stampare `f.a[2]`. Vi ricordo  
4:49
che in questo caso `f.a` è il puntatore a dove  inizia l'array. Ma non è questo un puntatore  
5:00
materializzato, è solo calcolato dal C al momento  della compilazione prendendo `F` e aggiungendogli  
5:06
l'offset dove è memorizzato... i byte che servono  per saltare questo intero. E quindi `return 0`.
5:15
Compiliamo questo programma. Eh no, non credo  che si possa fare questa inizializzazione. Credo  
5:29
che in realtà l'unico modo in cui si possa fare  una roba del genere è se io inizializzo `f` in  
5:39
un'unica dichiarazione. Al di là di questo, credo  che anche questo sia un problema, cioè questa cosa  
5:45
si può fare solo durante la dichiarazione. Esatto.  Ci sono molti limiti nell'inizializzazione in C.  
5:53
In realtà, una cosa del genere non la farebbe  mai nessuno, cioè, fuori dagli esempi di questo  
5:58
tipo in cui tu devi, diciamo, riempire le cose di  valori nominali, questa roba qua non si usa mai.
6:09
Quindi, che cos'è che in realtà si  farebbe qui? Si farebbe `f.i = 10` e poi,  
6:21
praticamente, uno assegna i valori...  però, ripeto, sono valori sintetici,  
6:28
è strano. Uno farebbe `memcpy(&f.a, ...)` con,  non lo so, degli array dei 4 byte che prende da  
6:37
qualche parte in base a come funziona il  programma, e finirebbe per fare una cosa  
6:41
del genere. E infatti se facciamo così, e  magari mettiamo il punto e virgola... eh,  
6:50
però `memcpy` la dobbiamo dichiarare qui,  `string.h` fa parte. Eh, vedete, ora funziona.
7:01
Uno si potrebbe chiedere: "Perché `string.h` e  `memcpy`?". `memcpy` è una funzione che ha a che  
7:06
fare con la memoria, non è una funzione che opera  sulle stringhe, ma per ragioni storiche `string.h`  
7:12
ha una quantità enorme di funzioni che in realtà  sono necessarie per lavorare con i buffer o con la  
7:19
memoria in generale. Anche `memset` è allo stesso  modo definita dentro `string.h`, e così via.
7:32
Quindi, come vedete, io c'ho queste due variabili  sequenziali. Ma posso chiedere alla struttura  
7:45
di esibire un comportamento veramente strano a  pensarci, eh. Bene, se uno non proviene dal C,  
7:54
'sta roba qui è veramente aliena. Eppure  nel C si usa ogni momento. Guardate,  
8:01
facciamo una cosa. Io, dopo la struttura  qua, scrivo `union` e metto questi due campi.
8:11
A questo punto succede questa cosa: io sto  chiedendo al C che i miei campi della struttura  
8:16
`f`, `i` e `a`, debbano iniziare allo stesso  offset. Prima `i` iniziava a offset 0 della  
8:24
struttura e `a` era 4 byte dopo. Ora iniziano  tutti e due all'offset 0, perché questa unione  
8:32
è il primo campo della struttura, quindi ad  offset 0. Io qua fuori dall'unione potrei  
8:36
avere un'altra variabile, quindi sarebbero tutti  e due a offset 4, ma in questo caso ci sono solo  
8:43
loro due e sono ad offset zero. Significa che  questi due campi condividono l'indirizzo di  
8:50
memoria al quale sono registrati. Cioè, se io  scrivo in `i` sovrascrivo anche l'array `a`,  
8:57
o se io scrivo nell'array `a` sovrascrivo  `i`. Può sembrare molto strano, lo capisco.
9:05
Allora, per iniziare, andiamo a vedere che  succede. Non inizializziamo più l'array. Guardate,  
9:11
quando io setto... e stavolta facciamoci  stampare tutti i campi dell'array `a`:  
9:18
`f.a[0]`, `f.a[1]`, `f.a[2]`,  `f.a[3]`, per vedere che c'è dentro.  
9:33
Qua ci va il punto. Esatto. Allora,  guardate: siccome io ho settato nell'intero  
9:43
`i` il valore 10, e siccome questo computer è  Little Endian (quindi i byte meno significativi  
9:50
sono registrati per primi), significa che  il primo byte ha lo stesso valore di 10 e  
9:56
gli altri sono settati a zero. Quindi io mi sto  beccando qui la rappresentazione a byte di 10.
10:06
Mettiamogli un numero più grande,  per esempio, mettiamogli `INT_MAX`.  
10:13
Forse dovrei includere `limits.h`. `INT_MAX` è  una macro settata all'intero più grande possibile.  
10:25
Guardate ora qual è la rappresentazione  dell'intero più grande possibile: 255,  
10:32
255, 255, 127. Perché ovviamente l'altra parte  oltre il byte più significativo è la metà,  
10:43
perché poi ci sono tutti gli altri valori  che rappresentano i valori negativi. Infatti,  
10:49
se io qua gli scrivo `INT_MIN`, stavolta,  esattamente al contrario, l'avrò... questo è il  
11:01
modo in cui sono rappresentati i numeri negativi  in C, complemento a due. E praticamente, vedete,  
11:09
qua per la prima volta c'è veramente 128.  Ora vi faccio vedere un'altra cosa ancora.  
11:14
Se invece io voglio vedere tutti i byte al valore  massimo, lo setto a -1. E stavolta sono tutti 255.
11:22
Quindi, praticamente, io qua c'ho una cosa  veramente strana: è la sovrapposizione di due  
11:28
variabili assieme. Uno si potrebbe giustamente  chiedere: "Ma 'sta roba qua a cosa serve?".  
11:36
In realtà, prima di dirvi a cosa serve questo  costrutto, e prenderò un esempio reale di codice  
11:43
che ho scritto pochi mesi fa, peraltro, vi dico  subito che questa `union`, per come è scritta qui,  
11:50
prima del C99 non si poteva scrivere, se non  mi sbaglio, perché questa è una union anonima.  
11:55
In teoria, le `union` dovrebbero avere un nome,  quindi io dovrei scrivere per esempio `union  
12:01
bla_bla_bla` e dargli un nome `u`. E quindi poi  per accedervi `f.u.i` e tutto così, `f.u.a`.
12:18
Vedete? Però è molto diffuso il caso  in cui io voglio che la mia unione sia  
12:32
assolutamente trasparente, cioè che non  si veda in nessun modo che gli elementi  
12:37
sono uniti. Ma io lo so per i fatti miei. Tra  l'altro, semanticamente non aggiunge niente,  
12:43
perché questo `u` potrebbe essere anche una  struttura se io do un nome alla `union`.  
12:47
A me interessa più che altro, con le unioni,  che diversi oggetti siano sovraimpressi nello  
12:54
stesso spazio di memoria. E vi  faccio vedere per quale motivo.
13:00
Questo è il codice che ho scritto pochi mesi fa,  sono i vector set di Redis. C'è la possibilità,  
13:07
quando si fa la ricerca vettoriale, di  filtrare in base a un'espressione come  
13:12
quella che scrivete dentro le `if`,  per capirci. Questo è un esempio di  
13:19
come funzionano queste espressioni. Per  esempio, io posso scrivere `10 > 50`,  
13:27
result: false. `10 < 50`, result: true.  E qui venivano supportate anche le liste,  
13:37
ha diverse funzioni, tipo `10 in (1, 5, 3, 8)`,  false. Ma se dentro la lista c'è davvero 10,  
13:47
true. Vedete? Questo qui è in pratica una  specie di piccolo Domain Specific Language,  
13:52
è un linguaggio di programmazione in miniatura  che serve per queste espressioni qua di Redis.
13:58
Ogni token di queste espressioni, perché poi  'sta roba qui funziona pure con le stringhe  
14:05
(posso scrivere per esempio, usiamo i  singoli apici, `'foo' == 'bar'`, false,  
14:13
ma `'foo' == 'foo'`, true), questo  piccolo linguaggio di programmazione  
14:21
ha diversi tipi. E questi tipi di dati sono  rappresentati da questa struttura `ExprToken`,  
14:29
il token dell'espressione. C'è il `ref_count` che  noi abbiamo incontrato, ma crucialmente c'è il  
14:37
tipo del token, ma anche l'offset dove appare  nell'espressione. Questo è molto importante,  
14:42
l'offset in cui appare nella dichiarazione  dell'espressione, quindi nel sorgente del  
14:46
programma, perché se io c'ho un syntax error  voglio riuscire a dire: "L'errore è accaduto  
14:52
al carattere 50", quindi lo mostro poi con un  apice, come quando compilate e c'è un errore.
14:59
Poi qui però c'è la `union`, perché in base a  questo `token_type`, cioè se il `token_type` è  
15:09
`EXPR_TOKEN_NUMBER`, io voglio usare solo questo  campo qui. Se invece ho una stringa, voglio usare  
15:20
questa struttura `str` con l'inizio della stringa,  la lunghezza, se è allocata nell'heap o no,  
15:27
eccetera. Se è un `op_code`, voglio usare solo  questo intero `op_code` che mi dica il numero.  
15:32
Perché questo è utile? Perché io potevo, cioè,  volendo potrei rimuovere questa `union` e tutto  
15:37
funzionerebbe uguale. Ma ogni volta che io  dichiaro una struttura di tipo `ExprToken`,  
15:43
io vado a pagare la somma delle dimensioni di  memoria di questa struttura. La sua dimensione  
15:50
sarà la somma di questo campo, più  questa struttura, più l'op_code.
15:56
Ma io non le uso mai simultaneamente, perché un  token può essere solo di un tipo specifico alla  
16:04
volta. E quindi sarebbe uno spreco bestiale  di memoria. Questo è l'uso più ovvio,  
16:10
ma come vi ho fatto vedere, a volte ci sono anche  degli usi interessanti. In questo caso, io posso  
16:15
vedere per esempio la rappresentazione dei byte.  Lo avrei potuto fare in maniera diversa, questa  
16:21
stessa cosa, dichiarando un puntatore `unsigned  char*` e facendolo puntare dove c'è `i`, e quindi  
16:27
poi posso comunque accedere con i puntatori. In  C puoi fare quello che ti pare, per cui si può  
16:35
fare tutto in tutti i modi. Però, ecco, questo è  un modo elegante anche per esplorare all'interno  
16:42
delle rappresentazioni dei dati e così via. Ma in  assoluto, la cosa più interessante è quella là.
16:50
Altra cosa che ci fa salvare memoria è questa: i  bitfield. Quindi, `struct foo { int a:4; int b:4;  
17:05
int c:8; };`. Allora, in tutto questi campi  occupano soltanto 2 byte. Andiamo a vedere se  
17:15
è vero. `printf("%zu\n", sizeof(f));`.  Voglio vedere quant'è la dimensione di  
17:36
questa variabile `f` di tipo `struct foo`  e la faccio stampare dalla mia `printf`.
17:40
Quattro. Perché quattro? Ah, perché c'è il  padding, giusto. Però se io qua aggiungessi...  
17:54
vi faccio vedere, eh, perché conta il tipo base.  Allora, se io qua invece di scrivere `int` scrivo  
18:04
`unsigned char`, `unsigned char` e `unsigned  char`, quindi ho sempre gli stessi campi,  
18:17
ho cambiato solo il tipo base, a questo  punto in effetti è 2 byte la mia struttura.
18:26
Allora, guardate che ho fatto. Io gli sto dicendo  questo intero di quanti bit deve essere. Cioè,  
18:32
è veramente una roba di basso livello questa che  il C ci offre. Quindi voglio un intero di 4 bit,  
18:38
un altro intero di 4 bit. Un intero di 4 bit che  numero può memorizzare? Da 0 a 15 (2^4 - 1). E  
18:48
questo qui da 0 a 255. Ora guardate: `%d %d  %d`. Facciamoci stampare `f.a`, `f.b`, `f.c`.  
19:04
Eh, non li ho inizializzati in nessun  modo, scusatemi. `f.a = 1`, `f.b = 2`,  
19:10
`f.c = 3`. Funziona tutto perfettamente. Ma se io  a questo qui ci assegno 16, mi dice che ci sarà un  
19:26
troncamento del valore di inizializzazione e io mi  becco zero, perché è immediatamente oltre. Cioè,  
19:34
il 16 mi setta solo il quinto bit. Qua ce ne sono  quattro, quindi evidentemente sono tutti a zero.  
19:41
17 segnerebbe il quinto bit che qui non c'è,  ma segnerebbe anche il bit meno significativo,  
19:46
quindi qua io mi ritrovo uno. Esatto. Ora  mi ritrovo uno invece che zero, e così via.
19:53
Siccome questi sono `unsigned`,  allora in C c'è una regola:  
19:57
incrementare un tipo senza segno (`unsigned`)  oltre la sua dimensione massima avrà come  
20:11
risultato che poi ritorna a zero. Il "wrapping  around", diciamo, è come fare l'operazione di  
20:16
modulo della stessa dimensione, quindi il resto  della divisione. Invece se il tipo è `signed`,  
20:24
l'operazione è `undefined behavior`, non è  definito quello che accade. Se fosse `char` non è  
20:30
più definito. Stateci attenti, perché questa è una  rogna assurda. Si è andati oltre, secondo me, con  
20:42
l'undefined behavior. Alcune cose, al costo di un  po' di performance, avrebbero dovuto normalizzarle  
20:50
per creare un linguaggio più sicuro o meno pieno  di tranelli, al costo di un po' di capacità  
20:58
di ottimizzazione del compilatore. Ma questo,  comunque, è solo un'opinione, per cui insomma...
21:05
E perché fare una cosa del genere? Allora, ci  potrebbero essere due motivi. Uno è per salvare  
21:11
memoria, quindi lo stesso discorso delle `union`.  Io voglio praticamente utilizzare, so che questo  
21:16
tipo qui mi servirà solo di 4 bit. Questa roba  qui si usa in Redis e in tanti altri posti. Ne  
21:24
uso 4 bit perché poi io c'ho a volte centinaia di  migliaia o milioni di oggetti in base al dataset,  
21:34
eccetera, e io voglio utilizzare veramente  poca memoria. Un altro motivo per cui uno  
21:42
vorrebbe poter fare questa cosa è che ci sono  dei protocolli di rete o anche delle strutture  
21:52
dei file, un header, che c'è 4 bit è questo, 8  bit è quello. In realtà, questo è un modo scarso  
22:00
di gestire questa cosa, perché io potrei poi  leggere il contenuto del file dentro la struttura.  
22:05
Prendo l'appuntatore della struttura, gli leggo  dentro con `fread` (ve lo ricordate? L'abbiamo  
22:10
visto l'altra volta) questo pezzo di file e  poi me li trovo tutti i campi. In realtà no.
22:17
Perché purtroppo in C, e di nuovo la specifica  qui non ci aiuta, i bitfield sono poco standard  
22:25
e il modo in cui verranno registrati in  memoria, l'offset a cui saranno questi bit,  
22:32
varia non solo in base al fatto che l'ambiente  che uso sia Little Endian o Big Endian,  
22:38
ma può anche decidere, a un certo punto,  se ci sono dei tipi incompleti che non  
22:43
usano tutta la dimensione dell'intero... se io  dichiaro dei bitfield interi, eh. Ah, poco fa,  
22:50
tra l'altro, non c'era solo una questione di  allineamento: siccome io avevo usato `int`,  
22:58
comunque nel bitfield intero io poi devo  andare a usare tutto il mio intero. D'accordo?
23:06
Ora, ecco, nei casi in cui praticamente io c'ho un  tipo che non usa tutta la grandezza dell'intero,  
23:14
non ho nessuna garanzia se questo  è memorizzato alla fine o se mi  
23:19
viene splittato tra due interi diversi se vado  oltre, se qui c'è un tipo `d` che è, non lo so,  
23:26
24 e così via. Non ho garanzie, in sostanza, sul  modo in cui il C renderà questi interi piccoli  
23:38
nella memoria, nel layout della mia memoria.  Quindi, di fatto, si possono fare delle cose:  
23:48
controlli se il tuo sistema è Big Endian o Little  Endian e inverti a volte le definizioni quando  
23:53
necessario. Funziona quasi sempre questo trucco,  però ci possono essere problemi di compatibilità.  
23:58
In realtà, in quel caso è molto meglio  fare delle cose diverse: dichiarare un  
24:04
array di `unsigned char` e poi leggere i campi e  utilizzare le operazioni di shifting per estrarre  
24:11
i bit che mi interessano. È più laborioso,  però mi ritrovo con codice molto portatile.
24:16
Nonostante tutto, 'sta roba qui si usa molto per  due motivi. Perché a volte io, per dire, compilo  
24:22
un programma che gira sullo stesso computer,  c'è una pipe, mi scambia dei dati, quindi sono  
24:28
sicuro che comunque l'architettura è la stessa e  quindi posso usare un bitfield per rappresentare  
24:33
un header o varie cose. Ecco, per esempio, vediamo  `C struct IP protocol packet`. Per esempio, nel  
24:44
protocollo IP, vediamo se qua becco... ecco qui.  Ahah, beccato. Bellissimo, l'header del pacchetto  
24:59
IP. Eh, qua c'è praticamente `ip_hl`, header  length, ed è solo 4 bit, perché il protocollo IP  
25:08
può avere anche delle opzioni, quindi l'header può  avere una lunghezza che varia. Qua è la versione,  
25:16
qua abbiamo la lunghezza totale, l'ID, l'offset  se è un frammento di un pacchetto (perché l'IP  
25:23
supporta la frammentazione), Time To Live (perché  sennò il pacchetto può girare all'infinito,  
25:29
invece ogni router decrementa questo campo e  quando arriva a zero il pacchetto viene droppato),  
25:34
eccetera. Vabbè, non facciamo qua un  corso di networking, ma ci siamo capiti.
25:37
Ecco, in questi casi semplici, in cui ci sono 4  bit e 4 bit, non ci sono split attraverso interi,  
25:45
eccetera, ci sono abbastanza garanzie, per quanto  i bitfield siano progettati un po' a casaccio,  
25:50
nel senso che ci danno pochissime garanzie. Va  bene lo stesso, si può fare una cosa del genere,  
25:56
ma devi testare l'endianness. Ma abbiamo  detto che ormai tutte le macchine sono  
26:01
sostanzialmente Little Endian. Questa roba  qua è stata scritta nell'82 o '91, insomma,  
26:09
tanto tempo fa. Ehm, ora praticamente potremmo  anche, volendo con un po' di rischio (ma io  
26:15
sinceramente lo farei), droppare questo check  qui e semplicemente scrivere 'sta roba qua,  
26:23
e funzionerebbe in tutte le macchine. Certo,  poi se nel futuro i Big Endian hanno di nuovo  
26:29
una... ma di solito quando le cose vengono...  allora, prima c'erano queste due famiglie,  
26:35
poi quando... ed era un casino, dovevi  supportarle tutte e due. Poi quando  
26:39
si crea uno standard fortissimo, tipo la  rappresentazione numerica col complemento  
26:44
a due (prima non era che tutti i computer  avevano questo tipo di rappresentazione),  
26:50
oggi è impensabile fare una macchina che non  ce l'abbia. Io credo che convergeremo tutti sul  
26:56
Little Endian, non ci sarà nient'altro, quindi  io rischierei e scriverei semplicemente così.
27:01
Quindi questo è un esempio molto interessante di  bitfield, ma io ve ne vorrei far vedere un altro.  
27:09
Ecco, `redisObject`. Guardate: `type`,  `encoding`... questo, guardate, bitfield a un bit,  
27:19
quindi ha un booleano. `lru`, Last Recently  Used. Qua uso un po' di bit, quelli che restano,  
27:29
per farci altro. `refcount`. Ecco, Redis è un  esercizio di salvare il salvabile di memoria,  
27:38
di CPU, di ogni cosa possibile. Quindi qua,  ovviamente, figuratevi se non c'è 'sta roba  
27:42
qua. Qui il bitfield a noi ci dà problemi dal  punto di vista di compatibilità dell'endianness,  
27:46
Little Endian o Big Endian? No, perché 'sta  roba qui rimane solo in memoria. Non viene  
27:50
mai serializzato l'oggetto Redis in maniera  così cruda con una `write` su disco di quello  
28:00
che noi abbiamo in memoria. C'è sempre poi la  serializzazione in cui si usa un formato diverso,  
28:04
c'è un'astrazione dei file RDB o Append  Only File, e quindi il problema non esiste.
28:10
Bene. A questo punto io avrei voluto  trattare anche i puntatori a funzione,  
28:17
ma siccome siamo andati oltre il limite, ci  vedremo la prossima volta. E mentre fate un po'  
28:23
di esperimenti col bitfield e con le union, perché  sono assai interessanti e sono due cose che,  
28:29
come avete potuto vedere, dal '91 ad oggi sono  state utili e continueranno a essere utili.


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