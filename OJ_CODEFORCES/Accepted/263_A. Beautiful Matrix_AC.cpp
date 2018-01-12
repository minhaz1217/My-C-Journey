#include<bits/stdc++.h>
using namespace std;
#define check(a) cout<<a<< endl;
int main(){
    long long arr[5][5],i,j,x,y;
    for(i=0;i<5;i++){
        for(j=0;j<5;j++){
            cin >> arr[i][j];
            if(arr[i][j]){
                x= i;
                y = j;
            }
        }
    }
    cout << abs(x-2) + abs(y-2) << endl;
	return 0;
}
