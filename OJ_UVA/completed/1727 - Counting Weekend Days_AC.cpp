#include<bits/stdc++.h>
using namespace std;
#define check(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;

int main(){

    map<string, int>week, month;
    week["SUN"] = 1;
    week["MON"] = 2;
    week["TUE"] = 3;
    week["WED"] = 4;
    week["THU"] = 5;
    week["FRI"] = 6;
    week["SAT"] = 7;
    month["JAN"] = 31;
    month["FEB"] = 28;
    month["MAR"] = 31;
    month["APR"] = 30;
    month["MAY"] = 31;
    month["JUN"] = 30;
    month["JUL"] = 31;
    month["AUG"] = 31;
    month["SEP"] = 30;
    month["OCT"] = 31;
    month["NOV"] = 30;
    month["DEC"] = 31;

    int tc, i,curr, counter;
    string wk, mon;

    cin >> tc;
    while(tc--){
        cin >> mon >> wk;
        counter = 0;
        curr = week[wk];
        for(i=1;i<=month[mon];i++){
            if(curr == 6 || curr == 7){
                counter++;
            }
            curr++;
            //cout << curr << endl;
            if(curr > 7){
                curr = 1;
            }
        }
        cout << counter << endl;
    }

    return 0;
}
