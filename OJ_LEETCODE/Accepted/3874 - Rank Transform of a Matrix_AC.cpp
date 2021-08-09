/*
Minhazul Hayat Khan
Website: www.minhazul.com
EWU, Bangladesh
Problem Name:
Problem Link: https://leetcode.com/explore/challenge/card/august-leetcoding-challenge-2021/614/week-2-august-8th-august-14th/3874/
Date : 08 / August / 2021
Comment: hard problem, the trick was hard to find.
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
[[-43],[-43],[-43]]
[[-43]]
[[43,43,43]]
[[1,2],[3,4]]
[[25,8,31,42,-39,8,31,-10,33,-44,7,-30,9,44,15,26],[-3,-48,-17,-18,9,-12,-21,10,1,44,-17,14,-27,48,-21,-6],[49,28,27,-18,-31,4,-13,34,49,48,47,-18,33,40,15,38],[5,-28,-49,-38,1,32,-25,-50,29,-32,35,-46,-43,48,-49,-6],[-27,-24,23,-14,-47,-12,7,6,25,-16,47,-26,13,-12,-33,-18],[45,-48,3,-26,-23,-36,-17,38,17,12,15,46,37,40,47,26],[-19,-24,-21,-2,-7,-48,47,30,5,-8,23,-46,21,-32,-33,-26],[-27,32,27,-26,21,-32,-49,-10,5,20,-29,46,-43,-44,39,22],[-43,48,27,26,-27,12,-1,-10,-27,12,-29,-34,41,-28,-25,-30],[25,-36,35,-26,37,-20,31,14,-19,-40,-29,-2,-39,-28,11,46],[49,-32,-29,-6,-47,32,-17,-18,-23,24,23,22,-47,-44,27,14],[37,-44,-33,-18,-47,24,-17,-46,-43,-32,15,-46,-27,-8,-25,46],[41,-40,31,-30,13,-24,-29,22,-15,-16,47,2,-39,4,-25,-42],[-3,12,7,14,-7,8,-37,-34,-7,-12,39,-38,1,44,27,-34],[-47,4,7,-2,-43,-32,27,2,-43,-8,-33,14,49,-48,-5,30],[-15,8,-33,-26,-23,-32,-25,22,13,-20,-9,26,29,4,-1,2]]
[[28,-13,42,49,-20,-9,-46,21,-8,-25,-18,-39,-8,-13,6,-7,-44,-33],[-30,9,4,-45,14,-7,44,47,-30,9,-40,43,-50,-15,36,-1,46,-35],[-24,19,2,-27,-20,23,6,-39,32,3,-14,-47,-36,23,-10,17,32,27],[42,9,40,11,-38,-23,16,-13,-30,-3,-32,-5,-6,-35,32,-1,30,33],[32,-33,26,49,-32,-25,22,-7,8,-1,-26,21,-28,31,22,33,28,47],[-46,37,-4,-1,-22,-35,-48,-37,-2,37,-16,-5,6,17,-36,3,30,41],[40,19,38,-3,-12,-29,14,-7,-44,19,-10,49,-8,-5,-6,-31,-12,-49],[6,-35,-16,-5,22,-27,24,35,2,45,-8,-49,10,-43,-36,11,34,-39],[-4,-21,18,-7,24,-21,26,1,12,15,46,-35,-20,7,-26,1,36,39],[-14,33,-16,43,42,49,12,-17,-18,49,-16,3,-34,49,-24,-29,-6,-47],[-4,-21,46,1,8,-41,18,-43,4,35,-46,13,4,47,-30,-7,4,43],[-18,-11,4,-21,38,1,32,-49,10,37,12,19,2,-27,32,-33,-46,33],[-36,11,-38,17,-20,15,26,-39,-48,-29,-42,-15,-32,35,-6,49,24,-21],[-14,33,-20,-41,-6,5,8,-49,-46,41,-24,-21,-38,-35,28,-1,2,-43],[44,-37,18,45,36,23,-26,21,44,-21,-46,-47,24,35,22,-7,40,47],[10,-7,-16,-33,38,-23,0,-33,-38,-39,-16,27,14,49,24,15,-38,-19],[36,-1,-6,-19,4,-17,46,-23,8,-9,42,-43,-48,31,-30,-3,0,31],[-10,-23,-20,15,30,-7,16,43,18,17,32,-29,-38,17,24,-13,6,-27]]
[[25,8,31,42,-39,8,31,-10,33,-44,7,-30,9,44,15,26],[-3,-48,-17,-18,9,-12,-21,10,1,44,-17,14,-27,48,-21,-6],[49,28,27,-18,-31,4,-13,34,49,48,47,-18,33,40,15,38],[5,-28,-49,-38,1,32,-25,-50,29,-32,35,-46,-43,48,-49,-6],[-27,-24,23,-14,-47,-12,7,6,25,-16,47,-26,13,-12,-33,-18],[45,-48,3,-26,-23,-36,-17,38,17,12,15,46,37,40,47,26],[-19,-24,-21,-2,-7,-48,47,30,5,-8,23,-46,21,-32,-33,-26],[-27,32,27,-26,21,-32,-49,-10,5,20,-29,46,-43,-44,39,22],[-43,48,27,26,-27,12,-1,-10,-27,12,-29,-34,41,-28,-25,-30],[25,-36,35,-26,37,-20,31,14,-19,-40,-29,-2,-39,-28,11,46],[49,-32,-29,-6,-47,32,-17,-18,-23,24,23,22,-47,-44,27,14],[37,-44,-33,-18,-47,24,-17,-46,-43,-32,15,-46,-27,-8,-25,46],[41,-40,31,-30,13,-24,-29,22,-15,-16,47,2,-39,4,-25,-42],[-3,12,7,14,-7,8,-37,-34,-7,-12,39,-38,1,44,27,-34],[-47,4,7,-2,-43,-32,27,2,-43,-8,-33,14,49,-48,-5,30],[-15,8,-33,-26,-23,-32,-25,22,13,-20,-9,26,29,4,-1,2]]
[[11,22,-11,-20,-29,-18,5,44,-25,-50,33,-28,-29,-26,29,-44,27,-50,9,-48],[-17,-26,-43,-16,-13,-18,29,20,-25,26,45,-24,19,-2,-23,-4,27,-2,-31,12],[-1,38,-23,4,19,-18,13,-16,-21,-46,9,-40,35,-10,-15,40,31,-50,5,16],[3,14,17,4,39,26,-3,12,11,6,45,-48,-5,14,-15,-4,43,-22,-3,-48],[-33,-46,13,-44,47,46,5,16,23,-34,1,-40,39,-38,-19,-28,39,-50,13,-8],[-13,46,25,36,-45,-2,29,20,15,-10,17,8,-45,2,-3,-48,-29,22,-31,-28],[-49,14,-7,-12,-9,10,37,20,27,42,49,-12,31,-30,45,44,-21,-46,-43,28],[31,46,-23,-20,35,-30,9,-4,39,10,-39,28,19,38,-23,-40,35,-26,17,4],[-25,-2,-15,28,-9,-50,33,8,-13,-30,-43,20,-9,-18,45,-24,27,38,45,16],[-21,-2,-19,-12,-5,-26,45,36,-1,-34,1,4,7,6,5,44,-45,-10,-3,-20],[47,10,-35,4,-41,-14,25,-12,-21,10,-7,-44,-1,-2,17,-36,-25,-14,37,-8],[39,-30,-15,28,-5,-30,21,16,15,-18,45,-20,-29,34,-27,-28,-41,-46,25,36],[-29,-42,-43,40,31,-42,5,0,31,-18,-3,-36,-37,34,37,36,-1,10,13,16],[-33,-22,41,36,-29,-38,-23,8,-1,10,33,12,43,18,-39,-44,-29,10,-15,40],[-49,-46,-47,44,-21,-14,-15,24,7,-18,-3,8,-25,22,49,-32,-49,-26,9,40],[-5,26,21,-32,-21,-18,25,40,-25,22,-43,24,-49,42,-47,-16,-33,-34,17,0],[-21,-38,-23,0,-17,10,-23,44,-37,-10,45,-8,-21,-42,-7,44,-49,-46,-11,36],[-13,-2,-31,-20,-49,2,41,28,31,30,29,-4,-5,-30,41,40,35,26,41,-12],[-41,42,-3,-8,31,-22,29,-48,11,2,-47,-4,-1,-50,-39,12,31,-14,-3,44],[-5,-26,-39,-36,-45,34,21,-12,31,-22,17,-8,-41,38,33,-40,43,-10,-3,-24]]

*/

