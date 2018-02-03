#include<bits/stdc++.h>
using namespace std;
#define check(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;

int main(){
    long long counter, n,i,a;
    queue<long long>q;
    cin >> n;
    long long arr[n];
    for(i=0;i<n;i++){
        cin >> arr[i];
        q.push(arr[i]);
    }
    for(i=n-1;i>=0;i--){
        //q.push(arr[i]);
    }
    counter = 0;
    sort(arr, arr+n);
    //msg("HI", arr[0])
    for(i=0;i<n;i++){
        while(q.front() != arr[i]){
            a = q.front();
            q.pop();
            q.push(a);
            counter++;
        }
        q.pop();
        counter++;
    }
    cout << counter << endl;

    return 0;
}
