#include<iostream>
using namespace std;
int main(){
    int tc, i,n;
    cin >> tc;
    while(tc--){
        cin >> n;
        for(i=0;i<=n;i++){
            cout << i;
            if(i!=n){
                cout << " ";
            }
        }
        cout << endl;
    }
	return 0;
}
