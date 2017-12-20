#include<bits/stdc++.h>
using namespace std;
#define check(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;



template<typename _CharT, typename _Traits, typename _Alloc>
class myString{
      typedef typename _Alloc::template rebind<_CharT>::other _CharT_alloc_type;
};
typedef basic_string<char> mystr;

int main(){
    myString str;
    //str = "d";
    cout << str << endl;

    return 0;
}



