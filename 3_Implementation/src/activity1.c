#include "activity1.h"

void seat_sensing(){
    DDRD|=(1<<PD2); 
    DDRD&=~(1<<PD3); 
    PORTD|=(1<<PD3); 
    DDRD&=~(1<<PD4); 
    PORTD|=(1<<PD4); 
}
