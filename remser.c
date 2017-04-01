#include <sys/un.h>
#include <fcntl.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main()
{
        char buf1[100], buf2[100];
        struct sockaddr_in s_address, c_address;
        int a,fd1,fd2,sd,ns,n,t,count=0;
        int fromlen;

	char command[50];

        sd=socket(AF_INET,SOCK_STREAM,0);
        s_address.sin_family=AF_INET;
        s_address.sin_addr.s_addr=INADDR_ANY;
        s_address.sin_port=htons(10227);
        a = bind(sd, (struct sockaddr*)&s_address, sizeof(s_address));
        listen(sd,1);

                ns=accept(sd, (struct sockaddr*)&c_address, &fromlen);
		n = recv (ns, buf1, 10, 0);
		printf("%s",buf1);
        
		
		strcpy( command, "aplay " );
		strcat(command, buf1);
		printf("%s",command);
		system(command);
 	close(ns);
   	return 0;
}


