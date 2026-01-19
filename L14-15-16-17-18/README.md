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
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// inversion of the file rows

// linked list
struct line {
    char *s;
    struct line *next;
};


// ./.a.out [filename]
int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Missing file name\n");
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("File does not exist\n");
        return 1;
    }

    char buf[1024];
    struct line *head =NULL;
    while (fgets(buf,sizeof(buf),fp) != NULL) {
        struct line *l = malloc(sizeof(*l));
        size_t linelen = strlen(buf);
        l->s = malloc(linelen+1);
        for (int j = 0; j <= (int)linelen; j++) {
            l->s[j] = buf[j];
        }
        l->next = head;
        head = l;
    }

    fclose(fp);

    while (head != NULL)
    {
        printf("%s", head->s);
        head = head->next;
    }
    

    return 0;
}


Lesson 16 - Lesson Link: https://www.youtube.com/watch?v=VPs_QtlLNcs&list=PLrEMgOSrS_3cFJpM2gdw8EGFyRBZOyAKY&index=17

Lesson 16 - Transcript
0:40
Quando ci siamo bloccati per approfondire  le strutture, eravamo arrivati qui. Allora,  
0:47
avevamo detto: ci potremmo mettere qua una  lunghezza delle nostre stringhe prefisse,  
0:54
un contatore delle nostre stringhe prefisse.  Io qua avevo iniziato a dire, allora, dovremmo  
0:58
fare `uint32_t len`, pointer, poi ci metto il  count. Il count lo faccio andare ad essere +4,  
1:07
perché guardate qui il layout. Quindi questo  è l'offset 0, questo è l'offset 4 dentro la  
1:13
mia allocazione e all'offset 8 inizia la  stringa. Infatti, qua facciamo s += 8,  
1:19
e allora poi ci siamo fermati per trattare,  diciamo, le strutture, ma finalmente abbiamo  
1:25
la possibilità di utilizzare le strutture  per implementare questa libreria di stringhe.
1:31
Quindi, io scriverò `struct`. Questo si chiama  `pls` e scrivo `uint32_t len; uint32_t refcount;`.  
1:47
Siccome la struttura ha i campi che sono  correttamente allineati, allineati in maniera  
1:57
naturale, si dice, quindi questo è un campo  di 4 byte allineato all'offset 0, questo è  
2:04
di 4 byte allineato all'offset 4. L'offset 4 è  multiplo della dimensione del campo di 4 byte,  
2:11
quindi non ci saranno spazi, non ci sarà niente  di strano. E qua, invece, facciamo `char str[]`.  
2:17
Qui usiamo la dichiarazione in stile C99. Se  non mi sbaglio, è stato introdotto in C99. Tu  
2:25
metti le parentesi quadre aperte. Significa che  questo in realtà sarà un puntatore all'offset 8  
2:32
di tipo char, ma non si sa quanti byte verranno.  Quindi la grandezza effettiva della stringa è  
2:39
controllata dalla grandezza dell'allocazione  che poi noi eseguiamo con `malloc`.
2:44
A questo punto, guardate qui che cos'è  che succede. Allora, tanto per iniziare,  
2:51
la dimensione dell'allocazione con `malloc` la  riscrivo e scrivo `sizeof(struct pls) + len + 1`.  
3:12
Allora, qua facciamo una cosa: l'allocazione io la  scrivo in `struct pls *p`, chiamiamolo puntatore,  
3:26
la chiamo p, che è, diciamo, l'abbreviazione di  'prefixed', è uguale a `malloc(sizeof(struct pls)  
3:34
+ len + 1)`, che è il mio header più la lunghezza  della stringa più un byte per il null terminator.
3:40
A questo punto, questi due non mi servono più  ovviamente, e poi mi tengo pure un puntatore.  
3:52
Allora, qua guardate, c'era `len_pointer = &len`.  Qua, in realtà, ora dobbiamo fare `p->len = len;`  
4:00
`p->refcount = 1;`. Nelle interfacce di  programmazione in cui si usa il reference  
4:07
counting, di solito è buona norma che la funzione  che crea l'oggetto restituisca l'oggetto con il  
4:14
conto di referenze a uno, perché comunque chi  l'ha chiamata questa funzione la memorizzerà da  
4:20
qualche parte questa referenza, e quindi è giusto  inizializzarla a uno e non a zero, anche perché  
4:25
altrimenti non si potrebbe più liberare perché  non potrei chiamare `ps_free` o `ps_release`,  
4:34
`ps_retain`. Di solito si usa una funzione  `retain` che aumenta il conto delle referenze,  
4:39
e una funzione `release` che decrementa il conto  
4:41
delle referenze. Io così posso fare con  `ps_create` la creazione della stringa,  
4:46
poi con `ps_release` decremento di uno il  reference counting, va a zero e lo libero.  
4:52
Quindi il conto della referenza iniziale  deve essere uno, ha senso che sia così.
5:00
Dopodiché, a me serve... ah no, in realtà non mi  serve più il puntatore `s` perché io utilizzerò  
5:08
`p->str`, perché vi ricordate che qui c'ho il  mio `str` interessante. Quindi `for (int j = 0;  
5:17
j < len; j++)` e poi qui scriverò  `p->str[j] = init[j];` e `p->str[len] = 0;`.  
5:32
A questo punto, voglio ritornare `p->str`,  quindi il puntatore all'inizio della mia stringa.
5:41
Vediamo le altre funzioni com'è che variano.  Quindi, io qua sempre mi becco nella mia  
5:47
`ps_print` il puntatore a `p->str`. Qui in realtà  quello che devo fare è `struct pls *p = (struct  
6:00
pls *)(s - sizeof(*p));`. Ma invece di scrivere  `sizeof(struct pls)`, posso scrivere, come vi  
6:10
avevo spiegato in una lezione precedente,  `sizeof(*p)`, che è la dimensione dell'oggetto  
6:22
che prenderei da questo puntatore se utilizzassi  l'operatore di dereferenziazione. Quindi,  
6:31
praticamente questa è una forma, io tendo a  scriverla così per una questione di brevità.  
6:38
Dopodiché, qui il `len_pointer` non mi serve  più, ma io scrivo qua `p->len`. Come vedete,  
6:47
così il codice è meglio documentato. Qui a questo  punto potrei usare `p->str[j]` per essere più  
6:59
esplicito in quello che succede. Probabilmente  è una buona idea. Non cambia una mazza.
7:07
`ps_free`... io voglio che non esista più;  la chiamo `ps_release`. A questo punto non  
7:13
esiste più il concetto di creare l'oggetto —  ancora c'è — ma di liberare l'oggetto. Io creo  
7:20
l'oggetto col conto delle referenze a uno,  posso aumentare questo conto delle referenze  
7:25
o decrementarlo. Se arriva a zero ci sarà la  `free`. O meglio, la `ps_free` io me la tengo,  
7:32
ma è una funzione che più o meno non chiamerà  più nessuno. Questa funzione non fa altro che  
7:38
fare `free(s - sizeof(struct pls));`. Chiudiamo  le notifiche dal cellulare. Don't allow. Quindi  
7:53
vado a liberare l'allocazione. Io vi ricordo che  per liberare un'allocazione che ho eseguito con  
7:58
`malloc`, poi la `free` deve essere chiamata  nel puntatore che mi ha restituito `malloc`,  
8:02
non da qualche parte dentro l'allocazione, deve  essere l'inizio. Quindi, io vado a fare questa  
8:08
sottrazione del puntatore `s` per arrivare di  nuovo al puntatore che mi ha restituito `malloc`.
8:18
A questo punto, però, dobbiamo aggiungere  `ps_release(char *s)`. Questo lo copiamo,  
8:31
mi becco il puntatore alla struttura  e poi scrivo `if (p->refcount == 0)`.  
8:44
Qui, vabbè, guardate, per ora scrivo con la  `printf`, poi queste cose si gestiscono in  
8:50
maniera un po' diversa, ma capiamoci: `Aborted  on free error`. Perché se già il conto delle  
8:58
referenze è a zero, ok, c'è qualcosa che non  va, perché quando è zero già l'oggetto è stato  
9:05
liberato. Quindi o è stato liberato un oggetto  che è stato già liberato o addirittura è stata  
9:11
liberata un'allocazione che non è neanche  una stringa `pls` perché il programmatore  
9:15
ha sbagliato. Quindi se il `refcount` è a  zero, io stampo questo messaggio e `exit(1)`.  
9:21
Per `exit(1)` ho bisogno di `unistd.h`.  Questa è una chiamata di sistema, `exit`,  
9:28
che hanno molti sistemi operativi, ma noi parliamo  di Unix `man 2 exit`. No, in realtà la `exit`,  
9:41
scusatemi... anche se in realtà chiama, credo, la  `_exit` syscall vera e propria. Siccome il nome è  
9:50
uguale, in realtà noi di solito chiamiamo  la funzione di libreria che è in `stdlib.h`,  
9:56
e quindi noi, nel caso dell'exit, non  abbiamo bisogno di includere `unistd.h`.
10:02
Benissimo. Ora che cos'è che facciamo?  
10:06
`p->refcount--;`. Decrementiamo il conto delle  referenze. Se `p->refcount` è arrivato a zero,  
10:17
non ci sono più possessori di referenze a  questo oggetto. A questo punto, io chiamo  
10:22
la `ps_free` al mio puntatore e lo libero,  altrimenti non faccio niente, niente di niente.
10:33
Questo ritorna la lunghezza. Questo  cancelliamolo. Qua, guardate, diventa  
10:38
tutto abbastanza immediato. `return p->len`,  che io prendo il mio puntatore all'header.  
10:45
Una volta che c'ho la struttura come header,  diventa tutto più facile e ritorno `p->len`.
10:51
Ah, qua facevo questo esempio con la mia  `global_string`. Allora, qua vediamo. Qua faccio  
10:56
`ps_create`, poi facevo `ps_print` che ancora  funziona. Qua, invece, uso `ps_release`. Qua,  
11:05
guardate, c'è ancora il problema perché io,  vi ricordate, qua il codice ancora simulava  
11:10
un bug. Allora, tanto per iniziare, andiamo a  `ps_release` e implementiamo pure la funzione  
11:17
gemella `ps_retain`, che serve per incrementare  il conto delle referenze della mia stringa. Così  
11:24
possiamo fare ora anche la versione corretta  di questo programma. Mi prendo l'header e  
11:29
faccio `p->refcount++;`. Questo non fa altro che  incrementare il conto delle referenze. In realtà,  
11:36
sarebbe interessante anche qui mettere questo  controllo: `Aborted on retain of illegal string`.  
11:58
Scriviamo così, perché il conto delle  referenze non può essere zero e poi io  
12:04
vado ad aumentare il conto di queste  referenze. C'è qualcosa che non va,  
12:09
non dovrebbe essere mai zero. Quando  si arriva a zero è solo in questo caso,  
12:14
ma in questo caso poi l'allocazione viene liberata  e non si dovrebbe utilizzare di nuovo `ps_retain`.
12:20
Allora, `release`: drop the reference  count of the string object by one and  
12:31
frees the object if the refcount reached  zero. `retain`: increase the reference  
12:43
count of the string object. Vabbè, commenti  minuscoli perché qua ci interessa fare altro.
12:52
Allora, guardate, a questo punto io  con `ps_create` creo la mia stringa,  
12:57
poi la assegno a un altro puntatore. Quindi, dopo  che io faccio questa operazione di assegnazione,  
13:04
io qua devo scrivere `ps_retain(mystr)`. Ora sì  che ci siamo. Io ora, siccome ho due referenze,  
13:15
ho creato la mia stringa con reference  counting 1 e, in effetti, ha un "owner",  
13:21
la mia variabile locale `mystr`. Quando poi gli  creo una nuova ownership, uso `retain`. A questo  
13:30
punto il programma è corretto. Poi la stampo due  volte, poi la stampo scrivendo la sua lunghezza,  
13:36
poi la rilascio la prima volta. Tra l'altro,  ho dimenticato la bottiglietta d'acqua,  
13:43
mannaggia a me. Ora la stampo ancora perché  ha un altro riferimento. Uso l'altra variabile  
13:50
che ancora dovrebbe avere un riferimento  lecito. A questo punto faccio anche qui  
13:55
`ps_release` e ora il programma dovrebbe essere  corretto. Proviamo. Non funziona una mazza.
14:07
Allora, andiamo al primo errore, alla linea 28.  Questo si chiama `refcount` e questo è facile. Poi  
14:13
qua c'è un problema di inizializzazione. Esatto,  perché questo oggetto qua è un puntatore di tipo  
14:24
`char`, quindi io qua devo scrivere `struct pls  *`, un puntatore di tipo `pls`. E guardate qui,  
14:32
io devo mettere ovviamente le parentesi perché non  voglio che il casting sia di `s`, perché poi la  
14:39
sottrazione avverrebbe in maniera errata. Quindi  io per chiarezza specifico proprio quali sono i  
14:46
passaggi. Io ti dico: prima prendi il puntatore di  tipo `char`, che con la matematica dei puntatori,  
14:52
siccome il `char` è un tipo di 1 byte, significa  che se io sottraggo la grandezza della struttura,  
14:58
tu mi sottrai davvero quei byte, non li  moltiplichi per qualche altra cosa, li moltiplichi  
15:03
per uno, quindi restano invariati. Una volta che  io c'ho il nuovo puntatore, a questo punto tu mi  
15:08
fai il casting. Ora questa riga così com'è,  noi l'andiamo a copiare in vari altri luoghi  
15:17
in cui avevo parimenti sbagliato. Forse basta.  Esatto. E ora infatti il programma funziona.
15:28
Ora vi faccio vedere una cosa. Se  io qua gli metto un altro `release`,  
15:31
che la stringa era già stata liberata  sufficientemente volte... c'è un problema,  
15:40
perché io qua non sto vedendo l'errore  che avrei dovuto vedere. Vediamo perché.  
15:49
`ps_release`. Io dovevo arrivare qui perché  il `refcount` doveva essere zero. Allora,  
15:57
per vedere il debugging di ciò che accade,  noi ora quante chiamate `release` abbiamo? 1,  
16:02
2 e 3. Ah, ok. Qua manca la newline, tanto  per iniziare, quindi comunque l'errore forse  
16:10
non l'avrei visto per tale motivo. Quello era un  problema, ma non era il problema che avevamo noi.
16:18
Qui ogni volta che chiamiamo `retain` scriviamo:  `current ref count is...` e ce lo facciamo  
16:30
scrivere. `ref count is one`. Ah no, scusate, non  mi interessa nella `retain`, mi interessa nella  
16:44
`release`. `current ref count is...` questo numero  qua. Allora, guardate che cos'è che è successo  
17:00
qui. Qui è successo che noi nella `release`...  ah ok, semplicemente si è corrotto l'header. Ok,  
17:15
questo check semplicemente non avevamo  nessuna garanzia che davvero funzionasse,  
17:21
perché una volta che io praticamente libero la  stringa, libero l'allocazione, quello che succede  
17:29
è che `malloc`, dove c'era la mia allocazione,  ci può scrivere quello che gli pare. Infatti,  
17:34
quello che è successo in questo specifico  caso, guardate che cos'è. Perché io, quando  
17:39
poi arrivo veramente qua, che davvero faccio  la `ps_free`... e ora scrivo qual è il valore  
17:46
del `refcount`. Quindi ora sto scrivendo il valore  del `refcount`... l'allocazione a cui fa capo `p`  
17:53
non è più valida. Io mi aspetterei di trovare  uno zero, invece trovo un valore a casaccio.
18:00
Allora, com'è che ci si può  difendere da questi errori qua?  
18:06
Il modo per difendersi da questi errori, almeno  in parte, ma col problema di dover utilizzare  
18:14
più memoria, è il seguente. Qua possiamo usare un  campo che noi chiamiamo `magic`. Questo `magic`,  
18:28
quando creiamo la nostra stringa, lo settiamo a un  valore particolare: `0xDEADBEEF`, che è un numero  
18:44
a 32 bit. Ok? Una volta che ho questo magic,  guardate che facciamo qui. Quando io praticamente  
18:52
faccio la `release`, guardate, prima di fare la  `ps_free` io faccio `p->magic = 0;`. Ok? Invalido  
19:09
questo magic. Ora questo numero magico che ho, lo  uso come validatore che la mia stringa sia valida.
19:18
Quindi, guardate qua, facciamo una funzione che  chiamo `ps_validate` e qua gli diamo direttamente  
19:31
la struttura. Vabbè, questa ora la uso solo qua  nella `release`, ma noi in realtà la dovremmo  
19:38
usare nella `retain`, la potremmo usare in tutte  le funzioni che manipolano queste stringhe. E  
19:43
guardate che ci facciamo con questa `ps_validate`.  Scriviamola. `ps_validate(struct pls *p)`. `if  
20:00
(p->magic != 0xDEADBEEF)`... `printf("INVALID  STRING: Aborting\n"); exit(1);`. `validate that  
20:22
a PS string looks valid`. Vediamo se ora  funziona questo programmino qua. Esatto.
20:32
Allora, guardate, il programma funziona.  Appena praticamente io vado ad accedere  
20:36
a una stringa che non è più valida perché  è stata liberata in questa chiamata qui,  
20:43
vedrò questo messaggio qua. Ora, se  io questa chiamata invece la tolgo e  
20:51
compilo il programma, il programma  andrà avanti in maniera corretta.
20:55
Quello che ci possiamo chiedere a questo  punto è: val la pena di usare 4 byte in più  
21:03
in queste stringhe per avere questa salvaguardia?  Dipende. Può valerne la pena, può non valerne la  
21:08
pena. Ci sono anche le possibilità di fare, per  esempio: `#ifdef PLS_DEBUG ... #endif`. Questa  
21:18
è una direttiva del compilatore che se io il  programma lo compilo definendo a uno questa macro  
21:26
`PLS_DEBUG`, allora il `magic` ci sarà veramente.  Ovviamente questa cosa qui poi la devo mettere  
21:33
anche qui. Quindi potrei avere delle build, mentre  io faccio lo sviluppo, che hanno questa importante  
21:43
protezione per beccare i bug. Quando poi faccio  la build, quella che effettivamente sarà eseguita  
21:53
in produzione nei sistemi, potrei definire  `PLS_DEBUG` a zero e salvare questi 4 byte per  
22:02
ogni stringa. Queste sono considerazioni  che lascio alla vostra cara saggezza.
22:11
Benissimo, io direi che con questa puntata  abbiamo messo abbastanza carne al fuoco.  
22:16
Vi vorrei dire solo una cosa: qua, in  questo caso, come riferimento ulteriore,  
22:19
abbiamo messo `global_string`, un riferimento  globale esterno, ma potete immaginare anche che  
22:25
ci siano degli array che contengono alcuni...  un array, per esempio, potrebbe contenere,  
22:29
o una lista linkata come abbiamo visto  l'ultima volta, tutte le sottostringhe.  
22:34
Altre liste linkate potrebbero contenere solo  alcune sottostringhe, un subset che ha una qualità  
22:40
particolare. Io manipolo queste due diverse liste  linkate, a volte rimuovo una sottostringa da un  
22:45
insieme e mi basterà chiamare `ps_release`. Poi,  se per caso la stessa stringa è referenziata anche  
22:51
dall'altra parte, avrà `refcount` 2 perché  quando io l'ho inserita anche dall'altra  
22:55
parte avrò chiamato `ps_retain`, e quindi sono  tranquillo, come ho fatto qui con `ps_retain`.
23:01
Vedete, questa è sempre una gestione manuale  della memoria, ma è molto meglio di andare  
23:07
di `malloc` e `free` nude e crude ogni singola  volta. È un modo per prevenire errori e, inoltre,  
23:14
a differenza della gestione completamente manuale  della memoria, ci consente con queste cose qui,  
23:20
con questo trucco per esempio del `magic`,  di inserire delle salvaguardie che rendono la  
23:27
programmazione in C un pelo più sicura di come lo  è altrimenti. Bene, allora alla prossima lezione.

