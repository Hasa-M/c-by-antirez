Lessons 6 and 7

Lesson 6, video link: https://www.youtube.com/watch?v=lc7aYXNl1T8&list=PLrEMgOSrS_3cFJpM2gdw8EGFyRBZOyAKY&index=8

Transcript:
0:27
Devo dire, abbiamo fatto dei passi avanti,  anche se all'inizio eravamo andati lenti,   perché altrimenti si rischia di sorvolare su cose  che sembrano apparentemente simili a quelle degli  
0:37
altri linguaggi, ma sono in C piuttosto diverse.  Poi, finalmente, siamo riusciti a introdurre le  
0:42
stringhe. Sarebbe ora il caso di fare il passaggio  ai puntatori, che sono poi un prerequisito  
0:50
necessario per scrivere programmi più complicati  in C. Però, paradossalmente, questo salto non  
0:56
lo possiamo fare, e vi dico perché: perché non  abbiamo introdotto le strutture di controllo in C,  
1:03
ovvero le scelte condizionali con `if`, che  probabilmente conoscete da altri linguaggi,  
1:10
e poi le strutture di ciclo, che sono in C poche:  lo `switch`, il `while`, il `for`, il `do-while`  
1:20
(che è una variante del `while`) e, infine, la  ricorsione, che può essere considerata a tutti  
1:26
gli effetti un modo che permette di creare dei  cicli. Senza queste cose non potremmo affrontare  
1:35
i puntatori, perché ogni volta che ci sarebbe da  fare qualcosa che richiede una `if` o di fare un  
1:42
loop per, non so, navigare con un puntatore una  stringa dall'inizio alla fine e cose di questo  
1:49
tipo, non potremmo continuare, perché violeremmo  la propedeuticità che questo corso si è preposta,  
1:59
ovvero quello di introdurre prima le cose  che si useranno nelle prossime puntate e   solo dopo utilizzarle. Per cui, non ci  resta che partire dalla più importante.
2:14
Delle strutture che controllano il flusso  di un programma, una scelta condizionale,  
2:20
ovvero la keyword `if`. Iniziamo a scrivere il  nostro programma. Includiamo `stdio.h` perché ci  
2:27
serve la `printf`. Definiamo una semplice `main`  per avere un entry point del nostro programma e  
2:38
poi definiamo una variabile `i` e gli assegniamo  il valore di 5. Poi scriviamo: se `i` è maggiore  
2:44
di 3, altrimenti qualcos'altro. Allora, la `if`  funziona così: la `if` valuta questa condizione  
2:51
che è scritta tra le parentesi tonde e, poi, come  vedete, ha un primo ramo e poi un secondo ramo  
2:59
dopo la `else`, che è opzionale. La `else` si può  evitare e, semplicemente, se la condizione è vera,  
3:06
sarà eseguito quello che c'è dentro le parentesi  graffe. Le parentesi graffe aperte e chiuse in C  
3:11
si chiamano "blocco". Se invece c'è la `else`,  verrà eseguito, se la condizione è falsa, ciò  
3:21
che c'è dentro il blocco della `else`. Iniziamo  direttamente con un `if-else`: quindi, se `i`  
3:29
è maggiore di 3, stampiamo "i è maggiore di 3",  altrimenti stampiamo "i è minore o uguale a 3".
3:49
Immancabile il nostro `return 0;` per scrivere  un programma corretto, altrimenti avremo un   warning. E finalmente possiamo compilare il nostro  programma, attivando i warning e l'ottimizzazione,  
4:03
ed eseguirlo. L'output del programma è "i > 3"  perché 5 è maggiore di 3. Se invece `i` è 2,  
4:13
compilo di nuovo il programma e vedo "i  <= 3". Questo può sembrare molto semplice,  
4:20
ma ci sono delle cose interessanti da notare.  Per esempio, i blocchi in C. Tanto per iniziare,  
4:30
non è necessario averceli qualora il mio programma  non faccia che eseguire un singolo statement,  
4:43
quindi è composto da una sola chiamata di  funzione o solo da un'assegnazione di variabile,  
4:51
eccetera. Quindi, abbiamo detto, se la  `if` è seguita da un'unica istruzione,  
4:57
non serve mettere le parentesi graffe.  Facciamo la compilazione di questo  
5:03
programma e non scrive niente perché non c'è  l' `else`, ma se io questo lo riporto a 5,  
5:11
un valore per cui l'espressione è  valida, avrò l'output che mi aspetto.
5:19
E qua posso scrivere pure `else printf("i <=  3");`. Questo programma compila senza problemi,  
5:28
non è cambiato niente. Un piccolo appunto  stilistico: a me, quando ci sono delle `if`  
5:34
con delle condizioni molto brevi, o anche  dei cicli `while`, eccetera, eccetera,  
5:39
piace scrivere tutto in una riga. Vi dico perché.  Tanto per iniziare, mi sembra che sia più comodo  
5:45
leggerlo tutto su una riga e, poi, semanticamente,  significa qualcosa di molto chiaro: se `i` è > 3,  
5:53
allora scrivi "i > 3". Non vedo nessun vantaggio  nel dividere questa cosa qua in due righe.  
6:00
C'è un altro vantaggio collaterale interessante:  così facendo, noi riduciamo la lunghezza del  
6:07
nostro codice sorgente dal punto di vista  dell'asse verticale, e ciò fa sì che in una  
6:14
data pagina che io vedo nel mio terminale ci sia  più codice, e quindi che mi debba spostare meno  
6:21
per vedere il resto del codice. Per tale motivo,  io molto spesso utilizzo questo stile. Ovviamente,  
6:31
gli altri stili sono perfettamente coerenti e si  può scrivere così, così come se, per ragioni di  
6:37
chiarezza, io credo che sia meglio, posso scrivere  anche le parentesi graffe. Perché vi dico ciò?  
6:43
È molto importante, quando si parla di  programmazione, quando si fa parte di una  
6:49
community, non focalizzarsi su dettagli che  sono poco determinanti, che poco contano per  
6:57
quello che stiamo facendo, e lanciarsi in accuse  inutili verso gli altri programmatori. Ognuno ha  
7:04
il suo stile, la sua sensibilità estetica,  e ogni stile di programmazione coerente va  
7:10
bene. Quello che fa schifo è scrivere "ciò"  [riferendosi a codice mal formattato], ma è   molto importante sapere che comunque funzionerà,  perché in C, nel linguaggio di programmazione C,  
7:21
l'indentazione non è in alcun modo semantica:  non significa niente, serve solo per gli esseri  
7:27
umani e non per i compilatori. Il compilatore  vedrà una `if`, salterà gli spazi, saprà che  
7:34
ora dovrà trovare un'istruzione, la trova e la  compila. Per cui, è solo una questione umana.
7:43
Molto più interessante, invece, e istruttivo,  è capire che cos'è un blocco. Guardate: dentro  
7:49
le parentesi graffe io posso dichiarare delle  variabili che saranno visibili solo dentro questo  
7:56
blocco, e posso fare altre cose che ora vedremo.  Ma, più che altro, è ancora più interessante il   fatto che io posso mettere un blocco ovunque.  Guardate qui: io apro le parentesi graffe,  
8:10
le chiudo, compilo questo programma e mi  scrive "i è maggiore di 3", ma è semplicemente  
8:17
un'istruzione. Se io qui dichiaro `int i = 5;`  e scrivo `printf("i is %d", i);`, il programma  
8:31
continuerà a compilare, ma la cosa interessante  è che io, fuori da qui, non posso avere di nuovo  
8:38
una `printf` che si riferisce a `i`, perché  questa `i` è locale a questo blocco. Quindi,  
8:49
lo scope lessicale di questa `i` non è altro che  dentro il blocco. Fuori dal blocco, questo `i`  
8:59
non può essere risolto, non esiste. Questo sarà  importante poi più avanti per certe cose. È molto,  
9:06
molto utile. A volte vi capita, vi capiterà di  dover definire qualcosa che non ha... Allora,  
9:12
vi faccio vedere anche un'altra cosa. In realtà,  `i` può essere anche definito qui: `int i = 8;`.  
9:18
Guardate cosa fa questo programma. Prima  stampa `i = 5` e poi stampa `i = 8`. Perché qua  
9:24
definisco `i = 8`. Qua c'è un blocco, `i` viene  definita col valore di 5, ma non è la stessa `i`,  
9:31
sono due `i` diverse, completamente.  Viene stampato che `i` è 5, perché nello  
9:37
scope lessicale di questo blocco `i` è questa  variabile qua. Si esce poi dal blocco, a questo  
9:45
punto `i` è quella che è stata definita fuori,  e quindi vedremo prima una `i` e poi un'altra.
9:53
A questo punto, per un attimo, violeremo la  progressione di questo corso e introduciamo,  
10:02
per un attimo, il modo in cui si può stampare il  valore di un puntatore. Allora, questa `i` sarà  
10:11
registrata da qualche parte, potrebbe essere  in un registro, nello stack, e così via. Ma  
10:16
se noi vogliamo ottenere l'indirizzo di memoria di  questa `i`, forzeremo il compilatore, in realtà, a  
10:21
utilizzare lo stack. Non lo può più mettere in un  registro, questo valore qui, non può ottimizzare  
10:27
più oltre un certo livello, perché noi vogliamo  poter accedere a questa variabile anche tramite   il puntatore, ovvero tramite il suo indirizzo di  memoria. E la stessa cosa avverrà qua. Guardate,  
10:38
io gli dico: `i is stored at %p`. Così come lo  specificatore di tipo `%s` stampa una stringa,  
10:49
così come lo specificatore di tipo `%i`  stampa un intero, `%p` stampa un puntatore.  
10:55
E per avere il puntatore, cioè l'indirizzo  di memoria al quale questo `i` è registrato,  
11:02
devo usare, prima del nome della variabile, la  e commerciale (`&`). Farò la stessa cosa qua:  
11:07
`stored at %p` e di nuovo useremo `&i`.  Probabilmente qui avremo un warning,  
11:19
perché in realtà qui si aspetta un puntatore  di tipo `void*`, invece qua è un puntatore di  
11:24
tipo `int*`. Non cambia niente dal nostro punto di  vista. Vogliamo compilare questo programma... no,  
11:30
non abbiamo ricevuto neanche il warning.  Ecco, vi faccio vedere una cosa. Guardate,   il primo `i` è registrato nell'indirizzo  di memoria `...16f7...28` (in esadecimale,  
11:40
ovviamente). Il secondo `i` è registrato molto  vicino al primo: `...2c`. Quindi, 9, a, b,  
11:52
c. Ci sono 4 byte di distanza tra uno e l'altro.  Sì, ci sono 4 byte di distanza. Infatti, se noi...
12:14
Allora, size... bytes... allora, facciamo,  gli mettiamo pure un `sizeof(i)` e qua copiamo  
12:21
esattamente la stessa riga. Allora, io ora  gli dico `i`, che è grande tot byte. Infatti,  
12:27
guardate, qua c'è `size_t`. `%zu` è per `size_t`,  che è il tipo che ritorna `sizeof`. Ne abbiamo  
12:37
parlato di `size_t`: è un intero come un altro,  però è garantito essere abbastanza grande da  
12:43
poter registrare le dimensioni più grandi che  possono esserci in questa architettura che noi   stiamo utilizzando (nel mio caso, amd64, perché  questo è un MacBook M3). Compiliamo. Guardate:  
12:58
`i`, che è 4 byte, registrato a questo  indirizzo qui. L'altro `i`, che è pure 4 byte,  
13:03
registrato a questo indirizzo `...2c`. Non a caso,  da `...28` a `...2c` c'è una distanza di 4 byte.
13:11
Quello che abbiamo mostrato ora ci permette  di non crearci più troppi problemi quando si  
13:17
vedono le parentesi graffe che si aprono e  si chiudono nelle istruzioni, diciamo così,  
13:24
condizionali o di loop. Quindi, quando ci sono  `if`, si aprono e si chiudono parentesi graffe,  
13:32
noi sappiamo che stiamo creando sostanzialmente un  nuovo blocco in C e che questo blocco, in realtà,  
13:39
fa parte del codice della funzione esattamente  come tutti gli altri, ma permette di avere delle   variabili con uno scopo più locale. Un'altra  cosa molto interessante è che, comunque sia,  
13:50
queste variabili che queste altre, come abbiamo  visto dagli indirizzi di memoria molto vicini,   risiedono tutte e due nello stack della funzione.  Quindi, vengono create all'ingresso della  
14:00
funzione, ma il compilatore potrebbe decidere  anche, a volte, di creare questa variabile qua  
14:06
dopo, e poi vengono liberate quando si esce dalla  funzione. Ma, dal punto di vista poi concettuale,  
14:14
noi dobbiamo pensare, però, che questa variabile  qui esiste solo all'interno del blocco,  
14:19
anche proprio come tempo di vita. Poi sarà il  compilatore che gestirà lo stack come vuole. A  
14:24
volte, in realtà, le allocherà all'inizio tutte  e due, decrementando lo stack pointer di 8 byte  
14:31
direttamente, usando quegli offset. A volte,  invece, potrebbe decidere di utilizzare prima,  
14:39
di creare prima una variabile nello stack,  decrementando lo stack pointer, e poi un'altra.   In realtà, c'è un modo semplice per vedere  questa cosa. Se io questa roba qui la faccio  
14:47
due volte e compilo, vi faccio vedere una cosa.  Guardate: `...18`, `...14`, `...1c`. Gli offset  
14:56
sono diversi. Cos'è che significa questo? Che  in teoria il compilatore avrebbe potuto giocare  
15:02
con lo stack e allocare prima questa variabile,  poi, quando si esce da qui, non utilizzarla più,  
15:07
e qui riutilizzare di nuovo la stessa. Allora, qua  c'è una discrepanza tra quello che il compilatore  
15:12
fa per essere efficiente e quella che è la  semantica del C. Questa `i` qui, io fuori  
15:18
dal blocco devo considerare che non esiste più.  Quindi, non è che posso prendere un puntatore qua,  
15:24
cioè, posso qua creare un puntatore, qua  registro il puntatore a `i` e poi la utilizzo   qui. Esattamente come io devo considerare  le variabili che sono dentro una funzione,  
15:35
in generale, locali, anche le variabili che  sono dentro un blocco sono locali a quel blocco.
15:42
Benissimo. Detto questo, vediamo che cos'è  che possiamo fare con la `if`. Per far ciò,  
15:52
ci serve introdurre un'altra  idea interessante: `goto`.
16:03
Ammettiamo di voler fare un programma che conta da  0 a 9. Quindi, io parto con una variabile `i` che  
16:10
inizializzo a 0 e poi posso scrivere: stampami  il valore di questa variabile con la `printf`,  
16:19
quindi `printf("%d\n", i);`. E poi io posso dire:  se `i` è minore di 10, `goto again`. E qui devo  
16:31
creare un'etichetta che si chiama `again`. Allora,  guardate che fa questo programma. Viene creata  
16:39
una variabile locale che si chiama `i`. Questo  `again:` qua serve solo al compilatore, non fa   niente, servirà poi solo al `goto` per sapere  a quale indirizzo di memoria il programma deve  
16:48
saltare quando incontra il `goto`. Viene stampato  il numero 0, perché `i` in questo momento vale 0.  
16:58
In realtà, qua devo scrivere `i++`, quindi  incremento la mia `i`. Se `i` è minore di 10,  
17:06
salto di nuovo a qua, quindi il programma  ripassa il controllo all'istruzione `printf`,  
17:11
e così via. Ora io compilo questo  programma, che conta da 0 a 9.
17:24
Allora, vi vorrei far notare una cosa. Qualcuno,  da ragazzino, o l'avrà visto poi da grande,  
17:31
avrà sicuramente visto il linguaggio BASIC,  in cui c'erano i numeri di linea per fare   più o meno quello. Perché, siccome qui possiamo  saltare in C in questo modo, quando io scrivo in  
17:41
assembly, ho pure le etichette, o altrimenti,  se scrivo proprio in linguaggio macchina,  
17:46
solo istruzioni di memoria a che offset è, e  quando faccio una jump in assembly, un salto,  
17:52
salto a quell'indirizzo di memoria. E  invece, in BASIC, si scriveva `10 PRINT   "Ciao"`, `20 GOTO 10` per fare un ciclo  infinito che stampa sempre "Ciao". Allora,  
18:03
guardate come io questa cosa la  posso più o meno riprodurre qui in C:  `L10: printf("Ciao\n");` `L20: goto L10;` 
18:17
Sembra BASIC, no? Qua mettiamo il nostro `return  0;` perché siamo delle brave persone. Vabbè,  
18:25
qua `L20` non l'ho usata perché non me ne frega  niente, ma ecco, questo programma va in un ciclo  
18:31
infinito e stampa sempre "Ciao". Quindi, il BASIC  altro non fa che dare ad ogni numero di riga,  
18:38
ad ogni istruzione del programma, in sostanza,  un numero al quale si può saltare o al quale  
18:45
poi il programmatore può riferirsi se vuole  cancellare quella riga, rimpiazzarla. Quindi,   in BASIC, in realtà, serve a due cose: sia per  il programmatore, per referenziare una data riga  
18:55
del codice e modificarla, o per fare i salti con  `GOTO` o `GOSUB`, e così via. Quindi, guardate,  
19:03
a volte il C può essere flessibile e sembrare  anche un'altra cosa rispetto a ciò che è. Queste  
19:10
si chiamano etichette, non so se l'ho già detto,  `L10`, `L20`. Non potevamo scrivere `10`, `20`,  
19:15
questo è sintassi invalida. Deve iniziare  con una lettera, per questo ho scritto   `L10` e `L20` invece di 10 e 20. Ma la cosa  interessante è che se noi, appunto, vogliamo,  
19:28
che ne so, così come abbiamo fatto, contare da  1 fino a 10, possiamo usare l'`if` e il `goto`.
19:34
Allora, guardate, ora vi voglio far  vedere... Ritorniamo al programma di prima. 
19:39
`again:` `int i = 0;` 
19:45
`printf(...)` Stampo `i`,  
19:50
incremento `i` di 1, se `i` è minore  di 10, vado di nuovo ad `again`. 
19:55
`return 0;` Compiliamo di nuovo. 0 1 2 3 4 5 6 7 8 9. Ok.  
20:06
Ora, questa cosa qui non è tanto diversa da un  ciclo `while`. Guardate, io questo programma lo  
20:12
potevo scrivere così: `i = 0;`  `while (i < 10) {` ` printf(...)` 
20:23
` i++;` `}` Cos'è che sbatte due bottiglie assieme? Scusate,  
20:31
prima di diventare pazzo, sposto queste  bottiglie. Anzi, addirittura berrò.  
20:49
Allora... Scusate, ho dimenticato  `i++`. `i++` doveva essere messo  
21:04
sotto. Succedono due volte la stessa  cosa, da 0 fino a 9, da 0 fino a 9.
21:11
Esaminiamo il programma su... anzi, cancelliamo  la prima versione e ci teniamo solo la  
21:17
seconda. Allora, `while (i < 10)`, sapete che  significa questo? Che io posso entrare dentro  
21:27
il blocco soltanto se la condizione è vera. `i`  all'inizio è uguale a 0. Per chi non lo sapesse,  
21:36
anche se questo corso ha come prerequisito  avere un minimo di base di programmazione,   diciamolo. Allora, `while` è la struttura che  in moltissimi linguaggi di programmazione esegue  
21:49
un pezzo di codice, un blocco di codice,  fin quando la condizione è vera. Quindi,  
21:56
a servizio di chi non sa queste cose, diciamo  cosa succede. Se `i` è 0, all'inizio è vero,  
22:02
perché `i` è minore di 10. Stampo `i`, che è 0,  incremento `i` di 1 e poi torno immediatamente di  
22:11
nuovo qua dentro. `i` è ancora minore di  10? Sì, perché è 1. Stampo `i`. Insomma,  
22:16
alla fine, dopo che `i` ha stampato 9, `i++`  significa `i = i + 1`, quindi `i` diventa 10.  
22:24
A questo punto, `i` non è più minore di  10 e io proseguo qui, fuori dal `while`.
22:31
Guardate come io posso tradurre questo  programma esattamente in `goto`. Questo  
22:39
diventa `if (!(i < 10)) goto next;` ... e qui  mettiamo la nostra etichetta `next:`. Questo è  
23:14
esattamente ciò che fa il `while`, il modo in  cui il `while` viene normalmente compilato.
23:20
[...]
26:04
Se noi volessimo addirittura evitare  il `goto` utilizzando la ricorsione e  
26:13
vogliamo lo stesso essere in grado  di contare da 0 a 9, proviamoci.
26:27
Allora, utilizziamo, però, stavolta  una funzione che chiamiamo `conta`. 
26:35
`conta(0, 9);` // Dove deve iniziare  a contare e dove deve finire. 
26:47
Allora, questa funzione qua la dichiariamo  `void`, non ci deve tornare niente. 
26:58
`void conta(int start, int end)` `{` 
27:07
` if (start > end) {` ` return; // Non abbiamo più niente da fare` 
27:24
` }` ` // Altrimenti siamo ancora dentro l'intervallo` 
27:34
` printf("%d\n", start);` ` conta(start + 1, end);  
27:44
// Chiamiamo di nuovo la stessa funzione` `}` 
27:52
Perché noi, a questo punto, dovevamo  contare da 0 a 9. Bene, abbiamo contato 0,  
27:59
e allora ora vogliamo contare da 1 a 9.  Proviamo a compilare questo programma.  
28:08
E abbiamo contato da 0 fino a 9. Che ne  dite? Guardate, non c'è più il `goto`,  
28:19
abbiamo fatto tutto solo utilizzando l'`if`.
28:25
La prossima volta vedremo una cosa molto  interessante che si chiama tail call optimization,  
28:32
l'ottimizzazione della chiamata che sta in coda.  Una cosa che però dovete notare ora è che c'è  
28:40
una differenza rispetto al `goto` che avevamo  utilizzato prima. Qui, ogni volta viene chiamata  
28:46
di continuo una funzione. Anche se è se stessa,  viene comunque creato di nuovo uno stack frame,  
28:55
vengono create altre due variabili, `start`  ed `end`. E io di ciò ve ne voglio dare prova.  
29:02
Tanto noi ormai sappiamo stampare i puntatori  delle variabili, anche se non sappiamo cosa sono   bene i puntatori. Sappiamo che con la `printf`  mettiamo `%p` e poi mettiamo `&` prima del nome  
29:15
di una variabile, e ciò traduce la variabile nel  suo indirizzo di memoria. Facciamoci stampare,  
29:23
man mano che questa funzione viene chiamata  in maniera annidata, l'indirizzo di `start`.
29:30
Guardate questi indirizzi di memoria:  `...c8`, `...98`, `...68`, eccetera,  
29:35
eccetera. Praticamente, se io prendo la  differenza, vedo che ho utilizzato mezzo kilobyte  
30:09
di memoria per un contatore che è 4 byte. Capite  che questo modo di scrivere i programmi (questa  
30:17
si chiama programmazione funzionale) è elegante,  ma ha qualcosa che non va: utilizza tanta memoria  
30:24
di stack, perché le chiamate annidate continuano,  in pila una sopra l'altra, a consumare memoria.

