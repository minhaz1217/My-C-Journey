#include<stdio.h>
#include<fcntl.h>
#include<string.h>

int main(){
	char str[] = "hello world\n";
	int writeOStream = write(1, str, strlen(str));
	if(writeOStream == -1){
        printf("Failed\n");
	}
	return 0;
}
