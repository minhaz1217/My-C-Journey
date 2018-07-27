#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;
int counter;
int gcd(int a, int b){
    if(a<b){
        swap(a,b);
    }
    msg(a,b)
    if(b == 0){
        return a;
    }
    counter++;
    return gcd(b, a%b);

}

int main(){
    long long int c, a,b,i,turn;
    while(1){
        scanf("%lld%lld", &a, &b);
        if(a==0 && b ==0){
            break;
        }
        c = __gcd(a,b);
        /*
        msg("GCD", __gcd(a,b))
        if(a==0 && b ==0){
            break;
        }
        counter = 0;
        if(a<b){
            swap(a,b);
        }
        turn = 1;
        while(a!= 0 && b!=0){
            if(a<b){
                swap(a,b);
            }
            //msg(a,b)
            for(i=1;i<=b;i++){
                if(i*b > a){
                    break;
                }
            }
            i--;
            if(turn == 1){
                if(i%2 == 0){
                    i--;
                    a = a- (b*i);
                    turn = 2;
                }else{
                    a = a- (b*i);
                }
            }else{
                if(i%2 == 0){
                    a = a- (b*i);
                }else{
                    i--;
                    a = a- (b*i);
                    turn = 1;
                }
            }
        }
        //msg("RES", turn)
        if(turn == 1){
            printf("Stan wins\n");
        }else{
            printf("Ollie wins\n");
        }
        //cc(counter)
        */
        if(c %2 == 0){
            printf("Stan wins\n");
        }else{
            printf("Ollie wins\n");
        }
    }

    return 0;
}
