# include <iostream>
# include <stdio.h>

using namespace std;

int main(){
    int t, val;
    char ch[2];
    char ch1;
    scanf("%d", &t);

    while(t--){
        cout << t << endl;
        scanf("%*c");
        scanf("%c", &ch1);
        cout << ch1 << endl;
        //val = ch[0];

        /*
        if(val >= 'A' && val <= 'Z'){
            printf("Uppercase Character\n");
        }else if(val >= 'a' && val <= 'z'){
            printf("Lowercase Character\n");
        }else if(val >= '0' && val <= '9'){
            printf("Numerical Digit\n");
        }else{
            printf("Special Character\n");
        }
        */
    }

    return 0;


}
