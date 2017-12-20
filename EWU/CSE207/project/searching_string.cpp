#include<bits/stdc++.h>
using namespace std;
#define check(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;

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

void trimSpace(string &st){
    //use custom stack
    int i;
    stack<char> stc1;
    queue<int> toremove;
    for(i = 0; st[i]; i++){
        if(st[i] == '"' || st[i] == '\''){
            if(stc1.top() == '\'' && st[i] == '\''){
                stc1.pop();
            }else if(stc1.top() == '"' && st[i] == '"'){
                stc1.pop();
            }else{
                stc1.push(st[i]);
            }

            //to avoid comp error
            if(st[i+1] != '\0'){
                if(stc1.top() == NULL){
                    if(st[i] == ' ' && st[i+1] == ' '){
                        toremove.push(i);
                    }
                }
            }
        }
    }
    char newStr[st.length()+1];
    int j=0;
    for(i=0;st[i];i++){
        if(i == toremove.front()){
            toremove.pop();
        }else{
            newStr[j++] = st[i];
        }
    }
    newStr[j] = '\0';
    st = newStr;



}

int main(){

    string myTestString = "this is a string 'Hello darkness my               old friend'";



    int lines = 0;
    FILE *pFile;
    char buffer[100];
    string s,str;
    pFile = fopen("my_file.cpp", "r");

    if(pFile == NULL){
        cout << "ERROR IN OPENING FILE" << endl;
    }else{
        while(!feof(pFile)){
            if(fgets(buffer, 100, pFile) == NULL){
                break;
            }
            str = buffer;
            //trim(str);
            //cout << str << endl;
            lines++;
        }
        fclose(pFile);
    }
    //trimSpace(myTestString);
    cout << myTestString << endl;
    //cout << lines << endl;


    return 0;
}
