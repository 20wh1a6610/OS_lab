#include<stdio.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#define MAX 10
struct msg_buffer{
		long msg_type;
		char msg_text[100];
}message;
int main(){
	key_t key;
	int msgid;
	key = ftok("progfile",65);
	msgid = msgget(key,0666|IPC_CREAT);
    message.msg_type=1;
	printf("write data:");
	fgets(message.msg_text,MAX,stdin);
	msgsnd(msgid,&message,sizeof(message),0);
	printf("data sent is: %s\n",message.msg_text);
	return 0;
}




/*output
write data:hi
data sent is: hi

*/                                                 
