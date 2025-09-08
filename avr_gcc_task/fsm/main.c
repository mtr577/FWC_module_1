#include <avr/io.h>
#include <util/delay.h>

int main(void) {
    int X,Y,Z;      // Current state inputs
    int A,B,C,D;    // Next state outputs to 7474
    int f;          // LED output

    // Configure inputs: X,Y,Z
    DDRD &= ~((1<<PD2)|(1<<PD3)|(1<<PD4));  // pins 2,3,4 as input

    // Configure outputs: A,B,C,LED,CLK
    DDRB |= (1<<PB0)|(1<<PB1)|(1<<PB2)|(1<<PB4)|(1<<PB5);  // pins 8,9,10,12,13

    while(1) {
        // Read current state
        X = (PIND & (1<<PD4)) ? 1 : 0; // MSB
        Y = (PIND & (1<<PD3)) ? 1 : 0;
        Z = (PIND & (1<<PD2)) ? 1 : 0; // LSB

        // Next-state equations (corrected)
        C = (X && !Y) || (X && !Z) || (!X && Y && Z); // MSB → pin 10
        B = (!Y && Z) || (Y && !Z);                   // middle → pin 9
        A = !Z;                                       // LSB → pin 8
        D = 0;                                        // unused

        // Compute f using K-map minimized logic
        f = (!X&&!Z) || (X&&Y);  // f=1 for XYZ=0,2,6,7

        // Drive LED → pin 12
        if(f)
            PORTB |= (1<<PB4);   // LED ON
        else
            PORTB &= ~(1<<PB4);  // LED OFF

        // Output next state to 7474 D inputs
        if(A) PORTB |= (1<<PB0); else PORTB &= ~(1<<PB0); // LSB → pin 8
        if(B) PORTB |= (1<<PB1); else PORTB &= ~(1<<PB1); // middle → pin 9
        if(C) PORTB |= (1<<PB2); else PORTB &= ~(1<<PB2); // MSB → pin 10

        // Toggle 7474 CLK → pin 13
        PORTB |= (1<<PB5);   // CLK HIGH
        _delay_ms(500);
        PORTB &= ~(1<<PB5);  // CLK LOW
        _delay_ms(500);
    }
}
