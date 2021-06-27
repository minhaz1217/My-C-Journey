/*
Minhazul Hayat Khan
Website: www.minhazul.com
EWU, Bangladesh
Problem Name:
Problem Link:
Date : 21 / September / 2020
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


#define MX 1000

int block = 999999;
int inf = -111111;
int n;
int mat[MX][MX];
int prevX[MX][MX];
int prevY[MX][MX];
int currX , currY;
int blockA, blockB; // These are used to calculate horizontal or vertical split, A will have top or left, B will have value for bottom or right
char facing; /// it can have 'r','l', 'u','d'
map<char, int> directionWiseMoveX, directionWiseMoveY;


/// This will split the area corresponding to direction, either 'v' for vertical, or 'h' for horizontal. and put the value in
void countNumberOfZeros(char direction){
    blockA = 0;
    blockB = 0;
    if(direction == 'h'){
        for(int i=0;i<currY;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j] == 0){
                    blockA++;
                }
            }
        }
        for(int i=currY+1;i<n;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j] == 0){
                    blockB++;
                }
            }
        }
    }else if(direction == 'v'){
        for(int i=0;i<n;i++){
            for(int j=0;j<currX;j++){
                if(mat[i][j] == 0){
                    blockA++;
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=currX+1;j<n;j++){
                if(mat[i][j] == 0){
                    blockB++;
                }
            }
        }
    }
}


/// returns -1 to end the algo
/// returns 1 for up, 2 for down, 3 for left, 4 for right
int bothNeighbourHasSameValueWhereShouldIGo(){
    if(facing == 'l' || facing == 'r'){
        countNumberOfZeros('h');
        if(blockA==0 && blockB == 0){ // we don't have any zeros left, so our algo ends
            return -1;
        }else if(blockA == blockB){ // both has same value, we can go either direction
            // we go to the direction which is closer to the boundary.
            if(currY < n-currY){ // top side is closer to the boundary
                return 1;
            }else{
                return 2;
            }
        }else if(blockA < blockB){
            return 1;
        }else{
            return 2;
        }
    }else{
        countNumberOfZeros('v');
        if(blockA==0 && blockB == 0){ // we don't have any zeros left, so our algo ends
            return -1;
        }else if(blockA == blockB){ // both has same value, we can go either direction
            // we go to the direction which is closer to the boundary.
            if(currX < n-currX){ // left side is closer to the boundary
                return 3;
            }else{
                return 4;
            }
        }else if(blockA < blockB){
            return 3;
        }else{
            return 4;
        }
    }
}

void makeAllInfNeighboursZero(){
    if(currX + 1 < n){
        mat[currX+1][currY] = mat[currX+1][currY] == inf ? 0 : mat[currX+1][currY];
    }
    if(currX - 1 >= 0){
        mat[currX-1][currY] = mat[currX-1][currY] == inf ? 0 : mat[currX-1][currY];
    }
    if(currY + 1 < n){
        mat[currX][currY+1] = mat[currX][currY+1] == inf ? 0 : mat[currX][currY+1];
    }
    if(currY - 1 >=0){
        mat[currX][currY-1] = mat[currX][currY-1] == inf ? 0 : mat[currX][currY-1];
    }
}

/// returns true if next move in the facing direction is collision to block or to boundary
bool collisionAhead(){
    // checking the boundary
    if( currX + directionWiseMoveX[ facing ] < 0||currX + directionWiseMoveX[ facing ] >=n || currY + directionWiseMoveY[ facing ] < 0||currY + directionWiseMoveY[ facing ] >=n  ){
        return true;
    }else{
        if( mat[currY + directionWiseMoveY[facing]][currX + directionWiseMoveX[facing]] == block){
            return true;
        }else{
            return false;
        }
    }
}

/// it returns 0 if we can't find minimum neighbour,
/// it returns 1 for up, 2 for down, 3 for left, 4 for right, 5 for go back, 6 for both direction has same value
int findMinimumNeighbour(){
    if(facing == 'u' || facing == 'd'){
        if( currX + 1 < n  && currX-1 >=0 ){ // we can go both left and right
            if(mat[currY][currX+1] == block && mat[currY][currX-1] == block){ /// both left and right has block, so we need to go back.
                return 5;
            }else if( mat[currY][currX+1] == block ){ // we know both doesn't have blcok, so if right has block we go left, or vice versa
                return 3; // right has block so we go left
            }else if(mat[currY][currX-1] == block){
                return 4; // left has block so we go right
            }else if(mat[currY][currX+1]==mat[currY][currX-1]){ // both is same
                return 6;
            }else if(mat[currY][currX+1] < mat[currY][currX-1]){ // right is less
                return 4;
            }else{
                return 3;
            }
        }else if( currX + 1 < n ){ // we can go only one direction, either left, or right
            if(mat[currY][currX+1] == block){
                // our right has block, left has boundary, so we need to go back
                return 5;
            }else{
                return 4;
            }
        }else if( currX - 1 >= 0){
            if(mat[currY][currX-1] == block){
                // our left has block and right has boundary
                return 5;
            }else{
                return 3;
            }
        }
    }else{
        if( currY + 1 < n  && currY-1 >=0 ){ // we can go up and down
            if(mat[currY+1][currX] == block && mat[currY-1][currX] == block){ /// both top and down has block, so we need to go back.
                return 5;
            }else if( mat[currY+1][currX] == block ){
                return 1; // down has block so we go up
            }else if(mat[currY-1][currX] == block){
                return 2; // up has block so we go down
            }else if(mat[currY+1][currX] == mat[currY-1][currX]){ // both are same
                return 6;
            }else if(mat[currY+1][currX] < mat[currY-1][currX]){ // down is less
                return 2;
            }else{
                return 1;
            }
        }else if( currY + 1 < n ){ // we can go only one direction, either up, or down
            if(mat[currY+1][currX] == block){
                // our down has block, up has boundary, so we need to go back
                return 5;
            }else{
                return 2;
            }
        }else if( currY - 1 >= 0){
            if(mat[currY-1][currX] == block){
                // our up has block and down has boundary
                return 5;
            }else{
                return 1;
            }
        }
    }
}
void makeRobotFaceToward(int intDirection){
    if(intDirection == 1){
        facing ='u';
    }else if(intDirection == 2){
        facing ='d';
    }else if(intDirection == 3){
        facing ='l';
    }else if(intDirection == 4){
        facing ='r';
    }
}
void goBack(){
    int temp = currX;
    currX = prevX[currY][temp];
    currY = prevY[currY][temp];
}
void printRoom(){
    cout << endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i == currY && j == currX){
                if(facing == 'u'){
                    printf("%6c", '^');
                }else if(facing == 'd'){
                    printf("%6c", 'v');
                }else if(facing == 'l'){
                    printf("%6c", '<');
                }else if(facing == 'r'){
                    printf("%6c", '>');
                }else{
                    printf("%6c", 'X'); // if at any moment this prints, then something has gone wrong.
                }
            }else{
                printf("%6d", mat[i][j]);
            }
        }
        cout << endl;
    }
    cout << endl;
}

void makeMove(){
    printRoom();
    mat[currY][currX]++;
    makeAllInfNeighboursZero();
    if(collisionAhead()){
        // Now we can't go forward, so we have to check our left or right neighbours and make decision.
        int nextDirection = findMinimumNeighbour();
        if( nextDirection == 5){ // we need to go back
            mat[currY][currX]++;
            printRoom();
            goBack();
            makeMove();
        }else if(nextDirection == 6){ // both has same direction
            int myNextMove = bothNeighbourHasSameValueWhereShouldIGo();
            if(myNextMove == -1){
                cout << "ALGO COMPLETE!! HURRAY!!" << endl;
                return;
            }else{
                makeRobotFaceToward(myNextMove);
                prevX[currX + directionWiseMoveX[facing]][currX + directionWiseMoveX[facing]] = currX; // we have come to our this position from previous position
                prevY[currY + directionWiseMoveY[facing]][currY + directionWiseMoveY[facing]] = currY;
                currX = currX + directionWiseMoveX[facing];
                currY = currY + directionWiseMoveY[facing];
                makeMove();
            }
        }else{
            // we have found a minimum to rotate to.
            makeRobotFaceToward(nextDirection);
            // this is our first rotation
            prevX[currX + directionWiseMoveX[facing]][currX + directionWiseMoveX[facing]] = currX; // we have come to our this position from previous position
            prevY[currY + directionWiseMoveY[facing]][currY + directionWiseMoveY[facing]] = currY;
            currX = currX + directionWiseMoveX[facing];
            currY = currY + directionWiseMoveY[facing];
            mat[currY][currX]++;
            printRoom();
            makeAllInfNeighboursZero();
            nextDirection = findMinimumNeighbour();
            if(nextDirection == 5){ // we need to go  back
                mat[currY][currX]++;
                printRoom();
                goBack();
                makeMove();
            }else if(nextDirection == 6){ // both has same value
                int myNextMove = bothNeighbourHasSameValueWhereShouldIGo();
                if(myNextMove == -1){
                    cout << "ALGO COMPLETE!! HURRAY!!" << endl;
                    return;
                }else{
                    makeRobotFaceToward(myNextMove);
                    prevX[currX + directionWiseMoveX[facing]][currX + directionWiseMoveX[facing]] = currX; // we have come to our this position from previous position
                    prevY[currY + directionWiseMoveY[facing]][currY + directionWiseMoveY[facing]] = currY;
                    currX = currX + directionWiseMoveX[facing];
                    currY = currY + directionWiseMoveY[facing];
                    makeMove();
                }
            }else{
                makeRobotFaceToward(nextDirection);
                // this is our second rotation
                prevX[currX + directionWiseMoveX[facing]][currX + directionWiseMoveX[facing]] = currX; // we have come to our this position from previous position
                prevY[currY + directionWiseMoveY[facing]][currY + directionWiseMoveY[facing]] = currY;
                currX = currX + directionWiseMoveX[facing];
                currY = currY + directionWiseMoveY[facing];
                makeMove();
            }
        }
    }else{
        // as there is no collision or boundary ahead so we move to the direction we are moving.
        currX = currX + directionWiseMoveX[facing];
        currY = currY + directionWiseMoveY[facing];
        makeMove();
    }


}
int main(){

    /// setup
    directionWiseMoveX['u'] = 0;
	directionWiseMoveX['d'] = 0;
	directionWiseMoveX['l'] = -1;
	directionWiseMoveX['r'] = 1;

	directionWiseMoveY['u'] = -1;
	directionWiseMoveY['d'] = 1;
	directionWiseMoveY['l'] = 0;
	directionWiseMoveY['r'] = 0;
	for(int i=0;i<MX;i++){
        for(int j=0;j<MX;j++){
            mat[i][j] = inf;
            prevX[i][j] = inf;
            prevY[i][j] = inf;
        }
	}


/// For dynamic input taking
//    cin >> n;
//    for(int i=0;i<n;i++){
//        for(int j=0;j<n;j++){
//            cin >> mat[i][j];
//        }
//    }

    n = 8;
    int preset[n][n] = {
        {  inf,   inf, inf, block, block, inf, inf, inf},
        {  inf,   inf, inf, block, block, inf, inf, inf},
        {  inf,   inf, inf, block, block, inf, inf, inf},
        {  inf,   inf, inf,   inf,   inf, inf, inf, inf},
        {  inf,   inf, inf,   inf,   inf, inf, inf, inf},
        {block, block, inf,   inf,   inf, inf, inf, inf},
        {block, block, inf,   inf,   inf, inf, inf, inf}
    };
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            mat[i][j] = preset[i][j];
        }
    }

    /// starting from top left side of the map, facing right
    prevX[0][0] = 0;
    prevY[0][0] = 0;
    mat[0][0] = 0;
    facing = 'r';
    makeMove();

    return 0;
}
