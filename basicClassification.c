// 207404997
# include "NumClass.h"

int sqroot(int n){
    if(n <= 0) return 0;
    int t = 1;
    while((t*t < n) && ((t+1)*(t+1) <= n)){
        t++;
    }
    return t;
}

int isPrime(int n){
    if(n < 0) return -1;
    if(n <= 3) return true;
    /* square root is an upper bound for
    the numbers to check to varify prime: */
    int sqrt_n = sqroot(n);
    int i = 2;
    for(i=2; i<=sqrt_n; i++){
        if(n%i == 0) return false;
    }
    return true;
}

int isStrong(int n){
    if(n < 0) return -1;
    /* keep array of factorials of digits - 
    to avoid repeating calculations: */
    int f[10];
    f[0] = 1;
    int i = 1;
    for(i=1; i<10; i++){
        f[i] = f[i-1]*i;
    }
    int sum = 0;
    int t = n;
    int digit;
    while(t > 0){
        digit = t%10;
        sum += f[digit];
        t /= 10;
    }
    if(sum == n) return true;
    return false;
}
