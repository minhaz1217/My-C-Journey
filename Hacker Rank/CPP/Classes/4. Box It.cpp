#include<bits/stdc++.h>
using namespace std;
class Box{
    long long l,b,h;
    public:
    Box(){
        l=0;
        b=0;
        h=0;
    }
    Box(int n1,int n2, int n3){
        l = n1;
        b = n2;
        h = n3;
    }
    Box(Box &bb){
        l = bb.l;
        b = bb.b;
        h = bb.h;
    }
    int getLength(){
        return l;
    }
    int getBreadth(){
        return b;
    }
    int getHeight(){
        return h;
    }
    long long CalculateVolume(){
        long long ll = l*b*h;
        return (ll);
    }

    bool operator<(Box &B){
        if(l < B.l){
            return 1;
        }else if(b < B.b && l == B.l ){
            return 1;
        }else if(h < B.h && b == B.b && l == B.l){
            return 1;
        }else{
            return 0;
        }
    }


};
ostream& operator<<(ostream& out, Box &B){
    out << B.getLength() << " " << B.getBreadth() << " " << B.getHeight();
    return out;
}
int main(){
    Box b1, b2;
        cout << b1 << endl;
    cout << (b1<b2) << endl;



    return 0;
}
