#include<bits/stdc++.h>
using namespace std;
#define check(a) cout<<a<< endl;
int main(){
    int i,a=100,sum = 0,pw = 4,md = 5;
    for(i=1;i<=a;i++){
        sum += pow(i,pw);
    }
    cout << "Sum: " << sum << endl;
    cout << "Mod: " << sum%md << endl;
    sum = 0;
    for(i=1;i<=a;i++){
        int x = pow(i,pw);
        sum += x % md;
    }
    cout << "Sum: " << sum << endl;
    cout << "Sum mod: " << sum % md << endl;




	return 0;
}
