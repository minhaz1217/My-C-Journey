#include<iostream>
#include<fstream>

using namespace std;

int main()
{   int counter = 0,i;
    char str[1000];
    FILE *fp;
    fp = fopen("1.txt", "r");

    while(fscanf(fp, "%s", str)){
            if(str[0] == '%' && str[1] =='%'){
                break;
            }
            for(i=0;str[i];i++){
                if(str[i] == ' '){
                    counter++;
                }
            }
            counter++;
    }
    cout << counter << endl;
}
