// Write a program to check whether a number is perfect or not using function.

#include <stdio.h>
#include <stdlib.h>
int isPerfect(int n);
int main()
{
    int n;
    printf("Enter the number:\n");
    scanf("%d", &n);

    if(isPerfect(n)){
        printf("%d is a perfect number.", n);
    }
    else{
        printf("%d is NOT a perfect number.", n);
    }
    return 0;
}

int isPerfect(int n){
int sum=0;
for(int i=1; i<n; i++){
    if(n%i == 0){
        sum += i;
    }
    else{
        continue;
    }
}
if(sum == n)
    return 1;
else
    return 0;
}
