#include<bits/stdc++.h>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;
#define msg3(a,b,c,d) cout << a << " : " << b << " : " << c << " : " << d << endl;

int main(){
    int caseCounter = 1;
    double tc,a,sum,flag,b;
    int result;
    string str;
    string c;
    cin >> tc;
    cin.ignore();
    while(tc--){
        getline(cin, str);
        stringstream ss(str);
        a = 0;
        b = 0;
        //cc(str.size())
        if(str.size() >= 6){
            ss >> a >> c >> b >>c;
            //msg(a,b)
            sum = (0.5 * a) + (.05*b);
        }else{

            ss >> a >> c;
            //cc(a)
            sum = (.5*a);
        }
        result = a * 50 + b * 5;

        printf ("Case %d: %d",caseCounter++, result / 100);

        result %= 100;

        if ( result ) {
            if (result % 10 == 0) printf (".%d", result / 10);
            else                  printf (".%d", result);
        }
        printf("\n");
}

    return 0;
}
