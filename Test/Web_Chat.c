#include <stdio.h>
#include <stdlib.h> // strlen
#include <unistd.h> // write
#include <string.h>	// strlen
#include <arpa/inet.h> // inet_addr
#include <sys/socket.h> 
#include <netinet/in.h>
#include <pthread.h> // thread

#define BUF_SIZE 100
#define MAX_CLNT 256

char webpage[] = "HTTP/1.1 200 OK\r\n"
								"Server:Linux Web Server\r\n"
								"Content-Type: text/html; charset=UTF-8\r\n\r\n"
								"<!DOCTYPE html>\r\n"
								"<html><head><title> My Web Page </title>\r\n"
								"<style>body {background-color: #FFF00 }</style></head>\r\n"
								"<body><center><h1>Hello world!!<h1><br>\r\n"
								"<img src=\"img.jpg\"></center></body></html>\r\n";
								
