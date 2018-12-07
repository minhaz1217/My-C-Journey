#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;

int main(){
    long long int tc,p,l,i,rt,q,sz,caseCounter = 1;
    scanf("%lld",&tc);
    while(tc--){
        scanf("%lld%lld", &p, &l);
        set<long long int>vec;
        q = p-l;
        if(q<p/2){
            printf("Case %lld: impossible\n", caseCounter++);
        }else{
            rt = sqrt(p)+1;
            for(i=1;i<=rt;i++){
                    if(q%i == 0){
                        if(i > l){
                            vec.insert(i);
                        }
                        if(q/i > l){
                            vec.insert(q/i);
                        }
                    }
                }
                vector<long long int>v(vec.begin(), vec.end());
                //copy(vec.begin(), vec.end(), v);
                sort(v.begin(), v.end());

                sz = vec.size();

                printf("Case %lld:", caseCounter++);
                if(sz>0){
                for(i=0;i<sz;i++){
                    printf(" %lld", v[i]);
                }
                }else{
                    printf(" impossible");
                }
                printf("\n");
            }
        }


    return 0;
}
