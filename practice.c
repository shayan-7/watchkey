#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <string.h>


void wrapper(void (*cb)(int), int n){
  printf("I'm in wrapper\n");
  cb(n);
}

int main(void)
{
  int sockfd, conn;
  struct sockaddr_in *server = malloc(sizeof(struct sockaddr_in));
  char buffer[1024];

  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  printf("%d\n", sockfd);

  server -> sin_family = AF_INET;
  server -> sin_port = htons(20202);
  int a = inet_aton("127.0.0.1", (struct in_addr *)&server -> sin_addr);
  conn = connect(sockfd, (struct sockaddr *)server, sizeof(struct sockaddr_in));
  printf("%d\n", conn);
  send(sockfd , "Hello" , strlen("Hello") , 0 );
  printf("Hello message sent\n");
  read(sockfd, buffer, 1024);
  printf("%s\n", buffer);
  return 0;
}