Lesson 16 - My Notes
pls.c:
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define PLS_DEBUG = 1;

struct pls {
    uint32_t len;
    uint32_t refcount;
#ifdef PLS_DEBUG
    uint32_t magic; // se setto la macro PLS_DEBUG a 1 magic viene inserita nella pls
#endif
    char str[]; // C99 - puntatore ad offset 6 di tipo char con byte dinamici
};

char *ps_create(char *init, int len) {
    struct pls *p = malloc(sizeof(struct pls)+len+1);
    p->len = len;
    p->refcount = 1;
#ifdef PLS_DEBUG
    p->magic = 0xDEADBEEF;
#endif
    for (int j = 0; j < len; j++) {
        p->str[j] = init[j];
    }
    p->str[len] = 0;
    return p->str;
}

/* Display the string "s" on the screen */
void ps_print(char *s) {
    struct pls *p = (struct pls*)(s - sizeof(*p));
    for (int j = 0; j < (int)p->len; j++) {
        putchar(p->str[j]);
    }
    printf("\n");
}

/* Free previously created PS string */
void ps_free(char *s) {
    free(s-sizeof(struct pls));
}


void ps_validate(struct pls *p) {
#ifdef PLS_DEBUG
    if(p->magic != 0xDEADBEEF) {
        printf("INVALID STRING: Aborting\n");
        exit(1);
    }
#endif
}

