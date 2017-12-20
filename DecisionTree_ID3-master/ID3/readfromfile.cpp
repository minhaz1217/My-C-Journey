#include<bits/stdc++.h>
using namespace std;
#define check(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;

int main(){
    string line;
    string a,b,c,d,e,f,g;
    string class1, attribute1, attribute2, attribute3, attribute4, attribute5, attribute6;
    fstream fs;
    fs.open("monks-1.test");
    if(fs.is_open()){
        while(fs >> class1 >> attribute1 >> attribute2 >> attribute3 >> attribute4 >> attribute5 >> attribute6 >> line){
            cout <<class1 << " " <<  attribute1  << " " << attribute2 << " " << attribute3 << " " << attribute4 << " " << attribute5 << " " << attribute6 << " " << line << endl;
            //printf("%s %s %s %s %s %s %s %s", a,b,c,d,e,f,g);
        }
        fs.close();
    }


    return 0;
}
