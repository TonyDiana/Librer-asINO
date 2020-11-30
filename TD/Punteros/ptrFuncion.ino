/*
 --- punteros a funciones (https://forum.arduino.cc/index.php?topic=84682.0)
 */

#include <Arduino.h>

class objeto {
  public:
    void imprimirAlgo() { Serial.println("Imprimiré algo"); };
};

// --- Yo no hago nada
void nadaDeNada() { Serial.println("YO NO HAGO NADA"); }


// --- Yo soy una función que enciendo el led del Arduino
void encenderLed() { digitalWrite(13, HIGH); }

// --- Yo soy una función que apago el led del Arduino
void apagarLed() { digitalWrite(13, LOW); }

// --- Yo soy una función que imprimo hola por el serial
void decirHola() { Serial.println("HOLA COCACOLA"); }

// --- Yo soy una función que imprimo presto por el serial
void decirPresto() { Serial.println("PRESTO PICCOLO BAMBINO"); }

// --- Yo soy una función que hago tonterías
void tonteria() { Serial.println("--  ESTOY HACIENDO TONTERIAS --"); }


// --- YO EJECUTO LO QUE ME ECHEN ENCIMA
void ejecutador( void( *queHago )() ) { ( *queHago )(); }


// --- byte, que la memoria está muy cara
byte veces=0;

// --- Un puntero ABSTRACTO A UNA FUNCION, NI IDEA DE CUAL, Global
void ( *noSeLoQueSoy_GLOBAL )();


// --- Instanciemos el objeto
objeto cosa;



// --- Preparemos el escenario
void setup() {
    pinMode(13, OUTPUT);
    Serial.begin(9600);

   // --- Si, ya sé que es una tontería
   veces = 0;
}


// --- ¡¡ VAMOS A VER QUE PASA !!

void loop() {

   // --- Vamos a contar las veces que damos vueltas
   veces ++;

   Serial.println();Serial.println();Serial.println();
   Serial.println( "HOLA ARDUINERO, soy el ciclo " + String(veces) );


   // --- Un puntero ABSTRACTO A UNA FUNCION, NI IDEA DE CUAL, local
   void static (* noSeLoQueSoy_LOCAL)();


   /* --- Aquí ocurren un montón de cosas complicadas que no las entiende ni el
          que las programó, pero que funcionan
    */

   if (veces == 1) {
      noSeLoQueSoy_GLOBAL = decirHola;
      noSeLoQueSoy_LOCAL  = encenderLed;
   }

   /* --- Aquí ocurren un montón de cosas que pueden modificar el valor de veces
          no importa por qué, pero supongamos que ocurre, o incluso cambiar el
          puntero
    */

   if (veces == 2) {
      noSeLoQueSoy_GLOBAL = decirPresto;
      noSeLoQueSoy_LOCAL  = apagarLed;
   }

   /* --- Aquí ocurren otro montón de cosas que pueden modificar el valor de
          veces o vete tu a saber
    */

   if (veces == 3) {
      noSeLoQueSoy_GLOBAL = tonteria;
      noSeLoQueSoy_LOCAL  = encenderLed;
   }

   /* --- Más cosas raras
    */

   if (veces == 4) {
      noSeLoQueSoy_GLOBAL = decirPresto;
      noSeLoQueSoy_LOCAL  = apagarLed;
   }

   /* --- Más cosas raras
    */

   if (veces == 5) {
      noSeLoQueSoy_GLOBAL = decirHola;
      noSeLoQueSoy_LOCAL  = encenderLed;
   }

   /* --- Más cosas Más raras
    */

   if (veces == 6) {
      noSeLoQueSoy_GLOBAL = decirPresto;
      noSeLoQueSoy_LOCAL  = apagarLed;
   }

   /* --- MUCHAS Más cosas Más raras
    */

   if (veces == 7) {
      noSeLoQueSoy_GLOBAL = tonteria;
   }

   if (veces == 8) {
      noSeLoQueSoy_LOCAL  = apagarLed;
   }


   /* --- Por cierto ¿Piensas que cuando veces > 7 no pasará nada? JEJEJEJE
    */



   /* --- Pedazo de código más largo que el quijote
    */


   /* --- Y ahora se sabe qué se tendría que hacer de ese montón de cosas
          posibles. ¿Miles de if endif?
    */

   // --- YO EJECUTO LO QUE ME ECHEN ENCIMA
   ejecutador( noSeLoQueSoy_GLOBAL );
   ejecutador( noSeLoQueSoy_LOCAL );


   // --- Aquí pongo un delay de esos que tanto les gusta a la comunidad Arduino
   delay(3000);


   // --- PREMIO SI AVERIGUAS POR QUÉ DESPUÉS DEL CICLO 7 NO SE APAGA EL LED
}
