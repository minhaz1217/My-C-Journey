#include<bits/stdc++.h>
using namespace std;
#define cc(a) cout << a << endl;
#define check(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b  << " : " << c << endl;

int main(){
    double a,n;
    int i, k;
    cin >> n >> k;
    double arr[(int)n+4];
    for(i=0;i<=n;i++){
        arr[i] = 0;
    }
    for(i=0;i<k;i++){
        cin >> a;
        arr[(int)a]++;
    }

    for(i=1;i<=n;i++){
        //printf("%.2lf%\n", arr[i]/n *100);
        double ans = arr[i]/(double)k * 100.00;
        //msg(ans, n)
        printf("%.2lf", ans);
        cout << "%" << endl;
    }
    return 0;
}
