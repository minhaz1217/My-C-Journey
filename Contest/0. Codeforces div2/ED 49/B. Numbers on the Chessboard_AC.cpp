#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;
#define msg3(a,b,c,d) cout << a << " : " << b << " : " << c << " : " << d << endl;

int main(){
    long long int n,q,a,b,i,j,ans;
    scanf("%lld%lld", &n, &q);
    while(q--){
        scanf("%lld%lld", &i, &j);
        if( (j+i) %2 == 0){
            ans = ((n-1)*(i-1)+(i+j)) /2;
        }else{
            if(n%2 == 0){
                if(i%2 == 0){
                    j++;
                }else{
                    j--;
                }
                ans = ((n-1)*(i-1)+(i+j)) /2;
               // msg("HI", ans)
                ans += (ceil(n*n/2));
            }else{
                if(i%2 == 0){
                    if(j == 1){
                        j = n;
                        i--;
                    }else{
                        j--;
                    }
                }else{
                    j--;
                }
                ans = ((n-1)*(i-1)+(i+j)) /2;
                ans += (ceil(n*n/2))+1;
            }

/*

            if(i%2 == 0){
                //left shift
                if(n%2 == 0){
                    j--;
                    ans = ((n-1)*(i-1)+(i+j)) /2;
                }else{
                    if(j == 1){
                        j = n;
                        i--;
                        ans = ((n-1)*(i-1)+(i+j)) /2;
                        ans++;
                    }else{
                        j++;
                        ans = ((n-1)*(i-1)+(i+j)) /2;

                    }
                    j++;
                }
                //msg("ANS", ans)
                ans += (ceil(n*n/2));
            }else{
                if(n%2 == 0){
                    j++;
                    ans = ((n-1)*(i-1)+(i+j)) /2;

                    ans += (ceil(n*n/2));
                }else{
                    j--;
                    ans = ((n-1)*(i-1)+(i+j)) /2;

                    ans += (ceil(n*n/2))+1;
                }
            }*/
        }
        //msg("ANS", ans)
        //cout << ans << endl;
        printf("%lld\n",ans);
    }
    return 0;
}
