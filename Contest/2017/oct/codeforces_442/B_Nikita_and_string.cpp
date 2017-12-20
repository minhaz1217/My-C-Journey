#include<bits/stdc++.h>
using namespace std;
#define check(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;

int main(){

    string str;
    cin >> str;
    int start,i,aCounter,bCounter;
    int ss[str.length()+1];
    char cc[str.length()+1];
    char curr,prev;
    curr = str[0];
    start = 0;
    vector< pair<char ,int> > v;
    aCounter =0;
    bCounter = 0;
    prev = str[0];
    for(i=0;str[i];i++){
        if(str[i] == 'a' && prev != 'a'){
            v.push_back(pair<char,int>('b', bCounter));
            cc[start] = 'b';
            ss[start] = bCounter;
            start = i;
            prev = 'a';
            aCounter = 1;
        }else if(str[i] == 'b' && prev!= 'b'){
            v.push_back(pair<char,int>('a', aCounter));
            cc[start] = 'a';
            ss[start] = aCounter;
            start = i;
            prev = 'b';
            bCounter = 1;
        }else if(str[i] == prev){
            if(str[i] == 'a'){
                aCounter++;
            }else if(str[i] == 'b'){
                bCounter++;
            }
        }
    }

    if(prev == 'a'){
        v.push_back(pair<char,int>('a', aCounter));

    }else{
        v.push_back(pair<char,int>('b', bCounter));
    }
    int firstType = 0,secondType = 0, thirdType =0,fourthType = 0,fifthType=0;
    for(i=0;i<v.size();i++){
        if(v[i].first == 'a' && v[i+1].first == 'a'){
            firstType = max(firstType, v[i].second + v[i+1].second);
        }
        if(v[i].first == 'a' && v[i+1].first == 'b'){
            thirdType = max(thirdType, v[i].second + v[i+1].second);
        }
        if(v[i].first == 'b' && v[i+1].first == 'a'){
            secondType = max(secondType, v[i].second + v[i+1].second);
        }
        if(v[i].first == 'a' && v[i+1].first == 'b' && v[i+2].first == 'a'){
            fourthType = max(fourthType, v[i].second + v[i+1].second + v[i+2].second);
        }
        fifthType = max(fifthType, v[i].second);
    }
    cout << max(firstType, max(secondType, max(thirdType, max(fourthType, fifthType)))) << endl;


    return 0;
}
