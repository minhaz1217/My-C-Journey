#include<bits/stdc++.h>
using namespace std;
#define check(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;

int main(){
    int n,i,j,k,l,mm;
    cin >> n;
    //for(n = 0;n<=2501;n++){

    //int karr[n+4] = {0};
    int counter = 0;
    int found = 1;
    for(i=1;i<=n ;i++){
        found = 0;
        for(j=i;j<=n;j++){
           mm = min(i+j,n);
            //mm = n;
            k = i^j;
            if(i+j>k && k<=n && k>=j){
                counter++;
            }
            /*
            for(k=j;k<=mm;k++){
                if( ((i^j)^k) == 0 && i+j > k){
                    //cout << i << " " << j << " " << k << endl;
                    //karr[j] = 1;
                    counter++;
                }
            }
            */
        }
    }
    printf("%d\n", counter);
    //printf("%d, ", counter);
    //}
    return 0;
}
