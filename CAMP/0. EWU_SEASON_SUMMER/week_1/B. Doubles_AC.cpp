#include<iostream>
#include<algorithm>
using namespace std;
#define check(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;

int main(){
    int arr[100], arrCounter = 0,i,j,doubleFound = 0,n,flag;
    while(1){
        cin >> n;
        if(n == -1){
            break;
        }else if(n==0){
            //sort(arr, arr+arrCounter);
            for(i=0;i<arrCounter;i++){
                //cout << arr[i] << endl;
                for(j=0;j<arrCounter;j++){
                    if(arr[j] == 2*arr[i]){
                        doubleFound++;
                    }
                }
            }
            cout << doubleFound << endl;
            arrCounter = 0;
            doubleFound = 0;
        }else{
            arr[arrCounter++] = n;
        }
    }


    return 0;
}
