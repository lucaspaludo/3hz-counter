
#include <avr/io.h>
#include <avr/interrupt.h>

ISR(TIMER0_OVF_vect){
	
	TCNT0 = 100; //valor do registrador TCNT0 para reiniciar a contagem
	
	if((PINC&0b00000001)==0){
		PORTC |= (1<<PC0);
	}
	
	else{
		PORTC&=0b11111110;
	}
	
}

int main(void)
{
	DDRC = 0b00000001; //define o pino PC0 como saída
	TCCR0 = 0b00000101; //definir prescaler
	TCNT0 = 100; //definir valor do registrador TCNT0
	TIMSK |= 1; //habilita a interrupção do timer 0
	sei(); //habilita todas as interrupções
	
	while (1) {}
	
}

