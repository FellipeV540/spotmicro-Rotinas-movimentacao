#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

#define MOTORc 7
#define MOTORo 11

// --- AJUSTE ESTES DOIS ---
int MEU_ZERO = 366;   // ponto morto encontrado
int TEMPO_180 = 1000;  // Tempo para meia volta

void setup() {
  Serial.begin(9600); // Inicia a conversa com o computador
  pwm.begin();
  pwm.setPWMFreq(60);
  
  Serial.println("--- SpotMicro: Teste de Direcao ---");
  pwm.setPWM(MOTORc, 0, MEU_ZERO); // Começa parado
  pwm.setPWM(MOTORo, 0, MEU_ZERO); // Começa parado
}

void loop() {
  // 1. VAI (Sentido horario)
  Serial.print(">>> VAI ombro (Valor: 210) | Sentido: Anti Horario ");
  pwm.setPWM(MOTORo, 0, 310); 
  delay(500);
  //Serial.println(" | PARADO");
  pwm.setPWM(MOTORo, 0, 361);

  Serial.print(">>> VAI joelho (Valor: 210) | Sentido: Horario ");
  pwm.setPWM(MOTORc, 0, 300); 
  delay(TEMPO_180);
  Serial.println(" | PARADO");
  pwm.setPWM(MOTORc, 0, MEU_ZERO);
  
  delay(2000);

  // 2. VOLTA (Sentido B)
  Serial.print("<<< VOLTA ombro (Valor: 522) | Sentido: horario ");
  pwm.setPWM(MOTORo, 0, 430); // Usei 522 para equilibrar a velocidade com o 210
  delay(TEMPO_180);
  Serial.println(" | PARADO");
  pwm.setPWM(MOTORo, 0, 374); 

  Serial.print("<<< VOLTA joelho (Valor: 522) | Sentido: Anti-horario ");
  pwm.setPWM(MOTORc, 0, 412); // Usei 522 para equilibrar a velocidade com o 210
  delay(TEMPO_180);
  Serial.println(" | PARADO");
  pwm.setPWM(MOTORc, 0, MEU_ZERO); 
  
  delay(2000);
}
