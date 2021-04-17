#include<stdio.h>
#include<string.h>
void main()
{
    char s[100];
    int n,i,j,k;
    printf("Enter the strings:");
    scanf("%100s",s);
    n=strlen(s);
    if(n%2==0)
        printf("string is even");
    else{
        printf("odd");
    }
        
    /*for(n=-1;s[n];n++){
        if(n%2==0){
            printf("string is even");
        }
        else{
            printf("not even");
        }
    }*/
        
}