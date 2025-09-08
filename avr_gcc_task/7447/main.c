#include <avr/io.h>
#include <util/delay.h>

int main(void) {
    int X, Y, Z, f;

    // Inputs: PD2, PD3, PD4
    DDRD &= ~( (1<<PD2) | (1<<PD3) | (1<<PD4) );

    // Outputs: PORTB pins PB0–PB3 for 7447 BCD inputs
    DDRB |= 0x0F; // PB0–PB3 as output

    while(1) {
        // Read inputs
        Z = (PIND & (1<<PD2)) ? 1 : 0;
        Y = (PIND & (1<<PD3)) ? 1 : 0;
        X = (PIND & (1<<PD4)) ? 1 : 0;

        // Logic function f = X'Y' + YZ
        f = ((!X && !Y) || (Y && Z));

        // Directly write BCD to 7447 (PB0–PB3)
        if(f == 1)
            PORTB = 0x01;  // 0001
        else
            PORTB = 0x00;  // 0000

        _delay_ms(200);
    }
}
