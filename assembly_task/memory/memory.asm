.include "/sdcard/fwc_module_1/assembly/m328pdef.inc"

; --------------------------------------------------
; Inputs : A=PD5, B=PD4, C=PD3, D=PD2
; Output : F -> PB0 (LED ON if F=1)
; F truth table stored in SRAM 0x60–0x6F
; F=1 for inputs: 2,3,5,7,8,9,12
; --------------------------------------------------

.org 0x00
rjmp reset

reset:
    ; PORTD input
    ldi r16,0x00
    out DDRD,r16

    ; PB0 output
    ldi r16,0x01
    out DDRB,r16

    ; -------- Store F truth table in SRAM --------
    ldi r16,0  ; F(0)=0
    sts 0x60,r16
    ldi r16,0  ; F(1)=0
    sts 0x61,r16
    ldi r16,1  ; F(2)=1
    sts 0x62,r16
    ldi r16,1  ; F(3)=1
    sts 0x63,r16
    ldi r16,0  ; F(4)=0
    sts 0x64,r16
    ldi r16,1  ; F(5)=1
    sts 0x65,r16
    ldi r16,0  ; F(6)=0
    sts 0x66,r16
    ldi r16,1  ; F(7)=1
    sts 0x67,r16
    ldi r16,1  ; F(8)=1
    sts 0x68,r16
    ldi r16,1  ; F(9)=1
    sts 0x69,r16
    ldi r16,0  ; F(10)=0
    sts 0x6A,r16
    ldi r16,0  ; F(11)=0
    sts 0x6B,r16
    ldi r16,1  ; F(12)=1
    sts 0x6C,r16
    ldi r16,0  ; F(13)=0
    sts 0x6D,r16
    ldi r16,0  ; F(14)=0
    sts 0x6E,r16
    ldi r16,0  ; F(15)=0
    sts 0x6F,r16

main:
    ; -------- Read inputs --------
    in r16,PIND
    lsr r16
    lsr r16
    andi r16,0x0F      ; r16 = 0–15 (ABCD)

    ; -------- Lookup F from SRAM --------
ldi r30, 0x60     ; Z low byte = base address 0x60
ldi r31, 0x00     ; Z high byte = 0x00 (for lower SRAM)
add r30, r16      ; r16 = input (0–15)
ld r17, Z         ; r17 = F from table
    ; -------- Output F to PB0 --------
    andi r17,0x01
    out PORTB,r17

    rjmp main