My notes:

#include <stdio.h>

void condizioniFn(void)
{
    int i = 5;

    if (i > 3)
    {
        printf("i > 3\n");
    }
    else
    {
        printf("i <= 3\n");
    }

    // se solo una istruzione non servono blocchi
    if (i > 3)
        printf("i > 3\n");
    else
        printf("i <= 3\n");

    // possibile mettere ovunque blocchi in c e il blocco ha una propria memoria locale
    int j = 8;
    {
        int j = 5;
        printf("j (%zu bytes) is %d, and stored at %p\n", sizeof(j), j, &j); // print 5
    }
    printf("j (%zu bytes) is %d, and stored at %p\n", sizeof(j), j, &j); // print 8
}

void gotoFn()
{
    int i = 0;

again:
    printf("Again Count i: %d\n", i);
    i++;
    if (i < 10)
        goto again;

    // con le etichette, esempio ciclo infinito;
    //  l10: printf("Ciao"");
    //  l20: goto l10;
}

void whileFn(void)
{
    // equivalente al gotoFn
    int i = 0;

    while (i < 10)
    {
        printf("While Count i: %d\n", i);
        i++;
    }

    // compilazione del while
    int j = 0;

loop:
    if (j < 10)
        goto enter_loop;
    goto next;
enter_loop:
    printf("Loop Count j: %d\n", j);
    j++;
    goto loop;
next:
    return;
}

