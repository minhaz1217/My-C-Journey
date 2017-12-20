#include<iostream>
using namespace std;
int main(){
    int i,a=5,j,k;
    for(i=1;i<=a;i++){
        for(j=a-i;j>=0;j--){
            cout << " ";
        }
        for(k=1;k<=i;k++){
            cout << "* ";
        }
        cout << endl;
    }

    return 0;
}
