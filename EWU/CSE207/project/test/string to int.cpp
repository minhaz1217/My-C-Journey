
#include<bits/stdc++.h>
using namespace std;
#define check(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
int isInteger(string s)
{
   if(s.empty() || !isdigit(s[0])) {
        return 0;
   }
   char * p ;
   strtol(s.c_str(), &p, 10) ;
   return (1) ;
}
int isInteger2(string s)
{
    int i;
    for(i=0;s[i];i++){
        if(isdigit(s[i]) == 0){
            if(s[i] == '.'){
                continue;
            }
            return 0;
        }
    }
    return 1;
}
int main(){
    check(isInteger2("99.99"))

    return 0;
}
