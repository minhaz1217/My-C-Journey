//prototype(not sytactically valid line)
for(initialization; condition; increment/decrement){}
while(condition is true){}

//Example
// prints from 1 to 10
for(i=1;i<=10;i++){
    printf("%d\n", i);
}
for(i=10;i>=1;i--){
    printf("%d\n", i);
}
//prints odd numbers from 1 to 10
for(i=1;i<=10;i+=2){
    printf("%d\n", i);
}
i=5;
//prints 10,12,14
while(i<=7){
    printf("%d\n", i*2);
    i++;
}
