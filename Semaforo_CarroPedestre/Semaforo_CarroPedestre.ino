// C++ code

/*
  LISTA DE MATERIAIS
  1 Arduino Uno R3
  2 leds verdes
  2 leds vermelhos
  1 led amarelo
  5 resistores 220 ohms ou superior - normalmente eu uso resistores de 330 ohms
  jumpers para as conexões
  
*/

//	Declaração das variáveis do semáforo para os carros
int ledVerdeCarro = 2;
int ledAmareloCarro = 3;
int ledVermelhoCarro = 4;

//	Declaração das variáveis do semaforo para os pedestres
int ledVerdePedestre = 6;
int ledVermelhoPedestre = 7;

void setup(){
  pinMode(ledVerdeCarro, OUTPUT);
  pinMode(ledAmareloCarro, OUTPUT);
  pinMode(ledVermelhoCarro, OUTPUT);
  pinMode(ledVerdePedestre, OUTPUT);
  pinMode(ledVermelhoPedestre, OUTPUT);
}

void loop(){
  digitalWrite(ledVerdeCarro, HIGH);
  digitalWrite(ledVermelhoPedestre, HIGH);
  
  delay(5000);
    
  digitalWrite(ledVerdeCarro, LOW);
  digitalWrite(ledAmareloCarro, HIGH);
  
  delay(5000);
  
  digitalWrite(ledVermelhoPedestre, LOW);
  
  digitalWrite(ledAmareloCarro, LOW);
  digitalWrite(ledVermelhoCarro, HIGH);
  digitalWrite(ledVerdePedestre, HIGH);
  
  delay(5000);
  
  digitalWrite(ledVermelhoCarro, LOW);
  digitalWrite(ledVerdePedestre, LOW);
  digitalWrite(ledVerdeCarro, LOW);
}