#include<iostream>
#include<algorithm>
using namespace std;
#define check(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;

int main(){
    int tc,i,maxLength=1,totalTower = 0,curr = 0,prev;
    cin >> tc;
    int arr[tc];

    for(i=0;i<tc;i++){
        cin >> arr[i];
    }
    sort(arr, arr+tc);
    prev = arr[0];
    curr = 1;
    for(i=1;i<tc;i++){
        if(arr[i] == prev){
            curr++;
            maxLength = maxLength > curr? maxLength:curr;
        }else{
            curr = 1;
            totalTower++;
        }
        prev = arr[i];
    }
    cout << maxLength << " " << totalTower+1 << endl;

    return 0;
}
