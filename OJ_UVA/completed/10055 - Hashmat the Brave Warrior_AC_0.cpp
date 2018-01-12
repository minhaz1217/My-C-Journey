#include<iostream>
using namespace std;
int main(){
    long a,b,arr[10000], arrLength = 0;
    while((cin>>a>>b) != 0){
        if(a>=b){
            arr[arrLength] = a-b;
        }else if(b>a){
            arr[arrLength] = b-a;
        }
        arrLength++;
    }
    for(a=0;a<arrLength;a++){
        cout << arr[a] << endl;
    }

    return 0;
}
