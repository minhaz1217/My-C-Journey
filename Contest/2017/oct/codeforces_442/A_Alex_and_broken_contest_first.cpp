#include<bits/stdc++.h>
using namespace std;
#define check(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;

int main(){
    int i,k,counter = 0;
    string str;
    string names[] = {"danil", "olya", "slava", "ann", "nikita"};

    cin >> str;
    std::transform(str.begin(), str.end(), str.begin(), ::tolower);
    for(i=0;i<=4;i++){
        k = str.find(names[i]);
        if(k >=0 && k<=str.length()){
            cout << k << endl;
            counter++;
        }
    }
    cout << counter << endl;
    if(counter == 1){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }


    return 0;
}
