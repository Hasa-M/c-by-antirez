Lesson 19 - link: https://www.youtube.com/watch?v=QWLJ7CBAu_I&list=PLrEMgOSrS_3cFJpM2gdw8EGFyRBZOyAKY&index=22

L19 Transcript:
0:41
Beh, questo è un momento importante di questo  corso di programmazione in C, perché questa è,  
0:47
se non erro, la 19ª puntata ed è stato  lungo il percorso che ci ha condotti qui,  
0:54
fino a scardinare per la prima volta i  confini del C stesso e introdurre una  
1:01
parte — quella che sarà una parte consistente  di questo corso nelle prossime settimane,  
1:06
nei prossimi mesi — ovvero la programmazione di  sistema, utilizzando direttamente le chiamate  
1:14
di sistema che offre lo standard POSIX,  quello che definisce lo Unix standard.
1:21
Perché di Unix ce ne sono tanti: Solaris è uno  Unix, macOS è uno Unix, Linux è uno Unix. Sono  
1:28
tre diversi Unix e ognuno avrebbe, se non ci  fosse il POSIX, un diverso set di chiamate  
1:35
di sistema leggermente incompatibili. In  realtà, questi sistemi operativi, grazie  
1:40
alla standardizzazione — che è un processo partito  decadi or sono e che continua oggi (per esempio,  
1:48
macOS è addirittura un sistema operativo  certificato Unix) — hanno un grandissimo  
1:55
numero di chiamate di sistema comuni a tutti  gli Unix, certificati o che tentano di essere  
2:01
compatibili con POSIX. E questo vuol dire  che io posso scrivere molti programmi che  
2:07
girano su tutti questi sistemi operativi senza  tenere conto delle differenze tra i sistemi.
2:14
Poi, in realtà, c'è una parte che va  oltre il POSIX, che non è standardizzata,  
2:18
con chiamate di sistema specifiche per fare  cose evolute che sono proprie di Linux,  
2:24
proprie di macOS, eccetera. Per esempio, la  gestione dell'audio non è standardizzata, ma anche  
2:31
cose a più basso livello. Le API di multiplexing,  quando io voglio ascoltare su diversi file, su  
2:37
diversi socket, se arriva una nuova informazione  o se c'è buffer libero per una scrittura in tanti  
2:46
file descriptor, in tanti socket, in tanti file...  questa cosa io la posso fare in maniera un po'  
2:53
poco efficiente con delle chiamate di sistema  POSIX che sono comuni a tutti questi sistemi,  
2:58
e poi ci sono chiamate specifiche più performanti  che sono diverse da sistema a sistema. Ma la  
3:04
verità è che in un sistema anche complesso e  molto grande come Redis, grazie a POSIX e a queste  
3:10
chiamate di sistema standard di Unix, c'è una  sovrapposizione enorme in tutti i sistemi, e  
3:17
il codice specifico per architettura è minuscolo.  In molti programmi, anche interessanti, è nullo.
3:26
E allora, noi avevamo scritto il nostro  programma xxdump nella scorsa lezione,  
3:32
ma questo programma non utilizzava le chiamate  di sistema, ma utilizzava... com'è che l'avevamo  
3:39
chiamato questo programma? Non era xxdump,  ma era stdio1.c. Utilizzavamo le chiamate  
3:57
della Lib C per fare delle cose che di solito  si dovrebbero fare con chiamate di sistema,  
4:03
se il C non esportasse un piccolo numero di  chiamate di libreria che sono effettivamente  
4:11
utili a fare cose che di solito il C non  potrebbe fare. Vediamo se riesco a pulire  
4:15
questo schermo che fa schifo. O meglio, non è  tanto lo schermo il problema, ma è la webcam.
4:25
Allora, dicevo, in realtà noi siamo riusciti a  scrivere questo programma senza utilizzare le  
4:32
chiamate di sistema, ma semplicemente chiamando  delle funzioni di libreria della Lib C. Quindi  
4:38
queste chiamate non sono parte del linguaggio  C, ma della libreria standard del linguaggio  
4:43
di programmazione C. Uno può anche avere un  compilatore C conforme, però in quasi tutti  
4:51
i sistemi seri uno trova la Lib C. Questa Lib C  ha una parte di roba che è assolutamente lontana  
4:59
dal sistema, cioè dall'accesso a device, file  e quant'altro, ma ha alcune chiamate che in  
5:05
effetti sono dei wrapper alle chiamate di sistema  che poi ci sono sotto ogni sistema operativo.
5:11
Per esempio, un processo in C di solito  viene eseguito nel suo spazio di memoria.  
5:18
Come farebbe ad aprire un file? Il file non  vive dentro lo spazio di indirizzamento che  
5:26
il processo conosce. Vive fuori, da qualche  parte in un device, e ci vuole qualcosa che  
5:33
permetta al nostro programma — che è chiuso  in questa capsula —... lui, il programma in C,  
5:40
pensatelo in termini di macchina di  Turing: può solo leggere e scrivere  
5:47
dalla memoria, ed eseguire dentro questa  memoria delle istruzioni che leggono,  
5:55
scrivono, comparano, fanno salti condizionati,  ma non c'è modo di uscire da questa monade.
6:06
Il sistema operativo, attraverso le chiamate  di sistema, offre un servizio ai processi.  
6:15
Questo servizio può essere del tipo:  "Senti, sistema operativo, per piacere,  
6:19
apri un file per me". Dopo che il sistema  operativo apre questo file, quindi alloca  
6:24
in kernel space una struttura che rappresenta  questo file eccetera, ritorna al processo che  
6:30
ha aperto il file un numero che identifica  quel file per quel processo, in modo che poi,  
6:37
se il nostro processo chiederà altre cose in  relazione a quel file, possa chiamare il kernel  
6:43
ed eseguire una chiamata di sistema dando di nuovo  quel file descriptor, quindi un identificatore.
6:50
Ora, mentre il nostro processo gira  in user space, non in kernel space,  
6:59
non può avere al suo interno una rappresentazione  del file secondo il kernel, secondo il disco,  
7:05
secondo la periferica. Un numero,  però, lo può trattenere senza problemi,  
7:09
può registrare un intero ovunque.  Ci sono gli interi in C. Quindi,  
7:13
il kernel e il processo si mettono d'accordo  sul fatto che certi numeri rappresentano  
7:19
certi file aperti. È questa l'interfaccia.  Questo può sembrare un discorso prolisso,  
7:24
ma credetemi, è fondamentale e si chiarirà  di più proprio nel corso di questa lezione.
7:31
La `fopen` fa da wrapper, ma noi non vogliamo più  il wrapper, vogliamo riscrivere questo programma  
7:38
nei termini di Unix. Allora, le chiamate  di sistema del sistema operativo sono nella  
7:48
sezione 2 del manuale, quindi `man open` mi  farà vedere come funziona veramente la `open`  
7:56
di POSIX. Io posso cercare qua... esatto, "An  open function appeared in Version 6 AT&T Unix".  
8:08
Vediamo quand'è che è stato fatto. Maggio 1975.  Io sarei nato due anni dopo. A questi punti siamo.  
8:22
E noi oggi, 50 anni dopo, andiamo a utilizzare  questa chiamata di sistema in maniera molto simile  
8:29
a come 50 anni fa i pionieri dell'informatica  l'hanno utilizzata. Quindi quando noi facciamo  
8:36
programmazione di sistema con lo standard POSIX,  ci riconnettiamo anche all'informatica ancestrale.
8:44
Allora, guardate come ritorna un intero  la chiamata di sistema `open`. Bisogna  
8:48
includere `fcntl.h`. `int open` prende il path  del file, dei flag e poi anche, potenzialmente,  
9:03
altri argomenti opzionali. Allora, andiamo a  vedere. Vabbè, il path è chiaro: il percorso  
9:09
del file, dov'è il file. Quello che facevamo  con la `fopen`. E questi sono i flag. Allora,  
9:17
i flag che a noi interessano sono per ora  i primi tre. Gli altri sono un po' più  
9:22
complicati e li spiegheremo magari in una  prossima puntata o li potete approfondire  
9:26
nel man page, ma queste sono le cose più  importanti. Io posso aprire questo file  
9:31
in sola lettura (`O_RDONLY`), in sola scrittura  (`O_WRONLY`), o in scrittura e lettura (`O_RDWR`).
9:47
In combinazione con questi flag, facendo il  bitwise OR con la pipe (`|`), posso aggiungere  
9:57
altre opzioni. Questi sono flag, quindi significa  che dell'intero è settato solo un bit, per esempio  
10:04
1, 2, 4, 8, 16, 32, 64, 128 e così via. E  quindi, se io uso il simbolo della pipe,  
10:17
che fa l'OR bit a bit di due numeri, mi si setta  sia l'uno che l'altro, perché l'OR logico vuol  
10:24
dire che saranno settati tutti i bit che ci  sono sia nel primo numero che nel secondo,  
10:29
d'accordo? Quindi, praticamente, se  dopo che ho selezionato, per esempio,  
10:37
`O_WRONLY` seleziono `O_APPEND`, questo mi apre  il file in scrittura ma in modalità append,  
10:46
che significa che ogni scrittura io la appenderò  alla fine del file. Questo è molto interessante,  
10:54
per esempio per implementare un log e in  altri contesti. Ma a noi ci interessa il  
10:59
primo e più semplice flag: aprire  il file in modalità sola lettura.
11:06
Quindi guardate questo programma come  diventa. Allora, `int fd; // file descriptor`.  
11:12
`fd = open("stdio1.c", O_RDONLY);`. Vi  ricordate che il file pointer, che poi  
11:25
alla fine era un puntatore a una struttura,  ritornava `NULL` in caso di errore. Invece,  
11:33
normalmente le chiamate di sistema nello standard  POSIX ritornano -1 per segnalare un errore,  
11:38
specialmente nel caso in cui il valore di  ritorno sia intero, come in questo caso.  
11:45
Siccome non esistono file descriptor minori di 0  validi, -1 è un buon modo per segnalare l'errore.
11:51
Quindi: `if (fd == -1)`. Guardate,  noi qua abbiamo usato la `printf`,  
11:58
ma c'è una chiamata di libreria che  si chiama `perror` in `stdio.h`.  
12:03
Quindi includiamo `stdio.h` (ce l'abbiamo),  `ctype.h` (l'abbiamo), e includiamo `fcntl.h`  
12:11
dove c'è la nostra `open`, e usiamo la chiamata  `perror("Unable to open file");`. Guardate,  
12:22
ora vi faccio vedere che cosa fa questa  chiamata. `return 1;` // ritorniamo un errore.
12:29
Qua facciamo `close(fd);`. Questa è la chiamata  di sistema simile alla `fclose`, ma che è relativa  
12:36
alla `open`. Quindi prende il file descriptor e  chiude un file. Che significa chiudere un file?  
12:41
Ritorniamo a quel discorso che il kernel ci offre  dei servizi. Il processo dice al kernel: "Senti,  
12:47
ti ricordi che tenevi quella risorsa aperta per  me, quel file che noi chiamavamo file numero tre?  
12:55
Guarda, non mi serve più, lo chiudo". Quindi  il kernel si può permettere di deallocare le  
13:00
strutture che aveva utilizzato per tenere traccia  di quel file aperto dal processo. Con `close` noi  
13:07
lo chiudiamo, poi qua scriviamo `return 0;`. In  questo modo, il programma che eseguiamo è solo  
13:12
questa parte qua, perché poi `main` ritorna e il  programma si interrompe. Questo lo teniamo solo  
13:22
perché stiamo facendo questa sorta di traduzione.  Anzi, facciamo una cosa: `cp stdio1.c stdio2.c`.
13:35
Questo qui lo ripristiniamo, chissà, magari  servirà usarlo più avanti. In realtà,  
13:44
compiliamo il due che l'abbiamo copiato. `close`  è in `unistd.h`. Perché non è su `fcntl.h`?  
13:57
Ragioni storiche, anche perché `close`  si usa anche per cose che non sono file,  
14:03
quindi è una chiamata di  sistema profondamente generale.
14:18
L'ho fatta qua su `stdio2.c`. Esatto,  perché il file esiste. Ora guardate,  
14:30
a parte che qua il file lo dovevamo chiamare  `stdio2`, anche qui che apre se stesso. Lo  
14:35
chiamo `stdio3`. Così vi faccio vedere che  cosa fa `perror`, che significa "print error". 
14:43
`Unable to open file: No such file or directory.` Come fa `perror` a sapere qual è l'errore che ha  
14:54
incontrato la `open`? Beh, noi possiamo includere  `errno.h`, che ci dà una variabile globale che è  
15:04
però specifica per ogni thread (quindi in realtà  non ci sono problemi di threading quando si usa  
15:11
`errno`). E questa variabile globale viene  assegnata a un numero che identifica l'errore  
15:20
della `open`. Guardate, vi faccio vedere una  cosa. Dopo che c'è la mia chiamata `open`,  
15:27
prima ancora di controllare `fd`, io scrivo  qua: `errno is...` e stampo questo `errno`.
15:40
Compilo, eseguo. Guardate: `errno is 2`. Se  io faccio `man open` e vado a guardare che  
15:49
errori mi può ritornare la `open`, alla fine  del manuale ci sono tutti gli errori che può  
15:54
tornare. `ENOENT` dovrebbe essere 2. Vediamo  se è vero. Dovrebbe essere proprio così,  
16:05
ma io per non sbagliare mi faccio stampare  sia `errno` che `ENOENT`. Vedete? 2. Quindi  
16:16
mi ha ritornato `ENOENT`. Se invece  il file ci fosse stato, `stdio2.c`,  
16:26
`errno` è settato a zero, non ci sono  errori. La `perror`, in sostanza,  
16:35
stampa prima questo messaggio che noi gli diamo  come unico argomento, i due punti, e poi traduce  
16:42
l'errore che c'è dentro `errno` in una stringa.  È comoda, non mi cambia la vita, ma è comoda.
16:52
Bene, ora noi dobbiamo andare a prendere  questo loop qui e metterlo qui. Eh sì,  
17:06
questo qui lo possiamo cancellare tutto, non ci  serve più a niente. Allora, guardate qui, noi qua  
17:10
lo chiamiamo `buffer`. Quindi, evidentemente,  esisterà una chiamata di sistema di Unix a cui  
17:19
noi possiamo passare un puntatore e, anche se  la chiamata viene eseguita in kernel space,  
17:24
il kernel ha un modo di passare dei byte  dagli indirizzi del kernel al nostro processo  
17:32
che gira in user space e ha un suo spazio di  indirizzi separato. Questa chiamata è la `read`.
17:40
Allora, come funziona la `read`? Mi ritorna  `ssize_t` (quindi `size_t` ma con segno) e  
17:49
prende il file descriptor, il puntatore  al buffer che io voglio venga riempito  
17:56
e il numero di byte che voglio leggere al  massimo. Ma non è garantito che questo numero  
18:01
di byte sia veramente il valore di ritorno.  La `read` ritornerà zero se il file è finito,  
18:08
o ritornerà, non lo so, cinque,  anche se io avevo chiesto 200 byte,  
18:12
se nel file ci sono solo 5 byte. O nel caso di un  socket TCP, quindi di una connessione a internet,  
18:19
può ritornarmi cinque semplicemente perché finora  ha ricevuto solo 5 byte dall'altro computer.
18:28
Quindi questo diventa `ssize_t`, perché deve avere  il segno, dato che `read` potrebbe tornare -1.  
18:37
Come tutte le chiamate di sistema, può  ritornare un valore negativo per segnalarmi  
18:42
un errore. Quindi io faccio `ssize_t nread;`.  `nread = read(fd, buffer, sizeof(buffer));`.  
19:33
Gli mettiamo un po' di spazio per rendere anche  il codice più leggibile, visto che è un esempio.
19:38
`if (nread == 0) break;` 
19:44
`if (nread == -1) { perror("reading  file"); return 1; }`
19:57
Se c'è un errore di lettura, ci facciamo scrivere  che cosa è successo. Se invece il file è finito,  
20:03
usciamo fuori. Altrimenti, `xxdump(buffer,  nread);`. E qua con la nostra chiamata di  
20:09
sistema `close` chiudiamo il file, ritorniamo  dalla `main` e il processo terminerà e verrà  
20:23
distrutto dal sistema operativo. `gcc stdio2.c -o stdio2`
20:30
Ed ecco che il mio programma funziona di nuovo,  ma questa volta non sto usando più le chiamate  
20:38
di libreria di `stdio`. Meglio, lo includo  lo stesso perché sto usando la `printf` per  
20:44
scrivere sullo standard output, e anche quando  vogliamo scrivere sullo standard output il kernel  
20:52
ci deve aiutare. Ma noi, perfino questo, volendo,  potremmo scriverlo con le chiamate di sistema. In  
20:57
questo caso sarebbe troppo complicato perché qua  c'è la formattazione, ma la mia `read` c'è anche  
21:03
nella versione che scrive, si chiama appunto  `write`. E io con la mia `write`, che è questa  
21:08
chiamata di sistema qui, potrei scrivere nel  file descriptor che è collegato al terminale.  
21:15
Quindi tutto si può fare a basso livello,  volendo, ma in questo caso non ne vale la pena.
21:23
Bene, per oggi ci fermiamo qui perché credo che  questa sia una puntata molto significativa. Vi  
21:30
do un compito per casa: leggete le man page  di `read`, di `write` e di `open`. Questa è  
21:42
letteratura informatica, ma è una forma di  letteratura tecnica in cui sono spiegate  
21:49
delle cose: cos'è non-block, i lock, ci sono  richiami ad altre chiamate di sistema. Credo  
22:00
sia molto istruttivo. Magari leggete le pagine  di manuale non di macOS, che sono un po' più  
22:11
scarsette. Leggete quelle di Linux e anche quelle  di POSIX sul sito dell'Open Group. Ecco, trovata.  
22:27
Leggete pure cosa ne scrive chi le standardizza,  
22:33
ma io credo che quelle di Linux in media siano  le man page probabilmente migliori. Ciao raga!



