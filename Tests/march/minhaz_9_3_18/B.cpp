#include<bits/stdc++.h>
using namespace std;
#define cc(a) cout << a << endl;
#define check(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c<< endl;

int main(){
    int tc,a,posX,posY;
    string str,pos;
    scanf("%d", &tc);
    posX = 0;
    posY = 0;
    while(tc--){
        cin >> a >> str;
        if(posX == 0 && posY == 0){
            pos = "n";
        }else if(posX == 0 && posY == -20000){
            pos = "s";
        }else{
            pos = "";
        }
        cc(pos)
        if(pos == "n" && str == "South"){
            cc("HI")
            posY = -(a);
            cc(posY)
        }else if(pos == "s" && str == "North"){
            posY += a%20000;
        }else{
            if(str == "West"){
                posX += -1*(a%20000);
            }else if(str == "East"){
                posX += (a%20000);
            }else if(str == "North"){
                posY += a;
            }else if(str == "South"){
                posY += -1*a;
            }
        }
        msg2(str, posX, posY)

    }


    return 0;
}
