#include<bits/stdc++.h>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;







struct point{
    double x,y;
    point(){
        x = 0;
        y=0;
    }
    point(double xx, double yy){
        x = xx;
        y = yy;
    }
};

double calculateDist(point a, point b){
    double d = sqrt( ((b.x - a.x)*(b.x - a.x)) + ((b.y - a.y)*(b.y - a.y)) );
    //cout << a.x << "," << a.y << "->" << b.x << "," << b.y<< " = " << d <<endl;
    return d;
}
struct triangle{
    point arm1, arm2,arm3;
    double dist12, dist23, dist31;
    triangle(double a , double b,double c, double d,double e, double f){
        arm1.x = a;
        arm1.y = b;
        arm2.x = c;
        arm2.y = d;
        arm3.x = e;
        arm3.y = f;
        dist12 = calculateDist(arm1, arm2);
        dist23 = calculateDist(arm2, arm3);
        dist31 = calculateDist(arm3, arm1);
    }
        triangle(){
        arm1.x = 0;
        arm1.y = 0;
        arm2.x = 0;
        arm2.y = 0;
        arm3.x =0;
        arm3.y = 0;
        dist12 = 0;
        dist23 = 0;
        dist31 = 0;
    }
};

double triangleArea(triangle t){
    double s;
    s = (t.dist12 + t.dist23 + t.dist31) / 2;
    double d = sqrt( s*(s-t.dist12)*(s-t.dist23)*(s-t.dist31) );
    return d;
}
double triangleArea(double a, double b, double c){
    double s;
    s = (a + b+ c) / 2;
    double d = sqrt( s*(s-a)*(s-b)*(s-c) );
    return d;
}
int checkInsideTriangle(triangle t, point p){
    double mainArea = (double)triangleArea(t);
    double p31 = (double)triangleArea(t.dist31, calculateDist(p, t.arm1), calculateDist(p,t.arm3));
    double p12 = (double)triangleArea(t.dist12, calculateDist(p, t.arm1), calculateDist(p,t.arm2));
    double p23 = (double)triangleArea(t.dist23, calculateDist(p, t.arm2), calculateDist(p,t.arm3));
    double d = (p12+p23+p31);

    if(p31 == 0 || p12 == 0 || p23 == 0){
        return 0;
    }

    if(fabs(mainArea - d) <=.000000009 ){
        //msg(mainArea, (p31+p12+p23))
        //cc("YES")
        return 1;
    }else{
        //msg(mainArea, (p31+p12+p23))
        //cc("NO")
        return 0;
        eps(4);
    }

}
struct rect{
    point top,down;
    rect(int a,int b,int c, int d){
        top.x = a;
        top.y = b;
        down.x = c;
        down.y = d;
    }
};
int checkRect(rect r, point p){
    if(p.x > r.top.x && p.x < r.down.x && p.y<r.top.y && p.y > r.down.y){
        return 1;
    }else{
        return 0;
    }
}

struct circle{
    point center;
    double radius;
    circle(double xx ,double yy, double rr){
        center.x = xx;
        center.y = yy;
        radius = rr;
    }
};

int checkCircle(circle c, point p){
    double d1 = calculateDist(c.center, p);
    if( d1 < c.radius ){
        return 1;
    }else{
        return 0;
    }
}

int main(){

        //setprecision(5);
        ios::fixed;
        char ch,type;
        double flag,t,a,b,c,d,e,f,g,h,counter = 1,i,pointCounter,pos,ans;
        vector<triangle>tri;
        vector<pair<char,int> >vec;
        vector<rect>rec;
        vector<circle>cir;
    while(1){
        cin >> ch;
        if(ch == '*'){
            break;
        }

        if(ch == 't'){
            cin >> a >> b >> c >> d >> e >> f;
            counter++;
            //mp[counter] = ch;
            tri.push_back( triangle(a,b,c,d,e,f) );
            vec.push_back(make_pair(ch, tri.size()-1));
        }else if(ch == 'r'){
            cin >> a >> b >> c >> d;
            rec.push_back( rect(a,b,c,d) );
            vec.push_back(make_pair(ch, rec.size()-1));
        }else if(ch == 'c'){
            cin >> a >> b >> c;
            cir.push_back( circle(a,b,c) );
            vec.push_back(make_pair(ch, cir.size()-1));
        }
    }
    pointCounter = 0;
    while(1){
        cin >> a >> b;
        if(a == 9999.9 && b == 9999.9){
            break;
        }
        point p(a,b);
        pointCounter++;
        flag = 0;
        for(i=0;i<vec.size();i++){
            type = vec[i].first;
            pos = vec[i].second;
            if(type == 'r'){
                ans = checkRect(rec[pos], p);
            }else if(type == 'c'){
                ans = checkCircle(cir[pos], p);
            }else{
                ans = checkInsideTriangle(tri[pos], p);
            }

            if(ans == 1){
                flag = 1;
                printf("Point %.0lf is contained in figure %.0lf\n",pointCounter, i+1);
            }
        }
        if(flag == 0){
                printf("Point %.0lf is not contained in any figure\n",pointCounter);

        }
    }

    return 0;
}
