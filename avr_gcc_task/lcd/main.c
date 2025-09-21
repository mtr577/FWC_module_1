#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t byte;

/* bit helpers */
#define ClearBit(x,y) ( (x) &= ~_BV(y) )
#define SetBit(x,y)   ( (x) |=  _BV(y) )

/* pin mapping on PORTB */
#define LCD_RS 0
#define LCD_E  1
#define DAT4   2
#define DAT5   3
#define DAT6   4
#define DAT7   5

#define CLEARDISPLAY 0x01

static void PulseEnableLine(void)
{
    SetBit(PORTB, LCD_E);
    _delay_us(2);
    ClearBit(PORTB, LCD_E);
    _delay_us(50);
}

static void SendNibble(byte data)
{
    PORTB &= ~((1<<DAT4)|(1<<DAT5)|(1<<DAT6)|(1<<DAT7));
    if (data & (1<<4)) SetBit(PORTB, DAT4);
    if (data & (1<<5)) SetBit(PORTB, DAT5);
    if (data & (1<<6)) SetBit(PORTB, DAT6);
    if (data & (1<<7)) SetBit(PORTB, DAT7);
    PulseEnableLine();
}

static void SendByte(byte data)
{
    SendNibble(data & 0xF0);
    SendNibble((data & 0x0F) << 4);
}

void LCD_Cmd(byte cmd)
{
    ClearBit(PORTB, LCD_RS);
    SendByte(cmd);
    _delay_ms(2);
}

void LCD_Char(byte ch)
{
    SetBit(PORTB, LCD_RS);
    SendByte(ch);
    _delay_ms(2);
}

void LCD_Init(void)
{
    PORTB &= ~((1<<LCD_RS)|(1<<LCD_E)|(1<<DAT4)|(1<<DAT5)|(1<<DAT6)|(1<<DAT7));
    _delay_ms(50);
    LCD_Cmd(0x33);
    LCD_Cmd(0x32);
    LCD_Cmd(0x28);   // 4-bit, 2 line, 5x7
    LCD_Cmd(0x0C);   // display on, cursor off
    LCD_Cmd(0x06);   // entry mode
    LCD_Cmd(CLEARDISPLAY);
    _delay_ms(3);
}

void LCD_Clear(void)
{
    LCD_Cmd(CLEARDISPLAY);
    _delay_ms(3);
}

void LCD_Message(const char *text)
{
    while (*text) {
        LCD_Char((byte)*text++);
    }
}

void LCD_Integer(int data)
{
    char st[8];
    itoa(data, st, 10);
    LCD_Message(st);
}

int main(void)
{
    int X, Y, Z, f;

    /* Set LCD pins as output */
    DDRB |= (1<<LCD_RS)|(1<<LCD_E)|(1<<DAT4)|(1<<DAT5)|(1<<DAT6)|(1<<DAT7);

    /* Inputs: PD2, PD3, PD4 */
    DDRD &= ~( (1<<PD2) | (1<<PD3) | (1<<PD4) );

    LCD_Init();
    LCD_Clear();

    while (1)
    {
        /* Read inputs */
        X = (PIND & (1<<PD2)) ? 1 : 0;
        Y = (PIND & (1<<PD3)) ? 1 : 0;
        Z = (PIND & (1<<PD4)) ? 1 : 0;

        /* Logic function f = X'Y' + YZ */
        f = ((!X && !Y) || (Y && Z));

        /* Display on LCD */
        LCD_Clear();
        LCD_Message("X="); LCD_Integer(X);
        LCD_Message(" Y="); LCD_Integer(Y);
        LCD_Message(" Z="); LCD_Integer(Z);

        LCD_Cmd(0xC0);  // move to second line
        LCD_Message("f = "); LCD_Integer(f);

        _delay_ms(500);
    }

    return 0;
}

