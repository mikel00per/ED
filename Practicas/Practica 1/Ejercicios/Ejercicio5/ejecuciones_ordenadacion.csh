#!/bin/csh
@ inicio = 100
@ fin = 2000000
@ incremento = 500
set ejecutable = ordenacion-mod
set salida = tiempos_operacion_desordenado.dat

@ i = $inicio
echo > $salida
while ( $i <= $fin )
  echo Ejecución tam = $i
  echo `./{$ejecutable} $i 1000000` >> $salida
  @ i += $incremento
end
