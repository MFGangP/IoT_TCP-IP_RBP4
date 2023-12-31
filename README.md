# IoT_TCP-IP_RBP4
부경대학교 IoT 사물인터넷 TCP/IP 라즈베리파이

## 1일차

-	네트워크 프로그래밍 & 소켓
	- 소켓 생성 : socket
	- IP 주소와 PORT 번호 할당 : bind
	- 연결 요청 상태로 변경 : listen
	- 연결 요청 수락 : accept

- 프로토콜과 데이터 전송 특성
	- TCP
		- 연결지향형 소켓(SOCK_STREAM)
	- UDP
		- 비 연결지향형 소켓(SOCK_DGRAM)

<img src="https://github.com/MFGangP/IoT_TCP-IP_RBP4/blob/main/image/Day01_hello_sv_clnt.png?raw=true" width="640">

## 2일차

- 주소체계와 데이터 정렬
	- 소켓에 할당되는 IP주소와 PORT번호
		- IPv4(4byte), IPv6(6byte)
	- 주소 정보의 표현
		- IPv4 기반 주소표현 구조체
	- 네트워크 바이트 순서와 인터넷 주소 변환
		- 바이트 순서와 네트워크 바이트 순서
			- 빅 엔디안 : 작은 주소에 큰 값 
			- 리틀 엔디안 : 작은 주소에 작은 값 
			- htons, ntohs, htonl, ntohl
	- 인터넷 주소의 초기화와 할당
		- 인터넷 주소, 클라이언트 주소의 초기화

- TCP 기반 서버/ 클라이언트 1		
	- TCP, UDP에 대한 이해
	- TCP기반 서버, 클라이언트 구현

<img src="https://github.com/MFGangP/IoT_TCP-IP_RBP4/blob/main/image/Day02_hello_sv_clnt.png?raw=true" width="640">

## 3일차

<img src="https://github.com/MFGangP/IoT_TCP-IP_RBP4/blob/main/image/Day03_uecho_sv_clnt.png?raw=true" width="640">

## 4일차

<img src="https://github.com/MFGangP/IoT_TCP-IP_RBP4/blob/main/image/Day04_thread_wait.png?raw=true" width="640">