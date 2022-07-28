//Conversor Inversor 12V |-3.3V/80mA
//Eng. Danuzio Alves / Engenharia entendida
#include <PWM.h>                          //Biblioteca para o pwm   
#define pwm0 10                           //Pino de saída do pwm 1
int32_t frequency = 50000;                //Frequência em Hertz
int Duty0 = 80;                           //Variável que armazena o valor do Duty Cycle inicial   
int FeedBack = 0;                         //Variável que armazena o valor de feedback
//===================Setup===========================================================================================================================================//
void setup() {
InitTimersSafe();                         //Configura os registadores do Atmega para uma frequência maior
SetPinFrequencySafe(pwm0, frequency);     //Configura a frequência no pino de saída 1
}
//===================Loop============================================================================================================================================//
void loop() { 
  FeedBack=analogRead(A0);                //FeedBack da entrada
  delay(50);                              //Delay para estabilizar
   if(FeedBack<610){                      //Se saída menor que 3.3V...
    Duty0++;                              //Incrementa o Duty0.
  }
  if(FeedBack>680){                       //Se saída maior que 3.3V...
    Duty0--;                              //decrementa o Duty0.
  }                          
  pwmWrite(pwm0,Duty0);                   //Envia o valor para o pino pwm

 
}