class disjoint_set{
    vector<int>p,rt;
public:
    disjoint_set(int n){
        p.assign(n,0);
        rt.assign(n,0);
        for(int i=0;i<n;i++){
            p[i] = i;
        }
    }
    int findSet(int x){
        if(p[x] == x){
            return x;
        }else{
            p[x] = findSet(p[x]);
            return p[x];
        }
    }
    bool isSameSet(int x, int y){
        return (findSet(x) == findSet(y));
    }
    void unionSet(int x, int y){
        if(!isSameSet(x,y)){
            int a,b;
            a = findSet(x);
            b = findSet(y);
            if(rt[a] > rt[b]){
                p[b] = a;
            }else{
                p[a] = b;
                if(rt[a] == rt[b]){
                    rt[b]++;
                }
            }
        }
    }

};

struct Info{
    int val, maxVal, row,column;
};
class Solution {
public:
    vector<vector<int>> matrixRankTransform(vector<vector<int>>& matrix){
        if(matrix.size() == 1 && matrix[0].size() == 1){
            matrix[0][0] = 1;
            return matrix;
        }
        queue<int> q;
        map<int,int> mp;
        vector< pair<int, pair<int,int> > > sortedPositions;
        vector<Info> maxColumnValue( matrix[0].size()+2, Info() ), maxRowValue( matrix.size()+2, Info() );
        disjoint_set djRow(250004);
        for(int rowIndex=0;rowIndex<matrix.size();rowIndex++){
            for(int colIndex = 0;colIndex < matrix[rowIndex].size();colIndex++){
                sortedPositions.push_back( make_pair( matrix[rowIndex][colIndex] , make_pair(rowIndex,colIndex) ) );
            }
        }

        sort( sortedPositions.begin(), sortedPositions.end() );
        int sz = sortedPositions.size(), szRow = matrix[0].size(),mx = INT_MIN;
        set<pair<int,int> > recalculation;
        for(int index = 0;index < sz;index++){
            int val = sortedPositions[index].first;
            int row = sortedPositions[index].second.first;
            int column = sortedPositions[index].second.second;

            int nextValueRowWise, nextValueColumnWise;

            if( maxRowValue[row].val == val ){
                recalculation.insert( make_pair(row,column) );
                recalculation.insert( make_pair(maxRowValue[row].row ,maxRowValue[row].column) );
                djRow.unionSet( row * szRow + column, maxRowValue[row].row * szRow + maxRowValue[row].column );

                nextValueRowWise = maxRowValue[row].maxVal;
                int parent = djRow.findSet(row * szRow + column);
                if(mp.find( parent ) == mp.end()){
                    mp[parent] = nextValueRowWise;
                }else{
                    mp[parent] = max( nextValueRowWise, mp[parent] );
                }

            }else{
                nextValueRowWise = maxRowValue[row].maxVal+1;
            }

            if( maxColumnValue[column].val == val ){
                recalculation.insert( make_pair(row,column) );
                recalculation.insert( make_pair(maxColumnValue[column].row ,maxColumnValue[column].column) );
                djRow.unionSet( row * szRow + column, maxColumnValue[column].row * szRow + maxColumnValue[column].column );
                nextValueColumnWise = maxColumnValue[column].maxVal;
                int parent = djRow.findSet(row * szRow + column);
                if(mp.find( parent ) == mp.end()){
                    mp[parent] = nextValueColumnWise;
                }else{
                    mp[parent] = max( nextValueColumnWise, mp[parent] );
                }
            }else{
                nextValueColumnWise = maxColumnValue[column].maxVal+1;
            }

            matrix[row][column] = max( nextValueRowWise, nextValueColumnWise );
            Info info1, info2;
            info1.val = val;
            info1.maxVal = matrix[row][column];
            info1.row = row;
            info1.column = column;

            info2.val = val;
            info2.maxVal = matrix[row][column];
            info2.row = row;
            info2.column = column;

            maxRowValue[row] = info1;
            maxColumnValue[column] = info2;
            q.push( index );
            if(index < sz -1){
                if(sortedPositions[index].first != sortedPositions[index+1].first ){
                    if(recalculation.size() > 1){
                        for(set<pair<int,int> >::iterator it = recalculation.begin(); it != recalculation.end();it++){
                            row = (it->first);
                            column = (it->second);
                            mp[djRow.findSet(row * szRow + column)] = max(mp[djRow.findSet(row * szRow + column)],matrix[row][column]);
                        }

                        for(set<pair<int,int> >::iterator it = recalculation.begin(); it != recalculation.end();it++){
                            row = (it->first);
                            column = (it->second);
                            matrix[row][column] = mp[ djRow.findSet(row * szRow + column) ];

                            Info info3, info4;
                            info3.val = val;
                            info3.maxVal = matrix[row][column];
                            info3.row = row;
                            info3.column = column;

                            info4.val = val;
                            info4.maxVal = matrix[row][column];
                            info4.row = row;
                            info4.column = column;

                            maxRowValue[row] = info3;
                            maxColumnValue[column] = info4;

                        }
                    }
                    set<pair<int,int> > empty;
                    swap( recalculation, empty );
                    mx = INT_MIN;
                }
            }
        }

        int index = sz-1,val,row,column,nextValueRowWise,nextValueColumnWise;
        if(sortedPositions[index].first == sortedPositions[index-1].first && q.size() > 1){
            if(recalculation.size() > 1){
                mx = INT_MIN;
                for(set<pair<int,int> >::iterator it = recalculation.begin(); it != recalculation.end();it++){
                    row = (it->first);
                    column = (it->second);
                    mp[djRow.findSet(row * szRow + column)] = max(mp[djRow.findSet(row * szRow + column)],matrix[row][column]);
                }

                for(set<pair<int,int> >::iterator it = recalculation.begin(); it != recalculation.end();it++){
                    row = (it->first);
                    column = (it->second);
                    matrix[row][column] = mp[ djRow.findSet(row * szRow + column) ];

                    Info info3, info4;
                    info3.val = val;
                    info3.maxVal = matrix[row][column];
                    info3.row = row;
                    info3.column = column;

                    info4.val = val;
                    info4.maxVal = matrix[row][column];
                    info4.row = row;
                    info4.column = column;

                    maxRowValue[row] = info3;
                    maxColumnValue[column] = info4;

                }
            }
        }
        return matrix;
    }
};
class disjoint_set{
    vector<int>p,rt;
public:
    disjoint_set(int n){
        p.assign(n,0);
        rt.assign(n,0);
        for(int i=0;i<n;i++){
            p[i] = i;
        }
    }
    int findSet(int x){
        if(p[x] == x){
            return x;
        }else{
            p[x] = findSet(p[x]);
            return p[x];
        }
    }
    bool isSameSet(int x, int y){
        return (findSet(x) == findSet(y));
    }
    void unionSet(int x, int y){
        if(!isSameSet(x,y)){
            int a,b;
            a = findSet(x);
            b = findSet(y);
            if(rt[a] > rt[b]){
                p[b] = a;
            }else{
                p[a] = b;
                if(rt[a] == rt[b]){
                    rt[b]++;
                }
            }
        }
    }

};

