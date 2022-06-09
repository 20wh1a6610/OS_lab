#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<pthread.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<string.h>
int main(){
	int fd1;
	char * myfifo = "/tmp/newpipe";
	mkfifo(myfifo,0666);
	char str1[80],str2[80];
	while(1){
		fd1 = open(myfifo,O_RDONLY);
		read(fd1,str1,80);
		printf("user1: %s\n",str1);
		close(fd1);
		fd1 = open(myfifo,O_WRONLY);
		fgets(str2,80,stdin);
		write(fd1,str2,strlen(str2)+1);
		close(fd1);
	}
return 0;
}
/*
output
hi
user1: hlo
*/
