#include<bits/stdc++.h>
using namespace std;
#define check(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;

int main(){
    int n,i,sum,q,a,b;
    cin >> n;
    int arr[n];
    vector<int>cummulative;
    cummulative.push_back(0);
    sum = 0;
    for(i=0;i<n;i++){
        cin >> arr[i];
        sum += arr[i];
        //arr[i] = sum;
        cummulative.push_back(sum);
    }
    for(i=0;i<cummulative.size();i++){
        cout << cummulative[i] << " ";
    }
    cout << endl;
    cin >> q;
    while(q--){
        cin >> a >> b;
        cout << cummulative[b] - cummulative[a-1] << endl;
    }


    return 0;
}
