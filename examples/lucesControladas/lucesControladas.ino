/*
 * Luces del coche fantastico.
 * 
 * En este ejemplo se va a realizar la secuencia de luces del coche fantástico. Para ello hay
 * que montar el siguiente circuito:
 * 
 * D0 -> Led1
 * D1 -> Led2
 * D3 -> Led3
 * D4 -> Led4
 * D5 -> Led5
 * D6 -> Led6
 * D7 -> Led7
 * Pulsador conectado a A0 y GND.
 * 
 * Con el botón Paramos la secuencia.
 */

#include <SimpleSequencer.h>
#include <BotonSimple.h>

SimpleSequencer luces(14);
BotonSimple boton(A0);

void setup() {
  // Accedemos directamente al registro de direcciones de entradas/salidas, indicando que en el 
  // puerto D sean todos los pines de salida. Sería equivalente a escribir la llamada a pinMode 
  // de cada uno de los pines D0 a D7.
  DDRD = 0xff;

  // Creamos la secuencia. Para no crear un función de llamada para cada paso se ha utilizado
  // una función Lambda. Igualmente no se ha llamado a la funcion digitalWrite para cada pin,
  // reduciendo notablemente el código.
  luces.setStep( 0, 100, []() { PORTD = 0x01; } );
  luces.setStep( 1, 100, []() { PORTD = 0x02; } );
  luces.setStep( 2, 100, []() { PORTD = 0x04; } );
  luces.setStep( 3, 100, []() { PORTD = 0x08; } );
  luces.setStep( 4, 100, []() { PORTD = 0x10; } );
  luces.setStep( 5, 100, []() { PORTD = 0x20; } );
  luces.setStep( 6, 100, []() { PORTD = 0x40; } );
  luces.setStep( 7, 100, []() { PORTD = 0x80; } );
  luces.setStep( 8, 100, []() { PORTD = 0x40; } );
  luces.setStep( 9, 100, []() { PORTD = 0x20; } );
  luces.setStep(10, 100, []() { PORTD = 0x10; } );
  luces.setStep(11, 100, []() { PORTD = 0x08; } );
  luces.setStep(12, 100, []() { PORTD = 0x04; } );
  luces.setStep(13, 100, []() { PORTD = 0x02; } );

  // Para que no se quede encendia una luz usamos la función onStop de la clase, apagando
  // el led.
  luces.setOnStop( []() { PORTD = 0x00; } );
}

void loop() {
  luces.update();     // Actualizamos la secuencia.
  boton.actualizar(); // Leemos el botón.

  // Comprobamos si hemos soltado el botón el estado de la secuencia y la iniciamos o paramos
  // según convenga.
  if ( boton.leer()==SOLTANDOLO ) {
    if ( luces.isRunning() ) 
      luces.stop();
    else
      luces.start();
  }
}
