Lesson 12 - Link: https://www.youtube.com/watch?v=ZkaKwWXJXs8&list=PLrEMgOSrS_3cFJpM2gdw8EGFyRBZOyAKY&index=15

Lesson 12 Transcript:
La scorsa volta avevamo visto le stringhe in stile  Pascal. Di solito, le stringhe in C sono così:  
0:47
"Hello World" e poi c'è un carattere  di terminazione, uno zero. Quindi,  
0:55
ognuno di questi caratteri varrà quello che  vale nell'ASCII e qui c'è un byte a zero  
1:00
che indica quando la stringa finisce.
1:02
Abbiamo visto che in Pascal, in realtà, le  stringhe funzionano in un altro modo (e anche  
1:09
in altri contesti, non solo in Pascal).  Lì c'è la lunghezza come primo byte,  
1:14
quindi il Pascal poteva avere soltanto  stringhe che vanno da 0 a 255 byte,  
1:19
il che fa sorridere ovviamente, erano altri anni.  Anche se io non sono sicuro che ci fosse questa  
1:26
limitazione intrinseca o se questa fosse una  delle possibili rappresentazioni utilizzate.
1:33
Questa era la stringa: la lunghezza della  stringa e poi seguiva "Hello World". Quindi,  
1:40
a conti fatti, questi byte sono 1, 2, 3, 4, 5, 6,  7, 8, 9, 10, 11. Questo byte che io ho chiamato L,  
1:46
questo qui era 11, e poi c'era il byte  corrispondente ad 'H' che non so quanto fosse,  
1:51
70 o quello che è. Possiamo guardarlo qua  nella tabella ASCII: in decimale la H è 72,  
2:06
ci sono andato vicino. Quindi 72 e poi gli altri  byte. A questo punto non c'è il terminatore zero  
2:14
alla fine, perché io la lunghezza la so, è  prefissa alla stringa (`prefixed length`).
2:25
Ora, immaginiamo di voler implementare in  C un sistema di stringhe del genere. Lo  
2:32
chiamo `Prefixed Length String`, o PLS. Disclaimer (che fastidio 'sti capelli  
2:41
appiccicati e bagnati...): comunque, disclaimer.  Io questa implementazione la sto scrivendo ora,  
2:47
diciamo "live", per cui non è preparata  e quindi vedrete anche, diciamo così,  
2:53
il percorso logico che utilizzo. Vi dico da subito  che prima utilizzerò un percorso errato, o meglio,  
3:03
limitato, perché oggi voglio introdurre un  argomento centrale, e questo argomento lo  
3:07
dobbiamo introdurre mostrando prima quali sono le  limitazioni della mancanza di una data funzione.
3:16
Allora, immaginiamo di avere `include `  e io ho la mia `main` e voglio fare, non lo so,  
3:25
un buffer di 256 caratteri. E io voglio creare  questa stringa che chiamo `PLS`, `Prefixed  
3:39
Length String`. Chiamiamo la funzione `PS_init`. A  questa funzione passo il puntatore al mio buffer,  
3:53
dove la stringa che sto andando a generare  sarà registrata, e poi gli passo la stringa.
4:02
Noi in queste stringhe vogliamo poter avere dei  caratteri zero anche nel mezzo. Quindi questo può  
4:09
essere uno zero, ma non uno zero nel senso del  carattere '0', proprio un byte a 0, esattamente  
4:17
come se fosse un null-terminator, e invece  vogliamo che le stringhe continuino a funzionare.  
4:23
Quindi, quando inizializzo una nuova stringa  con lunghezza prefissa non posso semplicemente  
4:29
dare la stringa in C. Se io volessi rappresentare  "hello", dove qua c'è uno zero (nel senso proprio  
4:39
di un byte a 0) e poi "world", non posso farlo,  perché se passo questa stringa alla mia funzione,  
4:50
la mia funzione dovrebbe utilizzare `strlen`,  per esempio, che è la funzione di libreria del  
4:57
C che data una stringa ne torna la lunghezza,  ma questa lunghezza sarebbe calcolata fino al  
5:01
primo byte a zero. Quindi, devo avere anche un  altro argomento che specifica la lunghezza della  
5:07
stringa. Per ora mettiamogli un normale "Hello  World". Abbiamo detto che sono 11 caratteri.
5:14
Allora, andiamo a scrivere questa  `PS_init`. `void`, perché non ritorna  
5:18
niente. `void PS_init(char *s, char *init, int  len)`. Questo `s` è un puntatore a un array di  
5:29
caratteri, lo spazio di memoria che ho. `init`  è la mia stringa di inizializzazione che devo  
5:37
copiare dentro. E poi `int len` (non è  corretto dal punto di vista dei tipi,  
5:52
dovrei usare `size_t` che mi garantirebbe  di essere corretto sulla grandezza massima  
5:57
di un oggetto di questo sistema, ma  per ora non facciamo cose complicate).
6:09
Allora, guardate cosa devo fare. Sappiate  che qui, se per caso `len` è maggiore di 255,  
6:21
sarà troncato a un byte e questa cosa  funzionerà malissimo. Addirittura,  
6:27
in questo caso c'è anche il  problema che io in realtà il  
6:31
primo byte lo voglio registrare come  `unsigned`. Quindi, la cosa che dovrei  
6:38
fare è questa per essere completamente corretto: `unsigned char *len_pointer = (unsigned char *)s;` 
6:53
Così `len_pointer` è sempre l'indirizzo di memoria  a cui punta `s`, ma con un tipo diverso, perché io  
6:59
voglio poter registrare in questo primo byte la  lunghezza della mia stringa che va da 0 a 255,  
7:06
altrimenti lì avremmo numeri da -128 a +127. `*len_pointer = len;` 
7:27
Ora ho ottenuto che, in quel pezzo di memoria,  nel primo byte io ho messo la mia lunghezza.
7:53
E ora faccio un ciclo for: `for (int j = 0; j <  len; j++)`. Questa variabile `j` dentro il ciclo  
8:05
andrà da 0 fino a `len - 1`. `s[j + 1] = init[j];` 
8:24
In pratica, sto facendo una copia. Sto  copiando dentro questo spazio di memoria,  
8:32
partendo dal secondo byte, la stringa di  inizializzazione che mi danno, "Hello World".
8:55
Bene, questa è la mia `PS_init`. Il programma lo  posso compilare. Non fa una mazza, perché fa un  
9:25
qualcosa con la memoria, ma noi non lo vediamo.  E se io avessi un bel `PS_print` a cui do la mia  
9:31
stringa di questo tipo? Beh, perché non scriverlo? `void PS_print(char *s)`. 
9:44
Anche nei semplici programmi di questo tipo, ci  dobbiamo ricordare sempre di scrivere commenti:  
9:50
`// Initializes a prefixed length string with  the specified string 'init' of length 'len'.` 
10:17
Una cosa importante, qua possiamo  scrivere: `// WARNING: This function  
10:21
does not check for buffer overflows.` Perché guardate, questo programma ha un problema.  
10:28
Se non c'è abbastanza spazio nel buffer `s`  per contenere la stringa di inizializzazione,  
10:40
allora io scrivo in memoria che non è allocata  correttamente. È un bug di sicurezza e un sacco  
10:48
di problemi vari. Ma per ora non ci interessa,  perché questo è un programma didattico.
11:01
Questo invece è: `// Displays  the string S on the screen.` 
11:11
Come funzionerà questo programma? `unsigned char *len_pointer = (unsigned char *)s;` 
11:22
`unsigned char len = *len_pointer;` `for (int j = 0; j < len; j++) {` 
11:42
` putchar(s[j + 1]);` `}` 
11:50
`putchar('\n');` Chiamiamola due volte: `PS_print(buffer);`,  
12:07
`PS_print(buffer);`. Compiliamo il programma,  lo avviamo: "Hello World" e "Hello World".
12:13
Ma qual è la differenza fondamentale  di questo programma rispetto a quello  
12:17
di prima? È che io qui posso scrivere  un byte a 0. Compilo il programma e il  
12:25
programma funziona ancora, non si ferma,  perché stavolta la lunghezza è prefissa.
12:33
Beh, tutto ciò è molto interessante, ma c'è un  problema enorme. Ripristiniamo "Hello World".  
12:41
Se io voglio più stringhe, ne voglio creare  diverse. Ma mica posso allocare qui staticamente  
12:48
una variabile locale, un array enorme? E poi  che faccio se una stringa non mi serve più? Devo  
13:05
passare puntatori e sapere esattamente quanto  sono lunghe le mie stringhe... è un incubo.
13:09
Quando programmo in un linguaggio a livello più  
13:11
alto, tipo Python, io faccio `a = "hello"`, `b =  "ciao"`, e ho `a` e `b`. Anche se so che queste  
13:13
stringhe sono allocate in memoria da qualche  parte, ho i miei oggetti e Python li libera da  
13:36
solo quando non sono più referenziati. In  C lo devo liberare a mano, perché il C ha  
13:42
l'allocazione manuale della memoria, però si  può arrivare a questo livello di astrazione.
13:48
Cambiamogli nome a `PS_init` e  chiamiamolo `PS_create`. E guardate: 
13:54
`char *my_str = PS_create("Hello World", 11);` Il buffer locale lo tolgo. Guardate che cosa è  
14:04
cambiato. Ora devo stampare `my_str`. Quindi io  dico: "Funzione `PS_create`, per piacere, crea  
14:18
questo oggetto stringa a lunghezza  prefissa e ritornami il puntatore a esso".
14:25
Ora, come si fa a tornare un puntatore?  Dalla funzione non posso mica fare `char  
14:31
buffer[256]` e usare questo spazio, perché è una  variabile locale. Quando la funzione (`PS_create`)  
14:42
ritorna, questa memoria non c'è più. Bene, ci vengono in aiuto due funzioni:  
14:48
`malloc` e `free`. Specialmente `malloc`  nella creazione di un nuovo spazio di memoria.
14:56
Facciamo parlare il manuale. La funzione `malloc`  alloca della memoria. La memoria allocata è  
15:08
allineata così che può essere utilizzata  per qualsiasi tipo di dato. La funzione  
15:19
`free` libera le allocazioni che sono state  create da `malloc`. `malloc` è molto semplice:  
15:36
prende come argomento la dimensione del  pezzo di memoria che io voglio e mi ritorna  
15:40
un puntatore di tipo `void *`. I puntatori  `void *` sono indirizzi di memoria generici,  
15:49
non legati a un tipo di oggetto, che posso  assegnare a qualsiasi altro tipo di puntatore.
16:05
Guardate il mio programma come si  trasforma. Dobbiamo includere `stdlib.h`. 
16:19
La funzione `PS_create(char *init, int len)`  non ha più il buffer `s` passato come argomento.  
16:30
E guardate che faccio: `char *s = malloc(1 + len);` 
16:37
A me servono `len` byte per registrare la  stringa, ma mi serve anche un byte in più  
16:42
per mettere la lunghezza. Forse vi  viene più naturale scrivere `1 + len`. 
17:11
Sono il tipo di programmatore  
17:14
che poi scriverebbe questo nei commenti: `// The created strings have the following layout:  
17:41
[L][My string here...]` `// Where L is one unsigned  
17:52
byte stating the total length of the string.` 
18:02
`// Thus, these strings are binary safe  (zero bytes are permitted in the middle).`
19:00
Uso `malloc`, e la funzione ora deve  ritornare questo puntatore: `char  
19:07
*PS_create(...)` e alla fine `return s;`. La memoria che io ho allocato con `malloc`  
19:22
è ancora valida quando la funzione  `PS_create` ritorna. Per quale motivo?  
19:28
Perché la memoria creata con `malloc` rimane  valida fino a quando non c'è una chiamata `free`  
19:34
su quel puntatore per liberare quell'area.  Quindi tutto funzionerà come uno si immagina.  
19:45
Se non ho sbagliato niente...  funziona tutto perfettamente.
20:06
Entriamo un attimo nella programmazione difensiva.  In una libreria del genere, se io poi scrivo  
20:15
`printf("%s\n", my_str);`, ovviamente questa  roba qui non funzionerà per due motivi. Uno,  
20:28
perché il primo byte della stringa non è un  carattere stampabile, ma è una lunghezza (11,  
20:44
che in ASCII è un Vertical Tab). Due, perché la  stringa non è null-terminata, quindi `printf`  
20:55
continuerà a leggere la memoria finché non  troverà uno zero casuale. Vediamo che succede... 
21:02
Siamo stati fortunatissimi che, guarda  caso, c'è un byte a zero subito dopo.  
21:06
Ma non è per niente garantito. Il Vertical  Tab l'abbiamo visto, c'è quella spaziatura.
21:16
Però potremmo fare una cosa. Invece di allocare  solo `1 + len` byte, ne allochiamo uno in più alla  
21:24
fine per il terminatore: `malloc(1 + len + 1)`. E alla fine della copia, scriviamo lo zero:  
21:25
`s[1 + len] = '\0';` In questo modo, la nostra stringa  
21:27
avrà la lunghezza `L`, la stringa vera e propria,  e un byte a zero alla fine. Così continuerà a  
21:46
funzionare anche con le funzioni standard del  C che si aspettano stringhe null-terminate.
21:57
Tuttavia, la stringa "vera" inizia un byte  dopo. Facciamo una funzione di supporto: 
22:01
`char *PS_get_c_string(char *s) {` ` // Returns a pointer to  
22:25
the null-terminated C-string` ` // embedded inside our PS string.` 
22:25
` return s + 1;` `}` 
22:29
In questo modo, la mia stringa  `prefixed-length` punta alla  
22:32
lunghezza, ma con questa funzione ottengo  un puntatore che punta direttamente al primo  
23:56
carattere, compatibile con `printf`. `printf("%s\n", PS_get_c_string(my_str));`
24:53
Vedete? Il C è molto flessibile.  Hai le stringhe in un dato modo,  
24:57
ti scrivi una libreria per averle in un  altro modo. Estendi il linguaggio e poi  
25:01
programmi in questo nuovo  linguaggio. Guardate qua,  
25:04
noi stiamo programmando in un nuovo linguaggio  in cui le stringhe sono a lunghezza prefissa.
25:09
Alla fine, io devo liberare la mia  memoria e chiamo `free(my_str)`.  
25:16
Compilo, e ora il programma è corretto. Una cosa molto importante: se non avessi  
25:21
liberato la memoria in questo caso specifico,  siccome poi il processo esce e viene terminato,  
25:28
il sistema operativo libera tutta la  memoria che il processo ha allocato.  
25:37
Ma noi dobbiamo scrivere programmi corretti e  quindi la liberiamo, anche se stiamo per uscire.
25:45
Bene, prima di chiudere, vi devo dire che qua  abbiamo fatto un salto logico enorme. Noi ora  
25:56
abbiamo la possibilità di allocare pezzi  di memoria. Parleremo di come sono fatti  
26:00
gli allocatori, ma per ora freghiamocene. Non  vogliamo sapere in questa fase dove è allocata  
26:10
questa memoria o come funziona l'allocatore al  suo interno. A me piace l'astrazione che tutto ciò  
26:45
comporta. D'un tratto, utilizzando i puntatori del  C, posso creare degli oggetti (di fatto, questo è  
26:53
un oggetto stringa che prima non esisteva),  posso manipolarli, posso liberarli e posso  
26:59
immaginare queste stringhe come se esistessero in  uno spazio virtuale. So che sono limitate dalla  
27:07
memoria del mio computer, ma posso creare questi  pezzi di memoria, usarli, liberarli, e questo è  
27:13
un grandissimo vantaggio che ci permette in C  di creare programmi molto più complessi. Ciao.

