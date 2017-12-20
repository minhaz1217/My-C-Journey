#include<bits/stdc++.h>
using namespace std;
#define check(a) cout<<a<< endl;
#define msg(a,b) cout << a << " : " << b << endl;
int main(){
    long long tc,counter = 0,i,j;
    cin >> tc;
    long long arr[tc];
    for(i=0;i<tc;i++){
        cin >> arr[i];
    }
    for(i=0;i<tc-1;i++){
        for(j=0;j<tc-i;j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
                counter++;
            }
        }
    }
    cout << counter << endl;






	return 0;
}
