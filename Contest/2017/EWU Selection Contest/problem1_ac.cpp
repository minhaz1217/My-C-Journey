#include<bits/stdc++.h>
using namespace std;
#define check(a) cout<<a<< endl;
int main(){
    int n,m,small;
    cin >> n >> m;
    small = n<=m? n:m;
    if(small %2 == 0){
        cout << "Galib" << endl;
    }else{
        cout << "Arif" << endl;
    }


	return 0;
}
