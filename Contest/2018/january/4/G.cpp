#include<stdio.h>
#include<math.h>
int main(){
    double n=6,a;
    scanf("%lf", &a);
    double area = .5 * n *2* n - (acos(-1) * n*n *.5 *.5 );
    while(a--){
        scanf("%lf", &n);
        area = .5 * n *2* n - (acos(-1) * n*n *.5 *.5 );
        printf("%.2lf\n" , area);
    }
	return 0;
}
