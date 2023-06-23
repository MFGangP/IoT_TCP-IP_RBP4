#include <stdio.h>
#include <stdlib.h> // strlen
#include <unistd.h> // write
#include <string.h>	// strlen
#include <arpa/inet.h> // inet_addr
#include <sys/socket.h> 
#include <netinet/in.h>
#include <pthread.h> // thread

#define BUF_SIZE 5000000
#define MAX_CLNT 256

char webpage[] = "HTTP/1.1 200 OK\r\n"
								"Server:Linux Web Server\r\n"
								"Content-Type: text/html; charset=UTF-8\r\n\r\n"
								"<!DOCTYPE html>\r\n"
								"<html><head><title> My Web Page </title>\r\n"
								"<style>body {background-color: #FFFF00 }</style></head>\r\n"
								"<body><center><h1>Hello world!!<h1><br>\r\n"
								"<img src=\"img.jpg\"></center></body></html>\r\n";

void error_handling(char *message);

int main(int argc, char *argv[])
{
	int serv_sock;
	int clnt_sock;

	struct sockaddr_in serv_adr;
	struct sockaddr_in clnt_adr;
	socklen_t clnt_adr_size;

	if(argc!=2)
	{
		printf("Usage : %s <port>\n", argv[0]);
		exit(1);
	}

	serv_sock=socket(PF_INET, SOCK_STREAM, 0);
	if(serv_sock == -1)
		error_handling("socket() error");
				
	memset(&serv_adr, 0, sizeof(serv_adr));
	serv_adr.sin_family=AF_INET;
	serv_adr.sin_addr.s_addr=htonl(INADDR_ANY);
	serv_adr.sin_port=htons(atoi(argv[1]));

	if(bind(serv_sock, (struct sockaddr*) &serv_adr, sizeof(serv_adr))==-1)
		error_handling("bind() error");

	if(listen(serv_sock, 5) == -1)
		error_handling("listen() error!");


	while(1)
	{
		clnt_adr_size=sizeof(clnt_adr);
		clnt_sock=accept(serv_sock, (struct sockaddr*)&clnt_adr, &clnt_adr_size);

		char buffer[BUF_SIZE];
		memset(buffer, 0, BUF_SIZE);	

  	if(clnt_sock==-1)
			error_handling("accept() error");

		read(clnt_sock, buffer, BUF_SIZE); 
		puts(buffer);

		if(strcmp(buffer, "/img.jpg")==0)
		{
			printf("사진 경로가 존재합니다.");
			FILE* fd = fopen("img.jpg", "r");
			send(clnt_sock, fd, sizeof(fd),0);
			fclose(fd);
		}
		else
		{
			printf("사진이 없습니다.");
			write(clnt_sock, webpage, sizeof(webpage)-1);
		}
		close(clnt_sock);
	}
	close(serv_sock);
	return 0;
}

void error_handling(char *message)
{
	fputs(message, stderr);
	fputc('\n', stderr);
	exit(1);
}
