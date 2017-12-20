#include<bits/stdc++.h>
using namespace std;
int main(){
    int tc,i,n,m,sum,counter=0,sign = 1,caseCounter = 1;
    cin >> tc;
    while(tc--){
        cin >> n >> m;
        counter = 0;
        sum = 0;
        sign = 1;
        for(i=1;i<=n;i++){
            if(sign == 1){
                sum -= i;
            }else{
                sum +=i;
            }
            counter++;
            if(counter == m){
                counter =0;
                sign*=-1;
            }
        }
        cout << "Case " << caseCounter++ << ": " << sum << endl;
    }

	return 0;
}
