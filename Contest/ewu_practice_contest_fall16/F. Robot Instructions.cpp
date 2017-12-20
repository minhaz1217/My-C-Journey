#include<bits/stdc++.h>
using namespace std;
#define check(a) cout<<a<< endl;
int main(){
    long long tc,counter, num,sum = 0,i;
    string str;
    cin >> tc;
    while(tc--){
        cin >> counter;
        long long instructions[counter+1];
        for(i=1;i<=counter;i++ ){
            cin >> str;
            if(str == "LEFT"){
                instructions[i] = -1;
            }else if(str == "RIGHT"){
                instructions[i] = 1;
            }else{
                cin >> str >> num;
                instructions[i] = instructions[num];
            }
        }
        sum = 0;
        for(i=1;i<=counter;i++){
            sum += instructions[i];
        }
        cout << sum << endl;
    }

	return 0;
}
