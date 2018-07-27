#include<bits/stdc++.h>
using namespace std;
#define cc(a) cout << a << endl;
#define check(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c<< endl;

int main(){
    int n,l,curr,tc,currMax;
    string str;
    cin >> tc;
    while(tc--){
        cin >> n;
        int arr[99999] = {0};
        currMax = 0;
        while(n--){
            cin >> str >> l;
            arr[l]++;
            if(currMax < arr[l]){
                //msg(l, arr[l]])
                currMax = arr[l];
                curr = l;
            }
        }
        cout << curr << endl;
    }

    return 0;
}