Lesson 20 - link: https://www.youtube.com/watch?v=yKavhObop5I&list=PLrEMgOSrS_3cFJpM2gdw8EGFyRBZOyAKY&index=24

Lesson 20 Transcript:

In questa lezione abbiamo fatto questa cosa  interessante di riscrivere il nostro hexdump  
0:50
attraverso le chiamate di sistema POSIX, quindi  non la Lib C, ma le system call di Unix: open,  
0:59
read, close, eccetera. Giustamente, qualcuno  mi ha fatto una domanda nei commenti del video,  
1:09
dicendo: "Ma quand'è appropriato  utilizzare una tecnica, cioè la Lib C,  
1:16
e quand'è appropriato utilizzare le  chiamate di sistema direttamente?".
1:22
Questa domanda può essere declinata in diversi  modi: qual è la tecnica più veloce tra le due?  
1:28
E così via. Per rispondere a queste  domande in maniera adeguata, intelligente,  
1:37
è necessario prima di tutto capire qual è il ruolo  della Lib C, cos'è che fa questa astrazione del  
1:44
file che ci viene data da essa. Per fare ciò  possiamo fare una cosa molto semplice, tanto  
1:52
per iniziare facciamo un esperimento. Vi faccio  vedere questa cosa qui. Apro il file stdio3.c,  
2:01
includo stdio.h e includo anche unistd.h,  perché ci servirà la chiamata di sistema sleep.
2:15
Questa chiamata, come si capisce dal suo nome,  molto banalmente blocca il processo per alcuni  
2:25
secondi. Allora, facciamo il nostro main,  guardate: sleep(5); return 0;. Compiliamo  
2:37
il programma. Guardate, il processo si blocca per  5 secondi e poi continua. Bisogna notare il fatto  
2:51
che questa modalità di bloccare il processo  è ben diversa da fare tipo un "while(1);",  
2:58
un ciclo infinito o cose del genere, perché in  questo momento il processo non è in alcun modo  
3:08
in esecuzione mentre la sleep è attiva. Com'è  possibile questa cosa? Ci avete mai pensato?
3:14
Beh, questo sistema che io sto utilizzando  è un sistema multitasking, significa che il  
3:20
kernel del sistema può dare tempo di CPU  ai vari processi. Quindi, praticamente,  
3:26
il kernel ha la possibilità di mandare in  esecuzione un processo, metterlo in pausa,  
3:32
dare tempo a un altro processo, rimetterlo  in pausa e così via. In questo modo,   anche se questo sistema avesse soltanto un core  (non è così, ma in generale quando ci sono più  
3:43
processi che core nelle CPU), è possibile lo  stesso che tutti questi processi continuino ad  
3:52
essere eseguiti in maniera concorrente, tutti  assieme. Questo è il multitasking preemptive.
4:00
Ma la cosa interessante del multitasking  preemptive è che esiste un algoritmo dentro  
4:06
ogni kernel che ha questa funzionalità, che si  chiama scheduler. Lo scheduler decide a chi dare  
4:12
tempo di esecuzione tra tutti i processi che  in quel momento vogliono essere eseguiti. Ora,  
4:19
questo scheduler, se a un certo punto un processo  è in una condizione di blocco (per esempio sta  
4:30
leggendo con una chiamata di sistema read;  vi ricordate che abbiamo visto la chiamata   di sistema read?), ecco, mettiamo che la read  viene eseguita su un file descriptor che in  
4:40
realtà è un socket TCP e sta aspettando altri  dati dalla rete. Se questi dati non arrivano,  
4:49
non sono disponibili, il processo non  viene più eseguito, viene messo in stallo,   in attesa, fino a quando effettivamente in quella  connessione non arrivino altri dati e quindi il  
5:02
processo possa essere svegliato, la chiamata  di sistema read possa ritornare e così via.  
5:07
Sleep utilizza un sistema diverso ma è molto  simile, cioè in quel momento il processo va  
5:12
in blocco, non viene più eseguito, quindi viene  messo in pausa e non utilizza nessun tempo di CPU.
5:22
Perché a noi ci serve la sleep  per far vedere come funziona,   da certi punti di vista, la Lib C? Guardate,  io ora scrivo `printf("hello world")` senza  
5:35
l'andata a capo. Ok? Quindi questo qui dovrebbe  stampare nello standard output "hello world",  
5:45
poi aspettare 5 secondi e poi il processo  termina. Ma non andrà così, ve lo dico  
5:50
subito. Guardate invece che succede: prima c'è  l'attesa e solo dopo c'è l'output. Strano, no?
6:03
Il motivo per il quale ciò accade è da  ricercarsi nel fatto che una delle cose  
6:09
che la Lib C implementa nella sua astrazione  di input e output è il buffering. In sostanza,  
6:18
ogni volta che io chiamo la mia chiamata di  sistema, tipo write, io devo andare in kernel  
6:23
space e tornare. Le chiamate di sistema, anche  se nei kernel moderni sono molto più efficaci  
6:29
che un tempo, sono costose. Per cui la Lib C  cos'è che fa? Pensa: "non è che magari questo  
6:40
programmatore o questa programmatrice mi scrive un  byte ogni volta, e io per ogni byte devo chiamare  
6:46
la write?". Cioè, se io avessi scritto, guardate,  questo programma invece di così, avessi scritto:  
6:56
`char my_str[] = "hello world"; size_t len =  strlen(my_str);`. Includiamo string.h, quindi  
7:11
io so qual è la lunghezza della mia  stringa. Vi ricordate come fa, no?   strlen inizia dal puntatore che io gli ho dato a  vedere quanti caratteri ci sono prima del primo  
7:21
byte a zero. E poi io posso fare: `for (size_t j  = 0; j < len; j++) putchar(my_str[j]);`. Questo  
7:41
programma tecnicamente è uguale a quello di  prima, però non usa più la printf, ma usa una  
7:48
funzione molto più di base, la putchar, che può  fare l'output di un solo carattere per volta.
7:55
Ecco, se io qui invece di putchar avessi  `write(STDOUT_FILENO, my_str + j, 1);`. Allora,  
8:17
guardate io qua che ho fatto. Vi ricordate la  chiamata di sistema read? La write è molto simile.   Quindi write, il file descriptor, e ci sono  delle macro definite. In questo caso io il file  
8:30
descriptor del mio terminale non lo devo aprire, è  già aperto. Me lo apre il sistema operativo quando  
8:38
avvia il processo. E questo qui, che probabilmente  vale 1 (probabilmente sono 0 standard input, 1 lo  
8:45
standard output e 2 lo standard error; non credo  che ci sia però una garanzia ufficiale di ciò,  
8:51
quindi uno usa la macro), questo è il file  descriptor aperto per il mio terminale. Qua io,   guardate, prendo il mio puntatore e gli aggiungo  j, quindi vado avanti col mio puntatore a puntare  
9:01
altre parti della mia stringa e faccio  la write per un byte solo. Tutto ciò è  
9:11
esattamente equivalente a ciò che accadeva prima,  ma stavolta funzionerà davvero che io vedo la   stringa prima della sleep. Però, anche se io vedo  la stringa prima della sleep, qui per scrivere  
9:25
'n' caratteri ho usato 'n' chiamate di sistema,  cioè io continuo a chiamare questa write un botto  
9:32
di volte e ciò è lento. È molto lento, perché  la chiamata di sistema ogni volta è costosa.
9:39
Allora la Lib C, quando io invece uso  non questa ma `putchar(my_str[j])`,  
9:53
succede una cosa. La Lib C, invece di chiamare  veramente write (cioè la chiamata di sistema per  
10:00
fare davvero l'output sul file), ogni volta che  io scrivo qualcosa sul file utilizza un buffer,  
10:09
cioè alloca un pezzettino di memoria con  malloc e ogni volta che io scrivo sul file,  
10:16
in realtà sul file non viene scritto niente, ma  viene scritto tutto in questo buffer. Quando poi  
10:22
capita che il buffer si riempie, o se capita per  esempio che c'è una newline a un certo punto...  
10:29
Se io per esempio qua scrivo `putchar('\n')`,  di solito i newline fanno anche da trigger  
10:42
per svuotare davvero il buffer nella write e  quindi scrivere davvero nel file. Vediamo se  
10:48
è il caso. Vedete che ora praticamente viene  scritto prima della sleep, vedo la scritta.
10:59
Beh, il motivo è ovvio. Se io ho un messaggio  e con la printf o un'altra chiamata di libreria  
11:05
scrivo effettivamente un messaggio che ha  la newline, significa che davvero lo voglio   visualizzare subito, e quindi a quel punto il  buffer della Lib C del mio file verrà svuotato  
11:16
davvero sul file fisico, cioè verrà scritto  sul file fisico e verrà resettato l'offset,  
11:22
quindi il mio buffer è nuovamente  vuoto e lo posso utilizzare. C'è anche una chiamata di libreria che  si può utilizzare per forzare questo  
11:33
comportamento. Quindi io qua ho scritto, per  esempio, guardate, qui ho la mia putchar,  
11:38
quindi io ho riempito il buffer della Lib  C e a questo punto chiamo `fflush(stdout)`.  
11:50
Flush significa: io ti do un file, però non  quello di Unix, quello ritornato da fopen,  
12:02
ecco. Quindi ti do un descrittore della Lib C  (FILE*), un handle o come lo volete chiamare,  
12:16
e tu, se ci sono dei dati pendenti che sono stati  scritti ma non li hai ancora scritti dentro il  
12:23
file, fammi la cortesia di scriverli stavolta.  Quindi io prima con putchar (ormai noi sappiamo  
12:29
il comportamento) riempirò solo il buffer.  Quando arrivo qua, il buffer sarà veramente   scritto sul file, su quel famoso STDOUT_FILENO.  E poi c'è la sleep. Quindi il comportamento  
12:43
nuovo del mio programma è: guardate, "hello  world" e poi finalmente il programma termina.
12:50
Tra l'altro, se io qua aggiungo una  sleep anche qua dentro e l'fflush lo  
12:58
metto qua dentro, quindi ogni  volta io scrivo un carattere,  
13:05
forzo la scrittura di questo carattere sullo  schermo e aspetto, si crea un effetto carino  
13:12
in cui io vedo sostanzialmente i caratteri  che appaiono uno dopo l'altro, con lentezza.  
13:20
La sleep è troppo lenta per avere un bell'effetto,  usiamo la usleep. Quindi io qua specifico i  
13:30
milionesimi di secondo, a questo punto, invece che  i secondi. Quindi questo equivale sostanzialmente  
13:37
a 100 millisecondi, che è più interessante.  Esatto. Poi aspetta 5 secondi ed esce.
13:50
Quindi, prima questione che accade quando si  usa la Lib C invece della chiamata di sistema:  
13:58
i programmi scritti così come capita saranno più  veloci grazie all'implementazione del buffering.  
14:05
Anche se i programmi scritti con la massima  efficacia in mente, usando le chiamate di  
14:11
sistema, saranno ancora più veloci (perché tu ti  implementi il tuo buffering per come ti serve,  
14:16
non quello della Lib C), ma in generale la Lib C  è più veloce. Questo buffering viene utilizzato  
14:23
anche in lettura. Quindi quando io, per dire, uso  delle chiamate della libreria C che leggono per  
14:31
esempio una riga intera ogni volta dal file...  ecco, io questa capacità, per esempio di leggere  
14:38
a righe, non ce l'ho con le chiamate di sistema.  Le chiamate di sistema sono brutali: questo è il   file descriptor, questo è il mio buffer, leggi 'n'  byte. Fine. Invece c'è la `fgets`, questa chiamata  
14:52
di libreria legge una linea intera. La lettura  si ferma al primo carattere newline incontrato  
15:04
(sempre se la size è sufficiente per la lunghezza  della riga), o alla fine del file, o se c'è un  
15:12
errore. Quindi questa qui è, in sostanza, una  read di più alto livello che legge dal mio file.  
15:24
Questa chiamata di sistema, siccome si basa  sull'implementazione dei file della Lib C,  
15:33
utilizza il buffering, quindi sarà più veloce  rispetto, per esempio, a una modalità di lettura  
15:41
banalotta in cui, per dire, io inizio a leggere un  carattere dopo l'altro facendo una read (proprio  
15:47
una chiamata di sistema read) in cui leggo ogni  volta un solo byte, aspetto il newline, mi fermo,  
15:57
e man mano che leggo accumulo in un buffer,  eccetera eccetera. Quindi un'implementazione   "cattiva" delle stesse cose che fa la Lib C sarà  più lenta della Lib C. La Lib C ci dà questa,  
16:09
diciamo, minima garanzia di performance, di non  fare le cose proprio in maniera a basso livello.
16:16
E c'è di più. Un sacco di programmi abbastanza  interessanti e utili si possono scrivere con la  
16:25
Lib C ed essere portabili. Quindi io questo  programma che scrivo, questo programma qui,  
16:35
se io gli tolgo la sleep... ecco, vedete, già  anche la sleep per esempio è in unistd.h e quindi  
16:40
non è parte del C. Se io tolgo questa sleep, a  questo punto questo programma è un programma in  
16:49
C, in ANSI C, che è lo standard del C, e quindi  io lo posso compilare su Linux, su Windows. Se  
17:01
c'era un compilatore di un computer vecchio, per  esempio l'Amiga aveva un buon compilatore C, lo  
17:07
posso compilare su Amiga, anche se è un hardware  di 30 anni fa, e ancora il programma funziona  
17:14
perfettamente. Quindi, se uno può utilizzare la  Lib C perché deve scrivere, vi faccio un esempio,  
17:21
un'utility che non è necessario che sia la più  veloce del mondo, che legge un file audio e mi  
17:29
dice, per esempio, qual è il volume medio di  questo file wave... se io lo scrivo utilizzando  
17:37
solo ed esclusivamente la Lib C, tanto poi nella  Lib C ho l'input/output e posso leggere il file,  
17:42
c'ho math.h con le funzioni matematiche che mi  servono per calcolare, non lo so, la deviazione  
17:52
standard, il valore assoluto, quello che mi serve.  Quindi perché scrivere in tal caso un programma  
18:01
che non sarà portabile? È molto interessante  invece mettere questo programma su GitHub e dire:  
18:07
"su qualsiasi sistema che ha un compilatore ANSI  C vi serve solo scrivere `gcc nome_del_file.c`".
18:16
Tuttavia, le cose avanzate non si possono fare  senza andare a scavare invece nella Lib C, verso  
18:29
le chiamate di sistema. Da questo punto di vista  volevo introdurre un concetto molto affascinante,  
18:37
avanzato, ma che mi sembra veramente  importantissimo. Noi abbiamo detto che  
18:43
il processo non può dialogare col mondo esterno  se non chiede aiuto al kernel. E abbiamo visto  
18:51
che la modalità normale di dialogo col mondo  esterno è chiamare delle chiamate di sistema.  
18:57
In realtà, però, il processo ha un'altra  possibilità di parlare con l'esterno,  
19:04
utilizzando il fatto che può  leggere e scrivere da memoria.   Una volta nei computer vecchi o nei computer  embedded, tipo nelle MCU come Raspberry Pi Pico,  
19:18
l'RP2040, questi piccoli microcontrollori  utilizzano ancora, così come lo utilizzava  
19:25
il Commodore 64 o l'Amiga, il memory mapping.  Ovvero, ci sono delle locazioni di memoria che,  
19:31
invece di essere davvero memoria, uno scrive in  quelle locazioni per scrivere a un device fisico  
19:38
esterno, quindi a un altro integrato, un  altro chip, e legge per leggere da quel chip.
19:46
Anche se sono passati così tanti anni,  questa tecnica è ancora utile e c'è una   chiamata di sistema POSIX, `mmap`, che può  mappare il contenuto di un file nello spazio  
20:03
di memoria del processo. A quel punto, io  per leggere e scrivere il file non ho più  
20:09
bisogno delle chiamate di sistema, ma posso  accedervi tramite un puntatore. Siccome il  
20:14
C è un linguaggio a basso livello che coi  puntatori può fare il cappero che gli pare,  
20:20
qualsiasi cosa, capirete che la `mmap` è  molto potente in relazione al linguaggio C.
20:27
È una chiamata di sistema un po' complicata, ma  in realtà neanche tanto. Allora, guardate, nella  
20:35
`mmap` io gli dico quale indirizzo desidererei  per la mappatura, in quale indirizzo di memoria  
20:45
venisse effettuata la mappatura. Ma poi in realtà  non è detto che questo indirizzo sia disponibile,   quindi la mappatura che `mmap` mi dà, l'inizio del  mio indirizzo, l'inizio della mappa in memoria,  
20:59
qual è l'indirizzo base, me lo dà col valore  di ritorno di `mmap`, ma io posso chiederne uno  
21:06
in particolare o qua credo che posso mettere  anche NULL. Poi gli dico qual è la grandezza  
21:14
in byte di questa mappatura tra memoria e file  che io voglio, il tipo di protezioni, i flag,  
21:22
il file descriptor e a quale offset del file  deve avvenire questa mappatura. Quindi se è 0,  
21:29
sin dall'inizio del file, altrimenti gli posso  dire: "da byte 1000 fammi questa mappatura".
21:36
Andiamo a vedere gli argomenti di `mmap`.  L'argomento `addr` è utilizzato dal sistema  
21:45
per determinare l'indirizzo di partenza della  mappatura e la sua interpretazione dipende dal  
21:55
settaggio di `MAP_FIXED`. Se `MAP_FIXED` è  specificato nei flag, il sistema tenterà di  
22:02
piazzare la mappatura all'indirizzo specificato,  possibilmente rimuovendo una mappatura che  
22:10
esiste già in quella locazione se avevo chiamato  `mmap` prima. Se `MAP_FIXED` non è specificato,  
22:17
allora il sistema tenterà di usare il range  specificato dall'indirizzo che io do, quindi  
22:23
è solo una desiderata. Se non c'è un overlap  con una mappa precedente, incluse le mappature  
22:31
che può ovviamente creare malloc (perché `mmap` è  molto complicata semanticamente, si può usare sì  
22:38
per vedere in uno spazio di memoria il contenuto  di un file, si può usare anche per allocare nuove  
22:44
pagine di memoria a specifici indirizzi, quindi  la malloc può utilizzare `mmap` come allocatore di  
22:53
livello basso per allocare pagine di memoria),  altrimenti il sistema sceglierà un indirizzo  
23:06
diverso per la mappa e lo ritornerà come valore  di ritorno. In altre parole, senza `MAP_FIXED`,  
23:15
se il range specificato è già utilizzato, tenterà  di utilizzare un altro indirizzo. Se l'indirizzo è  
23:22
zero (quindi il puntatore NULL) ma `MAP_FIXED`  non è specificato, allora l'indirizzo sarà  
23:27
selezionato dal sistema in automatico, in modo  da non avere nessun overlap, eccetera eccetera.
23:33
Queste sono invece le protezioni, quindi il  tipo di accesso: nessun tipo di accesso, read,  
23:41
write, execute. In base al fatto che di solito un  range di memoria può essere o letto o scritto o  
23:48
eseguito. Queste sono, diciamo, le capacità che di  solito il processore ha rispetto a un determinato  
23:56
indirizzo di memoria. Poi ci sono processori  che hanno addirittura delle funzioni ancora più  
24:02
specifiche e più sottili, ma storicamente queste  sono le modalità in cui si può accedere alla  
24:08
memoria: in lettura, in scrittura o in esecuzione.  Invece ci sono dei sistemi che hanno delle   limitazioni e alcuni ti dicono: "guardate che in  alcune piattaforme se tu hai accesso in scrittura  
24:19
lo hai anche in lettura". Anche la lettura  può implicare che tu puoi eseguire da quegli  
24:25
indirizzi, eccetera eccetera. In realtà i sistemi  moderni di solito hanno questa granularità.
24:32
Andiamo invece al tipo di mappa possibile, quindi  queste sono le protezioni. `MAP_ANONYMOUS` o  
24:39
`MAP_ANON`: memoria non associata a nessun  file specifico. Quindi io posso creare anche  
24:46
una mappa che non è effettivamente legata a  un file, l'abbiamo detto. Ma noi oggi invece  
24:53
vogliamo `MAP_FILE`. Questo l'abbiamo visto.  Va bene. Poi ci sono altre cose più complicate,  
25:02
se le modifiche sono o meno davvero  scritte sul file se io scrivo nel  
25:10
puntatore che mi è ritornato da `mmap`, ma oggi  noi utilizziamo solo `mmap` in modalità read-only.
25:20
Allora, proviamoci 'sta roba qua.  Includo `sys/mman.h` (memory management).  
25:37
`string.h` non mi serve. `stdio.h` ce lo  teniamo. Includo `fcntl.h` (file control)  
25:48
per usare la open, perché a me  serve il file descriptor. Vabbè,   dovrebbe essere abbastanza. Quindi, per dire, qua  io eviterò anche di avere il test sul descrittore,  
26:02
se il file è stato aperto o no, fidiamoci.  Così questo esempio lo rendiamo più facile.   Quindi `open("stdio3.c", O_RDONLY)`. Ci  fidiamo del fatto che il file esista.  
26:15
Mi ero dimenticato la O, per questo non vedevo...  ah no, l'highlighter se ne fotte lo stesso. Vabbè,  
26:23
qua il file ce lo possiamo anche far  scrivere. "Open file descriptor: %d\n", fd.
26:34
Ecco, il file è 3 perché 0, 1 e 2 sono già  utilizzati: standard input, standard out,   standard error. Il numero 3 è il primo file  descriptor disponibile. Vi voglio far notare una  
26:46
cosa: se io eseguo di nuovo questo programma,  è sempre 3, perché quando il processo viene   terminato tutti i file vengono chiusi, tutte le  socket vengono chiuse, tutto viene chiuso, viene  
26:55
distrutto tutto. Ci sono solo rarissime cose,  rarissime chiamate di sistema che un processo  
27:02
può eseguire che hanno effetti che poi, diciamo,  si propagano. Di solito tutto viene azzerato,  
27:08
tutto viene chiuso, sennò sarebbe un casino:  ogni bug in un processo significherebbe poi  
27:13
che il kernel si ritrova con file descriptor  aperti di processi che sono morti. Un disastro.
27:21
Ora che io c'ho... boh, "Open file descriptor".  Vai, teniamocela 'sta cosa. Allora, la mia `mmap`:  
27:36
`void *mem = mmap(...)`. Address: noi gli  diciamo NULL, se la vede lui. `len`: 100 byte.  
27:49
Non so se questo qua deve essere un multiplo della  grandezza della pagina... "if offset or length is  
27:54
not a multiple of the page size, the mapping may  be extended to a page boundary". Vabbè sì, cioè  
28:02
dovevo utilizzarlo, altrimenti mi fa l'estensione  lui. Vabbè, in realtà mapperà tipo 16k. Avrò  
28:11
una mappa di 16K e quello che mappa oltre il  file saranno tutti zero, credo. `protection`:  
28:18
andiamo alla protection, `PROT_READ`. `flags`:  `MAP_FILE | MAP_SHARED`. `descriptor`: fd,  
28:39
perché è la mia variabile qua. `offset`:  0. `printf("File mapped at %p\n",  
28:51
mem);`. Vediamo se funziona. Se mi è ritornato  NULL... e infatti c'è qualcosa che non va.
29:00
Allora, vediamo subito. `printf("%c\n",  ((char*)mem)[0]);`. Vediamo se c'è un  
29:11
carattere leggibile. Faccio il casting  del puntatore a carattere e mi prendo il  
29:29
primo byte. Segmentation fault. No, la mia  `mmap` ha ritornato errore. Vediamo perché.  
29:47
Forse io devo specificare per forza, per esempio,  questo... ma io in realtà voglio `MAP_SHARED`,  
29:56
non qui. Esatto, ora funziona.  Ora funziona perfettamente.
30:07
Tuttavia, vorrei capire una cosa. Attenzione  che praticamente quando c'è un errore,  
30:14
la `mmap` non ritorna NULL, ma ritorna  `MAP_FAILED`. Per questo noi abbiamo visto  
30:21
questo strano indirizzo che è praticamente la  fine del mio spazio di indirizzamento. Guardate,  
30:32
questo numero qui è lo stesso di 2^64 - 1, quindi  è l'ultimo byte nel mio spazio di indirizzamento  
30:45
del processo. Questa cosa qua perché è così?  Io non lo so, ma voglio vedere se Gemini lo sa.  
30:57
Perché `mmap` non ritorna NULL ma ritorna 'sta  roba qui? Perché NULL, comunque, non è che  
31:07
non sia un puntatore valido da cui far iniziare,  o ci sono delle situazioni in cui io voglio che la  
31:13
mia memoria sia mappata da zero? Eh sì, vogliono  che sia possibile mappare anche il puntatore NULL,  
31:24
quindi fare una mappa che inizia da zero. Chissà,  forse in casi particolari può essere utile.
31:36
Abbiamo scoperto anche questo. Quindi,  praticamente, ora vi faccio vedere che  
31:42
noi possiamo accedere a questo file attraverso  il puntatore, il che è veramente una figata  
31:47
bestiale. Quindi io uso un puntatore di tipo  char che chiamo 's' e ci assegno 'mem'. Tanto  
31:54
sempre indirizzi di memoria sono, ricordatevelo.  E `void*`, siccome è un indirizzo di memoria non   tipizzato, qua io non avrò nessun warning,  posso fare ciò che voglio. Ora faccio un  
32:03
ciclo for in cui faccio: `for (int j = 0; j  < 10; j++) printf("s[%d] = %c\n", j, s[j]);`.  
32:24
Così mi spunta s[0], s[1], s[2] e  quello che c'è effettivamente in `s[j]`.
32:33
Compiliamo ed eseguiamo. Vedete, questo  è praticamente ormai un array in memoria:  
32:41
`#include`, vedete l'include che c'è all'inizio  del file. Questi sono i primi byte del file.
32:48
Ora vi svelo un segreto. L'utilizzo accorto  di `mmap` consente di scrivere i programmi più  
32:56
veloci possibile per interfacciarsi  coi file. Ci sono un sacco di cose  
33:04
che bisogna sapere di questo approccio,  specialmente quando si usa in scrittura,  
33:09
perché guardate che succede: in pratica, l'unità  di gestione della memoria (MMU) della CPU sa che  
33:17
quella lì è un'allocazione speciale e si mette  d'accordo col kernel che, quando c'è un accesso,  
33:23
il kernel viene svegliato e allora: "ah, mi  si sta accedendo a questo spazio di memoria".  
33:29
Il kernel effettivamente va a leggere dal  dispositivo e copia quel contenuto del file,   tutta la pagina che era all'interno di  quell'indirizzo a cui ho avuto accesso,  
33:42
la copia dal file alla memoria del mio processo.  E avviene anche il contrario. A un certo punto,  
33:52
se io scrivo nella pagina di memoria (che è né più  e né meno, a quel punto, un pezzo di memoria del  
33:58
mio spazio di indirizzamento del processo), a un  certo punto io posso chiedere con una chiamata di  
34:03
sistema diversa dalla `mmap` che quello che  c'è di scritto venga effettivamente scritto  
34:11
dentro il file. A volte lo può fare il kernel  automaticamente per le pagine che si chiamano  
34:17
"dirty", che sono sporche perché ancora non  sono state davvero finalizzate nel file,   di passarle nel file. Altre volte, praticamente,  devo chiederlo io se voglio che venga effettuata  
34:27
questa operazione di scrittura nel file dalla  memoria immediatamente. Ma capirete che io,  
34:32
senza chiamate di sistema, posso scrivere un botto  di cose in questo file che è mappato in memoria  
34:38
e poi con una chiamata di sistema singola dire  al kernel di trasferire le scritture, eccetera.
34:44
O sennò, immaginate per esempio l'implementazione  di `grep`. `grep` è quel comando Unix che  
34:53
io posso utilizzare per esempio per cercare  dentro diversi file se c'è una data stringa.  
35:05
Se io implemento `grep` col memory mapping, beh,  c'ho praticamente la possibilità di utilizzare una  
35:14
programmazione anche più libera, perché non devo  fare `read`, non devo fare il buffering... no,  
35:19
io accedo a un puntatore, vedo tutto il mio  file, cerco con l'algoritmo più figo che  
35:25
posso utilizzare dove sono le mie occorrenze  e così via. Quindi a volte `mmap` può essere  
35:30
anche utilizzata come semplificazione di  un'implementazione di un programma. Quindi  
35:37
allo stesso tempo diventa più semplice e più  veloce. Insomma, è una tecnica di programmazione   evoluta e molto potente. Tra l'altro, è una di  quelle cose che non vedrete mai se programmate,  
35:48
non lo so, in Python o in JavaScript. È  raro che ci si imbatta in cose del genere,   quindi mi sembra molto interessante da  far vedere in questa programmazione C.
35:58
Vabbè, siamo andati per le lunghe,  abbiamo toccato argomenti complessi,   comunque spero che sia stato utile.
