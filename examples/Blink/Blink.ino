/*
 * Blink.ino
 * 
 * Ejecuta un parpadeo del led de la placa de arduino.
 */
#include <SimpleSequencer.h>

// Creamos el objeto de la secuencia. Tendrá dos pasos.
SimpleSequencer blink(2);

// Funcion que se ha de ejecutar en cada paso.
void cambiar() {
  digitalWrite(13, !digitalRead(13));
}

void setup() {
  pinMode(13, OUTPUT);
  // Creamos la secuencia indicando en cada paso su tiempo y la función
  // a ejecutar.
  blink.setStep(0, 1000, cambiar);
  blink.setStep(1, 1000, cambiar);
  // Iniciamos la secuencia.
  blink.start();
}

void loop() {
  // Actualizamos la secuencia.
  blink.update();

}
