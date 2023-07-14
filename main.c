#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

void external(){
	EIMSK|=(1<<INT0)|(1<<INT1)|(1<<INT2);
	EICRA|=(1<<ISC00);
	MCUCR|=(1<<IVCE);
	sei();
}

void pwm(void){
	TCCR0A|=(1<<WGM00)|(1<<WGM02)|(1<<COM0A1)|(1<<CS00);
	TCCR0B|=(1<<CS00);

}
//
ISR(INT0_vect){
	PORTC=0b00001001;
	_delay_ms(70);
	PORTC=0b00000000;
}
ISR(INT1_vect){
	PORTE^=(1<<7);
	_delay_ms(100);
	PORTE^=(1<<7);
}
ISR(INT2_vect){
	PORTC=0b00000110;
	_delay_ms(70);
	PORTC=0b00000000;
}

int main(void)
{
	pwm();
	external();

	DDRB=0xff;
	DDRC=0xff;
    DDRE=0xff;
    DDRD=0x00;
	DDRF=0x00;
	DDRG=0x00;

	int a[10],counter=0,k,x;
	a[0]=0b00111111; //0
	a[1]=0b00000110; //1
	a[2]=0b01011011; //2
	a[3]=0b01001111; //3
	a[4]=0b01100110; //4
	a[5]=0b01101101; //5
	a[6]=0b01111101; //6
	a[7]=0b00000111; //7
	a[8]=0b01111111; //8
	a[9]=0b01101111; //9

    while (1){
		if(!(PINF&0x1)){
			k=1;
			if(k>counter){
				PORTB=0b00000101;
				for(int i=counter;i<=k;i++){
					_delay_ms(40);
					PORTE=a[i];
					counter++;
				}
				PORTB=0b00000000;

				PORTC=0b00001001;
				_delay_ms(70);
				PORTC=0b00000110;
				_delay_ms(70);
				PORTC=0b00000000;
				counter--;
			}
			else{
				PORTB=0b00001010;
				for(int i=counter;i>=k;i--){
					_delay_ms(40);
					PORTE=a[i];
					counter--;
				}
				PORTB=0b00000000;
				PORTC=0b00001001;
				_delay_ms(70);
				PORTC=0b00000110;
				_delay_ms(70);
				PORTC=0b00000000;
				counter++;

			}
		}
		if(!(PINF&0x2)){
			k=2;
			x=0;
			if(k>counter){
					PORTB=0b00000101;
					for(int i=counter;i<=k;i++){
						_delay_ms(40);
						PORTE=a[i];
						counter++;
					}
					PORTB=0b00000000;
					PORTC=0b00001001;
					_delay_ms(70);
					PORTC=0b00000110;
					_delay_ms(70);
					PORTC=0b00000000;
					counter--;
				}
				else{
					PORTB=0b00001010;
					for(int i=counter;i>=k;i--){
						_delay_ms(40);
						PORTE=a[i];
						counter--;
					}
					PORTB=0b00000000;
					while(OCR0A!=255){
						OCR0A=x;
						_delay_us(200);
						x++;
					}
					while(OCR0A!=0){
						OCR0A=x;
						_delay_us(200);
						x--;
					}
					PORTC=0b00001001;
					_delay_ms(70);
					PORTC=0b00000110;
					_delay_ms(70);
					PORTC=0b00000000;
					counter++;

				}
		}
		if(!(PINF&0x4)){
			k=3;
			if(k>counter){
				PORTB=0b00000101;
				for(int i=counter;i<=k;i++){
					_delay_ms(40);
					PORTE=a[i];
					counter++;
				}
				PORTB=0b00000000;
				PORTC=0b00001001;
				_delay_ms(70);
				PORTC=0b00000110;
				_delay_ms(70);
				PORTC=0b00000000;
				counter--;
			}
			else{
				PORTB=0b00001010;
				for(int i=counter;i>=k;i--){
					_delay_ms(40);
					PORTE=a[i];
					counter--;
				}
				PORTB=0b00000000;
				PORTC=0b00001001;
				_delay_ms(70);
				PORTC=0b00000110;
				_delay_ms(70);
				PORTC=0b00000000;
				counter++;

			}
		}
		if(!(PINF&0x8)){
			k=4;
			if(k>counter){
				PORTB=0b00000101;
				for(int i=counter;i<=k;i++){
					_delay_ms(40);
					PORTE=a[i];
					counter++;
				}
				PORTB=0b00000000;
				PORTC=0b00001001;
				_delay_ms(70);
				PORTC=0b00000110;
				_delay_ms(70);
				PORTC=0b00000000;
				counter--;
			}
			else{
				PORTB=0b00001010;
				for(int i=counter;i>=k;i--){
					_delay_ms(40);
					PORTE=a[i];
					counter--;
				}
				PORTB=0b00000000;
				PORTC=0b00001001;
				_delay_ms(70);
				PORTC=0b00000110;
				_delay_ms(70);
				PORTC=0b00000000;
				counter++;

			}
		}
		if(!(PINF&0x10)){
			k=5;
			if(k>counter){
				PORTB=0b00000101;
				for(int i=counter;i<=k;i++){
					_delay_ms(40);
					PORTE=a[i];
					counter++;
				}
				PORTB=0b00000000;
				PORTC=0b00001001;
				_delay_ms(70);
				PORTC=0b00000110;
				_delay_ms(70);
				PORTC=0b00000000;
				counter--;
			}
			else{
				PORTB=0b00001010;
				for(int i=counter;i>=k;i--){
					_delay_ms(40);
					PORTE=a[i];
					counter--;
				}
				PORTB=0b00000000;
				PORTC=0b00001001;
				_delay_ms(70);
				PORTC=0b00000110;
				_delay_ms(70);
				PORTC=0b00000000;
				counter++;

			}
		}
		if(!(PINF&0x20)){
			k=6;
			if(k>counter){
				PORTB=0b00000101;
				for(int i=counter;i<=k;i++){
					_delay_ms(40);
					PORTE=a[i];
					counter++;
				}
				PORTB=0b00000000;
				PORTC=0b00001001;
				_delay_ms(70);
				PORTC=0b00000110;
				_delay_ms(70);
				PORTC=0b00000000;
				counter--;
			}
			else{
				PORTB=0b00001010;
				for(int i=counter;i>=k;i--){
					_delay_ms(40);
					PORTE=a[i];
					counter--;
				}
				PORTB=0b00000000;
				PORTC=0b00001001;
				_delay_ms(70);
				PORTC=0b00000110;
				_delay_ms(70);
				PORTC=0b00000000;
				counter++;

			}
		}
		if(!(PINF&0x40)){
			k=7;
			if(k>counter){
				PORTB=0b00000101;
				for(int i=counter;i<=k;i++){
					_delay_ms(40);
					PORTE=a[i];
					counter++;
				}
				PORTB=0b00000000;
				PORTC=0b00001001;
				_delay_ms(70);
				PORTC=0b00000110;
				_delay_ms(70);
				PORTC=0b00000000;
				counter--;
			}
			else{
				PORTB=0b00001010;
				for(int i=counter;i>=k;i--){
					_delay_ms(40);
					PORTE=a[i];
					counter--;
				}
				PORTB=0b00000000;
				PORTC=0b00001001;
				_delay_ms(70);
				PORTC=0b00000110;
				_delay_ms(70);
				PORTC=0b00000000;
				counter++;

			}
		}
		if(!(PINF&0x80)){
			k=8;
			if(k>counter){
				PORTB=0b00000101;
				for(int i=counter;i<=k;i++){
					_delay_ms(40);
					PORTE=a[i];
					counter++;
				}
				PORTB=0b00000000;
				PORTC=0b00001001;
				_delay_ms(70);
				PORTC=0b00000110;
				_delay_ms(70);
				PORTC=0b00000000;
				counter--;
			}
			else{
				PORTB=0b00001010;
				for(int i=counter;i>=k;i--){
					_delay_ms(40);
					PORTE=a[i];
					counter--;
				}
				PORTB=0b00000000;
				PORTC=0b00001001;
				_delay_ms(70);
				PORTC=0b00000110;
				_delay_ms(70);
				PORTC=0b00000000;
				counter++;

			}
		}
		if(!(PING&0x1)){
			k=9;
			if(k>counter){
				PORTB=0b00000101;
				for(int i=counter;i<=k;i++){
					_delay_ms(40);
					PORTE=a[i];
					counter++;
				}
				PORTB=0b00000000;
				PORTC=0b00001001;
				_delay_ms(70);
				PORTC=0b00000110;
				_delay_ms(70);
				PORTC=0b00000000;
				counter--;
			}
			else{
				PORTB=0b00001010;
				for(int i=counter;i>=k;i--){
					_delay_ms(40);
					PORTE=a[i];
					counter--;
				}
				PORTB=0b00000000;
				PORTC=0b00001001;
				_delay_ms(70);
				PORTC=0b00000110;
				_delay_ms(70);
				PORTC=0b00000000;
				counter++;

			}
		}
		if(!(PIND&0x1)){

		}
		if(!(PIND&0x2)){

		}
		if(!(PIND&0x4)){

		}
    }
}
