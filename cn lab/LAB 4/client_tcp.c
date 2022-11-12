#include<arpa/inet.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<unistd.h>

#define MAX 1024
#define PORT 8080


int main() 
{
    int sockfd;
    struct sockaddr_in servaddr, cli;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1)
    {
        printf("socket creation failed.\n");
        exit(0);
    }

    memset(&servaddr,0,sizeof(servaddr));
    //ADD ADDRESS DETAILS OF THE SERVER TO CONNNECT TO.
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);
    servaddr.sin_addr.s_addr = INADDR_ANY;

    //THE CONNECT METHOD IS USED TO ESTABLISH A CONNECTION WITH THE SERVER.
    //BEFORE THIS, THE SERVER IS WAITING IN IT'S ACCEPT CALL(NOT LISTEN).
    
    if (connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) != 0) {
        printf("connection with the server failed.\n");
        exit(0);
    }
    char buffer[MAX];
    printf("Enter something to send to the server: \n");
    scanf("%[^\n]s", buffer);
    send(sockfd, buffer, strlen(buffer), 0);
    int n=0;
    n=recv(sockfd,buffer,MAX,0);
    buffer[n]='\0';
    
    printf("From the server: \n");
    printf("%s\n", buffer);

    close(sockfd);
}