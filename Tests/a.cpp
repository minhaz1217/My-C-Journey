//LOJ 1354


#include<iostream>
#include<cmath>
using namespace std;
#define check(a) cout<<a<< endl;
int main(){
    char ch;
    int a,b,c,d,p,q,r,s,counter = -1,tc,caseCounter = 1;

    cin >> tc;
    while(tc--){
        cin >> a >> ch>> b >> ch >> c >> ch >> d;
        cin >> p >> ch>> q >> ch >> r >> ch >> s;
        counter = -1;
        for(;p!=0;){
            counter++;
            if(p%10 == 1){
                a -= pow(2 , counter);
            }
            p = p/10;
        }
        counter = -1;
        for(;q!=0;){
            counter++;
            if(q%10 == 1){
                b -= pow(2 , counter);
            }
            q = q/10;
        }
        counter = -1;
        for(;r!=0;){
            counter++;
            if(r%10 == 1){
                c -= pow(2 , counter);
            }
            r = r/10;
        }
        counter = -1;
        for(;s!=0;){
            counter++;
            if(s%10 == 1){
                d -= pow(2 , counter);
            }
            s = s/10;
        }
        counter = -1;
        if(a == 0 && b == 0&& c==0 &&d==0){
            cout << "Case " << caseCounter++ <<": " << "Yes" << endl;
        }else{cout << "Case " << caseCounter++ <<": " << "No" << endl;
        }


    }
	return 0;
}
