


#include <avr/io.h>
#define F_CPU 16000000UL                   // CPU clock
#include <util/delay.h>


/*  Function Port_setup 
*   Arguements  : void
*   Discrption  : Initialization and setup of the I/Os 
*   Return      : void
*/

void Port_Setup()
{
	//Use port D and B as Output Ports 
	DDRB  = 0xFF; 
	DDRD  = 0xFF; 
	//Use Port C as Input 
	DDRC  =0x00;	
	PORTD =0x00;   // set 
}


/*  Function ADC_setup
*   Arguements  : void
*   Discrption  : Setup of the ADC channel
*   Return      : void
*/
void ADC_setup()
{
	ADMUX  |= (1<<REFS0);                            // set the reference of ADC     
	ADCSRA |= (1<<ADEN);                             // Enable ADC 
	ADCSRA |= (1<<ADPS0)|(1<<ADPS1)|(1<<ADPS2);      //Set Prescaler
}


/*  Function start_ADC
*   Arguements  : void
*   Discrption  : starts the ADC conversion
*   Return      : void
*/
void startADC()
{
	ADCSRA |= (1<<ADSC);  // To start ADC Conversion	
}

/*  ADC_reset
*   Arguements  : void
*   Discrption  : Deactivate the ADC channel
*   Return      : void
*/
void ADC_reset()
{
	//Reset ADC
	ADC = 0;
}
