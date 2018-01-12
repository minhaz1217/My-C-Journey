#include<bits/stdc++.h>
using namespace std;
#define check(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
bitset<32> trans2(bitset<32> b){
    check("trans2")
    int i;
        for(i=0;i<32;i++){
            if(b[i] == 0){
                b[i] = 1;
                b[i-1] = 0;
                break;
            }
        }
        return b;
}
bitset<32> trans1(bitset<32> b){
    return bitset<32> (b.to_ulong()*2);
}
bitset<32> trans3(bitset<32> b){
    int i;
    check("trans3")
    b[0] = 1;
    for(i=1;i<32;i++){
        if(b[i] == 0){
            b[i] = 1;
            b[i-1] = 0;
            b[i-2] = 0;
            break;
        }
    }
    return b;
}
bitset<32> trans4(bitset<32> b){
    check("trans4")
    int i;
    b[0] = 1;
    for(i=4;i<32;i++){
        if(b[i] == 0){
            b[i] = 1;
            b[i-1] = 0;
            b[i-2] = 0;
            break;
        }
    }
    return b;
}

void myChange(bitset<32>b, int startPos, int oCount){
    int i;
    if(b.count() == oCount){
        return;
    }
    for(i=startPos;i<32;i++){
        if(b[i] == 0){
            b[i] = 1;
            break;
        }
    }
    for(i=i+1;i<32;i++){
        if(b[i] == 1){
            b[i];
        }
    }
}


int main(){
    int n,i;
    cin >> n;
    bitset<32> b(n);
    bitset<32> d;
    msg(b.to_ulong(), b)

    if(b.count() == 1){
        d = trans1(b);
        msg(d.to_ulong(), d)
    }else if(b[0] != 0){
        d = trans2(b);
        msg(d.to_ulong(), d)

    }else{
        b[0] = 1;
        for(i=1;i<32;i++){
            if(b[i] == 1){
                b[i] = 0;
                break;
            }
        }

    }

    return 0;
}
