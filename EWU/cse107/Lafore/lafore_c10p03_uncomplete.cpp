#include<iostream>
#include<cstring>
using namespace std;
#define check(a) cout<<a<< endl;
void order(char * , char *);
int main(){
    char *arrptrs[7] = {"sunday", "monday" , "tuesday", "wednesday", "thursday", "friday", "saturday"};

    /*for(int i=0;i<7;i++){
        cout << arrptrs[i] << endl;
    }
    */
    order(arrptrs[1] , arrptrs[0]);

	return 0;
}
void order(char *a, char *b){
    if(a>b){
        char *temp = new char[strlen(a) +1];
        strcpy(temp, a);
        *a = *b;
        *b = *temp;
    }
    cout << a << ":" << b << endl;
}




void bsort(char *arr[], int len){
    for(int i=0;i<len;i++){
        for(int j=i+1;j<len;j++){
            order(*arr+i, *arr+j);
        }
    }
}



