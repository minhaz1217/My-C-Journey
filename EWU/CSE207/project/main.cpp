#include<bits/stdc++.h>
#include<windows.h>
#include<conio.h>
#include "final/headerFiles.cpp"

using namespace std;
#define check(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define PROJECT_TITLE "SYNTAX PARSER"
#define FILE_NAME "files/testProblem2.cpp"
#define MAX_LINE_LENGTH 1000
string fileLine[MAX_LINE_LENGTH];
char tokens[] = " ;,.+-*/=<>-&|{}[]()\n";
char tempKeyWords[] = "if else for while int char float double string void break continue NULL main cout cin printf scanf endl return do switch case";
string cKeywords[500];
string skippingEntry = "";
int fileLineCounter = 0, keywordCounter = 0, stringFlag = 0;
int colorDefault = 240;
sc_stack ss;
qs_queue errorQueue;
ls_node *myFile, *variables, *words;


void menu();
void pauseScreen();

void trim(string &st){
    //it changes the string to exclude all spaces/tabs in the code
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
}
void readFile(char fileName[]="0"){
    // reads the file and puts in into a linked list called myFile and an array fileLine, also skips all the empty lines, also removes any tab spaces
    string s;
    FILE *pFile;
    char buffer[MAX_LINE_LENGTH];
    fileLineCounter = 0;
    myFile = NULL;
    if(fileName == "0"){
        pFile = fopen(FILE_NAME, "r");
        cout << "Opening File : " << FILE_NAME << endl;
    }else{
        pFile = fopen(fileName, "r");
        cout << "Opening File : " << fileName << endl;
    }
    if(pFile == NULL){
        cout << "ERROR IN OPENING FILE. Please try again." << endl;
        pauseScreen();
        menu();
        return;
    }else{
        while(!feof(pFile)){
            if(fgets(buffer, MAX_LINE_LENGTH, pFile) == NULL){
                break;
            }
            s = buffer;
            trim(s);
            // because length =1 if and only if there is only a line break
            if(s.length() >1){
                //createList(myFile, s);
                fileLine[fileLineCounter++] = s;
                createList(myFile, s, fileLineCounter);
            }
        }
        fclose(pFile);
    }
}
int checkForFIRSTBracketError(int l){
    // checks for first brackets mismatch on a give line L
    int i;
    char tmp;
    string stmp = fileLine[l];
    sc_stack lineStack1;
    for(i=0;stmp[i];i++){
        tmp = stmp[i];
        if(tmp == '('){
            push(lineStack1, tmp, l);
        }else if(tmp == ')'){
            if(top(lineStack1) == '('){
                pop(lineStack1);
            }else{
                enqueue(errorQueue, "First Brackets error.", l+1, 11);
            }
        }
    }
    if(lineStack1.size != 0){
        enqueue(errorQueue, "First brackets error.", l+1, 11);
    }
    return 0;
}


int checkForTHIRDBracketError(int l){
    // checks for third brackets mismatch on a give line L
    int i;
    char tmp;
    sc_stack lineStack2;
    string stmp = fileLine[l];
    for(i=0;stmp[i];i++){
        tmp = stmp[i];
        if(tmp == '['){
            push(lineStack2, tmp, l);
        }else if(tmp == ']'){
            if(top(lineStack2) == '['){
                pop(lineStack2);
            }else{
                enqueue(errorQueue, "Third Brackets error.", l+1, 12);
                //return 12;
            }
        }
    }
    if(lineStack2.size != 0){
        enqueue(errorQueue, "Third Brackets error.", l+1, 12);
    }
    return 0;
    // 0 means no problem
}
void checkForSyntexError(int l){
    string st = fileLine[l];
    if(st.find("&&") > st.length() && st.find("&") < st.length() ){
        enqueue(errorQueue, "1 & instead of 2 &s", l+1, 21 );
    }
    if(st.find("||") > st.length() && st.find("|") < st.length() ){
        enqueue(errorQueue, "1 & instead of 2 &s", l+1, 22 );
    }
    if(st.find("if") > st.length() && st.find("==") < st.length() ){
        enqueue(errorQueue, "found == without an if", l+1, 25 );
    }
    if(st.find("=<") < st.length() ){
        enqueue(errorQueue, "=< found.", l+1, 23 );
    }
    if(st.find("=>") < st.length() ){
        enqueue(errorQueue, "=> found.", l+1, 24 );
    }
}

