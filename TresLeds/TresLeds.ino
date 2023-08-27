/*

Projeto Três Leds

objetivo: Acender 3 leds gradualmente um por vez

material:
- 3 Leds (vermelho, verde e azul, por exemplo)
- 1 arduino Uno
- 1 protoboard
- 3 resistores de 330 ohms ou superior

nome dos leds no circuito
led vermelho = red
led verde = green
led azul = blue

*/

#define red 11
#define green 10
#define blue 9

const int minBrilho = 0;
int const maxBrilho = 255;
int brilho; 

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);

  acenderTodas();
  delay(2000);
  apagarTodas();
  Serial.println("Sistema inicializado com sucesso!");
}

void loop() {
  led_red();
  delay(2000);
  apagarTodas();

}

void acenderTodas(){
  digitalWrite(red, HIGH);
  digitalWrite(green, HIGH);
  digitalWrite(blue, HIGH);
}

void apagarTodas(){
  digitalWrite(red, LOW);
  digitalWrite(green, LOW);
  digitalWrite(blue, LOW);
}

void led_red(){
  Serial.println("ACENDENDO LED VERMELHO! ");
  for(int brilho=0; brilho <= maxBrilho; brilho++){
    analogWrite(red, brilho);
    delay(100);
  }
  Serial.println("LED VERMELHO ACESSO!");
}