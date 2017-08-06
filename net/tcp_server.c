#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>	
#include <pthread.h>
#include <stdlib.h>

#define BUF_SIZE 1024

void * process_connect(void * client_fd){
	char buf[BUF_SIZE];
	int len;

	int fd = *((int *)client_fd);
	memset(buf, 0, BUF_SIZE);
	
	len = send(fd,"Welcome to server.",21,0);

	while((len = recv(fd, buf, BUF_SIZE, 0)) > 0){
		buf[len] = '\0';
		printf("cliet[%d]-request data [%s]\n",fd, buf);
		if(send(fd, buf, len, 0) < 0){
			perror("send data to client error");
			return (void *)1;
		}
	}
	close(fd);
	printf("clinet[%d] exit.\n",fd);
	return NULL;
}


int main(int argc,char * argv[]){

	int server_fd;

	struct sockaddr_in my_addr;

	int sin_size;

	memset(&my_addr,0,sizeof(my_addr));

	my_addr.sin_family=AF_INET;
	my_addr.sin_addr.s_addr=INADDR_ANY;
	my_addr.sin_port=htons(8000);

	if((server_fd = socket(PF_INET,SOCK_STREAM,0))<0){
		perror("socket error");
		return 1;
	}

	if(bind(server_fd,(struct sockaddr *) &my_addr,sizeof(struct sockaddr))<0){
		perror("bind error");
		return 1;
	}

	listen(server_fd,10);
	printf("listen for client to connect.\n");

	sin_size = sizeof(struct sockaddr_in);

	for(;;){
		struct sockaddr_in remote_addr;
		int client_fd = accept(server_fd,(struct sockaddr *)&remote_addr,&sin_size);
		
		if(client_fd <0 ){
			perror("accept client connection error");
			continue;
		}

		printf("accept client [%s]'s connection,[fd = %d].\n",inet_ntoa(remote_addr.sin_addr), client_fd);
		
		//create thread to handle client request
		pthread_t t;
		if(pthread_create(&t,NULL,(void*)(&process_connect),(void *)(&client_fd))!=0){
			perror("failed to create a thread");
			continue;
		}
	}

	close(server_fd);
	return 0;
}
