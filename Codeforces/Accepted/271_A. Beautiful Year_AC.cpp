#include<bits/stdc++.h>
using namespace std;
#define check(a) cout<<a<< endl;
int main(){
    long long year,i,j,temp,arr[4],flag;
    cin >> year;
    year++;
    for(;;){
        temp = year;
        for(i=0;i<4;i++){
            arr[i] = temp %10;
            temp = temp/10;
        }
        for(i=0;i<4;i++){
            flag = 1;
            for(j=i+1;j<4;j++){
                if(arr[i] == arr[j]){
                    flag = 0;
                    break;
                }
            }
            if(flag == 0){
                break;
            }
        }
        if(flag == 1){
            cout << year;
            break;
        }else{
            year++;
        }

    }

	return 0;
}
