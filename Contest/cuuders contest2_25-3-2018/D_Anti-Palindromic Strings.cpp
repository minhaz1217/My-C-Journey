#include<bits/stdc++.h>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a  << " : " << b << endl;
#define msg2(a,b,c) cout << a  << " : " << b << " : " << c << endl;
int main(){
    string str = "aaaaa",str2= "aaaaa";
    int i,j,w = 6,counter = 0, palin = 0,k,l,m;
    for(i=0;i<w;i++){
        for(j=i;j<w;j++){
            for(k=j;k<w;k++){
                for(l=k;l<w;l++){
                    for(m=l;m<w;m++){
                        str[0] = i + 'A';
                        str[1] = j + 'A';
                        str[2] = k + 'A';
                        str[3] = l + 'A';
                        str[4] = m + 'A';
                        str[5] = '\0';
                        counter++;
                        str2 = str;
                        reverse(str.begin(), str.end());
                            //msg(str, str2)
                            if(str == str2){
                                    cc(str)
                                palin++;
                            }
                        }
                    }
                }


            //cout << str << endl;
        }
    }
    msg(palin, counter);
    //cout << counter << endl;



    return 0;
}
