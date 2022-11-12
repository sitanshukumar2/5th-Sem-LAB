#include<stdio.h>
#include<netinet/in.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<unistd.h>

#define MAX 1024
#define PORT 8080
int main()
{
    int sockfd,connfd,len;
    struct sockaddr_in servaddr,cli;
    sockfd=socket(AF_INET,SOCK_STREAM,0); //INSTEAD OF SOCK_DGRAM AS IN UDP
    if(sockfd==-1)
    {
        printf("Socket Creation Failed...\n");
        exit(0);
    }
    memset(&servaddr,0,sizeof(servaddr));

    //ADD ADDRESS DETAILS FOR BINDING
        servaddr.sin_family=AF_INET;
        servaddr.sin_addr.s_addr=htonl(INADDR_ANY);
        servaddr.sin_port=htons(PORT);
    
    if ((bind(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr))) != 0) 
    {
        printf("socket bind failed...\n");
        exit(0);
    }
    //THIS ACTUALLY DOES NOT LISTEN BUT JUST PREPARES THE QUEUE FOR 5 INCOMING CONNECTONS
    //AND RETURNS IMMEDIATELY(IT DOESN'T BLOCK THE PROGRAM)
    if ((listen(sockfd, 5)) != 0) 
    {
        printf("Listen failed.\n");
        exit(0);
    }

    len = sizeof(cli);

    // THIS CALL BLOCKS AS IT WAITS FOR INCOMING CONNECTION ESTABLISHMENT REQUESTS FROM CLIENTS
    //SOCKFD IS USED TO ACCEPT INCOMING CONNECTIONS AND AFTER A CONNECTION IS ESTABLISHED WITH
    //A PARTICULAR CLIENT , connfd IS RETURNED . 
    //connfd WILL BE USED FOR COMMUNICATION WITH THAT PARTICULAR CLIENT GOING FURTHER WHILE 
    //sockfd HELPS IN ESTABLISHMENT OF NEW CONNECTIONS.
    //WHEN A SECOND CLIENT CONNECTS,ANOTHER FD(YOU CAN CALL IT connfd1 OR WHATEVER YOU LIKE)
    //WILL BE RETURNED BY ACCEPT AND THAT WILL BE SPECIFIC TO COMMUNICATION BETWEEN THE SERVER 
    //AND ONLY THAT CLIENT.
    connfd = accept(sockfd, (struct sockaddr *) &cli, &len);
    if (connfd < 0) 
    {
        printf("server accept failed.\n");
        exit(0);
    }

    int n = 0;
    char buffer[MAX];

//WE USE recv INSTEAD OF recvfrom BECAUSE WE USE connfd and connfd ALREADY KNOWS FROM WHERE THE
//DATA IS COMING FROM AS IT IS A CONNECTION-SPECIFIC fd(IT CANNOT BE USED TO ACCEPT DATA FROM ALL CLIENTS. 
//IT CAN ONLY NE USED TO ACCPET DATA FROM THAT ONE PARTICULAR CLIENTS WITH WHOM CONNECTION HAS BEEN ESTABLISHED).
    n = recv(connfd, buffer, MAX, 0);
    buffer[n] = '\0';

    printf("From the client: \n");
    printf("%s\n", buffer);

    printf("Enter something to send to the client: \n");
    scanf("%[^\n]s", buffer);
//SIMILARLY , WE USED SEND INSTEAD OF sendto AS connfd INTERNALLY KNOWS WHO THE RECEIVER IS AND THERE IS NO NEED TO EXPLICITLY MENTION THE ADDRESS AGAIN.
     
    send(connfd, buffer, strlen(buffer), 0);

    close(connfd);
    close(sockfd);
}   
 