Lesson 12 My Notes
pls.c:
// prefixed lenght strings, useful for malloc introduction
#include <stdio.h>

/* Initialize a prefixed length string with
 * the specified string in "init" of lenght "len" 
 * Warning: this function does not check for buffer overflows */
void ps_init(char *s, char *init, int len) {
    unsigned char *lenptr = (unsigned char*)s; // len pointer
    *lenptr = len;
    for (int j = 0; j < len; j++) {
        s[j+1] = init[j];
    }
}

/* Display the string "s" on the screen */
void ps_print(char *s) {
    unsigned char *lenptr = (unsigned char*)s;
    for (int j = 0; j < *lenptr; j++) {
        putchar(s[j+1]);
    }
    printf("\n");
}

int main(void)
{
    char buf[256];

    ps_init(buf, "Hello World", 11);

    ps_print(buf);
    ps_print(buf);

    return 0;
}

malloc.c:
#include <stdio.h>
#include <stdlib.h>


/* +-+------------\\\
 * |L|My string here
 * +-+------------\\\
 * where L is one unsigned byte stating the string lenght.
 * Thus this string are binary safe: zero bytes are permitted in the middle */
char *ps_create(char *init, int len) {
    char *s = malloc(1+len+1); // string  1+ len + 1, first byte for the len byte (the first one) and last one for the 0
    unsigned char *lenptr = (unsigned char*)s; // len pointer
    *lenptr = len;
    for (int j = 0; j < len; j++) {
        s[j+1] = init[j];
    }
    s[len+1] = 0;
    return s;
}

