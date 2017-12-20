// UVA-11479

#include<bits/stdc++.h>
using namespace std;
int main(){
    long long tc,a,b,c,arr[3],caseCounter = 1;
    cin >> tc;
    while(tc--){
        cin >> arr[0] >> arr[1] >> arr[2];
        sort(arr, arr+3);
        a = arr[0];
        b = arr[1];
        c = arr[2];
        cout << "Case " << caseCounter++ << ": ";
        if( (a+b > c) && (a > 0 && b > 0 && c>0) ){
            if(a==b && b ==c){
                cout << "Equilateral" << endl;
            }else if( (a== b && a != c) || (b==c && b!=a) ){
                cout << "Isosceles" << endl;
            }else{
            	cout << "Scalene" << endl;
            }
        }else{
            cout << "Invalid" << endl;
        }
    }
    return 0;
}
