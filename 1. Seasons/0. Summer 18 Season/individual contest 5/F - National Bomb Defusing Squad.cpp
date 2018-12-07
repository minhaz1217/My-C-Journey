#include<bits/stdc++.h>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;

#define MX 40004
int bomb[MX];
struct point{
    int x, y;
    point(int xx, int yy){
        x = xx;
        y = yy;
    }
};

double calculate(point a, point b){
    double d = sqrt( ((b.x - a.x)*(b.x - a.x)) + ((b.y - a.y)*(b.y - a.y)) );
    cout << a.x << "," << a.y << "->" << b.x << "," << b.y<< " = " << d <<endl;
    return d;
}

int main(){

    //cc(calculate(point(1,1), point(5,5)))

    while(1){
    int n,q,i,a,b,j,l,r,mid;
    double dist;
    cin >> n >> q;
    if(n == 0 && q == 0){
        break;
    }
    vector<point>vec;
    map<point, int>mp;
    vector<int>qq;
    for(i=0;i<n;i++){
        cin >> a  >> b;
        //point p= new point(a,b);
        vec.push_back(point(a,b));
    }


    for(i=0;i<MX;i++){
        bomb[i] = 0;
    }

    for(i=0;i<q;i++){
        cin >> a;
        qq.push_back(a);
    }
    sort(qq.begin(), qq.end());
    for(i=0;i<vec.size();i++){
        for(j=0;j<vec.size();j++){
            dist = calculate(vec[i], vec[j]);
            l = 0;
            r = qq.size();
            while(l<=r){
                mid = (l+r) /2;
                if(l == r-1){

                    break;
                }
                if(dist > qq[mid]){
                    l = mid;
                }else{
                    r = mid;
                }
            }
           // msg2(i,j,dist)
            bomb[qq[r]]++;
            //msg(qq[r], bomb[ qq[r] ]);
            //bomb[vec[c]] ++;
        }
    }
        for(i=0;i<qq.size();i++){
            msg(qq[i], bomb[qq[i]])
        }
    }


    return 0;
}
