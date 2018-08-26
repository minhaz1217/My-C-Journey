/*
    to solve this problem lets first double the orginal array (put another array similar to (a) beside (a) ) so we get (aa)
    now we get every possible cyclic shift (any n consecutive elements represent a cyclic shift).
    we make a perfix sum array (s) and sort its elements by increasing order.
    now we perform the cyclic shift from 0 to n-1 .. each time we remove the first element and add it to the end,
    when we remove the first element we check if the smallest element in the prefix sum minus the sum of all the removed elements if it's >=0 so it's a valid cyclic shift.
*/
#include<bits/stdc++.h>
#define ii pair<int,int>
#define iii pair<ii,int>
#define endl '\n'
#define int long long int
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;
#define msg3(a,b,c,d) cout << a << " : " << b << " : " << c << " : " << d << endl;

using namespace std;
int a[2111111],sm[2111111];
main(){
    ios_base::sync_with_stdio(false);
    int t;
    int n;
    while(cin>>n){
        if(n==0)    break;
        for(int i=0;i<n;i++)
            cin>>a[i];
        for(int i=0;i<n;i++)
            a[i+n]=a[i];
        sm[0]=a[0];
        int mn=1e9;
        int curminus=0;
        vector<ii> v;
        for(int i=0;i<2*n;i++){
            sm[i]=sm[i-1]+a[i];
            v.push_back(ii(sm[i],i));
        }
        for(int i=0;i<v.size();i++){
            msg(v[i].first, v[i].second);
        }

        int ans=0;
        sort(v.begin(),v.end());
        int it=0;
        for(int i=0;i<n;i++){
            //���� �� �������� ���� ������ i
            //�� ��� ��ps ���� ������ i
            curminus+=a[i];
          //  cout<<i<<" "<<to.second<<endl;
            while(v[it].second<=i){
             //   cout<<v[it].second<<endl;

                it++;
            }
           // cout<<to.first<<" "<<curminus<<endl;
            if(v[it].first-curminus>=0)
                ans++;
        }
        cout<<ans<<endl;
    }
}
