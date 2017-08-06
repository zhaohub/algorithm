#include <stdio.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>

#define BUF_SIZE 1024

int main(int arc,char * argv[]){

	int client_fd;
	int len;
	
	struct sockaddr_in remote_addr;
	char buf[BUF_SIZE];

	memset(&remote_addr,0,sizeof(remote_addr));
	remote_addr.sin_family = AF_INET;
	remote_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	remote_addr.sin_port = htons(8000);

	if((client_fd = socket(PF_INET,SOCK_STREAM,0))<0){
		perror("creat client socket error");
		return 1;
	}

	if(connect(client_fd,(struct sockaddr *)&remote_addr,sizeof(struct sockaddr))<0){
		perror("connect to server error");
		return 1;
	}

	printf("connet to remote server sucessful\n");

	len = recv(client_fd,buf,BUF_SIZE,0);
	buf[len] = '\0';
	printf("%s client_fd = %d \n", buf, client_fd);

	while(1){
		printf("Enter string to send:");
		scanf("%s", buf);
		if(!strcmp(buf,"quit")) break;

		len = send(client_fd,buf,strlen(buf),0);

		if(len < 0 ){
			connect(client_fd,(struct sockaddr *)&remote_addr,sizeof(struct sockaddr));
		}

		len = recv(client_fd, buf, BUF_SIZE, 0);
		buf[len] = '\0';
		printf("server response data [%s]\n",buf);

	}

	close(client_fd);
	return 0;

}