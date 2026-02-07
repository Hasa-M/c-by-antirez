Special Lessons 1: 
link: https://www.youtube.com/watch?v=soiBgJjAmP8&list=PLrEMgOSrS_3cFJpM2gdw8EGFyRBZOyAKY&index=19

Transcript:
0:40
Ammazza che bello background del  ... che c'ho in questa stanza.
0:50
Allora, è mezzanotte e mezza, ho bevuto troppo  vino, però non mi andava di andare subito a  
0:57
letto e ho letto i commenti sul discorso di  chiedere o non chiedere alle interviste di  
1:04
programmazione — ai colloqui di programmazione,  diciamolo bene — domande algoritmiche. E io ciò  
1:11
che dicevo è che non serve andare, diciamo,  nei dettagli e negli algoritmi complicati;  
1:16
è che alcune idee dell'informatica sono  talmente fondamentali e legano i pezzi tra  
1:25
di essi che non è neanche necessario  imparare le cose a memoria. Infatti,  
1:30
farò un esperimento. Io non implemento un  Binary Search Tree da almeno 20 anni e posso  
1:39
usarmi come auto-cavia per far vedere se mi  riesce il processo col quale posso, diciamo,  
1:46
in qualche modo riesumare dalla mia memoria  il modo in cui si scrive un albero binario,  
1:53
facendo appello solo alle idee fondamentali  che ci sono in questa struttura dati.
1:59
Allora, io di questa struttura  dati so di certo una cosa:  
2:02
che ogni nodo ha a sinistra dei nodi  che hanno un valore inferiore a esso,  
2:12
e a destra dei nodi superiori ad esso. Ogni  nodo registra anche un'informazione satellite,  
2:17
che è il suo valore; noi per semplificare  magari la facciamo solo numerica.
2:22
Quindi, per iniziare... allora, Binary Search  Tree in C. Tanto per iniziare, sicuramente devo  
2:28
definire una struttura. Vabbè, facciamo anche  l'include di `stdio.h` perché stamperò qualcosa  
2:36
e `stdlib.h` perché mi serve. Eh, questo poi  lo vedremo nel corso: che le strutture dati  
2:44
linkate sono dove l'allocazione della memoria è  assolutamente fondamentale, `malloc` e `free`,  
2:50
perché io alloco nodi e li libero così come mi  serve. Allora, si chiama `struct node`, e io  
2:58
so che c'ho uno `struct node *left` e `*right`.  Quindi il mio nodo avrà un puntatore sempre allo  
3:06
stesso tipo, al tipo `node`, che punta al suo  figlio sinistro e uno al destro. Nel sinistro  
3:16
avrò valori inferiori, nel destro avrò valori  superiori, e poi il valore io lo chiamo `val`.  
3:23
Basta, la mia struttura dati è tutta qua. In  teoria, dovrei definire pure una `struct tree`,  
3:31
ma secondo me 'sta roba qui posso evitarla, perché  vorrei scrivere un'implementazione semplice. Eh.
3:44
Allora, iniziamo dalla `main`. Io  voglio qualcosa del genere, quindi:  
3:49
`struct node *root` che all'inizio sarà uguale  a `NULL`. Quindi io voglio poter fare `add`,  
4:00
in cui passo la `root` attuale, che però in  questo momento è `NULL`, e poi il nuovo valore  
4:04
che voglio scrivere dentro l'albero di ricerca  binaria. Ma siccome questa `root` all'inizio è  
4:10
`NULL` e poi può essere che non è più `NULL`,  io ho due possibilità: o qua devo fare così,  
4:16
passo un puntatore a puntatore a `root`, o faccio  `root = add(root, ...)`. Così, se praticamente la  
4:26
`root` non è `NULL`, mi ripassa la `root` che  io gli ho passato. Se la `root` era `NULL`,  
4:31
alloca il primo nodo e me lo restituisce.  Il primo nodo in assoluto. `return 0;`.
4:42
Allora... no, `struct node*  add(struct node *root, int val)`.
4:55
`// Add a new node, if root is  NULL returns the new root (the  
5:07
first inserted node) otherwise it  just returns the root passed by the  
5:22
user in input.`
5:24
Tutta questa complicazione, in  realtà, è perché non ho voluto  
5:27
definire la struttura `tree`. Forse  non è il caso, ma proseguiamo così,  
5:34
eh. Ok, allora, `if (root == NULL)`.  Allora, prima facciamo una cosa.
5:44
`struct node *new = malloc(sizeof(*new));`
5:53
Vi insegno un trucco. Invece di fare  così, uno può dire `sizeof(*new)`.  
5:58
Quindi, praticamente, dereferenziare il puntatore  
6:03
nel caso dell'operatore `sizeof`  mi dà il tipo, diciamo, base.
6:11
`// We don't check for malloc()  failures since this is a trivial  
6:37
example written at 00:09 o'clock with  glasses of wine fogging the head.`
7:02
Non controlliamo il valore di ritorno.  `malloc` potrebbe ritornare `NULL` in  
7:06
caso di out of memory. Ma su questo discorso,  su questa questione, faremo un lungo discorso  
7:11
nel corso di programmazione in C, perché  vedremo che i sistemi operativi, in realtà,  
7:15
ormai operano in maniera diversa nella maggior  parte dei casi. Quindi, però, freghiamocene.
7:23
Allora, `new->left = new->right = NULL`.  Inizializziamo a `NULL` left e right. `new->val =  
7:33
val`. Se la `root` è `NULL`, `return new`. `new` è  la mia `root`. Altrimenti, io devo fare una cosa:  
7:48
nel mio albero devo andare a cercare la posizione  in cui inserire il mio nuovo nodo. E, in sostanza,  
7:56
io devo fare un ciclo in cui io faccio...  `if (val > root->val)`... altrimenti, se è  
8:27
maggiore o uguale... anzi, facciamo una cosa, se è  maggiore... allora, se è maggiore io devo inserire  
8:34
'sto robo qui a destra, ammesso che ci sia spazio.  Quindi, `if (root->right == NULL)`. Quindi se,  
8:47
praticamente, a destra io ho spazio perché questo  nodo in cui sono in questo momento non ha il child  
8:59
destro, io ci posso inserire il mio valore. Quindi  che cosa farò? `root->right = new`. E `return...`.
9:18
Ora, io mentre giro col ciclo `while`...  allora io qua devo fare una cosa. Intanto,  
9:27
iniziare... qua scrivo `root = root`... sì, sì,  ok. Allora, se è così, che io l'ho inserito,  
9:34
devo ritornare, però io mi devo ricordare  qual è la `root` attuale. Perché io qua,  
9:47
quando praticamente non è il primo nodo, io devo  ritornare `saved_root`, che io poi qua faccio  
9:53
`root = root->right`. Quindi continuo a seguire.  Se non è nullo, io devo continuare a seguire,  
10:03
così poi il ciclo `while` torna qui e prendo  di nuovo la scelta destra o sinistra in base  
10:08
al nuovo valore rispetto al mio valore che voglio  inserire. Altrimenti, vabbè, qua diciamo così si  
10:15
crea una ripetizione. Non credo che sui libri di  testo troverete questo codice scritto così. `if  
10:21
(root->left == NULL)`, questa è la stessa filza,  `root->left = new`. Si potrà scrivere in maniera,  
10:29
diciamo, più elegante. Quindi lo inserisco e torno  `saved_root`. Altrimenti, `root = root->left`. Ok.
10:39
Uscendo da qui, che succede?  
10:47
Eh, allora sì, ho trovato un nodo qua. Volendo  potevamo fare `break`. Questo `saved_root` lo  
10:58
facciamo fuori... Vabbè, ma così è meglio. In  pratica succede 'sta cosa: quando poi qua io ho  
11:04
fatto, sono andato qui, che ho selezionato poi il  nodo a destra o il nodo a sinistra, l'algoritmo si  
11:09
ripete, perché qua c'è un `while(1)`, quindi  è un ciclo infinito, e io continuo a cercare  
11:14
praticamente per i valori. Però qua io sto facendo  una cosa: me ne sto impipando di controllare se il  
11:20
valore che mi hanno dato in realtà è dentro  l'albero, e in caso lo sparo a sinistra.  
11:25
Se ci sono più 10, per dire, io li metto tutti in  fila, e ciò mi pare che vada bene. `saved_root`  
11:33
io me lo sono salvato, che è uguale a `root`.  Ok, proviamo a inserire 10, 5, 20, 100 e 33.
11:50
`gcc bst.c -Wall -Wextra -o bst`. Vediamo che  succede. Vabbè, il programma gira, non è crashato.
12:03
Per vedere se io ho creato un albero  corretto, io vorrei stamparlo. Allora,  
12:08
una cosa bella dei Binary Search Tree è che poi  tu puoi navigare l'albero in maniera ordinata,  
12:15
dall'elemento più piccolo all'elemento  più grande. E io mi ricordo che questa  
12:19
cosa si può fare con un algoritmo  ricorsivo che è veramente elegante,  
12:25
e mi ricordo che quando me l'hanno mostrato, tipo  30 anni fa o quello che è stato... eh? 30 anni fa,  
12:34
sì, praticamente sì, 30 + 18 = 48. Esatto. Come  passa il tempo. Io sono impazzito per l'eleganza,  
12:44
e vediamo se lo posso ricostruire,  perché è troppo semplice, teoricamente.
12:48
Allora, io voglio la mia `void print_sorted(struct  node *root)`. Eh, allora io prima voglio stampare  
13:06
il valore più piccolo, quindi praticamente  io richiamo `print_sorted`. Attenzione,  
13:12
`if (root->left)`, se c'ho un figlio... allora,  prima di tutto `root` potrebbe essere nullo,  
13:19
e in tal caso niente, l'albero è vuoto.  Se ho invece `root->left`, io richiamo  
13:29
ricorsivamente la mia funzione su `root->left`,  perché significa che ho dei valori inferiori da  
13:37
stampare rispetto al nodo in cui sono. Poi a sua  volta risuccederà ancora, ancora, ancora, ancora,  
13:42
fino a quando c'è qualcosa a sinistra. Dopodiché,  a destra ho solo valori superiori al nodo attuale,  
13:51
e quindi io farò `printf("%d\n", root->val)`,  quindi stampo 'sto valore, e poi voglio stampare  
14:00
tutti i valori più grandi di quello attuale:  `print_sorted(root->right)`. Esatto. Cioè,  
14:12
guardate ragazzi, ora non lo so se funziona,  vi dico la verità, però per dire, eh, cioè,  
14:19
'sta roba qui è troppo elegante ed è dentro la  struttura dati. Cioè, questo codice non l'ho  
14:24
scritto io, lo ha scritto la struttura di questo  nodo. Cioè, tutto questo codice non è opera mia,  
14:34
è l'albero binario. Vediamo se funziona. Ah,  neanche l'ho chiamata, però. `print_sorted(root)`.
14:48
Esatto. 5, 10, 20, 33, 40... e  sono ordinati. C'è una cosa...
14:54
`cat bst.c`
14:58
"Gemini, please check this example.  Binary Search Tree implementation.  
15:06
Give me a list of bugs. Please note that `free`  is not used on purpose. This is just a trivial  
15:20
example. Also note that I didn't define a  `tree` struct. `add` returns the new root,  
15:37
either the first node or the  root passed by the user."
15:43
Caghiamogli il codice.
15:50
Minchia, ora c'è da aspettare. Che ore sono?  00:19. Tra l'altro, 'sto video lo approvo domani,  
15:58
perché ora è troppo tardi. Mi sono mangiato le  pesche poco fa quando sono arrivato a casa. Quanto  
16:06
sono buone le pesche, è una specie di pesca  catanese che è veramente una bomba, perché i  
16:12
frutti antichi sono troppo buoni, perché non li  hanno selezionati. Aspetta. Uh! "List of bugs."
16:23
"The main issue in the `add` function is the  incorrect handling of duplicated values." Ah,  
16:28
ma questo ve l'avevo detto, che non avrei gestito  i valori duplicati e li continuo a inserire. "The  
16:36
invariant in a BST is: values in the left subtree  must be less than the node's value, and values in  
16:39
the right subtree must be greater than the node's  value. Your implementation... this means if you  
16:43
try to add a value that already exists...  it will be inserted in the left subtree."  
16:50
Questo ve l'avevo detto. "While your  `print_sorted` function still works,  
16:56
the structure violates the standard BST  definition." Ok, io dovrei controllare  
17:01
nel caso di uguaglianza e non inserire un  elemento che c'è già. Ma in realtà... "Bug:  
17:07
memory leak. You allocate memory for six nodes  via `malloc`." Vabbè, non libero mai la memoria,  
17:15
grazie al cazzo, eh. Ah, `free_tree` usa  comunque lo stesso approccio ricorsivo,  
17:23
che è veramente molto figo. Noi non  l'abbiamo implementata, in realtà.
17:33
In realtà, io credo che i valori duplicati qua  funzionano. Guardate, ora inserisco un 20 qua,  
17:39
e anche un 20 all'inizio. Se io compilo e  stampo, guardate, vedete? 5, 10, 20, 20,  
17:46
33, 40, 100. Ora non so se ci sono casi...  In realtà l'invariante del Binary Search  
17:52
Tree dovrebbe essere quella, però credo che  comunque viene composto un albero corretto, eh.
18:00
E poi qui che mi diceva di interessante? Ah, ok.  Qua dice, invece di usare un approccio ricorsivo,  
18:12
ah, io uso un approccio iterativo, ma potevo usare  anche un approccio ricorsivo per l'add, che è un  
18:18
modo carino di procedere. In realtà, praticamente,  dal punto di vista strettamente della funzionalità  
18:23
è meglio utilizzare l'approccio iterativo per  evitare di consumare stack. Addirittura sarebbe  
18:28
stato meglio modificare anche la funzione che  stampa gli elementi per trasformarla in iterativa.
18:40
"In your `print_sorted` function...  this check `if (root->left)` is not  
18:47
necessary." Good catch. Perché siccome io  qua all'inizio controllo se `root` è `NULL`,  
18:55
io qua potevo scrivere `print_sorted(root->left)`  e `print_sorted(root->right)` e funzionava tutto  
19:04
uguale. Esatto. Sì, è più  elegante. Mi piace. Bravo Gemini.  
19:13
Esatto, e infatti l'ha riscritta esattamente  così anche lui. "And your solution is not wrong,  
19:19
but this version is more common."  Grazie, eh, dei miglioramenti.
19:24
Comunque, diciamo, siamo arrivati a  un'implementazione che funziona. Ora,  
19:27
io di tutta 'sta roba qui è da 20 anni che non  tocco minimamente un albero di questo tipo,  
19:33
perché poi in vita mia ho fatto tutto  con altre strutture dati. In particolare,  
19:36
i Radix Tree sono diventati un  arsenale fondamentale, e le Skip List.  
19:43
Io, tra Skip List e Radix Tree, diciamo che ho  surrogato gli alberi di vari tipi. Poi vabbè,  
19:53
il Radix Tree è un albero, però è un albero  profondamente diverso dall'albero binario  
20:00
di ricerca. Eh, però, cioè, vedete?  Esce fuori da sola l'implementazione.
20:06
Anche se poi, ecco, la cosa interessante è questa:  siccome io non mi ricordavo il modo canonico in  
20:12
cui 'ste cose qua vengono implementate, ciò che  succede è che tu tiri fuori l'implementazione  
20:18
per come la pensi tu in quel momento. Quindi  qua a me è venuto di farla spontaneamente di  
20:22
tipo iterativo. Quindi, diciamo, ecco, uno che vi  intervista e voi tirate fuori l'implementazione  
20:29
così, diciamo "a cazzo di cane" come ho fatto io  stasera... Se è un bravo intervistatore, uno bravo  
20:37
a fare colloqui di lavoro, vi dirà: "Ah, bravo, tu  lo sai che cos'è un albero binario di ricerca?".  
20:44
E, possibilmente, non ti farà  l'appunto di Gemini che ti dice:  
20:48
"Beh, non hai... c'è un memory leak", ti  dirà: "Ora mi implementi anche la funzione  
20:51
per liberare la memoria". E tu gli dici:  "Sì, certo, te la implemento", e così via.
20:56
Eh, e questo è il punto. Quindi i quesiti  algoritmici da chiedere, secondo me, sono  
21:02
di questo tipo. Io ora vi ho voluto far vedere  un'operazione di "becchinaggio" dalla memoria,  
21:08
cioè, tu puoi tirare fuori 'sta roba. Ora, questa  cosa la potrei fare con le hash table... vabbè,  
21:14
le hash table, diciamo, anche negli anni le ho  usate molto di più, eccetera eccetera, ma per  
21:19
una quantità di algoritmi potrei usare lo stesso  principio, perché mi ricordo solo l'idea per sommi  
21:23
capi, ma poi dall'idea per sommi capi puoi tirare  fuori l'implementazione, tranne nei casi in cui  
21:30
ci sono dei piccoli dettagli che devi studiare a  tavolino. Ci sono strutture dati che sono così.  
21:36
Eh, quindi per dire, io in questo momento non  mi ricordo per stimare la cardinalità degli  
21:44
HyperLogLog, la formula che devo utilizzare per  aggiustare per cardinalità bassa, per cardinalità  
21:51
alta e così via. Mi ricordo perfettamente  l'algoritmo, però, per dire, farei magari  
21:56
degli errori rispetto a un'implementazione top.  Eh, o sennò, che ne so, i Bloom Filter sono un  
22:02
altro caso in cui poi bisogna applicare comunque  un po' di matematica, dovrei lavorarci un po',  
22:07
ma ci sono altri casi in cui praticamente  l'implementazione emerge dalle idee di base.
22:11
Va bene, spero che questo video si senta,  perché qui rimbomba, e poi può essere che  
22:17
però riesco a cancellare il rimbombo con DaVinci  Resolve. Ora me ne vado a letto. Buonanotte.

