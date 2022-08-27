#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);

#define pino_sinal_analogico A0
#define pino_led_vermelho 5
#define pino_led_amarelo 6
#define pino_led_verde 7

int valor_analogico;
void tom(char pino, int frequencia, int duracao);

void setup()
{
  Serial.begin(9600);
  pinMode(pino_sinal_analogico, INPUT);
  pinMode(pino_led_vermelho, OUTPUT);
  pinMode(pino_led_amarelo, OUTPUT);
  pinMode(pino_led_verde, OUTPUT);
  pinMode(10,OUTPUT);
}
 
void loop()
{ 
  
//LEDs + Sensor de umidade

  valor_analogico = analogRead(pino_sinal_analogico);
  Serial.print("Porta analogica: ");
  Serial.print(valor_analogico);
 
  if (valor_analogico > 0 && valor_analogico < 400){
    Serial.println(" Status: Solo umido");
    apagaleds();
    digitalWrite(pino_led_verde, HIGH);}
 
  if (valor_analogico > 400 && valor_analogico < 800){
    Serial.println(" Status: Umidade moderada");
    apagaleds();
    digitalWrite(pino_led_amarelo, HIGH);}
 
  if (valor_analogico > 800 && valor_analogico < 1024){
    Serial.println(" Status: Solo seco");
    apagaleds();
    digitalWrite(pino_led_vermelho, HIGH);}
  delay(100);
  
//LCD

  lcd.init();
  lcd.setBacklight(HIGH);
  lcd.setCursor(0,0);

  if (valor_analogico > 800 && valor_analogico < 1024){
  lcd.print("Solo seco");}

  if (valor_analogico > 400 && valor_analogico < 800){
  lcd.print("Umidade media");}

  if (valor_analogico > 0 && valor_analogico < 400){
  lcd.print("Solo umido");}
  
//Buzzer

  if (valor_analogico > 0 && valor_analogico < 400){
 
  delay(1000);
  int tempo = 400;
  tom(10,440,tempo); //LA
  delay(tempo);
  tom(10,294,tempo); //RE
  delay(tempo);
  tom(10,349,tempo/2); //FA
  delay(tempo/2);
  tom(10,392,tempo/2); //SOL
  delay(tempo/2);
  tom(10,440,tempo); //LA
  delay(tempo);
  tom(10,294,tempo); //RE
  delay(tempo);
  tom(10,349,tempo/2); //FA
  delay(tempo/2);
  tom(10,392,tempo/2); //SOL
  delay(tempo/2);
  tom(10,330,tempo); //MI
  delay(tempo);}
}

void tom(char pino, int frequencia, int duracao){
  float periodo = 1000.0/frequencia; //Periodo em ms
  for (int i = 0; i< duracao/(periodo);i++){ //Executa a rotina de dentro o tanta de vezes que a frequencia desejada cabe dentro da duracao
    digitalWrite(pino,HIGH);
    delayMicroseconds(periodo*500); //Metade do periodo em ms
    digitalWrite(pino, LOW);
    delayMicroseconds(periodo*500);
  }s
}

//LEDs + Sensor de umidade

void apagaleds()
{
  digitalWrite(pino_led_vermelho, LOW);
  digitalWrite(pino_led_amarelo, LOW);
  digitalWrite(pino_led_verde, LOW);
}
