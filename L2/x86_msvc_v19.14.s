## c code in c_source.c
_a$ = 8                                         ; size = 4
_b$ = 12                                        ; size = 4
_sum    PROC
        push    ebp
        mov     ebp, esp
        mov     eax, DWORD PTR _a$[ebp]         ## muove la parola in ebp + a nel registro eax
        add     eax, DWORD PTR _b$[ebp]         ## aggiunge ad eax la word che c'è in ebp + b
        pop     ebp
        ret     0                               ## conclude e consuma il registro PC - va alla riga 19
_sum    ENDP

_main   PROC
        push    ebp
        mov     ebp, esp                        ## la mov copia il registro a destra in quello a sinistra
        push    20                              ; 00000014H
        push    10                              ; 0000000aH
        call    ebp                             # salta alla riga 4 e salva il PC
        add     esp, 8
        pop     ebp
        ret     0
_main   ENDP