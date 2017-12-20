#include<bits/stdc++.h>
using namespace std;
#define check(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;

#define FILE_NAME "prb1.cpp"
#define MAX_LINE_LENGTH 1000


// ls = link list string
struct ls_node{
    string lsStr;
    int line;
    ls_node *next;
}*lsHead, *lsTail, *lsTemp;
void createList(ls_node *&given, string str, int l){
    ls_node *curr, *tmp;

    curr = new ls_node;
    curr->lsStr = str;
    curr->line = l;
    curr->next = NULL;
    if(given == NULL){
        given = curr;
    }else{
        tmp = given;
        while(tmp->next != NULL){
            tmp = tmp->next;
        }
        tmp->next = curr;
    }
}

void display(ls_node *given){
    ls_node *tmp;
    tmp = given;
    while(tmp != NULL){
        cout << tmp->line << " : " << tmp->lsStr << endl;
        tmp = tmp->next;
    }
}
int search(ls_node *given, string srcString){
    ls_node *tmp;
    tmp = given;
    while(tmp!= NULL){
        if(tmp->lsStr == srcString){
            return 1;
        }
        tmp = tmp->next;
    }
    return 0;
}
void displayWithLines(ls_node *given){
    int counter = 1;
    ls_node *tmp;
    tmp = given;
    while(tmp != NULL){
        cout << counter++ << ": ";
        cout << tmp->lsStr;
        tmp = tmp->next;
    }
}
int isInteger(string s)
{
    int i;
    for(i=0;s[i];i++){
        if(isdigit(s[i]) == 0){
            if(s[i] == '.'){
                continue;
            }
            return 0;
        }
    }
    return 1;
}
void deleteIntegersFromList(ls_node *&given){
    ls_node *prev, *curr;
    prev = given;
    curr = given->next;
    while(prev != NULL){
        if(isInteger(curr->lsStr) == 1){
            ls_node *temp = curr;
            prev->next = curr->next;
            curr = curr->next;
            delete(temp);
        }
        prev = curr;
        curr = prev->next;
        if(curr == NULL){
            break;
        }
    }
}
//sc = stack character

struct sc_node{
    char ch;
    int line;
    sc_node *next;
};

struct sc_stack{
    sc_node *head = NULL;
    int size = 0;
};
void push(sc_stack &given, char c, int l){
    sc_node *curr;
    curr = new sc_node;
    curr->ch = c;
    curr->line = l;
    curr->next = NULL;
    if(given.head == NULL){
        given.head = curr;
    }else{
        curr->next = given.head;
        given.head = curr;
    }
    given.size++;
}
char pop(sc_stack &given){
    if(given.size!= 0){
        sc_node *tmp = given.head;
        char ch_temp = tmp->ch;
        given.head = given.head->next;
        delete(tmp);
        given.size--;
        return ch_temp;
    }else{
        return 0;
    }
}
sc_node popNode(sc_stack &given){
    if(given.size!= 0){
        sc_node *tmp = given.head;
        sc_node temp;
        temp.ch = tmp->ch;
        temp.line = tmp->line;
        char ch_temp = tmp->ch;
        given.head = given.head->next;
        delete(tmp);
        given.size--;
        return temp;
    }else{
        return sc_node();
    }
}
char top(sc_stack given){
    if(given.size!= 0){
        return given.head->ch;
    }else{
        return 0;
    }
}
sc_node topNode(sc_stack given){
    if(given.size!= 0){
        return sc_node{given.head->ch, given.head->line};
    }else{
        return sc_node();
    }
}
void display(sc_stack given){
    sc_node *tmp = given.head;
    while(tmp != NULL){
        printf("%c, %d\n", tmp->ch, tmp->line);
        tmp = tmp->next;
    }
}


// ls = link list string
struct qs_node{
    string qsStr;
    int line;
    int error;
    qs_node *next;
}*qsHead, *qsTail, *qsTemp;
struct qs_queue{
    qs_node *head = NULL;
    int size = 0;
};
void enqueue(qs_queue &given, string st, int l, int err){
    qs_node *curr,*tmp;
    curr = new qs_node;
    curr->qsStr = st;
    curr->line = l;
    curr->error = err;
    curr->next = NULL;
    if(given.head == NULL){
        given.head = curr;
    }else{
        tmp = given.head;
        while(tmp->next != NULL){
            tmp = tmp->next;
        }
        tmp->next = curr;
    }
    given.size++;
}
string dequeue(qs_queue &given){
    if(given.size!= 0){
        qs_node *tmp = given.head;
        string st_temp = tmp->qsStr;
        given.head = given.head->next;
        delete(tmp);
        given.size--;
        return st_temp;
    }else{
        return "-1";
    }
}
qs_node dequeueNode(qs_queue &given){
    if(given.size!= 0){
        qs_node *tmp = given.head;
        qs_node temp;
        temp.qsStr = tmp->qsStr;
        temp.line = tmp->line;
        temp.error = tmp->error;
        given.head = given.head->next;
        delete(tmp);
        given.size--;
        return temp;
    }else{
        return qs_node();
    }
}
string front(qs_queue given){
    if(given.size!= 0){
        return given.head->qsStr;
    }else{
        return 0;
    }
}
qs_node frontNode(qs_queue given){
    if(given.size!= 0){
        return qs_node{given.head->qsStr, given.head->line, given.head->error};
    }else{
        return qs_node();
    }
}
void display(qs_queue given){
    qs_node *tmp = given.head;
    while(tmp != NULL){
        cout << tmp->qsStr << " At line: " << tmp->line << " Error Code: " << tmp->error << " " << endl;
        tmp = tmp->next;
    }
}

string fileLine[MAX_LINE_LENGTH];
char tokens[] = " ;,.+-*/=<>-&|{}[]()\n";
char tempKeyWords[] = "if else for while int char float double string void break continue NULL main cout cin endl return";
string cKeywords[500];
string skippingEntry = "";
int fileLineCounter = 0, keywordCounter = 0, stringFlag = 0;
sc_stack ss;
qs_queue errorQueue;
ls_node *myFile, *variables, *words;
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
    if(fileName == "0"){
        pFile = fopen(FILE_NAME, "r");
    }else{
        pFile = fopen(fileName, "r");
    }
    if(pFile == NULL){
        cout << "ERROR IN OPENING FILE" << endl;
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
        }
        checkForFIRSTBracketError(i);
        checkForTHIRDBracketError(i);
        checkForSyntexError(i);
    }
}

int main(){
    int lines = 0;
    myFile = NULL;
    words = NULL;
    variables = NULL;

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
    */
    cout << "ERRORS" << endl;
    display(errorQueue);
    return 0;
}
