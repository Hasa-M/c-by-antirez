Lesson 18 - Link: https://www.youtube.com/watch?v=3w73xjUSUEU&list=PLrEMgOSrS_3cFJpM2gdw8EGFyRBZOyAKY&index=21

Lesson 18 - Transcript:
0:40
Ciao amici, benvenuti nel corso di C. Nelle ultime  lezioni, noi siamo stati accompagnati da questo  
0:47
esempio qua, delle "prefixed length string". Oggi  lo salutiamo perché non ci serve più. È finito  
0:53
qui il lavoro che facciamo con questo esempio, ma  continuiamo a farci accompagnare dalle strutture.  
0:59
Le vedremo sia in un'ottica diversa oggi, ma le  useremo anche per spiegare dei concetti nuovi  
1:05
che non hanno a che fare con le strutture, ma  che ben si integrano alle strutture stesse.
1:11
Allora, tanto per iniziare, andiamo subito a  introdurre il concetto di typedef. typedef è una  
1:18
delle poche parole chiave del C che non abbiamo  visto. Includiamo stdio. Creiamo la nostra main.
1:31
Bene, noi sappiamo che il C ha dei tipi che  hanno dei nomi. int è il nome di un tipo,  
1:36
e io posso dichiarare una variabile a di tipo  intero, assegnarle 10 e con printf stampare la  
1:44
variabile a. Questo funziona perché il C sa cos'è  a e sa cos'è un intero, int. Io so cos'è un int,  
1:52
cosa mi posso aspettare in diverse piattaforme. E  poi qua, la printf, che è una funzione variadica,  
1:59
cioè che prende un numero variabile di argomenti  (noi ancora questa cosa del C non l'abbiamo  
2:04
studiata, ma ci arriveremo), sa che, siccome io ho  specificato %d, dovrà estrarre dagli argomenti che  
2:11
vengono alla destra un intero. Quindi i tipi  in C hanno un nome ben chiaro e ognuno ha un  
2:20
suo specifico nome. Quindi, io ora compilo  questo programma, lo eseguo e lui scrive 10.
2:29
Bene, ora facciamo un esempio. Io voglio  usare degli interi, però per descrivere  
2:35
uno specifico tipo di intero: i numeri di  errore del mio programma. Per dire, io ho  
2:41
delle funzioni che si chiamano tipo foo. Questa  funzione fa qualcosa e ritorna un errore. Non so,  
2:51
-20 significa un errore in particolare. Ma nella  mia API, nei miei prototipi di funzioni, quando io  
2:59
le dichiaro e così via, voglio che si capisca  che questo intero è in particolare riferito a  
3:07
un numero di errore. typedef in soccorso. In  questi casi, io posso scrivere typedef e poi  
3:17
qua faccio quello che sarebbe una definizione di  una variabile: int error_code. Quindi guardate,  
3:30
se io togliessi typedef, questa è la definizione  di una variabile che si chiama error_code ed è di  
3:36
tipo intero. Se metto a sinistra di quella che  sembra una normale definizione (nome di tipo,  
3:41
nome di variabile) typedef, allora questa si  trasforma in una definizione di un tipo. Cioè,  
3:49
io gli sto dicendo che error_code è un alias di  int, quindi ogni volta che io dovrei scrivere int,  
3:57
posso scrivere error_code ed è uguale. Io  qua posso scrivere error_code foo() che  
4:03
ritorna -20. Poi, anche qua scriverò  error_code. error_code a = foo(). Se  
4:16
compilo questo programma, continua  a funzionare esattamente come prima.
4:22
C'è chi usa le typedef, ma forse in questo  caso sarebbe più il caso di usare una enum,  
4:29
che ancora non abbiamo introdotto ma  che introdurremo. Io vi dico la verità,  
4:35
sono il tipo di programmatore che invece usa  int, i tipi espliciti; non prova a fare questo  
4:43
tipo di documentazione attraverso i tipi  nel caso di tipi semplici (non composti),  
4:48
cioè gli interi. Ma utilizzo, al contrario,  moltissimo le typedef con le strutture.
4:55
Per esempio, se io ho la mia frazione, che  sapete che avevamo fatto: typedef struct { int n;  
5:08
int d; } fract;, cioè il mio numeratore e il  mio denominatore. In questo caso specifico,  
5:15
siccome io ho scritto typedef struct,  attenzione: il nome della struttura andrebbe qui,  
5:24
ma io sto dichiarando la struttura senza darle un  nome. E perché è possibile questo? Normalmente,  
5:30
io posso dichiarare una variabile fract  che è una struttura di questo tipo senza  
5:34
dare un nome specifico a questa struttura.  Nel caso della typedef, in questo caso,  
5:41
io neanche chiamo la struttura in un modo, perché  mi serve solo per dichiarare il tipo. Quindi  
5:48
fract è di questo tipo qua. A questo punto, io  posso benissimo scrivere qui: fract f; f.n = 10;  
6:02
f.d = 20; printf("%d/%d", f.n, f.d);. Compiliamo  questo programma ed ecco qua, la mia frazione.
6:20
Ma guardate, e questo è molto interessante,  perché io altrimenti qua avrei dovuto scrivere  
6:27
struct fract, eccetera, eccetera. Quindi  è più comodo. Diventa questo, guardate,  
6:35
un tipo del C a tutti gli effetti, perché io  lo chiamo per nome ed è un tipo aggregato,  
6:39
quindi non è un tipo base come un  intero, ma ha un suo significato.  
6:45
Addirittura, io posso anche fare: typedef  fract *fractptr;. Quindi, in questo caso io,  
7:04
guardate, se non ci fosse la typedef, avrei  definito un puntatore al tipo fract. Ok,  
7:10
con la typedef invece, fractptr diventa un tipo a  sé, che è un puntatore agli oggetti di tipo fract,  
7:21
alle strutture di tipo fract. Quindi ora  posso dichiarare fractptr fp = &f;. Prendo  
7:30
il puntatore da f. Guardate, in questo fp non ho  scritto l'asterisco, sennò era un puntatore a un  
7:35
puntatore, perché già il tipo in sé, la typedef,  ha definito fractptr come un puntatore. Quindi già  
7:44
qua, in questo specificatore di tipo, c'è tutto  quello che a me serve. E guardate, se io compilo  
7:50
questo programma: my fraction is stored at %p,  fp. Qua è sbagliato, dovrebbe essere struct. L'ho  
8:12
modificato poco fa per errore. Esatto. Guardate,  funziona tutto e ho anche il mio puntatore.
8:21
Tutto ciò è molto interessante perché mi permette  di creare dei tipi opachi in una libreria,  
8:28
che io posso esporre al programmatore che usa  questa libreria in maniera molto, ma molto,  
8:40
chiara e separata dall'implementazione  che ho. E l'esempio più interessante di  
8:47
tutta questa roba qua è proprio  la libreria standard del C.
8:51
Allora, guardate, questo qui in realtà lo lascio  così com'è e questa qui la chiamo stdio1.c.  
8:59
Guardate la libreria per gestire l'input/output  del C, come si aprono i file, come si chiudono,  
9:05
e ora vedremo perché questo concetto della typedef  è centrale. Quindi includo stdio.h, a maggior  
9:13
ragione perché useremo non la solita printf,  ma le funzioni più avanzate. int main(void).
9:21
Bene, io voglio fare un programma che  apre questo stesso file: stdio1.c.  
9:29
Con questo file fa qualcosa. Si fa così. Devo  dichiarare, guardate, un puntatore fp a un file di  
9:41
tipo FILE. Cioè, questo FILE qui non è altro che  una struttura, è typedef-ata, o almeno potrebbe  
9:47
essere implementato in questo modo. In realtà  potrebbe essere una macro, possono fare cose  
9:51
strane sotto sotto, ma la cosa interessante è che,  di fatto, il modo più ovvio per implementarlo,  
10:00
e il modo in cui voi potete implementarlo,  è attraverso una typedef di una struttura.
10:05
Poi io chiamo la mia chiamata fopen, che  quello che fa, praticamente, è di allocare una  
10:09
struttura di tipo FILE e passarmi il puntatore  di questa struttura. Quindi io gli dico fopen,  
10:16
questo file, come si chiama? stdio1.c, con  "r". Guardate, fopen funziona così. In pratica,  
10:24
mi ritorna il riferimento a questo file,  che è una struttura in cui dentro ci sarà  
10:28
il file descriptor, dove siamo arrivati  nella lettura del file, in che modo questo  
10:33
file è aperto (se è in lettura, se anche in  scrittura), e così via. Varie informazioni.
10:40
Quindi poi io dovrò avere una chiamata fclose  corrispondente, altrimenti c'è un memory leak,  
10:46
perché qui ho allocato delle cose e mi sono  anche impegnato con il sistema operativo  
10:51
ad aprire questo file descriptor, e  non voglio che poi si perda e rimanga  
10:56
allocato. Quindi fclose si occuperà  sia di chiudere il file descriptor  
11:01
(che è quel numero che identifica il  file tra il mio processo e il kernel,  
11:06
perché io e il kernel ci mettiamo d'accordo, ma  ci arriveremo). Mi serve la mia chiamata fclose.
11:12
Se per caso il file non c'è, fopen mi ritorna  NULL. Quindi questo fp sarà il puntatore a zero,  
11:22
che è un puntatore speciale in C che  serve per dire "qua non c'è niente",  
11:27
non c'è nessun puntatore valido allocato.  Quindi io posso scrivere qui: if (fp == NULL),  
11:37
printf("Unable to open file"), e ritorno  con un codice di errore. Guardate,  
11:48
ora compiliamo questo programma qua, e  il programma funziona, cioè è riuscito  
11:57
ad aprire il file e chiuderlo. Ma se io qua  indicassi un file che non esiste, cioè stdio2.c,  
12:04
ricompilo il programma e lo eseguo, mi ritorna  questo errore: "Unable to open the file".
12:11
Dopo che io apro questo file, che  ci posso fare di interessante?  
12:17
Guardate, una chiamata abbastanza interessante  è la fread. fread: gli devo passare un puntatore  
12:28
che è il mio buffer (un puntatore di tipo  void, quindi posso passare qualsiasi cosa).  
12:35
Poi gli devo passare una dimensione... o  meglio, la fread è un po' più complicata:  
12:42
gli dico la dimensione dell'oggetto che voglio  leggere e quanti di questi oggetti voglio leggere.  
12:49
Se questo lo metto a 1, gli dico semplicemente il  numero di byte. Se voglio leggere, per esempio,  
12:55
dal disco cinque oggetti che sono di 20 byte  ciascuno, scrivo 5 e qua scrivo 20. Questa è  
13:01
una cattiva API. Bene, memorizziamo tutti questa  cosa come un antipattern. Hanno sbagliato qui,  
13:12
60 anni fa hanno sbagliato. Qua ci andava  solo size, number_of_bytes, whatever,  
13:20
quello che volete. E poi, se uno si deve fare  la moltiplicazione, saprà anche scrivere 5 * 20.
13:27
In realtà, una delle motivazioni per cui questa  API poteva avere in passato un senso era quando  
13:36
i numeri erano a 32 bit o a 16 bit: leggere,  per esempio, 2^16 oggetti di 30 byte ognuno,  
13:47
andavi in overflow e ti dovevi complicare la  vita. È possibile che questa roba qua nasca da  
13:53
questo problema. Quindi, probabilmente,  dovrei rimangiarmi quello che ho detto,  
13:58
ma alla luce della modernità e di  size_t a 64 bit nei moderni sistemi,  
14:04
questa cosa andrebbe probabilmente evitata.  Ecco, bisognerebbe indagare su qual è la  
14:09
storia di questa cosa qui di preciso. E poi  gli dico, alla fine, il puntatore al mio file,  
14:14
perché fread da dov'è che la deve leggere  'sta roba? E poi il ritorno è size_t:  
14:20
quanti byte sono stati letti, o meglio, quanti  oggetti. Vediamo cosa ritorna la funzione:  
14:28
"the number of objects". O se accade un errore  o se è raggiunta la fine del file, il valore di  
14:43
ritorno è zero o uno "short count", cioè ritorna  meno oggetti di quanti io ho chiesto di leggere.
14:52
Quindi io, praticamente, avrò, se non ci  sono errori, sempre un numero positivo.  
14:57
Fino a quando ci sono ancora il  numero di oggetti che io chiedo,  
15:01
avrò questo numero di oggetti. Quando ne  rimangono di meno, ne avrò di meno, e l'ultima  
15:05
chiamata sarà zero perché il file è terminato  e mi segnala la condizione di "end of file".
15:14
Allora, proviamo a usare questa fread.  Io qua creo un buffer di 32 byte.  
15:24
E poi faccio fread(buf, 1, sizeof(buf),  fp). Gli dico: leggimi oggetti di 1 byte,  
15:39
quanti ne entrano nel buffer. Altrimenti, se  restano meno di 32 byte, non me li legge. Vedete?  
15:51
È un'API prona agli errori, fragile. Non mi  piace. Qua: size_t nread;. Il numero che ne  
16:01
ha letti lo registriamo qua. Quindi ci facciamo  scrivere il nostro nread. Veramente sarebbe %zd,  
16:17
nread. Per il size_t, lo specificatore di tipo  dovrebbe essere %zd, se ricordo bene. Vediamo  
16:23
se è vero. Compiliamo. Esatto, abbiamo  letto effettivamente 32 byte dal file.
16:33
Facciamo una cosa: noi avevamo hexdump,  ci eravamo implementati 'sta roba qui,  
16:41
quindi ora io la vado a copiare. Questa funzione  qua l'andiamo a riportare qui. Così io qui chiamo,  
16:55
sul numero di byte che ho letto, hexdump. Quelli  erano gli argomenti: il puntatore buf e il numero  
17:04
di byte che io voglio stampare a schermo con  la nostra hexdump. Ve la ricordate? hexdump,  
17:10
quella che mi faceva il dump sia esadecimale che  leggibile di un buffer qualsiasi. Proviamoci. Qua  
17:19
c'è qualcosa che usavamo noi che io non ho  incluso. isprint... Ah, include .
17:37
Ecco, guardate qui il mio file... ma in realtà 8  per linea sono pochi. Vediamo 16 come diventa. Sì,  
17:51
così va bene. Ehm, beh, ma così io stampo  solo l'inizio del file. Facciamo una cosa,  
18:02
un ciclo. Per ora ci semplifichiamo il ciclo  per renderlo più facile a chi non è abituato  
18:13
a queste cose, e poi lo miglioriamo. Quindi  io dichiaro la mia variabile nread fuori.  
18:22
Qua faccio un while(1). nread = fread(...). if  (nread == 0) break;. Quindi interrompo il ciclo  
18:31
while se la lettura dal file mi ritorna zero.  Altrimenti continuo. Se non ho interrotto il  
18:43
ciclo, cioè significa che sono riuscito a leggere  qualche byte, chiamo di nuovo la mia hexdump.
18:51
Benissimo. Guardate, compiliamo questo  programma e mi fa l'hexdump di tutto il  
18:59
suo stesso sorgente. Si autoanalizza in qualche  modo. Vedete, non è tanto diverso da "hexdump  
19:09
-C stdio1.c", non credete? Beh, questo è  più figo, diciamoci la verità. Guardate,  
19:20
c'ha le lineette, però il nostro programma è  una merdina, piccolo piccolo. Quindi comunque  
19:26
fa una cosa utile. Questo forse è il  primo programma utile che scriviamo.
19:33
Poi vedete, uno, quando man mano nel C si va  implementando dei pezzi, se li porta appresso e se  
19:39
ne frega di andare a cercare la cosa che fa questa  cosa. Alla fine hai la tua libreria, che comunque  
19:46
molto spesso includerai così, in maniera brutale,  e crei software che non hanno dipendenze. Sono un  
19:51
solo file, li compili, eppure sono in grado  di fare delle cose che hanno un certo valore.
19:58
Ma noi ci potremmo chiedere: saremmo in grado  di implementare noi stessi qualcosa di simile  
20:06
a questo, cioè fopen? Se io faccio man fopen,  questa è una chiamata di libreria. Guardate qua,  
20:14
c'è il 3, non il 2, quindi non è una  chiamata di sistema. Questa fa parte  
20:19
della lib del linguaggio C, dello standard. Beh,  in alcuni sistemi embedded magari STDIO non c'è,  
20:31
però in qualsiasi compilatore di un computer  vero c'è STDIO. E quindi, evidentemente,  
20:38
questo STDIO (quindi fopen, fread, fclose),  in realtà sotto sotto chiama le system call,  
20:48
le chiamate di sistema a basso livello del mio  sistema operativo. E il mio sistema operativo,  
20:55
visto che questo è un macOS, tra l'altro  certificato Unix (quindi è uno Unix a tutti gli  
21:00
effetti), deve seguire lo standard POSIX. E quindi  io, seguendo praticamente lo standard POSIX,  
21:08
posso andare a interrogare il sistema operativo e  saltare completamente la libreria standard del C.
21:14
Nella prossima lezione noi faremo proprio questo,  e dopo utilizzeremo typedef e strutture per vedere  
21:21
come possiamo implementare una piccola libreria  di input/output, diciamo, alternativa a quella  
21:28
della libreria standard del C, perché questa  è una cosa molto istruttiva che ci insegnerà  
21:34
qualcosa in più del C. Usciamo, diciamo, dal  gioco che c'è stato fino a questo momento e  
21:42
scriviamo una libreria vera, che non servirà  assolutamente a niente perché abbiamo la libc,  
21:50
bene, ma che servirà a noi per istruirci, per  farci fare un'esperienza di programmazione vera.
21:57
Dunque, alla prossima.

Lesson 18 - My Notes
typedef.c: