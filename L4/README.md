Lezione 4 - link: https://www.youtube.com/watch?v=YNsXyasn4R4&list=PLrEMgOSrS_3cFJpM2gdw8EGFyRBZOyAKY&index=6

Transcript: 
po' un salto indietro per affrontare nuovamente  il nostro programma, questo semplicissimo "Hello,  
0:27
world!", e smontarlo una volta di più. Ma  prima soffermiamoci un po' sui tipi, perché il  
0:31
discorso dei tipi in C è molto interessante. Negli altri linguaggi di programmazione,  
0:37
nella maggior parte degli altri  linguaggi di programmazione,  
0:40
un dato tipo intero ha un determinato range,  ha un determinato numero di bit, un valore  
0:46
minimo e massimo che voi potete assegnare alle  variabili di quel tipo, che è fisso. In Python,  
0:54
se io ho una data versione di Python, sia che  lo compilo per un sistema e lo eseguo in quel  
1:00
sistema, sia che lo utilizzo in un sistema  completamente diverso, vedrò, persino dentro  
1:06
MicroPython che è un'implementazione a parte e  così via, vedrò che c'è una certa consistenza nei  
1:11
tipi numerici. Ciò che è rappresentabile da Python  in un sistema è rappresentabile in un altro.  
1:17
Ed è così anche per altri linguaggi, persino  a basso livello, che sono però più moderni  
1:25
e che partono da principi un po' diversi. Il C è un linguaggio degli anni '60. Inoltre,  
1:33
è un linguaggio con una specifica ambizione:  l'ambizione è quella che il C doveva essere  
1:39
compatibile con tutti i sistemi disponibili. Dal  computer più piccolo con un processore 8 bit,  
1:48
con uno Z80, io potevo avere un compilatore  C funzionante per quel processore, fino a,  
1:55
eh, non lo so, un supercomputer a 64 bit,  io dovevo avere una versione del C, eh,  
2:03
capace di girare in quel computer. Per tale motivo, i tipi, per esempio  
2:07
il tipo int x = 5;, eh, a 5, non è specificato  nella specifica C questo int quanto è grande,  
2:18
se è un numero a 32 bit, se ha 64 bit, se ha 16  bit. Questo varia da piattaforma a piattaforma.  
2:25
Ehm, se però una cosa che vale per tutte  le implementazioni di C è che se non è,  
2:31
eh, preceduta la dichiarazione del tipo  da unsigned, allora l'intero è col segno,  
2:39
cioè capace di rappresentare, questa variabile  x intera, sia numeri negativi che numeri  
2:45
positivi. Ma quanto è grande non lo sappiamo. Ehm, ci viene però in soccorso sizeof. Qui  
3:01
scriviamo con la nostra fida printf("Hello world,  int is %d bytes\n"); e qua scriveremo sizeof di x.  
3:15
Tra l'altro, quando compileremo questo programma,  vi faccio vedere che esce sicuramente un warning,  
3:20
perché io qui ho detto alla printf "il tipo è  intero", ma poi in realtà non ho dato un intero,  
3:27
e guardate che ci sarà un warning. Compilo il  programma. Esatto: "Format specifies type 'int'  
3:35
but the argument has type 'unsigned long'".  Quindi tu mi hai detto che mi passi un intero,  
3:40
ma il tipo che mi ritorna sizeof  è un intero lungo senza segno. 
3:48
Allora io potrei fare... questo problema  si può risolvere in diversi modi. Uno è,  
3:53
si chiama, una tecnica che si chiama casting,  cioè mettere prima di una qualsiasi espressione C,  
4:00
tra parentesi, un tipo, vuol dire "convertimi  quello che viene a destra in questo tipo qua".  
4:06
Guardate, ora il problema non c'è più, perché io  effettivamente ho chiesto una conversione a un  
4:11
tipo intero. In questo caso, siccome poi  il casting magari lo vedremo più avanti,  
4:17
possiamo utilizzare lo specificatore di tipo  della printf %lu, che significa long unsigned,  
4:23
e siccome sizeof mi ritorna un long unsigned,  i due tipi sono ora compatibili. Quindi ora  
4:31
farò così e scopro che il mio intero è di 4 byte. Cosa ci va in un intero di 4 byte? 2 elevato a 32  
4:43
mi consentirebbe di rappresentare questo numero  di simboli. Quindi, se il tipo fosse unsigned int,  
4:51
potrei rappresentare da 0 a questo numero -1  (perché lo 0 è uno dei simboli). Ma siccome il  
5:02
tipo è signed, io posso rappresentare soltanto  da meno questo numero qua diviso 2, fino a più  
5:13
questo numero qua diviso 2 -1 (perché c'è lo 0  che prende un simbolo da questa parte). D'accordo? 
5:23
Se torniamo un attimo al nostro programma,  ci potremmo chiedere: ma questo tipo int,  
5:29
oltre io a fare i conti a manina con sizeof e  poi farmi le potenze, ma c'è un modo per vedere  
5:36
qual è il numero minimo e il numero massimo che  può, eh, gestire? Ci viene da questo punto di  
5:43
vista molto in aiuto limits.h. Un altro include,  includiamo questo file .h che ha dentro un sacco  
5:51
di definizioni diverse. E ora posso scrivere  qualcosa come del genere: int min %d, int max  
6:01
%d. E guardate, uso due costanti definite (poi vi  dirò di preciso com'è che si fa questa cosa in C).  
6:12
Ma voi per ora immaginate semplicemente  che una volta che io includo limits.h,  
6:17
il, eh, preprocessore trasformerà questo INT_MIN  nell'intero minimo che può essere rappresentato  
6:26
in questa piattaforma dal tipo int, e INT_MAX,  l'intero massimo che può essere rappresentato.  
6:32
Tutti e due i valori saranno interi, quindi ho  messo %d. E compiliamo il nostro programma, che  
6:37
in effetti compila. E guardate, sono esattamente  i numeri che c'eravamo detti noi con bc. 
6:46
Tuttavia, a volte si devono scrivere dei programmi  che, eh, hanno una determinata dimensione,  
6:55
e i tipi di C non ci garantiscono, eh, delle  dimensioni. Anche se però è bene sapere alcune  
7:01
cose. Anche se non c'è alcuna garanzia,  vi dico che cos'è che vi potete aspettare  
7:05
dai moderni sistemi a 32 e a 64 bit. Come vi ho  detto, nei sistemi passati, neanche un... cioè,  
7:14
a volte neanche i byte erano effettivamente di,  eh, di... neanche un byte era effettivamente di  
7:21
8 bit. A volte c'erano sistemi dove il byte era di  9 bit, eh, sistemi in cui l'intero era di 36 bit,  
7:29
era tutto molto complicato. Ora c'è una certa  standardizzazione. Ripeto, lo standard C non  
7:35
vi garantisce le cose che sto per dirvi, però vi  faccio vedere come nel 99% dei casi appariranno  
7:43
i tipi standard del C, i tipi interi. Allora, tanto per iniziare, noi abbiamo,  
7:48
eh, char c, che è intero a 8 bit, solitamente  1 byte. Ok. Qui li definisco tutti con segno,  
8:00
quindi non uso unsigned. Poi abbiamo short s. Eh,  
8:07
per il char si possono registrare valori  da -128 a +127; per lo short, qua,  
8:12
da -32.000 e rotti a +32.000. Perché  di solito è 16 bit, 2 byte, lo short. 
8:19
Poi c'ho l'intero, che di solito è 4  byte, ovvero 32 bit. Poi c'ho il long,  
8:26
e qui è molto interessante. Chiamiamolo L  = 10;. Vi faccio vedere quanto è grande il  
8:32
long in questo sistema qua. Di nuovo utilizziamo  l'operatore sizeof, quindi qua devo scrivere %lu.  
8:50
8 byte. 8 * 8 = 64, quindi  il nostro tipo long è 64 bit. 
8:59
Ora vi dico una cosa: solitamente il tipo  long. Allora, sapete, qua vi ho detto di  
9:05
solito il char è un byte (praticamente  universalmente), lo short è più o meno  
9:11
universalmente 2 byte. L'int, a volte capita che  è 8 byte (quindi 64 bit), però di solito è 32 bit,  
9:24
il tipo intero. Ripeto, queste sono cose che  C non garantisce, ma che io vi dico. Il long  
9:33
è quasi sempre, nel 99% dei casi, la stessa  grandezza della parola del microprocessore.  
9:39
Quindi in un processore di 64 bit sarà 64  bit, in un processore di 32 bit sarà 32 bit.  
9:48
E ciò ci dice una cosa assai interessante. A volte ci sono dei programmi in C, specialmente  
9:56
scritti nel passato, che assumevano di poter  registrare un indirizzo di memoria in un int.  
10:04
Quando l' int era della stessa dimensione  dell'indirizzo di memoria, questa cosa  
10:10
funziona. Se per caso l'int è più piccolo di un  indirizzo di memoria (come in tutte le macchine  
10:15
moderne a 64 bit, di solito l'indirizzo di memoria  è 64 bit, 8 byte) e l'int è 32 bit, e quindi se ci  
10:23
sono vecchi programmi che assumono che possono  registrare in un int un indirizzo di memoria,  
10:30
i programmi poi non funzioneranno nelle macchine  nuove, o faranno, tra l'altro, delle cose subdole,  
10:35
perché possibilmente, magari, eh, dipende molto  dal modo in cui, diciamo, lo spazio del programma,  
10:42
degli indirizzi del programma, viene mappato, ma  a volte possono funzionare fino a un certo punto  
10:46
o non funzionare da subito. È più facile  che vadano in crash immediatamente, e poi  
10:52
vedremo anche perché più avanti in questo corso. Però, invece, il long, anche se non c'è nessuna  
10:57
garanzia da parte del C di ciò, solitamente può  registrare un indirizzo di memoria, e infatti è  
11:06
molto più grande. Vedremo poi che ci sono dei  tipi avanzati del C, man mano che sono inclusi  
11:18
con stdint.h, che prima non erano parte della  specifica, in cui posso specificare esattamente  
11:24
la grandezza che voglio. uint64_t è un intero  senza segno di 64 bit. int64_t. C'ho size_t,  
11:34
che è un tipo che può rappresentare una grandezza  in base al target del processore per cui sto  
11:43
compilando quel programma; quella grandezza può  essere massima di 16 bit, può essere massima di  
11:48
32 bit, di 64 bit. Tipo, per esempio, un  pezzo di memoria allocato, la grandezza di  
11:53
un file o quello che volete. Ma più che altro  size_t si riferisce normalmente... guardate,  
12:03
cerchiamolo... 'maximum size' di un oggetto  di qualsiasi tipo, array o quello che volete. 
12:11
Ma poi abbiamo pure dei tipi specifici  nelle implementazioni nuove del C, ma,  
12:15
tipo, implementazioni nuove che credo che si  parli del C99, quindi implementazioni di 25  
12:21
anni fa. Ma sappiate che a volte alcuni programmi  non vogliono neanche supportare il C99. C'è per  
12:28
esempio pure intptr_t, che è un intero che ha una  grandezza che ci assicura che là dentro ci entra  
12:35
un indirizzo di memoria, ovvero un puntatore. Uno, peraltro, si potrebbe chiedere:  
12:40
"Ma come mai?". Perché c'è pure intptr_t? Ora,  gli indirizzi di memoria mica sono negativi,  
12:48
sono positivi. Da possiamo immaginare, tipo, la  memoria, un blocco contiguo, eh, da zero fino a,  
12:55
non lo so, quel che volete voi. Nel caso estremo,  da 0 a 2 elevato a 64. Perché c'è anche un tipo  
13:03
compatibile con la grandezza dei puntatori, cioè  degli indirizzi di memoria, con segno? È perché  
13:09
io a volte i puntatori li voglio sottrarre tra di  loro, eh, e questa sottrazione può dar vita a un,  
13:17
eh, valore negativo. Per dire, se io non  so se un puntatore è prima di un altro,  
13:23
posso sottrarre un puntatore da un altro e  voglio poter essere sicuro, poi, di avere  
13:30
un tipo che mi permette di fare questo tipo di  differenza e di avere anche dei valori negativi. 
13:36
Bene, ora che abbiamo dimestichezza con i tipi  base del C, eh, possiamo chiederci perché ce ne  
13:45
sono così tanti e per cosa usare diversi tipi?  Eh, perché usare un tipo al posto di un altro? 
13:52
Allora, vedremo che i caratteri, il tipo  car (o char - io ho detto sempre char,  
13:56
credo che sia normale dire car perché è  l'abbreviazione di character) è utilissimo  
14:02
perché è centrale in C, perché è il modo  in cui vengono rappresentate le stringhe.  
14:07
Quindi le stringhe, ovvero i testi, tipo:  "questa è una stringa" (questa che parte con le  
14:12
virgolette, si chiude con le virgolette), vengono  rappresentati da elementi, da array di tipo char,  
14:20
quindi singoli array di questa dimensione. Lo short è 16 bit. Quando io voglio rappresentare  
14:26
numeri abbastanza piccoli, se utilizzo uno short  salvo moltissima memoria rispetto a utilizzare un  
14:32
long. Nello spazio di un long, se la macchina  ha 64 bit, ce ne entrano ben quattro short;  
14:39
se la macchina ha 32 bit, ce ne entrano due.  Comunque la differenza è notevole, e così via. 
14:46
Quindi, invece, in un tipo long, ma specialmente  un tipo uint64_t, quando così noi lo specifichiamo  
14:53
(se includiamo stdint.h), abbiamo i tipi a  64 bit. Siamo sicuri, tanto per iniziare,  
14:59
che possiamo fare della matematica su numeri, per  esempio di input a 32 bit, e non succederà mai che  
15:07
vadano in overflow. Quindi ho uno spazio maggiore  di bit per fare matematica con numeri più grandi.  
15:15
Ma un'altra cosa molto importante è che io posso  incrementare questi, eh, numeri a 64 bit, eh,  
15:22
con la tranquillità che non andranno in overflow.  Perché se io... facciamo... se facciamo i conti,  
15:27
2 elevato a 64 fa questo numero (scusate,  ho scritto 65). Se io lo divido per,  
15:34
mettiamo che ho 1 milione di eventi al secondo,  per, eh, quanti secondi ci sono in un'ora (3600),  
15:46
per 24 ore, per 365 giorni, posso continuare  a incrementare per 584 anni. Quindi,  
15:56
sostanzialmente, per molte applicazioni, un tipo  di, eh, a 64 bit, eh, si può considerare come un  
16:04
tipo che non andrà mai in overflow in tempi,  diciamo, normali di esecuzione del programma. 
16:10
Magari a questo punto vi state illudendo  che finalmente andremo avanti con, ehm,  
16:17
il nostro percorso nelle cose magari più avanzate  che riguardano il linguaggio C. E invece no,  
16:24
mi dispiace, ma andiamo di nuovo al  nostro "Hello, world!". Torniamo al  
16:30
nostro programma e ripartiamo un po' da capo,  da quello che avrei dovuto dire all'inizio,  
16:35
ma che sarebbe stato mortalmente noioso dire  all'inizio (che non ho detto all'inizio). Allora,  
16:41
gli include li abbiamo spiegati, quindi questa  parte qui 'smonterà' il file. Ma andiamo a  
16:48
vedere la struttura del nostro programma. Questa è una definizione di una funzione.  
16:54
C'è il tipo di ritorno, che può essere int, short,  quello che volete, o void se non ritorna niente;  
17:01
il nome della funzione; e tra parentesi ci  sono espressi i parametri della funzione coi  
17:07
loro tipi (per esempio, int x, float  y, e così via) separati da virgole.  
17:13
In questo caso la funzione non accetta nulla.  Dopodiché c'è un nome di un simbolo, di qualcosa:  
17:23
printf. Bene, possiamo vedere dal fatto che  subito dopo printf c'è la parentesi tonda, che si  
17:30
tratta di una funzione che noi stiamo chiamando. In pratica, in C le funzioni si chiamano scrivendo  
17:37
il loro nome, aprendo la parentesi tonda e dando  una lista di argomenti. A volte la funzione  
17:43
potrebbe non avere alcun argomento, e in tal caso,  mhm, sarà qualcosa come, per esempio, clear().  
17:54
Ora scriviamo questa funzione clear. Peraltro,  ora vi faccio vedere un trucco. Io non mi ricordo  
17:58
in questo momento la sequenza di escape da dare al  terminale per pulire lo schermo. Ok, voglio pulire  
18:04
lo schermo prima di scrivere "Hello, world!".  Guardate cosa facciamo. Siccome noi abbiamo il  
18:08
comando Unix che spara queste sequenze, noi lo  spariamo in pipe a Unix. Una pipe Unix è questa:  
18:16
xdump -C. E lui ci fa vedere esattamente che  cos'è che esce da questo programma. Quindi,  
18:22
guardate qua: 1B è escape. Escape parentesi  quadra aperta 3J, e poi Escape parentesi quadra H,  
18:36
Escape parentesi quadra 2J. Questa è un  po' complicata come sequenza di escape. 
18:41
Allora, void clear(void). Quindi questa funzione,  definiamo una funzione void, non ritorna niente,  
18:48
si chiama clear, non accetta alcun argomento.  printf("\033..."). Questo \033 è un modo in cui  
19:04
posso descrivere i byte in ottale, eh, 033  che sarebbe, eh, 27 in decimale. Guardate,  
19:17
questa è la tabella ASCII. Questo qui è ottale  033, guardate, è escape. Questo è esadecimale,  
19:29
e l'escape in questo caso lo vado a trovare  qua: 1B. Vi ricordate qui che abbiamo visto 1B?  
19:38
Perché questi sono... questo è un dump. xdump è un  programma che fa il dump esadecimale. -C maiuscola  
19:44
significa che vogliamo vedere un dump canonico  con gli indirizzi di memoria, cioè l'offset dei  
19:50
vari byte, che mi restituisce il contenuto di  quello che xdump sta vedendo in esadecimale,  
19:59
byte dopo byte. E qui la sua rappresentazione a  stringa leggibile per l'essere umano. Se volete,  
20:06
eh, che io sia più chiaro: xdump -c. Guardate  il mio programma "Hello, world!", quello che  
20:13
ho scritto poco fa. Eh, qui. Qua, come vedete,  è leggibile. Qua ci sono i byte esadecimali,  
20:20
e qui gli offset del file. Quindi, eh, io in  ottale scrivo questa cosa qua. Potevo scrivere,  
20:28
volendo, \x1B. Voi credo che siete più avvezzi  a vedere questa sintassi qua. E poi, ok,  
20:36
lui mi dice di usare quella sequenza di escape,  ma è un po' complicatuccia. Io magari proverò a  
20:41
usare questa (\033[2J), che credo pulirà  lo stesso lo schermo. Vediamo se è vero. 
20:51
Esatto, guardate, pulisce lo schermo prima di  scrivere "Hello, world!". Allora, qui io avrei  
20:58
dovuto scrivere fflush(stdout). Ma siccome  noi ancora non abbiamo parlato degli standard  
21:05
input/output, del modo standard di fare I/O della  libreria del C (la libreria quella di default),  
21:12
noi ce ne fregheremo, e vi dico che questo  programma funziona lo stesso, perché siccome  
21:17
dopo che scrivo "Hello" c'è un newline, comunque  il gioco funziona. Ve lo dico solo in soldoni. 
21:25
In sostanza, printf, invece di scrivere davvero  sul terminale, accumula in un buffer interno  
21:31
nella memoria fino a quando non vede un newline  o fino a quando io non chiamo una chiamata che  
21:37
si chiama fflush. Questo per ottimizzare,  perché sennò dovrebbe fare un sacco di I/O.  
21:43
Ciò rende le cose più veloci, più performanti. Ma  siccome poi, quando vede il newline, fa il flush  
21:50
(scrive sul terminale), io prima ho scritto  questo che rimarrà solo nella memoria (perché  
21:54
non c'è la chiamata fflush), e poi in realtà  faccio la printf, e quindi la cosa funziona. 
22:00
Allora, guardate questa è una chiamata a  funzione: nome, aperta parentesi tonda,  
22:06
chiusa parentesi tonda. Avrete anche notato  cos'è che io non ho detto all'inizio (perché  
22:12
semplicemente certe cose possono essere  facilmente assorbite guardando, e quindi  
22:17
le posso dire anche più tardi): che le diverse  parti del programma, i diversi statement del mio  
22:24
programma, sono divisi da un punto e virgola. Eh, il C... si può scrivere nel modo in cui  
22:34
volete. L'indentazione serve solo all'essere  umano che legge il programma, ma non al programma,  
22:40
che continua a funzionare e se ne impipa. Posso  scrivere come mi pare. Compilerà sempre lo stesso  
22:48
e funzionerà tutto. Quindi è una questione di  gusti. Io vi consiglio non solo di organizzare  
22:55
il programma in maniera leggibile, ma anche  di farlo a mano, senza usare gli editor che  
23:00
lo facciano per voi, perché c'è tanto di noi nel  modo in cui scriviamo certe cose. Per esempio,  
23:07
vi faccio un esempio: io ho il vezzo che se  una condizione è molto breve (per esempio:  
23:13
if (!x) exit(0);), questa qua la metto su una  linea. Un indentatore automatico scriverebbe  
23:23
questa cosa qui, ma ci metto un po' del mio,  un po' di stile, ok? Ed è anche questa parte  
23:30
della programmazione. Ma anche imparare a  fare queste cose a mano non è tempo perso,  
23:34
perché, mmm, vi aiuta anche a livello mentale,  secondo me, nel creare una struttura mentale,  
23:41
il fatto che dovete fare le cose a manina. Allora, dicevo, qua c'è una seconda chiamata  
23:49
a funzione, e guardate cosa incontriamo qui: una  stringa "Hello, world!" e poi return 0;. In realtà  
23:59
questa stringa non è altro che un insieme  di, eh, tipi char. Nella prossima puntata  
24:08
(perché ormai questa puntata ha raggiunto il tempo  limite) vedremo che cosa sono le stringhe in C,  
24:15
eh, per continuare il nostro viaggio,  stavolta grammaticale, dentro l'Hello World. 
24:22
Ora vediamo che qua c'è lo statement. Allora,  tutto questo programma è composto da una sola  
24:29
parola chiave che è in questo statement  qui: return 0;. return è una parola chiave,  
24:34
0 è un'espressione (perché io potrei scrivere  qui una qualsiasi espressione, come 1 + 2 + 3). 
24:41
In realtà, prima di chiudere, volevo spiegare  qualcosa, perché qualcuno di voi si sarà chiesto:  
24:47
"Ma che cos'è che succede in questa printf?  Perché pulisce lo schermo? Che significa?".  
24:52
Allora, in pratica, i terminali... io sto usando  un programma che è di emulazione di terminale, eh,  
24:58
ok? Quando aprite, voi, non lo so, qualsiasi  terminale in cui scrivete i comandi e vedete  
25:03
l'output, quello è un terminale. E siccome  potete scrivere clear o alcuni programmi  
25:08
magari possono muovere il cursore, eh, questi  programmi hanno la necessità di distinguere  
25:14
quando noi vogliamo semplicemente stampare delle  cose sullo schermo o quando vogliamo spedire dei  
25:19
caratteri che sono delle sequenze di controllo. Bene, le sequenze di controllo, dal terminale  
25:24
VT100 in poi (VT100 è un terminale del 1978,  per capirci), da questa roba qua... Guardate,  
25:34
peraltro, che design industriale meraviglioso!  Ma comunque, a parte questo, eh, funzionano così:  
25:40
Uno prima spedisce uno speciale carattere che  è l'escape (quindi quello specifico byte),  
25:46
poi, eh, scrive una parentesi quadra e poi altre  lettere che indicano che cosa fare. In realtà,  
25:55
peraltro, questa sequenza qui (ESC[H) non sarebbe  quella che veramente pulisce lo schermo. H (ack)  
26:00
significa home e dovrebbe semplicemente far andare  il cursore qui, ma dipende dalla modalità in cui è  
26:07
il terminale. Proviamo con Python, per dire.  Io anche qui posso scrivere la stessa cosa,  
26:14
eh, quindi era così. Guardate, qua fa  solo l'homing, fa andare il cursore lì.  
26:25
Per una sequenza di escape che davvero,  eh, pulisca lo schermo, io dovrei fare,  
26:33
probabilmente, prima lanciare l'escape e  fare [2J (la quadra 2J). Esatto, ora sta  
26:44
funzionando, guardate. Ora pulisce lo schermo. Perché qui funziona... qui è necessario, come  
26:51
dovrebbe essere, eh, produrre anche questo escape.  Invece, nel nostro programma in C, eh, funzionava  
26:58
tutto benissimo? Beh, non è sicuramente perché  è il programma in C. Io se scrivo test.py... in  
27:03
Python, e faccio... produco solo questo (\033[2J).  Ecco, come potete vedere, pulisce. Probabilmente  
27:14
perché quando sono dentro la REPL, il terminale  è in modalità raw per leggere i caratteri, eh,  
27:22
in maniera raw dalla tastiera, e quindi,  praticamente, l'emulazione del terminale  
27:27
funziona in maniera più pura. Credo che quando non  è in modalità raw, quando è in modalità cooked,  
27:33
forse interpreta in maniera diversa la mia  sequenza di escape. L'avevamo visto qui,  
27:40
ma per semplicità, durante la spiegazione,  abbiamo preso, diciamo, delle scorciatoie. 
27:44
Va bene ragazzi, ciao, a  presto, alla prossima puntata.


Miei appunti: 
I tipi in c non hanno nella specifica la loro grandezza in bit ( a differenza dei linguaggi di programmazione più nuovi).
#include <stdio.h>
#include <limits.h>
#include <stdint.h>

void clear(void)
{
    printf("\x1b[H");
}

int main()
{
    char c = 1;      // 8 bit, 1 byte - carattere, rappresenta le stringhe
    short s = 2000;  // 16 bit, 2 byte - intero corto
    int x = 5;       // 32bit, 4 byte - intero
    long l = 300000; // grandezza della parola del microprocessore, quindi 64 o 32 bit, 8 o 4 byte - intero lungo

    uint64_t big = 1234567890123456789ULL; // intero senza segno a 64 bit - matematica modulare
    int64_t sbig = -1234567890123456789LL; // intero con segno a 64 bit
    size_t size = sizeof(big);             // tipo intero senza segno per rappresentare la dimensione in byte di un oggetto

    intptr_t ptr_value = (intptr_t)&x;    // tipo intero capace di contenere un puntatore
    uintptr_t uptr_value = (uintptr_t)&x; // tipo intero senza segno capace di contenere un puntatore

    clear();
    printf("Hello World: int is %lu bytes\n", sizeof(x));
    printf("Hello World: int min %d int max %d\n", INT_MIN, INT_MAX);
    printf("Hello World: long is %lu bytes\n", sizeof(l));

    return 0;
}