struct Info{
    int val, maxVal, row,column;
};
class Solution {
public:
    vector<vector<int>> matrixRankTransform(vector<vector<int>>& matrix){
        if(matrix.size() == 1 && matrix[0].size() == 1){
            matrix[0][0] = 1;
            return matrix;
        }
        queue<int> q;
        map<int,int> mp;
        vector< pair<int, pair<int,int> > > sortedPositions;
        vector<Info> maxColumnValue( matrix[0].size()+2, Info() ), maxRowValue( matrix.size()+2, Info() );
        disjoint_set djRow(250004);
        for(int rowIndex=0;rowIndex<matrix.size();rowIndex++){
            for(int colIndex = 0;colIndex < matrix[rowIndex].size();colIndex++){
                sortedPositions.push_back( make_pair( matrix[rowIndex][colIndex] , make_pair(rowIndex,colIndex) ) );
            }
        }

        sort( sortedPositions.begin(), sortedPositions.end() );
        int sz = sortedPositions.size(), szRow = matrix[0].size(),mx = INT_MIN;
        set<pair<int,int> > recalculation;
        for(int index = 0;index < sz;index++){
            int val = sortedPositions[index].first;
            int row = sortedPositions[index].second.first;
            int column = sortedPositions[index].second.second;

            int nextValueRowWise, nextValueColumnWise;

            if( maxRowValue[row].val == val ){
                recalculation.insert( make_pair(row,column) );
                recalculation.insert( make_pair(maxRowValue[row].row ,maxRowValue[row].column) );
                djRow.unionSet( row * szRow + column, maxRowValue[row].row * szRow + maxRowValue[row].column );

                nextValueRowWise = maxRowValue[row].maxVal;
                int parent = djRow.findSet(row * szRow + column);
                if(mp.find( parent ) == mp.end()){
                    mp[parent] = nextValueRowWise;
                }else{
                    mp[parent] = max( nextValueRowWise, mp[parent] );
                }

            }else{
                nextValueRowWise = maxRowValue[row].maxVal+1;
            }

            if( maxColumnValue[column].val == val ){
                recalculation.insert( make_pair(row,column) );
                recalculation.insert( make_pair(maxColumnValue[column].row ,maxColumnValue[column].column) );
                djRow.unionSet( row * szRow + column, maxColumnValue[column].row * szRow + maxColumnValue[column].column );
                nextValueColumnWise = maxColumnValue[column].maxVal;
                int parent = djRow.findSet(row * szRow + column);
                if(mp.find( parent ) == mp.end()){
                    mp[parent] = nextValueColumnWise;
                }else{
                    mp[parent] = max( nextValueColumnWise, mp[parent] );
                }
            }else{
                nextValueColumnWise = maxColumnValue[column].maxVal+1;
            }

            matrix[row][column] = max( nextValueRowWise, nextValueColumnWise );
            Info info1, info2;
            info1.val = val;
            info1.maxVal = matrix[row][column];
            info1.row = row;
            info1.column = column;

            info2.val = val;
            info2.maxVal = matrix[row][column];
            info2.row = row;
            info2.column = column;

            maxRowValue[row] = info1;
            maxColumnValue[column] = info2;
            q.push( index );
            if(index < sz -1){
                if(sortedPositions[index].first != sortedPositions[index+1].first ){
                    if(recalculation.size() > 1){
                        for(set<pair<int,int> >::iterator it = recalculation.begin(); it != recalculation.end();it++){
                            row = (it->first);
                            column = (it->second);
                            mp[djRow.findSet(row * szRow + column)] = max(mp[djRow.findSet(row * szRow + column)],matrix[row][column]);
                        }

                        for(set<pair<int,int> >::iterator it = recalculation.begin(); it != recalculation.end();it++){
                            row = (it->first);
                            column = (it->second);
                            matrix[row][column] = mp[ djRow.findSet(row * szRow + column) ];

                            Info info3, info4;
                            info3.val = val;
                            info3.maxVal = matrix[row][column];
                            info3.row = row;
                            info3.column = column;

                            info4.val = val;
                            info4.maxVal = matrix[row][column];
                            info4.row = row;
                            info4.column = column;

                            maxRowValue[row] = info3;
                            maxColumnValue[column] = info4;

                        }
                    }
                    set<pair<int,int> > empty;
                    swap( recalculation, empty );
                    mx = INT_MIN;
                }
            }
        }

        int index = sz-1,val,row,column,nextValueRowWise,nextValueColumnWise;
        if(sortedPositions[index].first == sortedPositions[index-1].first && q.size() > 1){
            if(recalculation.size() > 1){
                mx = INT_MIN;
                for(set<pair<int,int> >::iterator it = recalculation.begin(); it != recalculation.end();it++){
                    row = (it->first);
                    column = (it->second);
                    mp[djRow.findSet(row * szRow + column)] = max(mp[djRow.findSet(row * szRow + column)],matrix[row][column]);
                }

                for(set<pair<int,int> >::iterator it = recalculation.begin(); it != recalculation.end();it++){
                    row = (it->first);
                    column = (it->second);
                    matrix[row][column] = mp[ djRow.findSet(row * szRow + column) ];

                    Info info3, info4;
                    info3.val = val;
                    info3.maxVal = matrix[row][column];
                    info3.row = row;
                    info3.column = column;

                    info4.val = val;
                    info4.maxVal = matrix[row][column];
                    info4.row = row;
                    info4.column = column;

                    maxRowValue[row] = info3;
                    maxColumnValue[column] = info4;

                }
            }
        }
        return matrix;
    }
};

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
    LeetCodeInputTaker<int> scanner;
    vector<vector<int> > input = scanner.take();

    Solution solution;
    vector<vector<int> > answer = solution.matrixRankTransform(input);
    scanner.display(answer);
    return 0;
}
