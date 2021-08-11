/*
Minhazul Hayat Khan
Website: www.minhazul.com
EWU, Bangladesh
Problem Name:
Problem Link:
Date : 09 / August / 2021
Comment:
*/
#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define DEBUG 1
#define check(a) DEBUG==1?(cout << a << endl):null;
#define cc(a) DEBUG==1?(cout << a << endl):cout<<"";
#define msg(a,b) DEBUG==1?(cout << a << " : " << b << endl):cout<<"";
#define msg2(a,b,c) DEBUG==1?(cout << a << " : " << b << " : " << c << endl):cout<<"";
#define msg3(a,b,c,d) DEBUG==1?(cout << a << " : " << b << " : " << c << " : " << d << endl):cout<<"";
#define msg4(a,b,c,d,e) DEBUG==1?(cout << a << " : " << b << " : " << c << " : " << d << " : " << e << endl):cout<<"";
#define _INIT ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

/*
[[1,2],[3,4]]
[[7,3,6],[1,4,5],[9,8,2]]

[[7.1,3.1,6.1],[1.9,4.9,5.9],[9.5,8.1,2.9]]
*/
template <typename T>
class LeetCodeInputTaker{
vector< vector<string> > vectorVectorString(string str){
    vector<vector<string> > mainVec;
    str = str.substr( 1, str.size()-2 );
    while(str.size() > 0){
        int leftBracketPosition = str.find('[');
        vector<string> insideVector;
        if(leftBracketPosition == -1){
            break;
        }
        int rightBracketPosition = str.find(']');
        string tempStr = str.substr( leftBracketPosition+1, rightBracketPosition - leftBracketPosition-1);
        str = str.substr(rightBracketPosition+1, str.size());
        int commaPosition = tempStr.find(',');
        while(tempStr.size() > 0){
            commaPosition = tempStr.find(',');
            if(commaPosition == -1){
                insideVector.push_back(tempStr);
                break;
            }
            string tempStr2 = tempStr.substr(0, commaPosition);
            insideVector.push_back(tempStr2);
            tempStr = tempStr.substr(commaPosition+1, tempStr.size());
        }
//        cout << "INSIDE" << endl;
//        for(int i=0;i<insideVector.size();i++){
//            cout << insideVector[i] << " ";
//        }
//        cout << endl;
        mainVec.push_back(insideVector);
    }
    return mainVec;
}
vector<vector<T> > convertStringToInt(vector<vector<string> > vec){
    vector<vector<T> > mainVec;
    for(int i=0;i<vec.size();i++){
        vector<T> nestedVec;
        for(int j=0;j<vec[i].size();j++){
            stringstream ss(vec[i][j]);
            T a;
            ss >> a;
            nestedVec.push_back(a);
        }
        mainVec.push_back(nestedVec);
    }
    return mainVec;
}

public:
    vector<vector<T> > take(){
        string str;
        getline(cin, str);
        return convertStringToInt(vectorVectorString(str));
    }
    void display(vector<vector<T> > input, int padding = 5){
        for(int i=0;i<input.size();i++){
            for(int j=0;j<input[i].size();j++){
                cout << right << setw(padding) << input[i][j];
            }
            cout << endl;
        }
    }

};

int main(){
    LeetCodeInputTaker<float> input;
    vector<vector<float> > vec = input.take();
    input.display(vec, 3);
//    for(int i=0;i<vec.size();i++){
//        for(int j=0;j<vec[i].size();j++){
//            cout << vec[i][j] << "\t ";
//        }
//        cout << endl;
//    }
    return 0;
}
