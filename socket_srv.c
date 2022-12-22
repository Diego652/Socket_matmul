#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <linux/in.h>
#include <string.h>
#include <unistd.h>
#include "utils.h"

int main(void)
{
	int sd, sc;
	int size;
	int num[1];

	int N;
	struct sockaddr_in server_addr,  client_addr;
	sd =  socket(AF_INET, SOCK_STREAM, 0);

	/* asigna la direcci�n al socket */
	bzero((char *)&server_addr, sizeof(server_addr));
	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = INADDR_ANY;	
	server_addr.sin_port = htons(4200);
	bind(sd, (struct sockaddr *)&server_addr, sizeof(server_addr));

	listen(sd, 5);
	size = sizeof(client_addr);

	while (1)
	{
		printf("\nEsperando conexion...\n");
		sc = accept(sd, (struct sockaddr *)&client_addr, (socklen_t*)&size);
		if (sc < 0)
			break;

		// RECIBE EL TAMANIO DE LAS MATRICES
		read(sc, (char *) num, 1 *sizeof(int)); 
		N = num[0];

		printf("\nn: %d \n\n",N);

		float A[N][N], B[N][N], C[N][N];
		// RECIBE A Y B
		read(sc, (char *) A, (N*N) *sizeof(float)); 
		read(sc, (char *) B, (N*N) *sizeof(float));
		// CALCULA C
		matrizMul(N,A,B,C);
		display(N,A,B);
		//ENVIA C
		write(sc, (char *) C, (N*N) *sizeof(float));

		close(sc);
    }

	printf("Error en accept...\n");
	close (sd);
	exit(0);
}	
