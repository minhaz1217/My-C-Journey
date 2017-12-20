#include <iostream>
#include <cstdio>
using namespace std;

int max_of_four(int a,int b,int c,int d){
    if(a>=b && a>=c && a>=d){
        return a;
    }else if(b>=a && b>=c && b>=d){
        return b;
    }else if(c>=a && c>=b && c>=d){
        return c;
    }else{
        return d;
    }
}

int main() {
    int x, xx,xxx, xxxx;
    scanf("%d %d %d %d", &x, &xx, &xxx, &xxxx);
    int ans;
    ans = max_of_four(x,xx, xxx, xxxx);
    printf("%d", ans);

    return 0;
}

