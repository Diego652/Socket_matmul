all:
	gcc -o cliente utils.c socket_cli.c
	gcc -o servidor utils.c socket_srv.c 
