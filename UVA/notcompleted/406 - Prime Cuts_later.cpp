#include<iostream>
using namespace std;
#define check(a) cout<<a<< endl;
int main(){
    int n,c,i,j,arrCounter = 0,limit;
    cin >>n >> c;
    limit = n%2==0?c*2 : (c*2)-1;
    int arr[n];
    arrCounter = 0;
    for(i=1;i<=n;i++){
        flag = 0;
        if(i%2==0){
            flag = 1;
        }else{
            for(j=3;j<=i;j+=2){
                if(i%j ==0){
                    flag = 1;
                    break;
                }
            }
        }
        if(flag == 0){
            arr[arrCounter++] = i;
        }
    }
    if((arrCounter-1)<= limit){
        cout << n << " " << c <<":";
        for(i=0;i<arrCounter;i++){
            cout <<" " << arr[i];
        }
        cout << endl;
    }
	return 0;
}
