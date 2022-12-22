# Quilodran - Guzman - Hinrichs

Si se desea ejecutar en distintos computadores
cerciorarse de estar conectados en la misma red.

En terminal

make
./servidor
./cliente <n> <ip-servidor>

se probo con matrices de hasta 25x25.

Si ejecuta el servidor y luego interrupme el proceso
con ctrl+c, es posible que al ejecutar de nuevo el cliente
arroje "Error en connect: connection refused".
No pudimos solucionar ese problema.

En macOS eliminar el header "#include <linux/in.h>"
de cliente.c y servidor.c
