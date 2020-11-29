/* ----------------------------------------------------------------------------
    Potencia de un número

    Autor:    Tony Diana
    Versión:  20.11
    Licencia: (CC BY-NC-SA 4.0)

    Consume menos tiempo/máquina que pow, pero NO FUNCIONA CUANDO hay decimales
    en la base y mucho menos en el exponente, además su resultado debe
    redondearse a '0' antes de utilizarse
   ----------------------------------------------------------------------------
*/

#ifndef FTD_Potencia_h
#define FTD_Potencia_h

namespace FTD_Potencia {    // --- Espacio de nombres propio

  float potencia(float base, int exponente) {
    double _ret = 1.0;

    // --- Si hay exponente, haremos multiplicaciones sucesivas
    if (exponente != 0) { for (int i=0; i < exponente; i++) { _ret *= base; } }
    return _ret;
  }

}  // --- Espacio de nombres propio

#endif