void checkForFileBracketMismatch(){
    // swap through the whole code and finds { mismatch, only second brackets can expand to different lines , so we check for only second brackets
    int i,j;
    string tempString;
    char ctmp;
    sc_stack brStack;
    for(i=0;i<fileLineCounter;i++){
        tempString = fileLine[i];
        for(j=0;tempString[j];j++){
            ctmp = tempString[j];
            if(ctmp == '{'){
                push(brStack, '{', i+1);
            }else if(ctmp == '}'){
                if(top(brStack) == '{'){
                    pop(brStack);
                }else{
                    //c("bracket mismatch found")
                    enqueue(errorQueue, "2nd bracket", i+1, 13);
                }
            }
        }
    }
}
void checkForBranchingIf(){
    // checks if branching ifs are ok, ie: there are no else without an if, there are no else if without an if.
    int i;
    string testLine;
    sc_stack ifStack;
    for(i=0;i<fileLineCounter;i++){
        testLine = fileLine[i];
        if(testLine.find("else if") < testLine.length()){
            if(top(ifStack) != '{'){
                enqueue(errorQueue, "else if error", i+1, 14);
            }
        }else if(testLine.find("if") < testLine.length()){
            push(ifStack, '{', i+1);
        }else if(testLine.find("else") < testLine.length()){
            if(top(ifStack) == '{'){
                pop(ifStack);
            }else{
                enqueue(errorQueue, "else without if error", i+1, 15);
            }
        }
    }
}

int checkForEndofLineColon(int l){
    // starts from the end of any given line l and checks if the first character it found is ;
    string stmp;
    int i;
    stmp = fileLine[l];
    for(i=stmp.length();i>=0;i--){
        if(stmp[i] == ';'){
            return 1;
        }
    }
    enqueue(errorQueue, "No semicolon at the end of line.", l+1, 16);
    return 0;
}
int checkUnwantedKeys(string st){
    // checks if the given string st has any unwanted keys (c/cpp keywords) or (strings that are inside " or '
    // returns 0 if there are no unwanted keys, returns 1 if there are unwanted keys
    char *pt;
    int i;

    if(st.find('"') <st.length() || st.find("'") < st.length()){
        if(st[st.length()-1] == '"' || st[st.length()-1] == '\''){
            stringFlag = 0;
            return 1;
        }
        if(stringFlag == 0){
            stringFlag = 1;
            return 1;
        }else if(stringFlag == 1){
            stringFlag = 0;
            return 1;
        }
    }else if(stringFlag == 1){
        return 1;
    }
    for(i=0;i<keywordCounter;i++){
        if(cKeywords[i] == st){
            return 1;
        }
    }

    return 0;
    //1 means found, 0 means not found
}
void scrapWords(){
    // find every possible word that are not generic c/cpp keywords. We assume all those found words are variable names
    int i,tLength,stringFlag = 0;
    ls_node *tmp = myFile;
    string tstr, sTemp;
    char tchar[500], *p;
    while(tmp != NULL){
        tstr = tmp->lsStr;
        if(tstr.find("#") < tstr.length() || tstr.find("using") < tstr.length() || tstr.find("return") < tstr.length() ){
            tmp = tmp->next;
            continue;
        }
        for(i=0;tstr[i];i++){
            tchar[i] = tstr[i];
        }
        tchar[i] = '\0';
        p = strtok(tchar, tokens);
        //strtok splits the sentence by the tokens.
        while(p!= NULL){
            sTemp = p;
            if(!checkUnwantedKeys(sTemp)){
                createList(words, sTemp, tmp->line);
            }
            p = strtok(NULL, tokens);
        }
        tmp = tmp->next;
    }
}
void inputVariables(string st){
    // lists the variables in to "variables" linked list
    char ctemp[MAX_LINE_LENGTH], *p;
    int i;

    for(i=0;st[i];i++){
        ctemp[i] = st[i];
    }
    ctemp[i] = '\0';
    char tkey[] = " ,;\n";
    if(st.find("(")< st.length() && st.find(")") < st.length()){
        // ignoring the functions that might be sent here.
        return;
    }else{
        p = strtok(ctemp, tkey);
        while(p!=NULL){
            if(search(variables, p) == 0){
                createList(variables, p, 0);
            }
            p = strtok(NULL, tkey);
        }
    }
}
void listVariables(){
    // find those lines where variables have been initiated and calls inputVariables to list the variables.
    int i;
    string stTemp;
    for(i=0;i < fileLineCounter;i++){
        stTemp = fileLine[i];
        if(stTemp.find("int") < stTemp.length()){
            checkForEndofLineColon(i);
            inputVariables( stTemp.substr( stTemp.find("int")+3 ) );
        }else if(stTemp.find("char") < stTemp.length()){
            checkForEndofLineColon(i);
            inputVariables( stTemp.substr( stTemp.find("char")+4 ) );
        }else if(stTemp.find("float") < stTemp.length()){
            checkForEndofLineColon(i);
            inputVariables( stTemp.substr( stTemp.find("float")+5 ) );
        }else if(stTemp.find("double") < stTemp.length()){
            checkForEndofLineColon(i);
            inputVariables( stTemp.substr( stTemp.find("double")+6 ) );
        }else if(stTemp.find("string") < stTemp.length()){
            checkForEndofLineColon(i);
            inputVariables( stTemp.substr( stTemp.find("string")+6 ) );
        }
    }
}
void populateKeywordArray(){
    char *p;
    p = strtok(tempKeyWords, " ");
    while(p!= NULL){
        cKeywords[keywordCounter++] = p;
        p = strtok(NULL, " ");
    }
}
void checkForVariableError(){
    ls_node *llword, *llvar;
    llword = words;
    while(llword != NULL){
        if(search(variables, llword->lsStr) == 0){
            enqueue(errorQueue, "Variable '"+ llword->lsStr +"' not found.", llword->line, 17);
        }
        llword = llword->next;
    }
}
void checkForIfBracketError(int l){
    string st = fileLine[l];
    int firstBracketFound = 0, firstBracketFoundAtLeastOnce = 0;
    sc_stack brackets1;
    // () if
    if(st.find("if") > st.find('(') ){
        enqueue(errorQueue, "If bracket started before if.", l+1, 18);
    }
    if(st.find("==") > st.length() && st.find("=") < st.length() ){
        enqueue(errorQueue, "= instead of == inside an if", l+1, 20);
    }
    while(st.find(" ") < st.length() ){
        //removing all the spaces from the if
        st.erase(st.find(" "), 1);
    }
    if(st[st.find("if") + 2] != '('){
        enqueue(errorQueue, "Wrong brackets after if", l+1,19);
    }
}
void sendLinesToDifferentFunctions(){
    int i;
    string stTemp;
    for(i=0;i<fileLineCounter;i++){
        stTemp = fileLine[i];
        if(stTemp.find("if") < stTemp.length()){
            checkForIfBracketError(i);
        }else if(stTemp.find("return") < stTemp.length()){
            checkForEndofLineColon(i);
        }else if(stTemp.find("=") <stTemp.length() && stTemp.find("if") > stTemp.length() ){
            // a = b+c; if(a=b+c){}
            checkForEndofLineColon(i);
        }else if(stTemp.find("return") < stTemp.length()){
            checkForEndofLineColon(i);
        }else if(stTemp.find("cout") < stTemp.length()){
            checkForEndofLineColon(i);
        }else if(stTemp.find("cin") < stTemp.length()){
            checkForEndofLineColon(i);
        }
        checkForFIRSTBracketError(i);
        checkForTHIRDBracketError(i);
        checkForSyntexError(i);
    }
}
void doAllTheThings(){
    // do the basic things than every time we needed to do, we could've done all these things in a single function, but we've separated this into small parts for better understanding.
    words = NULL;
    variables = NULL;
    errorQueue.head = NULL;
    errorQueue.size = 0;
    scrapWords();
    listVariables();
    deleteIntegersFromList(words);
    checkForVariableError();
    sendLinesToDifferentFunctions();
    checkForBranchingIf();
    display(myFile);
    cout << "Total Errors: " << errorQueue.size << endl;
    display(errorQueue);
    pauseScreen();
    menu();
}