void recursiveFnConta(int start, int end)
{
    // programmazione funzionale -> utilizza molta memoria di stack
    if (start > end)
        return;
    printf("Recursive Count: %d\n", start);
    recursiveFnConta(start + 1, end);
}

int main(void)
{
    condizioniFn();

    gotoFn();

    whileFn();

    recursiveFnConta(0, 9);

    return 0;
}


Lesson 7 - video link: https://www.youtube.com/watch?v=HCRthhjbfAg&list=PLrEMgOSrS_3cFJpM2gdw8EGFyRBZOyAKY&index=9

Transcript:
0:39
Bene, eccoci qui dal mare per la  settima lezione di programmazione in C.  
0:46
Vi ricordate che eravamo arrivati qui:  avevamo scritto, mentre esploravamo tutte  
0:53
le possibilità per fare dei loop nel linguaggio  di programmazione C, questa funzione che usa la  
1:01
ricorsione. La funzione si chiama `conta`  e prende come argomento `start` ed `end`.  
1:08
Vi vorrei fare notare una  cosa prima di continuare. Questa funzione, concettualmente, fa questa cosa  qui: stampa il numero dello `start` e poi richiama  
1:20
se stessa col resto della computazione da fare,  cioè contare di nuovo da un numero più avanti  
1:28
fino alla stessa fine esatta. Ora, questo modo  di pensare alla ricorsione è estremamente comune,  
1:37
quindi quello che vedete qui non è l'applicazione  di un pattern bizzarro, ma è qualcosa che  
1:42
invece è la norma. Durante l'applicazione della  ricorsione, voi potete scomporre un problema in:  
1:50
"ne faccio un pezzettino e poi rimando a se  stesso", diciamo, "delegato questo pezzettino  
2:01
a fare il prossimo pezzettino". Già avete risolto  il problema in termini ricorsivi. Poi vedremo che  
2:08
questa cosa si può applicare a moltissimi casi.  Vi faccio un esempio pratico: immaginate di  
2:15
dover scrivere una funzione che trova il massimo  valore in un array. Allora, tanto per iniziare,  
2:25
questa funzione scriviamola... perché siccome  abbiamo anche visto come funzionano gli array...  
2:33
facciamo `int max` e... ecco, il problema è che  servono i puntatori. No, ancora questa cosa non  
2:40
la possiamo fare, in effetti, perché altrimenti  dovremmo scriverla male e non è una buona idea.  
2:46
Però, ecco, anche solo concettualmente, è una  funzione che cerca il massimo in un array.   Io potrei dire: se l'array è costituito da un solo  elemento, il massimo è quello; se invece l'array  
3:02
non è costituito da un solo elemento, il massimo  di tutto l'array è il massimo tra questo elemento  
3:11
e il massimo di tutti gli elementi restanti  dell'array. E anche in questo caso, questo modo  
3:18
di scrivere la funzione mi permetterebbe  di implementarla in termini ricorsivi.
3:24
La scorsa volta abbiamo parlato pure di  un'interessante ottimizzazione possibile  
3:29
che si chiama *tail call optimization*. Che  cos'è una *tail call*? In questo caso la  
3:36
funzione `conta` richiama se stessa. Ora, anche  se i compilatori moderni possono rendersi conto  
3:46
di questa cosa e ottimizzare la chiamata in  modo da non creare veramente un nuovo stack   frame (l'altra volta avevamo stampato i puntatori  e vedevamo che erano sempre diversi), in sostanza  
3:56
ogni chiamata annidata della funzione creava un  nuovo stack frame e utilizzava nuova memoria.  
4:05
Se non vogliamo fidarci del compilatore,  possiamo fare questa cosa a mano,   sempre con il nostro fantastico `goto`. E allora,  guardate: questa la chiamiamo `conta_vanilla`,  
4:18
cioè l'implementazione semplice, e la nostra  `conta` la facciamo diventare invece così.  
4:28
Se `start` è maggiore di `end` abbiamo finito,  altrimenti stampa `start` e poi fai la stessa  
4:35
cosa con `start + 1` ed `end`. Ora, se io qua,  come prima riga, faccio un'etichetta per il `goto`  
4:45
che chiamo `iterate`, posso sostituire questa  chiamata qua (`conta(start + 1, end)`). Uguale  
5:00
`start + 1`, `end` è sempre `end`, quindi non  lo modifico. `goto iterate` non cambia niente.
5:10
Questa è come una chiamata alla funzione stessa,  perché io sto saltando all'inizio della funzione.  
5:17
Ho modificato lo stato in modo che la prossima  chiamata sia con uno `start` maggiore a quello  
5:23
di prima, e quindi è esattamente come chiamare una  funzione. Questa cosa si può fare solo se `conta`  
5:28
è una chiamata di coda, il che significa  che io non stia chiamando, per esempio,  
5:33
una funzione `F(conta(...), qualcos'altro)`.  In questo caso, ci sarebbe sì la ricorsione,  
5:40
ma io poi dovrei mantenere lo stato, perché dovrei  chiamare `F` col ritorno di `conta` e con qualche  
5:47
altra cosa. Questi sono degli argomenti di teoria  della programmazione che sono molto interessanti,  
5:58
ma che in questo caso non possiamo approfondire  perché noi ci dobbiamo occupare del C.   Però, per programmare in C in maniera  efficace, a volte è importante modificare  
6:07
la ricorsione e farla diventare iterazione,  e sappiate che il modo per farlo è questo.
6:12
Proviamo a compilare il nostro programma:  `loop.c -o loop -Wall`. Che mi dice qui?  
6:27
Qui mi dice che in `conta_vanilla` non  ho cambiato, nella versione vanilla,  
6:33
il nome della funzione. E ora ci siamo. Eseguiamo  il programma e ora stampa 0 1 2 3 4 5 6 7 8 e 9.
6:43
Inutile dire che se ora io, oltre al numero,  stampo il puntatore a `start`... quindi  
6:49
io stampo `start` con `%d`, poi con `%p`  stampo il puntatore a `start`. No, scusate,  
6:56
ho sbagliato. Questa cosa la dovevo scrivere qui,  perché questa è la nostra versione "vanilla".  
7:02
In quella invece in cui abbiamo rimosso la *tail  call* e l'abbiamo fatta diventare un `goto`,  
7:11
inutile dire (perché è piuttosto ovvio)  che l'indirizzo di memoria della nostra   variabile sarà sempre lo stesso, perché  è sempre lo stesso stack frame e sempre  
7:19
la stessa invocazione della stessa funzione.  Quindi qui non utilizzeremo memoria in più.
7:26
Bene. Ovviamente il `goto` serve a questo  e ad altri scopi in C, ma normalmente non  
7:33
si scrivono i programmi utilizzando il `goto`. Si  utilizzano i costrutti di loop a più alto livello.  
7:40
Avevamo visto l'altro giorno il `while`, ma ora li  riaffrontiamo tutti, proprio utilizzando il fatto  
7:51
di dover contare. Però scriviamo tutto dentro  la `main` per rendere la questione più semplice.
7:58
Quindi, tanto per iniziare, il `while`. `int i =  0; while (i < 10)`... stampo `i` e lo incremento.  
8:13
Quindi il `while` è molto simile al `while` che  conoscete negli altri linguaggi di programmazione.  
8:22
Compiliamo questo programma, `printf`,  e il risultato sarà sempre lo stesso.
8:35
C'è un ciclo che si chiama `for`, che potete  conoscere da altri linguaggi. Dipende da   quale linguaggio di programmazione provenite.  Credo che in JavaScript sia proprio identico a  
8:45
quello del C. Sì, allora, in JavaScript  è proprio esattamente identico. Invece,  
8:54
in linguaggi di programmazione come Python o Ruby,  le cose sono più ad alto livello, sono diverse,  
9:01
e quindi chi viene da quei linguaggi non conosce  questo costrutto, per cui lo vediamo qua. Io  
9:08
questo programma avrei potuto scriverlo pure  come: `for (i = 0; i < 10; i++)`. A questo punto,  
9:19
dentro il corpo del ciclo c'è soltanto la  `printf`, perché l'incremento è messo qui.
9:26
Allora, guardate, io per iniziare eseguo  questo programma perché vi voglio far   vedere che l'output è esattamente come quello  di prima: da 0 a 9 e da 0 a 9 qui. Ma il `for`,  
9:37
in pratica, è un `while` mascherato. Allora,  iniziamo: ci sono tre parti nel ciclo `for`  
9:46
dopo la parentesi tonda. La parte prima,  che è l'inizializzazione; la parte seconda,   che è il controllo; e la parte terza, che è,  diciamo, l'incremento. Ora, la parte prima,  
9:58
se voglio trasformare il `for` in un `while`, la  scrivo come prima cosa prima del ciclo `while`.  
10:03
Quindi ho fatto proprio una trasformazione  di testo: ho preso questa e l'ho messa qui.  
10:09
Poi scrivo il ciclo `while` e gli metto come  condizione la seconda parte. Poi scrivo qualsiasi  
10:17
cosa c'è nel corpo del `while` e l'ultima parte,  la terza parte del `for`, la metto qui. Questi  
10:29
due cicli sono assolutamente identici. Il `for`  è sostanzialmente zucchero sintattico per il  
10:38
ciclo `while` che ha un momento, diciamo, di  inizializzazione e un momento di incremento.
10:45
Tra l'altro, vorrei farvi notare che, siccome la  variabile `i` era già inizializzata, in questo  
10:50
caso io posso omettere l'inizializzazione,  mettendo soltanto il punto e virgola.  
10:58
Se lo compilo, questo programma, il  compilatore non avrà nulla da ridire   e funziona perfettamente. Posso omettere  anche la condizione di test e scrivere qui  
11:11
una cosa che ci serve da approfondire: `if  (i >= 10)`, quindi se la condizione non è  
11:20
verificata (l'ho invertita), `break`.  Rompi il ciclo, esci dal ciclo. Ok.
11:28
Quindi `break`, che si può usare sia con i cicli  `for` che con i cicli `while` (e si usa pure con  
11:34
lo `switch`, ma ha una funzione diversa), termina  il ciclo e va al prossimo ciclo annidato o,  
11:41
se non ci sono altri cicli annidati, prosegue.  Cioè, semplicemente prosegue immediatamente dopo  
11:47
la parentesi graffa del blocco dentro il quale è  chiamato o, se non c'è alcun blocco, semplicemente  
11:54
dalla prossima istruzione (`statement`),  quella che viene immediatamente dopo.
12:00
Compiliamo questo programma e funziona ancora.  
12:05
Posso anche omettere l'incremento e lo metto  qua. A questo punto il `for` è diventato un ciclo  
12:13
`while` che non ha né inizializzazione,  né controllo, né incremento. Di fatto,  
12:20
è un ciclo infinito. Continua a funzionare  perché io ho messo la condizione di stop qua,  
12:27
utilizzando `break`, e ho messo l'incremento alla  fine. Così come il ciclo `for`, in questo caso,  
12:34
modella un ciclo infinito. L'altro modo per fare  un ciclo infinito in C è `while(1)`. `while(1)`  
12:42
perché 1 è una condizione sempre vera. Per il C,  un numero uguale a 0 è falso, un numero diverso  
12:54
da zero è vero. Compiliamo di nuovo questo  programma e avremo sempre il solito ciclo.
13:12
Il `break` funziona bene per uscire da un ciclo.
13:25
Il C, da alcune versioni in poi, consente di  dichiarare la variabile direttamente dentro il  
13:32
ciclo `for`, nella parte di inizializzazione:  `for (int i = 0; i < 10; i++) printf("%d",  
13:40
i);`. Qua non usiamo il blocco perché è una sola  istruzione, e io in una sola riga ho espresso una  
13:49
computazione complicata. Qua mi ero dimenticato  la `i`. Questo programma fa ancora quello che  
13:57
facevano i programmi di prima, ma è solo una riga.  È molto facile da leggere. C'è un problema, però:  
14:04
dopo questa istruzione, `i` non esiste  più. Guardate: se io stampo `i` qua,  
14:13
non c'è più e si blocca tutto. Mi dà un errore di  compilazione perché `i` qua non c'è più. Invece,  
14:21
se io lo stesso programma lo scrivo così,  `i` esiste ancora (ho scritto `print`,  
14:29
scusatemi), esiste ancora dopo il `for`  e mi stamperà 10. Allora, per distinguere  
14:37
quello che stampa questa `printf`, gli metto  due segni di maggiore. Esatto: 0...9, >>10.
14:47
A volte è comodo poter utilizzare il fatto di  sapere che valore ha la variabile di ciclo dopo  
14:55
il ciclo. Per esempio, se vogliamo sapere... vi  faccio un esempio molto semplice ma interessante:  
15:04
`int a[] = {1, 5, 7, 8, 4, 9, 0};`. Ve lo  ricordate che avevamo parlato degli array e   di come si dichiarano? Facciamo che questo ciclo  si blocca quando arrivo a zero. Ok. `for...`  
15:36
Dichiariamo una variabile `i` che ci serve  per accedere ai membri di questo array.  
15:41
Partiamo facili: facciamoci stampare tutti  questi elementi qua dell'array. `for (i = 0;  
15:51
a[i] != 0; i++)`, e qua scriviamo  `printf(...)`. Vi ricordate che  
16:06
agli elementi dell'array si accede con  le parentesi quadre? Ne abbiamo parlato  
16:11
nella lezione in cui abbiamo introdotto  le stringhe. Compiliamo questo programma.
16:20
Mi vedo stampare gli elementi  del mio array, escluso lo zero,   perché questo `for` uscirà dal ciclo una volta  che `a[i]` è uguale a 0. Quindi la condizione  
16:32
per continuare il ciclo è che `a[i]` non è  uguale a 0. Ricordatevi che è come un `while`,  
16:37
quindi è come dire "mentre", "fintanto che  `a[i]` non è uguale a 0, continua a fare questo".
16:45
Ora, immaginate che io invece non voglia stampare  gli elementi dell'array, ma voglia vedere se  
16:56
dentro l'array, da qualche parte, c'è il numero  8. Io scrivo, quindi: `if (a[i] == 8)` - sono due  
17:05
uguali perché è un'operazione di comparazione  e non di assegnazione, altrimenti sarebbe un  
17:14
solo uguale - `break`. Rompo il ciclo. A questo  punto, fuori dal `for`, come faccio a sapere se  
17:24
effettivamente c'era 8 dentro l'array o no? Beh,  lo faccio osservando la variabile `i`. Se `i` è  
17:33
arrivata alla posizione in cui l'array è finito  (e io in questo caso l'ho contrassegnato con zero,  
17:38
come se fosse una stringa in C - lo sapete che  le stringhe in C sono array di interi piccoli  
17:44
di 8 bit che poi finiscono con zero, che fa da  terminatore - e ho utilizzato questo stratagemma  
17:51
pure qua per fare un programma più semplice),  allora... io qui posso dire, oh scusatemi, posso  
18:03
dire: `if (a[i] == 0)` - quindi se praticamente  ho raggiunto l'elemento 0 - `"non trovato"`,  
18:16
`else` `"trovato"`. Compiliamo questo programma.  In effetti, il nostro 8 è stato trovato, perché  
18:30
qua c'è. Se io ora questo 8 lo sostituisco con un  5, l'otto non c'è più, e mi scrive "non trovato".
18:40
Ora, questo tipo di struttura di programmazione  non la posso avere se scrivo qua `int i`,  
18:49
perché immediatamente qua il valore di `i`  non sarebbe più presente. Quindi a volte,  
18:55
anche se sembra efficace, elegante e, come  dire, ottimizzante dello spazio verticale  
19:07
fare le dichiarazioni in questo modo,  in realtà abbiamo visto che c'è qualche   problema nell'utilizzare questa tecnica.  In questo caso, invece, va benissimo.
19:22
Ora vi volevo parlare del `do-while`. Il `while`  ha una, diciamo, alternativa con una semantica un  
19:38
po' diversa. In sostanza, in questo caso, prima  viene fatta la prima iterazione e solo dopo viene  
19:48
testato se effettivamente la condizione  è vera. Se la condizione è ancora vera,  
19:55
si ritorna di nuovo alla parentesi graffa iniziale  e si riesegue il blocco, altrimenti si esce.  
20:01
Questo costrutto non è spesso necessario; ci  sono sempre modi alternativi per farlo, scrivendo  
20:10
`while(1)` e mettendo sotto la condizione di stop  `if... break`. Però, ogni tanto, risulta valido.
20:20
Invece, più interessante è lo `switch`. Lo  `switch` è importante per alcuni motivi,  
20:27
e ora vi dico perché. Lo `switch`,  peraltro, non c'è in molti linguaggi  
20:33
di programmazione... mi sa... beh sì, in  tanti sì. In JavaScript c'è lo `switch`.  
20:42
Sì, il JavaScript è proprio preso pari  pari dal C a livello, diciamo così,  
20:53
di questi costrutti di base, anche a  livello sintattico. Guardate, è identico:   `break;`. JavaScript somiglia moltissimo  al C dal punto di vista grammaticale.
21:05
Allora, lo `switch` di C è molto simile  a quello di JavaScript. E vi faccio un  
21:13
esempio: `int i = 10; switch(i)`. In  sostanza è una collezione di `case`.  
21:22
`case 5: printf("è un 5\n"); break;`.  `case 7: printf("è un 7\n"); break;`.  
21:47
`default: printf("qualche altro numero\n");  break;`. Compiliamo. "qualche altro numero".  
22:14
Perché `i` è uguale a 10, effettivamente 10 è  "qualche altro numero". Mettiamogli 5. "è un 5".
22:23
Allora, che succede? Lo `switch` è molto simile  a `if (i == ...)`, `else if (i == 7) ...`. Non  
22:39
vi ho detto, probabilmente, che `if` si  può scrivere anche così, con `else if`,   per fare una catena di `if` di cui solo la prima  che sarà verificata "vincerà" e tutte le altre  
22:50
non verranno eseguite. L'`else` finale,  senza l'`if`, sarebbe il `default`: cioè,  
22:57
la condizione di `default` viene presa se tutte  quelle di prima falliscono. Fa qualcos'altro.
23:04
Non ci sono tante differenze, ma ce n'è una  importante: il `break` è necessario, altrimenti  
23:14
succede una cosa. Se io non lo metto, quando  entro nel `case 5`, viene eseguita l'istruzione  
23:23
che è associata al `case 5` (e tra l'altro  qui possono essere più di una le istruzioni,  
23:30
io posso scrivere: "sì, proprio un bel cinque!",  ok). Alla fine qua ci vorrebbe `break`, ma noi  
23:39
lo abbiamo eliminato. Commentiamolo con `//`.  Forse dei commenti in C non ne abbiamo parlato,  
23:45
ma ne parleremo, perché ci sono solo due modi  di commentare: o questo (`//`) o multilinea  
23:54
(`/* ... */`). Comunque, `case 5`: qui lo  commentiamo, abbiamo detto. Siccome non c'è  
24:06
il `break`, dopo che viene seguito il blocco di  codice associato al `case 5`, si entra nel `case  
24:15
7` - quello proprio successivo dal punto di vista  strettamente sintattico, quello che viene dopo. Si  
24:21
entra qua dentro, finalmente c'è il `break`  e quindi qui ci blocchiamo. Scriviamo tutto   così per chiarezza. Compiliamo. Guardate che  succede: "è un 5", "sì proprio un bel cinque",  
24:34
"è un 7". Perché era cinque, quindi entrava  qua, non c'è il `break` e prosegue. Se io il  
24:40
`break` lo rimetto, lo ripristino, fa solo  le prime due istruzioni e poi si ferma.
24:49
Cose importanti a proposito dello `switch`:  qui non si possono dichiarare variabili.  
24:54
Se io dichiaro una variabile qua, ecco  qui, errore, perché questa è una *label*,  
25:03
come se fosse una *label* del `goto`. Infatti,  ci sono molti modi per compilare questa cosa qua;  
25:12
il compilatore potrebbe fare, per esempio,  quella che si chiama una *jump table*,   un costrutto molto efficace per compilare queste  cose in modo da non fare davvero tutti i test.  
25:28
Allora, come si fa se io devo  dichiarare qua dentro delle variabili?   Ma noi abbiamo detto che i blocchi in C  li possiamo mettere ovunque noi vogliamo,  
25:42
quindi se facciamo così... mi dà il  warning che la variabile non è utilizzata,   ma io ora la uso e non ho più neanche questo  warning. E semplicemente, come potete vedere  
25:58
(tra l'altro l'ho chiamata pure `i`, come quella  di prima, quindi va in *shadowing*), cambiamole   nome. Come potete vedere, ciò mi consente di  avere le variabili anche dentro il `case` del C.
26:17
Sono tentato di fare una cosa. Tutte queste cose  che ci siamo detti, in particolare lo `switch`,  
26:27
voglio vedere nel codice reale che ho scritto  (ed è facile beccare il codice che ho scritto  
26:34
io) quante volte è usato. E, se ci pensate,  è usato poco, non moltissime volte. No,  
26:47
ci sono tanti utilizzi, però insomma... quanti  sono? Vediamo. 2011 utilizzi su tanto codice... su  
27:06
154.000 righe di codice, 2011 utilizzi secondo  me sono pochi. Per capire perché sono pochi,  
27:13
facciamo il paragone col `while`, che ho usato  1353 volte. Si capisce che, però, insomma...
27:23
Andiamo a vedere com'è che è utilizzato  lo `switch`. Ah, questo è bello. Questa   è una funzione che ho scritto tanti anni fa  che fa il *globbing* di una stringa. Avete  
27:35
presente quando tu fai `bla*` o `bla_ab*` e  questo farà match con "blablabla" e così via?  
27:47
Questa funzione fa questa cosa qua. Tra l'altro,  questa è una funzione ricorsiva. Guardate:  
27:52
se io cerco se stessa, la trovo qua. Esatto, la  trovo lì, nel caso dell'asterisco, perché un modo  
28:03
molto interessante per implementare 'sta roba qua,  ovviamente, è con la ricorsione. Non è il modo più  
28:09
efficace, ma è il modo più semplice, diciamo,  ed elegante. Quindi qua, per esempio, utilizzo  
28:15
lo `switch` per sapere che valore ha un dato  carattere. Allora, se il `pattern[0]`, quindi il  
28:24
carattere che in questo momento sto processando,  è un asterisco, farò delle cose. Poi, guardate,  
28:29
qui c'è il `break`. È un punto interrogativo? Farò  altre cose. È una parentesi quadra? E guardate,  
28:36
qua si apre proprio il blocco, perché mi serve  dichiarare due variabili, `not` e `match`. Quindi,  
28:44
come vedete, le cose che ci siamo detti hanno  un'applicazione pratica, diciamo, super diretta.
28:53
Andiamone a vedere un altro. Ecco, questo è  un caso più classico: devo ritornare diversi  
29:05
valori in base, per dire, a delle costanti.  E quindi qui posso o dichiarare un array a  
29:14
cui a questi indici corrispondono questi  valori e faccio `return array[encoding]`,  
29:24
che sarebbe stata un'opzione, altrimenti  posso fare così: un altro `switch`.  
29:30
Ah, questa è una funzione che genera una  stringa casuale e sceglie dei parametri  
29:37
casuali per la generazione della stringa:  valori minimi e massimi, in modo che alcune   stringhe siano completamente binarie (da  0 a 255, quindi tutti i byte possibili),  
29:47
altre da 48 a 122 (che credo che siano, diciamo,  tutto l'ASCII più leggibile) e l'altro da 48 a 52,  
29:56
che saranno, non lo so, forse solo i numeri.  Probabilmente sì... vediamo se sono solo i  
30:04
numeri decimali... da 48, esatto... dalla '0'...  a 52... quindi solo pochi numeri, 0, eccetera.
30:21
Va bene, credo che per questa lezione ci siamo.  Ci vediamo alla prossima. Godetevi il mare,  
30:28
godetevi in generale la vita anche se non vi  piace il mare, e buon fine settimana. Ciao raga!

Notes:
#include <stdio.h>

void tailCallConta(int start, int end)
{
    if (start > end)
        return;
    printf("Tail Call Counter: %d, with pointer %p\n", start, &start);
    tailCallConta(start + 1, end);
}

void tailCallOptimizationConta(int start, int end)
{
    // modificare una ricorsione per farla diventare iterazione
    // utilizzabile solo se Conta è una funzione di coda
    // non: f(conta(start, end), ...)
iterate:
    if (start > end)
        return;
    printf("TCO Counter: %d, with pointer %p\n", start, &start);
    start = start + 1;
    goto iterate;
}

void whileFn(void)
{
    int i = 0;
    while (i < 10)
    {
        printf("While: %d\n", i);
        i++;
    }

    // while(1) - aka while true - è un ciclo infinito
}

void forFn(void)
{
    int i = 0;
    for (; i < 10; i++)
    {
        printf("For 1: %d\n", i);
    }
    printf(">> %d", i);

    for (int i = 0; i < 10; i++)
    {
        printf("For 2: %d\n", i);
    }

    for (int i = 0;; i++)
    {
        if (i >= 10)
            break; // il break rompe il ciclo - esce dal ciclo
        printf("For 3: %d\n", i);
    }

    for (int i = 0;;)
    {
        if (i >= 10)
            break;
        printf("For 4: %d\n", i);
        i++;
    }

    //---------------
    int a[] = {1, 5, 8, 4, 9, 0};
    int j;
    for (j = 0; a[j] != 0; j++)
    {
        if (a[j] == 8)
            break;
    }
    if (a[j] == 0)
    {
        printf("Non trovato\n");
    }
    else
    {
        printf("Trovato, in posizione %d\n", j);
    }
}

void doWhileFn(void)
{
    int i = 0;
    do
    {
        printf("Do While: %d\n", i);
        i++;
    } while (i < 10);
}

void switchFn(int i)
{
    // senza il break si passa anche alle istruzioni del case successivo
    switch (i)
    {
    case 5:
    {
        char* s = "sei";
        printf("Cinque e poi %s\n", s);
        break;
    }
    case 7:
        printf("Sette\n");
        break;
    default:
        printf("Not 5 or 7\n");
        break;
    }
}

int main(void)
{

    tailCallConta(0, 9);
    tailCallOptimizationConta(0, 9);

    whileFn();

    forFn();

    doWhileFn();

    switchFn(5);

    return 0;
}


il while e la ricorsione viene trattata in entrambe le versioni. Genera il README in maniera tale che non sia ripeititivo, ma come se le lezioni fossero una soltanto e gli argomenti trattate più volte siano generati nel README solamente una, in maniera "intelligente" ovvero inserendo le cose importanti di tutte le volte in cui sono stati trattati.