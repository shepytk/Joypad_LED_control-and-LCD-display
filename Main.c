

/*
 * Calibration.c
 *
 * Created: 1/27/2016 1:27:50 AM
 *  Author: Shepherd
 */ 


#include "includes.h"


int main(void)
{
		uint16_t uiHorizontal    = 1000;    //initial value X axis
		uint16_t uiVertical      = 1000;      //initial value Y axis
		uint16_t uiHorizontalMov = 0;
		uint16_t uiVerticalMov   = 0;
	
	init_setup();
	Port_Setup();
	ADC_setup();
	
	
	//SetupPorts();                       // use PortB for LCD interface
	LCD_Init();                         // initialize LCD controller
	LCD_Message("Ready.");              // welcome message
	msDelay(2000);                      // wait     while(1)
	//FillScreen();                   // fill screen with ASCII characters


	while(1)
	{
		switch(ADMUX)
		{
			case 0x40:
			{
				startADC();
				while(!(ADCSRA&(1<<ADIF)));  //Wait till ADC conversion is done
				uiHorizontalMov = ADC;       //Get the Horizontal moving value
				ADC_reset();                 //Reset the ADC register
				ADMUX = 0x41;                //Changint the ADC channel
				break;
			}
			case 0x41:
			{
				startADC();
				while(!(ADCSRA&(1<<ADIF)));  //Wait till ADC conversion is done
				uiVerticalMov = ADC;         //Get the Vertical moving value
				ADC_reset();                 //Reset the ADC register
				ADMUX = 0x40;                //Changint the ADC channel
				break;
			}
			
		}
		                            /* Display Horizontal Data*/
		LCD_Message("H: ");
		LCD_Integer(uiHorizontalMov);
	 
	 /*   _delay_ms(30);
		LCD_Clear();
		_delay_ms(10);
		               */            /* Display Vertical Data  */     
		LCD_Message(" V: ");
		LCD_Integer(uiVerticalMov);
	    _delay_ms(30);
		LCD_Clear();
		_delay_ms(10);
		
		 if(uiHorizontalMov <= 55 )
		 {
			 LED_left();
			 delay();
			 PortD_reset();
		 }
		 if(uiHorizontalMov > uiHorizontal-5 )
		 {
			 LED_right();
			 delay();
			 PortD_reset();  //return to default
		 }
		 
		 if(uiVerticalMov <= 55)
		 {
			 LED_down();
			 delay();
			 PortD_reset();  //return to default state
		 }
		 if(uiVerticalMov > uiVertical-5)
		 {
			 LED_up();
			 delay();
			 PortD_reset();
		 }
	}
	
	
}


	
