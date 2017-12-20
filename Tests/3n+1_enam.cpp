#include<bits/stdc++.h>

using namespace std;

int main(){
    int i,a,b,n,max,counter=0,temp;
    //for(;;){
    cin>>a>>b;
    if(a>b){
       max=0;
    for(i=a;i>=b;i--){
            counter=1;
            n=i;
        while(n!=1){
            if((n%2)==0){
                n=n/2;
                counter++;
            }
            else{
                n=(3*n+1);
                counter++;
            }
        }
            if(counter>max){
                max=counter;
            }

    }
    cout<<a<<" "<<b<<" "<<max<<endl;
}
    else{
    max=0;
    for(i=b;i>=a;i--){
            counter=1;
            n=i;
        while(n!=1){
            if((n%2)==0){
                n=n/2;
                counter++;
            }
            else{
                n=(3*n+1);
                counter++;
            }
        }
            if(counter>max){
                max=counter;
            }

    }
    cout<<a<<" "<<b<<" "<<max<<endl;
}
    //}
}

