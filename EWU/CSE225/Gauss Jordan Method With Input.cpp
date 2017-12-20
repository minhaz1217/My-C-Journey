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
    printf("%.2lf  %.2lf  %.2lf = %.2lf\n\n", a31, a32, a33,r);

}
int main(){
    scanf("%lf  %lf  %lf %lf", &a11, &a12, &a13,&p);
    scanf("%lf  %lf  %lf %lf", &a21, &a22, &a23,&q);
    scanf("%lf  %lf  %lf %lf", &a31, &a32, &a33,&r);


    cout << "Actual Equatinos: " << endl;
    display();
    if(a11 == 0){
        swap(a11,a21);
        swap(a12,a22);
        swap(a13,a23);
        swap(p,q);

        /*
        a11 = a11 + a21/a21;
        a12 = a12 + a22/a21;
        a13 = a13 + a23/a21;
        p = p + q/a21;
        */
        cout << "First equation zero: " << endl;
        display();
    }
    if(a11 != 1 && a11!= 0){
        a12 = a12/a11;
        a13 = a13/a11;
        p = p/a11;
        a11 = 1;
        cout << "After Normalizing: " << endl;
        display();
    }
    a22 = a22 - a21*a12;
    a23 = a23 - a21*a13;
    q = q - a21*p;
    a21 = a21 - a21 * a11;
    cout << "Making 1st with 2nd: " << endl;
    display();

    a32 = a32 - a12*a31;
    a33 = a33 - a13*a31;
    r = r-p*a31;
    a31 = a31 - a11*a31;
    cout << "After making 1st and 3rd: " << endl;
    display();
    if(a22 == 0){

        swap(a22, a32);
        swap(a23, a33);
        swap(q,r);
        /*
        a22 = a22 + a32/a32;
        a23 = a23 + a33/a32;
        q = q+ r/a32;
        */
        cout << "2nd Equation zero: " << endl;
        display();
    }
    if(a22 != 1 && a22!=0){
        a23 = a23/a22;
        q = q/a22;
        a22 = 1;
        cout << "After Normalizing: " << endl;
        display();
    }

    a13 = a13 - a23 * a12;
    p = p - q *a12;
    a12 = a12 - a22*a12;
    cout << "After making 2nd and 1st: " << endl;
    display();
    a33 = a33 - a23 * a32;
    r = r - q *a32;
    a32 = a32 - a22*a32;
    cout << "After making 2nd and 3rd: " << endl;
    display();
    if(a33 != 1 && a33 != 0){
        r = r/a33;
        a33 = 1;
        cout << "After normalizing: " << endl;
        display();
    }

    p = p - r*a13;
    a13 = a13 - a33*a13;
    cout << "After making 3rd and 1st: " << endl;
    display();

    q = q - r*a23;
    a23 = a23 - a23*a33;
    cout << "After making 3rd and 2nd: " << endl;
    display();

    printf("Answer: (x,y,z) = (%.2lf,%.2lf,%.2lf)\n\n\n", p,q,r);

    return 0;
}
