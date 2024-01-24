#include <iostream>
#include <stdio.h>
using namespace std;


int main(){
    int a;
    int b;
    int n[50];
    int m[50];
    int merge[50];
    int i, j;
    int sum;
    printf("Enter the size of first array: \n");
    scanf("%d",&a);
    for(int i=0;i<a;i++){
        scanf("%d",&n[i]);
    }
    printf("Enter the size of second array: \n");
    scanf("%d",&b);
    for(int i=0;i<b;i++){
        scanf("%d",&m[i]);
    }
    sum = a+b;
    j = 0;
    for(int i=0; i<sum;i++){
        if(i<a){
            merge[i] = n[i];
            

        }
        else if(i>=a){
            merge[i] = m[j];
            j++;
        }
    }
    
    for(int i=0; i<sum;i++){
        printf("%d  ",merge[i]);
    }

}