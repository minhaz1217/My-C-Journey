#include<iostream>
using namespace std;
struct Time{
    int h,m,s;
};
int main(){
    Time t1,t2, diff;
    cin >> t1.h >> t1.m >> t1.s;
    cin >> t2.h >> t2.m >> t2.s;

    if(t1.h > t2.h){
            if(t1.m > t2.m){
                if(t1.s > t2.s){
                    diff.h = (t1.h - t2.h) -1;
                    diff.m = ((60-t1.m) + t2.m) - 1;
                    diff.s = ((60-t1.s) + t2.s );
                }else if(t1.s <= t2.s){
                    diff.h = (t1.h - t2.h) -1;
                    diff.m = ((60-t1.m) + t2.m);
                    diff.s = t2.s - t1.s;
                }
            }else if(t1.m <= t2.m){
                if(t1.s > t2.s){
                    diff.h = (t1.h - t2.h);
                    diff.m = (t2.m - t1.m) - 1;
                    diff.s = ((60-t1.s) + t2.s );
                }else if(t1.s <= t2.s){
                    diff.h = (t1.h - t2.h);
                    diff.m = (t2.m - t1.m);
                    diff.s = t2.s- t1.s;
                }
            }
    }else if(t1.h <= t2.h){
            if(t1.m > t2.m){
                if(t1.s > t2.s){
                    diff.h = (t2.h-t1.h) -1;
                    diff.m = ((60-t1.m) + t2.m) - 1;
                    diff.s = ((60-t1.s) + t2.s );
                }else if(t1.s <= t2.s){
                    diff.h = (t2.h-t1.h)-1;
                    diff.m = ((60-t1.m) + t2.m);
                    diff.s = t2.s - t1.s;
                }
            }else if(t1.m < t2.m){
                if(t1.s > t2.s){
                    diff.h = t2.h-t1.h;
                    diff.m = (t2.m - t1.m) - 1;
                    diff.s = ((60-t1.s) + t2.s );
                }else if(t1.s <= t2.s){
                    diff.h = t2.h-t1.h;
                    diff.m = (t2.m - t1.m);
                    diff.s = t2.s- t1.s;
                }
            }
    }
    cout << diff.h << ": "<< diff.m << ": " << diff.s << endl;
    return 0;
}
