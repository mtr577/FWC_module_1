#include <avr/io.h>
#include <util/delay.h>

int main(void) {
    int X, Y, Z, f;

    // Inputs: PD2, PD3, PD4
    DDRD &= ~((1<<PD2)|(1<<PD3)|(1<<PD4));

    // Outputs: PB0 → D input of 7474 (Arduino pin 8)
    //          PB5 → CLK input of 7474 (Arduino pin 13)
    DDRB |= (1<<PB0)|(1<<PB5);

    while(1) {
        // Read inputs
        Z = (PIND & (1<<PD2)) ? 1 : 0;
        Y = (PIND & (1<<PD3)) ? 1 : 0;
        X = (PIND & (1<<PD4)) ? 1 : 0;

        // Compute logic function f = X'Y' + YZ
        f = ((!X && !Y) || (Y && Z));

        // Output f to D input of 7474
        if(f)
            PORTB |= (1<<PB0);   // f = 1
        else
            PORTB &= ~(1<<PB0);  // f = 0

        // Generate clock pulse for 7474
        PORTB |= (1<<PB5);       // CLK HIGH
        _delay_ms(500);          // Wait 500 ms
        PORTB &= ~(1<<PB5);      // CLK LOW
        _delay_ms(500);          // Wait 500 ms
    }
}
