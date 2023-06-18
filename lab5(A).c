#include <stdio.h>

long long factorial(int n) {
    if(n == 0)
        return 1;
    else
        return(n * factorial(n-1));
}

int main() {
    int num;
    printf("Input the number for factorial calculation: ");
    scanf("%d", &num);
    
    if(num < 0)
        printf("Factorial of negative numbers doesn't exist.\n");
    else {
        printf("The factorial of %d is %lld.\n", num, factorial(num));
    }

    return 0;
}

