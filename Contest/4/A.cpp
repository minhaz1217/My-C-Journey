#include<stdio.h>
int main(){
    int a,p,q;
    scanf("%d", &a);
    while(a--){
        scanf("%d %d", &p, &q);
        if(q-p>0 && q-p<= 6){
            printf("Yes\n");
        }else{

            printf("No\n");
        }
    }
	return 0;
}
