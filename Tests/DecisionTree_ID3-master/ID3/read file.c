#include<stdio.h>
#include<string.h>
#define check(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define MAXLENGTH 10
int main(){
    char class1[MAXLENGTH],line,attributes[6][MAXLENGTH],tags[MAXLENGTH];
    FILE *fp;
    char temp[20];
    int i;
    fp = fopen("monks-1.test", "r");
    while(fscanf(fp, "%s %s %s %s %s %s %s %s", class1, attributes[0], attributes[1],attributes[2], attributes[3], attributes[4], attributes[5], tags)!= EOF){
    //while(fscanf(fp, "%s %s %s %s %s %s %s %s", &class1, &attributes[0], &attributes[1], &attributes[2], &attributes[3], &attributes[4], &attributes[5], &tags)){
        //fgets(temp, 10, fp);
        printf( "%s %s %s %s %s %s %s %s\n", class1, attributes[0], attributes[1],attributes[2], attributes[3], attributes[4], attributes[5], tags);
        /*
        for(i=0;i<6;i++){
            fgets(attributes[i], MAXLENGTH, fp);
        }
        */
        //fgets(tags, MAXLENGTH, fp);
        //printf  ("%s", class1);
        //printf  ("HELLO: %s\n", class1);
    }
    fclose(fp);


    return 0;
}
