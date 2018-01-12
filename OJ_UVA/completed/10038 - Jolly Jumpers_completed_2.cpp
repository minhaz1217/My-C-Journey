#include<iostream>
#include<cmath>
using namespace std;
int main(){
    int n,i,j,flag;
    for(;;){
        cin >> n;
        if(cin.eof()){
            break;
        }
        int arr[n];
        for(i=0;i<n;i++){
            cin >> arr[i];
        }
        for(i=1;i<n;i++){
            flag = 0;
            for(j=0;j<n-1;j++){

                if(abs(arr[j]-arr[j+1]) == i){
                    flag = 1;
                    break;
                }
            }
            if(flag == 0){
                break;
            }
        }
        if(flag ==1 || n==1){
            cout << "Jolly" << endl;
        }else {
            cout << "Not jolly" << endl;
        }
    }

	return 0;
}
