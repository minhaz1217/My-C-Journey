#include<bits/stdc++.h>
using namespace std;
#define check(a) cout<<a<< endl;
double calculateDistance(double x1,double y1, double x2, double y2){
    double temp = sqrt((x1- x2)*(x1-x2) + (y1 - y2)*(y1-y2));
    return temp;
}
double calcAnotherDist(double p, double q, double x1, double y1, double x2, double y2){
    double temp = ( (y1-y2)*p - (x1-x2)*q + (x1*y2 - x2*y1)    ) / sqrt( (y1-y2)*(y1-y2) + (x1 - x2)*(x1-x2)   );
    //cout << temp << endl << endl;
    return temp;


}


int main(){
    string str;
    char c;
    int i,tc;
    double arr[4][2],bigx=0,smallx=101,midx=101, bigy=0,smally=101,midy=101,distAB, distBC, distCA,distA,distB,distC;
    scanf("%d", &tc);
    scanf("%*c");
    while(tc--){

        scanf("(%lf,%lf)(%lf,%lf)(%lf,%lf)(%lf,%lf)",&arr[0][0],&arr[0][1],&arr[1][0],&arr[1][1],&arr[2][0],&arr[2][1],&arr[3][0],&arr[3][1]);

        distAB = calculateDistance(arr[0][0], arr[0][1], arr[1][0],arr[1][1]);
        distBC = calculateDistance(arr[1][0], arr[1][1], arr[2][0],arr[2][1]);
        distCA = calculateDistance(arr[2][0], arr[2][1], arr[0][0],arr[0][1]);
        distA = calculateDistance(arr[3][0], arr[3][1], arr[0][0],arr[0][1]);
        distB = calculateDistance(arr[3][0], arr[3][1], arr[1][0],arr[1][1]);
        distC = calculateDistance(arr[3][0], arr[3][1], arr[2][0],arr[2][1]);
        if(distA > distAB || distA > distCA || distB > distBC || distB > distAB || distC > distCA || distC > distBC){
            distAB = fabs(calcAnotherDist(arr[3][0], arr[3][1], arr[0][0], arr[0][1], arr[1][0], arr[1][1]));
            distBC = fabs(calcAnotherDist(arr[3][0], arr[3][1], arr[1][0], arr[1][1], arr[2][0], arr[2][1]));
            distCA = fabs(calcAnotherDist(arr[3][0], arr[3][1], arr[2][0], arr[2][1], arr[0][0], arr[0][1]));
            //cout << distAB << " " << distBC << " " << distCA << endl<<endl << endl;
            if(distAB <= distBC && distAB <= distCA){
                printf("%.4lf\n", (distAB));
            }else if(distBC <= distAB && distBC <= distCA){
                printf("%.4lf\n", (distBC));

            }else{
                printf("%.4lf\n", (distCA));
            }
        }else{
            printf("SUB IUPC!\n");
        }

    }

        return 0;
}
