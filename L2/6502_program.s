## stampa 50 pixel di colore verde in sequenza a video

START:
    LDA #50         ## carica il valore 50 dentro il registro A
    JSR FILL_FIVE   ## dopo aver caricato il valore salta alla funzione FILL_FIVE
    BRK

FILL_FIVE:          ## parte da 200 ($0200) e scrive nella memoria per 50 volte 5 spostandosi sequenzialmente
    TAX             ## trasferisci A in X
    BEQ DONE        ## se vale 0, l'istruzione è conclusa, va in riga 18. Casistica in cui LDA #N abbia N = 0.
    LDY #$00        ## carica nel registo Y il valore 0
    LDA #$05        ## carica nel registro X il valore 5
LOOP:
    STA $0200, Y    ## Registra il valore di A alla locazione -> indirizzo di base + valore di Y, che quindi dichira l'offset.
    INY             ## incrementa di un unità Y.
    DEX             ## decremento X di un unità.
    BNE LOOP        ## se X non è zero salta a LOOP.
DONE:
    RTS