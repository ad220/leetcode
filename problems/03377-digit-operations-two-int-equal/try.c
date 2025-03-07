unsigned char exploreArray[10000] = {0};
unsigned int weightArray[10000] = {0};

char isPrime(int n) {
    if (exploreArray[n]&1) {
        return exploreArray[n]&3==3;
    } else {
        if (n%2==0){
            exploreArray[n]|=1;
            return 0;
        } 
        for (int i=3; i<=n/3; i++) {
            if (n%i==0) {
                exploreArray[n]|=1;
                return 0;
            }
        }
        exploreArray[n]|=3;
        return 1;
    }
}

int minOperations(int n, int m) {
    if (isPrime(n) || isPrime(m)) {
        return -1;
    }

    char best_op = 0;
    unsigned int min_weight;
    unsigned int current_weight = n;
    weightArray[n] = n;
    exploreArray[n] |= 4;
    while (n!=m) {
        min_weight = -1;

        for (char op)




        if (n/1000 && !isPrime(n-1000)) {
            if (current_weight+n-1000<weightArray[n-1000]) {
                weightArray[n-1000]=current_weight+n-1000;
                if (weightArray[n-1000]<min_weight) {
                    best_op=1;
                    min_weight = weightArray[n-1000];
                }
            }
        }
        
        if (n<9000 && !isPrime(n+9000)) {
            if (current_weight+n-1000<weightArray[n-1000]) {
                weightArray[n-1000]=current_weight+n-1000;
            }
            if (weightArray[n-1000]<min_weight) {
                best_op=1;
                min_weight = weightArray[n-1000];
            }
        }
    }
    return 0;
}