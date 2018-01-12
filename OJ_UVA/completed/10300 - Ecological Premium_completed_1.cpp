#include<iostream>
using namespace std;
int main(){
    long long int tk,f,s,a,e,sum=0;
    cin >> tk;
    while(tk--){
        cin >> f;
        sum =0;
        while(f--){
            cin >> s >> a >> e;
            sum+= s*e;
        }
        cout << sum << endl;
        if(cin.eof()){
            break;
        }

    }
	return 0;
}
