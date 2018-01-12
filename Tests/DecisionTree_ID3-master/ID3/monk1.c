#include <stdio.h>
#include <stdlib.h>
#include "id3.c"
#define MAXLENGTH 10

char dataset[20000][20];/* =
{
// 	attr 1		attr 2		attr 3		attr 4		classes1, 1, 1, 1, 1, 2,
"Sunny","Hot","High","Weak","No",
"Sunny","Hot","High","Strong","No",
"Overcast","Hot","High","Weak","Yes",
"Rain","Mild","High","Weak","Yes",
"Rain","Cool","Normal","Weak","Yes",
"Rain","Cool","Normal","Strong","No",
"Overcast","Cool","Normal","Strong","Yes",
"Sunny","Mild","High","Weak","No",
"Sunny","Cool","Normal","Weak","Yes",
"Rain","Mild","Normal","Weak","Yes",
"Sunny","Mild","Normal","Strong","Yes",
"Overcast","Mild","High","Strong","Yes",
"Overcast","Hot","Normal","Weak","Yes",
"Rain","Mild","High","Strong","No"
};
*/

int main()
{
    int result = 0;
    char class1[MAXLENGTH],line,attributes[6][MAXLENGTH],tags[MAXLENGTH];

    FILE *fp;
    fp = fopen("monks-1.test", "r");
    int counter= 0, i;
    while(fscanf(fp, "%s %s %s %s %s %s %s %s", class1, attributes[0], attributes[1],attributes[2], attributes[3], attributes[4], attributes[5], tags)!= EOF){
        strcpy(dataset[counter++], class1);
        strcpy(dataset[counter++], attributes[0]);
        strcpy(dataset[counter++], attributes[1]);
        strcpy(dataset[counter++], attributes[2]);
        strcpy(dataset[counter++], attributes[3]);
        strcpy(dataset[counter++], attributes[4]);
        strcpy(dataset[counter++], attributes[5]);
        printf("%s\n", dataset[counter-1]);
        /*
        dataset[counter++] = class1;
        dataset[counter++] = attributes[0];
        dataset[counter++] = attributes[1];
        dataset[counter++] = attributes[2];
        dataset[counter++] = attributes[3];
        dataset[counter++] = attributes[4];
        dataset[counter++] = attributes[5];
        */
    };
    printf("Counter: %d\n", (counter/7));
    fclose(fp);
    result = id3tree_create( 	dataset,			// puntatore al database
								7,					// totale colonne ( attributi + classi )
								(counter/7),					// totale samples nel database
								"class",			// etichetta per attributo 1
								"att1",		// etichetta per attributo 2
								"att2",		// etichetta per attributo 2
								"att3",		// etichetta per attributo 2
								"att4",		// etichetta per attributo 2
								"att5",		// etichetta per attributo 2
								"att6",		// etichetta per attributo 2
								NULL				// terminatore
							);
    //printf( "Esito: %d\n", result );


    return 0;
}
