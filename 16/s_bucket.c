#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>//read
#include <stdlib.h>//exit
#include <netdb.h> //getaddrinfo() getnameinfo() freeaddrinfo()
#define pto "9999"
int TAM= 3500; 

void mergeSort(int arr[], int l, int r);
void merge(int arr[], int l, int m, int r);

void error(const char * msj){
	perror(msj);
	exit (1);
}

// get sockaddr, IPv4 or IPv6:
void *get_in_addr(struct sockaddr *sa)
{
	if (sa->sa_family == AF_INET) {
		return &(((struct sockaddr_in*)sa)->sin_addr);
	}

	return &(((struct sockaddr_in6*)sa)->sin6_addr);
}


int main(){
	int sd,cd,n,n1,v=1,rv,op=0;
	socklen_t ctam;
	char s[INET6_ADDRSTRLEN], hbuf[NI_MAXHOST], sbuf[NI_MAXSERV];
	//struct sockaddr_in sdir,cdir;
	struct addrinfo hints, *servinfo, *p;
	struct sockaddr_storage their_addr; // connector's address 
	ctam= sizeof(their_addr);
	memset(&hints, 0, sizeof (hints));  //indicio
	hints.ai_family = AF_INET6;    /* Allow IPv4 or IPv6  familia de dir*/
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_flags = AI_PASSIVE; // use my IP
	hints.ai_protocol = 0;          /* Any protocol */
	hints.ai_canonname = NULL;
	hints.ai_addr = NULL;
	hints.ai_next = NULL;

	if ((rv = getaddrinfo(NULL, pto, &hints, &servinfo)) != 0) {
		fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
		return 1;
	}//if

	for(p = servinfo; p != NULL; p = p->ai_next) {
		if ((sd = socket(p->ai_family, p->ai_socktype,p->ai_protocol)) == -1) {
			perror("server: socket");
			continue;
		}

		if (setsockopt(sd, SOL_SOCKET, SO_REUSEADDR, &v,sizeof(int)) == -1) {
			perror("setsockopt");
			exit(1);
		}

		if (setsockopt(sd, IPPROTO_IPV6, IPV6_V6ONLY, (void *)&op, sizeof(op)) == -1) {
			perror("setsockopt   no soporta IPv6");
			exit(1);
		}

		if (bind(sd, p->ai_addr, p->ai_addrlen) == -1) {
			close(sd);
			perror("server: bind");
			continue;
		}//if

		break;
	}//for

	freeaddrinfo(servinfo); // all done with this structure

	if (p == NULL)  {
		fprintf(stderr, "servidor: error en bind\n");
		exit(1);
	}

	listen(sd,5);
	printf("Servidor listo.. Esperando clientes \n");

	for(;;){

		ctam = sizeof their_addr;
		cd = accept(sd, (struct sockaddr *)&their_addr, &ctam);
		if (cd == -1) {
			perror("accept");
			continue;
		}
		if (getnameinfo((struct sockaddr *)&their_addr, sizeof(their_addr), hbuf, sizeof(hbuf), sbuf,sizeof(sbuf), NI_NUMERICHOST | NI_NUMERICSERV) == 0)
			printf("cliente conectado desde %s:%s\n", hbuf,sbuf);


		FILE *f = fdopen(cd,"w+");

		int buf[TAM];
		//for(;;){
		bzero(buf,sizeof(buf));
		n=read(cd,buf,sizeof(buf));
		if(n<0){
			perror("Error de lectura\n");
			close(cd);
			break;
		}
		else if(n==0){
			perror("Socket cerrado\n");
			break;
		}//if
		//printf("recibidos:  %d bytes \n",n);
		int tam = (n/sizeof(int));
		//printf("Tamaño: %lu\n", n/sizeof(int));

		int bufAux[tam];
		int y;

		for(y = 0; y < tam; y++)
			bufAux[y] = ntohl(buf[y]);
		
		mergeSort(bufAux, 0, tam);

		for(y = 0; y < tam; y++)
			//printf("%d,", bufAux[y]);
		//char *tmp = (char *) malloc(strlen(buf));

		for(y = 0; y < tam; y++)
			bufAux[y] = htonl(bufAux[y]);

		n1 = write(cd,bufAux,n);
		fflush(f);
		//printf("Se mando acuse de recibo\n\n\n");
	}//for
	close(sd);
	printf("Ya está todo chido :3\n");
	return 0;
}//main

void merge(int arr[], int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 =  r - m;

	int L[n1]; 
	int R[n2]; 

	for (i = 0; i < n1; i++) //llenando arreglos temporales
		L[i] = arr[l+i];
	
	for (j = 0; j < n2; j++)
		R[j] = arr[m+1+j];

	i = 0; 
	j = 0; 
	k = l; 

	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])//comparando la primera letra del arreglo
		{
			arr[k] = L[i]; //moviendo el contenido de temporal a arreglo original
			i++;
		}
		else
		{
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	while (i < n1) //copiando elementos restantes
	{
		arr[k] = L[i];
		i++;
		k++;
	}

	while (j < n2) //copiando elemntos restantes
	{
		arr[k] = R[j];
		j++;
		k++;
	}
}

void mergeSort(int arr[], int l, int r)
{
	if (l < r) //condicion de paro
	{
		int m = l+(r-l)/2;
		mergeSort(arr, l, m);
		mergeSort(arr, m+1, r); //llamadas recursivas 

		merge(arr, l, m, r); //llamada a ordenar
	}
}
