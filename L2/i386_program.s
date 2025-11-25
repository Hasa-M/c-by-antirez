## c code in c_source.c
_a$ = 8                                         ; size = 4
_b$ = 12                                        ; size = 4
_sum    PROC
        push    ebp
        mov     ebp, esp
        mov     eax, DWORD PTR _a$[ebp]         ## move the word in ebp + a into the eax register
        add     eax, DWORD PTR _b$[ebp]         ## sums to eax the word that is in ebp + b
        pop     ebp
        ret     0                               ## concludes and consumes the PC register - goes to line 19
_sum    ENDP

_main   PROC
        push    ebp
        mov     ebp, esp                        ## the mov copies the register on the right to the one on the left
        push    20                              ; 00000014H
        push    10                              ; 0000000aH
        call    ebp                             # jump to line 4 and save your PC
        add     esp, 8
        pop     ebp
        ret     0
_main   ENDP
