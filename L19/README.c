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
