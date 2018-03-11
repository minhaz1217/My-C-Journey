#include<bits/stdc++.h>
using namespace std;
#define cc(a) cout << a << endl;
#define check(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;

#define MX 2000004

//long long int arr[MX];
int main(){
    int tc,i,caseCounter = 1,maap, counter,curr;
    long long int n,a;
    scanf("%d", &tc);
    while(tc--){
        //map<long long int, int> mp;
        vector<long long int>vec;
        //st.clear();
        scanf("%lld", &n);
        maap = 1;
        counter =0;
        for(i=0;i<n;i++){
            scanf("%lld", &a);
            vec.push_back(a);
            //st.insert(a);
        }
        sort(vec.begin(), vec.end());
        if(n>0){
            curr = vec[0];
            counter = 1;
            for(i=1;i<n && counter <= 2000000;i++){
                if(vec[i] != curr){
                    counter++;
                    curr = vec[i];
                }
            }
            printf("Case %d: %d\n",caseCounter++, counter);

        }else{
            printf("Case %d: 0\n",caseCounter++);
        }
        //a = st.size();
        //printf("Case %d: %d\n",caseCounter++, counter);
    }
    return 0;
}
