#include<iostream>
#include<string>
using namespace std;
#define check(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;

int main(){

    int a,fcounter = 0,big=0,bcounter = 1,i,j,tcCounter = 1;
    string str[16],st;
    while(1){
        cin >> a;
        if(a == 0){
            break;
        }
        fcounter = 0;
        bcounter = 1;
        for(j=1;j<=a;j++){
            cin >> st;
            if(j%2 == 0){
                str[a-bcounter] = st;
                bcounter++;
            }else{
                str[fcounter++] = st;
            }
        }
        cout << "SET " << tcCounter++ << endl;
        for(i=0;i<a;i++){
            cout << str[i] << endl;
        }
    }





    return 0;
}
