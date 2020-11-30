/* ----------------------------------------------------------------------------
    Redondear una float o una double

    Autor:    Tony Diana
    Versión:  20.11
    Licencia: (CC BY-NC-SA 4.0)

    https://github.com/TonyDiana/LibreriasINO

   ----------------------------------------------------------------------------
*/

#ifndef FTD_Redondear_h
#define FTD_Redondear_h

namespace FTD_Redondear {    // --- Espacio de nombres propio

  // --- Redondea un valor a una cantidad 'x' de decimales
  float redondear(float valor, int decimales) {
    double _potencia = pow(10, decimales);
    return (roundf(valor * _potencia) / _potencia);
  };

}   // --- Espacio de nombres propio

#endif