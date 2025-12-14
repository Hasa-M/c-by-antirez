Lesson 8 link: https://www.youtube.com/watch?v=c5atNuYdKK8&list=PLrEMgOSrS_3cFJpM2gdw8EGFyRBZOyAKY&index=9

Transcript:
La puntata di oggi sarà per molti versi  atipica rispetto alle lezioni del C fin qui,  
0:49
eh, presentate all'interno di questo corso. Sarà  diversa perché stavolta non introdurremo nuovi  
0:57
concetti, se non lo stretto indispensabile  affinché si possa scrivere il programma che  
1:07
scriverò con voi quest'oggi. Ma più che altro,  dobbiamo fare il tentativo di prendere l'insieme  
1:16
dei concetti espressi finora intorno al linguaggio  C e utilizzarli per scrivere un programma. Non  
1:23
un programma qualsiasi, ma il programma "The  Game of Life". Game of Life che noi, comunque,  
1:32
qua andiamo a mettere in inglese per avere  una qualità maggiore della voce di Wikipedia.
1:43
Game of Life, che è stato inventato negli anni '70  dal matematico John Conway, matematico inglese,  
1:55
e che ha delle semplicissime regole che però  generano dei risultati sorprendenti. Allora,  
2:06
sostanzialmente questo è un gioco, diciamo,  ma in realtà è un universo bidimensionale,  
2:15
come qua dicono, composto da celle. Possiamo  pensare a queste celle come a dei bit in una  
2:25
griglia bidimensionale, quindi X e Y,  un po' come lo schermo di un computer,  
2:31
sostanzialmente. E queste celle della griglia  possono essere vive (quindi nere e accese,  
2:39
allo stato uno) o morte (quindi possono  contenere invece una cella bianca, o zero).
2:50
Ogni dato stato della griglia di gioco,  eseguendo sempre le stesse semplicissime  
3:01
regole su ogni cella, dà vita al prossimo stato.  In particolare, se voi immaginate uno stato,  
3:10
ecco, come questo... questa è una simulazione.  Sì, esatto. Molto interessante. Rimettiamola  
3:18
all'inizio. Questo che cos'è? Ah, questo toglie o  reinserisce la griglia. Una cella viva (in questo  
3:29
caso bianca, qua i colori sono invertiti, però  in questo caso la cella viva è quella bianca;  
3:36
nel caso invece di questa GIF animata, le celle  vive sono nere) nella prossima iterazione, ok,  
3:48
che qua chiama "generazione", sarà sempre  viva se ha due o tre vicini vivi. Allora,  
4:01
quali sono le celle vicine a questa? Sono le otto  celle che costituiscono il suo intorno. E allora,  
4:10
aspetta, ve lo faccio vedere. "An average cell  interacts with its eight neighbors", quindi i suoi  
4:19
otto vicini, eccole qui: Nord-est, est, sud-est,  sud, sud-ovest, ovest, nord, nord-ovest...  
4:25
ci siamo capiti. Quindi se praticamente nella  generazione attuale la cella ha due o tre  
4:37
celle vive come vicini, allora sopravvive.  Per esempio, guardate questa cella qui: 1,  
4:45
2... delle otto vicine ha due celle vive e quindi  sopravviverà. Se invece... qua io posso togliere  
4:57
e mettere celle, ecco, vi faccio un esempio, per  esempio, molto tipico che è questo qua. Questo è  
5:03
un "più" che continuamente, diciamo, forma un più  perché c'è una linea che da orizzontale diventa  
5:09
verticale e così via. Vi faccio vedere perché.  Allora, dicevo, le regole sono: per esempio,  
5:15
questa cella qui non ha, tra i suoi vicini, due o  tre celle vive, ne ha solo una, questa qua tutta  
5:27
a destra, e quindi muore. Questa centrale invece  sopravvive perché ha due vicini vivi, così come  
5:35
quella a sinistra non sopravvive perché ha solo un  vicino vivo, che è questo centrale. Mentre invece  
5:41
si applica un criterio diverso per le celle morte.  Le celle morte diventano vive se hanno esattamente  
5:51
tre vicini vivi. Guardate, questa cella qua ha  tre vicini vivi? Sì, 1, 2, 3. Questa cella qua ha  
5:59
tre vicini vivi? 1, 2, 3. Quindi succede che nella  prossima iterazione le due celle estreme moriranno  
6:06
per sottopopolazione, perché ci sono meno di due  vicini. Allo stesso modo, se ha troppi vicini una  
6:15
cella muore per sovrappopolazione. Mentre invece  questa cella e questa cella vivranno perché hanno  
6:24
esattamente tre vicini attivi. Siccome poi  nello stato immediatamente successivo che   si genera si ha questa situazione contraria,  poi rivivranno quelle accanto orizzontali e  
6:35
quelle verticali moriranno, e quindi si crea di  continuo questa situazione alternante. Quindi  
6:43
questo è un gioco con delle regole molto  semplici che noi possiamo simulare in C.
6:48
Inoltre, perché riusciamo a simularlo? Perché  abbiamo visto in qualche lezione passata come si   fa a pulire lo schermo. Per simulare una griglia  possiamo utilizzare gli spazi e gli asterischi,  
7:00
o i puntini, affinché si vedano tutti gli spazi  della griglia, e gli asterischi o i diesis,  
7:08
i cancelletti o come volete chiamarli, per  fare invece le celle vive. E quindi abbiamo  
7:14
anche a disposizione un ambiente, chiamiamolo  grafico-testuale minimale, per riuscire a simulare  
7:21
questa situazione qua. Qual è la parte veramente  molto importante della lezione che faremo?  
7:30
Il modo in cui, e lo vedrete presto, scomporremo  il problema in funzioni C, e anche il modo in cui  
7:40
dobbiamo in qualche modo barcamenarci tra tutte le  cose che abbiamo fatto e che dovremmo utilizzare  
7:47
per scrivere un buon programma di Game of Life, ma  non abbiamo ancora studiato. E quindi utilizzeremo  
7:53
degli escamotage che però saranno istruttivi,  ma più che altro la scomposizione del problema  
7:59
in funzioni. Vi ricordo sempre, l'ho detto  altre volte, che in C è come se la prima  
8:05
parte del programma servisse a specializzare il  linguaggio per il problema che vogliamo risolvere,  
8:10
alzandoci di livello. Perché il C di solito è  molto a basso livello, noi scriviamo prima un  
8:16
primo set di funzioni che ci alzano di livello e  poi, con questo livello, a volte ne costruiamo un  
8:21
altro e un altro, e alla fine scriviamo la nostra  applicazione. Quindi è molto, diciamo, istruttivo  
8:29
da questo punto di vista. Una premessa importante:  io questo gioco non lo implemento forse da 20 anni  
8:37
e non ho fatto nessun tentativo di implementazione  prima di fare questo video, altrimenti avrei fatto  
8:45
una bellissima figura perché me lo sarei preparato  prima, ma questo video mancherebbe di ogni  
8:53
spontaneità di quello che è il processo di problem  solving, perché mi vedrete sicuramente sbagliare.  
9:01
Aiuta anche il fatto che sono particolarmente  stanco negli ultimi due giorni perché ho fatto  
9:06
un sacco di lavori di casa, ho fatto anche dei  lavori di profiling di Redis e questa notte un  
9:12
ospite del B&B mi ha svegliato alle 2:30.  Quindi per una serie di motivi mi vedrete  
9:18
approcciare questo problema senza che io abbia,  in questo momento, alcuna idea di cos'è che farò.
9:28
Andiamo dunque al nostro terminale. Chiamiamolo  life.c. `include `. E io direi che  
9:36
la prima cosa che ci serve... non  abbiamo le strutture, vi ricordo,  
9:42
non abbiamo fatto il `#define` del preprocessore.  Per esempio, io potrei scrivere `#define ROWS 50`,  
9:51
`#define COLS 50`, in base alla grandezza  che voglio che sia la mia scacchiera. Niente,  
9:59
useremo delle variabili globali. `int`. Facciamo  una cosa, visto che sono variabili globali,  
10:06
`COLS` lo scrivo maiuscolo. Questa dovrebbe  essere forse una proprietà della struttura  
10:11
che implementa la griglia, ma noi non abbiamo  fatto le strutture, quindi andremo semplicemente   a utilizzare le variabili intere e gli  array di numeri interi, nient'altro.  
10:22
Quindi `COLS` è uguale a, facciamo, non so, una  griglia 30x30 che ci dovrebbe andare abbastanza...  
10:33
Vediamo qua quanto siamo... qua `resize` non  c'è... vediamo a quanto... di quanto è grande  
10:39
'sto terminale. Ah, questo è 79x26. Allora,  facciamo 25x25. Quindi 25 nell'asse delle x,  
10:53
25 nell'asse delle y, e andiamo a  scrivere la nostra funzione `main`.
11:01
Allora, la prima cosa che noi vogliamo  fare è dichiarare un array che contenga  
11:06
tutte le nostre celle. Possiamo usare per questo  array semplicemente `char`, cioè il carattere,  
11:15
perché tanto noi utilizzeremo per dire, il  punto è... l'asterisco per le celle morte  
11:23
e per le celle vive. Quindi sono solo caratteri.  Quindi io lo chiamerò `grid`, chiamiamolo `grid`,  
11:35
`COLS * ROWS`. Esatto. La mia griglia sarà  grande 25x25. Ora a me serve una funzione  
11:47
per inizializzare questa griglia affinché sia  composta solo da celle morte all'inizio, e poi  
11:57
le celle vive che voglio settare. Quindi, tanto  per iniziare, allora, prima di tutto veramente,   mi serve ancora prima di far questo, mi serve  una funzione che dato un punto x, y... scusate,  
12:10
ho Telegram qua che mi balla, io lo chiudo  perché qualcuno mi scrive ma io me ne fotto.
12:19
Mi serve qualcosa come `set_grid` e `get_grid`  perché io devo poter dire, per esempio,  
12:25
"setta questa griglia a x, y a 'morto' o 'vivo'".  Allora, facciamo una cosa. Qua possiamo anche fare  
12:46
altre due variabili globali che chiamo `ALIVE` e  la setto a questo carattere, e `DEAD` e la setto  
13:02
a questo carattere. Ripeto, avrei dovuto scrivere  `#define ALIVE '*'` e `#define DEAD '.'`. Ma in  
13:16
realtà, guardate ragazzi, lo possiamo benissimo  fare. Facciamo, perché vi dico come funziona  
13:22
il `#define`. Se qua ci sarà scritto a un certo  punto `ALIVE`, il preprocessore del C sostituirà  
13:29
ad `ALIVE` quello che c'è qua a destra. Quindi  questo segno provoca una sostituzione testuale.   È troppo facile, non mi ricordo se già l'ho fatto.  Quindi `#define GRID_COLS 25`, `#define GRID_ROWS  
13:46
25`. Lo stesso, non è il massimo perché noi  dovremmo avere una struttura che cattura   queste proprietà, ma ce lo faremo bastare.  Quindi `char grid[GRID_COLS * GRID_ROWS];`.  
14:03
Andiamo a creare la nostra funzione `set_cell`.
14:10
`void` perché non ci ritorna nulla. `set_cell`.  Allora, qua dobbiamo necessariamente usare un  
14:19
puntatore, `char* grid`. Scusatemi di questo.  Sappiate solo che poi capiremo perché lo stiamo  
14:25
facendo nelle lezioni successive, ma non  abbiamo scampo per farvi capire quanto il  
14:30
C è profondamente interconnesso all'idea  degli indirizzi di memoria che si devono  
14:37
passare da una parte all'altra, cioè alcune  cose proprio non si possono fare altrimenti.   Quindi noi faremo `char* grid` col puntatore  e poi non vi preoccupate, perché dentro questa  
14:47
funzione possiamo sempre riferirci a `grid` con  un indice e leggerlo, scriverlo e fare quello che  
14:58
vogliamo. Quindi fregatevene. Questo è il modo  in cui noi passiamo questo array non per valore,  
15:03
ma per riferimento. Quindi se da questa funzione  noi chiamiamo `set_cell(grid, 10, 10, ALIVE)`,  
15:15
questo punto della griglia sarà settato ad  `ALIVE`, ma poi la funzione `main` continuerà a  
15:25
vedere questa modifica che `set_cell` ha operato,  perché `grid` viene passato per riferimento e  
15:32
quindi qualsiasi modifica viene fatta a `grid`,  io continuerò a vederla. Quindi io qua passo   l'indirizzo di memoria a `set_cell`. `int x,  int y, char state`. E il nuovo stato. Allora,  
15:47
abituiamoci anche a fare le cose bene: `// This  function sets the specified cell at x,y to the  
15:58
specified state`. Anche se questa funzione  è semplicissima, noi la commentiamo. Allora,  
16:04
vi voglio anche dire una cosa. Ora noi dobbiamo  andare a settare la cella della griglia che  
16:21
corrisponde a x, y, e dobbiamo risolverla e  farla diventare un punto lineare nel nostro  
16:28
array. Perché guardate, ammettiamo che io ho una  griglia 3x3. Gli indici del mio array in cui io  
16:37
registrerò la griglia saranno 0, 1, 2, 3, 4, 5,  6, 7 e 8. Ma a me l'utente mi sta passando x, y.  
16:47
Allora, questo è molto facile da calcolare, perché  io devo fare y per il numero di colonne che ho,  
16:54
quindi 3. Quindi se y è 0, io parto da qui; se  y è 1 voglio partire da qui, quindi aggiungo 3;  
17:03
se y è 2 aggiungo 6 e così via, più x,  che mi dà l'offset orizzontale. Quindi:
17:16
`grid[y * GRID_COLS + x] = state;`
17:29
Basta, la nostra funzione è tutta qua. Ma in  realtà non è così facile. Ora vedremo perché. Io  
17:40
direi che è molto utile se noi abbiamo la libertà  di poter specificare anche valori negativi, per  
17:47
esempio -1, e la nostra funzione automaticamente  riesce a capire che -1 vuol dire che deve partire  
17:55
dal lato destro, ok? Dalla fine della griglia,  in modo che la griglia, anche se è limitata,  
18:01
sia "infinita", perché è come se si toccasse da  una parte e dall'altra. Però prima scriviamo la  
18:08
nostra `get_cell`, che è la simmetrica di questa.  `char get_cell(char* grid, int x, int y)`.
18:18
`// This function returns  the state of the grid at x,y` 
18:24
`return grid[y * GRID_COLS + x];`
18:33
E qui mi ritorna lo stato della mia griglia in  quella specifica posizione. Facciamo una cosa: che  
18:42
ne dite se noi scriviamo una funzione che faccia  questo per noi, in modo che anche se andiamo in  
18:48
overflow... per esempio, la nostra griglia è di  25. Se io scrivo qua 20... se io voglio accedere   all'elemento x=25, che sarebbe in overflow perché  l'indice va da 0 a 24, io voglio che 25 diventi  
19:01
zero, che faccia "wrap around". Quindi proviamo  a scrivere una nostra funzione che faccia questa  
19:08
parte che c'è qua dentro, che converta x e y  nell'indice. Vediamo di inventare un nome decente  
19:15
per questa funzione. `cell_to_offset`.  Vabbè, ci sta bene. `(int x, int y)`.
19:29
`// This function translates the  specified x,y grid point into the  
19:41
offset (the index) in the linear array.` `// This function implements wrapping,  
19:54
so both negative and positive coordinates` `// that are out of the grid will wrap around.`
20:12
E vediamo questa roba qui com'è che la dobbiamo  fare. Allora, questa roba qui in realtà non è  
20:22
difficile da fare, e vi dico per quale motivo.  Iniziamo con il caso positivo. Ok? Quindi io devo,  
20:38
tanto per iniziare, scrivere: `if (x >= GRID_COLS)  x = x % GRID_COLS;`. Scusate... chi mi scrive...  
21:00
se non è importante, no? Mettiamo la vibrazione.  Allora, perché ho fatto così? Perché praticamente,  
21:13
che cos'è `%`? È l'operazione di modulo, quindi  è il resto della divisione tra `x` e `GRID_COLS`.  
21:23
Perché questa cosa qua funziona? Questa cosa  qui funziona perché, praticamente, ogni volta  
21:37
che io vado in overflow vorrei sottrarre 25 fino  a quando ho un numero inferiore a 25, per vedere  
21:44
di quanto sono andato oltre. E così implemento  il wrap-around in maniera corretta. Per esempio,  
21:49
vi faccio un esempio: se per caso io ho 25,  che è esattamente il primo che va in overflow,  
21:59
la divisione di 25 per 25 ha resto 0. Ok? Se  avessi 26, diventa 1, e così via. Quindi questa  
22:08
cosa l'ho risolta così. Stessa cosa qui:  `if (y >= GRID_ROWS) y = y % GRID_ROWS;`.
22:21
Andiamo ora al negativo. Quando io ho il numero  negativo, quello che vorrei fare in teoria è  
22:33
aggiungere `GRID_COLS` continuamente fino a  quando finalmente il numero diventa positivo.  
22:42
E a quel punto io praticamente ho risolto.  Perché immaginate se ho -1. -1 a che cos'è che  
22:48
corrisponderebbe? È il primo dall'altra parte,  quindi a 24. Quindi -1 + 25 fa esattamente 24,  
22:59
e sarebbe ok. Ma per riportare questa cosa negli  ordini della matematica intera positiva, io faccio  
23:11
una cosa: tanto per iniziare, trasformo...  Allora, immaginiamo di non avere l'overflow,  
23:30
quindi io potrei fare `x = GRID_COLS + x`.  Quindi immaginate che x sia -1, `GRID_COLS`  
23:47
è 25, più -1 andiamo a 24, che è proprio quello  che desideriamo. Però c'è un piccolo problema:  
23:59
se ho -26, questo gioco non funziona più. Quindi  io faccio una cosa: prima faccio `x = -x`,  
24:19
lo rendo positivo, `x = x % GRID_COLS`, quindi  lo normalizzo di nuovo, wrap-around, ok. Esatto.  
24:33
Ora però l'ho fatto tornare positivo e l'ho  normalizzato secondo la matematica dell'orologio,  
24:40
per capirci. E qui però scrivo `GRID_COLS  - x` perché da negativo che era l'ho fatto  
24:46
diventare positivo. Ok? Facciamo la stessa cosa  pure per `y`. `if (y < 0) { y = -y % GRID_ROWS;  
25:01
y = GRID_ROWS - y; }`. Però ci dobbiamo  rendere conto se questa cosa funziona. Allora,  
25:09
vi faccio un esempio, facciamo un esempio  proprio pratico. Mettiamo che x sia -28.  
26:10
Allora, -28. Io ho scritto prima `x = -x`,  quindi 28. `28 % 25` diventa 3. Poi faccio  
26:33
`25 - 3` e diventa 22. Vedete che funziona?  Almeno dovrebbe funzionare senza alcun problema.
26:41
Cancelliamo qui. Va bene. Ora che  abbiamo `cell_to_index`, guardate,   noi andiamo a sostituire qui `cell_to_index(x,  y)` e anche qua `cell_to_index(x, y)`. Magic!  
27:03
Cioè guardate, questa è proprio un'astrazione.  Questa è un'astrazione di più basso livello   che viene utilizzata da due astrazioni di  più alto livello, `set_cell` e `get_cell`,  
27:13
che però sono la stessa astrazione,  uno è un setter e uno è un getter. E  
27:19
ora la `main` può fare tutto quello  che vuole. Però vi dico la verità,   c'è un problema con tutto ciò. Noi prima  ci dobbiamo mettere nelle condizioni di  
27:26
osservare 'sta roba qui. Quindi a noi ci  serve una funzione che si chiama `print_grid`.
27:35
`void print_grid(char* grid) { ... }` `// This function shows the grid  
27:53
on the screen, clearing the terminal` `// using the required VT100 escape sequence.` 
28:17
`print_grid` utilizzerà ovviamente  `get_cell`, quindi è facile da scrivere. 
28:26
`for (int y = 0; y < GRID_ROWS; y++) { ... }` `for (int x = 0; x < GRID_COLS; x++) { ... }` 
28:45
`printf("%c", get_cell(grid, x, y));` Qua dopo che ho scritto la prima riga  
29:03
mi serve un new line, devo andare a  capo. Basta. E qui è fatta la funzione.
29:10
Mi serve pure `set_board`. `void set_board(char*  
29:23
grid, char state) { ... }` `// This function  
29:32
sets all the grid cells to the specified state.` Qua `state` avevamo fatto... abbiamo sbagliato,  
29:49
questo è `char` perché sempre  di caratteri si tratta. Ok.  
29:56
Copia-incolla selvaggio del ciclo for: `for (y...) for (x...) set_cell(grid,  
30:06
x, y, state);` Da notare che per non utilizzare puntatori,   `memset` e tutte le funzioni che avremmo dovuto  utilizzare se solo le avessimo già studiate,  
30:16
noi stiamo scrivendo un programma poco efficiente.  Ce ne freghiamo. Questo programma poco efficiente  
30:21
sarà comunque ordini di grandezza più veloce  dello stesso programma scritto in Python.
30:28
Allora, a questo punto guardate che  possiamo fare. Abbiamo la nostra   griglia. Bene. `set_board(grid,  DEAD)`. `print_grid(grid)`.  
30:54
`return 0;`. Mmh, abbiamo scritto un  programma. Vediamo quanti warning ci sono ora. 
31:02
... Ok, come  
33:19
vedete la nostra cella 10,10 è stata settata. Ora  andiamo a fare una cosa più interessante. Allora,  
33:26
noi ci mettiamo ora, quando abbiamo detto che  è 20x20, ci mettiamo a 19,10, quindi nel bordo,  
33:35
proprio al limite. Andiamo oltre, a 20...  pam, e passa dall'altra parte. Esatto. A 40,  
33:53
passa ancora dall'altra parte. -1, è proprio  nell'angolo al limite. -19... è giusto.  
34:23
-20, dovremmo essere proprio al  limite. -21 si torna dall'altra  
34:33
parte. Va bene? Sembra che le nostre  funzioni di base ci siano tutte.
34:42
A questo punto io farò una cosa. A me  non serve in realtà solo una griglia.  
34:48
A me serve `char old_grid[...]` e `char  new_grid[...]`. `GRID_COLS * GRID_ROWS`.  
35:01
Facciamo anche un'altra cosa qua, dopo che  abbiamo fatto `GRID_COLS` e `GRID_ROWS`.  
35:07
`#define GRID_CELLS (GRID_COLS * GRID_ROWS)`.  Vi faccio vedere una cosa: l'abbiamo messo tra  
35:19
parentesi perché così noi non abbiamo problemi con  la precedenza degli operatori, perché poi in base   a come usiamo questo `GRID_CELLS`, siccome viene  proprio spacchettato (una trasformazione di testo  
35:29
quello che fa il preprocessore), se poi ci sono  più, meno, diviso, per... non vogliamo problemi.  
35:35
Quindi mettiamo queste ulteriori parentesi e  siamo sicuri che questa è un'espressione a sé   che verrà valutata prima delle altre. Allora, è  leggermente più pulito. `old_grid`, `old_grid`,  
36:03
`old_grid`. Vabbè, variabile non utilizzata,  ce ne sbattiamo, funziona ancora tutto.
36:15
A questo punto facciamo la funzione che è  quella centrale: `compute_new_state`. La  
36:24
funzione `compute_new_state` prende la `old`,  prende anche un puntatore alla `new`. Quindi  
36:31
io qua ci terrò la versione vecchia e qua  avrò la mia nuova versione della griglia.  
36:42
Quindi `compute_new_state(char* old_grid, char*  new_grid)`. E basta, non mi serve nient'altro. 
36:51
`// This function computes the new state of  the Game of Life according to its rules.`
37:03
Allora, una figata che può sembrare  una stupidaggine, ma è importantissimo,  
37:09
è che... prendete qui, ricarichiamo 'sta  pagina. Questo è un glider, guardate,  
37:19
lo vedete qui? Praticamente le cose vanno  a morire quando finiscono nei bordi dello  
37:24
schermo. Dovrebbero invece continuare dall'altra  parte, e il nostro gioco dovrebbe funzionare  
37:30
in questo modo. Qua invece tutto va a morire.  Per esempio, c'è un glider che è molto, molto  
37:42
utilizzato e semplice... questo coso funziona  veramente male, l'offset è sfanculatissimo.  
37:51
Dovrebbe essere questo, se non mi sbaglio. Esatto.  Guardate, questo è un glider, cammina sempre.  
37:59
Ora io mi aspetto che 'sta roba quando arriva  qua all'angolo dello schermo passi dall'altra  
38:05
parte. Invece no. Qui la nostra logica...  ah, qui hanno fatto proprio una griglia  
38:12
infinita. In realtà è molto più figo, però  diciamo, devi seguirlo. Noi invece vogliamo  
38:17
che da solo passi dall'altra parte. Dovrebbe  funzionare in teoria così il nostro programma.
38:25
Tra l'altro, per avere... `print_grid`  noi ce l'abbiamo, solo che non abbiamo  
38:34
fatto la cancellazione. `clear; xxd -c ...`  vediamo quali sono le sequenze di escape.  
38:42
Me le copio brutalmente da qua. L'escape è  `\x1b`. Quindi `printf("\x1b[2J\x1b[H");`.  
39:09
Vediamo se funziona. Sì, vedete, ora  cancella lo schermo e poi stampa. Va bene.
39:28
Allora, `compute_new_state`. Che dobbiamo fare?  Noi per ogni cella... Ah, ma ora noi facciamo  
39:34
una cosa fighissima. Guardate. A noi serve  ogni volta sapere quanti vicini 'sto coso ha,  
39:41
quanti sono vivi. Quindi noi facciamo  `int count_living_neighbors(char* grid,  
39:53
int x, int y)`. Quindi, dato un x, y, mi  conti per piacere quanti vicini vivi ho. 
40:02
`// This function returns the  number of living neighbors of x,y.` 
40:21
E qua guardate che facciamo. `int alive_count  = 0; for (int y_offset = -1; y_offset <= 1;  
41:25
y_offset++) { for (int x_offset = -1;  x_offset <= 1; x_offset++) { ... } }`.  
42:43
Solo che noi vogliamo che `if (x_offset == 0 &&  y_offset == 0)` questo ciclo lo voglio saltare,  
43:22
perché io non voglio vedere se è viva  la cella stessa che io specifico,   ma solo quelle attorno, gli otto vicini. E  qua in realtà è `get_cell(grid, x + x_offset,  
43:37
y + y_offset)`. `if (get_cell(...) == ALIVE)  alive_count++;`. E `return alive_count`. Guardate,  
43:50
grazie al fatto che noi qui abbiamo  gestito 'sta roba, il wrapping,   qui non è che ci dobbiamo preoccupare che  siamo al bordo della cella, "allora che  
43:58
succede?". No. Perché le nostre astrazioni sono  state costruite in maniera robusta all'inizio e  
44:05
praticamente viviamo, si può dire, di rendita.  `count_living_neighbors`. Vediamo se funziona. 
44:16
... Sembra funzionare, vedremo.
46:13
Allora, `compute_new_state`. A questo punto  facciamo una cosa. Guardate qua. Facciamo,   sapete quel "più" che abbiamo visto che  alterna? E qua c'abbiamo 'sto trattino che  
46:24
poi doveva diventare quello orizzontale. Allora,  `compute_new_state`. Qua andiamo a fare la stessa  
46:32
storia dello stesso `for` loop. Allora, che cos'è  che decreterà lo stato nuovo in `new_grid`? Tanto  
46:50
per iniziare prendiamo i vicini: `int n_alive =  count_living_neighbors(old_grid, x, y);`. Ora,  
47:14
`if (get_cell(old_grid, x, y) == ALIVE) { ... }  else { ... }`. Quindi se è viva... qua chiamiamo  
47:40
`new_state_value`. Se era viva, `new_state_value`  è... ora qui bisognerebbe usare l'operatore  
47:54
ternario, ma noi non l'abbiamo fatto, quindi  dobbiamo scrivere codice un po' meno elegante,   meno succinto, ma pazienza. `if (n_alive == 2  || n_alive == 3) new_state_value = ALIVE; else  
48:21
new_state_value = DEAD;`. Se invece è morta,  allora facciamo una cosa. Guardate, noi partiamo  
48:35
dal dare il `new_state_value` come morto, così non  dobbiamo scrivere l'altro caso ogni volta. `char  
48:43
new_state_value = DEAD;`. Lo trasformiamo in vivo  se effettivamente abbiamo la condizione. Invece  
48:51
se per caso la cella è morta, solo se ha `n_alive  == 3`, `new_state_value = ALIVE;`. Una volta fatto  
49:04
ciò noi dobbiamo scrivere `set_cell(new_grid,  x, y, new_state_value)`. Ci dovremmo essere.
49:25
Quindi facciamo qui: `compute_new_state(old_grid,  new_grid)` e ci facciamo stampare la `new_grid`.  
49:43
Compiliamo. Oh, guardate, sono diventati  verticali. Facciamolo di nuovo. Ci facciamo  
49:54
computare dalla `new` alla `old` perché ora sono  invertiti, e ci facciamo stampare la `old_grid`.  
50:07
Esatto. In sostanza, sembra proprio che  il nostro programma stia funzionando.
50:13
A questo punto io credo che siamo andati ben oltre  la lunghezza massima che ci eravamo dati e quindi  
50:23
non riusciremo a vedere forse il glider che va  o in generale questa animazione che funziona.  
50:30
Io invece direi che ormai mancano due righe  precise. Quindi io includo `` perché mi  
50:41
serve `sleep` per dormire. `while (1)`, quindi il  ciclo che dura per sempre: computo lo stato nuovo,  
50:51
stampo la griglia, `sleep(1)`. Computo lo stato  nuovo, stampo la griglia, `sleep(1)`. Compiliamo.
51:01
Esatto, guardate. Ting, ting. Facciamo il nostro  glider, quello lì figo. Allora, 10,10, poi 9,10,  
51:14
11,10 e ho fatto una linea orizzontale.  Poi questo glider qui ce ne ha uno a  
51:23
11,9 e uno a 10,8. Vediamo se ci ho beccato.  Esatto! Guardate come si muove. Che figata.  
51:45
Tuttavia, siccome non vogliamo  diventare vecchi... `sleep`...  
51:57
dormiamo meno. Vediamo se funziona il  wrap-around. Oh, magic! Fantastico.
52:09
Allora ragazzi, grazie al fatto  che abbiamo scritto 'sto semplice   programmino... ora facciamo una cosa,  va. `cat life.c | pbcopy`. `github.com`.  
52:30
"Game of Life C implementation". `// Warning: This program is "odd"  
52:58
C because it is an example` `// using just a subset of  
53:07
things learned by my students` `// so far on my YouTube channel.` 
53:22
Vabbè, la URL di 'sta roba qui poi io la  metterò... Vabbè, ma credo che... a parte  
53:29
che lo trovate tra le mie cose di GitHub,  nei miei Gist, ma io comunque metterò,  
53:40
credo, la URL se me lo ricordo. Spero  proprio di sì. Bene, alla prossima allora.

Notes:
