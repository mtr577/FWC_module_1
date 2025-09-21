.include "/sdcard/fwc_module_1/assembly/m328pdef.inc"

.org 0x00
rjmp reset

reset:
    ; PORTD inputs
    ldi r16, 0x00
    out DDRD, r16

    ; PB3..PB0 outputs
    ldi r16, 0x0F
    out DDRB, r16

main:
    in r16, PIND
    lsr r16
    lsr r16
    andi r16, 0x0F
    mov r17, r16          ; r17 = ABCD

    mov r18, r17
    andi r18, 0b1000
    lsr r18
    lsr r18
    lsr r18               ; A

    mov r19, r17
    andi r19, 0b0100
    lsr r19
    lsr r19               ; B

    mov r20, r17
    andi r20, 0b0010
    lsr r20               ; C

    mov r21, r17
    andi r21, 0b0001      ; D

    ldi r22,1
    eor r22,r18           ; ~A
    ldi r23,1
    eor r23,r19           ; ~B
    ldi r24,1
    eor r24,r20           ; ~C
    ldi r25,1
    eor r25,r21           ; ~D

    mov r26,r22
    and r26,r23
    and r26,r20           ; Term1 = ~A·~B·C

    mov r27,r22
    and r27,r19
    and r27,r21           ; Term2 = ~A·B·D

    mov r28,r18
    and r28,r23
    and r28,r24           ; Term3 = A·~B·~C

    mov r29,r18
    and r29,r19
    and r29,r24
    and r29,r25           ; Term4 = A·B·~C·~D

    mov r30,r26
    or  r30,r27
    or  r30,r28
    or  r30,r29

    cpi r30,0
    breq show_one          ; if F=0 → show "1"
    rjmp show_zero         ; if F=1 → show "0"

show_zero:
    ldi r31,0b0000         ; BCD=0000 → "0"
    out PORTB,r31
    rjmp main

show_one:
    ldi r31,0b0001         ; BCD=0001 → "1"
    out PORTB,r31
    rjmp main
