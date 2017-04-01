#include <sys/socket.h>
#include <sys/un.h>
#include <fcntl.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	 int fromlen,res,sd,fd1,n,size,l,t;

	 char buf1[100],buf2[100];

	 struct sockaddr_in s_address;
	 sd=socket(AF_INET,SOCK_STREAM,0);
	 s_address.sin_family=AF_INET;
	 s_address.sin_addr.s_addr=inet_addr("192.168.43.97");
	 s_address.sin_port=htons(10227);
	 fromlen=sizeof(s_address);
	 res=connect(sd,(struct sockaddr*)&s_address,fromlen);
	 printf("Welcome to Kratos file transfer Protocol");
	 printf("\n");
	 

	char command[50], again;
	int flag=0;
	int choice;

	do
	{
		printf("\nEnter your choice of Operation:\n1.Detailed List of the files.\n2.Download a Video file.\n3.Download a music file\n4.Download a PDF file.\n5.Upload a file.\n");
		printf("\nInitiating Kratos FTP portal...");
		scanf("%d",&choice);flag++;

		if(choice==1)
	{
		strcpy(command, "sh script1.sh");
		system(command);
	}
else if(choice==2)
{
	char file[30];
	printf("\nEnter the video file name to be downloaded ");
	scanf("%s", file);
	
	strcpy(command, "sh script2.sh ");
	strcat(command, file);
	system(command);
	if(strcmp(strstr(file,".mp4"),".mp4") == 0){
		
		strcpy(command, "totem ");
		strcat(command, file);
		//printf("%s\n", command);
		system(command);
	}
}
else if(choice==3)
{
	char file[30];
	printf("Enter the music file to be downloaded");
	scanf("%s", file);
	
	strcpy(command, "sh script2.sh ");
	strcat(command, file);
	system(command);

	if(strcmp(strstr(file,".wav"),".wav") == 0){
		strcpy(command, "aplay ");
		strcat(command, file);
		system(command);
	}
}
else if(choice==4)
{
	char file[30];
	printf("Enter the PDF file name to be downloaded");
	scanf("%s", file);
	
	strcpy(command, "sh script2.sh ");
	strcat(command, file);
	system(command);

}
else if(choice==5)
{
	char file[30];
	printf("Enter the file name to be uploaded");
	scanf("%s", file);
	
	strcpy(command, "sh script3.sh ");
	strcat(command, file);
	system(command);
}
printf("\nEnter Y/y for another run\n");
scanf(" %c",&again);
}while(again=='Y' || again=='y');
	 close(sd);

	 return 0;
} 
