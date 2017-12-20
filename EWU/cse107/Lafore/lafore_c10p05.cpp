#include<iostream>
using namespace std;
#define check(a) cout<<a<< endl;
void addarrays(float *a,float *b,float *c, int n){
    for(int i=0;i<n;i++){
        c[i] = a[i] + b[i];
        //cout << *(c+i) << endl;
    }
}


int main(){
    int a = 3;
    float n1[]={1.2,2.3,3.4}, n2[] = {10.1,20.3,30.5}, n3[a];
    addarrays(n1,n2,n3,a);
    for(int i=0;i<a;i++){
        cout << n3[i] << endl;
    }



	return 0;
}
