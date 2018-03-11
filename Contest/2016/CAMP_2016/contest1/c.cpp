#include<bits/stdc++.h>
using namespace std;
int main(){
    int tc,x1,x2,y1,y2,n,a,b,caseCounter = 1;
    cin >> tc;
    while(tc--){
        cin >> x1 >> y1 >> x2 >> y2;
        cin >> n;
        cout << "Case " << caseCounter++ <<": " << endl;
        while(n--){
            cin >> a >> b;
            if( (a > x1 && a <x2) &&( b>y1 && b<y2)){
                cout << "Yes" << endl;
            }else{
                cout << "No" << endl;
            }
        }
    }

    return 0;
}
