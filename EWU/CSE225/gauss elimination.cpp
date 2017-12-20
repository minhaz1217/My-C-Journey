#include<bits/stdc++.h>
using namespace std;
//sample 1 , answer(1,2,1)
//double a11=3,a12=6,a13=1,a21=2,a22=4,a23=3,a31=1,a32=3,a33=2,p=16,q=13,r=9;
#define che(a) cout << endl << endl << a << endl<<endl;
//sample 2, answer(5.8, 3.2 , 5.4)
double a11=2,a12=4,a13=-6,a21=1,a22=3,a23=-1,a31=2,a32=-4,a33=-2,p=-8,q=10,r=-12;
void display(){
    printf("%.2lf  %.2lf  %.2lf = %.2lf\n", a11, a12, a13,p);
    printf("%.2lf  %.2lf  %.2lf = %.2lf\n", a21, a22, a23,q);
    printf("%.2lf  %.2lf  %.2lf = %.2lf\n", a31, a32, a33,r);



}
int main(){
    cout << "Input (a1X + a2Y, a3Z = P) : ";
    cin >> a11 >> a12 >> a13 >> p;
    cout << "Input (b1X + b2Y, b3Z = Q) : ";
    cin >> a21 >> a22 >> a23 >> q;
    cout << "Input (c1X + c2Y, c3Z = R) : ";
    cin >> a31 >> a32 >> a33 >> r;



    cout << "First Equation: " <<endl;
    display();
    if(a11 == 0 && a21 != 0){
        swap(a11,a21);
        swap(a12,a22);
        swap(a13,a23);
        swap(p,q);
    }else if(a11 == 0 && a31 != 0){
        swap(a11,a31);
        swap(a12,a32);
        swap(a13,a33);
        swap(p,r);
    }
    cout << "Selected Equation: " << endl;
    display();
    /*
    if(a11 != 1){
        a12 = a12/a11;
        a13 = a13/a11;
        p = p/a11;
        a11 = 1;
        cout << "After normalizing equation 1: " << endl;
        display();
    }
    */

    // making a21 = 0
    a22 = a22 - (a12/a11)*a21;
    a23 = a23 - (a13/a11)*a21;
    q = q - (p/a11)*a21;
    a21 = a21 - (a11/a11)*a21;

    cout << "After making 1st and 2nd equation: " << endl;
    display();
    //making a31 = 0
    a32 = a32 - (a12/a11)*a31;
    a33 = a33 - (a13/a11)*a31;
    r = r - p*(a31/a11);
    a31 = a31 - (a11/a11)*a31;
    cout << "After making 1st and 3rd equation" << endl;
    display();
    if(a22 == 0 && a32 != 0 ){
        swap(a31,a21);
        swap(a32,a22);
        swap(a33,a23);
        swap(r,q);
    }
    cout << "Selected equation 2: " << endl;
    display();
    //normalize 2nd equation
    /*
    if(a22 != 1){
        a22 = a22/a22;
        a23 = a23/a22;
        q = q/a22;
        a22 = 1;
        cout << "After normalizing selected 2nd equation: " << endl;
        display();
    }
    */
    a33 = a33 - a23*(a32/a22);
    r = r- q * (a32/a22);
    a32 = a32 - a22*(a32/a22);
    cout << "After making 2nd and 3rd equation: " << endl;
    display();
    //normalize 3rd z
    //this is z
    r = r/a33;
    q = (q - a23*r)/a22;
    p = (p - a13*r - a12*q)/a11;
    cout <<"( "<< p << " , " << q << " , " << r <<" )"<< endl;
    return 0;
}
