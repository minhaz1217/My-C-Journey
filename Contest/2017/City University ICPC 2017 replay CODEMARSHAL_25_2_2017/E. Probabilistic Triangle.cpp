#include<iostream>
#include<cmath>
#include<iomanip>

using namespace std;

int main(){
    double tc,a,b,c;
    double p,area;
    cout.setf(ios::fixed);
    cin>>tc;
    while(tc--){
            area=0;
            p=0.000;
        cin>>a>>b>>c;
        p=a+b+c/2.00;
        //cout<<setprecision(6)<<p<<endl;
        area=sqrt(p*(p-a)*(p-b)*(p-c));
        cout<<setprecision(6)<<area<<endl;
    }
}
