#!/bin/csh
@ inicio = 10000
@ fin = 500000000
@ incremento = 500000
set ejecutable = ejercicio_desc
set salida = tiempos_operacion.dat

@ i = $inicio
echo > $salida
while ( $i <= $fin )
  echo Ejecución tam = $i
  echo `./{$ejecutable} $i 100000` >> $salida
  @ i += $incremento
end
