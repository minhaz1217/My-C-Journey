/*
Minhazul Hayat Khan
github.com/minhaz1217
Bangladesh

Problem Name:
Problem Link:
Complexity: n * klog(k)
Date : 17 / Oct / 2022

Comment:
*/
#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;
#define msg3(a,b,c,d) cout << a << " : " << b << " : " << c << " : " << d << endl;
#define _INIT ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

string convertToLowerCase(string word){
    for(int i=0;i<word.size();i++){
        if(word[i] >= 'A' && word[i] <='Z'){
            word[i] =  (char)(word[i] - 'A' + 'a');
        }
    }
    return word;
}
void printOutput(map<string, vector<string> > anagrams){
    for(map<string, vector<string> >::iterator it=anagrams.begin();it!= anagrams.end();it++){
        vector<string> pairs = (it->second);
        if(pairs.size()<=1){
            continue;
        }
        for(int i=0;i<pairs.size();i++){
            if(i>0){
                cout << " ";
            }
            cout << pairs[i];
        }
        cout << endl;
    }
}


int main(){
    _INIT;

    int wordCount;
    string word;

    map<string, vector<string> > anagrams;

    cout << "How many words?" << endl;
    cin >> wordCount;

    while(wordCount--){
        cin >> word;

        string sortedWord = convertToLowerCase(word);
        sort(sortedWord.begin(), sortedWord.end());


        if(anagrams.find(sortedWord) == anagrams.end()){
            // the sorted word is not present in the dictionary.
            vector<string> temporaryHolder;
            temporaryHolder.push_back(word);
            anagrams[sortedWord] = temporaryHolder;
        }else{
            // word is present in the dictionary so we'll insert is in the anagram list.
            anagrams[sortedWord].push_back(word);
        }
    }

    cout << endl << endl;
    printOutput(anagrams);
    return 0;
}
