# SimpleSequencer.

SimpleSequencer es una librería para Arduino para generar secuencias simples, del tipo apagado/encendido durante un tiempo.

Forma parte del tutorial [Una forma sencilla de realizar secuencias.](https://forum.arduino.cc/index.php?topic=676200.0) del foro de Arduino es español.

## Uso básico.

Crea un objeto de la clase SimpleSequencer indicando el número de pasos de la secuencia.

```c++
SimpleSequencer secuencia(numPasos);
```

Crear las funciones que se ejecutaran en cada paso. Deben ser del tipo void sin parametros:

```c++
void funcionPaso0() {

}
```

Añadir los pasos al objeto creado anteriormente indicando el número de paso, el tiempo, y la función que se ha de ejecutar en cada paso:

```c++
secuencia.setStep(paso0, tiempo0, funcion0);
secuencia.setStep(paso1, tiempo1, funcion1);
...
secuencia.setStep(pasoN, tiempoN, funcionN);
```
Iniciar la secuencia llamando a la función `start`. Podemos parar la secuencia llamando a la función `stop`.

Opcionalmente podemos realizar alguna acción al iniciar o parar la secuencia. Para ello contamos con las funciones `setOnStart` y  `setOnStop`.

