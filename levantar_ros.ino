Codigo postando para o ros
`#include <ros.h>
#include <std_msgs/Int16.h> // Biblioteca para enviar números inteiros
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

// --- CONFIGURAÇÃO ROS ---
ros::NodeHandle nh;
std_msgs::Int16 msg_angulo;
ros::Publisher pub_angulo("angulo_joelho", &msg_angulo); // Tópico agora chama "angulo_joelho"

// --- CONFIGURAÇÃO HARDWARE ---
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

// =======================================================
// ⬇️ ÁREA DE CALIBRAÇÃO (ALTERE ESTES VALORES PARA TESTAR) ⬇️
// =======================================================
#define SERVO_PINO 11          // Pino do motor (Joelho = 7)
#define TESTE_VALOR 430       // Velocidade do giro
#define TESTE_TEMPO 1000      // Tempo em milissegundos
#define ANGULO_ESPERADO 60   // O ângulo que o ROS vai registrar
#define SERVOSTOP 370         // Ponto morto do meu servo
// =======================================================

void setup() {
  pwm.begin();
  pwm.setPWMFreq(60);
  
  // Inicializa o nó ROS e o publicador
  nh.initNode();
  nh.advertise(pub_angulo);
  
  // Aguarda a conexão com o roscore (VM Ubuntu) antes de começar
  while (!nh.connected()) {
    nh.spinOnce();
    delay(10);
  }
  
  delay(500); // Pausa de segurança

  // 1. Inicia o movimento físico
  pwm.setPWM(SERVO_PINO, 0, TESTE_VALOR);
  
  // 2. Espera o tempo mapeado para atingir o ângulo
  delay(TESTE_TEMPO);

  // 3. Para o motor fisicamente
  pwm.setPWM(SERVO_PINO, 0, SERVOSTOP);

  // 4. Avisa o ROS do resultado esperado
  msg_angulo.data = ANGULO_ESPERADO;
  pub_angulo.publish(&msg_angulo);
  nh.spinOnce(); // Despacha o pacote para o cabo USB
}

void loop() {
  nh.spinOnce(); // Mantém o Arduino vivo na rede ROS
  delay(10);
}`
