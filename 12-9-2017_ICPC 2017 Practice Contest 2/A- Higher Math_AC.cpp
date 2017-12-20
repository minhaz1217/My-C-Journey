#include<iostream>
#include<algorithm>
using namespace std;
#define check(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;

int main(){
    int tc,a,b,c,caseCounter = 1;
    int arr[3];
    cin >> tc;
    while(tc--){
        cin >> arr[0] >> arr[1] >> arr[2];
        sort(arr, arr + 3);
        a = arr[0];
        b = arr[1];
        c = arr[2];
        if(a*a + b*b == c*c && (c >a && c >b)){
            cout << "Case "<< caseCounter++ << ": yes" << endl;
        }else{
            cout << "Case "<< caseCounter++ << ": no" << endl;
        }
    }
    return 0;
}
