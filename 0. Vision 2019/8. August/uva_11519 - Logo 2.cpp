double DEG_to_RAD(double th){
    return (th * acos(-1)/180.0);
}
typedef complex<double> point;
#define X real()
#define Y imag()
#define polar(r, t) (r) * exp(point(0,(t)))
#define rotate(v,t) (v) * exp(point(0,(t)))
#define length(v) hypot((v).Y , (v).X)



int main(){

    long long int tc,n;
    double a;
    string str;
    double x,y;
    cin >> tc;
    while(tc--){
        cin >> n;
        point p(0,0), d(1,0);
        while(n--){
            cin >> str >> a;
            if(str == "fd"){
                p = p + polar(a, 0) *d;
                //msg(x,y)
            }else if(str == "bc"){
                p = p  - polar(a, 0) *d;
            }else if(str == "lt"){
                d = rotate(d, DEG_to_RAD(a));
            }else{

                d = rotate(d, -DEG_to_RAD(a));
            }
        }
        printf("%.0f\n", length( p ));
        //cout << (int)round(pointDistance(Point(0,0), Point(x,y))) << endl;
    }

    return 0;
}