/* Drop the reference count of the string object by one
 * and frees the object if the refcount reached 0 */
void ps_release(char *s) {
    struct pls *p = (struct pls*)(s - sizeof(*p));
    ps_validate(p);
    
    p->refcount--;
    if (p->refcount == 0) {
#ifdef PLS_DEBUG
        p->magic = 0;
#endif
        ps_free(s);
    }
}

/* Increase the reference count of the string object */
void ps_retain(char *s) {
    struct pls *p = (struct pls*)(s - sizeof(*p));
    if (p->refcount == 0) {
        printf("ABORTED ON RETAIN OF ILLEGAL STRING\n");
        exit(1);
    }
    p->refcount++;
}

/* Return the length of the string in 0(1) time */
uint32_t ps_len(char *s) {
    struct pls *p = (struct pls*)(s - sizeof(*p));
    return p->len;
}

char *global_string;

int main(void)
{
    char *mystr = ps_create("Hello World", 11);
    global_string = mystr;
    ps_retain(mystr);

    ps_print(mystr);
    printf("%s %d\n", mystr, (int)ps_len(mystr));

    ps_release(mystr);
    printf("%s\n", global_string);
    ps_release(global_string);
    ps_release(global_string);

    return 0;
}


Lesson 17 - Link: https://www.youtube.com/watch?v=grkIJjw6o18&list=PLrEMgOSrS_3cFJpM2gdw8EGFyRBZOyAKY&index=18

