.include "/sdcard/fwc_module_1/assembly/m328pdef.inc"

.org 0x00
    rjmp reset

reset:
    ldi r16, 0x00
    out DDRD, r16

    ldi r16, 0x3F
    out DDRB, r16

main:
    in r16, PIND
    lsr r16
    lsr r16             ; PD5..PD2
    andi r16, 0x0F      ; r16 = PS = ABCD
    mov r18, r16        ; Save PS in r18

    mov r19,r18         ; A
    andi r19,0b1000
    lsr r19
    lsr r19
    lsr r19             ; r19 = A

    mov r20,r18         ; B
    andi r20,0b0100
    lsr r20
    lsr r20             ; r20 = B

    mov r21,r18         ; C
    andi r21,0b0010
    lsr r21             ; r21 = C

    mov r22,r18         ; D
    andi r22,0b0001     ; r22 = D

    ldi r23,1
    eor r23,r19         ; A_out

    ; B_out = B ⊕ A
    mov r24,r20
    eor r24,r19         ; B_out

    ; C_out = C ⊕ (A·B)
    mov r25,r19
    and r25,r20         ; A·B
    eor r25,r21         ; C_out

    ; D_out = D ⊕ (A·B·C)
    mov r26,r19
    and r26,r20
    and r26,r21         ; A·B·C
    eor r26,r22         ; D_out

    ldi r27,1
    eor r27,r19         ; ~A
    ldi r28,1
    eor r28,r20         ; ~B
    and r27,r28
    and r27,r22         ; Term1 in r27

    ; Term2: ~A·B·~C
    ldi r28,1
    eor r28,r19         ; ~A
    mov r29,r20         ; B
    and r28,r29
    ldi r29,1
    eor r29,r21         ; ~C
    and r28,r29         ; Term2 in r28

    ; Term3: ~A·B·C
    ldi r29,1
    eor r29,r19         ; ~A
    mov r30,r20         ; B
    and r29,r30
    mov r30,r21         ; C
    and r29,r30         ; Term3 in r29

    ; Term4: A·~B·~C·~D
    mov r30,r19         ; A
    ldi r31,1
    eor r31,r20         ; ~B
    and r30,r31
    ldi r31,1
    eor r31,r21         ; ~C
    and r30,r31
    ldi r31,1
    eor r31,r22         ; ~D
    and r30,r31         ; Term4 in r30

    ; Term5: A·~B·C·D
    mov r31,r19         ; A
    ldi r16,1
    eor r16,r20         ; ~B
    and r31,r16
    mov r16,r21         ; C
    and r31,r16
    mov r16,r22         ; D
    and r31,r16         ; Term5 in r31

    ; Combine all terms -> r17 = F
    mov r17,r27
    or r17,r28
    or r17,r29
    or r17,r30
    or r17,r31          ; r17 = F

    ldi r16,0
    or r16,r17          ; F to bit0
    mov r27,r16

    mov r16,r23
    lsl r16
    lsl r16
    lsl r16
    or r27,r16

    mov r16,r24
    lsl r16
    lsl r16
    or r27,r16

    mov r16,r25
    lsl r16
    or r27,r16

    or r27,r26

    out PORTB,r27

    sbi PORTB,5
    rcall delay_500ms
    cbi PORTB,5
    rcall delay_500ms

    rjmp main

delay_500ms:
    ldi r30, 200
outer_loop:
    ldi r31, 250
middle_loop:
    ldi r16, 250
inner_loop:
    dec r16
    brne inner_loop
    dec r31
    brne middle_loop
    dec r30
    brne outer_loop
    ret
