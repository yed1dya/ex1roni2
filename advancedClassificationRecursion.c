// 207404997
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
        return true;
    }
    return false;
}

int reverse(int n){
    if(n>-10 && n<10) return n;
    int len = length(n);
    return (n%10)*power(10, len-1) + reverse(n/10);
}
int isPalindromeHelp(int a, int b){
    if(a>-10 && a<10 && b>-10 && b<10) return true;
    int check = false;
    if(a%10 == b%10) check = true;
    return check * isPalindromeHelp(a/10, b/10);
}
int isPalindrome(int n){
    if(n>-10 && n<10) return true;
    return isPalindromeHelp(n, reverse(n));
}
