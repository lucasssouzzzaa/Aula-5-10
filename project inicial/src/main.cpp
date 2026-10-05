#include <Arduino.h>
#include <Bounce2.h>

// Ex 1

// #include <Bounce2.h>

// const int PINO_BOTAO = 4;
// const int PINO_LED = 19;

// bool estadoLed = LOW;

// Bounce debouncer = Bounce();

// void setup() {
//   pinMode(PINO_LED, OUTPUT);
//   digitalWrite(PINO_LED, estadoLed);

//   pinMode(PINO_BOTAO, INPUT_PULLUP);

//   debouncer.attach(PINO_BOTAO);
//   debouncer.interval(25);
// }

// void loop() {
//   debouncer.update();

//   if (debouncer.fell()) {
//     estadoLed = !estadoLed;
//     digitalWrite(PINO_LED, estadoLed);
//   }
// }


// Ex 2

//  int led1 = 4;
//  int btn = 19;
  // int estadoBAnt = 1; 
  // int contador = 0; 
  // void setup() {
  //  pinMode(led1, OUTPUT);
  //  pinMode(btn, INPUT_PULLUP);

  //  Serial.begin(9600);
  // }

  // void loop() {
  //   int estadoBAtual = digitalRead(btn);

  //   if (estadoBAnt == 1 && estadoBAtual == 0) {
  //     contador++;

  //     Serial.println(contador);

  //     delay(50); 
  //   }

  //   estadoBAnt = estadoBAtual;
  // }

  // Ex 3

//   #include <Bounce2.h>

// // Definição dos pinos
// const int PINO_BOTAO = 4;
// const int PINO_LED   = 19;

// // Configuração de tempos (em milissegundos)
// const unsigned long TEMPO_PRESSIONADO = 800; // Tempo segurado para começar a piscar
// const unsigned long INTERVALO_PISCA  = 200; // Velocidade da piscada

// // Instância do objeto Bounce
// Bounce botao = Bounce();

// // Variáveis de controle de estado
// bool estadoLED = false;
// bool emModoPisca = false;

// unsigned long tempoInicioClique = 0;
// unsigned long ultimoPisca = 0;

// void setup() {
//   pinMode(PINO_LED, OUTPUT);
//   digitalWrite(PINO_LED, estadoLED);

//   // Configuração do botão com a biblioteca Bounce2
//   botao.attach(PINO_BOTAO, INPUT_PULLUP); // Pino do botão com resistor pull-up interno
//   botao.interval(25);                     // Tempo do debounce em milissegundos
// }

// void loop() {
//   // Atualiza a leitura do botão
//   botao.update();

//   unsigned long tempoAtual = millis();

//   // 1. Detecta o momento exato em que o botão é PRESSIONADO (pressionar = LOW devido ao INPUT_PULLUP)
//   if (botao.fell()) {
//     tempoInicioClique = tempoAtual;
//   }

//   // 2. Se o botão está mantido pressionado...
//   if (botao.read() == LOW) {
//     if ((tempoAtual - tempoInicioClique) >= TEMPO_PRESSIONADO) {
//       emModoPisca = true;
//     }
//   }

//   // 3. Detecta o momento em que o botão é SOLTO
//   if (botao.rose()) {
//     if (!emModoPisca) {
//       // Clique rápido: alterna o LED
//       estadoLED = !estadoLED;
//       digitalWrite(PINO_LED, estadoLED);
//     } else {
//       // Foi solto após piscar: sai do modo pisca e restaura o estado anterior do LED
//       emModoPisca = false;
//       digitalWrite(PINO_LED, estadoLED);
//     }
//   }

//   // 4. Executa o pisca-pisca se o modo pisca estiver ativo
//   if (emModoPisca) {
//     if (tempoAtual - ultimoPisca >= INTERVALO_PISCA) {
//       ultimoPisca = tempoAtual;
//       digitalWrite(PINO_LED, !digitalRead(PINO_LED)); // Inverte o estado atual do LED
//     }
//   }
// }

// Ex 4

// #include <Bounce2.h>

// const int PINO_BOTAO = 2;
// const int PINO_LED = 13;

// enum EstadoLED { OFF, ON, PISCANDO };
// EstadoLED estadoAtual = OFF;

// Bounce botao = Bounce();

// unsigned long tempoPressionado = 0;
// bool acaoPressionadoExecutada = false;

// unsigned long tempoAnteriorBlink = 0;
// const long intervaloBlink = 200;
// bool estadoLEDTemp = LOW;

// void setup() {
//   botao.attach(PINO_BOTAO, INPUT_PULLUP);
//   botao.interval(25);

//   pinMode(PINO_LED, OUTPUT);
//   digitalWrite(PINO_LED, LOW);
// }

// void loop() {
//   botao.update();
//   unsigned long tempoAtual = millis();

//   if (botao.fell()) {
//     tempoPressionado = tempoAtual;
//     acaoPressionadoExecutada = false;
//   }

//   if (botao.read() == LOW) {
//     if ((tempoAtual - tempoPressionado >= 2000) && !acaoPressionadoExecutada) {
//       estadoAtual = PISCANDO;
//       acaoPressionadoExecutada = true;
//     }
//   }

//   if (botao.rose()) {
//     if (!acaoPressionadoExecutada) {
//       if (estadoAtual == PISCANDO) {
//         estadoAtual = OFF;
//       } else if (estadoAtual == OFF) {
//         estadoAtual = ON;
//       } else if (estadoAtual == ON) {
//         estadoAtual = OFF;
//       }
//     }
//   }

//   switch (estadoAtual) {
//     case OFF:
//       digitalWrite(PINO_LED, LOW);
//       break;

//     case ON:
//       digitalWrite(PINO_LED, HIGH);
//       break;

//     case PISCANDO:
//       if (tempoAtual - tempoAnteriorBlink >= intervaloBlink) {
//         tempoAnteriorBlink = tempoAtual;
//         estadoLEDTemp = !estadoLEDTemp;
//         digitalWrite(PINO_LED, estadoLEDTemp);
//       }
//       break;
//   }
// }