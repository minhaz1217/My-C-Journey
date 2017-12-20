for(i=1;i<=10;i++){
    if(i%2 == 0){
        continue;
    }
    printf("%d\n", i);
}
for(i=1;i<=1;i++){
    if(i>3){
        break;
    }
    printf("%d\n", i);
}
//take input while it is not end of file.
while(scanf("%d", &a) != EOF){
    if(a == 0){
        break;
    }
    printf("%d\n",a);
}
//or in shourt.....
while(scanf("%d", &a)!= EOF && a){
    printf("%d\n", a);
}
