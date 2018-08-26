#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;
#define msg3(a,b,c,d) cout << a << " : " << b << " : " << c << " : " << d << endl;


int main(){
    long long int tc,caseCounter=1;
    scanf("%lld", &tc);

    while(tc--){
        long long int a,b,n,q,counter=1,sz1,sum,c,d,mx;
        map<long long int, long long int> mp;
        vector<long long int>vec2,vec,points;
        //vec.assign(1000004,0);
        scanf("%lld%lld", &n,&q);
        points.assign(n+4,0);
        mx = INT_MIN;
        for(int i=0;i<n;i++){
            cin >> a >> b;
            if(!mp[a]){
                mp[a] = counter++;
                vec2.push_back(a);
            }
            mx = max(mx, a);
            points[mp[a]]++;
        }
        //sort(vec2.begin(),vec2.end());
        sz1 = vec2.size();
        //mx = vec2[sz1-1];
        mx += 4;
        mx *= 2;
        vec.assign(mx, 0);
        for(int i=0;i<sz1;i++){
            for(int j=i;j<sz1;j++){
                vec[ vec2[i]+vec2[j] ] += points[mp[vec2[i]]] + points[mp[vec2[j]]];
                //mx = max(mx, vec2[i]+vec2[j]);
                //msg( vec2[i]+vec2[j],points[mp[vec2[i]]] + points[mp[vec2[j]]] )
            }
        }
        //msg("MAX", mx)
        sum =0;
        /*
        for(int i=0;i<mx;i++){
            msg(i, vec[i])
        }
        */
        for(int i=0;i<mx;i++){
            sum += vec[i];
            vec[i] = sum;
        }
        printf("Case %lld:\n",caseCounter++);
        for(int i=0;i<q;i++){
            scanf("%lld%lld%lld%lld", &a, &b,&c,&d);
            a = max(a,b);
            a = min(a, mx);
            b = min(c,d);
            b = min(b,mx);
            printf("%lld\n", (vec[b] -vec[a-1]) /2-1);
        }

    }


    return 0;
}
