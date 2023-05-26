#include <mega32.h>
#include <delay.h>

int i, channel;

void car_move(void){
    PORTC.0 = 1; 
    PORTC.1 = 0;
    PORTC.2 = 1;
    PORTC.3 = 1;
    delay_ms(10);
}

void car_brake_slow(void){
    PORTC.1 = 1;
    PORTC.2 = 0;
    PORTC.3 = 0;
    delay_ms(10);
    for (i = 0; i < 2; i++){
        PORTC.0 = 0;
        delay_ms(120);
        PORTC.0 = 1;
        delay_ms(40);
    }  
}

void car_brake_fast(void){
    PORTC.1 = 1;
    PORTC.2 = 0;
    PORTC.3 = 0; 
    for (i = 0; i < 2; i++){
        PORTC.0 = 0;
    } 
}

void LEFT_slow(void){
    PORTC.2 = 1;
    PORTC.3 = 0;
    PORTC.4 = 1;
    PORTC.5 = 0; 
    PORTC.6 = 0; 
    PORTC.7 = 0;  
    delay_ms(100);
}

void LEFT_fast(void){
    PORTC.2 = 1;
    PORTC.3 = 0;
    PORTC.4 = 1;
    PORTC.5 = 1; 
    PORTC.6 = 0; 
    PORTC.7 = 0;  
    delay_ms(100);
}

void RIGHT_slow(void){
    PORTC.2 = 0;
    PORTC.3 = 1;
    PORTC.4 = 0;
    PORTC.5 = 0; 
    PORTC.6 = 0; 
    PORTC.7 = 1;  
    delay_ms(100);
}

void RIGHT_fast(void){
    PORTC.2 = 0;
    PORTC.3 = 1;
    PORTC.4 = 0;
    PORTC.5 = 0; 
    PORTC.6 = 1; 
    PORTC.7 = 1;  
    delay_ms(100);
}

void straight(void){
    PORTC.1 = 0;
    PORTC.2 = 1;
    PORTC.3 = 1;
    PORTC.4 = 1;
    PORTC.5 = 0; 
    PORTC.6 = 0; 
    PORTC.7 = 1; 
    delay_ms(100);
}

void ADC_channel(int channel){
    if (channel == 0){
        ADMUX = 0xC0;
    }
    if (channel == 3){
        ADMUX = 0xC3;
    }
    if (channel == 6){
        ADMUX = 0xC6;
    }
    ADMUX = ADMUX|(channel & 0xFF);
}

void Forward_Backward(void){
    ADC_channel(3);
    ADCSRA|= (1<<ADSC);
    while(ADCSRA&(1<<ADIF)==0); 
    delay_ms(10);
     
    if (ADCW >= 512 && ADCW <= 632){
        PORTB = 0x18;
        car_brake_slow();
        delay_ms(10);            
    }  
        
    else if (ADCW > 632 && ADCW <= 831){
        PORTB = 0x3C;
        car_brake_slow();
        delay_ms(10);            
    } 
        
    else if (ADCW > 831 && ADCW <= 1023){
        PORTB = 0x7E;
        car_brake_fast(); 
        delay_ms(10); 
        PORTB = 0x00;      
    }
}

void LEFT(void){
    ADC_channel(6);
    ADCSRA|= (1<<ADSC);
    while(ADCSRA&(1<<ADIF)==0);  
    delay_ms(10);
     
    if (ADCW >= 632 && ADCW <= 831){
        PORTB = 0x03;
        LEFT_slow(); 
        delay_ms(10);           
    } 
        
    else if (ADCW > 831 && ADCW <= 1023){
        PORTB = 0x0F;
        LEFT_fast();
        delay_ms(10);        
    }
        
    else 
        straight();
        delay_us(10);
        PORTB = 0x00;
}

void RIGHT(void){
    ADC_channel(0);
    ADCSRA|= (1<<ADSC);
    while(ADCSRA&(1<<ADIF)==0);
    delay_ms(10);
     
    if (ADCW >= 632 && ADCW <= 831){
        PORTB = 0xC0;
        RIGHT_slow();
        delay_ms(10);            
    } 
        
    else if (ADCW > 831 && ADCW <= 1023){
        PORTB = 0xF0;
        RIGHT_fast();
        delay_ms(10);        
    }
        
    else 
        straight();
        delay_us(10);
        PORTB = 0x00;
}

void main(void)
{
    DDRA = 0x00;
    DDRB = 0xFF; 
    DDRC = 0xFF;
    ADCSRA = 0x87;
    PORTC = 0x01;
    
    while(1){ 
        RIGHT();
        delay_ms(10);
        LEFT();
        delay_ms(10);
        Forward_Backward();
        delay_ms(10);
    }
}
