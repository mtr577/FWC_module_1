.include "/sdcard/fwc_module_1/assembly/m328pdef.inc"

; ---------------------------------------------------
; Inputs : A=PD5, B=PD4, C=PD3, D=PD2
; Output : F shown on 7-seg (pins 6–12)
; Mapping : seg_a = PD6, seg_b = PD7, seg_c = PB0,
;           seg_d = PB1, seg_e = PB2, seg_f = PB3, seg_g = PB4
; Common Anode
; ---------------------------------------------------

.org 0x00
rjmp reset

reset:
    ; Inputs
    ldi r16, 0x00
    out DDRD, r16
    ; Outputs: PD6,PD7
    ldi r16, (1<<6)|(1<<7)
    out DDRD, r16
    ; Outputs: PB0..PB4
    ldi r16, 0b00011111
    out DDRB, r16

main:
    ; -------- Read inputs --------
    in r16, PIND
    lsr r16
    lsr r16
    andi r16, 0x0F
    mov r17, r16          ; r17 = ABCD

    ; -------- Extract A,B,C,D --------
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

    ; -------- Complements --------
    ldi r22,1
    eor r22,r18           ; ~A
    ldi r23,1
    eor r23,r19           ; ~B
    ldi r24,1
    eor r24,r20           ; ~C
    ldi r25,1
    eor r25,r21           ; ~D

    ; -------- Terms --------
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

    ; -------- Final F --------
    mov r30,r26
    or  r30,r27
    or  r30,r28
    or  r30,r29           ; F in r30 (0 or 1)

    ; -------- 7-seg patterns --------
    cpi r30,0
    breq show_zero
    rjmp show_one

; --- Show digit "0"
show_zero:
    ; pattern "0" = abcdef ON, g OFF
    ; Common anode → ON=0, OFF=1
    ; Segments: PD6=a, PD7=b, PB0=c, PB1=d, PB2=e, PB3=f, PB4=g
    ; a=0, b=0, c=0, d=0, e=0, f=0, g=1
    ldi r31, (0<<6)|(0<<7)    ; PD6=0, PD7=0
    in r16, PORTD
    andi r16, 0b00111111      ; clear PD6,7
    or   r16, r31
    out PORTD, r16

    ldi r31, (1<<4)|(0<<3)|(0<<2)|(0<<1)|(0<<0)
    out PORTB, r31
    rjmp main

; --- Show digit "1"
show_one:
    ; "1" = b,c ON, others OFF → b=0, c=0, rest=1
    ldi r31, (1<<6)|(0<<7)    ; a=1, b=0
    in r16, PORTD
    andi r16, 0b00111111
    or   r16, r31
    out PORTD, r16

    ldi r31, (1<<4)|(1<<3)|(1<<2)|(1<<1)|(0<<0)
    out PORTB, r31
    rjmp main
