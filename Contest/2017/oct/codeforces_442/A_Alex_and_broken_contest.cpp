#include<bits/stdc++.h>
using namespace std;
#define msg(a,b) cout << a << " : " << b << endl;

pair<int, string> check(string str, int pos1, int pos2){
    int i,k;

    if(!(pos2 -pos1 >= 3)){
        return pair<int, string>(-1, "");
    }
    msg(str, pos1) ;
    //msg(pos1, pos2);
    string names[] = {"danil", "olya", "slava", "ann", "nikita"};
    for(i=0;i<=4;i++){
        k = str.find(names[i]);
        if(k>=pos1 && k < pos2){
            if(k+names[i].length()-1 <= pos2){
                //return k;
                return pair<int, string>(k, names[i]);
            }
        }
    }
    return pair<int, string>(-1, "");
}




int main(){
    int i,k,counter = 0;
    string str;

    cin >> str;
    std::transform(str.begin(), str.end(), str.begin(), ::tolower);
    pair<int, string> ck = check(str, 0, str.length()-1), ck1,ck2;
    if(ck.first == -1){
        cout << "NO" << endl;
    }else{
        ck1 = check(str, 0, ck.first-1);
        ck2 = check(str, ck.first + ck.second.length(), str.length()-1);
        cout << ck1.first << ck2.first << endl;
        if(ck1.first == -1 && ck2.first == -1){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }

    return 0;
}
