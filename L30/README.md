Lesson 30 - Link: https://www.youtube.com/watch?v=D1U3uCe-kok&list=PLrEMgOSrS_3cFJpM2gdw8EGFyRBZOyAKY&index=35

Lesson 30 - Transcript:
0:40
Benvenuti amici al corso di programmazione  in C. Vedo un po' che queste lezioni mancano  
0:46
da questo canale perché le vacanze di  Natale hanno in effetti desincronizzato  
0:53
la mia routine ed è stato un po'  difficile farle in questi giorni.  
0:58
Ora che siamo al 9 gennaio, siamo  tornati, è il tempo di riprendere. Tuttavia questa sarà una lezione strana, tanto per  iniziare perché il corso sarebbe dovuto continuare  
1:10
naturalmente con la conclusione della scrittura  dell'interprete Forth, ma come ho preannunciato  
1:17
la scrittura dell'interprete Forth è diventata  un po' troppo lunga e la popolazione generale di  
1:24
questo corso potrebbe effettivamente arenarsi un  po' troppo su quei concetti. Quindi ho deciso di  
1:33
fare un'unica puntata molto lunga in cui lo finirò  sostanzialmente tutto dall'inizio alla fine. Devo  
1:40
trovare il tempo, in questa settimana o nella  prossima, perché credo che prenderà anche 2-3  
1:49
ore di lezione continua in cui farò delle  pause, quindi devo allocare questo tempo.
1:56
Ma la cosa interessante, anche diversa,  spero stimolante di questa puntata è  
2:03
quella che più di parlare del C in sé,  in realtà vedremo C, modificheremo C,  
2:09
partiremo da un programma che ho scritto  nel 2024. Mostreremo anche perché il C,  
2:19
perché a volte è un linguaggio così brutalmente  abile a manipolare i bit, è così brutalmente  
2:26
veloce, può essere particolarmente  utile per risolvere certi problemi.
2:31
Tanto per iniziare vi faccio vedere che cos'è  questo programma. Non l'ho mai rilasciato,   lo rilascerò nel corso di questa lezione. Alla  fine di questa puntata, io farò un push su GitHub,  
2:44
quindi alla fine della lezione lo troverete  sostanzialmente online. Potete scaricarlo e  
2:50
potete continuare a modificarlo. Prima  continuerò a modificare questi commit.  
2:57
Diciamo che già avevo fatto alcuni commit nei  giorni, negli anni successivi. Qua c'è un mix  
3:04
di cose fatte, appunto, quando avevo intenzione  di fare questa puntata il 30 dicembre e poi non  
3:10
sono riuscito a farla, e invece gli altri commit  2024. Solo questo ha un refactoring minore che  
3:19
serve appunto a dare chiarezza al codice  sorgente affinché chi segue questo corso  
3:24
possa capire meglio. E ho modificato un po'  l'algoritmo, ma poi di questo ve ne parlo.
3:31
Allora, che cos'è questo programma? Il 2024  è stato un periodo in cui ho smanettato molto  
3:42
con lo ZX Spectrum. Avevo fatto delle cose  anche negli anni passati e avevo voglia di  
3:48
creare delle schermate caricabili dallo ZX  Spectrum reale, perché io c'ho l'hardware  
3:54
fisico lì con la televisione, diciamo, CRT.  Nei giochi dello Spectrum molto spesso,  
4:02
nonostante le capacità grafiche dinamiche,  quindi durante il movimento del gioco, durante  
4:08
il gameplay dello Spectrum fossero profondamente  limitate, questo computer di 40 anni fa, che è,  
4:15
ve lo faccio vedere, stiamo parlando di  questo computer qua. Questa è una scheda,  
4:28
una porta che permette di attaccare il  joystick. Di default non si può neanche   attaccare il joystick. Se io lo stacco,  lo vedete, guardate, questa è la mia mano.  
4:40
È veramente piccolissimo. È grande quanto  l'estensione della mia mano. Ecco qui.
4:49
Quindi questo computer di 40 anni fa, molto  spesso nei giochi c'era una grafica piuttosto  
4:55
spettacolare di apertura e poi seguiva un gameplay  più povero, però nelle fasi di apertura era capace  
5:04
di mostrare effettivamente delle cose abbastanza  interessanti. Vi faccio vedere. ZX Spectrum screen  
5:13
Game. Vediamo se troviamo qualcosa. Ecco,  guardate, sono interessanti queste grafiche.  
5:22
Ecco, per esempio, Jetpac, uno dei miei giochi in  assoluto preferiti, perché aveva questi colori,  
5:28
diciamo, particolarmente vivaci, quando  a volte potevano essere anche, diciamo,   un po' così cacofonici, brutti da vedere,  poi, ripeto, specialmente nel gameplay,  
5:38
però gli artisti di queste copertine a volte  riuscivano a fare effettivamente un bel lavoro.
5:46
Potete vedere qui da subito che c'è una  separazione netta tra i colori verticale,  
5:52
perché purtroppo gli attributi del colore  si possono dare soltanto a blocchi 8x8. Ogni   blocco 8x8 può avere un determinato sfondo  e un determinato colore invece dei pixel,  
6:04
quindi può avere solo due colori e valgono  per tutti i 64 pixel della griglia 8x8.  
6:10
Queste limitazioni sono simili magari ad altre  modalità di altri computer che hanno una grafica   molto migliore, come per esempio il Commodore 64.  Però altri computer hanno gli sprite e gli sprite  
6:21
quando si sovrappongono allo sfondo non hanno  di queste limitazioni e possono avere, diciamo,  
6:27
un background trasparente e sotto si vede la  grafica senza avere questo limite dei blocchi 8x8.
6:35
Prima vi faccio vedere effettivamente che cos'è  che fa questo programma ZXfy. Sostanzialmente  
6:48
io do una PNG, per esempio, do questa PNG  che è questa l'immagine della ragazza con  
6:55
l'orecchino di perla. Ah, qua c'era pure Lenna.  Vi farò vedere Lenna, che è un'immagine che si  
7:03
usa tradizionalmente nella ricerca della computer  graphics. Questa immagine qui l'ho modificata un  
7:16
po' per saturarne i colori in maniera più estrema  per avere risultati migliori. Dovrebbe essere in  
7:24
realtà parte del programma questa capacità, ma per  ora noi ce ne freghiamo e semplicemente avviamo  
7:32
il nostro programma dando come input la nostra  immagine. L'immagine che vogliamo sia trasformata  
7:42
in un formato caricabile dallo ZX Spectrum  con tutti i limiti dello ZX Spectrum. Quindi,  
7:51
deve essere un'immagine che effettivamente  l'hardware è capace di visualizzare. Avvio questo programma e vedrete subito  che la prima cosa che accade è che si vede  
8:02
sostanzialmente un rumore di pixel che sono stati  settati casualmente a 0 o a 1. All'inizio non c'è  
8:12
alcun colore e poi piano piano emerge l'immagine  della ragazza con l'orecchino di perla. Qui si  
8:23
possono vedere le generazioni. La differenza tra  l'immagine originale e quella che noi finora siamo  
8:31
riusciti a generare è questo parametro che si  chiama temperatura, che vedremo che cos'è. Allora,  
8:37
questo programma non calcola, non ha dentro  alcun algoritmo di dithering. Questa immagine  
8:43
che vedete emerge sostanzialmente in maniera,  come dire, evolutiva. Usa un algoritmo evolutivo.
8:58
Ah, guardate che succede. Dopo praticamente  che viene creato un abbozzo dei pixel in  
9:04
bianco e nero, c'è una fase in cui poi  l'immagine inizia ad essere colorata.  
9:09
Il fatto di fare prima un compito, diciamo, più  selettivo e poi svolgerne un altro e così via...  
9:18
Ora ve lo farò vedere dentro il codice sorgente.  Si chiama in gergo "Curriculum Learning",  
9:26
solitamente si chiama, sia nelle reti  neurali che negli altri algoritmi. Vuol  
9:32
dire che sostanzialmente fare tutte le cose  assieme creerebbe un risultato inferiore,  
9:37
invece fare queste cose step by step... Ora  per esempio abbiamo modificato solo i colori,   a un certo punto l'algoritmo entrerà in una fase  in cui modificherà invece sia i pixel che i colori  
9:48
e così via. Non ci saranno più alcune regole che  impongono ora necessariamente un colore di sfondo  
9:53
e quello di foreground, diciamo, di quello in  primo piano, che debbano essere per forza diversi.
10:00
Ecco, già siamo entrati in questa fase. Guardate  come ora i blocchi, quando possono essere neri,  
10:06
sia i pixel che lo sfondo, viene utilizzato un  blocco nero e si tolgono queste imperfezioni  
10:11
e ora migliorerà ancora di più. Ma andiamo a  vedere il codice sorgente di questo programma  
10:17
che è piuttosto semplice. Allora, vabbè, qua  copyright 2008-2024 in realtà, perché siamo 2026,  
10:30
ho copiato i sorgenti di un altro programma  che si chiama Shape Me che è pubblicato,  
10:36
che fa una cosa, diciamo, non  simile, veramente molto lontana,   ma dovevo copiarmi giusto le chiamate SDL e quelle  delle librerie PNG, che hanno due API atroci,  
10:47
come molte librerie purtroppo. E vi faccio  vedere proprio come funziona questo programma.
10:56
Allora, dicevo, l'algoritmo che viene  utilizzato fa parte di una famiglia di  
11:02
algoritmi che si chiamano algoritmi evolutivi.  Credo che sia la traduzione italiana corretta.  
11:14
Non vi faccio vedere la pagina Wikipedia  italiana perché è sbagliata, l'ho letta,  
11:20
ci sono diversi errori che ho riconosciuto, sono  andato nella pagina, diciamo, inglese. Ed è una  
11:28
famiglia di algoritmi. Gli algoritmi più famosi  sono i genetic algorithms. La programmazione  
11:37
genetica è anche molto interessante. Il genetic  programming è una cosa che ho esplorato molto  
11:43
quando avevo 26-27 anni, qualche giorno magari  ve ne parlerò, ma quello che stiamo usando qui  
11:51
è il Simulated Annealing, che probabilmente  non troveremo. Io credo, esatto. Il Simulated  
11:59
Annealing secondo me non viene teoricamente  classificato negli algoritmi evolutivi. È una  
12:06
classificazione, diciamo, a parte, il fatto  che ognuno lo classifica un po' come vuole,   ma secondo me ci entra di fatto quello che noi  stiamo utilizzando, perché anche se non c'è,  
12:17
non ci sono soluzioni che competono e non c'è  crossover e se ne prende parte di una e parte  
12:22
dell'altra, in realtà è un algoritmo che simula  comunque, diciamo, delle tecniche dell'evoluzione  
12:29
biologica, ma utilizzando soltanto le mutazioni  senza alcuna riproduzione tra diversi individui  
12:39
che rappresentano diverse soluzioni al  nostro problema. Tutti questi problemi   sono comunque algoritmi di ottimizzazione.  Quindi io voglio trovare un set di parametri,  
12:49
cioè in questo caso i pixel e gli attributi  colore che soddisfano una data condizione.
12:55
Allora, qua guardate che faccio. Io dico tanto per  iniziare qual è la memoria video dello ZX Spectrum  
13:01
che è composta di questa quantità di byte.  Definisco quali sono i colori che lo Spectrum  
13:08
ha a disposizione in RGB. Questi sono numeri 32  bit. In realtà noi ne usiamo di bit soltanto 24.  
13:20
Aspettate, RGB, non so se li ho detti nell'ordine  giusto. No, quindi è RGB, sono fatti al contrario.
13:27
Allora, queste sono le chiamate che servono  per creare questa finestra qui, questa piccola  
13:33
finestra qui. Guardate, già il nostro algoritmo  è riuscito a convergere verso quella che è   sostanzialmente la migliore soluzione. Possiamo  andarla a guardare qui. La differenza ormai è  
13:44
soltanto il 6,23% con l'immagine originale.  Ha provato la bellezza di 1.328.000 soluzioni  
13:56
ed è arrivata a questa qua che è abbastanza  interessante. Se voi immaginate questa immagine  
14:02
qui caricata in uno ZX Spectrum, in un CRT dove  tra l'altro il dithering farebbe un effetto molto  
14:09
più figo perché i fosfori si mischiano e così via,  sarebbe credo abbastanza impressionante da vedere.
14:18
Allora, qua ci sono le chiamate della libreria  SDL. La libreria SDL è una libreria per fare   grafica e suono di base, non fa delle cose molto  evolute, ma ti permette di aprire una finestra,  
14:32
di configurare se sia o meno full screen, di  configurare il colore se è RGB. Ecco, guardate  
14:42
qua: SDL pixel format RGB 24, quindi, diciamo,  è lo stesso formato poi dei byte che ho qui,  
14:55
ma questa qui è molto poco interessante.  Allora, guardate, si crea una Window,   si crea un Renderer, si crea una Texture. Queste  chiamate poi si... una prende quello che ti ha  
15:06
restituito l'altro. Guardate qui, lo screen  lo ottengo con create window e ho una finestra  
15:13
con posizione non definita e una data  larghezza e altezza. Poi creo un renderer  
15:20
utilizzando questo screen, infatti lo passo  come primo argomento e poi da questo renderer  
15:26
faccio una texture e poi finalmente posso  sostanzialmente ritornare la texture del  
15:32
renderer che utilizzerò per scrivere nella  mia finestra, come lo vedremo fra poco. Ecco, questa funzione qui è brevissima.  
15:40
Io gli passo la texture e il render che mi  hanno ritornato le chiamate della libreria SDL,  
15:47
poi gli passo un buffer che rappresenta...  un buffer di caratteri, di byte. Guardate,  
15:52
questo è un puntatore FB, frame buffer, che  rappresenta RGB RGB RGB con larghezza e altezza  
16:00
della mia immagine da renderizzare. Addirittura  height neanche la utilizza. E vi dico perché:  
16:12
perché qui serve soltanto dare la width * 3, che  è la grandezza di ogni riga, ok? E poi lo sa lui  
16:25
quando è grande la finestra e quindi leggerà i  dati per quel che serve. Poi pulisco il renderer,  
16:33
copio la texture nel renderer e poi praticamente  lo presento nella finestra attuale. Quindi  
16:44
praticamente sono delle chiamate, diciamo,  abbastanza semplici che possiamo liquidare così,   così come liquideremo il processing di eventi  che permette di sentire se premo un tasto o ne  
16:55
premo un altro. Questo non è... questa lezione  non è incentrata su SDL, quindi ce ne freghiamo.
17:00
Questa è una funzione che credo non  sia usata nel programma, no? Ma io la   vorrei usare in realtà. Vedremo se riusciremo  a utilizzarla. E questa è un'immagine a cui...  
17:13
è una funzione a cui si passano proprio questi  row pointers come un'immagine RGB e lui scrive,  
17:23
questa funzione scrive un file PNG. Non  mi ricordo il formato di PNG byte pointer,  
17:28
ma credo che sia un puntatore a byte banalissimo.  Fatemi vedere qui com'è usata. Row pointers a chi  
17:36
viene passata? Write image. Credo proprio di  sì. Guardate, per scrivere una Jpeg ci sono un  
17:44
sacco di porcate. Queste sono librerie  vecchie, non mi piace come ho scritto,   addirittura con setjmp per la gestione degli  errori. Sono pessimi esempi di programmazione,  
17:54
ma ovviamente non mi vado a scrivere  la libreria. Ecco, questa la useremo. Invece a questa funzione gli diamo un puntatore,  un file. Vi ricordate che noi con fopen potevamo  
18:09
aprire appunto i file e poi abbiamo questo  puntatore a cui poi la libreria standard  
18:15
input output può accedere e PNG prende appunto  questo FP. Ah no, io proprio sono io che leggo,  
18:26
lo avevo fatto io che leggo il buffer, eccetera  eccetera. No, forse poi però in realtà sì.  
18:33
Per ora qua cerco solo di vedere se il Magic, se  i primi byte con cui inizia la PNG siano quelli  
18:43
corretti. Read structure, initialize structure, ah  PNG init io. E ci passo gli passo il file pointer.  
18:57
Quindi la libreria PNG ha automaticamente  la capacità, appunto, di attaccarsi al file   pointer di un file aperto, quindi al descrittore  di un file aperto e inizia a leggere l'immagine.  
19:08
Comunque quello che importa è che quando  io praticamente ho letto questa immagine,   quello che faccio è poi di scrivere questa  immagine nella mia memoria, nel mio buffer.
19:22
Allora, guardate, questa funzione ritorna  sostanzialmente un puntatore di byte,  
19:30
quindi un puntatore a carattere, quindi a un  intero senza segno di 8 bit, quindi sono dei  
19:37
byte semplicemente che noi allo... in questa  funzione e restituiamo poi all'utente. Scusate,  
19:45
siccome cambio dal portatile Linux che mi  sono comprato a questo, invece di premere  
19:52
Ctrl premo function perché i tasti sono in  posizione un po' diversa dall'altra parte,   questo context switching mi crea questo problema.
20:01
Dicevo, siccome a volte in alcuni casi le immagini  sono registrate RGB, in alcuni casi BGR, allora  
20:08
qui faccio una conversione per avere quello che mi  serve a me e se per caso c'è il canale alfa della  
20:14
trasparenza lo salto, quindi poi ritorno. Guardate  RGB, vi faccio vedere anche RGB dov'è che l'avevo  
20:22
allocato qua. RGB uguale malloc row bytes per...  quindi la i byte che ci sono in ogni row, quindi  
20:29
in una singola riga della mia immagine. In questo  caso sarà risoluzione in x * 3 RGB per l'altezza  
20:40
dell'immagine, così ho un buffer sufficiente  ad accomodare tutta l'immagine. Qua in teoria  
20:47
ti dovrebbe dare errore se non è della dimensione  giusta. Credo che me ne sono addirittura fregato.  
20:52
Ah no, forse poi quando PNG load. Esatto.  Se la width non è 256 e l'altezza non è 192,  
20:59
"The image must match exactly ZX Spectrum  resolution". Quindi questa cosa c'era qua.
21:06
Quindi dicevo, una volta che carico l'immagine e  la ritorno, poi ho questa funzione che calcola la  
21:17
differenza tra un'immagine A e un'immagine B, dove  l'immagine A è l'immagine che in quel momento c'è  
21:26
nella memoria video dello Spectrum e l'immagine B  è la mia immagine target, quella a cui io voglio  
21:33
arrivare ed è quella che ho caricato dal file.  E questa differenza viene ritornata come long.  
21:44
Vediamo perché viene ritornata come long, perché  non me lo ricordo. Torniamo qui. Compute... Ah,  
21:52
ok. Ok. Allora, io qua faccio una cosa, sto  semplicemente ritornando la distanza come la  
22:07
somma di tutte le distanze dei pixel dell'immagine  A con l'immagine in B. Ora vi dico in che modo è  
22:17
che funziona questa funzione qua. Allora, per  ogni pixel dell'immagine, quindi per y da 0  
22:24
all'altezza -1 e per x da 0 alla larghezza -1,  mi prendo la differenza di R, G e B. Per ora  
22:35
ignorate queste righe che ci sono sotto. Ora ve  le spiego. Quindi la differenza di R, G e B, ok?  
22:45
Questa differenza perché la elevo al  quadrato e le sommo? Considerate che  
23:05
quando io elevo al quadrato, se per caso  questa era negativa, non è un problema,   perché -5 * -5 fa 25 come 5 * 5. Quindi ecco, non  vi meravigliate se qui manca il valore assoluto.
23:16
Questa funzione prova ad essere, diciamo,  relativamente veloce. In sostanza io sto   facendo la formula della distanza nello spazio  3D. Quindi io faccio finta che questi pixel,  
23:25
il pixel 1 dell'immagine A e  il pixel 1 dell'immagine B,  
23:31
faccio finta che questo RGB siano coordinate  nello spazio e guardo quanto distanti sono, ok?  
23:38
E poi io sommo tutte queste distanze e questa  `computeDiff` ritorna appunto la somma di tutte  
23:46
queste distanze. Maggiore sarà la distanza, il  numero long che mi ritorna questo computeDiff...  
23:52
essa è effettivamente la mia immagine. Ma  guardate, per capirci, poi questo computeDiff,  
23:58
io faccio una cosa: per avere la percentuale di  differenza, io faccio che questa differenza la  
24:07
divido per la massima differenza possibile,  ovvero se ogni pixel tra di esso avesse la  
24:15
differenza massima di 442 e 442. Dovrebbe  essere Python... math.sqrt... esatto. Allora,  
24:42
255*255 + 255*255 + 255*255. Esattamente. Guardate  quanto fa. 441. Quindi la distanza massima tra  
24:56
000 e 255 255 255. Quindi i pixel più estremi  hanno come distanza 441. E vabbè, io ho messo  
25:08
441 virgola qualcosa, ho messo 442 e poi quindi  avrei un numero, dividendo questa differenza per  
25:15
la differenza massima tra 0 a 1 e lo moltiplico  per 100 per avere una differenza da 0 a 100.
25:22
Quindi credo che questa cosa è chiara.  Quindi allora capiamoci. Io per ora c'ho  
25:28
una roba che mi carica in un frame buffer  l'immagine target. C'è una cosa che sa fare  
25:34
la differenza tra questa immagine target  e l'immagine che ho io in questo momento   nella memoria dello Spectrum. Come la creo  l'immagine che ho nella memoria dello Spectrum?  
25:43
Guardate, questo è proprio l'algoritmo che usa  lo ZX Spectrum, la sua ULA, per trasformare  
25:50
l'immagine nella RAM video nell'immagine che  viene visualizzata. Perché com'è encodata  
25:58
questa immagine nella RAM video? Qua ormai  siamo alla soluzione definitiva, lo possiamo  
26:03
anche quittare. Questa è la mappa, la memoria  dello ZX Spectrum. Screen memory. Guardate,  
26:12
da 4000 esadecimale a 57FF ci sono i pixel 0  e 1. Quindi ci sono 256*192, scusate, pixel.  
26:30
E poi qua ci sono tutti i byte che servono, che  saranno allora 256 * 192. Sono questi pixel qua,  
26:42
diviso 8*8. Esatto. Deve fare esattamente 768.  Io c'ho 768 blocchi 8x8 di 64 pixel ognuno,  
26:55
quindi c'ho 768 byte di attributo colore e vi  faccio vedere questo attributo colore com'è.
27:02
Ah, questa è un'immagine, per esempio, che viene  visualizzata se io setto tutta la RAM video  
27:08
a una cosa casuale, perché ci saranno blocchi di  colore casuale. A volte ci sarà l'attributo blink,  
27:15
a volte no, a volte ci sarà l'attributo colori ad  alto contrasto, a volte no. E questo è il modo in  
27:23
cui funziona. Quindi io c'ho questi... quando  abbiamo detto che sono 768? Non c'è scritto da  
27:29
nessuna parte qui. 768, no? Ah, sì, guardate  qui. 768 blocchi, 32 row per 24 colonne,  
27:39
righe per colonne e guardate, ogni byte  degli attributi video è fatto così. F B  
27:46
PPP I I I. PPP è il colore della paper, quindi il  background. I I I sarebbe ink, quindi il colore  
27:57
dei pixel accesi, dei pixel settati a uno nel  resto della memoria video dove c'è la bitmap.
28:07
Sarebbe... dovrebbe essere, aspettate che guardo  qui. Flash. Esatto. Io cercavo blink e dicevo  
28:20
perché B? F flash e B è bright se deve essere ad  alta luminosità. Noi flash non lo utilizziamo in  
28:28
nessun modo, lo ignoriamo completamente perché non  vogliamo che flashi un bel niente, vogliamo che  
28:35
l'immagine sia statica. Allora, noi utilizziamo  esattamente la funzione che trasforma esattamente  
28:50
`zx2rgb`, quindi dalla memoria dello ZX Spectrum.  Qua guardate questa funzione prende un puntatore  
28:56
al frame buffer dove scriverà l'immagine che  viene rappresentata in questo momento dalla   memoria video del computer e un puntatore alla  memoria video del computer e traduce. Ovviamente,  
29:06
siccome sono encodate strane, le cose  non sono neanche sequenziali queste   bitmap nella RAM video perché c'erano dei vantaggi  hardware a farle in un determinato modo per il  
29:18
modo in cui poi la ULA accede alla RAM mentre fa  il refresh video. Un casino bestiale. Quindi si  
29:25
devono fare tutte queste operazioni di flipping  dei bit vari. Ma questo ve lo potete andare a  
29:30
guardare, se volete, nelle informazioni  che ci sono in rete sullo ZX Spectrum.
29:36
Vabbè, qua in realtà, ecco, questo qui non sarebbe  neanche necessario, credo, perché questo codice io  
29:43
l'ho preso dall'emulatore dello ZX Spectrum che  ho scritto per il ZX20 e ci sono delle cose che  
29:50
sono probabilmente ridondanti. Però a questo  punto vorrei capire... Ah, ecco. Ok. Allora,  
30:02
se praticamente c'è l'attributo blink, io devo  prendere il foreground e il background invertiti.  
30:08
In questo modo, così inverto le variabili qua e  poi praticamente tutto il resto non è un problema.  
30:14
Credo che queste righe qui dovrebbero essere  perfettamente inutili: `Blink uguale a 0`. Eh no,  
30:33
qua non avevamo avviato mai il programma. Qui sì,  avviamolo e vediamo noi mentre comunque ragioniamo  
30:42
sulle nostre cose, questo lo mettiamo qua e noi  ce ne torniamo qui a guardare il nostro programma.
30:49
Allora, quindi dopo che ho ottenuto il colore dei  pixel settati a uno e il colore dei pixel settati  
30:56
a 0, poi decido se praticamente è bright. Se  per caso è bright io devo cambiare il colore  
31:10
del foreground e del background. Allora, in  questo momento io questi colori qui li sto  
31:17
ottenendo non come colori RGB, ma come indice di  colore dello Spectrum, quindi 0 1 2 3 eccetera  
31:26
eccetera fino a quant'è? Sono 16, no? Esatto. A  questo punto io c'ho i colori di tutti gli 8 pixel  
31:46
di questa riga della x. Ok? Quindi poi ci sarà  x + 8 da qualche parte qui. Allora, x... Ah,  
31:57
sì, guardate, la x ogni volta prende tutto un  byte, quindi qua con la x voi vi aspetterete 256,  
32:09
invece 256/8 perché prendo tutto un byte, prendo  gli attributi per quel byte e poi di questo byte  
32:17
faccio il rendering qua. Guardate, copio sul frame  buffer, sul mio frame buffer di destinazione, il  
32:23
colore della palette per 3 byte di quella palette  con tutti i colori che avevamo visto definita  
32:29
prima e poi avanziamo il nostro puntatore di 3  byte e gli andiamo a settare il prossimo pixel,   il prossimo pixel, il prossimo pixel e  abbiamo fatto la prima strisciolina di  
32:37
8 pixel, poi la prossima, la prossima, la  prossima, poi scendo, eccetera eccetera. Va da sé che potete capire bene  che quando io prendo qui `CLR`,  
32:47
che sarebbero sostanzialmente i color attributes,   ora mi sto orientando meglio nel codice che avevo  un po' dimenticato, `clr_offset`, se guardate,  
32:57
praticamente rimarrà uguale ogni volta che io  sono dentro un determinato blocco proprio. Quindi  
33:04
quando qua se si fa il conto finirà che se sono  dentro un determinato blocco io rimango sempre  
33:10
costante. E qua si può vedere dal mascheramento  che viene fatto della Y che perde anche, diciamo,  
33:16
i 2 byte, meno 2 bit meno significativi e  così via. Però qua per semplicità conviene  
33:23
sostanzialmente ogni volta leggere e andare a  scrivere gli 8 bit e così via. O almeno mi ero  
33:28
persuaso in questo modo. Può essere che ci sono  dei modi che ottimizzano ancora di più la cosa.
33:34
A questo punto mi serve una funzione che muti un  po' lo schermo perché io parto con uno schermo  
33:44
che è completamente casuale, sono bit casuali  sia nella parte della memoria che rappresenta  
33:52
i pixel che è questa screen memory, che anche nei  colori. Anzi no, io all'inizio i colori, scusate,  
33:58
li metto tutti neri, tutto nero e bianco. Quindi  questo è il curriculum learning, fa parte anche  
34:05
di... c'è questa strategia anche di curriculum  learning che all'inizio io parto da una soluzione  
34:10
che semplifica il problema quantomeno di trovare  le zone che devono essere con i pixel settati a  
34:17
uno e le zone con i pixel settati al nero con il  background e il foreground che metto di default.  
34:26
Ma questa cosa noi la possiamo andare a  guardare nell'inizializzazione. Comunque   poi mi serve una funzione che muti un po'  la mia memoria e poi ci arriviamo perché  
34:38
qua guardate qua è implementato il curriculum  learning. Fino a una determinata generazione  
34:43
deve fare una determinata cosa, poi da una  generazione in poi, quindi se è passato un  
34:48
po' di tempo deve fare un'altra cosa e così  via. Questa cosa l'andiamo a vedere dopo. Prima di tutto, allora, concentriamoci sul  loop principale di questo algoritmo. Allora,  
34:57
questo algoritmo che usiamo noi si chiama  Simulated Annealing. Il Simulated Annealing qui in  
35:06
una forma veramente rudimentale perché è proprio  una cosa... è quasi, diciamo, un algoritmo qua  
35:14
veramente a forza bruta questo, però di nostro ci  mettiamo che siamo disponibili ad accettare anche  
35:21
soluzioni peggiori per poterlo chiamare Simulated  Annealing, ma è abbastanza inutile, poi vedremo.  
35:29
Però, insomma, è un algoritmo in  cui vengono fatte delle modifiche,   si vede se praticamente questa modifica è  migliorativa o peggiorativa, perché abbiamo  
35:38
una funzione che ci dice qual è la differenza  tra l'immagine che noi abbiamo generato e   l'immagine target. Ma se vogliamo parlare in  termini più generali, tra la soluzione che  
35:47
noi abbiamo generato e la soluzione target. Se  c'è un miglioramento lo accettiamo e facciamo  
35:52
un'altra mutazione, quindi continueremo a  trovare delle soluzioni sempre migliori.
35:58
In realtà il Simulated Annealing ha due  altri trucchi che permettono di andare  
36:07
via dai minimi locali, cioè perché  la mia funzione d'errore è, diciamo,   abbastanza complicata. Visto che la memoria dello  Spectrum è fatta in quel modo e così via. Allora,  
36:16
mi può capitare che io incappo in un minimo  locale. Per esempio, vi faccio un esempio di   un minimo locale. Se io praticamente tolgo il  curriculum learning e gli faccio già variare  
36:25
sin dall'inizio randomicamente sia i blocchi,  i colori, gli attributi del colore che i pixel,  
36:31
lui se c'è un'area nera, beccherà che può mettere  il background e il foreground di quel blocco nero  
36:39
e però avrò dei margini frastagliati, non  ci sarà alcuna curva, se c'era una curva là  
36:44
vicino. Si accontenta di quello. Ed è un minimo  locale perché poi se lui cambia il colore di  
36:51
quel blocco di attributi e mette uno dei due  bianco, sarà talmente tanto l'errore di quei  
36:58
64 pixel che non ci sarà mai la possibilità di  scavalcare questo errore qui e in effetti mettere  
37:03
bianco e nero e poi trovare la giusta curva dei  pixel che sarebbe ottimale. Quindi quel blocco  
37:09
rimarrà tutto nero. Spero di essermi spiegato.  Per questo noi serve il curriculum learning.
37:18
Però in generale il Simulated Annealing ha  anche un parametro che si chiama temperatura.  
37:24
La temperatura inizia ad essere con  un valore molto alto e man mano cala.  
37:30
Quando la temperatura è alta, a volte accettiamo  anche soluzioni che sono peggiorative rispetto a  
37:37
quella migliore trovata attualmente. Però questa  probabilità di accettare una soluzione più  
37:43
sconveniente è proporzionale alla temperatura. Se  la temperatura è alta è facile che l'accettiamo,   se la temperatura è bassa è difficile che noi  accettiamo soluzioni peggiorative. Inoltre,  
37:53
più alta è la temperatura e maggiore sarà la  quantità di mutazioni o il grado di mutazione  
38:04
che faremo nella soluzione attuale. Questo  algoritmo in realtà si ispira a un processo  
38:11
fisico che è quello che si usa quando si  fa raffreddare un metallo per, diciamo,  
38:17
temprarlo. Ora non so se il Simulated Annealing  è proprio la temperatura o è un altro processo,  
38:23
ma noi lo scopriremo. Simulated Annealing è il  processo di ricottura. Comunque un processo simile  
38:32
in cui praticamente all'inizio le molecole si  muovono all'impazzata e trovano piano piano che si  
38:38
raffreddano si muovono sempre di meno, si spostano  e trovano il modo di legarsi quanto più ordinato  
38:44
e quanto più che conferisce poi resistenza,  diciamo, ai metalli. E questo processo, ecco,  
38:51
come vedete funziona tutto esattamente  dopo che abbiamo fatto quella modifica,   perché era abbastanza inutile quella roba lì  che mi ero portato appresso dall'emulatore.
39:05
Eh, ma in realtà, siccome noi facciamo  questo curriculum learning in cui prima  
39:10
impariamo la configurazione da bitmap e  poi cambiamo i colori, a noi il fatto di  
39:17
accettare una soluzione peggiore non ci  serve a niente perché non entreremo mai   in un minimo locale da cui non possiamo  uscire. Per cui in questo momento è così,  
39:27
ma noi probabilmente questa cosa qua  la possiamo rimuovere senza indugi.
39:32
Quindi guardate qual è il loop principale. Ecco,  questa cosa è da imparare. Poi i sorgenti, ripeto,  
39:37
li metterò online, per cui ve li potete andare  a guardare con cura. Evolve the current solution  
39:44
using simulated annealing. Max mutation.  Allora la funzione `mutate` che cambia dei  
39:54
bit sia dello ZX Spectrum, perché questo  fa bit flipping sostanzialmente e basta.  
40:01
Vedete, cioè si crea il rendering, è pazzesco.  Fa da una fino a massimo cinque mutazioni. Ok?  
40:10
In realtà queste mutazioni dovrebbero ridursi  man mano che la temperatura si abbassa. Ora   vediamo se questa cosa la vogliamo fare o meno,  ma potrebbe non migliorerà quello che troviamo,  
40:21
ma migliorerà la velocità alla quale noi riusciamo  a trovare delle soluzioni migliori. Ecco perché a  
40:27
noi non ci interessa il fatto tanto di riuscire  ad accettare delle soluzioni peggiori, perché  
40:35
siccome noi facciamo cinque mutazioni, se abbiamo  una configurazione di pixel che dovremmo mutare,  
40:41
diciamo, una vicino all'altra per beccare  la soluzione migliore, capiterà che visto  
40:47
quanti calcoli facciamo senza sosta, capiterà che  praticamente andiamo a modificare proprio quei due  
40:54
pixel vicini e li invertiamo e quindi ci voleva in  teoria per arrivare a quella soluzione modificando  
41:00
un pixel per volta prima passare da una soluzione  peggiorativa, ma siccome noi facciamo fino   a cinque swap simultaneamente e l'immagine è  minuscola, incredibilmente funziona anche così.
41:12
Ehm, quindi guardate che succede. Noi copiamo  nella nuova soluzione, la migliore attualmente  
41:20
trovata e la copiamo per tutta la memoria dello  ZX Spectrum. Quindi la nostra soluzione che cos'è?  
41:27
Una soluzione per noi è la copia  della memoria video dello ZX Spectrum,   quindi lavoriamo alla cieca in maniera  totale. Facciamo questa mutazione,  
41:36
gli diciamo anche in che generazione siamo.  Come mai `mutate` prende la generazione? Ah,  
41:42
perché deve fare lavori diversi in base a dove  siamo arrivati per fare il curriculum learning.  
41:50
Poi trasformiamo la nuova soluzione in una  immagine perché ricordatevi che la soluzione non  
41:55
è l'immagine ma è la memoria dello ZX Spectrum che  genera una data immagine. Poi faccio la differenza  
42:01
tra l'immagine che io avevo caricato della PNG e  effettivamente il frame buffer per questa width  
42:09
e per questa height. A questo punto calcolo la  percentuale di differenza dalla differenza raw  
42:15
che è la somma delle distanze di tutti i punti  e ne abbiamo parlato. Questa cosa per esempio   ecco è bad design. Sta roba qui dovrebbe essere  assolutamente incorporata giù. Perché io questo  
42:30
DIF... ah, perché lo voglio stampare. Ah,  no, questo DIF non è il DIF, è `percDiff`.  
42:49
DIF dov'è DIF? Lo cancelliamo. `percDiff` ci  serve è un'altra cosa. Andiamo alla funzione  
43:02
`computeDiff` e gli diamo un po' di senso.  Quindi non ritorniamo D, ma facciamo, scusate,  
43:13
qui questa cosa e questa ora ritorna float.  Quindi questa funzione: "Compute difference is  
43:25
the sum of the differences... The returned value  is the percentage of difference from 0 to 100%,  
44:33
and 0% means identical images". Vabbè, questo  è quello di cui avevamo parlato poco fa.  
44:40
Quindi ora questo `computeDiff` noi l'abbiamo  fatto qua, non funziona niente. 300 perché si  
44:49
chiama `d`. Vediamo se funziona ancora. Quittiamo  e riavviamo. Se inizia a mostrarsi l'immagine,  
45:06
come sta già succedendo, significa  che funziona tutto perfettamente. Va  
45:12
bene. Ecco perché non avevo rilasciato questo  programma, perché faceva schifo e io lo sapevo,  
45:18
ma volevo solo vedere il risultato  e me ne impipavo delle altre cose.
45:23
Allora, guardate qua che succede. Qua lancio un  dado da 0 a 1, un dado in virgola mobile, genero  
45:33
un numero da 0 a 1. Se il dado è minore della  temperatura, accetto una... eh ah no, scusate,  
45:45
se la generazione è la prima generazione, quindi  devo accettare per forza come una mia soluzione   migliore, ne ho solo una, o se la percentuale  della differenza è minore della percentuale di  
45:56
differenza della mia immagine, della mia soluzione  migliore, quindi se è migliorativa o anche se non  
46:01
è migliorativa, ma il dado ha un valore inferiore  della temperatura. Quindi praticamente in quel  
46:11
caso guardate la temperatura come si evolve.  Già la temperatura è negativa, ma all'inizio,  
46:18
ecco, guardate, parte da 0,9, quindi c'è il  10% di probabilità all'inizio che io accetto  
46:24
una soluzione peggiorativa, man mano questa  probabilità scende sempre di più, dopo poi diventa   negativo e non può succedere mai più. Infatti qua  vediamo l'immagine che man mano si va formando.
46:38
Allora io praticamente accetto questa  nuova soluzione. In che modo la accetto?   Copio nella memoria dello ZX Spectrum la  mia soluzione best la new, e poi mi setto  
46:49
qual è la differenza migliore finora che ho  incontrato, quindi la differenza più bassa  
46:56
che finora sono riuscito a incontrare. Ogni volta  che eseguo 1000 generazioni di questo programma,  
47:05
mostro l'immagine a video, quindi trasformo  la mia soluzione migliore in un frame buffer  
47:11
e poi chiamo `SDL_ShowRGB` che mi permette  di vedere questa immagine e poi faccio  
47:18
`processSDLEvents` e aumento la generazione  e abbasso la temperatura piano piano.
47:24
Bene, pensavo di farcela in un'unica puntata,  invece mi sa che è da tantissimo tempo che  
47:30
parlo. Non ne ho idea. Saranno di più di 40  minuti, è molto probabile, se non ancora di più,  
47:36
per cui dobbiamo dividere anche questa cosa che  doveva essere una pausa dalle lungaggini della  
47:43
Toy Forth. Ci tocca dividere questa puntata  a metà. Arrivederci alla prossima settimana.