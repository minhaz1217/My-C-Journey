# include <iostream>
# include <cstdio>
# include <cstring>

using namespace std;

int main()
{
    int t, i, count;
    char str[10002];
    char *word;
    char *token = new char();

    scanf("%d", &t);

    for(i = 1; i <= t; i++){
        scanf(" %[^\n]s", str);

        word = strtok(str, ",!;?. ");
        count = 0;
        while(token != NULL){
            token = strtok(NULL, ",!;?. ");
            printf("%s\n", token);
            count++;
        }

        printf("%d\n", count+1);
        token = new char();
    }


}
