/*
*  Functions LED_XXX
*  Arguements  :void 
*  Description : Turn on the LED on PINDx
*  Return : void
*/

void LED_left()
{
	PORTD |=(1<<PIND7);
}
void LED_right()
{
	PORTD |=(1<<PIND5);
}
void LED_up()
{
	PORTD |=(1<<PIND3);
}
void LED_down()
{
	PORTD |=(1<<PIND1);
}

void PortD_reset()
{
	PORTD = 0;
}
void delay()
{
	_delay_ms(5);	
}
void init_setup()
{
	PORTD =0;
	
}
void All_on()
{
	PORTD = 0xFF;
}
