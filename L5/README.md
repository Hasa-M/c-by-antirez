Lezione 5 - link: https://www.youtube.com/watch?v=SWWHqgSwQFw&list=PLrEMgOSrS_3cFJpM2gdw8EGFyRBZOyAKY&index=6

Transcript:
0:00
Bene, bene, bene. Ci addentriamo in uno  dei, diciamo, un po' nelle complicazioni  
0:07
e nelle peculiarità del C. Andiamo a  vedere le cose di cui veramente è fatto,  
0:12
perché finora abbiamo visto i tipi,  abbiamo visto la struttura sintattica  
0:17
dei programmi. Ora dobbiamo fare un salto  in là. Chiamiamo questo programma string.cc.  
0:23
Ripartiamo dal nostro Hello World, che  ci serve la sua struttura. Hello World.
0:37
Allora, tanto per iniziare, vi volevo far vedere  una cosa. Noi abbiamo visto che la printf,  
0:44
come primo argomento, prende una stringa di  formato dove ci sono dei caratteri che vengono  
0:50
stampati così come sono. Poi ci possono essere  dei segnaposto, chiamiamoli speciali, che iniziano  
0:58
con la percentuale e poi una o più lettere,  diciamo, con dei simboli che indicano cosa,  
1:06
cos'è che daremo poi alla printf come argomenti e  cosa la printf deve stampare per voi. Ricordate,  
1:14
se facciamo printf("hello world %d", 10),  la printf si aspetta che può prelevare  
1:20
dagli argomenti che abbiamo dato alla printf un  intero e può stamparlo. Quindi noi ora facciamo  
1:29
cc string.cc. Di solito dovremmo fare, anche  aggiungere, delle opzioni come abbiamo visto. Con  
1:36
questi semplici programmi, se noi li aggiungiamo,  pazienza, non ci beccheremo i warning.  
1:41
A voi vi consiglio di aggiungere almeno queste  due, perché se avete sbagliato qualcosa il  
1:45
compilatore vi avvisa. Eh, infatti, mi avvisa  anche a me, perché qua doveva essere return 0.
1:56
Eseguiamo il nostro eseguibile, che si chiama  a.out. Nei sistemi Unix, di solito. In altri  
2:02
sistemi, con altri compilatori C, l'eseguibile  si può chiamare in una maniera diversa,  
2:06
ma non importa. Hello world 10. Ora, mh, c'è un  modo diverso per esprimere i numeri in C. Allora,  
2:15
tanto per iniziare, vi ricordo che se noi  facciamo un numero, dichiariamo un numero più  
2:21
piccolo di un int, se io qua scrivo 'C', nelle  funzioni con un numero di argomenti variabile,  
2:33
eh, i char vengono promossi al tipo intero, così  come gli short. Quindi questo qui continuerà a  
2:40
funzionare. Continuerà a funzionare. È "Hello  World 10". Ma c'è un modo diverso di poter  
2:48
indicare gli interi di tipo char: con gli apicini.  Questo qui è un intero di tipo char. Voi direte:  
2:56
"Ma come? Questa è una stringa che invece di usare  le virgolette utilizza gli apici singoli?". E non  
3:04
è così. Questo è vero in Python, per esempio. In  Python, io posso scrivere print 'ciao' e funziona,  
3:11
e posso scrivere print "ciao" e funziona pure. In  C, gli apici possono contenere solo un carattere  
3:19
singolo, e questo carattere che è dentro gli apici  verrà espanso a un numero che rappresenta, eh, la  
3:32
posizione di quel carattere nello standard ASCII,  diciamo. Quindi ASCII mappa ogni carattere a un  
3:43
numero. Eh, quindi, per i sistemi che utilizzano  l'ASCII, praticamente quasi tutti per fortuna, a  
3:50
questo punto potete aspettarvi una corrispondenza.  Poi, se inserite dei caratteri dentro gli apici  
3:56
che sono fuori dall'ASCII, mapperà ad un  byte che è specifico per l'architettura,  
4:01
ma non capita mai, diciamo, di andare di solito  fuori dal seminato, quindi atteniamoci all'ASCII.  
4:09
Eh, però possiamo poi fare pure una prova. Allora,  guardate questo qui. Allora, la 'A' maiuscola,  
4:15
molti di voi, eh, ricorderanno che è 65.  Guardate qui, infatti, eh, 'decimal set',  
4:25
la 'A' maiuscola è 65, e infatti funziona  perfettamente. Per vedere in realtà quella  
4:33
cosa che vi ho detto... Non so se sapete che su Y  premete Ctrl+V e poi, che ne so, Ctrl+A, gli state  
4:42
dicendo che avete messo un carattere verbatim,  cioè il prossimo carattere non sarà interpretato,  
4:48
ma proprio leggerà dalla tastiera in 'raw' cos'è  che scrivete e lo inserirà così com'è. Infatti, ho  
4:56
messo, per esempio, Ctrl+A, che dovrebbe mappare  a un numero molto basso, infatti mappa ad uno.  
5:06
Questo byte è il byte 1. Altri caratteri possono  mappare ad altre cose diverse. Quindi quelli  
5:13
che voi vedete dentro gli apici sono pur sempre  interi. E qui iniziamo a vedere come il C, sotto  
5:20
sotto, gestisce solo ed esclusivamente numeri,  anche quando si parla di stringhe. Questo qui,  
5:26
quindi, è un tipo letterale del carattere, così  come questo è un tipo numerico che è un intero,  
5:32
così come questo è un tipo numerico che è un  float. Sono tutti tipi letterali, cioè significa  
5:38
che in un dato linguaggio di programmazione un  tipo letterale è un tipo di dato che ha proprio  
5:43
una sintassi con cui si può scrivere, dentro il  linguaggio di programmazione, per avere un dato  
5:49
tipo. Vi faccio un esempio. Io, in un, per dire,  potrei avere un linguaggio di programmazione dove  
5:54
io posso scrivere a = 1, b = 1.5, magari un  linguaggio di programmazione ad alto livello,  
6:00
ma dove non c'è una sintassi per scrivere le  liste, gli array. Cioè, non posso scrivere così.  
6:06
In questo caso, se manca un tipo letterale, magari  ci sarà una funzione che si chiama 'array' dove io  
6:12
passo degli argomenti per fare dei tipi letterali,  e gli array 'nested' si faranno così. Quindi non è  
6:18
che ogni tipo che un linguaggio di programmazione  supporta debba avere necessariamente un  
6:23
tipo letterale. Il C ha pochissimi tipi  letterali: il carattere è uno di questi,  
6:30
la stringa è un altro. Ecco, ora, una cosa molto  interessante è questa, che io, tanto per iniziare,  
6:39
ecco, vi voglio far vedere un'altra cosa. Il  nostro Hello World potremmo scriverlo così:
6:47
Questo è sempre il primo argomento, specifica  esattamente ciò che noi vogliamo che la printf,  
6:53
eh, abbia come output. %s stampa una stringa.  Infatti noi, come secondo argomento, cosa gli  
6:58
abbiamo passato? Una stringa, perché il C ha come  tipo letterale anche la stringa. Compiliamo questo  
7:05
programma, lo eseguiiamo e, infatti, vediamo Hello  World, né più né meno come prima. Ma, visto che  
7:13
ora ce l'abbiamo, però, eh, qua dentro io posso  scrivere anche, per esempio, che la stringa la  
7:19
voglio tra parentesi quadre, e lui me la stampa  tra parentesi quadre. Tra l'altro, se vi chiedete,  
7:26
qua avevo dimenticato il new line, o meglio, il  new line avrebbe più senso metterlo in questo  
7:31
caso, esatto, una stringa di formato, perché io  non lo voglio qua dentro. Eh, quando non c'è il  
7:37
new line, la shell che sto utilizzando io, che è  Z Shell (cosa che si può vedere, echo $0, uno vede  
7:44
che shell sta utilizzando in un dato momento),  ehm, per non farmi spuntare poi il cursore qui,  
7:51
praticamente alla fine dell'esecuzione del  programma, mi segnala che comunque il new  
7:56
line manca e mette un invio da sola. Ora che  io ho messo l'invio, funziona in maniera più  
8:03
sensata. Bene, la printf, in realtà, ha anche la  possibilità di stampare %c, il carattere. Cioè,  
8:14
se io gli scrivo qui 65, glielo do intero, il  carattere, quindi come un numero intero, compilo  
8:22
il mio programma, pulisco lo schermo, così è più  chiaro l'output, e vedo proprio la 'A'. Quindi,  
8:29
guardate, io posso fare %c %c %c %c e scrivere  65, 66, 67 e 68. Compilo questo programma  
8:43
e quello che vedo è A B C D. Questo è abbastanza  ovvio. Ma così come, eh, gli do, eh, i codici  
8:50
direttamente ASCII, io gli posso dare anche un  carattere come, eh, tipo letterale, quindi apice  
8:59
'X' apice. Questo sarà la stessa cosa di scrivere  il codice ASCII della X. Infatti qua vedo X A XCD.  
9:11
Benissimo. Allora, a questo punto, proviamo a  fare un salto e introduciamo gli array. Quindi,  
9:19
io vi ho fatto vedere poco fa, nella scorsa  lezione più che altro, che se scrivo int a;  
9:25
ho una variabile intera, poi posso scrivere  a = 10; printf("%d\\n", a);. Compilo questo  
9:37
programma, lo eseguo e mi scrive 10, perché ho  dichiarato una variabile intera che si chiama A,  
9:45
ho assegnato ad A il valore di 10 e la faccio  stampare. Ma questo A potrebbe essere anche un  
9:51
array. Per esempio, dichiaro un array di cinque  elementi e, eh, poi si usano le parentesi graffe  
10:00
per inizializzare l'array ai valori che  io voglio. Gli metto 10, 5, 50, 107...
10:12
A questo punto mi faccio stampare a[0], che  sarebbe 10. Come vedete, la sintassi per  
10:20
l'indicizzazione degli array è comune ai linguaggi  di programmazione che sono venuti dopo il C e al  
10:27
C. Invece, questa potrebbe essere meno ovvia.  L'inizializzazione degli array si fa con le  
10:33
parentesi graffe. Credo che negli altri linguaggi  di programmazione, di solito in quelli ad alto  
10:37
livello, non è quasi mai così. E questo perché?  Allora, torniamo un attimo qui. I linguaggi, i  
10:45
progettisti dei linguaggi che sono venuti dopo il  C, hanno capito che dovevano unificare una cosa,  
10:51
cioè: se io l'array lo dichiaro così, e io  l'array lo indicizzo così, e allora l'array,  
10:57
magari il tipo letterale dell'array, usa  la stessa convenzione, è più sensato, no?
11:11
Infatti mi stampa 10. A questo punto, io potrei  far stampare altri due elementi, a[1] e...
11:16
a[2]. 10, 5, 50. Ci siamo capiti. Bene. In C  le stringhe non sono altro che array di tipo  
11:30
char. Guardate, dichiaro un array str (perché è  una stringa) di sei elementi e gli assegno 'H',  
11:46
'e', 'l', 'l', 'o', e alla fine ci metto  uno 0. Quindi questi saranno gli interi  
11:57
che indicano le lettere H, e, l, l, o,  e poi c'è zero. Come vedete, sono sei,  
12:05
incluso lo zero. E poi qui vado a utilizzare per  stampare la stringa proprio lo specificatore %s,  
12:14
che è quello che si utilizza per le stringhe,  come abbiamo fatto poco fa per Hello World.  
12:19
Guardate che succede. Ora mi stampa effettivamente  "hello". Se io dimentico di mettere lo zero,  
12:27
e invece dello zero metto un punto esclamativo,  è probabile che vedrò un po' di schifo. No,  
12:34
siamo stati molto fortunati perché, guarda  caso, la memoria dopo questi byte era a zero,  
12:43
settata a zero. Ma se così non fosse stato,  io avrei visto altri caratteri strani dopo,  
12:50
perché sostanzialmente lo zero, che si chiama  il terminatore NUL, indica al C quand'è che  
12:57
la stringa è finita. Perché io, in C, visto che,  guardate, la stringa in C è una sequenza di byte  
13:06
dove non c'è alcuna intestazione, non c'è scritto  quanto è lungo quello che seguirà, nulla. Quindi,  
13:11
come fa il C a sapere quando finisce la stringa?  Beh, l'unico modo è trovare un carattere speciale.  
13:17
Questo carattere speciale è lo zero. Infatti,  vi sarà magari capitato in passato di avere a  
13:23
che fare con delle librerie, anche di linguaggi  ad alto livello, che se gestivano magari delle  
13:30
stringhe o dei blob binari, appena c'era uno  zero in mezzo (specialmente capitava anni fa,  
13:37
ora le cose sono state migliorate), non  funzionavano più e troncavano l'output al  
13:43
primo byte zero. Che non è zero come carattere, è  un'altra cosa. Ok, da questo zero... io questo qui  
13:52
lo posso compilare... Ah, mi dice che ho messo più  elementi di quelli che ho nel... Ce ne vogliono  
13:59
sette. A questo punto, ovviamente, vedrò lo zero  e poi si ferma, perché questo zero non è zero,  
14:05
nella tabella ASCII lo '0' è 60 in ottale, 48 in  decimale. Quindi c'è bisogno, eh, che la stringa  
14:19
termini in qualche modo, e quindi questo è il null  terminator, terminatore nullo. Eh, avete visto,  
14:27
sostanzialmente, noi abbiamo scoperto una cosa  molto interessante: che la stringa nient'altro  
14:32
è che un array di interi, e di interi di tipo  char, che sono interi di 8 bit, eh, ciascuno,  
14:44
quindi che possono contenere un valore... siccome  non è unsigned char ma è solo char, quindi da -128  
14:51
a +127. Non a caso, se andiamo a guardare nel  decimale, eh, lo standard ASCII è definito fino  
15:01
al carattere 127, e lo zero è proprio questo NUL  di cui abbiamo parlato. Bene, in questa lezione  
15:09
abbiamo fatto un progresso molto significativo  nel capire che cos'è che sono le stringhe in C:  
15:16
sono array di interi. Eh, questi interi sono  di solito grandi, eh, un byte, perché dipende  
15:24
dal tipo char. Allora, abbiamo detto che il C non  fa assunzioni di questo tipo, ma noi queste cose  
15:29
diamole per scontate perché sono vere in tutte le  architetture moderne. Quindi, lo abbiamo detto che  
15:34
non è corretto dire che il C fa certe assunzioni;  siccome sono praticamente universalmente vere da,  
15:41
non lo so, 30 anni a questa parte, mmm, una volta  che abbiamo precisato che non possiamo fare queste  
15:47
assunzioni, le facciamo perché sono poi pratiche,  utili nella pratica. E sappiamo che, quindi,  
15:53
sono array di byte le stringhe in C, in cui ci  sono specificati dei caratteri e alla fine c'è  
15:58
uno zero per indicarne la loro terminazione. E noi  con la printf possiamo stampare questi caratteri,  
16:05
eh, utilizzando il fatto che, diciamo, abbiamo  uno specificatore di formato che è %s che fa  
16:12
proprio ciò. Ma a questo punto, chi è che a  noi... chi ci ferma dal tentare di scrivere lo  
16:21
specificatore %s in funzione dello specificatore  %c? Noi ancora il ciclo for non l'abbiamo fatto,  
16:29
eh, ma suppongo che quasi tutti conosceranno il  while. Quindi, guardate, io scrivo int i = 0;  
16:37
(ma per... lo abbreviamo a i) e poi scrivo  while (str[i] != 0) stampo il carattere alla...
16:51
posizione i. Quindi stamperà questo... questo  i sarà zero. Se il primo carattere non è già  
17:02
il NUL terminator (ma non è in questo caso,  perché è più avanti), stampa il carattere  
17:07
e poi incrementiamo i. Alla fine, quando siamo  arrivati fuori dal while perché abbiamo incontrato  
17:16
il terminatore facendo avanzare il nostro indice  i, stampiamo un new line per andare a capo e...
17:21
ritorniamo. Eseguiamo il programma e, in effetti,  scrive proprio "hello". Quindi siamo riusciti, già  
17:31
utilizzando while (che spiegheremo nella prossima  lezione assieme ad if, for e tutte le cose,  
17:36
eccetera), ma un prerequisito per questo corso  era avere qualche elemento di programmazione,  
17:42
quindi a volte salto ma poi ci ritorno e  spiegherò il while. Utilizzando, quindi,  
17:47
semplicemente il while, siamo riusciti a  reimplementare quello che fa la printf con  
17:51
lo specificatore %s, sulla base di una printf  molto più semplice che è in grado di stampare,  
17:57
semplicemente dato, ehm, il valore  ASCII di un carattere, il carattere...
18:02
corrispondente. Arrivati a questo punto,  però, mi pare lecito dire: "Va bene,  
18:09
lo sappiamo che il C era un linguaggio di  programmazione ostico, sappiamo che era difficile,  
18:15
ma veramente devo definire le stringhe così?  Le stringhe, se voglio manipolare una stringa,  
18:20
la devo definire così, come un array, eccetera,  eccetera?". In realtà, per fortuna, no. Allora,  
18:26
ritorniamo al nostro Hello World, però stavolta,  ecco, in questo formato, eh, facciamo Hello World  
18:42
%s\n e qui ci scriviamo str. Quindi abbiamo visto  che così noi possiamo stampare la nostra stringa.  
18:54
Ma definiamone un'altra: char string[6] = "hello";  str chiamiamola questa, e stampiamo anche questa.  
19:11
Vediamo se funziona dargliela in pasto in questo  modo qui. Compiliamo. Puliamo lo schermo. Hello,  
19:21
hello. Guardate, Hello e hello. Quindi io lo  posso dire pure così. La prima cancelliamola,  
19:29
perché sappiamo che abbiamo una forma più  diretta per indicare una stringa. Ma attenzione:  
19:35
se io volessi fare un array di interi  e bla bla, allora devo usare questo  
19:41
formato. Quindi non è che dico di non usare  questo formato qui, ma non per le stringhe.  
19:46
Quando voglio indicare una stringa, posso farlo  in questo modo. Ehm, vi faccio vedere una cosa.  
19:51
Se io qua gli dico che però c'ho quattro  caratteri e provo a compilare, mi dice, eh,  
19:56
attenzione, guarda che 'initializer string for  char array is too long'. Quindi la stringa di  
20:05
inizializzazione per l'array di caratteri  è troppo lunga. E se io ne uso una più...
20:10
grande... eh, scusate, qui dobbiamo dire str,  ma credo che lui non si lamenti in nessun modo.  
20:23
Guarda cosa ho sbagliato: ho messo due, due  conversioni. Ok, torniamo al nostro programma  
20:28
iniziale. Non si lamenta in nessun modo, perché  c'è più spazio di quello che serve. Ma vi dico  
20:35
di più: posso eliminare completamente il numero  di caratteri e dirgli: "Senti, veditela tu quanti  
20:44
caratteri sono". Compilo il programma e funziona  ancora senza problemi. Ora, vi ricordate che noi  
20:53
abbiamo un amichetto che si chiama sizeof? Qua  gli diciamo %lu (long unsigned). Quindi questo  
21:04
è uno specificatore di tipo che è lo stesso tipo  che ritorna sizeof. Quindi, qual è la dimensione  
21:10
in byte? Quindi sizeof è un operatore che, nel  momento della compilazione (perché questa cosa  
21:16
si sa quando il compilatore sta compilando il  codice), tra, mmm, sostituisce praticamente, eh,  
21:27
la chiamata sizeof con la dimensione. Non accade  a runtime, al momento della compilazione. Questo  
21:34
è molto importante, non è un dettaglio, è una  cosa molto importante. Quindi voi le chiamate  
21:39
a sizeof le potete considerare gratuite, come  se qui metteste direttamente un numero. Non c'è  
21:44
alcun tempo di chiamata, di ritorno da una  funzione, niente, è una cosa che accade a  
21:49
compile time. Cioè, se sizeof qui ritornerebbe  sei, e se io scrivo sei qua, è uguale. Ehm,  
21:57
vediamo effettivamente se la dimensione è quella  che noi ci aspettiamo. E in effetti sì, sizeof 6.  
22:07
Una cosa interessante è che, siccome  questo è un array, come posso accedere  
22:14
ai singoli elementi con, per esempio, str[]? Ma  a questo punto togliamo il due, chiamiamola...
22:19
str. Ok, quindi io setto str[3] (0, 1, 2,  3). La seconda 'L' ha una 'X' maiuscola.
22:38
E infatti la mia stringa è cambiata  e vedo "helXo". Allo stesso modo,  
22:47
posso settarla a un numero. Ricordate, 65  è la 'A', perché non ci scordiamo mai che  
22:54
le stringhe in C sono array di numeri, di  numeri che ognuno prende lo spazio di un...
23:00
byte, e sono da zero, però, a 127, perché fuori  da questo range l'ASCII non è definito. E infatti  
23:11
qua spunta hellhow. Quindi continua a funzionare.  Io qui vado là, potrei fare pure ++. Vi ricordate  
23:20
l'operatore ++ da cui viene C++? Quindi incremento  il carattere di uno, quindi quello che c'era...
23:28
prima, mi becco... Dopo la 'L'  c'è la 'M', bic mi becco...
23:34
"HelMo". Benissimo. Con questo,  per questa puntata, è abbastanza.  
23:43
Giocateci, scrivete dei piccoli programmi, se  vi va potete fare anche qualche passo avanti,  
23:50
eh, utilizzando while, if, eccetera, eccetera, se  sapete come fare, ma più che altro concentratevi  
23:56
sulle stringhe. Guardate cos'è che succede se  non c'è il terminatore giusto, eh, e così via.  
24:03
Ecco, per esempio, poco fa io vi volevo far  vedere cosa succede se il terminatore non è  
24:08
quello corretto. Guardate qua, facciamo  'a', '\0'. Quindi questa è una stringa  
24:15
che contiene solo un carattere e poi  il terminatore, quindi sono 2 byte.  
24:20
Eh, io credo che se qua specifico una variabile  x e gli do il valore, tipo, di... anzi, facciamo  
24:31
una cosa: qua ci mettiamo un byte a e gli diamo  il valore di 10. Qua mettiamo un byte b e gli  
24:40
diamo il valore di 20. E qui, invece, sbagliamo  e, invece del terminatore, mettiamo una 'B'.  
24:46
A questo punto manca il NUL terminator.  Quando noi andiamo a stampare questa...
24:50
stringa... eh, qui, ah, qua mi dà un warning, ma  noi ce ne freghiamo che queste due variabili non  
24:58
sono utilizzate, ce ne freghiamo. Eseguiamo  il codice. Guardate che cosa è successo:  
25:04
dopo la 'A' e la 'B' mi ha stampato altri  caratteri errati, e così via. Perché io poi  
25:12
vi spiegherò che cosa succede in qualche puntata  molto più avanti di questa, magari fra 6 mesi,  
25:19
però sostanzialmente, il modo in cui il C mette  queste variabili in memoria... se magari c'era  
25:25
uno zero normalmente subito dopo la stringa, come  è capitato all'inizio, mettendogli una variabile  
25:30
inizializzata prima e una dopo, ho reso molto  probabile che in realtà ci fossero altri byte,  
25:36
dopo i primi due byte di questa stringa, che non  avessero il valore di zero, e quindi poi succede  
25:43
quel che succede. Va bene, stavolta è veramente  la fine di questa puntata. Alla prossima. Ciao!


Miei Appunti:
#include <stdio.h>

int main(void)
{
    char c = 'A'; // intero di tipo carattere, può contenere solo un carattere singolo, il numero è la posizione di quel carattere in ascii
    printf("Hello World %d \n", c);
    printf("[%s]\n", "Hello World");
    printf("[%c]\n", 65);

    // --- Array -----
    int a[5] = {10, 5, 50, 100, 7};
    char s[6] = {'H', 'e', 'l', 'l', 'o', 0};

    printf("%d\n", a[0]);
    printf("%s\n", s);

    int i = 0;
    while (s[i] != 0)
    {
        printf("%c", s[i]);
        i++;
    }
    printf("\n");

    char str[] = "hello";
    str[3] = 'X';
    str[1] = 65;
    printf("%s\n", str);
    printf("%lu\n", sizeof(str)); // sizeof non viene eseguito a runtime ma a compile time

    return 0;
}