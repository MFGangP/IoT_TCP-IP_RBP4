#include <stdio.h>
#include <stdlib.h> // strlen
#include <unistd.h> // write
#include <string.h> // strlen
#include <arpa/inet.h> // inet_addr
#include <sys/socket.h>
#include <netinet/in.h>
#include <pthread.h> // thread

#define BUF_SIZE 500000
#define MAX_CLNT 256

void error_handling(char *message);

int main(int argc, char *argv[])
{
	int sock;
	struct sockaddr_in serv_addr;
	char message[BUF_SIZE];
	int str_len;

	if(argc!=3)
	{	
		printf("Usage : %s <IP> <port>\n", argv[0]);
		exit(1);
	}

	sock=socket(PF_INET, SOCK_STREAM, 0);
	if(sock == -1)
		error_handling("socket() error");

	memset(&serv_addr, 0, sizeof(serv_addr));
  serv_addr.sin_family=PF_INET;
  serv_addr.sin_addr.s_addr=htonl(INADDR_ANY);
  serv_addr.sin_port=htons(atoi(argv[2]));

	if(connect(sock, (struct sockaddr*) &serv_addr, sizeof(serv_addr))==-1)
		error_handling("connect() error!");

	str_len=read(sock, message, BUF_SIZE-1);
	fputs(message,stdout);
	
	close(sock);
	return 0;
}

void error_handling(char *message)
{
	fputs(message, stderr);
	fputc('\n', stderr);
	exit(1);
}
