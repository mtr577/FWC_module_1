#include <avr/io.h>

int main(void) {
    // Inputs: X=PD4, Y=PD3, Z=PD2
    DDRD &= ~((1<<PD2) | (1<<PD3) | (1<<PD4));

    // Output: F=PB0 (pin 8 Arduino UNO ref.)
    DDRB |= (1<<PB0);

    int X, Y, Z, F;

    while (1) {
        // Read inputs
        Z = (PIND & (1<<PD2)) ? 1 : 0;
        Y = (PIND & (1<<PD3)) ? 1 : 0;
        X = (PIND & (1<<PD4)) ? 1 : 0;

        // F = X'Y' + YZ
        F = ((!X && !Y) || (Y && Z));

        if (F)
            PORTB |= (1<<PB0);   // LED ON
        else
            PORTB &= ~(1<<PB0);  // LED OFF
    }
}
