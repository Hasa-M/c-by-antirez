Lesson 14 - Lesson Link: https://www.youtube.com/watch?v=p4IMHau2lq8&list=PLrEMgOSrS_3cFJpM2gdw8EGFyRBZOyAKY&index=16

Lesson 14 - Transcript:
0:39
Beh, devo ammettere che l'altra volta ho fatto la  cattiveria di introdurre le strutture senza poi  
0:45
parlarne. Eh, perché noi volevamo creare il nostro  tipo di oggetto stringa nuovo, dov'era... eh,  
0:57
prefixed length strings. E avevamo detto: "Ma  guardate, facciamo che la lunghezza è 4 byte, ci  
1:05
mettiamo un conto delle referenze, così possiamo  avere diversi riferimenti alla nostra stringa e  
1:10
poi ogni volta che ne aggiungiamo uno, chiamiamo  una funzione che incrementa questo contatore."  
1:16
Quando togliamo una referenza, sottraiamo da  questo contatore. Quando le referenze arrivano a  
1:21
zero, chiamiamo la `free`. Quindi abbiamo anche un  sistema di gestione della memoria semi-automatico.
1:30
E allora avevamo detto: "Però non è che ci  possiamo mettere a fare qua con gli offset,   `memcpy`, S+4... perché, cioè, così ancora  ancora si potrebbe fare senza problemi,  
1:42
ma che succede se io ho 10 campi nell'oggetto  che voglio rappresentare?" Diventa un casino  
1:49
micidiale. E allora avevo detto: "Guardate  qua, possiamo usare una struttura". Ma per  
1:57
introdurre per bene le strutture, dobbiamo per  un attimo dimenticare il nostro problema delle   'prefixed length strings' e cancelliamo quindi  questa roba qui. Ci teniamo solo `stdio.h` e  
2:13
facciamo finta che noi vogliamo scrivere  un programma che gestisce le frazioni.
2:23
Per dire, io devo avere un numeratore e un  denominatore. E questi sono due numeri. Quindi,  
2:37
cos'è che potrei fare? In teoria, io potrei  dire: "Guarda, io so usare `malloc`, che  
2:42
però è in `stdlib.h`". E allora... definisco un  puntatore. Ah, anzi, qua non ho i tipi standard,  
2:56
non li ho inclusi. Facciamo un puntatore  intero, `my_fraction`... `mf`... anzi,  
3:03
chiamiamolo solo `f`. `malloc(sizeof(int) * 2)`  perché ne voglio due. L'intero è 4 byte in questo  
3:14
computer, quindi questo `sizeof(int)  * 2` farà 8, e io avrò con `malloc`  
3:20
un'area di memoria di 8 byte. In più, c'ho il  puntatore a intero `f` che punta proprio lì.
3:29
Ora, se io scrivo `f[0]`, significa che  modificherò o leggerò il primo intero. Quindi,  
3:41
guardate: quando io faccio questo `malloc`,  io qua mi creo un pezzo di memoria di 8 byte.  
3:47
Qua ci sono i primi 4 byte e qua i secondi 4  byte. Se io faccio `f[0]`, mi sto riferendo  
3:58
all'intero che è registrato nei primi 4 byte;  `f[1]` va qui, nell'intero che è registrato  
4:05
nei secondi 4 byte. Quindi posso fare, che ne so,  per esempio `set_fraction`, gli passo il puntatore  
4:13
`f` e poi 1, 2, se voglio creare una frazione che  vale 1/2. E questo `set_fraction` potrebbe essere:  
4:22
`void set_fraction(int *f, int num,  int den) { f[0] = num; f[1] = den; }`.
4:42
Quindi questa funzione lavora solo come  effetto collaterale, non ritorna nulla.  
4:48
Siccome mi è passato un puntatore `f` a un  array di due interi, allora qua scriviamo  
4:59
dentro questa locazione di memoria prima il  numeratore e poi il denominatore. Vi faccio  
5:06
vedere una cosa. Io potrei anche scrivere  `print_fraction(f)`. Facciamo anche questa  
5:12
funzione qui: `void print_fraction(int  *f) { printf("%d/%d\n", f[0], f[1]); }`.
5:27
Quindi io praticamente posso compilare 'sto  programma qua, `struct.c`. Sì. E mi scrive  
5:38
'1/2'. Qua mettiamoci anche il newline. Quindi  questa chiamiamola magari `f1`, frazione 1. Poi  
5:46
ne potrei fare una frazione 2, ma guardate, ogni  volta devo fare `malloc`, che rottura di scatole.
5:51
Invece, facciamo una cosa: che ne dite  se la chiamiamo `create_fraction`?  
5:57
Quindi, stavolta mi ritorna un puntatore  a intero. `create_fraction` non prende più  
6:06
il puntatore. Guardate che facciamo.  Perché non lo facciamo allocare alla   funzione stessa? `f = malloc(sizeof(int) *  2)`. Qua dovremmo fare: `if (f == NULL)`.  
6:21
Il sistema operativo mi sta dicendo che non ha  memoria da allocare e ritorniamo `NULL` anche  
6:27
noi. Questo qui è il `malloc` error checking. Si  dovrebbe sempre controllare l'allocazione. Noi  
6:34
per ora facciamo questa cosa. Poi vi spiegherò  perché nei programmi seri di grandi dimensioni  
6:41
quasi sempre questo non si fa, e perché invece  nelle librerie quasi sempre bisogna farlo.  
6:47
Ma poi ci torneremo. Per ora, facciamo i  buoni cittadini e se `malloc` mi ritorna  
6:55
`NULL` (il puntatore a zero, che è speciale,  l'indirizzo zero) significa "ho fallito".
7:03
`malloc` è una famiglia di funzioni. "The malloc  function allocates size bytes... etc. etc."  
7:13
Andiamo al valore di ritorno. "If there  is an error", quindi se c'è un errore,  
7:20
queste funzioni ritornano un puntatore a `NULL`  e settano questo speciale intero globale,  
7:27
di cui poi vi parlerò, `errno`.  All'errore `ENOMEM`: non ho memoria.  
7:35
Usatele le pagine del manuale. Una  volta erano spettacolarmente scritte,  
7:42
ora dipende dal sistema, da chi le ha  scritte, però insomma sono ancora utili.
7:48
Quindi, praticamente, a questo punto io, guardate,  posso fare: `int *f1 = create_fraction(10, 20);` e  
7:54
`int *f2 = create_fraction(3, 4);`.  Va da sé che io dovrei controllare,  
8:13
così come `create_fraction` controlla il valore  di ritorno di `malloc`, tutti gli utenti di  
8:21
`create_fraction` dovrebbero controllare il suo  valore di ritorno e, se è `NULL`, dovrebbero  
8:27
interrompere l'esecuzione o recuperare in qualche  modo. Quindi questa funzione sarà commentata così:  
8:34
"Create a new fraction setting num and den as the  numerator and the denominator of the fraction."  
8:51
"If an out of memory condition happens"...  veramente questo è troppo convoluto,  
8:57
è meglio scrivere: "The function returns  NULL on out of memory. Otherwise the fraction  
9:07
object is returned." Denominatore,  scusate. Numeratore, denominatore.
9:41
Ora, noi potremmo fare una funzione che semplifica  la frazione. Vediamo una funzione banalissima che  
10:07
chiamiamo `simplify_fraction` e gli diamo `f1`,  che era 10/20. Allora, facciamo questa funzione:  
10:24
`void simplify_fraction(int *f)`. "Simplify the  provided fraction." Allora, qua dobbiamo dividere  
10:45
sia il numeratore che il denominatore per lo  stesso numero che riesce a dividere entrambi.
10:53
Quindi qua noi la facciamo veramente semplice e  facciamo che il mio divisore, che chiamiamo `d`,  
11:03
lo facciamo partire da 2. `d` deve essere minore  o uguale a `f[0]` e `d` deve essere minore o  
11:12
uguale a `f[1]`. Se il resto della divisione tra  `f[0]` e `d` è 0 (e quindi se `d` è un divisore  
11:44
del numeratore) e `d` è anche un divisore del  denominatore... non vi preoccupate, la matematica  
11:51
di questa lezione è finita qua. Se divide tutti e  due i numeri, allora li divido entrambi per `d`.  
12:07
Ok, e vediamo se funziona.
12:23
Allora, `create_fraction` deve ritornare `f`  dopo che lo ha allocato e inizializzato. Infatti,  
12:45
la funzione ritorna un puntatore a  intero. E ora funziona. Mi ritorna  
12:54
5/10 ed è sbagliato. E vi dico perché: perché  questi due numeri possono avere più volte lo  
13:13
stesso fattore primo come divisore. E quindi,  quando è così, io posso usare `while`: cioè,  
13:25
fin quando questo numero `d` divide sia  `f[0]` che `f[1]`, io continuo a dividere.
13:42
Ed è lo stesso sbagliato: 5/10. E  perché è sbagliato anche questo? Ah,  
14:04
perché `d` deve essere minore o uguale... Esatto.  Ora la nostra funzione effettivamente semplifica  
14:15
nella maniera corretta. Però guardate questo  programma. Ho dovuto accedere a `f[0]` e `f[1]`.  
14:30
In realtà, avrei potuto fare una cosa più  interessante, creando due funzioni "helper",  
14:48
come `set_fraction_num` e `get_fraction_num`, ma  non avrebbe avuto molto senso in questo contesto.
15:32
Ma il C ci riserva una sorpresa.  Posso dichiarare io una struttura,  
15:37
chiamiamola `fract`, in cui ho dei campi  che hanno un nome: `int num; int den;`.  
15:52
Eh, guardate qua, gli dico praticamente al  C: "Fammi un tipo di dato aggregato". Le  
15:59
strutture sono l'unico caso in cui il C esce fuori  dall'idea di manipolare solo numeri. Per il resto,  
16:08
manipola sempre numeri. Guardate: `malloc` mi  ritorna un puntatore, un indirizzo di memoria.  
16:15
Cos'è? Un numero. `NULL`? Un numero, zero.  Questi sono offset, sono numeri. È tutto numeri.
16:34
Però la struttura non è un numero.  La struttura è qualcosa di più,   è un tipo di dato, tanto che io posso  dichiarare questo tipo di dato. Allora,  
16:47
qua: `#if 0 ... #endif`. Questo è un modo  per commentare un bel blocco di codice.
17:06
Guardate, per creare una variabile  di questo tipo... anzi, prima vi  
17:12
faccio vedere una cosa. Quant'è grande  questo tipo? `printf("size of: %zu",  
17:23
sizeof(struct fract));`. È grande 8, perché  il tipo intero nel mio computer è 4 byte.  
17:49
Uso due campi di 4 byte. Ma che succede se io  prima ci metto un `unsigned char color`? Questo  
18:44
è un byte solo, quindi 1 + 4 + 4 = 9. E invece  no! Compiliamo: 12 byte. Che brutta sorpresa!
19:09
Allora, le strutture, di default, ti garantiscono  che ogni membro sia registrato a un indirizzo di  
19:21
memoria che è un multiplo della sua dimensione.  Quindi `num` sarà a un indirizzo multiplo di 4.  
19:33
Questo `char` sarà seguito da 3 byte di  *padding* (riempimento) per fare in modo  
19:40
che `num` inizi a un indirizzo multiplo di  4. Se invece, più saggiamente, `unsigned char  
19:54
color` lo mettevo alla fine, potreste dire:  "Ora dovrebbe essere 9". Eh no, è sempre 12.  
20:29
Perché, inoltre, la struttura deve garantire  di essere allineata al suo componente più  
20:38
grande (in questo caso 4 byte), per  funzionare correttamente negli array.
21:41
Questo è un assaggio per farvi capire che la  struttura in C è un impacchettamento di roba  
21:48
in un unico blocco, ma ogni campo deve  rispettare il proprio allineamento. C'è  
21:56
un modo per fare una struttura  "impacchettata" senza padding,  
22:08
ma il programmatore deve chiederlo in  maniera esplicita. E ci arriveremo.
22:21
Torniamo al nostro problema. Posso dichiarare  una variabile in maniera molto facile:  
22:42
`struct fract a;`. Questo è come scrivere  `int a;`. `struct fract` è il nome del tipo,  
22:59
`a` il nome della variabile. Le strutture sono  tipi di dati definiti dall'utente, come una  
23:06
classe in Python, per capirci. Poi posso usare  l'operatore punto (`.`) per accedere ai campi:  
23:15
`a.num = 1; a.den = 2;`. È più interessante  riferirsi ai campi con i propri nomi,  
23:42
invece che fare `f[0]`, `f[1]`; si genera  una confusione bestiale altrimenti.
24:08
Se io definisco un puntatore a una  struttura, per esempio `struct fract *b;`,  
24:16
e gli assegno l'indirizzo di `a` (`b =  &a;`), non posso usare più il punto. Se  
24:35
la variabile è un puntatore a una struttura,  invece del punto ci va la freccia (`->`).
25:58
Perché esiste questa distinzione? Il C è  progettato per essere esplicito. Semplicemente,  
26:04
quando vedi una freccia, sai che si  parla di un puntatore. È un'ottima idea  
26:25
per la leggibilità. Ora sarete sereni  quando userete il punto o la freccia.  
27:11
Penserete: "Ah, ecco, è solo perché è  un puntatore. Il C è fatto così. Fine".
27:40
Ora posso utilizzare questa roba per riscrivere  il mio programma. `print_fraction` cambia:  
28:00
`void print_fraction(struct fract *f)`. E qui  è divertente, perché questo diventa `f->num`  
28:08
e `f->den`. Questo è meglio, no? Si capisce che  stai stampando il numeratore e il denominatore. Io  
28:37
posso tradurre questo programma in maniera  meccanica. Dove c'è scritto `f[0]` metto `f->num`.  
28:53
Qui: `malloc(sizeof(struct fract));`. È un  po' cacofonico questo `struct`. Guardate  
29:10
com'è bello questo: `f->num = num; f->den  = den;`. È così che dovrebbe funzionare il  
29:16
mondo! Scherzo, però si capisce che  tutto è più sensato in questo modo.
29:23
Vi volevo fare vedere una cosa. Con l'operatore  asterisco (`*`) posso prendere il valore a cui  
29:31
punta un puntatore. Allo stesso modo, in  `sizeof`, posso scrivere `sizeof(*f)`,  
29:47
che è uguale a `sizeof(struct fract)`, però  è più compatto, e io di solito faccio così.
30:06
Che cosa abbiamo sbagliato? `struct  fract *`... il valore di ritorno di  
30:12
questa funzione. E ora funziona tutto come prima.
30:29
In realtà, lo sapete che le strutture  possono essere anche ritornate come   valore? E ciò è veramente strano, perché  il C finora ha manipolato solo numeri.  
31:02
Però se il C può ritornare addirittura le  strutture, allora veramente la struttura  
31:08
è un tipo di dati. Guardate, io avrei  potuto fare in modo che `create_fraction`  
31:20
ritornasse una `struct fract`, non un  puntatore. Quindi `malloc` lo tolgo e  
31:27
dichiaro la `struct` come una variabile locale.  Tolgo il check se è `NULL`, non ha più senso. Qui  
31:34
diventa `.` (punto) perché è una variabile,  non un puntatore, e io la posso ritornare.
31:40
Ma questa è una cosa strana, no? Che succede  quando ritorno una frazione? A questo punto  
31:48
`f1` e `f2` diventano `struct fract f1;` e `struct  fract f2;`. E siccome le altre funzioni prendono  
31:54
un puntatore, qua gli metto `&` prima del nome,  così passo il puntatore a queste strutture.  
32:13
Sotto sotto il C fa un'operazione di copia:  prende i byte della struttura ritornata e li  
32:24
copia nella nuova variabile. Quindi, mentre prima,  col puntatore, non c'era nessuna copia implicita,  
32:33
stavolta sì. Se ritornate strutture molto  grandi, il programma diventa inefficiente.
32:46
Di fatto, ritornare le strutture per valore non  si fa quasi mai. Bisogna sapere "sotto il cofano"  
32:58
come funziona, però sappiate che costringe  a una copia. Se è una copia di due interi,  
33:05
come in questo caso, non ci fa niente. E uno  può dire: "Quasi quasi creo un'interfaccia  
33:14
che eviti l'allocazione dinamica...". Quasi  quasi sarebbe stato meglio, in questo caso,  
33:38
usare questo stratagemma progettuale. Ma, di  norma, le strutture si passano per puntatore,  
33:50
vengono allocate nello *heap* e si  ritornano. Sono, di fatto, oggetti   che vivono nella memoria e che io posso allocare  e distruggere come voglio con `malloc` e `free`.
34:04
Mi sembra che per questa volta  ci siamo detti abbastanza cose,   per cui io vi saluto e vi do  appuntamento a sabato prossimo. Ciao!

Lesson 14 - My notes
struct-base.c:
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

/* Internal layout:
 * +----+----+----+
 * |num |den ||c   |
 * +----+----+----+ 
 * struct must be aligned to its type max size
 */
struct fract {
    int num;
    int den;
    unsigned char color;
};

/* creating a new fraction, setting num and den as the numerator
 * and denominator of the fraction.
 * The fraction return NULL on out of memory otherwise
 * the fraction object is returned 
 * Note: Returning the struct by value and not pointer cause memory copy in the assegnation
 * moment, so it is highly raccomended to use a pointer for returning stuct */
struct fract *create_fraction(int num, int den) {
    struct fract *f = malloc(sizeof(*f));
    if (f == NULL) return NULL; // malloc error checking
    f->num = num;
    f->den = den;
    return f;
}

/* Simplify the provided fraction */
void simplify_fraction(struct fract *f) {
    for (int d = 2; d <= f->num && d <= f->den; d++ ) {
        while (f->num % d == 0 && f->den % d == 0) {
            f->num /= d;
            f->den /= d;
        }
    }
}

void print_fraction(struct fract *f) {
    printf("%d/%d\n", f->num, f->den);
}

int main (void) {
    printf("%d\n", (int)sizeof(struct fract)); // 12

    struct fract a; // class concept
    struct fract *b = &a;
    b->num = 1;
    a.den = 2;
    printf("%d/%d\n", a.num, a.den);

    struct fract *f1 = create_fraction(10,20);
    struct fract *f2 = create_fraction(3,4);
    simplify_fraction(f1);
    simplify_fraction(f2);
    print_fraction(f1);
    print_fraction(f2);
    return 0;
}


Lesson 15 - Lesson Link: https://www.youtube.com/watch?v=aTT2W5NACEY&list=PLrEMgOSrS_3cFJpM2gdw8EGFyRBZOyAKY&index=16

Lesson 15 - Transcript:
0:01
C'eravamo lasciati qui, avevamo implementato...
0:09
Miseria, parlano i vicini, bastardi.
0:14
Dicevo, avevamo implementato queste frazioni e  c'eravamo illusi di capire come funzionano le  
0:23
strutture. In realtà, non abbiamo capito nulla  fin quando non facciamo un salto in là. Allora,  
0:34
avete presente il comando in Unix `cat`? Io,  per esempio, posso fare `cat bst.c` e lui mi  
0:45
mostra il contenuto del file. C'è un comando che  è l'inverso di `cat` che mostra il contenuto del  
0:56
file al rovescio. Guardate, questa è la prima riga  del file, viene stampata come ultima, e così via.  
1:02
Proviamo a reimplementare questo  comando, e la reimplementazione di  
1:08
questo comando farà sì che noi esploreremo  le strutture in un modo completamente nuovo.
1:14
Allora, per implementare questo comando a  me serve fare una cosa: devo caricare le  
1:23
righe del file una dopo l'altra e memorizzarle  in una struttura dati che mi permette poi,  
1:30
molto facilmente, di scorrerle  dalla prima fino all'ultima,  
1:36
ma in ordine inverso, quindi  dall'ultima fino alla prima.
1:42
Scusate, devo dire ai miei di smetterla  di urlare... anzi no, non ce la farò mai.  
1:57
Quindi spostiamo il computer nell'altra  camera. Niente, oggi vi rendo partecipi.  
2:05
Andiamo nella stanza del mio caro fratello  che purtroppo se n'è già andato a Vienna.
2:11
Dicevo, ho bisogno di caricare queste linee di  testo in memoria e poi stamparle al contrario.  
2:18
Tanto per iniziare, allora: `tac.c`.  `include `. Tanto per iniziare,  
2:24
come si fa a leggere le linee di  un file? Allora, siccome ora non  
2:28
vogliamo gestire l'apertura e la chiusura  dei file, facciamo una cosa più semplice:  
2:35
le leggiamo dallo standard input,  cioè quelle che arrivano... Anzi no,  
2:40
dovrei introdurre il concetto di standard input,  è peggio, perché dobbiamo parlare già di POSIX,  
2:45
di Unix, di un sacco di roba. Quindi introduciamo  l'apertura dei file perché è molto facile.
2:50
`int main()`, anzi non `void`. Allora, la `main`,  se uno vuole, invece di essere una funzione `void`  
2:59
che non riceve niente, può ricevere un numero di  argomenti e delle stringhe che sono gli argomenti  
3:10
che io passo al mio programma. Allora, vi faccio  un esempio per farvi capire com'è che funziona e  
3:16
poi vi dico che cos'è questo `char **argv`,  questo puntatore a puntatore a carattere.
3:23
`for (int i = 0; i < argc; i++)  { printf("%d %s", i, argv[i]); }`
3:41
Quindi guardate, io praticamente... qua `argc`  è il numero di parametri che a me passano dalla  
3:47
command line quando io eseguo un programma, tipo  `ls ptr1.c`. Questo programma ha due argomenti:  
3:54
il nome del programma stesso e il secondo  argomento, il file (in questo caso è un  
3:59
nome di un file). Quindi qua, in questo  caso, `argc` sarebbe 2. E `argv` che cos'è?  
4:05
Siccome ogni stringa è un puntatore a un array  di caratteri, e quindi sarebbe... ogni stringa  
4:11
ha un puntatore a `char`. Se io ho un array  di puntatori a `char`... quindi, praticamente,  
4:20
guardate com'è in memoria: ogni stringa è, per  esempio, all'indirizzo 1000 c'è questa stringa,  
4:28
all'indirizzo 1100 c'è questa stringa,  all'indirizzo 1200 c'è questa stringa.  
4:34
Quindi ognuno di questi indirizzi di memoria  io lo registro in un `char` puntatore,  
4:39
`char *`, che per esempio vale 1000 per la prima  stringa, vale 1100... Ma io voglio un array,  
4:48
quindi un array contiguo in cui ci sono tutti  questi puntatori uno appresso all'altro.
4:54
Quindi, questi sono indirizzi di memoria  dove sono registrate le stringhe, però il  
5:07
nome stesso della variabile sarà l'indirizzo.  Quindi `argv` sarà l'indirizzo di memoria dove  
5:16
è registrato un array di indirizzi di memoria  `char*`, e quindi c'ho i due asterischi, ok?  
5:27
Perché `argv`... se io avessi dichiarato  `char *argv[10]`, io dichiaravo un array di 10  
5:38
elementi, 10 puntatori a `char`, quindi un  array di 10 puntatori a stringhe. In effetti,  
5:45
siccome vedete che qua ci sono anche le parentesi  quadre, questo è un puntatore a sua volta,  
5:51
io mi troverei un puntatore di puntatore al tipo  `char`, quindi un `char **`. Così come quando io  
6:00
dichiaro una stringa `s`, che è semplicemente una  stringa e la inizializzo a del testo qualsiasi,  
6:09
`char *s` è un puntatore a carattere.  Ok, spero di essere stato chiaro,  
6:17
ma purtroppo siamo stati forzati qua a  dichiarare questo tipo perché così è.
6:24
Allora, vediamo che fa questo programma. Quindi,  `gcc tac.c`. `./a.out foo bar`. Vedete? `argv[0]`  
6:37
è `./a.out`, quindi il primo argomento del  programma. `argv[1]` è `foo`, `argv[2]` è `bar`.
6:51
Quindi, praticamente, `argv` rappresenta  l'indirizzo di memoria al quale sono  
6:57
memorizzati degli indirizzi di memoria, e ognuno  di questi indirizzi di memoria è l'indirizzo di  
7:05
memoria al quale è memorizzato un array di  caratteri che è la mia stringa. D'accordo?
7:12
Per tornare qui... Ah no, che fa? L'avevo  cancellato. Ci voglio tornare su questa cosa.  
7:19
Allora, mettiamo che all'indirizzo 1000 c'è  scritto `foo`, all'indirizzo 2000 c'è scritto  
7:25
`bar`. Sono tutti indirizzi di memoria, solo  che qui, questo è 2000, l'indirizzo di memoria  
7:39
a cui sono registrati i caratteri, quindi `char  *`. Questo invece è l'indirizzo di memoria a  
7:49
cui sono registrati indirizzi di memoria a cui  sono registrati i caratteri. Quindi `char **`.
8:01
Allora, per aprire i file in C,  immaginiamo che `argc` valga 2,  
8:12
perché dobbiamo avere il nome del programma  e il nome del file che noi vogliamo aprire.  
8:16
Quindi `if (argc != 2) { printf("Missing file  name\n"); return 1; }` e ritorniamo questo errore.
8:38
Se invece il `filename` ce l'hanno dato, ed  è `argv[1]`, questo è il puntatore al nome.  
8:47
Dichiariamo un puntatore di tipo `FILE`. Poi  vedremo perché è possibile scrivere `FILE`,  
8:53
ma tutto ciò si cela in una keyword che si chiama  `typedef`. In realtà questa è una struttura,  
8:59
tipo `struct FILE`, non lo so, però si  può dare a una struttura un nome unico,  
9:08
singolo, senza dover usare `struct`, con  `typedef`. Si può dare un nome anche ad  
9:12
altri tipi di dato che non sono  strutture. Poi vedremo `typedef`.
9:17
Quindi `FILE *fp`. E qua chiamerò la chiamata  `fopen`. Andiamo a vedere come funziona. Allora,  
9:24
`fopen` c'ha prima `char *path`, quindi  gli devo passare un puntatore a carattere  
9:34
col nome del file, e poi un puntatore  a carattere, un'altra stringa, con la  
9:41
modalità di apertura del file. Praticamente  facciamo prima a far vedere come si fa:  
9:45
`argv[1]` è il nome del file e qui gli passo  una stringa che contiene semplicemente il  
9:50
carattere 'r' per dirgli che voglio che  il file sia aperto in read-only mode.
9:55
Se `fp` mi ritorna `NULL`, significa che il  file non esiste. Lui qua in teoria mi alloca  
10:04
una struttura e mi restituisce il puntatore  a questa struttura che rappresenta il file,  
10:10
ok? Il file che avevo aperto. Ma  mi ritorna nullo se il file non  
10:14
c'è. Quindi io qua scriverò `printf("File  does not exist\n"); return 1;` di nuovo.
10:28
Altrimenti, qui stamperò le linee del file, e poi  vedremo come si fa, e poi io dovrò chiudere questo  
10:33
file. Si fa con la chiamata di libreria, non di  sistema... c'è una differenza che poi vedremo  
10:44
più avanti in questo corso. Quindi `fclose`, gli  passi il puntatore al file che ti ha ritornato  
10:51
`fopen`. Quindi `fopen` ti ha ritornato `fp`,  che tu utilizzerai per manipolare il file in  
10:56
tutti i modi: leggere, scrivere, quello che  ti pare. E poi chiami `fclose`. `return 0`.
11:02
Compiliamo questo programma. `./a.out  test.txt`... `test.c` perché esiste davvero,  
11:09
e quindi non succede niente. `test.blablabla`...  `File does not exist`. Ci siamo? Bene.
11:19
Ora, per registrare in maniera agevole,  veloce, semplice e che ha senso dal punto di  
11:27
vista algoritmico tutte le righe che io leggo dal  file, userò una struttura particolare. Ma prima vi  
11:36
faccio vedere come si fa a leggere ogni riga. Per  leggere righe dal file si usa la chiamata `fgets`.  
11:43
Guardate qua, io gli passo `char *`, un buffer,  un array di caratteri. Qua gli dico quanti byte è,  
11:53
così che non venga scritto oltre. E  qua gli passo il puntatore al file.
12:01
Quindi, `fgets`. Dichiaro qua un buffer, `char  buf[1024]`. Io gli dico `buf`, `sizeof(buf)` (che  
12:18
mi ritorna 1024). Ma il vantaggio di fare così è  che se io qua scrivo 2024, ancora qua il programma  
12:23
funziona. Ok. `fp`. Allora, questa chiamata qui  mi riempirà il buffer con la prossima riga del  
12:31
file. D'accordo? Quando il file è finito (end of  file), non ci sono più righe, ritornerà `NULL`.
12:41
Quindi io faccio così:  `while (fgets(...) != NULL)`.  
12:47
Noi per ora ce ne fregheriamo del buffer overrun,  del fatto se questa stringa è sempre terminata,  
12:55
se ci sono righe più grandi o meno  di 1024... fregatevene di tutto ciò,  
12:59
non ci interessa oggi. Invece quello che ci  interessa è che io stampo qui `%s`, `buf`, il mio  
13:09
buffer. Ok? Quindi faccio questo ciclo `while`,  ogni volta leggo una riga. Quando `fgets` ritorna  
13:14
`NULL`... perché che cos'è che ritorna `fgets`?  `fgets` ritorna o `NULL` o in realtà il puntatore  
13:22
al buffer. Ma è inutile che io me lo leggo perché  lo so qual è il puntatore al mio buffer: è `buf`.
13:31
Guardate questo programma che cos'è che fa.  `./a.out tac.c`. Ecco, guardate, ho sbagliato  
13:43
una cosa, perché io qua ho messo il newline, ma in  realtà `fgets` il newline già lo legge dal file,  
13:55
cioè ti legge la riga incluso il newline. Quindi  qua togliamo questo "andate a capo" quando  
14:01
stampiamo. `tac.c`. E guardate, praticamente  ho ricreato finora il programma `cat`,  
14:09
anche se sarebbe un `cat` buggato, perché se le  righe sono maggiori di 1024 non funzionerebbe più,  
14:14
invece `cat` deve essere binary safe,  eccetera, eccetera. Fin qui ci siamo.
14:25
Allora, come faccio a registrare mano a  mano tutte le entry in ordine rovesciato?  
14:35
Guardate, dichiaro una struttura `struct line`.  Ogni linea del mio file. E gli metto un puntatore,  
14:48
che chiamo `s`, un puntatore a carattere  `s`, dove ci sarà effettivamente la stringa  
14:55
che ho letto. E guardate: `struct line  *next`, un puntatore allo stesso tipo  
15:05
della struttura che io sto dichiarando, che  punta al prossimo nodo della struttura. Ok?
15:15
Quindi io leggo la prima riga dal mio file,  creo (ora vi faccio vedere come) questo  
15:22
oggetto `struct line`. Dopodiché,  quando io leggo la seconda riga,  
15:31
quella che era la prima in realtà diventerà il  puntatore `next` della seconda. Quindi guardate,  
15:39
già ho invertito l'ordine di queste due entry.  Se poi parto dall'ultimo e navigo sempre `next`,  
15:45
finirò per andare dall'ultima riga  del file che ho letto fino alla prima.
15:51
Allora, guardiamolo qui in maniera più esplicita.  
15:55
Vi ricordo che io qua non controllerò il valore  di ritorno di `malloc`, me ne fregherò altamente.
16:05
Allora, ho una nuova riga, è dentro il mio buffer.  
16:11
Quindi io faccio `struct line *l =  malloc(sizeof(struct line));`. Ho  
16:21
allocato un pezzo di memoria dove ci può  andare la mia struttura. Quindi saranno 16  
16:29
byte in questo computer, perché sono 8 byte il  primo puntatore, 8 byte il secondo puntatore.
16:36
`l->s`, guardate, devo usare la freccia perché  questo è un puntatore a una struttura. `l->s`  
16:43
dove ci va la mia linea, sarà `malloc(strlen(buf)  + 1)`. `strlen` mi ritorna la lunghezza di questa  
16:59
stringa qua. Quindi lui cerca il primo byte a zero  e mi ritorna quanti caratteri ha contato, più uno  
17:06
perché c'è pure il terminatore a `NULL`. Io faccio  spazio perché ovviamente non è che posso assegnare  
17:12
`l->s = buf`, perché `buf` è sempre lo stesso  buffer e io lo riutilizzo, altrimenti tutti i nodi  
17:17
del mio file sarebbero tutti settati all'ultima  riga che ho letto. Invece io voglio ogni volta  
17:25
copiare la linea del file, quindi alloco  abbastanza memoria per farci stare sta linea.
17:35
E poi uso la funzione `memcpy` che copia tot byte  di memoria... Guardate, potevo farlo con un ciclo,  
17:42
facciamo con un ciclo `for`, va. Facciamo  una cosa: `size_t linelen = strlen(buf);` Ok,  
17:55
quindi qua facciamo `malloc(linelen +  1)`. Ok? `for (size_t j = 0; j <= linelen;  
18:09
j++) { l->s[j] = buf[j]; }`. Invece di usare  la `memcpy` io faccio la copia qui a manina,  
18:28
giusto per non introdurre complessità al di  fuori del concetto che noi stiamo esplorando  
18:33
oggi in questa lezione. Quindi ho copiato pure il  null terminator, sono andato uno oltre `linelen`.
18:46
E poi guardate, io qua prima mi creo un  puntatore `struct line *` che chiamo `head`,  
18:58
è la testa della mia lista. All'inizio  io lo setto a `NULL`. Guardate perché,  
19:02
ora ve lo faccio vedere. `l->next` sarà uguale  a `head`. Quindi, praticamente, all'inizio,  
19:12
siccome non ho nessun oggetto ancora di  `line` e ho iniziato ora, il puntatore,  
19:20
diciamo, all'ultima linea che ho letto sarà  `NULL`. Quindi, quando praticamente io creo  
19:25
la mia prima struttura, il `next` sarà `NULL`.  Ma guardate poi quando questo ciclo reitera,  
19:33
perché io guardate che faccio: scrivo  così, a parte che questo va giù,  
19:38
`l->next = head;` e poi scrivo `head = l;`.  Quindi stavolta la testa diventa l'ultimo nodo.
19:48
Quindi quello che succede è questo. Mettiamo  che io c'ho tre righe: `one`, `two`, `three`.  
19:55
Io leggo la prima riga e diventa una struttura.  In `s` c'è scritto `one`, in `next` c'è scritto  
20:04
`NULL`. `head` prima era uguale a `NULL`. Ok.  Subito dopo, mettiamo che questo qui è registrato  
20:15
all'indirizzo di memoria 1000. Poi `head` è uguale  a 1000. Ok. Poi io leggo un'altra riga. Per dire,  
20:27
questo qui è registrato... `malloc` mi ritorna  l'indirizzo di memoria 2000, qualsiasi esso sia.  
20:32
`s` diventa `two`, `next` io lo setto a `head`,  ed è 1000. Ok. E ora `head` diventa 2000. Vedete?  
20:46
Se io ora parto da `head`, prima scriverei `two`.  Poi se seguo il puntatore `next` andrei qua e poi  
20:52
scrivo `one`. Vedete che sto registrando i miei  oggetti linea concatenati al contrario. Questa si  
21:02
chiama, nella teoria della programmazione,  una lista linkata, una linked list.
21:14
Benissimo. Quando io ho finito di fare  questa lettura, chiudo il file e poi  
21:19
guardate che faccio: `while (head != NULL)`,  potevo scrivere anche solo `while (head)`.  
21:38
Stampami `head->s`, la stringa che questo  nodo della mia linked list rappresenta. E  
21:48
poi `head = head->next`. Quindi questo puntatore a  questo nodo diventa il puntatore al prossimo nodo.
21:57
Se io ora compilo questo  programma non funziona una fava.  
22:08
Che avrò sbagliato io? Che cos'è che dice?  `undeclared identifier 'j'`. Ah, sì, `for  
22:17
(int j = 0...`. `undeclared 'malloc'`. `include  `. `strlen`, `include `.
22:49
In realtà questo qui deve essere  non `int` per essere corretto,  
22:53
ma `size_t`, così come `strlen` mi ritorna  `size_t`. Vedete? Compiliamo. Boh. Molto  
23:05
bene. `./a.out tac.c`. Esattamente. Guardate,  vedete che mi ha stampato tutto al contrario.
23:20
Questo è l'output.  
23:23
Ora usiamo davvero `tac`, ed è identico. Vedete,  i due programmi restituiscono lo stesso output.
23:34
Ora voi credete di aver già capito tutto  di questo programma. Invece è possibile,  
23:40
non è detto, che vi manca il passaggio decisivo.  Noi qui siamo di fronte a un'astrazione che finora  
23:49
in tutte queste puntate non avevamo mai visto.  Questo è un salto mentale enorme. A questo punto,  
23:57
io col C ho inventato un'astrazione. A me di  dove sia allocata ognuna di queste linee non  
24:05
me ne frega più niente. Ho chiamato `malloc`, gli  faccio fare questo compito all'allocatore. Io mi  
24:10
disinteresso completamente di dov'è questo pezzo  di memoria, ma so che questo pezzo di memoria poi  
24:16
è linkato a un altro che è da qualche altra parte,  fin quando la memoria del computer mi basterà.
24:22
Ho costruito una nuova astrazione, un nuovo  modello mentale. Io c'ho degli oggetti che  
24:27
esistono da qualche parte nella memoria del mio  computer, non so dove, che sono linkati e creano  
24:34
delle strutture dati astratte. Nella mia testa,  e nel calcolatore, sono reali, ma io ci ragiono  
24:41
in termini astratti. Posso navigarle con una  determinata complessità. Io prima ho utilizzato  
24:49
O(n), quindi un tempo proporzionale al numero  di righe che ci sono nel file, considerando  
24:55
che le righe sono a dimensione massima, quindi  considero O(1) la `fgets`, in tempo costante,  
25:02
anche se poi le cose sono un po' più complicate.  E poi io posso di nuovo navigare il file  
25:08
dall'ultima riga alla prima utilizzando un tempo  costante per ogni linea, e quindi di nuovo O(n).
25:16
Quindi questo programma è efficiente per  quello che deve fare, ma ha il grandissimo  
25:21
difetto che alloca tanta memoria, perché  prima carica tutto il file in memoria,  
25:28
cosa che un'implementazione furba di `tac`  potrebbe benissimo evitare. Ma a noi ci  
25:34
interessava capire che le strutture sono  una grandissima astrazione, perché io le  
25:40
strutture le alloco, diventano degli oggetti,  possono avere dei puntatori ad altre strutture,  
25:45
dello stesso tipo o di altri tipi, e quindi  creare un grafo, creare strutture dati,  
25:50
creare una nuova astrazione che è sostanzialmente  uno dei capisaldi della programmazione in C.
25:58
Scusate se questo video forse è stato un po'  meno organico degli altri. Ero molto stanco,  
26:02
era tardi, ma ci tenevo a farlo. Un saluto.


Lesson 15 - My Notes
tac.c:
