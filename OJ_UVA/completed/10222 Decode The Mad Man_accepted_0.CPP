#include<iostream>
using namespace std;
int main(){
    int i;
    string str,str1 = "";
    getline(cin, str);
    for(i=0;str[i];i++){
        switch(str[i]){
        case 'e': case 'E':
            cout << 'q';
            break;
        case 'd': case 'D':
            cout << 'a';
            break;
        case 'c': case 'C':
            cout << 'z';
            break;
        case 'r': case 'R':
            cout << 'w';
            break;
        case 't': case 'T':
            cout << 'e';
            break;
        case 'y': case 'Y':
            cout << 'r';
            break;
        case 'u': case 'U':
            cout << 't';
            break;
        case 'i': case 'I':
            cout << 'y';
            break;
        case 'o': case 'O':
            cout << 'u';
            break;
        case 'p': case 'P':
            cout << 'i';
            break;
        case '[':
            cout << 'o';
            break;
        case ']':
            cout << 'p';
            break;
        case 'f': case 'F':
            cout << 's';
            break;
        case 'g': case 'G':
            cout << 'd';
            break;
        case 'h': case 'H':
            cout << 'f';
            break;
        case 'j': case 'J':
            cout << 'g';
            break;
        case 'k': case 'K':
            cout << 'h';
            break;
        case 'l': case 'L':
            cout << 'j';
            break;
        case ';':
            cout << 'k';
            break;
        case '\'':
            cout << 'l';
            break;
        case '\\':
            cout << ';';
            break;
        case 'v': case 'V':
            cout << 'x';
            break;
        case 'b': case 'B':
            cout << 'c';
            break;
        case 'n': case 'N':
            cout << 'v';
            break;
        case 'm': case 'M':
            cout << 'b';
            break;
        case ',':
            cout << 'n';
            break;
        case '.':
            cout << 'm';
            break;
        case '/':
            cout << ',';
            break;
        case ' ':
            cout << ' ';
            break;
        }
    }
    cout << endl;
	return 0;
}
