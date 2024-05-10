# include "NumClass.h"

int length(int n){
    if(n>-10 && n<10) return 1;
    return 1 + length(n/10);
}

int power(int n, int p){
    if(p < 1) return 1;
    if(p == 1) return n;
    return n*power(n, p-1);
}

int armstrongValue(int n, int p){
    if(n == 0) return 0;
    return armstrongValue(n/10, p) + power(n%10, p);
}
int isArmstrong(int n){
    if(n == armstrongValue(n, length(n))){
        return 1;
    }
    return 0;
}

int isPalindrome(int n){
    if(n>-10 && n<10) return 1;
    int MSD = n;
    int LSD = n%10;
    int sum = 0, c = 1;
    while(MSD > 9){
        sum += (MSD%10)*c;
        c*=10;
        MSD /= 10;
    }
    if(MSD != LSD) return 0;
    int checkLength;
    if((length(sum/10) == length(n)-2) || (sum/10 == 0)){
        checkLength = 1;
    }
    else{ checkLength = 0; }
    return isPalindrome(sum/10) * checkLength;
}