Lesson 17 - Transcript:
0:40
Cari amici, oggi per noi è necessario andare ad approfondire  alcuni argomenti che sono stati toccati nella  
0:50
scorsa puntata e in alcune di quelle precedenti:  prefixed-length strings, quando abbiamo  
0:57
implementato questo file qui. Infatti, ci sono  stati molti dubbi. Ci sono stati dei dubbi che  
1:05
noi dobbiamo necessariamente sciogliere prima di  continuare. Ma magari, visto che questa puntata  
1:12
non può essere solo uno scioglimento di dubbi  perché sennò si potrebbe tradurre anche in un  
1:18
rompimento di scatole, la utilizzeremo anche per  far capire, se questa dovesse essere una libreria  
1:30
per uso in codice in produzione, come si arriva da  qui a una serie. Quindi esploreremo queste diverse  
1:39
cose. Secondo me la prima e più importante  questione è il dubbio di questo puntatore.
1:51
Primo problema: struct { int len; char str[];  }. La gente mi diceva: "Ma perché c'è scritto  
2:05
str[] invece di char *str?". Bene, queste due  cose sono completamente diverse e lo vedremo  
2:15
iniziando da questa definizione, quella  che le persone si aspettavano di trovare.
2:23
Includiamo stdio.h... stdlib.h  pure, non lo so, ora vediamo.
2:40
E scriviamo la nostra main. Allora, per  dire, io posso scrivere struct pls S. Poi  
2:56
devo inizializzare i miei campi: s.len è uguale a  10; s.str. A questo punto questo è un puntatore,  
3:06
quindi è, ricordiamoci cos'è un puntatore:  un numero, quindi è un intero. Devo questo  
3:14
puntatore allocarlo, perché altrimenti la mia  stringa dov'è che la registro? La mia stringa  
3:19
di 10 caratteri più il terminatore nullo. Mi  tocca scrivere malloc(10 + 1), che sarebbe 11,  
3:26
ma lo scriviamo così per sottolineare come il +1  sia per il null terminator. E poi io posso... c'è  
3:34
la funzione memcpy, che forse non avevamo visto  mai, che è una funzione molto importante del C.  
3:41
Si dà un puntatore di destinazione, un puntatore  sorgente e un numero di byte, e memcpy effettua  
3:48
la copia. Noi dentro la libreria avevamo usato un  ciclo for per palesare quello che stava accadendo,  
3:54
ma in C è idiomatico, è normale usare memcpy.  `memcpy(s.str, ...)` qua è il mio puntatore di  
4:02
destinazione. Il mio puntatore sorgente invece  glielo do così, come una stringa literal in C,  
4:10
quindi scritta direttamente nel sorgente.  Ma il C, quando compila questo programma,  
4:16
dentro una parte particolare della memoria  del programma allocherà questa stringa qui,  
4:24
fissa nel programma, in delle pagine che  di solito non possono essere modificate,   altrimenti il programma viene interrotto con  una violazione della memoria. Però trasformerà  
4:34
questa stringa letterale che io do qui in un  puntatore, quindi memcpy vedrà un puntatore.  
4:41
`memcpy("1234567890", ...)` sono 10 byte, virgola  11, perché vi ricordo che anche se questi sono  
4:50
10 byte, il C metterà alla fine il terminatore  nullo, quindi un byte a zero. E ora io mi posso  
4:57
chiedere qual è il layout... return 0. Peraltro,  io prima di farvi vedere il layout, volevo farvi  
5:05
vedere qui con printf, che è la printf che può  stampare un puntatore, che questo è un puntatore.
5:18
È definito in string.h.
5:26
Vedete che è un puntatore, cioè, lo stampa come un  puntatore, né più e né meno. Qual è in memoria il  
5:32
layout di questa roba qui? Prima di farvelo  vedere nella maniera più visuale possibile,  
5:39
ragioniamoci assieme. Quindi questo è un intero.  Quindi qua ci sono 4 byte, in questa macchina  
5:46
l'intero è di 4 byte. Poi c'è un padding, perché  siccome il puntatore è di 8 byte, perché è una  
5:56
macchina a 64 bit, c'è un padding. Quindi no, per  non avere questo padding qua, scriviamogli `long`,  
6:03
così questo intero qui è di 8 byte pure. Quindi  abbiamo 8 byte un intero, 8 byte un altro intero  
6:09
che è il puntatore, e questo puntatore conterrà  l'indirizzo di memoria che gli abbiamo assegnato  
6:15
qui. Ma per vedere queste cose per bene, proviamo  a scrivere una funzione molto carina. Guardate:  
6:22
void hexdump(...). Avete presente hexdump?  `hexdump -C` che significa "canonical".  
6:31
Io posso stampare dei file con  hexdump guardando gli offset,  
6:36
i byte e quello che contengono all'interno.  È molto carina questa cosa. Proviamo a fare  
6:43
una funzione hexdump, quindi `unsigned  char *`, anzi `void *p, size_t len`.
7:07
Facciamo una cosa. Allora, la lunghezza io la  considero... for `int j = 0; j < len; j++`.  
7:25
Partiamo con una versione semplice. Allora, tanto  per iniziare, io faccio che `unsigned char *byte`  
7:42
e lo assegno a `p`. `p` è `void *`, quindi  non ha bisogno di casting, è semplicemente un   indirizzo di memoria. Questo è un altro indirizzo  di memoria, ma questo è tipizzato. Io posso fare,  
7:51
qui in questo ciclo for in cui j va da 0 fino a  quanti byte ho, `printf("%02X ", byte[j])`. Questo  
8:01
specificatore di tipo, `02X`, stampa un numero che  io passo come intero, lo stampa come esadecimale,  
8:14
e io stampo `byte[j]`, quindi il mio byte. Ok?  Poi alla fine qua scriviamo un new line. Allora,  
8:24
quindi abbiamo questa semplice versione della  hexdump. Proviamo a usarla qui: `hexdump(&s,  
8:31
sizeof(s))`. Devo usare la e commerciale per  ottenere da S, che è una struttura, il suo  
8:41
puntatore. Questo è di quanti byte è composta.  Proviamo. Compiliamo. Ed ecco, guardate questo  
8:53
qui. Questi primi 8 byte sono il mio intero.  Siccome io avevo assegnato 10 alla lunghezza,  
9:01
vedete, qua c'è scritto... c'è solo un... siccome  questa macchina è little-endian, i byte meno   significativi, quelli che valgono di meno nel  numero, sono i primi. Nelle macchine big-endian,  
9:12
che vi ripeto, non esistono praticamente più  nell'informatica di oggi da un po' di anni,  
9:17
e la tendenza sembra quella che  le vedrà del tutto scomparire,  
9:23
avrebbero avuto 0A qui e qua avrebbero avuto  tutti zero, perché i byte più significativi in  
9:29
big-endian sono i primi e quelli meno  significativi gli ultimi. Dopodiché,   qua c'è il nostro puntatore. Guardate,  questo è il puntatore a `...060...032`  
9:41
perché lo dovete leggere al contrario,  perché è little-endian. Infatti, guardate,   io qua mi faccio anche stampare prima di hexdump,  mi faccio stampare 'sto puntatore `s.str`.
9:55
Guardate, il puntatore è `...6010` e qui guardate  cosa abbiamo: `...60...10`. I due byte iniziali  
10:04
sono zero, ma fanno parte del puntatore. Però,  ovviamente, qua nella printf... perché non è che  
10:09
se devo scrivere 10, io scrivo 0010, perché  non hanno valore. Quindi in questa struttura  
10:21
io ho effettivamente un puntatore a stringa che  esiste dentro la struttura e che occupa 8 byte.
10:32
Ora invece cambiamo le carte in tavola. Io  questa `str` la definisco come un array di  
10:46
20 caratteri. Ora, se ci ragionate,  io c'ho prima qui la mia lunghezza,  
10:54
ok? Quindi sono sempre i miei 8 byte, dopodiché  c'ho 20 caratteri, uno appresso all'altro.  
11:01
Quindi vedete che non c'è più un  puntatore registrato qua dentro,   e ora ci arriviamo bene. Però già io so che  ho una lunghezza e 20 caratteri. Non c'è più  
11:10
quel puntatore che io avevo quando  le cose erano definite diversamente.
11:17
Dovrei, per far funzionare il programma, cambiare  questa cosa qui pure, perché `str` non è più un  
11:22
puntatore, non ci posso assegnare niente, è un  array fisso dentro la struttura. Ma `s.str` verrà  
11:30
convertito dal C in un puntatore: il puntatore al  quale inizia questo array di 20 caratteri. Quindi,  
11:38
che cos'è che fa il C? Prende l'inizio  di S, ovunque fosse registrata S.  
11:47
Qualsiasi fosse l'indirizzo di memoria,  ci aggiunge 8, perché è l'offset di `str`,  
11:53
perché prima ci sono 8 byte di `len`. E  questo è il modo in cui compila `s.str`.
12:01
Ora io ci scrivo 'sta roba qua, 11 byte, e  rieseguo il programma esattamente com'era prima.  
12:10
Allora, guardate qua: ci sono gli 8 byte  e qua iniziano i byte della stringa che  
12:18
ho... gli ASCII 31, 32, 33 sono 1, 2, 3...  Infatti, la mia hexdump non era tanto carina.  
12:26
Facciamo una cosa... `if ((j+1) % 8  == 0)`... stampiamo in gruppi di 8.
13:00
Guardate, qua gli dico, se `(j+1)` diviso 8 ha  resto 0, quindi significa se questa cosa accade  
13:10
a 8, 16, 24 e così via, ma siccome i miei indici  partono da zero, io in realtà lo voglio fare a 7,  
13:21
15... quindi ci aggiungo uno a j.  Però poi ho un new line in più...
14:37
Sarebbe carino avere anche i caratteri leggibili.  Allora, facciamo una cosa più interessante.  
15:10
Se è multiplo di 8 o se `j == len-1`, se comunque  sto uscendo dal ciclo e quindi non c'è nessuno  
15:22
che potrà stampare il new line, stampa il new  line se è l'ultima iterazione. Così funziona.
15:35
Ora vi faccio vedere perché è stato utile  ricondurre la logica solo qui: perché ora  
15:44
noi facciamo un altro ciclo for. Prima del new  line, noi stampiamo un tab che ci sposta a destra  
15:53
e facciamo un altro ciclo. `int i = ...` Io voglio  sapere quando ho iniziato a stampare i caratteri.  
16:26
Allora, facciamo una cosa: `size_t po =  0`. Perché voglio stampare, oltre agli  
16:41
esadecimali, anche quelli leggibili,  human-readable. Quando io arrivo qua,  
16:51
voglio stampare tutti quelli... `for (size_t i =  po; i <= j; i++)`. Stampiamo anche il carattere,  
17:32
ma ora questo carattere lo dobbiamo stampare  in un modo speciale. C'è questa funzione di  
18:38
libreria del C, bisogna includere ctype.h, che  si chiama `isprint`, che è l'abbreviazione di "is  
18:46
printable". Questo carattere è stampabile  a video? Quali sono i caratteri stampabili?  
18:52
Sono quelli che non mi creano casini quando li  stampo. Quindi io, guardate che cosa faccio qua.
19:04
Facciamo `int c = isprint(byte[i]) ? byte[i]  : '.'`. Questo è l'operatore ternario.  
19:17
È stampabile? Allora uso `byte[i]`, altrimenti  il mio carattere sarà il punto. Prima vi faccio  
19:26
vedere che questa roba qui funziona e  poi vi spiego come. Includo ctype.h.
19:41
Ecco, vedete ora che succede? Io vedo  praticamente i caratteri. Però... 0A lui  
19:52
lo considera stampabile... no, qui il problema  è diversissimo. È che qui manca un uguale,  
20:14
perché io devo stampare da `po` a `j`  incluso. E poi qui è sbagliato, perché il  
20:43
prossimo byte che non ho ancora stampato è `j+1`.  Esattamente. Ora funziona tutto come dovrebbe.
21:11
Allora, vi devo una spiegazione su questa  riga. Ho usato uno strano operatore. `int  
21:21
c = isprint(byte[i]) ? ...`. Se questa condizione  è vera, la mia espressione ritorna questo,  
21:39
altrimenti ritorna questo. In sostanza, è  come se fosse un if. Prima viene valutata  
21:47
questa condizione, dopodiché il valore  di ritorno dell'espressione è questo a  
21:57
sinistra se la condizione è vera, o questo se  è falsa. Altrimenti, avrei dovuto scrivere `if  
22:08
(isprint(byte[i])) c = byte[i]; else c =  '.';`. Il programma funziona allo stesso modo.
22:48
Vi sarete forse chiesti come mai questi  byte finali variano, ma è perché noi abbiamo   inizializzato la nostra struttura fino a qui, fino  al puntino dopo lo zero, che è il null terminator.  
23:06
Dopodiché, la struttura è parte del programma  non inizializzata. Se vogliamo vedere bene la  
23:15
parte non inizializzata, potremmo fare che,  prima di `memcpy`, usiamo `memset`. `memset`,  
23:24
come `memcpy`, prende un puntatore di  qualsiasi tipo, un valore di un byte (FF,  
23:36
quindi 255), e la dimensione, e riempie  tutta l'area di memoria di quel byte.  
23:51
Se io ora compilo il programma e lo eseguo,  guardate, vedete che ora sono tutti FF le  
23:56
cose che io non ho inizializzato. Quindi  ho inizializzato la lunghezza, non è FF,   gli ho messo 'sta stringa fino a qua col  null terminator, il resto è tutto FF.
24:07
Ripristiniamo un po' di cose, togliamo la  `memset` e usiamo con vantaggio il nostro  
24:19
operatore ternario. Mi sembra che la nostra  hexdump funzioni in maniera accettabile.  
24:32
Sapete forse come l'avremmo dovuta migliorare?  Teoricamente uno dovrebbe usare una define,  
24:38
`HEXDUMP_CHARS_PER_LINE`, e la  settiamo a 8, o magari a 16.  
24:48
E qui usiamo questa define. Vedete com'è stato  bello unificare questa logica? E anche usare  
25:08
una variabile d'appoggio che ci ricorda fino  a che punto noi avevamo stampato i caratteri.  
25:13
Perché ora, così facendo, io credo che il  nostro programma funzionerà senza problemi.   Guardate com'è bello questo. Sembra un po'  l'output canonico che abbiamo visto poco fa.
28:36
E invece no, cari ragazzi, mi sono accorto che  qui un bug ce l'abbiamo. Guardate: quando è  
28:43
esattamente multiplo del numero di caratteri,  vengono stampati un sacco di padding inutili.  
28:51
Questa cosa qui la possiamo sistemare in vari  modi, ma il modo più semplice è, credo, questo  
28:57
qui. Aggiungiamo un modulo all'operazione di  padding per farlo tornare a zero quando non serve.  
29:04
Se `len % HEXDUMP_CHARS_PER_LINE` valeva  0, poi qua io faccio `16 - 0` e sono 16.  
29:22
Ma con questa istruzione qui ci togliamo questo  pensiero. Potevo scriverlo tutto dentro una linea,  
29:28
ma sarebbe stato meno chiaro. A  questo punto, la nostra funzione  
29:33
dovrebbe funzionare bene in tutti i casi.  E credo che stavolta ci siamo davvero.
29:58
E niente raga, guardate qua. C'è la  lunghezza, torniamo a 8 caratteri per riga.  
30:14
C'è la lunghezza, che sono i nostri 8 byte, e poi  qua inizia l'array. E allora, lo vogliamo capire  
30:20
che cos'è il nostro `str`? Vi faccio vedere.  Io stampo qua con la printf l'indirizzo della  
30:29
struttura, l'indirizzo di memoria dove risiede,  e poi stampo `s.str`. Guardate: la struttura è a  
30:51
`...18` e in esadecimale, 8 byte dopo, c'è la mia  `str`. Quindi `str` non è altro che un simbolo. E  
31:04
quando io gli tolgo la dimensione (`char str[]`),  gli voglio dire al C: "Io non ho davvero un array,  
31:11
ma tu questo `str` me lo devi far puntare alla  fine della struttura". Così, se io iper-alloco  
31:17
la struttura, perché in realtà sarebbe  solo di 8 byte, ma io la alloco di 40 byte,  
31:23
c'ho 32 byte spendibili a cui il puntatore `str`  farà capo. Anche in questo caso `str` non è parte  
31:30
veramente della mia struttura, non è un campo che  io posso modificare, è un offset. Gli sto dicendo:  
31:37
"`str` è il mio offset alla fine della struttura  e lì posso scrivere quello che mi pare".
31:46
Va bene, mi sembra che questa cosa dovrebbe essere  chiara. Ma c'è di più, e queste sono cose che  
31:52
riguardano un po' il design, ma sono molto  importanti. Tanto per iniziare, vi faccio subito  
31:57
una confessione: io non la farei una libreria  di stringhe prefixed-length che ha il reference  
32:05
counting, perché secondo me il reference counting  appartiene logicamente a un ordine di idee più ad  
32:16
alto livello. Quindi, se io per esempio in Redis,  la mia libreria SDS, non ha il reference counting  
32:26
nell'header. C'ha la lunghezza, c'ha la grandezza  dell'allocazione. Questo sì che è utile, ma se ne  
32:32
parlerà in un'altra lezione. Forse c'ha dei flag,  ma non ho il reference counting. Se invece io vado  
32:38
a guardare nel mio `redisObject`, c'è il tipo, c'è  l'encoding e c'è il ref-count. Qui sì che c'è il  
33:00
ref-count, perché è l'oggetto ad alto livello. Poi  il mio puntatore può essere una stringa SDS o può  
33:06
essere una lista. Ci sono dei casi di programmi in  cui il reference counting nelle stringhe è utile,  
33:13
ma secondo me è molto strano che accada,  perché quasi sicuramente hai un tipo più  
33:19
ad alto livello che rappresenta diversi oggetti,  che fa da conchiglia e che ha queste funzioni.
33:48
Quindi questa è una. Secondo, qualcuno mi  diceva: "Ah, ma la lunghezza così ti permette  
33:53
di avere stringhe solo di 4 GB, tipo come i  file massimi della FAT32. Tutti i sistemi a  
34:02
32 bit finiscono per rompere le scatole".  Verissimo. Ma uno si deve chiedere: nella  
34:08
mia applicazione ho stringhe più grandi di così?  Altrimenti, voglio sprecare ogni volta 4 byte?  
34:14
Ci sono per queste cose compromessi e ci sono  anche mancanze di compromesso, avendo il massimo  
34:22
usando una programmazione più efficace. Infatti,  la SDS guardate cosa fa: ha diversi tipi di header  
34:40
in base a quanto è grande la stringa. Stringhe a  64 bit, stringhe a 32 bit, a 16, a 8, addirittura  
34:48
a 5 bit. Per le stringhe molto piccole, io non ho  tutto questo header, ma ho semplicemente un byte  
34:53
solo dove ci sono dei flag (3 bit di flag) e 5 bit  di lunghezza, e posso risolvere fino a stringhe  
35:15
lunghe 31 caratteri. Ho avuto solo un byte di  overhead. Ma noi dovevamo semplificare le cose.
35:23
Altra domanda che mi è arrivata: "Ma il ref-count  è di 32 bit? Che succede se va in overflow?". A  
35:31
parte il fatto che è molto strano che io abbia  una condizione in cui posso referenziare il mio  
35:40
oggetto più o meno 4 miliardi di volte, che è più  o meno impossibile, in realtà questa cosa si rende  
35:49
possibile in un caso specifico. A volte, io con  le stringhe faccio un trucco. Se, per esempio,  
35:55
c'ho delle stringhe che sono molto diffuse, che  ne so, "0", "1", "2", quelle che rappresentano   i numeri nel mio programma, io le internalizzo.  Cioè, quando mi arriva una chiamata `ps_create`  
36:07
e mi rendo conto che `init` in realtà è una  di queste stringhe che io ho internalizzato,  
36:14
una di queste stringhe che vengono usate molto  spesso, che faccio? Gli ritorno una stringa  
36:20
preallocata che avevo creato all'inizio del mio  programma e incremento solo il reference counting.  
36:26
In questo caso si fa così di solito: quando il  reference counting arriva al valore massimo,  
36:31
io poi metto dei check nel codice che fanno  sì che il ref-count, da quel momento in poi,  
36:37
né si incrementi né si decrementi. In pratica creo  un leak, ma un leak in quel caso non è un errore  
36:45
nel programma. Mi accontento di non liberare più  quella stringa. O addirittura, per le stringhe  
36:51
che io ho internalizzato e voglio che non vengano  mai toccate, il ref-count lo setto direttamente al  
37:01
valore più grande che può contenere un `uint32_t`  e metto dei check che direttamente quel ref-count  
37:07
magico non viene più toccato. Quindi, in realtà,  la stessa tecnica mi fa da salvaguardia in tutti   e due i casi. Voglio un oggetto statico pur nel  sistema del reference counting, o voglio che,  
37:19
quando il reference counting sarebbe andato  oltre il suo limite naturale, io non abbia  
37:24
più modo di tracciare veramente quante referenze  esistono. Di quell'oggetto diventa "sticky" e non  
37:30
si libera mai più, quindi non corro mai il rischio  di liberare l'oggetto e poi qualcuno vi accederà.  
37:37
D'altra parte, se sono arrivato col mio oggetto ad  avere 4 miliardi di referenze, è molto probabile  
37:42
che questo oggetto comunque non verrebbe  liberato mai fino alla fine del programma. Questa puntata mi sa che è andata un po' per le  lunghe, la interrompiamo e alla prossima. Ciao.

