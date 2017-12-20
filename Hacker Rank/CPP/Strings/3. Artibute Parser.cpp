#include<bits/stdc++.h>
using namespace std;



void extractTags(string str){
    int i;
    for(i=0;str[i];i++){
        if(str[i] == '<'){
            if(str[i+1] == '/'){
                //tag closed
            }else{

            }
        }
    }
}
string copynChars(string n, int startPos, int endPos){
    //char ch[] = n;
    char temp[n.length()];
    int i,j;
    for(i=startPos,j=0;i<=endPos;i++,j++){
        temp[j] = n[i];
    }
    temp[j] = '\0';
    //string str = temp;
    return temp;
}
string getInsideQuote(string str){
    int firstQ, secondQ,i,j;
//cout << str << endl;
    for(i=0;str[i];i++){
        if(str[i] == '"'){
            firstQ = i;
            break;
        }
    }
    for(i=firstQ+1;str[i];i++){
        if(str[i] == '"'){
            secondQ = i;
            break;
        }
    }
    char ch[secondQ - firstQ + 1];
    for(i=firstQ+1,j=0;i<=secondQ-1;i++,j++){
        ch[j] = str[i];
    }
    ch[j] = '\0';
    //cout << ch << endl;
    return ch;

}


int main() {
    string str[4];
    int i;
    str[0] = "<tag1 value = \"HelloWorld\">";
    str[1] = "<tag2 name = ""Name1"">";
    str[2] = "</tag2>";
    str[3] = "</tag1>";

    string currentTag ="", currentTagName = "",artibuteName,artibuteValue;
    stringstream ss(str[0]);
    int currentTagEnded = 1, currentTagIsASubTag = 0, gotArtibuteName = 0;

    string temp;


    //cout << ss.eof() << endl;
    while(1){
        ss >> temp;
        //cout << temp << endl;
        if(temp[0] == '<' && temp[1] == '/'){
            //tag ended
        }else if(temp[0] == '<'){
            currentTag = copynChars(temp,1,temp.length());
        }else if(temp[0] != '<' && (temp[0] == '"' || temp[0] == '\'')){
            artibuteValue = getInsideQuote(temp);
            //cout << "Entered 3" << endl;
        }else if(temp[0] != '<' && temp[0] != '='){
            artibuteName = temp;
            //cout << "Entered 4" << endl;
        }
        cout << currentTag  << "~" << artibuteName << "=" << artibuteValue << endl;


        if(ss.eof()){
            break;
        }
    }
    //cout << ss.eof() << endl;

//    ss >> temp;
 //   cout << temp;


    //extractTags(str[0]);




    /*
    for(i=0;i<4;i++){
        cout << str[i] << endl;
    }
    */

    return 0;
}
