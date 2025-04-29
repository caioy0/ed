#include <stdio.h>
#include <stdbool.h>

bool isPalindrome(long int x) {
    
    if (x < 0) return false;
    double revNum = 0, remain, num = x;

    while(x > 0) {
        remain = x % 10;
        revNum = revNum * 10 + remain;
        x /= 10;
    }
    return num == revNum;
}

bool isPalindrome2(long int x){
    if (x<0){
        return false;
    }else{
        double revNum = 0, remain, num = x;
        while(x > 0) {
            remain = x % 10;
            revNum = revNum * 10 + remain;
            x /= 10;
        }
        return num == revNum;
    }
}

int main() {
    long int x;
    
    printf("Enter a number: ");
    if (scanf("%ld", &x) != 1) {
        printf("Invalid input\n");
        return 1;
    }

    if (isPalindrome(x)) {
        printf("Es palindromo\n");
    } else {
        printf("No es palindromo\n");
    }
    if (isPalindrome2(x)) {
        printf("Es palindromo\n");
    } else {
        printf("No es palindromo\n");
    }
    return 0;
}