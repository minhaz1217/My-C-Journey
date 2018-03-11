#include<iostream>
#include<stdio.h>
using namespace std;
int main(){
    int day,tc,i,caseCounter = 1;
    string str,month[] = {"", "January","February","March","April","May","June","July","August","September","October","November","December"};
    string myStr[] ={"", "Pohela Falgun","Valentine's Day","International Mother Language Day","International Women's Day","International Color Day","Bangladesh Independence Day","April Fools Day","Pohela Boishakh","May Day","Father's Day","Mandela Day","World Mosquito Day","Halloween","World Toilet Day","Human Rights Day","Victory Day of Bangladesh","Christmas Day"};
    scanf("%d", &tc);
    //cin >> tc;
    for(i=0;i<tc;i++){
        cin >> str >> day;
        //scanf("%s %d", &str,&day);
        //cin >> str >> day;
        printf("Case %d: ", caseCounter);
        caseCounter++;
        if(str == month[1] || (str == month[2] && day<13) || (str == month[12] && day >= 25)){
            ////printf("%s", myStr[1]);
            cout << myStr[1];
        }else if(str == month[2] && day==13){
            //printf("%s", myStr[2]);
            cout << myStr[2];
        }else if(str == month[2] && (day>=14 && day <21)){
            //printf("%s", myStr[3]);
            cout << myStr[3];
        }else if((str == month[2] && day >=21) || (str== month[3] && day < 8)){
            //printf("%s", myStr[4]);
            cout << myStr[4];
        }else if( (str == month[3] &&(day >=8 && day<21) )){
            //printf("%s", myStr[5]);
            cout << myStr[5];
        }else if( (str == month[3] && (day >= 21 &&day <26)) ){
            //printf("%s", myStr[6]);
        cout << myStr[6];
        }else if( (str == month[3] && day >= 26) ){
            //printf("%s", myStr[7]);
        cout << myStr[7];
        }else if( (str == month[4] && day <14) ){
            //printf("%s", myStr[8]);
        cout << myStr[8];
        }else if(str== month[4] && day >=14){
            //printf("%s", myStr[9]);
            cout << myStr[9];
        }else if( (str == month[5] )|| (str == month[6] && day <19) ){
            //printf("%s", myStr[10]);
            cout << myStr[10];
        }else if( (str == month[6] && day >= 19) || (str == month[7] && day <18)){
            //printf("%s", myStr[11]);
            cout << myStr[11];
        }else if( (str == month[7] && day>=18) || (str == month[8] && day < 20) ){
            //printf("%s", myStr[12]);
            cout << myStr[12];
        }else if( (str == month[8] && day >= 20)||(str == month[9]) ||(str == month[10] && day < 31) ){
            //printf("%s", myStr[13]);
            cout << myStr[13];
        }else if( (str == month[10] && day >=31) || (str == month[11] && day<19) ){
            //printf("%s", myStr[14]);
            cout << myStr[14];
        }else if( (str == month[11] && day >=19) || (str == month[12] && day <10) ){
            //printf("%s", myStr[15]);
            cout << myStr[15];
        }else if( (str == month[12] && (day>=10 &&day<16)) ){
            //printf("%s", myStr[16]);
            cout << myStr[16];
        }else if( (str == month[12] && (day >=16 && day <25)) ){
            //printf("%s", myStr[17]);
            cout << myStr[17];
        }
        printf("\n");
    }

    return 0;
}
