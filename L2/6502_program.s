; print video 50 green pixels in sequence

START:
    LDA #50         ; load the value 50 into register A
    JSR FILL_FIVE   ; after loading the value jump to the FILL_FIVE function
    BRK

FILL_FIVE:          ; it starts at 200 ($0200) and writes to memory 50 times 5 moving sequentially
    TAX             ; transfer A to X
    BEQ DONE        ; if it is 0, the instruction is completed, it goes to line 18. Case in which LDA #N has N = 0
    LDY #$00        ; load the value 0 into the Y register
    LDA #$05        ; load the value 5 into the X register
LOOP:
    STA $0200, Y    ; records the value of A at location -> base address + value of Y, which then declares the offset
    INY             ; increment by one unit Y
    DEX             ; decrease X by one unit
    BNE LOOP        ; if X is not zero jump to LOOP
DONE:
    RTS
