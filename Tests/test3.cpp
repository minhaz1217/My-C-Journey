# include <iostream>
# include <cstdio>
# include <cstring>

using namespace std;

int main()
{
    int t, i, count;
    char str[10002];
    char *word;
    char *token = '1';

    scanf("%d", &t);

    for(i = 1; i <= t; i++)
    {
        scanf(" %[^\n]s", str);
        word = strtok(str, ",!;?. ");
        printf("%s", word);
        count = 0;
        while(word != NULL)
        {
            if(strlen(word) > 0)
                count++;
            word = strtok(NULL, ",!;?. ");
            printf("%s", word);
        }

        printf("%d\n", count);
    }


}
