// Very easy Permutation problem
#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;
#define msg3(a,b,c,d) cout << a << " : " << b << " : " << c << " : " << d << endl;

string convToString(vector<char> vec){
    string str;
    for(int i=0;i<vec.size();i++){
        str.push_back(vec[i]);
    }
    return str;
}

int main(){

    string str[] = { "RAKIBUL","ANINDYA", "MOSHIUR","SHIPLU","KABIR","SUNNY","OBAIDA","WASI"};
    string hor[] = {
        "OBIDAIBKR",
        "RKAULHISP",
        "SADIYANNO",
        "HEISAWHIA",
        "IRAKIBULS",
        "MFBINTRNO",
        "UTOYZIFAH",
        "LEBSYNUNE",
        "EMOTIONAL"
    };

    string ver[] = {
        "ORSHIMULE",
        "BKAERFTEM",
        "IADIABOBO",
        "DUISKIYST",
        "ALYAINZYI",
        "IHAWBTINO",
        "BINHURFUN",
        "KSNILNANA",
        "RPOASOHEL"
    };
    string mn = "MINHAZ";
    //cout << mn.end() << endl;
/*
    string currStr, nextStr,src,check;
    int counter = 0;
    vector<int>arr;
    arr.assign(8,0);
    vector<char>vec1,vec2;
    for(int i=0;i<8;i++){
        currStr = str[i];
        vec1.clear();
        vec2.clear();
        for(int j=0;j<currStr.size();j++){
            vec1.push_back(currStr[j]);
        }
        vec2 = vec1;
        next_permutation(vec2.begin(), vec2.end());
        while(vec2!=vec1){
            check = convToString(vec2);
            //cc(check)
            for(int k=0;k<9;k++){
                src = hor[k];
                if(src.find(check)!= string::npos ){
                    msg2("HOR", check, src)
                    arr[i]++;
                }
                src = ver[k];
                if(src.find(check)!= string::npos ){
                    msg2("VER", check, src)

                    arr[i]++;
                }
            }

            next_permutation(vec2.begin(), vec2.end());
        }
    }
    for(int i = 0;i<8;i++){
        msg2(i, arr[i], str[i])
    }
    */
    cout << "KABIR" << endl;
    return 0;
}
