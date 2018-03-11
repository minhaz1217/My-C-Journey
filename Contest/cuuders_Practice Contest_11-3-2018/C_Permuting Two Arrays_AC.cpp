#include<bits/stdc++.h>
using namespace std;
#define cc(a) cout << a << endl;
#define check(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;


int main(){
    long long int n,k,a;
    int tc,i,flag = 1;
    scanf("%d", &tc);
    while(tc--){

        vector<long long int> vec,vec2;
        scanf("%lld%lld", &n , &k);
        for(i=0;i<n;i++){
            scanf("%lld", &a);
            vec.push_back(a);
        }
        for(i=0;i<n;i++){
            scanf("%lld", &a);
            vec2.push_back(a);
        }
        sort(vec.begin(), vec.end());
        sort(vec2.begin(),vec2.end());
        reverse(vec2.begin(),vec2.end());
        flag = 1;
        for(i=0;i<n;i++){
            if(vec[i] + vec2[i] < k){
                flag = 0;
                //msg2(vec[i], vec2[i], vec[i]+vec2[i])
                break;
            }
        }
        if(flag == 1){
            printf("YES\n");
        }else{
            printf("NO\n");
        }

    }

    return 0;
}
