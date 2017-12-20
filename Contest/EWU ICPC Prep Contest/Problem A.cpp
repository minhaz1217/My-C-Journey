#include<iostream>
using namespace std;
#define check(a) cout<<a<< endl;
int main(){
    string str;
    char ch[5];
    int a,j,len,i,invalidCheck = 0,totalCounter = 0;
    while(1){
        cin >> str;
        if(cin.eof()){
            break;
        }
        len = str.length();
        //cout << len << endl;
        invalidCheck =0;
        for(i=1;str[i];i++){
            if(str[i-1] > str[i]){
                invalidCheck = 1;
                break;
            }
        }
        if(invalidCheck == 1){
            cout << "Invalid" << endl;
        }
        totalCounter += str[len-1]-96;
        cout << "Total Value is " << totalCounter << endl;
/*
a > aa > 1
b > aa, ba bb > 3
c > aa, ba, bb, ca, cb, cc> 6
a = 1
ab ac ad
b = 2 > 2+1 = 3
c = 3 > 3 + 2+ 1 = 6
a > b > c .... > z > ab > ac ..... > bc >>
zz > 26! > 351
abc >
yz
abc = 352
26*26*1 = a** > 676 + 49 + 3 > 728
b* >> 49
c > 3

yz = 351
25
650 - 325 + 26
ya yb yc >> yy > yz

z > ab > ac > ad ....... > az > bc > bd >>>> bz > cd >
.... ya yb ....
yz = 650
ab >> 25 + 2 = 27
26*a - (a*(a+1) /2) =
bc >> 49 + 3 = 52
26 * b - 2*3 /2 + *
yz
zzzzz 26 ^ 5 = 11881376
y = 25
z * z+1 /2 = 378 -2
#y* = (26*y - ((y * (y+1))/2) + *) + (26 * 26 * #) - ()
a** = 26*26*a -
abc er jonno baad jaitache 376
abc > 352
abc > a** = 676 + 49 + 3 = 728 - 376
a** = 676
(26*26*a + b* + c)- 376 = ABC
bcd ??
adfl
aaaaa
728
bb > 54
yz = 325 + 26 >> 351
abc >> 352
650 - 325 = 325
* ....

26*a 1

bc
^
(26*2 - 2! + 3)
49 + 3

(26*2) - 3)


*/


    }

	return 0;
}