Lesson 17 - My Notes
hexdump.c:
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct pls {
    long len;
    //char *str; - C here create a pointer with 8bytes
    char str[]; /* now s.str is a string with a 8byte pointer attached and 
                 * str simply points at the end of the struct as an offset 
                 * so use it, *str for this use is a conceptual and functional error */
};

#define HEXDUMP_CHARS_PER_LINE 8
void hexdump(void *p, size_t len) {
    unsigned char *byte = p;
    size_t po = 0;
    for (size_t j = 0; j < len; j++) {
        printf("%02X ", byte[j]);
        if (((j+1) % HEXDUMP_CHARS_PER_LINE == 0) || (j == len-1)) {
            if (j == len-1) {
                int pad = HEXDUMP_CHARS_PER_LINE - (len % HEXDUMP_CHARS_PER_LINE);
                pad %= HEXDUMP_CHARS_PER_LINE;
                for(int i = 0; i < pad; i++) {
                    printf("~~ ");
                }
            }

            printf("\t");
            for(size_t i = po; i < j; i++) {
                int c = isprint(byte[i]) ? byte[i] : '.';
                printf("%c", c);
            }
            printf("\n");
            po = j+1;
        }
    }
}

int main(void) {
    struct pls s;

    s.len = 10;

    memcpy(s.str, "1234567890", 11);
    printf("%p\n", &s);
    printf("%p\n", s.str);
    hexdump(&s, sizeof(s));

    return 0;
}


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
sdfad.c: