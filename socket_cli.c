#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <linux/in.h>
#include <string.h>
#include <unistd.h>
#include "utils.h"

int main(int argc, char *argv[]) {
	
	if(argc!=3){
		fprintf(stderr,"ejecutar como ./cliente <n> <ip-servidor> \n");
		exit(EXIT_FAILURE);
	}

	struct sockaddr_in server_addr;
	struct hostent *hp;
	int num[1], N, res, sd;
	
	N = atoi(argv[1]);

	float A[N][N], B[N][N];
	matrizGen(N,A,B);

	sd = socket(AF_INET, SOCK_STREAM, 0);

	/* se obtiene y rellena la direcci�n del servidor */
	bzero((char *)&server_addr, sizeof(server_addr));
	hp = gethostbyname (argv[2]);
	if (hp==NULL){
		printf("Error en la llamada gethostbyname");
		exit(0);
	}
        
	memcpy (&(server_addr.sin_addr), hp->h_addr, hp->h_length);
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(4200);

	/* se establece la conexi�n */
	if (connect(sd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0){
		perror("Error en la llamada connect");
		exit(0);
	}

	//ENVIA TAMANIO DE MATRICES
	num[0]=N;
	write(sd, (char *) num, 1 *sizeof(int));
	
	//ENVIA A Y B
	write(sd, (char *) A, (N*N) *sizeof(float)); 
	write(sd, (char *) B, (N*N) *sizeof(float));
	
	float C[N][N];
	// RECIBE C
	read(sd, (char *) C, (N*N) *sizeof(int));
	displayOne(N,C);
	
	close (sd);
	exit(0);
}
