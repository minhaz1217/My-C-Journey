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
        vec.assign(1000004,0);
        scanf("%lld%lld", &n,&q);
        points.assign(n+4,0);
        for(int i=0;i<n;i++){
            cin >> a >> b;
            vec2.push_back(a);
            /*
            if(!mp[a]){
                mp[a] = counter++;
                vec2.push_back(a);
            }
            points[mp[a]]++;
            */
        }
        sz1 = vec2.size();
        mx = INT_MIN;
        for(int i=0;i<sz1;i++){
            for(int j=i;j<sz1;j++){
                vec[ vec2[i]+vec2[j] ] += 2;
                /*
                vec[ vec2[i]+vec2[j] ] += points[mp[vec2[i]]] + points[mp[vec2[j]]];
                //mx = max(mx, vec2[i]+vec2[j]);
                //msg( vec2[i]+vec2[j],points[mp[vec2[i]]] + points[mp[vec2[j]]] )
                */
            }
        }
        //msg("MAX", mx)
        sum =0;
        /*
        for(int i=0;i<mx;i++){
            msg(i, vec[i])
        }
        */
        for(int i=0;i<1000004;i++){
            sum += vec[i];
            vec[i] = sum;
        }
        printf("Case %lld:\n",caseCounter++);
        for(int i=0;i<q;i++){
            scanf("%lld%lld%lld%lld", &a, &b,&c,&d);
            a = max(a,b);
            b = min(c,d);
            printf("%lld\n", (vec[b] -vec[a-1]) /2-1);
            //cout << (vec[b] -vec[a-1]) /2-1 << endl;
        }

    }


    return 0;
}
