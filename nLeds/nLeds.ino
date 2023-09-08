// PROJETO INICIALMENTE DESENVOLVIDO PARA TRÊS LEDS, MAS QUE COM PEQUENOS AJUSTES PODE SER UTILIZADO COM INFINITOS LEDS LIMITADO APENAS PELO NUMERO DE PORTAS PWM DO CONTROLADOR UTILLIZADO.
// LEMBRANDO QUE O ARDUINO UNO R3 POSSUI APENAS 6 PORTAS PWM NECESSÁRIAS PARA ESTE PROJETO

/*

Projeto Três Leds

objetivo: Acender leds gradualmente um por vez

material:
- Leds (vermelho, verde e azul, por exemplo)
- 1 arduino Uno R3
- 1 protoboard
- resistores de 330 ohms ou superior (UM RESISTOR PARA CADA LED DO CIRCUITO)

nome dos leds no circuito
led vermelho = CH1
led verde = CH2
led azul = CH3

*/

#define CH1 11 // LED VERMELHO
#define CH2 10 // LED VERDE
#define CH3 9 // LED AZUL

#define nLeds 3 // numero de leds no circuito
int Leds[] = {CH1, CH2, CH3}; // ATRIBUIÇÃO DOS LEDS DO CIRCUITO NO ARRAY RESPONSAVEL PELO LAÇO DE REPETIÇÃO A SER UTILIZADO NO CIRCUITO

const int minBrilho = 0;
int const maxBrilho = 255;
int brilho; 

void setup() {

  Serial.begin(9600);
  iniciarLeds();

  acenderTodas();
  delay(1000);
  apagarTodas();
  Serial.println("Sistema inicializado com sucesso!");
}

void loop() {

  acenderGradual();
  delay(3000);
  apagarGradual();
  delay(2000);

}

void iniciarLeds(){
  for(int i = 0; i < nLeds; i++){
    pinMode(Leds[i], OUTPUT);
  }
}

void acenderTodas(){
  for(int i=0; i<nLeds; i++){
    digitalWrite(Leds[i], HIGH);
  }
}

void apagarTodas(){
  for(int i=0; i<nLeds; i++){
    digitalWrite(Leds[i], LOW);
  }
}

void acenderGradual(){
  Serial.println("SISTEMA ACENDENDO GRADUALMENTE!");
  for(int i = 0; i < nLeds; i++){
    for(int brilho = minBrilho; brilho <= maxBrilho; brilho++){
      analogWrite(Leds[i], brilho);
      delay(10);
    }
  }
  Serial.println("SISTEMA TOTALMENTE ACESSO!");
}
void apagarGradual(){
  Serial.println("SISTEMA AGAPANDO GRADUALMENTE!");
  for(int i = 0; i < nLeds; i++){
    for(int brilho = maxBrilho; brilho >= minBrilho; brilho--){
      analogWrite(Leds[i], brilho);
      delay(10);
    }
  }
  Serial.println("SISTEMA TOTALMENTE APAGADO!");
}
