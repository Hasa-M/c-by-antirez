Lesson 23 link: https://www.youtube.com/watch?v=vYODKK8TQGE&list=PLrEMgOSrS_3cFJpM2gdw8EGFyRBZOyAKY&index=26

Lesson 23 Transcript:
0:40
Bene, bene. A questo punto siamo in una fase  evoluta di questo corso di programmazione in C,  
0:45
nel senso che abbiamo esplorato una quantità di  concetti di questo linguaggio, dalle strutture ai  
0:53
puntatori a funzione, a come si usano i puntatori  per manipolare i dati in memoria, e così via, che  
1:01
possiamo dire di avere una quantità sufficiente di  strumenti per cimentarci a fare qualcosa di vero.
1:08
Perché noi potremmo continuare nell'esporre delle  funzionalità del C o della libreria standard,  
1:14
o potremmo addentrarci, come faremo prima  o poi, nelle chiamate di sistema POSIX,  
1:20
ma per imparare a usare il C davvero (e non  è una questione che è limitata solo a questo  
1:26
linguaggio di programmazione, ma per imparare a  programmare in maniera forte) bisogna capire come  
1:33
questi strumenti si mettono assieme quando  si deve realizzare qualcosa di non banale.
1:39
Una cosa non banale è un interprete  per un linguaggio di programmazione,   e il più semplice linguaggio di programmazione  che noi possiamo scrivere, a iniziare da  
1:47
questa lezione (non credo che finiremo in 20  minuti), è una versione giocattolo di Forth.
1:55
Forth è un linguaggio basato sullo stack.  Per esempio un programma Forth, o meglio,  
2:02
qui non utilizzeremo davvero la sintassi esatta  di Forth in tutti i casi, ma di questo ideale  
2:09
linguaggio di programmazione che noi vogliamo  scrivere. Però, per esempio, se io scrivo 5 5 + è  
2:15
un programma che somma il numero 5 col numero 5,  o potrei scrivere lo stesso programma come 5 DUP.
2:24
Andiamo a vedere cos'è che fanno questi  programmi e che cos'è un linguaggio di   programmazione basato sullo stack. Quindi  io faccio finta, questo è il programma uno  
2:33
e questo è il programma 2. Sono due programmi  diversi. Facciamo finta di essere l'interprete. Inizio dal programma 1. 5. Io ho una pila che si  chiama lo stack di valori. Quando incontro cinque,  
2:45
che è un valore letterale, io metto cinque  nello stack. Questo è il mio stack. Il mio  
2:52
stack ora contiene cinque. Poi, quindi questa  parola... allora, i linguaggi stack sono basati  
3:00
sull'idea di "parola", è una sequenza di parole,  quindi sostanzialmente il programma è una lista.
3:06
Vado alla seconda parola e c'è  di nuovo cinque. Siccome è sempre   un valore e non è una funzione, io  accodo di nuovo cinque al mio stack.
3:19
Finalmente trovo come terza parola del mio  programma una funzione. Siccome questa è una  
3:26
funzione, io invoco questa funzione, "+". Questa  funzione fa di prelevare i due valori sullo stack,  
3:34
che sono gli ultimi due che sono stati inseriti,  quindi i due valori in cima allo stack.  
3:42
Li somma, quindi li preleva (non ci sono  più, ma ci sono, diciamo, qua ora dentro  
3:48
il contesto della funzione "+"), li preleva,  li somma e questo è il risultato, e inserisce  
3:55
nello stack il valore risultato. Quindi il mio  stack varrà 10 alla fine di questo programma.
4:04
Andiamo ora ad eseguire, partendo con lo stack  vuoto, il programma numero due. Incontro 5 e,  
4:10
siccome è un valore, lo metto dentro lo stack.  Incontro stavolta direttamente una funzione:  
4:15
DUP. DUP fa questa cosa: preleva o, possiamo  dire che, o preleva dallo stack il valore più  
4:26
in cima (5) e lo inserisce due volte, o  potremmo dire che (è un'alternativa di  
4:34
implementazione) guarda che valore c'è  in cima allo stack e lo reinserisce.  
4:40
Comunque il risultato è di duplicare  l'ultimo valore in cima allo stack.
4:45
Quindi io c'ho qua 5 e 5, e poi quando incontro  "+" succede quello che succedeva prima. Prendo 5  
4:53
e 5, li sommo, li prelevo dello stack,  li sommo e metto 10 come risultato.
5:00
Un linguaggio stack-based fa esattamente  questo. Uno potrebbe chiedersi: "Ma come  
5:09
faccio poi ad andare oltre? Come faccio a  fare una if? Come faccio a fare un ciclo?  
5:17
E tutte queste cose?". Lo vedremo dopo,  però ve lo voglio accennare immediatamente.
5:23
Io ho visto che cinque è un valore. Può  essere anche un valore... per esempio,   un programma valido potrebbe essere "Hello World"  strlen. Questo programma avrà questo effetto:  
5:38
io prima incontro questo valore stringa, lo  metto sullo stack. Poi c'ho questa funzione  
5:45
strlen che prende il valore in cima  allo stack (la stringa) e lo preleva  
5:55
(quindi non c'è più). Guarda quanto è  lunga questa stringa: 1 2 3 4 5 6 7 8 9  
6:00
10 11. E mette sullo stack il valore 11. E  poi magari potevo avere anche una "print",  
6:07
e la print preleva dallo stack l'ultimo  valore e lo stampa a video. Quindi il  
6:14
risultato sarebbe stato di avere 11 stampato a  video. Quindi questo è l'output del programma.
6:24
Ora, visto che i diversi valori  possono essere non solo numerici,  
6:30
perché io non potrei avere come valore  un sottoprogramma? Abbiamo detto che  
6:37
un programma alla fine in questo  tipo di linguaggio è una lista, OK? Quindi io posso fare, per esempio, che... [ DUP  * ]. Quindi sostanzialmente questo programma qui  
6:49
farebbe l'elevazione al quadrato del numero che  c'è in cima allo stack, perché DUP lo duplica   e * fa l'uno per l'altro, e siccome i due valori  sono uguali è x * x, quindi eleva al quadrato.
7:02
Ma io posso fare invece anche DUP.  Quindi questi sono due sottoprogrammi,   e questa è il ramo vero della if.  Questo è il ramo falso della if. E  
7:12
qua ci metto un'espressione che è quella  che deve essere verificata. Per esempio,   "se 10 è 20", if. Qua a questo punto  è anche questo un sottoprogramma.
7:27
Eh no, scusate, ho sbagliato.  Ecco, così. In sostanza quello   che succede... guardate in questo programma  che cosa succede, com'è implementata la if.
7:39
Quindi c'ho questo stack. Incontro un primo  valore. Questo è un valore che è una lista che,  
7:45
guarda caso, rappresenta un programma, e  lo metto nel mio stack. Incontro il secondo  
7:50
valore e lo metto nel mio stack. Incontro  il terzo valore... però questo qui, scusate,  
7:57
dovevo scriverlo così, perché l'operatore  qua va sempre a destra. Prima devo fare il  
8:03
push nello stack dei miei valori e poi c'è  la mia funzione che opera sui valori. OK?  
8:08
Comunque questo significa "10 20 <". Bisogna  un po' abituarsi alla sintassi, lo capisco.
8:15
Quindi metto anche questa lista, che però  rappresenta un programma, nel mio stack.  
8:20
Quando poi viene chiamata la IF, alla fine la IF  non fa che prelevare tutta 'sta roba dallo stack.  
8:27
Prima esegue questo sottoprogramma qui, il  terzo. Quindi tutti e tre gli argomenti della  
8:33
if devono essere liste di questo nostro  linguaggio di programmazione valide.
8:39
Lo esegue. Quindi 10 < 20? Sì. Quindi  restituisce "true" nello stack.  
8:47
Vabbè, neanche ci passa allo  stack, semplicemente guarda se   quell'espressione ritorna un valore vero.  O meglio, siccome esegue il programma,  
8:58
va a finire effettivamente nello stack, perché  sta eseguendo un programma e quindi noi abbiamo  
9:04
uno stack unico e globale in questo linguaggio  di programmazione, e quindi qua diventa "true".
9:09
Poi preleva dallo stack questo valore, lo osserva:  se è vero, esegue il primo sottoprogramma che ha  
9:19
prelevato; se è falso, esegue il secondo  sottoprogramma. In questo caso è true,   quindi... vabbè, facciamo finta  che prima lo stack aveva qua 20,  
9:27
prima ancora di esserci quel "true" che avevamo  inserito. Quindi esegue questo sottoprogramma,   duplica il valore, lo moltiplica, e  quindi 20 * 20... 2 * 2 = 4... fa 400.  
9:40
E qui lo stack avrà solo 400. Quindi si  possono implementare anche le condizionali.
9:48
Voi direte: "Caspita, ma è strana  una condizionale scritta così?".   Però poi ci aiuta il fatto di scriverla così.
9:59
Magari questi qua si possono anche indentare così: [ ... ]  [ ... ] 10 20 < 
10:05
if  OK? Quindi, praticamente, l'indentazione  funzionerebbe in questo caso esattamente  
10:11
al contrario. Sono dei linguaggi che  hanno una logica, diciamo, diversa.
10:18
In realtà, per rendere questo programma più  leggibile, è meglio se la condizione è il   primo argomento. In questo modo il programma  diventa più leggibile, perché diventa così:  
10:34
[condizione] [questo] o [questo] if. Mi sembra  un modo più interessante di strutturarlo.
10:43
E poi inoltre è anche vero che questo  qui si dovrebbe chiamare "if else",   perché "if" sarebbe la forma più compatta,  in cui io posso fare [condizione] [...] if.  
10:54
Quindi questa operazione viene svolta solo  se in effetti questo programma qui è vero.
11:01
Bene, come si fa a fare tutta 'sta roba qui?   Dobbiamo usare ovviamente le strutture per  rappresentare i nostri oggetti, dobbiamo  
11:09
usare i puntatori per fare il parsing di questo  programma, dobbiamo usare i puntatori a funzione  
11:14
(probabilmente, ora vedremo) per modellare  comunque i diversi tipi di comandi che, diciamo,  
11:23
di funzioni che questo nostro linguaggio  di programmazione accetta, e così via.  
11:28
Questo mi sembra comunque veramente mettere  assieme tanta della roba che noi c'eravamo detti.
11:35
La prima cosa da fare quando si  scrive... Allora, questo qui,   siccome sono tutti derivati dal Forth,  chiamiamolo ToyForth. Quando si crea un  
11:46
programma di una certa complessità,  è bene partire dalle strutture dati. Quindi io avrò una rappresentazione degli  oggetti di questo linguaggio di programmazione,  
11:55
la posso chiamare struct... TF o ToyForthObject. E avrà questo ToyObject un "type", perché può  
12:11
essere un intero, una stringa... una...  può essere tante cose che ora vedremo.
12:19
Beh, qua definiamo: TF_OBJECT_TYPE_INT 0 
12:26
TF_OBJECT_TYPE_STR 1 Qua si potevano usare  
12:32
delle enum, che noi non abbiamo ancora trattato,  ma comunque è equivalente, non è questo il punto.  
12:38
Il punto è capire come si mettono assieme le  cose ad alto livello, dal basso all'alto livello.
12:43
...STR... LIST... anzi prima i booleani,  perché poi abbiamo le comparazioni per fare  
12:54
appunto cicli if, cicli for e tutte  le cose qua che ci possono servire. 
13:03
Forse che poi la lista comunque è anche il  tipo nativo del linguaggio, quando si vuole,  
13:09
diciamo, appunto, programmare. Che poi la lista è, tra l'altro,  
13:17
la stessa rappresentazione che si usa per  i programmi stessi in questo ToyForth.
13:22
Dopodiché qui dobbiamo usare una union, le nostre  union anonime di cui avevamo parlato. Allora,  
13:30
in base al tipo, ovviamente qui  vogliamo un "i" intero... o meglio,  
13:37
forse qui facciamo una cosa. Allora,  int... in realtà ci servirebbero, vabbè,   anche tipi di floating point, ma ci incasiniamo  troppo. Per ora facciamo le cose semplici.
13:48
Poi la stringa sarebbe struct  str. Qua ci vuole un char *ptr,  
14:01
size_t len, perché la nostra stringa deve avere un  puntatore, dobbiamo sapere anche quanto è lunga,  
14:08
e così non abbiamo neanche da crearci problemi  con la null termination eccetera eccetera.
14:15
Poi il booleano, vabbè, lo mettiamo sempre qui,  che poi alla fine è "i", cioè potremmo usare  
14:23
per i booleani potremmo usare benissimo  "i" e forzarlo a essere true o false.
14:29
E invece la lista è la cosa un po' più complicata.  Sostanzialmente è struct tfobj... Allora,  
14:38
struct... ed è un puntatore a un puntatore di...  e la chiamo elements, "ele", e poi size_t len. 
14:55
Allora, qui perché ho fatto questa cosa  qua? Perché qui noi finiremo per avere   questa lista che è un array di puntatori  ad oggetti tfobj, perché ci vanno dentro  
15:07
'sta lista altri oggetti dello stesso  tipo, quindi è una definizione ricorsiva. 
15:14
E quindi il mio array è un puntatore  a dei puntatori di tipo struct tfobj,  
15:24
quindi qua ci vogliono due asterischi e non uno. Questo significa che se io scrivo, per dire,  
15:31
ele[0]... devo togliere un asterisco e quindi mi  ritrovo un puntatore a quell'elemento, d'accordo? 
15:43
E quindi poi lo posso manipolare. Quindi voi  pensate sempre che quando dereferenziate il   puntatore con le parentesi quadre, togliete  un asterisco di qua e quello che vi resta è  
15:52
appunto un puntatore a un oggetto che  poi potete utilizzare come volete.  Quindi qua di solito quello che faremo è:  quando abbiamo una lista, noi avremo un ciclo  
16:01
for e faremo ele[0], ele[1], ele[2], ele[3]... e  avremo tutti i puntatori degli oggetti contenuti.
16:11
Mi sa che per semplificarci la vita  qui ci mettiamo pure un int refcount.  
16:16
Usiamo il reference counting in questo  piccolo linguaggio di programmazione,  
16:22
perché così ci togliamo dalle scatole  una quantità bestiale di cose.
16:29
In realtà noi possiamo usare addirittura...  perché ci servono stack. Avete visto che noi  
16:35
abbiamo gli stack in questo linguaggio,  e lo stack è una cosa fondamentale,   lo stack globale dove i valori vengono inseriti  e tolti. Ma tutto sommato noi possiamo usare la  
16:46
lista come stack, perché questa lista è un array  di elementi. Noi possiamo accodare elementi,   possiamo prenderli dalla fine e toglierli,  insomma, possiamo fare tutto quello che  
16:55
ci serve con la lista. Quindi questa cosa qui  effettivamente la riusciamo a scavalcare così.
17:01
Ci serve anche un'altra cosa. Poi abbiamo  la necessità di avere una funzione che,  
17:07
dato un programma tipo "5 5 DUP" che è una  stringa in C, sostanzialmente, che ci arriva  
17:14
da qualche parte (la leggiamo dal file, ce  la scrive l'utente in modalità interattiva,  
17:20
quel che volete), deve trasformare  questa stringa in un oggetto tfobj.
17:30
Tra l'altro qua facciamo una cosa:   typedef struct tfobj tfobj. Così che noi non  dobbiamo scrivere ogni volta struct tfobj,  
17:43
ma possiamo scrivere tfobj e basta, visto  che lo scriveremo un miliardo di volte.
17:49
Però dicevo, a noi ci serve poi una funzione che,  
17:55
data la stringa del programma, ci ritorna in  realtà un oggetto tfobj che lo ha tokenizzato,  
18:03
lo ha tagliato in parti. Tipo le parti  qui quali sono? Sono il 5, il 5 e DUP.
18:09
Però dobbiamo sapere che... Ah, attenzione però:  questo qui, DUP, è una cosa diversa da tutti  
18:19
'sti tipi qui. È sostanzialmente un simbolo. Si  chiama, diciamo, nel linguaggio di programmazione,  
18:24
negli interpreti, di solito, una cosa che non è  nessun tipo letterale, ma che comunque è... cioè,  
18:32
o meglio, noi chiamiamo questa roba qui, questo  tipo di dato qui che non è tra virgolette ed è  
18:38
una parola singola, non ha caratteri speciali  (o meglio, alcuni caratteri speciali li ha,   perché i simboli possono essere pure "+",  eccetera eccetera). Lo chiamiamo simbolo. 
18:46
Così sappiamo che quando troviamo un simbolo,  noi vogliamo eseguire quel simbolo e non   metterlo dentro lo stack. Eseguendo questo  simbolo, sarà effettivamente associato (poi  
18:56
ci sarà una tabella) che collega il nome  del simbolo alla funzione da chiamare.  Quindi io qua ho bisogno di:  #define TFOBJ_TYPE_SYMBOL 4.
19:12
Allora, qua type... gli mettiamo TFOBJ_TYPE_* per  fare capire che queste define poi sono i valori  
19:21
che prende 'sta roba qui, il type. Qua c'è int i. Facciamo una cosa:  
19:30
noi per il simbolo utilizzeremo  sostanzialmente questo qui, la stringa,   quindi non dobbiamo definire un'altra struttura  perché è questa, no? Puntatore e lunghezza.
19:41
Allora, per fare il parsing, organizzare  questa cosa e trasformarla poi alla fine   in una struttura, a noi ci serve  una struct. Allora, sempre facciamo:  
19:50
typedef struct ToyForthParser TFParser. 
20:05
Allora, per fare il parsing  a noi che ci serve? Ci serve:  char *prg; // to compile into a list char *p; // next token to parse.
20:28
Così noi ci portiamo avanti questo oggetto qui,  ce lo passiamo in giro per le nostre funzioni  
20:34
di parsing e abbiamo sempre l'inizio della stringa  che rappresenta il programma e, in questo caso, ci  
20:39
accontentiamo benissimo che sia terminato da NULL,  perché comunque dentro il nostro programma un byte  
20:45
a zero non si può avere, quindi ci sta benissimo  che le cose vadano così senza complicarci  
20:52
la vita con lunghezze e cose del genere. E qua invece char *p, next token to parse,  
21:02
dov'è che siamo arrivati col parsing. Quindi  noi questo qui praticamente all'inizio coincide  
21:07
con "prg", poi man mano che facciamo il  parsing andiamo avanti e così via. OK?
21:13
int main(int argc, char **argv) Dovremmo leggere praticamente un  
21:23
programma da un file. Guarda, all'inizio  facciamo una cosa, facciamola più facile:  
21:31
usiamo la funzione... cioè leggiamo una riga  praticamente direttamente dallo standard  
21:38
input. Cioè noi avviamo il nostro linguaggio di  programmazione, la gente ci scrive praticamente   con un piccolo prompt il programma, preme invio e  il programma viene eseguito, perché così il ciclo  
21:47
di sviluppo è più veloce. O forse ci incasiniamo  che ogni volta dobbiamo ripetere 'ste cose.
21:53
Guarda, facciamo una cosa. Invece diamo int  argc, char **argv. Così a noi ci arriva un  
22:02
array di stringhe che sono quelle date nella  linea di comando dal C. E quanti ne abbiamo? 
22:09
Primo... allora, quando già solo per il fatto  che io ho eseguito il programma, guardate,  
22:17
argv[0] è sempre il nome del mio programma  e argc è 1, quindi non può essere mai 0.
22:25
Compiliamo 'sto programma che non  funziona niente. Allora, prima di tutto: 
22:35
#include Ed è 1. 
22:42
#include
22:50
Eh, struct... str... qua "str" andava qui e  anche qui, che non è il nome della struttura,  
23:02
che la struttura qua nomi non ne ha.  In questo caso è proprio direttamente   la definizione di un membro. Noi non la  stiamo chiamando in nessun modo questa  
23:10
struttura perché ci serve solo una volta e  quindi non la chiameremo più. str... list...
23:18
First parameter of main... Scusate, qua  ho invertito stupidamente queste due cose.
23:29
Esatto. Guardate, quando io eseguo questo  programma, vedete, il nome del programma   è il primo argomento che viene passato al  programma stesso. Questo è utile perché a  
23:39
volte ci sono dei programmi che sono lo stesso  binario, ma in base a come vengono chiamati,  
23:44
cioè se lo chiami tipo "ls", fa una cosa, se  lo chiami con un altro nome fa un'altra cosa.  
23:50
In Unix è molto molto facile che accada ciò.  ls -l /usr/bin... Vediamo se qua ne trovo qualcuno  che è un link simbolico. wish... vi... view... 
24:04
Ecco, guardate, per esempio, se io controllo  dentro i binari qua di MacOS, guardate,  
24:12
ci sono diversi link simbolici. Per esempio, "vi"  è linkato a "vim", ma a volte può capitare che se  
24:22
il vim è chiamato tramite il suo link simbolico  "vi", e lui se ne accorge che il primo argomento è  
24:27
effettivamente "vi" e non "vim", cambia alcuni  comportamenti per avere una compatibilità  
24:33
più stretta con "vi". Non so se succeda, è  molto probabile che ciò accada, e così via. 
24:38
Quindi, comunque, questa cosa  è utile da sapere. Scusate.
24:46
ToyForth. Allora, facciamo una cosa. Noi vogliamo, tanto per iniziare,  
24:56
che... quindi if argc != 2 (che io c'ho  il nome del mio programma ToyForth e il  
25:07
file che voglio eseguire), diamo errore. fprintf... stderr... fprintf. E allora,  
25:14
fprintf è come la printf, ma ha un primo argomento  che gli specifica un oggetto FILE* dove puoi  
25:22
scrivere, e l'oggetto FILE* stderr, definito  direttamente dalla libreria standard, significa  
25:29
che voglio scrivere nello standard error. È sempre il terminale, ma il terminale ha   due canali, uno per l'output normale e uno  per lo standard error. In questo modo puoi  
25:38
praticamente catturare l'output di un programma  senza farti catturare gli errori, o viceversa. 
25:44
Quindi questa è una cosa utile e noi qua scriviamo  correttamente uno standard error come dovremmo: 
25:53
"Usage: %s filename\n", argv[0] ...così gli spieghiamo com'è che  
26:07
lo deve usare all'utente, che non  passa esattamente due argomenti. 
26:12
return 1. E ritorniamo un errore. Se ora compilo io 'sto robo qui, se lo  eseguo così mi dà errore. Se lo eseguo  
26:19
con un argomento non mi dà più errore. Il che bene... ciò che voglio fare è anche  
26:28
di caricare questo programma da qualche parte in  memoria, in un buffer, così poi posso chiamare la  
26:36
mia... boh, credo che si chiamerà compile. Quindi tfobj *prg = compile(prgtext),  
26:46
il testo del programma. E poi farò qualcosa come exec o  
26:53
eval... no, eval sarebbe, diciamo, l'unione  di compile ed exec. No, facciamo exec(prg).
27:02
Anzi, prima devo creare un contesto di  esecuzione. Esatto. Ci manca una struttura qua,  
27:11
perché noi qui abbiamo il parser, ma ci  serve una struttura che faccia da contesto,  
27:22
perché io voglio poter utilizzare più  interpreti nello stesso momento di ToyForth,  
27:27
e ognuno avrà il suo stack e ognuno avrà, non lo  so, quelle altre informazioni che possono servire.
27:33
Quindi typedef struct tfctx... questo è  il mio contesto di esecuzione... tfctx. 
27:42
E cos'è che avrà il mio contesto  di esecuzione? Avrà: tfobj *stack.  
27:49
Questo è lo stack principale. E poi avrà...  ce lo teniamo un riferimento al programma  
27:56
che stiamo eseguendo? Ma questa cosa la  vedremo dopo. Questa cosa la vedremo dopo,  
28:03
se vogliamo farlo o meno.  Però avremo il nostro compile.
28:10
Allora, ci serve anche un'altra cosa prima di  poter continuare. Siccome il nostro stack di  
28:15
fatto è un oggetto, un oggetto di tipo tfobj, ci  serve in realtà anche una funzione che ci crea un  
28:26
oggetto nuovo di ognuno di questi tipi. OK? Perché  io devo poter creare effettivamente un oggetto  
28:35
stack, devo poter creare un oggetto intero, devo  poter creare un oggetto del tipo che mi pare.
28:43
Quindi facciamo questa funzione qua. Allora,  
28:49
quindi queste sono le strutture.  Quindi qua facciamo un po' di   object... object related functions. E queste sono le mie data structures. 
29:13
Separiamo un po'. Qua vedo  un... OK, li avevo fatti giusti. 
29:26
Vabbè, questo è niente qua. Ma...  un po' di artigianato del software.
29:40
Allora, a me serve tfobj *createObject(int type). // Allocate and initialize a new Toy Forth object.
30:11
Una cosa molto importante: qua ce ne  fregheremo di gestire gli out of memory,  
30:19
però faremo una cosa, poi dobbiamo usare dei  wrapper. Allora, iniziamo subito a fare questa  
30:25
cosa qui. Ora ve lo faccio vedere. Allora, in questo caso io farò:  tfobj *o = malloc(sizeof(tfobj)); o->type = type; (che è l'unica cosa  
30:41
che mi passa qua il convento) o->refcount = 1; (quindi no,  
30:46
il conto referenze parte a uno perché lo sto  ritornando e qualcuno lo assegnerà da qualche  
30:52
parte a una variabile. Per cui effettivamente  io qui parto col reference counting settato).
30:59
Però siccome poi ho il problema che dovrei  cercare sempre di controllare se malloc  
31:05
eccetera eccetera, ma io in realtà  voglio quittare con "out of memory",   quindi lo chiamo xmalloc. E qua  faccio: Allocation wrappers. 
31:25
E scrivo, guardate, mi vado a prendere  il prototipo della malloc, che va bene.  
31:34
Semplicissimo, ma il punto è che io voglio  che la mia xmalloc sia esattamente uguale,  
31:41
solo che farà questa cosa qua: void *ptr = malloc(size); 
31:47
Esattamente. Noi chiamiamo la  malloc. Se il puntatore è NULL: 
31:53
fprintf(stderr, "Out of memory  allocating %zu bytes\n", size); 
32:08
exit(1); La exit è una chiamata di sistema definita   in unistd.h. Quindi andiamo a mettere questa cosa  qua. Altrimenti ritorniamo il nostro puntatore.
32:22
Allora, questa è una versione di malloc  che semplicemente va in panico quando non  
32:31
c'è abbastanza memoria. Poi noi avremo pure  realloc, che mi sa che non ho mai spiegato,   ma la useremo molto all'interno di  questo programma e la devo spiegare. Sì.
32:43
Allora, faccio una precisazione.  Siccome io questo programma qui che   sto scrivendo non me l'ero preparato,  perché sennò non c'è bello, è finito,  
32:50
diciamo, la parte di apprendimento di  tutte 'ste robe qui. Perché se non vado   in difficoltà io stesso nel pensare a come  devo fare le cose, il valore didattico di  
33:01
questa lezione sarebbe veramente basso.  Quindi non è detto che noi finiremo per   usare veramente le strutture nelle prossime  lezioni che io qua sto definendo. Si vedrà.
33:11
Però ora c'abbiamo createObject e quello  che possiamo fare è che poi comunque  
33:17
dobbiamo avere altre funzioni. Per esempio: createStringObject(char *s, size_t len). 
33:28
Anzi qua, invece di "pointer" chiamiamo "s"  perché è la stringa. E questa funzione qui farà: 
33:35
tfobj *o = createObject(TFOBJ_TYPE_STR); Come si chiama? ptr, sì. 
33:57
o->str.ptr = s; o->str.len = len; 
34:03
Allora, qua stiamo andando a settare noi,  visto che la nostra struttura ha questa   union e ognuno di questi elementi della union  sarà utilizzato da un tipo diverso. Il tipo  
34:13
stringa utilizza ovviamente questo "str" qui,  questa struttura dove viene settato l'inizio  
34:20
della stringa, il puntatore dove inizia  la stringa, e la lunghezza della stringa.
34:27
E fin qui mi pare che ci  siamo. Poi a me mi serve pure:  tfobj *createIntObject(int i). E qui quello che farò è... vabbè,  
34:43
questo me lo copio. Poi siccome... ah,   qua return o. E anche qua return o. Se  non lo ritorno non ho fatto un bel niente. 
34:53
Qui il tipo è intero. Qui quello  che setto è o->i = i. Return o.
35:08
Facciamo a questo punto tutti gli altri.  Quindi qua abbiamo string, il booleano,  
35:16
che praticamente è uguale all'intero, né più  e né meno, però lo dobbiamo creare lo stesso,  
35:28
perché cambia questo, il tipo,  e ciò è molto importante. 
35:38
Il simbolo pure, che è praticamente  identico all'oggetto stringa.
35:46
Qui possiamo fare una cosa: tfobj *createSymbolObject(char *s, size_t len). 
35:59
Potrebbe avere senso qua fare: tfobj *o = createStringObject(s, len); 
36:05
perché sono uguali. È l'unica cosa  che cambia: il tipo. E qui il tipo   lo settiamo a TFOBJ_TYPE_SYMBOL. Scusate. Esatto. Questo è un trucco per non ripetere la logica e il  
36:18
codice. Se poi domani cambieremo ptr e len qui,  non lo dobbiamo cambiare anche per il simbolo.
36:25
Qui in teoria noi dovremmo mettere anche  dei commenti, però siccome qua è troppo   ovvio effettivamente quello che sta succedendo in  queste funzioni, neanche lo mettiamo qua. Quello  
36:35
che dovrei... io quello che farei in questo  caso è mettere qui un commento in cui dico: 
36:43
"The following functions allocate Toy  Forth objects of different types." 
36:57
Scriviamo così. Poi magari questa  roba qui si potrà estendere,   però finora è troppo semplice  per mettere altri commenti.
37:07
E poi che abbiamo? La mia lista. Sì, la mia lista. createListObject(). 
37:20
Di tipo lista. E qua ci siamo. o->list. (L'ho chiamato 'ele'.) 
37:31
o->list.ele = NULL; (perché all'inizio è vuota) o->list.len = 0; (perché all'inizio è vuota) 
37:43
Return o. Vediamo se compila ancora 'sto robo. Figurarsi. Perché ho scritto ciò? OK. 
38:03
refcount... No member refcount. Ci manca una 'n'. Compiliamo. 
38:12
Non-void function non ritorna una fava... return o. 
38:21
Compiliamo. Eh vabbè, la   funzione compile non esiste, la funzione exec non  esiste... ma poi le riempiremo con calma. Va bene?
38:33
Credo che questa lezione è andata  già abbastanza lunga. Chi volesse,  
38:38
perché no, si potrebbe lanciare già a  implementare 'sta roba qui. Potrebbe   essere comunque una cosa interessante da  fare. Se ancora non vi sentite pronti,  
38:48
guarderete la prossima lezione,  la prossima settimana, e man mano,   quando vi sentite pronti, a un certo punto vi  sganciate dalle lezioni, andate in una scoperta,  
38:57
implementate da soli ToyForth e poi tornate qui e  vedete mano mano come lo implemento io. Ciao raga.



Lesson 24 link: https://www.youtube.com/watch?v=-QxrmHo-V7Y&list=PLrEMgOSrS_3cFJpM2gdw8EGFyRBZOyAKY&index=27

Lesson 24 Transctipt:
Eccoci qua ragazzi, dobbiamo continuare il nostro  Toy Fort. Io l'ho aperto poco fa per ricordarmi  
0:47
che cos'è che avevamo fatto. Vabbè, ma avevamo  fatto poco, poco, ma tanto concettualmente. 
0:52
Questo è il nostro oggetto. Noi quando abbiamo  a che fare con un linguaggio di programmazione   interpretato e stiamo scrivendo un interprete,  questa è una struttura dati assolutamente  
1:02
necessaria, perché dobbiamo rappresentare sia gli  elementi del nostro linguaggio di programmazione,  
1:10
eh, gli elementi, diciamo, anche sintattici.  Quando facciamo il parsing noi utilizzeremo  
1:16
sempre questo oggetto per rappresentare i  vari pezzi del programma, ma anche ovviamente  
1:22
ancor di più. Perché? Perché questa cosa  è specialmente vera nel nostro linguaggio   di programmazione, che è rappresentato  da una lista di, diciamo, di oggetti,  
1:31
ma in altri linguaggi di programmazione potrebbe  non essere così e potremmo compilare in byte code. 
1:36
Quindi sintatticamente, eh, il programma  non verrà convertito poi, diciamo,  
1:42
in oggetti di questo tipo, ma comunque lo stato  di esecuzione, quello che c'è dentro le variabili,   quello che c'è dentro lo stack e così via,  sarà comunque un oggetto di vari tipi. 
1:54
Quindi se voi aprite i codici  sorgenti di Ruby, di Python,   troverete qualcosa di del genere. Eh, ma oltre a questa struttura avevamo  
2:04
altro. Avevamo un parser. Questo è molto  comodo perché poi vedrete che nel parsing,   siccome c'è sempre da parte delle funzioni  che fanno il parsing di ritornare dov'è che  
2:13
siamo arrivati a fare il parsing dentro la  stringa che rappresenta il nostro programma.  Eh, e allora ogni volta o praticamente passi  un puntatore, un puntatore, un puntatore,  
2:24
quindi ti scrive poi in questo puntatore di  puntatore dove è arrivato il puntatore originale,  
2:31
o te lo ritorna come valore la funzione di  ritorno dov'è che siamo arrivati, ma è scomodo.  In questo modo noi passiamo un puntatore  al nostro tipo TF parser e, eh, usiamo  
2:41
praticamente questa P per avanzare e abbiamo  anche un riferimento all'inizio del programma. 
2:47
Poi possiamo scrivere qui, per esempio,  la linea di codice dove siamo arrivati e   anche nel nostro oggetto possiamo aggiungere la  linea di codice in cui quell'oggetto è stato,  
2:56
eh, trovato, così quando ci sono errori di  sintassi, o meglio, quando ci sono errori a  
3:02
runtime oltre a quelli di sintassi. Qua la linea di codice ci serve per   segnalare dov'erano gli errori  di sintassi, tipo la linea 14. 
3:11
Se aggiungiamo poi 'line' qua, tipo int line,  ma lo faremo magari dopo se ci arriviamo, eh,  
3:19
possiamo anche, eh, segnalare gli errori a  runtime dicendo dov'è che è avvenuto l'errore,  
3:25
in quale linea è avvenuto l'errore, il  che ovviamente è effettivamente comodo.  E poi qua abbiamo il contesto di  esecuzione che nel caso di questo  
3:33
semplice Fort giocattolo utilizza solo uno stack. Qualcuno mi ha chiesto: "Ma perché lo stack lo  
3:40
rappresenti con lo stesso tipo, eh, che usi,  diciamo, per le liste del linguaggio stesso?" Beh,  
3:47
per semplicità. "E perché le liste del linguaggio  le, eh, le implementi utilizzando un array?" 
3:54
Eh, allora la linked list può sembrare per  questo caso d'uso la cosa ideale. In realtà  
4:01
non lo è in una implementazione seria e vi dico  perché: la linked list è interessante perché ha  
4:07
comunque una complessità costante, cioè O di uno,  sia per inserire elementi che per rimuoverli. 
4:14
Quindi io non devo fare nessun lavoro sugli  altri elementi quando ne aggiungo uno,   quando ne prendo uno. Sono allocazioni  a sé collegate dai puntatori next  
4:23
o previous se è doppiamente linkata e così via,  ma in realtà ha una cattiva località della cache e  
4:32
quindi, e inoltre, usa un sacco di memoria perché  ogni nodo ha un puntatore al next e così via,  
4:38
e quindi c'è un sacco di memoria che si spreca. Eh, la, poi c'è l'overhead dell'allocazione  
4:44
stessa di ogni pezzo di malloc che deve  avere dei metadati e così via. Ci sono vari  
4:49
motivi per cui, eh, non è proprio l'ideale. In realtà qui potrebbe sembrare che c'è il  
4:58
problema che ogni volta che la nostra lista  cresce, che noi la usiamo pure per stack,  
5:04
ma lista, stack e array non è tanto il nome,  ma è proprio la struttura dati che modella. 
5:10
Eh, allora da questo punto di vista c'è  una distinzione interessante da fare. Un   conto è come chiama una data struttura dati, un  linguaggio di programmazione ad alto livello,  
5:20
e che operazioni sono definite in quella struttura  dati. Un altro conto è il modo in cui è poi in C  
5:26
implementata, perché anche assicurandogli  la stessa complessità, eh, algoritmica per  
5:32
le stesse operazioni, ci sono diverse operazioni,  diverse implementazioni possibili e anche diverse  
5:38
implementazioni poi comunque possono  avere diverse complessità algoritmiche.  Quindi un conto è l'alto livello,  la descrizione che fa per esempio,  
5:46
non lo so, Python di una struttura dati,  un conto è poi quello che succede sotto.  Ovviamente se sai quello che succede sotto  puoi usare meglio la struttura dati. Eh,  
5:56
ma qua la cosa interessante è questa. Se noi oltre ad avere la lunghezza e   l'array del numero degli elementi avessimo  anche size_t alloc_len, possiamo sovraallocare 
6:13
questa lista, perché se vediamo che inizia  a crescere, per esempio partiamo quando una   lista è vuota, l'allochiamo a quattro elementi. Quando poi arriviamo al quarto elemento e c'è da  
6:23
inserire il quinto, facciamo una realloc. Realloc  praticamente crea una nuova allocazione con più  
6:31
spazio, quindi se è necessario copia anche  i dati che avevamo prima, e qui c'è anche  
6:37
l'inefficienza potenziale della rialloc. Eh, dopo che è arrivata a quattro elementi,  
6:44
noi ne possiamo aggiungere otto, poi ne  possiamo aggiungere 16 e ci ricordiamo  
6:50
quanto è grande l'allocazione in maniera  disgiunta da quanti elementi ci sono   davvero in quel momento nella struttura dati. In questo modo, allocando ogni volta per, eh,  
7:00
potenze di due e quando gli elementi invece  decrescono non deallocando, quindi lasciandoci  
7:06
sempre lo spazio per il massimo stack che abbiamo  visto, si dice che la amortized time complexity  
7:14
della struttura dati, quindi la complessità  ammortizzata, a quel punto è costante, quindi  
7:20
rimane O di uno come se fosse una linked list. Perché è vero che a volte io devo fare delle   operazioni molto costose di riallocazione, ma  è anche vero che queste operazioni le faccio  
7:31
sempre con meno frequenza, visto che ogni  volta alloco per la potenza successiva di 2,  
7:43
e quindi praticamente finisce che la mia  complessità è uguale a quella della linked list,   ma ho due vantaggi fondamentali: uno, la località  maggiore e, secondo, che è enorme, impagabile: 
7:58
il fatto che io posso accedere in tempo costante  all'elemento i-imo, quindi io praticamente posso  
8:05
accedere in maniera casuale alla struttura dati,  e un array di un linguaggio di programmazione deve  
8:12
consentire questo accesso in maniera non lineare. Se fosse O di N, eh, quindi in tempo lineare,  
8:20
l'accesso all'n-esimo elemento, dei  programmi semplicissimi che sulla  
8:26
carta sembrano non avere niente che non vada,  diventano quadratici nella loro complessità. 
8:32
Anche un ciclo for che accede prima  all'elemento 1, poi 2, poi 3, poi 4,  
8:38
diventa un programma di complessità quadratica. Quindi questo è il fatto, ma noi per ora ce ne  
8:43
freghiamo anche di questo e faremo una cosa  banalissima di riallocazione se è necessario,  
8:50
eh, ogni volta, perché siamo qua non per fare  il linguaggio di programmazione più efficiente,  
8:56
ma per fare un giocattolo che  sia però semplice da capire.  Quindi è questo che avevamo. Poi qua avevamo  creato una funzione che crea un oggetto e la  
9:05
usavamo poi in maniera specializzata  per creare oggetti di vario tipo:  
9:12
simbolo, int, boolean e così via. Lista. Qua c'è un errore però, perché questo 'i' non  
9:18
viene usato mai. Me ne sono accorto poco fa. Quindi questo è void. Quando creo un oggetto  
9:23
lista io lo creo vuoto e poi saranno le altre  operazioni che farò sulle liste che mi consentono  
9:30
di aggiungere elementi sulla lista o accedere  all'elemento n-esimo della lista e così via. 
9:37
E poi 'sto programma non faceva  niente, neanche compilava,   perché qua uso una compile che in realtà è  poi un exec che non sono neanche definiti. 
9:47
E qua gli davo Program text, che è Program Text,   che in realtà è argv[1], esatto, che è  il primo argomento della mia... Ah, no,  
9:59
devo... abbiamo detto che volevamo leggere  questo programma da un file, quindi, eh,  
10:07
qua che abbiamo incluso STDIO ce l'abbiamo. FILE *fp = fopen(argv[1], "r");  
10:15
Apriamo il file in read-only. E poi possiamo  magari vedere quanto è grande il file. 
10:28
Eh, ci sono due trucchi per fare. Possiamo fare  fseek alla fine del file e poi usare ftell per  
10:34
vedere cosa ci ha dato, se vogliamo farlo in  maniera completamente portatile, eh, soltanto  
10:40
usando la Lib C, senza utilizzare nessuna roba  di Unix Standard, perché se... Sì, perché questo  
10:48
ovviamente sarebbe una API di Unix, proviamo  a usare questa tecnica che si usava una volta. 
10:57
Non ci dimentichiamo poi di chiudere il file. Allora, guardate, se io faccio fseek. fseek  
11:04
cambia il cursore di dove stiamo  leggendo in questo momento nel file. 
11:13
Io posso andare per esempio alla fine del file  fseek, offset e dove. Quindi guardate io che  
11:20
faccio. È f... iso... SEEK. 
11:31
fseek 0, quindi dico "vai alla posizione zero  a partire dalla fine del file" e siccome poi  
11:39
io c'ho una funzione che si chiama ftell che  mi dice dov'è che sono arrivato, ed è un long, 
11:53
io in questo modo so quant'è grande il  file. Vediamo se è vero. source file size 
12:05
%ld file size. compile ed exec li  commentiamo, sennò qui non si compila niente. 
12:19
Eh, program.toy 5 dup * print. Sono 14 byte, è vero. Sì, 14 byte written qui.  
12:39
Quindi questo è un modo completamente portatile, portabile, forse dovrei dire, per avere la  
12:49
dimensione del file. A questo punto, che  me ne faccio della mia dimensione del file? 
12:55
Eh, program text. char *prgtext =  xmalloc. Avevamo qua, vero? L'avevamo  
13:04
fatta. xmalloc(file_size +  1) perché ci serve anche il   null term. E poi facciamo fread. f... no, fread. Che argomenti ha?  
13:22
Puntatore, dimensione, numero di  item, stream. Quindi puntatore, 
13:32
dimensione, numero di item e lo stream. Vabbè,  qua dovremmo controllare che in effetti, eh,  
13:45
leggiamo tutto il file, in realtà ce ne fottiamo  per quel discorso della semplicità che dicevamo. 
13:51
Alla fine però prgtext[file_size] = 0. Dobbiamo  mettere il null term, perché finora abbiamo  
14:01
letto dal byte 0 al byte file_size - 1,  ma qua ne avevamo allocato uno in più. 
14:07
Siccome è zero-based, ovviamente, file_size  perché parte da zero gli indici degli array,   quindi file_size sarà l'ultimo byte di questa  allocazione qua e facciamo il null term. 
14:18
A questo punto questo lo cancelliamo e qua  scriviamo prgtext e prg_text. Qua dovremmo  
14:27
avere il nostro programma eh, program. 
14:36
E invece no. E vi dico perché. Dopo che noi  abbiamo fatto praticamente fseek all'end,  
14:44
ovviamente poi fread parte da leggere  dalla fine del file e non c'è più niente. 
14:49
Poi dobbiamo fare di nuovo un fseek(fp,  0, SEEK...). Quindi vogliamo che il file  
14:56
si riposizioni il cursore all'indice  zero a partire dall'inizio del file. 
15:03
SEEK_BEGIN, com'è che si chiama? Perché si...  START non me lo colora? SEEK_SET, scusate. 
15:14
Ok, ricompiliamo. Eh, esattamente. Program  text: 5 dup... Eh, e poi c'è il new line,  
15:26
perché alla fine del programma c'è il new line  e siccome poi io ho messo anche il new line qui,  
15:33
qui ce ne sono due e vediamo che il  cursore, cioè che c'è una linea vuota.  Ma va bene così, perché noi vogliamo per  il parsing prendere tutto il programma,  
15:41
non è che vogliamo fare qua nessuna operazione  di cleanup della stringa in questo momento.  Piuttosto, se volete osservare meglio questa  cosa qua, mettiamo due parentesi quotate,  
15:53
ovviamente, così quando ci stampa il programma,  ecco, si vede che parte da qui il programma,  
16:01
dalla virgoletta, poi c'è il new line e poi  si chiude qua, si capisce che c'è il new line. 
16:08
Ma in realtà noi non vogliamo neanche stampare  'sta roba. Invece qui vogliamo scrivere,  
16:14
allora, if (fp == NULL). Qua un errore,  se il file non c'è lo dobbiamo mettere. 
16:24
Opening Toy Fort program. return 1. Qua diamo questo errore. perror...  
16:37
ridefinita in STDIO.H, quindi non dobbiamo  includere niente. E qua mettiamo un commento. 
16:47
Read program for later parsing. Ok, ora la nostra funzione compile. Per ora  
16:58
exec la commentiamo. La nostra funzione compile. Turn program into Toy list. 
17:24
Non è una vera compilazione in realtà, ma  chiamiamola così perché poi forse possiamo  
17:33
fare anche delle operazioni che potrebbero  somigliare un po' alla compilazione.  Ehm, eh, perché vi dico una  cosa. Voi, vi avevo fatto vedere 
17:46
com'è che funziona questo linguaggio  qua. Eh, poi questi linguaggi qua  
17:52
sono una famiglia di linguaggi chiamati  concatenativi. Il più interessante... 
18:00
Joy Programming Language. Linguaggio  di programmazione Joy. Come vedete,   guardate, 'square' qua definisce  'square' che è 'dup' e forse il  
18:09
punto dice che è finita questa definizione.  In questo caso è un linguaggio concatenativo  molto interessante con delle robe funzionali,  
18:19
addirittura le closure, la ricorsione. Questo  è Qort, guardate com'è semplice, è pazzesco. 
18:27
Eh, molto, molto interessante. Ora io avevo  partecipato un po' a questo linguaggio di  
18:34
programmazione e avevo proposto una  modifica a questi linguaggi basati   sullo stack che poi comunque credo che  sia apparsa poi negli anni... in Antirez. 
18:44
Esiste 'sta roba ancora? Sì, io qua avevo  implementato, guardate ragazzi questa foto,  
18:52
questa foto me la salvo. "A Joy implementation  written in...". Questo l'avevo fatto io nel 2004. 
18:59
Questa implementazione credo che  implementasse già il variable capturing. 
19:06
Ah, guardate qua, infatti, guardate cosa mi  avevano scritto in questo wiki Manfred: "Se puoi  
19:14
leggere questo, Salvatore, ti interesserebbe  scrivere una, diciamo, dare un contributo  
19:20
al paper che stiamo scrivendo sui linguaggi  concatenativi. La tua implementazione sembra  
19:26
significativamente differente dalle altre e il  tuo contributo in questo paper sarebbe benvenuto." 
19:33
Non so se poi io ho risposto, forse in parte sì. Comunque, praticamente, qual è la differenza che  
19:40
c'è in questa implementazione che avevo fatto  io? C'è un modo di implementare le variabili  
19:46
locali in questi linguaggi senza violare le  caratteristiche semantiche del linguaggio. 
19:54
Vi faccio un esempio. Questo è un  programma, perché poi questa cosa  
20:00
qui la implementeremo noi nel nostro Toy Fort. Questo è un programma che fa '5 dup *', quindi  
20:07
cinque si duplica. Quindi questo è lo stack.  Vi ricordo come funzionava molto brevemente:  
20:14
arriviamo, vediamo cinque, mettiamo cinque  nello stack. 'dup' e lo duplichiamo. '*' (per):  
20:19
preleviamo questi due dallo stack, li  moltiplichiamo e mettiamo il risultato,   eh, sullo stack. 'print': preleviamo 25, lo  stampiamo a video. Questo è il nostro output. 
20:31
Ok? E i linguaggi sono tutti così, senza  variabili, i linguaggi basati sullo stack. 
20:38
Ma io avevo pensato: e se noi utilizzassimo  un tipo che si chiama tupla, che è tipo una  
20:45
lista così, e quando ci sono queste tuple,  in realtà noi catturiamo delle variabili  
20:52
locali in dei simboli A e B? Quindi, per esempio, guardate,   io c'ho 5 e qui, eh, scrivo questo e  quindi 5 sarà catturato dal mio simbolo A. 
21:06
Quindi nello stack avevo 5 e lo... faccio il  push... lo stack. Poi qua c'è una cattura di  
21:15
una variabile, lo prendo e ora questo  cinque sarà... quindi ora c'ho pure   delle variabili locali, a = 5. Poi posso scrivere $a $a che  
21:26
fa il push della variabile locale sullo  stack, quindi 5, e ho implementato 'dup'. 
21:34
Ma siccome queste variabili qua non cambiano  nulla dal punto di vista semantico del linguaggio,  
21:39
rendono scrivere una quantità di  programmi molto, ma molto più semplice.  Questa mia implementazione del 2004  aveva questa modifica, ma vi faccio  
21:47
anche un altro esempio. Per esempio 5 10. Un altro comando tipico dei linguaggi, eh,  
21:52
di programmazione stack-based è 'swap', che se qua  c'abbiamo 5 e 10, il risultato è 10, 5. Invertono,  
21:59
perché spesso devi fare questa meccanica. Se avete programmato, per esempio, in Lua,   implementando in Lua della roba in C, dei  programmi in C, Lua ha un'interfaccia basata  
22:10
sullo stack che ha di queste complessità. Alla fine le cose diventano un po' scomode  
22:16
e allora, per esempio, come diventa 'swap'?  L'implementazione di 'swap' è tutta naturale,  
22:22
non devi neanche implementare queste primitive  qui nel linguaggio, perché puoi implementare  
22:27
'swap' in questi termini: [a, b]. Ok? Poi vi farò vedere che questa roba qui rende  
22:35
i linguaggi molto più semplici da utilizzare,  molto più maneggevoli dal punto di vista  
22:43
dell'utente finale, e quindi noi potremo finire  per avere qua in Toy una compilazione di queste  
22:50
variabili e poi assegnare a queste variabili,  per esempio, un indice unico e così via.  Questo, diciamo che è una specie di, eh, diciamo,  precompilazione, compilazione in byte code,  
23:00
perché comunque non interpretiamo ogni volta  il sorgente mano a mano che a runtime facciamo  
23:06
eseguire il programma, ma c'è qualche fase  iniziale in cui, per esempio, a delle variabili   simboliche possono essere associati degli  indici fissi in una tabella di variabili locali. 
23:17
Ma torniamo indietro a questa digressione.  Il mio programma compile era... eh,  
23:24
tfobj*. Ritorna 'compile(char *prg)'. L'idea è questa: e in realtà quello  
23:37
che fa compile non è altro che  trasformare una stringa in una lista. 
23:46
E per fare questa operazione qui  io devo implementare un parser. I  
23:52
parser di solito si scrivono... quando uno  vuole imparare qualcosa li scrive a mano. 
23:59
Quando invece vuole fare una cosa al  volo, che non è però tanto importante,   magari utilizza un generatore di parser. Quando poi le cose si fanno davvero serie, devi  
24:09
scrivere un'implementazione seria di un linguaggio  di programmazione serio, utilizzi di nuovo il  
24:16
parser scritto a mano. Questa è la logica. È  fondamentale imparare a scrivere un parser a mano. 
24:21
Allora, siccome ora già siamo andati lunghi,  iniziamo solo con la prima parte del parser.  Allora, io per iniziare voglio... voglio  creare un oggetto di parsing che era TF Parser. 
24:37
TF Parser parser. parser.prg, eh, com'è che si  chiamano i campi? PRG e P. parser.prg = prg; 
24:56
parser.p = prg. All'inizio noi siamo sempre...  partiamo ovviamente dall'inizio del programma  
25:11
che è il puntatore che ci hanno passato. Allora, qui io non mi metto a fare delle funzioni   per costruire un parser e inizializzarlo.  Lo alloco nello stack qua brutalmente,  
25:20
praticamente lo inizializzo così, e poi  passerò alla mia funzione di parsing il parser,   in questo modo, parser, il puntatore al parser. E per esempio, io per iniziare devo scrivere while  
25:35
(parser.p[0])... fino a quando, quindi,  non ho incontrato il terminatore null. 
25:45
Allora, la prima cosa che devo fare è consumare  gli spazi vuoti, quindi... parseSpaces(&parser). 
26:11
Vabbè, guarda, il parsing lo mettiamo  sempre dentro questa... stanza,   diciamo. void parseSpaces(tfparser *parser) p chiamiamolo. Ah, m vabbè, chiamiamolo  
26:32
'parser'... è troppo lungo, però  'p' poi viene p.p... perché il   campo si chiama pure .p e pare male. Allora, io per consumare praticamente  
26:44
quello che c'è qui di spazi posso usare include ctype.h. 'isspace'. La funzione, eh, fa tab,  
27:00
new line, spazi, ok. Mi piace. E  quindi questa funzione che farà? 
27:16
while (isspace(parser->p[0])) parser->p++;  incrementando il puntatore fino a quando il  
27:34
carattere su cui sono ora, quindi  [0], è uno spazio, incremento  
27:44
il puntatore e vado al prossimo carattere. Non so se sto facendo bene. Poi qua facciamo  
27:51
una switch: switch (parser->p[0]). Quindi  se il carattere dove sono in questo momento  
28:00
è per esempio un numero... Ah, qua dovrei  verificare... no, non mi piace la switch.  
28:05
In questo caso noi usiamo if... if (parser->p[0])... if isnumber... 
28:23
isnumber... Sì, mi copre  esattamente... Ah, isdigit. 
28:29
Facciamo isdigit. Se è p[0] è  effettivamente un numero or parser->p[0] 
28:47
è il meno, perché un numero può  iniziare per il segno meno. parse... no 
29:00
parseInteger, parseNumber, perché poi  vediamo questi numeri com'è che li abbiamo  
29:08
rappresentati. Abbiamo solo gli interi, vero?  Sì, non abbiamo neanche i numeri... vabbè,   chi se ne frega. parseNumber(&parser). Allora, questo lo chiamiamo parseSpaces  
29:25
perché dobbiamo avere dei nomi che hanno  senso. parseNumber. Ma questo parseNumber  
29:32
a me mi deve ritornare effettivamente... Allora, qui io ho bisogno di un tfobj *o;  
29:44
l'oggetto che sto parsando. o =  parseNumber(...); eccetera eccetera. 
29:55
E se 'o' è NULL, perché il numero è formato in  maniera scorretta, io qui devo generare un errore. 
30:12
Sì. Allora, tanto per iniziare qua,  facciamo una cosa. Dopo che ho fatto   il parsing degli spazi, if (parser->p[0] p[0] == 0) break. Qua ho finito di compilare  
30:35
perché sono arrivato al null term of program. 
30:46
Qua mettiamo subito else, perché se  trovo qualcosa che non è valido nel   mio linguaggio di programmazione, qua settiamo  'o' = NULL, così come mi ritornerà NULL anche  
30:55
parseNumber se c'è un errore. In questo modo io qua faccio:  
31:00
check if the current token produced compilation error. 
31:18
Eh, if (o == NULL), allora io scriverò  magari printf("syntax error near..."), eh,  
31:37
massimo non lo so quanto gli metto. 32 caratteri e qua i puntini... e, eh, parser->p è dove sono  
31:53
arrivato... quella combinazione, diciamo. Qua c'è  stato un errore da qualche parte vicino a qui,  
32:00
che però in realtà sarebbe interessante non  dare p... perché p è a metà di un numero dove  
32:07
noi abbiamo trovato un carattere sbagliato. Sarebbe interessante dare l'inizio del   numero. Quindi qua potrebbe essere  più carino per esempio fare char  
32:16
*token_start = parser->p; e qua token_start. Vedete come la programmazione è tanto il  
32:28
processo anche di anticipare certi casini  o certe parti poco interessanti del nostro  
32:35
programma. E qua facciamo return NULL, ma  in realtà qua dobbiamo fare il cleanup.  Allora, questi oggetti che noi di cui facciamo il  parse devono finire però dentro una lista. tfobj  
32:53
*parsed = ... com'è? createListObject(). Questo era void perché all'inizio mi  
33:07
crea una lista vuota. Quando poi praticamente   io faccio il parsing di questo numero qua e  ce l'ho dentro il puntatore 'o', poi io...  
33:18
quando... se o == NULL c'è un syntax error. Else, io devo fare, eh, listPush() che non  
33:28
l'ho ancora scritta, parsed, che è il mio  oggetto lista, o. Quindi devo accodare 
33:41
alla mia lista questo nuovo  oggetto. Implementiamo listPush. 
33:54
list object. A questo punto,  
33:59
visto che le cose si mettono in questo verso,  le cose dell'oggetto lista buttiamole qua. 
34:15
Sì, anche la creazione, eh. void  listPush(tfobj *l, tfobj *ele) 
34:30
push the new... add the new element  at the end of the list 'list'. 
34:41
Allora l->... Anzi, qua  com'è che siamo messi qui? L, 
34:55
chiamiamolo L. Questo... realloc...  la grandezza di un puntatore. 
35:10
Io qua ho un array di puntatori,  quindi quanto deve essere grande   'sta allocazione? La dimensione di 'sto  puntatore, di cui io ho tanti elementi,  
35:19
per... scusate, ho toccato più volte il  microfono facendo credo un cattivo rumore   che poi non potrò togliere mai... per len  + 1, perché devo aggiungere un elemento.  
35:31
Quindi faccio questa riallocazione. l->list.ele[l->list.len] = ele; 
35:48
Ma qua c'è un discorso molto, molto,  molto, molto, molto importante. 
35:58
Ora io in questa lista c'ho una  nuova referenza di questo oggetto,  
36:05
quindi io dovrei fare inc_ref_count(ele),  dove aumentare il conto delle referenze. 
36:10
E secondo me è giusto che  sia così, che questa funzione 
36:16
increment the reference  count of the added element. 
36:27
Ci sono due scelte possibili. O il conto  della referenza lo gestisce listPush,   o altrimenti uno dopo che fa il  push nella lista lo fa a mano. 
36:36
Guarda, facciamolo a mano, perché sennò nel caso  del... ci sono vantaggi e svantaggi, poi vediamo. 
36:43
Guardate, in questo caso io per ora  questo lo tolgo, anche perché così   lo possiamo non implementarlo per ora. Per dire, qua se lo avesse gestito lui,  
36:55
poi io qua dovevo fare dec... o, perché altrimenti qua diventava  
37:02
due il conteggio. Ma io ora non ci faccio niente  con questo oggetto 'o' che già ha referenza uno,  
37:08
perché quando io creo gli oggetti, vi ricordo che  li creo con reference counting di uno, vedete qui? 
37:15
E quindi, eh, certe volte è comodo, certe  volte è scomodo. Niente, facciamo che:  
37:21
it is up to the caller to increment the reference  count of the element added to the list if needed. 
37:41
Questo è molto importante. Qua ci deve  essere scritto, una documentazione,   una funzione che non se ne occupa lei. E poi  l->list.len++; abbiamo un elemento in più. 
37:54
Allora, qua guardate che abbiamo fatto. Abbiamo  riallocato... ah, e realloc ovviamente prende  
37:59
prima list.ele... il vecchio puntatore. Guardate realloc. Realloc è come malloc,  
38:08
ma in realtà prende un'allocazione  precedentemente fatta e la modifica affinché  
38:15
sia la nuova dimensione che ci serve, d'accordo? E se necessario il puntatore può cambiare,  
38:20
quindi, ma i dati vecchi noi non  li perdiamo, vengono copiati. 
38:27
Se l->list.ele è NULL, come all'inizio, realloc  equivale a malloc, quindi è comodissima,  
38:33
perché prima era un puntatore NULL, quindi  diciamo a realloc noi non ce l'avevamo prima   un'allocazione, semplicemente vogliamo  un'allocazione di questa dimensione qua. 
38:42
All'inizio len è 0, quindi diventerà  len + 1 lo spazio per uno solo,   list.ele[0]... e quindi siccome però  gli indici partono da zero riempiremo  
38:51
il primo elemento e poi aumentiamo  la dimensione della nostra lista. 
38:59
Quindi ora abbiamo questo listPush che  usiamo qui, e dec_ref_count non ci serve più. 
39:05
Questa, la gestione ancora del ref counting  non l'abbiamo neanche implementata. 
39:11
Quindi quello che dovremmo fare ora  in realtà è implementare parseNumber.  Allora, se io provo a compilare questo programma  che succede ora? Ovviamente ho una quantità enorme  
39:20
di problemi, quindi linea 111... 'parser'  che avevo sbagliato, 'tfobj' scritto male, 
39:38
parseNumber non esiste. unused variable... e questa  
39:44
variabile qui non la uso mai. Tutto vero? Ora quello che faremo nella prossima  
39:53
puntata è implementare parseNumber. Allora, tfobj *parseNumber, vediamo  
40:01
dove arriviamo. (tfparser *parser)... perché  secondo me l'attenzione fra un po' crolla a zero,  
40:10
perché non mi ricordo da quant'è che  registro, ma è un tempo significativo. 
40:17
Allora, guardate qua che cos'è che  noi dobbiamo fare. Tanto per iniziare,  
40:23
vabbè, l'oggetto lo creiamo alla fine. Dobbiamo, tanto per iniziare, avere  
40:28
idea di dove comincia, di dove finisce il nostro  numero. Guarda qua, facciamo un buffer, non lo so,  
40:33
di 128 caratteri al massimo e poi facciamo che fino a quando... parser->p[0]...  
41:02
while isdigit... fino a quando è un carattere e questo qui dovrebbe anche includere il fatto  
41:12
che se arriviamo alla fine del programma...  però noi mettiamo un esplicito. parser... 
41:20
->p[0], cioè non è 0, il byte 0, NULL terminator,  è un carattere. Facciamo che int i = 0. Copiamo  
41:36
dentro questo buffer che noi stiamo scrivendo. buffer[i] = parser->p[0]... Mh. No,  
41:52
c'è un modo che mi piace secondo me di più.  Invece facciamo che char *start = parser->p; 
42:11
Ok. Sì, parser->p, scusate. Char... semplicemente fino a quando soddisfa  
42:29
i nostri criteri di quello che  ci può stare dentro un numero. 
42:36
E allora il meno può apparire solo all'inizio,  quindi if (parser->p[0] == '-') parser->p++; 
43:00
e qua parser->p++;   Quindi questo lo gestiamo come caso a parte  perché il meno può apparire solo all'inizio. 
43:10
Incrementiamo il nostro parser. Quando  abbiamo finito 'sto ciclo, end = parser->p. 
43:20
E questo 'end' in realtà è il primo  carattere che non è tra i caratteri  
43:27
numerici che noi gestiamo. Quindi int numlen è uguale a end... Allora, i puntatori,  
43:40
siccome sono numeri, si possono sottrarre  senza problemi per vedere qual è la differenza,  
43:46
perché io c'ho l'indirizzo di memoria di  dove parte il numero, che è questo parser->p.  Poi parser->p, mentre continuo a  incrementarlo, parser->p++ qui.  
44:01
Quindi alla fine la sottrazione ci dirà quanti  caratteri ci sono là dentro questo numero. Ok? 
44:10
end - start. A questo punto if  (numlen >= 128) return NULL. 
44:22
Questo è la lunghezza massima del mio numero.  Vabbè, qua facciamo #define MAX_NUM_LEN 128,  
44:29
MAX_NUM_LEN, 128 e MAX_NUM_LEN. Così se lo vogliamo cambiare in  
44:36
futuro è più facile, non è hardcoded,  anche se questo è un piccolo esempio,  
44:41
ma comunque un minimo di decenza  la possiamo anche, diciamo, tenere.  A questo punto che siamo qua e sappiamo che  abbiamo meno di 128 byte o meno di MAX_NUM_LEN,  
44:53
copiamo dentro buffer a partire da start il numero  di caratteri di cui è composto il nostro numero e  
45:02
mettiamo il null term, il terminatore null. 
45:11
E a questo punto possiamo usare una  chiamata di sistema che si chiama 
45:20
str... ma guardate, ne uso una terribile che  si chiama atoi() e me ne frego. Guardate,  
45:27
ritorna un intero partendo dalla stringa,  perché qua dobbiamo fare cose facili. 
45:33
A questo punto posso finalmente  creare il mio oggetto 
45:43
e lo creo dandogli come numero  atoi(buff) e ritorno il mio oggetto. 
45:52
Ok, questo mi dovrebbe tornare un  oggetto numerico che effettivamente  
45:59
è quello che io voglio. createIntObject. 
46:15
Se ora compilo questo programma qui, non  abbiamo memcpy perché includiamo string.h. 
46:30
Qua dobbiamo ritornare il nostro  parsed, il nostro programma già parsato. 
46:46
E qua questa variabile non è utilizzata,  ma noi troviamo un modo di utilizzarla.  
46:52
La nostra exec la facciamo  diventare una cosa molto più facile. 
47:03
Qua mancava uno spazio. Execute the program.  In realtà noi la nostra exec, che però non la  
47:10
vogliamo assolutamente implementare, eh, tfobj *prg, 
47:23
gli facciamo semplicemente stampare  quello che c'è dentro. Eh, for... int... 
47:34
prg->list.len... j++... e poi in base al tipo stampiamo quello che c'è  
47:48
dentro. Vabbè, prima siccome questo, il programma,  è una lista, apriamo la parentesi quadra e la  
47:57
chiudiamo. E qua ci mettiamo anche un new line. Ehm, switch (prg->list.ele[j]...).  
48:16
Vediamo in base al tipo... case se è TFOBJ_TYPE_INT, stampo questo... virgola... 
48:41
Eh, i... break. default: Se non è nessuno di  questa roba qui, stampiamo un punto interrogativo. 
49:05
Ehm, ogni volta che stampo un elemento,  magari ci metto uno spazio dopo. Vabbè,  
49:14
ci sarà uno spazio in più alla fine, chi  se ne frega. Questa è solo una prova. 
49:26
Eh, switch (o->type). Attenzione,  io voglio controllare il tipo. 
49:37
E questo è un size_t e deve rimanere un size_t. 
49:44
incompatible pointer... exec... exec... io  voglio eseguire il programma, non program...  
49:56
scusate, questo era un errore di prima. Ok, il programma compila. Che funzioni,  
50:05
ho qualche dubbio, ma vedremo. Allora, io per fare funzionare 'sto  
50:12
coso facciamo program.tf. TF. Il nostro programma  facciamo che è semplicemente 5 10 20. 5 10 20... 
50:29
stampa effettivamente tre numeri,  ma sono sbagliati. Perché? Guardate,  
50:37
perché quando io praticamente faccio  il parsing del mio numero... parse... 
50:49
atoi(buff), createIntObject. Allora,  dobbiamo andare a vedere dov'è che sbagliamo. 
50:56
Veramente mi sembrava di saperlo, ma in  realtà non lo so. Vediamo se questi buffer   qui sono correttamente settati al numero. Sì, 5 10 20, stampa. Quindi qua facciamo il  
51:10
parsing in maniera corretta. Vediamo qua se, ehm, o->i è veramente il numero che noi di cui facciamo  
51:26
il parsing. E fin qua ci siamo. Quindi parseNumber avviene qui. 
51:40
Eh, prima di fare questa listPush, controlliamo di  nuovo che il nostro oggetto abbia veramente quello  
51:49
che noi ci aspettiamo che ci sia là dentro e ci siamo anche qua. Andiamo a vedere  
51:58
che la listPush abbia senso. realloc, eccetera eccetera.  
52:08
sizeof(tfobj*)... list.len + 1...  l->list.ele[l->list.len]... e poi incremento 
52:20
e anche questo sembra essere sensato.  Vediamo qua che cosa stiamo facendo. 
52:31
Allora, facciamo un'altra cosa. Quando io faccio  parseNumber e ho visto che c'è veramente quello  
52:38
che vorrei prima del push, mi faccio stampare i puntatori. Guardate, questo praticamente ha  
52:49
l'effetto di... No, scusate, facciamo  una cosa. gcc ... a.out program.tf,  
52:56
così con un'esecuzione sola. Questi sono i puntatori. Io   gli stessi puntatori di questi oggetti li voglio  andare a trovare e li voglio andare a trovare qui. 
53:19
Ah, ragazzi, scusate, avevo sbagliato una  cosa banalissima. Quindi andiamo a cancellare   questo che non mi serve più a niente. Qui l'oggetto... non è che questo prg  
53:28
è il mio programma. Ehm, quindi object... tfobj *o = ... questo. Quindi l'oggetto  
53:48
della lista attuale è questo qua. Quindi  scriviamo qua o->type e qua scriviamo o->i. 
54:04
Ah, perfetto, sta funzionando,  guardate. 5 10 e 20.  Quindi ho, diciamo, una parvenza di  compilazione di questo programma qua. 
54:14
Poi ci sono delle cose che noi non  stiamo gestendo. Attenzione, per esempio,   qui se io ho un problema di parsing, fixme: release parsed here. Qua c'era  
54:33
un memory leak, tanto per iniziare, eccetera. Però guardate, lo vedete come dal nulla siamo  
54:41
passati al fatto che c'è in memoria una  rappresentazione di questo programma. 
54:47
Se già lo volessimo eseguire veramente con  la nostra exec, ogni volta che troviamo un   intero, andiamo a popolare quello stack. Già è in maniera super embrionale l'inizio  
54:57
di qualcosa. Nelle prossime puntate  vedremo cos'è questo qualcosa. Ciao.

