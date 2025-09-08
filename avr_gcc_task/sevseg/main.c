#include <avr/io.h>
#include <util/delay.h>

int main(void) {
    int X, Y, Z, f;

    // Inputs: PD2, PD3, PD4
    DDRD &= ~( (1<<PD2) | (1<<PD3) | (1<<PD4) );

    // Outputs: seven-seg on PD6, PD7, PB0–PB4
    DDRD |= (1<<PD6) | (1<<PD7);
    DDRB |= (1<<PB0) | (1<<PB1) | (1<<PB2) | (1<<PB3) | (1<<PB4);

    while(1) {
        // Read inputs
        X = (PIND & (1<<PD2)) ? 1 : 0;
        Y = (PIND & (1<<PD3)) ? 1 : 0;
        Z = (PIND & (1<<PD4)) ? 1 : 0;

        // Logic function f = X'Y' + YZ
        f = ((!X && !Y) || (Y && Z));

        if(f==1) {
            // Show "1" on seven-seg → segments b,c ON
            PORTD |= (1<<PD6);             // a off → 1
            PORTD &= ~(1<<PD7);            // b on  → 0
            PORTB &= ~(1<<PB0);            // c on  → 0
            PORTB |= ((1<<PB1)|(1<<PB2)|(1<<PB3)|(1<<PB4)); // d,e,f,g off → 1
        }
        else {
            // Show "0" on seven-seg → segments a,b,c,d,e,f ON
            PORTD &= ~((1<<PD6) | (1<<PD7));  // a,b on → 0
            PORTB &= ~((1<<PB0)|(1<<PB1)|(1<<PB2)|(1<<PB3)); // c,d,e,f on → 0
            PORTB |= (1<<PB4);                 // g off → 1
        }

        _delay_ms(200);
    }
}
