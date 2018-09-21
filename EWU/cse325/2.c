#include<stdio.h>
#include<fcntl.h>
#include<string.h>

int main(){
	char str[] = "hello world\n";
	int sz = write(1, str, strlen(str));
	return 0;
}
