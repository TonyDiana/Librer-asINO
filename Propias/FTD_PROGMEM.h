/* ----------------------------------------------------------------------------
    Manejo de PROGMEM, extración genérica de información de forma unificada

    Autor:    Tony Diana
    Versión:  20.11
    Licencia: (CC BY-NC-SA 4.0)
   ----------------------------------------------------------------------------
*/

#ifndef FTD_PROGMEM_h
#define FTD_PROGMEM_h

namespace FTD_PROGMEM {    // --- Espacio de nombres propio

  // --- Extractor genérico de PROGMEM
  String extraerPROGMEM( const char* const TABLA[], int INDICE, byte LEN=20) {

    // --- Determinar el tamaño del String receptor
    byte _len = LEN;

    // --- Eliminar la posibilidad de tamaño 0 (algún despiste)
    if ( !LEN ) { _len = 20; }

    // --- Por si se han olvidado de aumentar al tamaño el carácter `\0`
    _len ++;

    // --- Array extractor
    char _temp[LEN];

    // --- Instrucción incomprensible
    strcpy_P( _temp, (char *)pgm_read_word( &( TABLA[ INDICE ] )
                                          )
            );

    // --- Y fin de la historia
    return _temp;
  } ;

}   // --- Espacio de nombres propio

#endif