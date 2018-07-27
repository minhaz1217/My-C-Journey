#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;


char convert(int a){
    if(a<0){
        return ' ';
    }else{
        return (a + 'a');
    }
}
string make(int i,int j, int k,int l, int m){
    //char a[] = {convert(i), b = convert(j), c = convert(k), d = convert(l), e = convert(m)};
    char a[] = {convert(i), convert(j), convert(k), convert(l),convert(m)};
    char c[] = "AAAAA";
    int index=0,p;
    for(int p=0;p<5;p++){
        if(a[p] != ' '){
            c[index++] = a[p];
        }
    }
    c[index] = '\0';
    return c;
}


int main(){

    int i,j,n=26,k,l,m,counter = 1;
    string str = "AB";
    map<string ,int>mp;
    for(i=-4;i<n;i++){
        for(j=-3;j<n;j++){
            for(k=-2;k<n;k++){
                for(l=-1;l<n;l++){
                    for(m=0;m<n;m++){
                        if( !(m <= l || l <=  k || k <= j || j <= i) ){
                            str = make(i,j,k,l,m);
                            //msg(str, counter)
                            if(!mp[str]){
                                mp[str] = counter;
                                counter++;
                            }

                        }

                    }
                }
            }
            //cout << str << endl;
        }
    }

    while(cin >> str){
        if(mp.find(str) == mp.end()){
            printf("0\n");
        }else{
            printf("%d\n", mp[str]);
        }
    }


    return 0;
}
