
#define SIEVE 1000005
bool arrPrime[SIEVE] = {1};
void sieve(){
    int i,j, root = sqrt(SIEVE);
    for(i=0;i<SIEVE;i++){
        arrPrime[i] = 1;
    }
    for(i=2;i<=root;i++){
        if(arrPrime[i] == 1){
            for(j=2;i*j<=SIEVE;j++){
                arrPrime[i*j] = 0;
            }
        }
    }
}
