#include<bits/stdc++.h>
using namespace std;
#define check(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;

int main(){
    long long tc,x1,x2,y1,y2,caseCounter = 1;
    cin >> tc;
    while(tc--){
        cin >> x1 >> y1 >> x2 >> y2;
        x1 = min(x1, y1);
        y1 = min(x1, y1);
        x2 = min(x2, y2);
        y2 = min(x2, y2);
        if(x1 <0 || x2 <0){
            cout << "Case "<< caseCounter++ << ": ";
            cout << min(abs(x1-x2), abs(y1-y2)) + 1<<endl;
        }else{
            cout << "Case "<< caseCounter++ << ": ";
            cout << min(abs(x1-x2), abs(y1-y2))<<endl;
        }
    }

    return 0;
}
