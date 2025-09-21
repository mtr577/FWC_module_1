.include "/sdcard/fwc_module_1/assembly/m328pdef.inc"

.org 0x00
rjmp reset

reset:
    ; PORTD as input
    ldi r16, 0x00
    out DDRD, r16

    ; PB0 and PB5 as outputs
    ldi r16, (1<<DDB0)|(1<<DDB5)
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
    and r26,r20           ; Term1

    mov r27,r22
    and r27,r19
    and r27,r21           ; Term2

    mov r28,r18
    and r28,r23
    and r28,r24           ; Term3

    mov r29,r18
    and r29,r19
    and r29,r24
    and r29,r25           ; Term4

    mov r30,r26
    or  r30,r27
    or  r30,r28
    or  r30,r29

    andi r30,0x01         ; ensure single bit
    out PORTB,r30         ; PB0 = F

    sbi PORTB,5           ; PB5 = 1
    rcall delay500
    cbi PORTB,5           ; PB5 = 0
    rcall delay500

    rjmp main

delay500:
    ldi r16, 50           ; outer loop
d1: ldi r17, 200
d2: ldi r18, 200
d3: dec r18
    brne d3
    dec r17
    brne d2
    dec r16
    brne d1
    ret
