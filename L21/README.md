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