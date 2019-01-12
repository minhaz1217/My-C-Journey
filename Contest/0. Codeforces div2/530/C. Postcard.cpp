#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;
#define msg3(a,b,c,d) cout << a << " : " << b << " : " << c << " : " << d << endl;

int main(){
    int n,countQ=0, countS=0,sz,bare,rem=0;
    string str, myStr="",myStrQ = "", myStrS ="",myStrSS="";

    cin >> str >> n;
    for(int i=1;i<=str.size();i++){
        if(str[i] == '?'){
            countQ++;
            myStrQ += str[i-1];
        }else if(str[i] == '*'){
            countS++;
            myStrS += str[i-1];
            myStrSS += str[i-1];
            myStrSS += str[i-1];
        }else{
            if( !( str[i-1] == '*' || str[i-1] == '?')  ){
                myStr += str[i-1];
                myStrQ += str[i-1];
                myStrS += str[i-1];
                myStrSS += str[i-1];
            }
        }
    }
    //msg2(myStr, myStrQ, myStrS)
    /*
    remove all
    take only Q
    take only *
    take Q and *
    take double *
    take Q and double *
    */
    sz = str.size();
    bare = sz - 2*(countQ + countS);
    //msg(sz, bare)
    if(bare == n){
        // remove all
        //msg("HELLO", 1)
        cout << myStr << endl;
        return 0;
    }else if(bare + countS == n){
        //msg("HELLO2", 1)
        cout << myStrS << endl;
        return 0;
    }else if(bare + countQ == n){
        //msg("HELLO3", 1)
        cout << myStrQ << endl;
        return 0;
    }else if(bare + countS + countS == n){
        //msg("HELLO4", 1)
        cout << myStrSS << endl;
        return 0;
    }else if( n>bare && n < bare+ countQ  ){
        //msg("HELLO5", 1)
        //add some ?
        rem = (n-bare);
        //msg("REM", rem)
        myStr = "";
        for(int i=1;i<=str.size();i++){
            if(str[i] == '?' && rem != 0){
                myStr += str[i-1];
                rem--;
                //msg(myStr,rem)
            }else{
                if( !( str[i-1] == '*' || str[i-1] == '?' || str[i] == '?' || str[i] == '*')  ){
                    myStr += str[i-1];
                //msg(myStr,"HI")
                }
            }
        }

    }else if( n > bare && n< bare+countS ){
        //msg("HELLO6", 1)
        // add some *
        rem = (n-bare);
        myStr = "";
        for(int i=1;i<=str.size();i++){
            if(str[i] == '*' && rem != 0){
                myStr += str[i-1];
                rem--;
            }else{
                if( !( str[i-1] == '*' || str[i-1] == '?' || str[i] == '?' || str[i] == '*')  ){
                    myStr += str[i-1];
                }
            }
        }
    }else if( n > bare && n < bare + countS + countS){
        // add some double
        //msg("HELLO7", 1)
        rem = (n-bare);
        //msg("REM", rem)
        myStr = "";
        for(int i=1;i<=str.size();i++){
            if(str[i] == '*'){
                if(rem!=0){
                    myStr += str[i-1];
                    rem--;
                }
                if(rem!=0){
                    myStr += str[i-1];
                    rem--;
                }
            }else{
                if( !( str[i-1] == '*' || str[i-1] == '?' || str[i] == '?' || str[i] == '*')  ){
                    myStr += str[i-1];
                }
            }
        }
    }else if( n> bare && n < bare+countQ + countS ){
        // add some Q and some S

        //msg("HELLO8", 1)
        rem = (n-bare);
        myStr = "";
        for(int i=1;i<=str.size();i++){
            if(str[i] == '*' && rem != 0){
                myStr += str[i-1];
                rem--;
            }else if(str[i] == '?' && rem != 0){
                myStr += str[i-1];
                rem--;
            }else{
                if( !( str[i-1] == '*' || str[i-1] == '?' || str[i] == '?' || str[i] == '*')  ){
                    myStr += str[i-1];
                }
            }
        }
    }else if( n> bare && n < bare + countQ + countS + countS ){
        // add some bare and some ss

        //msg("HELLO9", 1)
        rem = (n-bare);
        //msg("REM", rem)
        myStr = "";
        for(int i=1;i<=str.size();i++){
            if(str[i] == '*'){
                if(rem!=0){
                    myStr += str[i-1];
                    rem--;
                }
                if(rem!=0){
                    myStr += str[i-1];
                    rem--;
                }
            }else if(str[i] == '?' && rem != 0){
                myStr += str[i-1];
                rem--;
            }else{
                if( !( str[i-1] == '*' || str[i-1] == '?' || str[i] == '?' || str[i] == '*')  ){
                    myStr += str[i-1];
                }
            }
        }
    }else{
        myStr = "Impossible";
    }
    //msg(myStr, (int)myStr.size())
    cout << myStr << endl;


    return 0;
}
