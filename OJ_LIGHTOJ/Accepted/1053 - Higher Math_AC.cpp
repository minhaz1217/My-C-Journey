#include<bits/stdc++.h>
using namespace std;
#define check(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;

int main(){
    long long int tc,caseCounter = 1;
    long long int arr[3];
    cin >> tc;
    while(tc--){
        cin >> arr[0] >> arr[1] >> arr[2];
        sort(arr, arr+3);
        if(arr[0] * arr[0] + arr[1] * arr[1] == arr[2] * arr[2]){
            cout << "Case "<< caseCounter++ << ": yes" << endl;
        }else{

            cout << "Case "<< caseCounter++ << ": no" << endl;
        }
    }


    return 0;
}