My notes: bst.c
#include <stdio.h>
#include <stdlib.h>

/* Un albero binario di ricerca ha le seguenti proprietà:
 * - Il sottoalbero sinistro di un nodo x contiene soltanto i nodi con chiavi
 *   minori della chiave del nodo x
 * - Il sottoalbero destro di un nodo x contiene soltanto i nodi con chiavi
 *   maggiori della chiave del nodo x
 * - Il sottoalbero destro e il sottoalbero sinistro devono essere entrambi
 *   due alberi binari di ricerca. */

struct node
{
    int val;
    struct node *left, *right;
};

/* Add a new node, if root is NULL returns the new root
 * (the first inserted node) otherwise it just return the
 * root passed by the user in the input */
struct node *add(struct node *root, int val)
{
    struct node *saved_root = root;
    struct node *new = malloc(sizeof(*new));

    new->left = new->right = NULL;
    new->val = val;

    if (root == NULL)
        return new;

    while (1)
    {
        if (val > root->val)
        {
            if (root->right == NULL)
            {
                root->right = new;
                return saved_root;
            }
            root = root->right;
        }
        else
        {
            if (root->left == NULL)
            {
                root->left = new;
                return saved_root;
            }
            root = root->left;
        }
    }
}

void print_sorted(struct node *root)
{
    if (root == NULL)
        return;
    print_sorted(root->left);
    printf("%d\n", root->val);
    print_sorted(root->right);
}

void free_three(struct node *root) {
    if (root == NULL)
        return;
    free_three(root->left);
    free_three(root->right);
    free(root);

}

int main(void)
{
    struct node *root = NULL;

    root = add(root, 20);
    root = add(root, 10);
    root = add(root, 5);
    root = add(root, 20);
    root = add(root, 20);
    root = add(root, 100);
    root = add(root, 40);
    root = add(root, 33);

    print_sorted(root);

    free_three(root);

    return 0;
}