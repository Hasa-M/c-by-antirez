Lesson 28 - Link: https://www.youtube.com/watch?v=cvWbCx0lLjs&list=PLrEMgOSrS_3cFJpM2gdw8EGFyRBZOyAKY&index=32&t=18s

Lesson 28 - Transcript:
0:40
Eccoci qui con la nuova lezione di programmazione  in C. Oggi devo dire che è una lezione che forse  
0:46
non vi aspettate. Stavo andando a registrare  la lezione su Toy, quando mi sono accorto che,  
0:55
scritte le prime linee, sostanzialmente mi serviva  un costrutto del C che non ho trattato. Perché,  
1:04
come vi dicevo, su Toy servirà nel contesto in  qualche modo poter settare un errore a runtime,  
1:11
e sarebbe bello se questo errore potesse essere  settato con una funzione che si comporta tipo la  
1:16
printf, in cui poi posso mettere, diciamo,  un formato e poi posso mettere numeri,  
1:23
righe, per dire, la riga di codice dov'è  stato l'errore o la funzione che lo ha  
1:28
scaturito e così via. Per esempio:  function entry, name, eccetera.  
1:36
Ma per far ciò ci serve introdurre le funzioni  variadiche in C, ovvero quelle funzioni che  
1:42
hanno un numero di argomenti variabile.  E per farlo serve appunto questa lezione.
1:48
Per cui andiamo a editare un nostro programmino  "vararg" in cui faremo dentro gli esempi. Per ora  
2:00
main void sarà il nostro "Hello World". Scusate il  casino, c'ho un tubo a vista e quindi se qualcuno  
2:15
tira lo scarico o cose del genere si sente questo  casino, ma spero che presto non si sentirà più.
2:21
Il nostro Hello World a cui siamo ormai  affezionatissimi. Faremo esami qua dentro.  
2:29
Ma tanto per iniziare vorrei dire una cosa che è  peculiare del C e delle funzioni variadiche in C.  
2:39
Prendiamo qua la pagina con le funzioni che si  occupano proprio di permettere l'accesso o la  
2:46
copia dell'oggetto che descrive gli argomenti  variabili in una funzione in C. In C c'è un mix  
2:57
tra sintassi per poter definire una funzione con  numero variabile di argomenti, e qua ci dovrebbe  
3:06
essere un esempio... infatti c'è. La sintassi  sono questi tre puntini. Sostanzialmente quando io   definisco una funzione scrivo gli argomenti che la  funzione deve accettare per forza, quelli fissi,  
3:17
e poi in coda posso terminare la lista con questi  tre puntini. Questi tre puntini... scusate,  
3:24
tolgo le notifiche e la suoneria dal telefono,  ok... dicono al C che questa funzione,  
3:33
oltre agli argomenti che sono listati, ne può  prendere un numero da zero a, diciamo, infinito  
3:39
in linea teorica. Diciamo non infinito, però ci  siamo capiti, molti altri in numero variabile.
3:46
A parte questa parte qui che è sintattica, il  fatto è che il resto non è sintattico. Per il  
3:54
resto ci serviamo di funzioni vere e proprie che  ci permettono di accedere a questi argomenti,  
4:01
per esempio va_start, va_arg e così via. Vediamo  qua che cos'è che fanno queste diverse funzioni  
4:10
o queste macro. va_start deve essere la prima a  essere chiamata e inizializza AP, che è questo suo  
4:25
argomento, una va_list (variable argument list),  che può essere passata a va_arg per ogni argomento  
4:38
che deve essere processato. In pratica va_arg  estrae dalla lista degli argomenti variabili.
4:55
Finalmente poi chiamare va_end segnala  che non ci sono altri argomenti e  
5:02
causa l'invalidazione di AP. Si noti che ad ogni  chiamata di va_start deve succedere una chiamata  
5:13
a va_end, devono essere in paio all'interno della  stessa funzione. Il parametro "last" è il nome  
5:21
dell'ultimo argomento prima della lista,  prima che inizino gli argomenti variabili.  
5:29
Quindi, per capirci, quando qua chiama va_start  per inizializzare AP, che è l'oggetto, diciamo,  
5:37
che rappresenta gli argomenti variabili,  uno gli deve dire a va_start qual è l'ultimo  
5:46
argomento a non essere variabile, ed  è format (FMT), questo qua. Da quel  
5:53
momento in poi si può usare va_arg passando  come primo argomento appunto questo oggetto  
5:59
inizializzato e come secondo argomento il tipo  di argomento variabile che stiamo estraendo.
6:07
In sostanza la funzione in C deve sapere a  priori in qualche modo qual è il formato dei  
6:16
vari argomenti variabili che va estraendo uno  dopo l'altro con queste chiamate a va_arg. Ma  
6:23
è meglio che facciamo un esempio qui. Quindi  include , ci serve questo include,  
6:31
e nella nostra main chiameremo una nostra funzione  foo che usa un numero variabile di argomenti.
6:45
Com'è che la possiamo pensare? Ecco, possiamo  fare una funzione che ha un char *fmt, tipo  
6:53
simile alla printf ma, ora vedremo, sarà  molto più semplice della printf, e poi un  
6:59
numero variabile di argomenti. Guardate che cosa  farà questa funzione. Allora, tanto per iniziare:  
7:06
va_list ap; devo dichiarare il mio oggetto  ap che conterrà gli argomenti da estrarre,  
7:14
o lo stato dell'estrazione degli argomenti  per essere più precisi. va_start(ap,  
7:23
fmt). Dovrebbe essere così, che io devo passare  un puntatore ad ap? Andiamo a vedere. va_start...  
7:33
No, si passa direttamente ap così com'è. E poi  va_arg con ap e il formato mi dirà cosa prendere.
7:44
Allora, io faccio una cosa, faccio un puntatore  p a format. While *p, fino a quando quello che  
7:58
c'è registrato nel puntatore p non è null, quindi  non è la fine della stringa che io passerò al mio  
8:07
foo come formato. Potrei usare qua lo switch...  No, niente. Facciamo if *p == 'i'. Se è una 'i'  
8:20
vuol dire che voglio stampare un intero. Quindi:  int i = va_arg(ap, int). Qua devo specificare  
8:29
il tipo che voglio estrarre. va_arg mi ritornerà  l'intero dalla mia lista variabile di argomenti e  
8:36
si posiziona sul prossimo. D'accordo? E lo stampo  questo intero con la printf. Else if *p == 's',  
8:50
se è una 's' io voglio stampare una stringa: char  *s = va_arg(ap, char*). Quindi ci aspettiamo che  
9:03
ci sia un puntatore di tipo carattere. Else...  wrong specifier. Scriviamo così e basta.  
9:21
E continuiamo, anzi veramente a questo punto  ritorniamo perché significa che lo stato può  
9:26
essere corrotto, non si sa che succede. p++ perché  dobbiamo ogni volta incrementare il puntatore.
9:34
E come si userebbe una tale funzione? Foo,  per esempio: due interi, una stringa e un  
9:40
altro intero ("iisi"). E poi qua gli passo: 10,  20, "ciao ciao" e 5. Ok, quindi questa funzione  
9:49
foo man mano legge un carattere dopo l'altro  le cose che io voglio stampare, con va_arg le  
9:57
estrae dagli argomenti variabili e alla fine  termina. Vediamo se questo programma funziona.
10:08
Il programma, come vedete, funziona. Scrive  "Hello World" e poi stampa 10, 20, ciao ciao,   5. Ma qua noi ci siamo detti che in realtà  ci dovrebbe essere la chiamata va_end(ap),  
10:21
e anche qui prima del return. Non cambierà niente  dal punto di vista dell'esecuzione, ma evitiamo  
10:29
che ci sia qualche leak perché noi non conosciamo  come è implementata una cosa così a basso livello  
10:34
come gli argomenti variabili, e quindi dobbiamo  sempre curarci di usare va_start e va_end.
10:46
Vi dico di più, guardate qui: qua c'è un errore,  un'eccezione e dobbiamo chiamare va_end, ma anche  
10:52
quando la funzione termina dobbiamo chiamare  va_end. Questo è un buon caso, anche se molto  
10:59
semplice, ma ve lo voglio fare vedere in questo  contesto in cui bisogna utilizzare goto. Qui  
11:05
mettiamo una label "cleanup". Goto cleanup. Quindi  togliamo la return perché poi dopo la cleanup  
11:20
automaticamente la funzione ritorna, e se ci fosse  una cleanup più complicata in questa funzione,  
11:28
invece di duplicarla qui e poi qui e magari  in chissà in quanti altri casi, noi abbiamo  
11:35
un singolo entry point per fare la cleanup.  Compiliamo. Il programma è identico a prima dal  
11:45
punto di vista dell'esecuzione, ma è un programma  meglio scritto, alla faccia di quelli che vi  
11:51
dicono che non dovete usare goto: usatelo tutte  le volte in cui credete che sia migliorativo.
11:57
Ehm, volevo dirvi una cosa: perché noi quando  facciamo va_arg dobbiamo specificare qua il  
12:07
tipo dell'argomento? Ci sono due ragioni per far  ciò. La prima ragione è che poi non dobbiamo avere  
12:17
warning quando lo assegniamo alla nostra variabile  o quando lo usiamo. Quindi il valore di ritorno di  
12:25
va_arg, di questa macro, deve essere coerente. Ma  c'è di più. In realtà va_arg non ha idea di quali  
12:32
siano gli argomenti variabili che seguono uno dopo  l'altro. Il C non è così ad alto livello da avere  
12:38
un argument vector, un vettore di parametri che  sono stati passati alla funzione. Assolutamente  
12:44
no. Per cui si deve fidare di noi. Quindi lui  estrae il tipo in base alla grandezza che ha un  
12:52
intero. Se un intero è 4 byte e un puntatore è 8  byte e così via, altrimenti succedono dei casini.
12:58
Allora, vi faccio vedere una cosa qua. In teoria  noi avevamo 10, 20 e poi "ciao ciao". Ma se  
13:04
io qui invece di 10 e 20 gli metto "zig ba",  una stringa, il programma compila lo stesso,  
13:14
non ci sono warning, stampa prima  un numero, poi un altro numero,   poi va bellamente in segmentation fault. Perché  si corrompe lo stato? Perché non è vero che gli  
13:26
argomenti sono quelli che lui si aspetta. Però,  come potete vedere, non c'è nessun tipo di warning  
13:35
durante la compilazione. Non mi avvisa nessuno  del fatto che c'è qualcosa che non va. Per cui,  
13:41
anche se poi in realtà i compilatori più evoluti  con la printf danno warning che lo specificatore  
13:47
di tipo non combacia con gli argomenti, è una  funzione specifica del compilatore e non una   funzione del C in termini così generali. Insomma,  questo mi sembra molto interessante da stressare  
14:01
anche per spiegare perché poi uno qua deve  mettere il tipo. In teoria uno dovrebbe poter   fare va_arg e basta, in base a quello che ci hanno  passato, ma col C queste cose non si possono fare.  
14:12
Quindi ripristiniamo qua il nostro programma  originale affinché tutto funzioni nuovamente.
14:20
Ma c'è di più, c'è di più.  
14:28
Che succede se io voglio una funzione con un  numero variabile di argomenti che chiama una  
14:38
funzione con un numero variabile di argomenti?  Per esempio, io vi dicevo che volevo settare nel  
14:43
contesto un errore che fosse dato da una funzione  simile alla printf, ma non posso ottenere questo  
14:54
scopo con quello che abbiamo imparato finora. Ma  guardate, se io faccio "man 2 printf" o "man 3  
15:03
printf", vedrò che oltre alle printf normali c'ho  anche delle printf più interessanti. Guardate qui:  
15:16
vprintf. Invece di prendere una lista di argomenti  vera e propria, cioè lo specificatore di tipo,  
15:25
prende un argument variable nel formato  va_list, esattamente in questo formato qui.
15:35
Quindi guardate, io mi prendo questa  funzione qua, cancello tutto il resto  
15:48
e faccio semplicemente sta cosa qui: vprintf(fmt,  ap). Guardate, ho scritto un wrapper della printf.  
16:01
Questa foo verrà chiamata, creerà questo  oggetto ap, inizializzerà questo oggetto  
16:09
ap... Qua c'è uno specificatore di tipo  che è esattamente compatibile con quello   della printf. Forse quella printf è const, nel  modificare quello a cui punta questo puntatore,  
16:24
quindi ci proteggiamo con const e poi chiamiamo  questa vprintf e poi abbiamo la nostra chiamata  
16:33
va_end. Compiliamo questo programma, stavolta lo  useremo come se fosse la printf la nostra foo.  
16:46
E come vedete funziona: 10,  20, funziona perfettamente. Perché è utile una cosa del genere? Allora,  tanto per iniziare invece di usare la vprintf,  
16:56
usiamo la vsnprintf. La vsnprintf è come  la printf, ma invece di scrivere a video  
17:05
scrive dentro un buffer, un buffer che  si chiama str che è di dimensione size.  
17:11
Quindi io allo qua my_buffer di, non lo so, 32  byte. Alla mia vsnprintf gli do il my_buffer,  
17:25
virgola, e gli do sizeof(my_buffer),  la sua dimensione. A questo punto,  
17:34
se io ora compilo il programma e lo eseguo...  vsnprintf, vediamo che cosa ho sbagliato. Sì,  
17:49
const format, quindi stringa, dimensione  e formato. No, ragazzi, scusate, non lo  
17:56
so perché ho letto male. Il formato è l'ultimo.  Ora dovrebbe combaciare tutto, infatti compila.
18:04
Allora, come vedete non succede niente oltre al  fatto che scrive "Hello World", perché io sto   scrivendo dentro un buffer, ok? Quindi dovrei poi  stampare quello che c'è dentro il mio buffer. Il  
18:15
mio buffer è una stringa, ma la posso stampare con  la printf se lo voglio vedere. Infatti c'è scritto   10 e 20. Ma facciamo una cosa qua, scriviamo "Hi  Hi hi AAAABBB". Così vediamo che la stringa è  
18:30
questa. E dopo che io ho il mio buffer faccio una  cosa: size_t j = 0; j < size of my_buffer; j++.  
18:44
Per tutta questa stringa, non mi preoccupo neanche  di cercare il null terminator. my_buffer[j] =  
18:59
tolower(my_buffer[j]). "man tolower": che cos'è  tolower? È una funzione in C che è dichiarata qua  
19:09
(ormai includiamo ctype.h) che mi ritorna  la minuscola della lettera che io gli do.
19:20
Quindi a questo punto questa vsnprintf crea  l'output che doveva avere normalmente la printf.  
19:28
Io rendo tutti i caratteri minuscoli e  poi finalmente stampo la stringa e posso  
19:34
ritornare. Come vedete ho creato una funzione,  una variante di printf che stampa in minuscolo  
19:44
tutto quello che c'è da stampare. Anche se io  qui avessi una stringa che passo io, "CIAO",  
19:54
darà minuscolo perché questa  modifica è fatta alla fine.
20:01
L'altra cosa che ci potrei fare in teoria  è, invece di fare questa roba qua, dopo che  
20:08
ho fatto la vsnprintf guardo la len: size_t len =  strlen(my_buffer). Guardo quant'è lunga la stringa  
20:27
risultante. A quel punto calcolo il padding:  (80 - len) / 2. 80 che sono le colonne del mio  
20:36
terminale, meno la lunghezza della stringa, diviso  2, e ho quanto spazio lasciare a sinistra se  
20:50
voglio che la stringa sia centrata (perché tutto  sono 80, io sto usando per esempio 60 di stringa,  
20:56
resta questo spazio qui, ne voglio metà a destra  e metà a sinistra). Quindi poi faccio: for  
21:16
size_t j = 0; j < padding; j++ printf(" ");  (uno spazio). Questo è molto inefficiente  
21:28
ma non ci importa assolutamente niente.  E ho una funzione strlen che è definita  
21:35
in string.h. A questo punto ho una  funzione che mi centra le scritte.  
21:44
Così me la centra. Se gli scrivo foo("Antirez"),  mi centra anche questo. Insomma, è un modo carino  
21:56
per farvi vedere perché uno vuole wrapperare a  volte delle funzioni variadiche e tutto il resto.  
22:02
A questo punto abbiamo sufficiente conoscenza  delle funzioni variadiche per implementare, nella  
22:07
prossima puntata, la nostra set_context_error  o come la vorremmo chiamare di Toy. Bene, ciao.
22:15
Vi dico la verità, mi accingevo a montare questo  video, ora è tardi, che ore sono? Le 10:15.  
22:24
Ehm, niente, sono qui ancora, avevo il terminale  aperto su sta roba qui, ma non ho fatto vedere gli  
22:32
usi più interessanti dei va_arg in C, perché non  sono neppure quelli che noi utilizzeremo poi nel  
22:41
Toy, nell'interprete che stiamo scrivendo. Io sono  un fanatico delle funzioni con un numero variabile  
22:50
di argomenti perché in C sbloccano una cosa che è  abbastanza magica: permettono di far diventare il  
22:58
C un linguaggio a più alto livello. Io questa  cosa l'ho esplorata in una maniera veramente  
23:04
molto interessante qui nella mia botlib. Questa è  una libreria che serve per scrivere bot Telegram,  
23:12
ma a noi non ce ne frega niente. Ma per  questa libreria avevo scritto due cose:  
23:17
un wrapper della libreria cJSON e  un wrapper della libreria SQLite.
23:31
Ora vi voglio fare vedere sqlite_wrap.c.  Esattamente. Guardate: "this is a low level  
23:41
function that we use to model all the high level  functions". Quindi questa è la base, la funzione a  
23:46
basso livello che si serve per modellare tutte le  altre. Guardate, praticamente tu fai il quoting di  
23:52
quello che c'è dentro la query con questo ?s, ?b,  ?i e ?d in base ai tipi che SQLite prende. Ora,  
24:06
però per farvi capire fino a che punto tutto  ciò modifica in maniera totale il modo in cui  
24:15
si possono scrivere le query, vi faccio vedere  una cosa. Andiamo a... come si chiama il bot  
24:23
quello finanziario che avevo chiamato? Stonky,  che avevo scritto con questa libreria. Stonky.c.
24:32
Ah, poi prima di tutto vi devo  fare vedere... vabbè, non importa,   facciamo tutti i vari utilizzi della query. Ah,  ecco qua: sqlGenericQuery. Perché qua ancora  
24:48
era implementato come parte del bot stesso,  poi l'ho estratto in una libreria. sqlNextRow  
24:55
e così via. sqlSelect. Allora, io voglio  arrivare al punto che vi faccio vedere...  
25:04
ecco, esattamente. Questa è una query:  db_get_portfolio. sqlSelect. Qua c'è la  
25:11
query. Guardate, lo vedete questo ?i? Ma  non è solo quello. Quando io poi scrivo,  
25:18
per dire, sqlSelect, questa già fa una select e  poi c'ho questo iteratore che utilizza sqlNextRow.
25:26
Ora io vi voglio far vedere una cosa. Io prendo  questo pezzo di codice qui e lo voglio dare qui  
25:36
a Claude e gli dico: "Take as written using  the wrapper that I attached to this chat.  
25:55
Now write the same code as if  we could not use our wrapper,  
26:05
just using the raw sqlite3 C API". Ora io gli  passo la mia botlib qua e sqlite wrapper...  
26:26
Gliela mettiamo qui, gliel'abbiamo attaccata  pure. Ecco. E ora vi faccio vedere questo codice  
26:35
qui senza questo wrapper cosa diventa. E questo  wrapper è fondamentalmente possibile... Ecco,  
26:44
vi sta facendo vedere che succede. Allora, uno  deve fare sqlite_prepare_v2. Ok, qua gli devi  
26:54
mettere il punto interrogativo, poi devi fare  sqlite_bind_int perché devi fare il binding degli  
27:03
argomenti con dove hai messo i punti interrogativi  e ti devi ricordare dove li hai messi. Ok.
27:12
"Now make an example where the SQLite  SQL query needs multiple parameters  
27:25
and write the code both with and without wrapper".
27:39
Perché quello era un caso semplice. Adesso la  differenza è enorme, quindi poi sqlite_finalize...  
27:46
Ah, guardate questo qui. Questo però non credo  che l'ho wrapperato. Questo credo che fosse  
27:54
identico a com'era prima. Vediamo... Botlib  sqlite wrapper... Ah no, anche questo è diverso.  
28:23
C'è anche un'astrazione per la row. È  pazzesca. La differenza è enorme. Ecco,  
28:31
questo è con il wrapper. E qui è un po' più  complicato, ci sono due interi eccetera eccetera.  
28:37
E poi guardate qui: quantity, average price,  eccetera eccetera. Qui guardate bisogna fare  
28:42
questa binding in base al tipo con  l'indice. Poi praticamente bisogna  
28:49
ricordarsi di utilizzare queste altre API:  column_text, eccetera eccetera. Ed è un casino.
28:59
Ecco, questo per farvi vedere  che la potenza è enorme,   ma forse c'è un caso nella botlib ancora  più estremo che è il wrapper di JSON.  
29:10
Guardate qui. Qua io però la sto usando qua  negli esempi un solo argomento, però sì,  
29:17
sostanzialmente tu puoi sostituire con degli  asterischi delle parti di questo selettore JSON  
29:25
che scrivi, e devono matchare quello che poi dai  come argomento qua. Allora, bisogna dire che sì,  
29:31
il numero variabile di argomenti fa la differenza,  ma anche il fatto di fare il parsing del selettore  
29:39
e di andare nested dentro l'oggetto cJSON è  pure abbastanza importante. Quindi questo sì,  
29:49
questa cosa pure fa una differenza incredibile  nel modo in cui si può accedere. Guardate, questo  
29:57
file è una... funziona, cambia l'API da così a  così, cioè fa diventare il C un linguaggio più  
30:05
ad alto livello. Perché io ora ve lo voglio fare  vedere, sempre su Stonky, spero di averlo usato...  
30:20
esatto. cJSON_Parse. Ah, Select. Cioè  uno fa cJSON Parse, poi fai cJSON_Select,  
30:29
result due punti e gli dici che tipo è. Qua  io sto forzando che deve essere un array,  
30:34
altrimenti il parsing fallisce e mi ritorna null.   Questa è un'altra vita completamente. Quindi  questi strumenti che il C dà, ma tutto assieme:  
30:45
il numero variabile di argomenti, le strutture  se sono usate, e i puntatori a funzioni (anche   dentro le strutture) se sono usati in maniera  proficua, rendono il C sostanzialmente un altro  
30:56
linguaggio. Ecco, ci tenevo, diciamo,  a fare questa aggiunta serale. Ciao.
