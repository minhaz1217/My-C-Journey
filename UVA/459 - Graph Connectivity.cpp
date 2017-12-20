//disjoint set union

#include<bits/stdc++.h>
#include<conio.h>
using namespace std;
#define check(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;



int main(){
    int tc,counter,n,i,chCounter = 0;
    char a,b,c;

    cin >> tc;
    while(tc--){
        cin >> c;
        counter = 0;
        n = c - 'A'+1;
        int par[n];
        for(i=0;i<n;i++){
            par[i] = i;
        }
        while(1){
            a = getch();
            if( !((int)a >='A' && (int)a <= 'Z') && chCounter == 0){
                //check("breaking")
                break;
            }else if(!((int)a >='A' && (int)a <= 'Z') && chCounter >= 2){
                chCounter = 0;
                continue;
            }else{
                chCounter++;
                //cout << a <<endl;
            }
            b = getch();
            //cout << b << endl;
            chCounter++;
            //check(chCounter)
            //par[min(a - 'A', b- 'A')] = max(a - 'A', b - 'A');
            if(par[b-'A'] != a-'A'){
                par[a-'A'] = b - 'A';
            }
        }
        for(i=0;i<n;i++){
            //msg(i, par[i])
            if(par[i] == i){
                counter++;
            }
        }
        cout << counter << endl;
    }

    return 0;
}
