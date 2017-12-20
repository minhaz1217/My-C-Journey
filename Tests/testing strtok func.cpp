#include<stdio.h>
#include<string.h>
using namespace std;
int main(){
    char strArr[300] = "Hurrah! was heard on all sides";
    char *pchar;
    //scanf("%s", strArr);
    pchar = strtok(strArr, " ");
    printf("%s\n", pchar);
    pchar = strtok(NULL, " ");
    printf("%s\n", pchar);
    pchar = strtok(0, " ");
    printf("%s\n", pchar);
    pchar = strtok('\0', " ");
    printf("%s\n", pchar);
    pchar = strtok(NULL, " ");
    printf("%s\n", pchar);
    pchar = strtok(NULL, " ");
    printf("%s\n", pchar);

	return 0;
}
