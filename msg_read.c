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
    msgrcv(msgid,&message,sizeof(message),1,0);
	printf("data received is:%s\n",message.msg_text);
	msgctl(msgid,IPC_RMID,NULL);
	return 0;

}


/*output
data received is:hi
*/
  
