// 207404997 329056683
# include "NumClass.h"

int length(int n){
    if(n == 0) return 1;
    int ans = 0;
    while(n != 0){
        ans++;
        n /= 10;
    }
    return ans;
}

int power(int n, int p){
    if(p < 1) return 1;
    int ans = n;
    int i = 1;
    for(i=1; i<p; i++){
        ans *= n;
    }
    return n;
}

int isArmstrong(int n){
    if(n < 0) return -1;
    int p = length(n), sum = 0, t = n, digit;
    while(t != 0){
        digit = t%10;
        sum += power(digit, p);
        t /= 10;
    }
    if(sum == n) return true;
    return false;
}

int isPalindrome(int n){
    if(n < 0) return -1;
    int len = length(n), digit;
    int number[len], reverse[len];
    int i = 0;
    for(i=0; i<len; i++){
        digit = n%10;
        number[i] = digit;
        reverse[len-i-1] = digit;
        n /= 10;
    }
    int j = 0;
    for(j=0; j<len; j++){
        if(number[j] != reverse[j]) return false;
    }
    return true;
}
