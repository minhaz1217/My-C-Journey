#include<stdio.h>
#include<fcntl.h>

int main(){
	char c;
	int fd1 = open("foobar.txt", O_RDONLY, 0);
	int fd2 = open("foobar.txt", O_RDONLY, 0);
	read(fd1, &c, 1);
	read(fd2, &c, 1);
	printf("c = %c\n", c);
	close(fd1);
	close(fd2);

	return 0;
}
