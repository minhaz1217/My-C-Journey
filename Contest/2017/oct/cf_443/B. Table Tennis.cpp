#include<bits/stdc++.h>
using namespace std;
#define check(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;

int main(){
    long long int n,k,a,i,b,winner;
    queue<long long int> q;
    cin >> n >> k;
    int arr[n+1] = {0};
    for(i=0;i<n;i++){
        cin >> a;
        q.push(a);
    }
    a = q.front();
    q.pop();
    while(1){
        b = q.front();
        q.pop();
        if(a>b){
            arr[a]++;
            q.push(b);
        }else{
            arr[b]++;
            q.push(a);
            a = b;
        }
        if(arr[a] == k){
            winner = a;
            break;
        }else if(a == n){
            winner = a;
            break;
        }
    }
    cout << winner << endl;

    return 0;
}
