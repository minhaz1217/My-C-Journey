#include<stdio.h>
#include<fcntl.h>
#include<dirent.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char *argv[]){

	if(argc != 2){
		printf("Invalid number of arguments\n");
		printf("Usage: PROG_NAME FILE_NAME\n");
		exit(1);
	}
	char *filename = argv[1];

	creat(filename,0777);
	int fd = open(filename, O_WRONLY,0);

	DIR *dirptr = opendir("/home/fahim/Desktop/CSE325/Lab/assignment");

	if(dirptr == NULL){
		printf("Cannot open directory\n");
		exit(1);
	}

	struct dirent *entry = readdir(dirptr);
	while(entry!=NULL){
        int n = strlen(entry->d_name);

		if(entry->d_name[n-1] == 't' && entry->d_name[n-2] == 'x' && entry->d_name[n-3] == 't' && entry->d_name[n-4] == '.'){
			char buf[1024];
			int fd1 = open(entry->d_name,O_RDONLY, 0);
			int szr = read(fd1, buf, 1024);
			lseek(fd,0,2);
			int szw = write(fd, buf, szr);
		}
        entry = readdir(dirptr);
	}

        return 0;
}

