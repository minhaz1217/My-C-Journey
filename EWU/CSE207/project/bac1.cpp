#include<bits/stdc++.h>
#include "final/headerFiles.cpp"
using namespace std;
#define check(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;

#define FILE_NAME "my_file.cpp"


void trim(string &st){
    int counter = 0,i;
    for(i=0;st[i];i++){
        if(st[i]!=' '){
            break;
        }else{
            counter++;
        }
    }
    st.erase(0,counter);

    counter = 0;
    for(i=st.length();st[i] != ' ';i--){
        //check("LOG")
        counter++;
    }
    cout << counter << endl;
    //if(counter!=0)st.erase(counter+1, st.length());
}

/*
void checkAfterIf(string st){
    int i;
    Stack st;
    for(i=0;st[i];i++){
        if(st[i]=="i" && st[i+1] == "f"){
            if(st[i+2] != "("){
                // missing first breacket
            }else{
                st.push(st[i+2], i+2);
            }
        }
    }
}
*/
int checkIfAStringContainsAnythingOtherThanSpace(string str){
    int i;
    for(i=0;str[i];i++){
        if(str[i] != NULL || str[i] != ' '){
            return 1;
        }
    }
    return 0;
}

int main(){
    int lines = 0;
    lsHead = NULL;
    sc_stack ss;
    push(ss,'{', 5);
    push(ss,'{', 5);
    push(ss,'{', 5);
    push(ss,'{', 5);
    display(ss);
    //file

    FILE *pFile;
    char buffer[1000];
    string s,str;
    pFile = fopen(FILE_NAME, "r");

    if(pFile == NULL){
        cout << "ERROR IN OPENING FILE" << endl;
    }else{
        while(!feof(pFile)){
            if(fgets(buffer, 1000, pFile) == NULL){
                break;
            }
            //cout << buffer << endl;
            s = buffer;
            //strcat(buffer, "\0");
            str = buffer;
            trim(str);
            cout << str << endl;
            //fputs(buffer, stdout);
            lines++;
        }
        fclose(pFile);
    }
    //cout << lines << endl;


    return 0;
}
