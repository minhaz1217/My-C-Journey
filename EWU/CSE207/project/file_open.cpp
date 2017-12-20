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



int main(){
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
