#include "activity2.h"
#include "activity3.h"

void adc_initialization()
{
    ADMUX=(1<<REFS0);   //AVCC = +5V
    ADCSRA=(1<<ADEN)|(7<<ADPS0);
}

uint16_t adc_sense(uint8_t channel)
{
    //Select ADC Channel(channel_2) which must be from 0-7
    ADMUX&=0xf8;
    channel=channel&0b00000111;
    ADMUX|=channel;

   
    ADCSRA|=(1<<ADSC);

    //wait for conversion to complete
    while(!(ADCSRA & (1<<ADIF)));

    //Clear ADIF by writing one to it
    ADCSRA|=(1<<ADIF);
    return(ADC);
}

void timer_initialization(void){

    TIMER1_FAST_PWM; //setting timer1 for PWM
    TIMER_PRESCALER_AS_64; //8 prescalar
    PWM_OUTPUT_PIN; //Setting PB1 as output pin

}

void pwm_out(uint16_t ADC_READING){
    char Temperature[20];
    char starter[]="Temperature :)";

    if(ADC_READING>0 && ADC_READING<=200){

        OCR1A = 195; //20% duty cycle
        Temperature[0] = '2';
        Temperature[1] = '0';
        Temperature[2] = 223;
        Temperature[3] = 'C';
        Temperature[4] = ' ';
        Temperature[5] = '\0';
        LCD_String(starter);
        LCD_Command(0xC0);
        LCD_String(Temperature);
        _delay_ms(20);
    }
    else if((ADC_READING>=210) && (ADC_READING<=500)){

        OCR1A = 495; //40% duty cycle
        Temperature[0] = '2';
        Temperature[1] = '5';
        Temperature[2] = 223;
        Temperature[3] = 'C';
        Temperature[4] = ' ';
        Temperature[5] = '\0';
        LCD_String(starter);
        LCD_Command(0xC0);
        LCD_String(Temperature);
        _delay_ms(20);
    }
    else if((ADC_READING>=501) && (ADC_READING<=700)){

        OCR1A = 695;//70% duty cycle
        Temperature[0] = '2';
        Temperature[1] = '9';
        Temperature[2] = 223;
        Temperature[3] = 'C';
        Temperature[4] = ' ';
        Temperature[5] = '\0';
        LCD_String(starter);
        LCD_Command(0xC0);
        LCD_String(Temperature);
        _delay_ms(20);
    }
    else if((ADC_READING>=701) && (ADC_READING<=1024)){

        OCR1A = 1019; //95% duty cycle
        Temperature[0] = '3';
        Temperature[1] = '3';
        Temperature[2] = 223;
        Temperature[3] = 'C';
        Temperature[4] = ' ';
        Temperature[5] = '\0';
        LCD_String(starter);
        LCD_Command(0xC0);
        LCD_String(Temperature);
        _delay_ms(20);
    }
    else{
        OCR1A = 0; //0% output
        Temperature[0] = 'O';
        Temperature[1] = 'F';
        Temp[2] = 'F';
        Temperature[3] = ' ';
        Temperature[4] = ' ';
        Temperature[5] = '\0';
        LCD_String(starter);
        LCD_Command(0xC0);
        LCD_String(Temperature);
        _delay_ms(20);
    }

}
