.include "/sdcard/fwc_module_1/assembly/m328pdef.inc"

.org 0x00
rjmp reset

reset:
    ; set PORTD as input
    ldi r16, 0x00
    out DDRD, r16

    ; set PB0 as output
    ldi r16, 0x01
    out DDRB, r16

main:
    in r16, PIND         
    lsr r16              
    lsr r16
    andi r16, 0x0F       
    mov r17, r16         ;copy → r17 = ABCD

    mov r18, r17
    andi r18, 0b1000      ; A mask
    lsr r18
    lsr r18
    lsr r18               ; r18 = A

    mov r19, r17
    andi r19, 0b0100      ; B mask
    lsr r19
    lsr r19               ; r19 = B

    mov r20, r17
    andi r20, 0b0010      ; C mask
    lsr r20               ; r20 = C

    mov r21, r17
    andi r21, 0b0001      ; D mask

    ldi r22,1
    eor r22,r18           ; r22 = ~A

    ldi r23,1
    eor r23,r19           ; r23 = ~B

    ldi r24,1
    eor r24,r20           ; r24 = ~C

    ldi r25,1
    eor r25,r21           ; r25 = ~D

    ; Term1 = ~A·~B·C
    mov r26,r22
    and r26,r23
    and r26,r20

    ; Term2 = ~A·B·D 
    mov r27,r22
    and r27,r19
    and r27,r21

    ; Term3 = A·~B·~C
    mov r28,r18
    and r28,r23
    and r28,r24

    ; Term4 = A·B·~C·~D 
    mov r29,r18
    and r29,r19
    and r29,r24
    and r29,r25

    ; Combine all terms 
    mov r30,r26
    or  r30,r27
    or  r30,r28
    or  r30,r29           ; r30 = F

    andi r30,0x01
    out PORTB,r30

    rjmp main
