#include <stdio.h>
#include "NumClass.h"
int main(){
    int a;
    int b;
    scanf("%d",&a);
    scanf("%d",&b);
    if(a > b){
        int t = a;
        a = b;
        b = t;
    }
    printf("The Armstrong numbers are:");
    int i = a;
    for(i=a; i<=b; i++){
           if(isArmstrong(i) == 1){
            printf(" %d",i);
        }
    }
    printf("\n");
    printf("The Palindromes are:");
    i = a;
    for(i=a; i<=b; i++){
           if(isPalindrome(i) == 1){
            printf(" %d",i);
        }
    }
    printf("\n");
    printf("The Prime numbers are:");
    if(a == 0){ a = 1; }
    i = a;
    for(i=a; i <= b; i++){
           if(isPrime(i) == 1){
            printf(" %d",i);
        }
    }
    printf("\n");
    printf("The Strong numbers are:");
    i = a;
    for(i=a; i <= b; i++){
        if(isStrong(i)){
            printf(" %d",i);
        }
    }
    printf("\n");
}
