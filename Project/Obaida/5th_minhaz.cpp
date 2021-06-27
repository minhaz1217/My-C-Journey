#include<bits/stdc++.h>
#include<iostream>
#include<stack>
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
stack< pair<int,int> > prevNode;

int currX , currY;
int blockA, blockB; // These are used to calculate horizontal or vertical split, A will have top or left, B will have value for bottom or right
char facing; /// it can have 'r','l', 'u','d'
map<char, int> directionWiseMoveX, directionWiseMoveY, directionWiseMoveopX, directionWiseMoveopY;


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
                if(mat[i][j] == 0 || mat[i][j] == inf){
                    blockA++;
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=currX+1;j<n;j++){
                if(mat[i][j] == 0 || mat[i][j] == inf){
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
        cout<<"blockA "<<blockA<<"blockB: "<<blockB;
        if(blockA==0 && blockB == 0){ // we don't have any zeros left, so our algo ends
            return -1;
        }
        else if(blockA == 0)
        {
            return 2;
        }
        else if(blockB == 0)
        {
            return 1;
        }
        else if(blockA == blockB){ // both has same value, we can go either direction
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
        mat[currY][currX+1] = mat[currY][currX+1] == inf ? 0 : mat[currY][currX+1];
    }
    if(currX - 1 >= 0){
        mat[currY][currX-1] = mat[currY][currX-1] == inf ? 0 : mat[currY][currX-1];
    }
    if(currY + 1 < n){
        mat[currY+1][currX] = mat[currY+1][currX] == inf ? 0 : mat[currY+1][currX];
    }
    if(currY - 1 >=0){
        mat[currY-1][currX] = mat[currY-1][currX] == inf ? 0 : mat[currY-1][currX];
    }
}

/// returns true if next move in the facing direction is collision to block or to boundary
bool collisionAhead(){
    // checking the boundary
    if( currX + directionWiseMoveX[ facing ] < 0 || currX + directionWiseMoveX[ facing ] >=n || currY + directionWiseMoveY[ facing ] < 0||currY + directionWiseMoveY[ facing ] >=n  ){
        return true;
    }else{
        if( mat[currY + directionWiseMoveY[facing]][currX + directionWiseMoveX[facing]] == block){
            return true;
        }else{
            return false;
        }
    }
}
bool cleanedAreaAhead(){
    if( mat[currY + directionWiseMoveY[facing]][currX + directionWiseMoveX[facing]] > 0){
            return true;}
}
/// it returns 0 if we can't find minimum neighbour,
/// it returns 1 for up, 2 for down, 3 for left, 4 for right, 5 for go back, 6 for both direction has same value
int findMinimumNeighbour(){
    if(facing == 'u' || facing == 'd'){
        if( currX + 1 < n  && currX-1 >=0 ){ // we can go both left and right
            if(mat[currY][currX+1] == block && mat[currY][currX-1] == block){ /// both left and right has block, so we need to go back.
                return 5;//go back
            }else if(mat[currY+1][currX] >0 && mat[currY-1][currX] == block){
                return 5;
            }else if(mat[currY+1][currX] ==block && mat[currY-1][currX] > 0){
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
            if(mat[currY+1][currX] == block && mat[currY-1][currX] == block){
                return 5;//go back
            }else if(mat[currY+1][currX] >0 && mat[currY-1][currX] == block){
                return 5; //up block down visited
            }else if(mat[currY+1][currX] ==block && mat[currY-1][currX] > 0){
                return 5; //down block up visited
            }
            else if( mat[currY+1][currX] == block){
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
        }else if( currY + 1 < n ){ // we can go only one direction down
            if(mat[currY+1][currX] == block){
                // our down has block, up has boundary, so we need to go back
                return 5;
            }else{
                return 2;
            }
        }else if( currY - 1 >= 0){ // we can go only one direction up
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


bool moreThanOneSameNeighbor()
{
    if(facing == 'u' || facing == 'd'){//90 degree for up,dowan
        if(mat[currY+1][currX] == mat[currY-1][currX]){ // both are same
                return true;}
        else
            {return false;}
    }
    else{//90 degree for left,right
        if(mat[currY+1][currX] == mat[currY-1][currX]){ // both are same
             cout<<"UP "<<mat[currY-1][currX];
             cout<<"DOWN "<<mat[currY+1][currX];
                return true;}
        else
            {
            cout<<"UP "<<mat[currY-1][currX];
            cout<<"DOWN "<<mat[currY+1][currX];
            return false;
            }
        }

}

bool minimumValueForward()
{
    if(facing == 'r' && currX+1 <n){
        if(currY+1 > currX+1 && currY-1 > currX+1){
        cout<<"right and minimum forward";
        return true;
        }
        else{
            cout<<"right and not minimum forward";
            return false;
        }
    }
    else if(facing == 'l' && currX-1 >0){
        if(currY+1 > currX-1 && currY-1 > currX-1){
        cout<<"left and minimum forward";
        return true;}
        else{
            cout<<"left and not minimum forward";
            return false;}
    }
    else if(facing == 'u' && currY-1 >0){
        if(currX+1 > currY-1 && currX-1 > currY-1){
        cout<<"up and minimum forward";
        return true;}
        else
        {
            cout<<"UP and not minimum forward";
            return false;
        }
    }
    else if(facing == 'd' && currY+1 >n){
        if(currX+1 > currY-1 && currX-1 > currY-1){
        cout<<"Down and minimum forward";
        return true;}
        else
        {
            cout<<"Down and not minimum forward";
            return false;}
    }
}

void goBack(){
    currX = prevNode.top().first;
    currY = prevNode.top().second;
    prevNode.pop();
}
void printRoom(){
    cout << endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i == currY && j == currX){
                if(facing == 'u'){
                    printf("%7c", '^');
                }else if(facing == 'd'){
                    printf("%7c", 'v');
                }else if(facing == 'l'){
                    printf("%7c", '<');
                }else if(facing == 'r'){
                    printf("%7c", '>');
                }else{
                    printf("%7c", 'X');
                }
            }else{
                if(mat[i][j] == block){
                    printf("▇");
                }else{
                    printf("%7d", mat[i][j]);
                }
            }
            cout << "\t";
        }
        cout << endl;
    }
    cout << endl;
}

void makeMove(){
    mat[currY][currX]++;
    makeAllInfNeighboursZero();
    printRoom();
    if(collisionAhead())
    {
        int nextDirection = findMinimumNeighbour();
        if(nextDirection<=4)//minimum neighbor found
        {
            cout<<"1st turn ";
            makeRobotFaceToward(nextDirection);
            int myNextMove = bothNeighbourHasSameValueWhereShouldIGo();
            if(myNextMove == -1){
                cout << "ALGO COMPLETE!! HURRAY!!" << endl;
                exit(0);
            }
            prevNode.push( make_pair( currX, currY));
            currX = currX + directionWiseMoveX[facing];
            currY = currY + directionWiseMoveY[facing];
            cout<<"CurrX: "<<currX<<"currY: "<<currY<<endl;
            mat[currY][currX]++;
            makeAllInfNeighboursZero();
            printRoom();
            goto secondturn;
        }
        else{//more then 1 same neighbor?
            if(nextDirection == 6){ // both has same value
                int myNextMove = bothNeighbourHasSameValueWhereShouldIGo();//select neighbor with smaller distant

                if(myNextMove == -1){
                    cout << "ALGO COMPLETE!! HURRAY!!" << endl;
                    exit(0);
                }else{
                    makeRobotFaceToward(myNextMove);
                    prevNode.push( make_pair( currX, currY));
                    currX = currX + directionWiseMoveX[facing];
                    currY = currY + directionWiseMoveY[facing];
                    mat[currY][currX]++;
                    makeAllInfNeighboursZero();
                    printRoom();
                    goto secondturn;
                    makeMove();
                }
            }
            else if(minimumValueForward())
            {
                mat[currY][currX]++;
                prevNode.push( make_pair( currX, currY));
                currX = currX + directionWiseMoveX[facing];
                currY = currY + directionWiseMoveY[facing];
                makeAllInfNeighboursZero();
                printRoom();
                goto secondturn;
            }
            else if( nextDirection == 5){ // we need to go back
                mat[currY][currX]++;
                makeAllInfNeighboursZero();
                goBack();
                printRoom();
                makeMove();
            }
        }
    }
    else{
        prevNode.push( make_pair( currX, currY));
        currX = currX + directionWiseMoveX[facing];
        currY = currY + directionWiseMoveY[facing];
        makeAllInfNeighboursZero();
        printRoom();
        makeMove();
    }


    secondturn:{
        int nextDirection = findMinimumNeighbour();
        if(nextDirection<=4)//minimum neighbor found
        {
            cout<<"1st turn ";
            makeRobotFaceToward(nextDirection);
            int myNextMove = bothNeighbourHasSameValueWhereShouldIGo();
            if(myNextMove == -1){
                cout << "ALGO COMPLETE!! HURRAY!!" << endl;
                exit(0);
            }
            prevNode.push( make_pair( currX, currY));
            currX = currX + directionWiseMoveX[facing];
            currY = currY + directionWiseMoveY[facing];
            cout<<"CurrX: "<<currX<<"currY: "<<currY<<endl;
            mat[currY][currX]++;
            makeAllInfNeighboursZero();
            printRoom();
            makeMove();
        }
        else{//more then 1 same neighbor?
            if(nextDirection == 6){ // both has same value
                int myNextMove = bothNeighbourHasSameValueWhereShouldIGo();//select neighbor with smaller distant

                if(myNextMove == -1){
                    cout << "ALGO COMPLETE!! HURRAY!!" << endl;
                    exit(0);
                }else{
                    makeRobotFaceToward(myNextMove);
                    prevNode.push( make_pair( currX, currY));
                    currX = currX + directionWiseMoveX[facing];
                    currY = currY + directionWiseMoveY[facing];
                    mat[currY][currX]++;
                    makeAllInfNeighboursZero();
                    printRoom();
                    makeMove();
                }
            }
            else if(minimumValueForward())
            {
                mat[currY][currX]++;
                prevNode.push( make_pair( currX, currY));
                currX = currX + directionWiseMoveX[facing];
                currY = currY + directionWiseMoveY[facing];
                makeAllInfNeighboursZero();
                printRoom();
                makeMove();
            }
            else if( nextDirection == 5){ // we need to go back
                mat[currY][currX]++;
                makeAllInfNeighboursZero();
                goBack();
                printRoom();
                makeMove();
            }
        }
    }//secondturn finish
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

	directionWiseMoveopX['u'] = 0;
	directionWiseMoveopX['d'] = 0;
	directionWiseMoveopX['l'] = 1;
	directionWiseMoveopX['r'] = -1;

	directionWiseMoveopY['u'] = 1;
	directionWiseMoveopY['d'] = -1;
	directionWiseMoveopY['l'] = 0;
	directionWiseMoveopY['r'] = 0;


	for(int i=0;i<MX;i++){
        for(int j=0;j<MX;j++){
            mat[i][j] = inf;
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
    mat[0][0] = 0;
    facing = 'r';
    makeMove();

    return 0;
}