void pauseScreen(){
    // pauses the screen until a button has been pressed.
    cout << "\nPress any key to continue\n";
    char tempgetch = getch();
}
void changeConsoleColor(int color){
    HANDLE consoleHandler = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(consoleHandler, color);
}
void clearScreen(){
    string spaces = "                        ";
    system("cls");
    SetConsoleTitle(PROJECT_TITLE);
    changeConsoleColor(27);
    cout <<setw(61) << "" << endl;
    cout << spaces<< PROJECT_TITLE << spaces << endl;
    cout <<setw(61) << "" << endl;
    cout << endl;
    changeConsoleColor(colorDefault);
}
void menu(){
    int ch;
    char strFileName[MAX_LINE_LENGTH];
    clearScreen();
    string myLine;
    cout << "Press 1 to enter file name and open file." << endl;
    cout << "Press 2 to enter a single line and parse it." << endl;
    cout << "Press 3 to read the default file set in code." << endl;
    cout << "Press Any Other Key To Exit." << endl;
    cout << "Enter your choice: ";
    cin >> ch;
    if(ch == 1){
        cout << "Enter file name: ";
        cin >> strFileName;
        readFile(strFileName);
        doAllTheThings();
    }else if(ch == 2){
        cout << "Enter a single line of code." << endl;
        cin.ignore();
        getline(cin ,myLine);
        createList(myFile, myLine, 1);
        fileLine[fileLineCounter++] = myLine;
        doAllTheThings();
    }else if(ch == 3){
        readFile("0");
        doAllTheThings();
    }else{
        exit(0);
    }
}



int main(){

    system("color f0");
    SetConsoleTitle(PROJECT_TITLE);


    myFile = NULL;
    words = NULL;
    variables = NULL;
    errorQueue.head = NULL;
    populateKeywordArray();
    menu();
    /*
    int lines = 0;
    populateKeywordArray();
    readFile("0");

    scrapWords();
    listVariables();
    deleteIntegersFromList(words);
    checkForVariableError();
    sendLinesToDifferentFunctions();
    checkForBranchingIf();

    //display(variables);

    display(myFile);
    /*
    cout << "VARIABLES" << endl;
    display(variables);
    cout << "WORDS" << endl;
    display(words);

    cout << "ERRORS" << endl;
    display(errorQueue);
    */
    return 0;
}
