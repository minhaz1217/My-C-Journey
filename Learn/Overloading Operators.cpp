#include<bits/stdc++.h>
using namespace std;
class Box{
    int l,b,h;
public:
    Box(){}
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
        return (l*b*h);
    }
    //overloading less than (<) operator
    bool operator<(Box bb){
        //cout << Box::CalculateVolume() << endl << bb.CalculateVolume() << endl;
        // or we can you just CalculateVolume() without the Box:: mark
        if(CalculateVolume() < bb.CalculateVolume()){
            return 1;
        }else{
            0;
        }
    }




};
ostream& operator<<(ostream& out, Box bb){
    out << bb.CalculateVolume() << endl;
}
int main(){
    Box b(4,5,6), b2(10,20,30);
    cout << "First Volume: "  << b.CalculateVolume() << endl;
    cout << "Comparing: " << (b < b2 )<< endl;
    cout << b << endl;
    return 0;
}
