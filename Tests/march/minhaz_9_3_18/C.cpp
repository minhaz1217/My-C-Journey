#include<bits/stdc++.h>
using namespace std;
#define cc(a) cout << a << endl;
#define check(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c<< endl;

struct point{
    double x,y;
    point(double aa, double bb){
        x = aa;
        y = bb;
    }
};
double dist(point b, point a){
    //return
    double ans= (sqrt( (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y)));
    //cc(ans);
    return ans*ans;
}
int main(){
    double a,b,sum;
    int i,j,sz;
    int tc;
    cin >> tc;
    vector<point>vec;
    while(tc--){
        scanf("%lf%lf", &a, &b);
        //msg(a,b)
        //cin >> a >> b;
        point p(a,b);
        vec.push_back(p);
        /*
        if(mp[p]){
            mp[p] = 1;
            vec.push_back(p);
        }else{
            mp[p]++;
        }
        */
    }

//        vec.push_back(p);
        sz = vec.size();
        sum = 0;
        for(i=0;i<sz;i++){
            for(j=0;j<i;j++){
                sum += dist(vec[i], vec[j]);
            }
        }
        printf("%.0lf" , sum);
    return 0;
}
