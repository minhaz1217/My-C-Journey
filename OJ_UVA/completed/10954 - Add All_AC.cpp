// very easy with STL queue
#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;
#define msg3(a,b,c,d) cout << a << " : " << b << " : " << c << " : " << d << endl;

int main(){

    long long int n,a,sum=0,b,ans;
    while(1){
        sum = 0;
        priority_queue< long long int, vector<long long int>, greater<long long int> >pq;
        cin >> n;
        if(n == 0){
            break;
        }
        for(int i=0;i<n;i++){
            cin >> a;
            //vec.push_back(a);
            pq.push(a);
        }
        while(!pq.empty()){
            if(pq.size() == 1){
                ans = sum + pq.top();
                break;
            }
            a = pq.top();
            pq.pop();
            b = pq.top();
            pq.pop();
            sum += a+b;
            pq.push(a+b);

        }
        cout << sum << endl;

    }
    return 0;
}
