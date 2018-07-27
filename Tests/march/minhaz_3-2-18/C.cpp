#include<bits/stdc++.h>
#include<conio.h>
using namespace std;
#define cc(a) cout << a << endl;
#define check(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c<< endl;

int main(){
    int tc,i,j,k,matchFound,counter, counter2,mCounter1, mCounter2,a;
    char c;
    string str1, str2;
    int mm,s1,s2;
    cin >> tc;
    vector<char>v1,v2;
    while(tc--){
        counter = 0;
        cin >> str1 >> str2;
        s1 = str1.size();
        s2 = str2.size();
        mm =max(s1, s2);
        v1 = vector<char>(str1.begin(),str1.end());
        v2 = vector<char>(str2.begin(), str2.end());
        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end());
        for(i=0;i<mm;i++){
            if(v1[i] != v2[i]){
                break;
            }else{
                counter++;
            }
        }
        cout << counter << endl;
        /*
        for(i=0;i<mm;i++){
            if(i < s1){
                v1.push_back((int)str1[i]);
            }
            if(i < s2){
                v2.push_back((int)str2[i]);
            }
        }*/
    }

    return 0;
}
