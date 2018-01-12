//https://open.kattis.com/contests/j4tigo/problems/alicedigital
#include<bits/stdc++.h>
using namespace std;
#define check(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;

int main(){
    int tc,i,n,m,p,big, sum;
    queue<int> mPos;
    cin >> tc;
    while(tc--){
        big = INT_MIN;
        cin >> n >> m;
        int arr[n];
        for(i=0;i<n;i++){
            cin >> arr[i];
            if(arr[i] == m){
                mPos.push(i);
            }
        }
        while(!mPos.empty()){
            p = mPos.front();
            mPos.pop();
            sum = m;
            for(i=p+1;i<n;i++){
                if(arr[i] <= m){
                    break;
                }else{
                    sum+= arr[i];
                    big = max(sum, big);
                }
            }
            for(i=p-1;i>=0;i--){
                if(arr[i] <= m){
                    break;
                }else{
                    sum+= arr[i];
                    big = max(sum, big);
                }
            }
        }
        cout << big << endl;

    }
    return 0;
}