/* Return the pointer to the null terminated C
 * string embedded inside our PS string 's' */
char *ps_get_c(char *s){
    return s+1;
}


int main(void)
{
    char *mystr = ps_create("Hello World", 11);

    printf("%s\n", ps_get_c(mystr));
    
    free(mystr);

    return 0;
}



Lesson 13 - Lesson Link: https://www.youtube.com/watch?v=9AhaOdEBmPc&list=PLrEMgOSrS_3cFJpM2gdw8EGFyRBZOyAKY&index=14

Lesson 13 Transcript:
Ciao amici, benvenuti a questo corso di  programmazione in C. Vi ricordate che  
0:49
l'ultima volta avevamo fatto le nostre stringhe  a lunghezza prefissa e andavano benissimo?
0:55
Noi abbiamo fatto anche una funzione che  si chiamava PS_get, che era, diciamo,  
1:03
l'abbreviazione di "dammi il puntatore a una  stringa in C". Perché la cosa interessante di  
1:09
queste stringhe a lunghezza prefissa è che se  io salto la lunghezza, quello che viene dopo,  
1:16
anche per il fatto che io ho, non a caso, messo  un terminatore nullo alla fine della stringa. Se  
1:23
la stringa non contiene byte zero a metà, io ho  anche una stringa C normale "embeddata" dentro la  
1:31
mia rappresentazione, contenuta dentro la  mia rappresentazione. E allora perché non  
1:35
consentire l'interoperabilità? Che vi assicuro  è importantissima, perché in C ci sono una  
1:41
quantità enorme di funzioni di vario tipo per la  manipolazione delle stringhe. A volte io utilizzo,  
1:48
assieme alla mia libreria delle stringhe  prefisse, altre librerie che si aspettano  
1:52
funzioni in C e quindi è importantissimo  che ci sia questa interoperabilità.
1:58
Per far ciò, io avevo preso la mia funzione PS_get  che mi ritornava appunto il puntatore alla stringa  
2:06
semplicemente aggiungendo uno al puntatore,  saltando il prefisso. Ma io vi dico che noi  
2:14
possiamo fare di più. Allora, tanto per iniziare,  facciamo una cosa. Aggiustiamo questa stringa  
2:17
in modo che possa contenere una lunghezza di 4  byte, perché così è troppo poco. Quindi `include  
2:27
`. Quando io includo `stdint.h` ho  `uint32_t`, `uint16_t`, tutti questi tipi in  
2:34
cui specifico il numero di bit, il che è molto  utile. E io posso fare 4 byte, scusate, 32 bit.  
2:45
2^32 - 1. Questa sarà la dimensione  massima della mia stringa. 4 GB, diciamo,  
2:54
per questo esempio è sufficiente. Normalmente  avrei potuto utilizzare `size_t` e sarebbe stata  
3:03
probabilmente una buona idea, perché così in  un sistema a 64 bit il prefisso è lungo 8 byte,  
3:10
in un sistema a 32 bit 4 byte. Ma c'è un discorso.  Siccome è molto strano avere stringhe superiori a  
3:17
4 GB — può capitare in certi contesti, in molti  altri contesti no — ce la sentiamo noi di pagare  
3:25
l'overhead di 4 byte in più ogni stringa? Sono  considerazioni che, come dire, bisogna fare.
3:36
Allora, come modifico io questo programma? Beh,  
3:40
questo sarà quattro. In teoria  potrei scrivere `sizeof(uint32_t)`.  
3:47
Per carità, ci sta, ma ho chiesto un tipo di  un certo numero di byte, non a caso, quindi  
3:58
scrivo 4 e me ne frego. `unsigned char`, questo  non è più così, ma è un puntatore a `uint32_t`.  
4:13
Eh, qui invece di +1 dovrei mettere +4, però in  realtà possiamo fare una cosa più interessante,  
4:22
che è questa. Qua scriviamo s + 4. Quindi noi  facendo s + 4 andiamo all'inizio della stringa.
4:35
Questo qui lo rendiamo a questa copia qua. We  should use `memcpy` here. Questo lo vedremo  
4:44
fra un attimo, perché dico che noi dovremmo usare  `memcpy` invece di fare questo loop che copia. E  
4:52
poi mettiamo il terminatore alla lunghezza. Ma a  questo punto quando io ritorno alla mia stringa,  
4:59
dovrei tornare s - 4, giusto? Quindi io  sono qui, dovrei tornare a questo byte.  
5:11
Eh, e se io invece torno s? Se io usassi  questo trucco, che ne dite se noi le  
5:18
stringhe le torniamo in modo che il puntatore  sia la stringa creata, la nostra `PS_string`,  
5:25
ma che parta dalla stringa in C? Così non mi serve  una funzione per la conversione tra le due. Ok?
5:32
Quando invece io dovrò, per esempio,  nella prossima funzione `PS_print`,  
5:38
sapere veramente qual è la lunghezza, allora io  faccio così. Il `len_pointer`, che è `uint32_t`,  
5:47
`len_pointer` è uguale a `(uint32_t*)s`.  Quindi sottraggo ad s e vado indietro.  
6:03
Faccio il casting al mio nuovo tipo di puntatore.  A questo punto c'è il mio `len_pointer` e qui  
6:10
uso j senza +1 per lo stesso motivo che ci  siamo detti, perché ormai il riferimento di  
6:16
s è l'inizio della stringa e non la lunghezza.  Quindi io ce l'ho sempre prima del puntatore  
6:23
che torno. Quindi il puntatore mi dà la vista  alla stringa; dietro al puntatore, nascosto,  
6:29
c'ho il mio header, che in questo momento,  diciamo, la mia intestazione è composta solo  
6:34
dalla lunghezza della stringa. Questa  è una cosa molto, molto interessante.
6:38
`get_c` non serve più a niente e `free_my_string`  non è più utilizzabile, perché stavolta io per  
6:46
liberare la mia stringa, `PS_free(char *s)`,  devo fare `free(s - 4)`. Perché? Con `malloc`,  
7:06
se `malloc` mi ritorna un puntatore, io devo fare  `free` a *quel* puntatore, non è che posso fare  
7:11
`free` dentro l'allocazione. Metti che ho preso 10  byte, non è che gli posso dire `free` a qualsiasi  
7:17
cosa all'interno. Gli devo dare di nuovo  l'indirizzo di memoria che `malloc` mi aveva  
7:20
ritornato. Una `malloc`, una `free`, allo stesso  indirizzo. Vediamo se questo programma funziona.
7:32
`PS_get` non mi serve più. Ormai  le mie stringhe sono compatibili.  
7:40
Ecco fatto. Sembra proprio funzionare tutto bene.  Facciamo anche un'altra funzione. Copiamoci qua.
7:53
`PS_len`. Retrieve the length of the  string in O(1) time. Questa volta,  
8:02
al contrario della `strlen` — la `strlen` è la  funzione di C normale che, dato il puntatore  
8:07
a una stringa, ti ritorna la lunghezza, ma  deve andare a cercare la fine della stringa,  
8:12
il byte a zero. Quindi il suo tempo di  esecuzione è proporzionale alla grandezza  
8:17
della stringa. Invece la mia `PS_len` non fa  altro che prendere un puntatore e ritornare  
8:28
il valore a 32 bit che è registrato in quel  puntatore. Quindi praticamente la mia stringa,  
8:37
le... questo sistema di stringhe può avere  accesso alla lunghezza di una stringa senza  
8:42
andare a fare la scansione della stringa,  il che è un vantaggio molto significativo.
8:46
Quindi io ora stampo questo qui e poi  stampo `PS_len(&my_string)`. Faccio il  
8:57
cast a `int`. Non voglio impelagarmi qui  perché ci sono gli specificatori di tipo  
9:02
della `printf` per `uint32_t`, ma sono  scomodi da scrivere e così via. Invece  
9:11
noi facciamo il casting a `int`; in  questo caso è uguale. Eh, vedete,  
9:16
la lunghezza è 33. Molto bene. In questo modo  noi abbiamo risolto un problema interessante.
9:26
Vi volevo fare vedere una cosa. I moderni  allocatori hanno un minimo di protezione per  
9:31
il fatto di liberare due volte una cosa. Cioè, io  questo puntatore l'ho liberato qui con `PS_free`.  
9:37
Ora richiamo di nuovo `PS_free`. Guardate che  succede. Ecco qua. `malloc`: error for object:  
9:44
pointer being freed was not allocated. Set a  breakpoint per vedere che cos'è che è sbagliato.  
9:52
Quindi, invece di corrompere memoria, mi blocca  il programma. Ciò non è garantito, per cui non vi  
10:02
fidate. Queste sono feature utili per scovare dei  bug, ma non tutte le implementazioni lo faranno  
10:10
ed è anche possibile, in certi casi, corrompere  la memoria in modo che queste salvaguardie non  
10:16
siano sufficienti e il bug di sicurezza ci  scappa lo stesso. Quindi, programmare bene.
10:26
Una cosa interessante è questa. Se io, per  esempio, siccome quando alloco una stringa  
10:30
poi la devo liberare, a volte mi capita di  avere più di un riferimento alla mia stringa.  
10:35
Per esempio, qua c'ho la mia stringa.  Facciamo anche una variabile globale,  
10:43
chiamiamola `global_string`. Quindi io qua creo  una stringa, poi `global_string` lo assegno a  
10:55
`my_string`. Quindi ora c'ho due variabili  che puntano alla stessa stringa: una è questa  
11:02
e una è questa variabile globale qui. Dopo che io  libero `my_string`, ho ancora un riferimento alla  
11:11
mia variabile globale che referenzia la stessa  stringa. Ma la stringa ormai è liberata. Vedete?  
11:17
Io qua ora voglio stampare `global_string` e  compilo, se ci riesco. Guarda che stampa. Stampa  
11:29
punto e virgola. Si è corrotta la memoria, quella  era un'allocazione, è stata liberata e così via.
11:37
Allora, non sarebbe utile avere nelle nostre  stringhe un sistema che ci permette di tenere  
11:45
il conto di quante volte abbiamo referenziato  quella stringa? E quando tutte le referenze a  
11:52
quella stringa vengono, diciamo, rimosse, la  memoria viene liberata in maniera automatica.  
12:00
Potremmo avere, per esempio, un contatore  che chiamiamo "conto delle referenze",  
12:05
perché questa tecnica si chiama *reference  counting*, quindi proprio contare le referenze.  
12:12
Che ne so, dopo la lunghezza noi gli mettiamo qua  "CCCC", che è il nostro conto delle referenze.
12:28
E in questo modo, io quando creo una  stringa magari posso tenere il mio  
12:32
conto delle referenze. E invece ogni volta che  aggiungo un altro puntatore a questa stringa,  
12:46
aumento il conto delle referenze. Ogni volta  che invece io un puntatore non lo utilizzo più,  
12:52
e quindi questa stringa ha una referenza in  meno, viene referenziata da un posto in meno,  
12:58
io decremento questo contatore.  Quando il contatore arriva a zero,  
13:02
faccio veramente la `PS_free`. A questo punto, io  ho un sistema molto più interessante di gestione  
13:10
della memoria che non mi obbliga a pensare  a mano, ogni singola volta, quante volte ho  
13:18
referenziato quella stringa. Devo creare però un  automatismo. Ogni volta che aggiungo un puntatore  
13:23
a quella stringa da qualche parte, io chiamo una  funzione che incrementa quel contatore. Ogni volta  
13:30
che tolgo un puntatore a quella stringa, chiamo  una funzione che mi decrementa quel contatore  
13:38
e quando il contatore arriva a zero, c'è  l'automatica liberazione della memoria.
13:43
Ma per far ciò ci stiamo impelagando... guardate  qua, nell'header già c'ho... allora dovrei fare  
13:50
`len_pointer`, `uint32_t count`. Quindi,  prima c'è il `len_pointer`, poi qua è un  
14:02
`uint32_t` a `s + 4`. Quindi, praticamente, `s`  è l'inizio della mia allocazione. Siamo qua. Ok,  
14:10
quindi il `len_pointer` è semplicemente il cast  al tipo giusto, sempre di `s`. Non abbiamo fatto  
14:17
nessuna aritmetica dei puntatori per spostare  il puntatore. `count` è 4 byte dopo. Ok,  
14:23
e fin qui ci siamo. Qua avrei dovuto scrivere  poi `s + 8` perché la stringa parte qui.
14:30
Ma non è scomodo programmare così?  Non sarebbe bello poter scrivere,  
14:34
per esempio, qualcosa del genere?
14:38
`struct PS`, chiamiamolo così,  le nostre stringhe prefisse:  
14:46
`uint32_t len; uint32_t ref_count; char str[];`
14:59
Poi vi spiegherò nella prossima puntata perché  qua ho utilizzato `str`. Quindi ho una struttura  
15:05
a questo punto che ha un insieme di campi e questa  struttura `PS` ha definito un nuovo tipo di dato.


Lesson 13 My Notes:
