#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<stdlib.h>

int foo(int fd, char *buf, int b_size, int n, int skip){
    int r = 0;
	if(strlen(buf) <= n*b_size+((n-1)*skip)){
		return -1;
	}
	else{
        lseek(fd,0,0);
		while(n--){
            printf("%d\n",n);
            if(n == 0){
                r+=b_size;
			}
			else{
                lseek(fd,b_size+skip,1);
                r+=b_size;
            }

		}
		return r;
	}
}

int main(int argc, char *argv[]){
    if(argc !=2){
		printf("Ivaild number of arguments.\n");
		printf("Usage: PROG_NAME FILE_NAME\n");
		exit(1);
	}
	char *filename = argv[1];
	int b_size, n, skip;

	printf("Enter Block Size: ");
	scanf("%d",&b_size);
	printf("Enter Total Number: ");
	scanf("%d",&n );
	printf("Enter Skip Size: ");
	scanf("%d",&skip);

	int fd = open(filename, O_RDONLY, 0);
	if(fd == -1){
		printf("Error opening file.\n");
		exit(1);
	}

	char buf[1024];
	int sz = read(fd, buf, 1024);

	int r = foo(fd, buf, b_size, n, skip);
	close(fd);

	if(r == -1){
		printf("Operation Unsuccessfull.\n");
	}
	else{
		printf("\nBytes read: %d\n",r);
	}

	return 0;
}
