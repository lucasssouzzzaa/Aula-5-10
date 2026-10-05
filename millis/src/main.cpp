#include <Arduino.h>
#include <Bounce2.h>

// #define pinLed 4

// bool estadoLed = 0;

// unsigned long tempoAnterior = 0;
// unsigned long intervalo = 500 ;

// void setup() {
//   pinMode(pinLed, OUTPUT);
// }

// void loop() {
//   unsigned long tempoAtual = millis();

//   if (tempoAtual - tempoAnterior >= intervalo) {
//     estadoLed = !estadoLed;

//     tempoAnterior = tempoAtual;
//   }
//   digitalWrite(pinLed, estadoLed);

// Ex 1: Piscar 2 LEDs de forma alternada

// const int pinLed1_Ex1 = 5;
// const int pinLed2_Ex1 = 21;
// const unsigned long intervaloEx1 = 500;

// void setupEx1() {
//   pinMode(pinLed1_Ex1, OUTPUT);
//   pinMode(pinLed2_Ex1, OUTPUT);
//   digitalWrite(pinLed1_Ex1, HIGH);
//   digitalWrite(pinLed2_Ex1, LOW);
// }

// void loopEx1() {
//   static unsigned long tempoAnterior = 0;
//   static bool estado = true;
//   unsigned long tempoAtual = millis();

//   if (tempoAtual - tempoAnterior >= intervaloEx1) {
//     tempoAnterior = tempoAtual;
//     estado = !estado;
//     digitalWrite(pinLed1_Ex1, estado);
//     digitalWrite(pinLed2_Ex1, !estado);
//   }
// }

// Ex 2: Piscar 2 LEDs com tempos diferentes (500ms e 2000ms)

// const int pinLed1_Ex2 = 21;
// const int pinLed2_Ex2 = 5;

// void setupEx2() {
//   pinMode(pinLed1_Ex2, OUTPUT);
//   pinMode(pinLed2_Ex2, OUTPUT);
// }

// void loopEx2() {
//   unsigned long tempoAtual = millis();

//   static bool estadoLed1 = false;
//   static bool estadoLed2 = false;
//   static unsigned long tempoAnterior1 = 0;
//   static unsigned long tempoAnterior2 = 0;

//   if (tempoAtual - tempoAnterior1 >= 500) {
//     tempoAnterior1 = tempoAtual;
//     estadoLed1 = !estadoLed1;
//     digitalWrite(pinLed1_Ex2, estadoLed1);
//   }

//   if (tempoAtual - tempoAnterior2 >= 2000) {
//     tempoAnterior2 = tempoAtual;
//     estadoLed2 = !estadoLed2;
//     digitalWrite(pinLed2_Ex2, estadoLed2);
//   }
// }

// Ex 3: Mensagem no Serial a cada 2s

// void setupEx3() {
//   Serial.begin(9600);
// }

// void loopEx3() {
//   static unsigned long tempoAnterior = 0;
//   unsigned long tempoAtual = millis();

//   if (tempoAtual - tempoAnterior >= 2000) {
//     tempoAnterior = tempoAtual;
//     Serial.println("Mensagem a cada 2 segundos");
//   }
// }

// Ex 4: Botão temporizado liga LED ao pressionar e apaga após 3s

// const int pinBotao_Ex4 = 23;
// const int pinLed_Ex4 = 5;

// Bounce2::Button botaoEx4 = Bounce2::Button();

// void setupEx4() {
//   // Configura o botão com Bounce2 (usa INPUT_PULLUP por padrão e debounce de 5ms)
//   botaoEx4.attach(pinBotao_Ex4, INPUT_PULLUP);
//   botaoEx4.interval(5);
//   botaoEx4.setPressedState(LOW);

//   pinMode(pinLed_Ex4, OUTPUT);
// }

// void loopEx4() {
//   botaoEx4.update(); // Atualiza a leitura do botão

//   static unsigned long tempoAnterior = 0;
//   unsigned long tempoAtual = millis();

//   // Aciona ao pressionar o botão (com debounce)
//   if (botaoEx4.pressed()) {
//     digitalWrite(pinLed_Ex4, HIGH);
//     tempoAnterior = tempoAtual;
//   }

//   if (tempoAtual - tempoAnterior >= 3000) {
//     digitalWrite(pinLed_Ex4, LOW);
//   }
// }

// Ex 5: Semáforo que cada LED acende por 5s e apaga por 1s infinitamente

const int pinLedVermelho = 5;
const int pinLedAmarelo = 21;
const int pinLedVerde = 22;

unsigned long tempoAntVm = 0;
unsigned long tempoAntAm = 0;
unsigned long tempoAntVd = 0;
unsigned long tempoAtual;
const int intervaloAm = 1000;
const int intervaloVm = 3000;
const int intervaloVd = 2000;

int fase = 1;

void setup()
{
  pinMode(pinLedAmarelo, OUTPUT);
  pinMode(pinLedVerde, OUTPUT);
  pinMode(pinLedVermelho, OUTPUT);
}

void loop()
{
  tempoAtual = millis();

  if (tempoAtual - tempoAntVm >= intervaloVm)
  {
    fase = 2;
    tempoAntVm = tempoAtual;
  }
  if (tempoAtual - tempoAntVd >= intervaloVd)
  {
    fase = 3;
  }
  if (tempoAtual - tempoAntAm >= intervaloAm)
  {
    fase = 1;
  }





  if (fase == 1)
  {
    /* code */
  }else if(fase == 2)
  {
    /* code */
  }
  
  
  


}