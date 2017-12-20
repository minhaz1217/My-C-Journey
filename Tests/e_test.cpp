#include<iostream>
#include<iomanip>
#include<math.h>
#include<string.h>

using namespace std;

int main(){

   char word[250];

   int i;

   cin>>word;
    i=0;
   while(word[i]!=NULL){
    if(word[i]!='W' && word[i+1]!='U' && word[i+2]!='B') {
        cout<<word[i];
        i++;
    }
    else{
        //cout << "HI" << endl;
        cout<<" ";
        i+=3;
    }

   }

}
