// Write a program that input 10 values in an Array using USER DEFINE FUNCTION "in_array" 
// also write a USER DEFINE FUNCTION "out_array" to print all values in reverse order.

#include <stdio.h>

void inArray(int arr[]){
    printf("Enter 10 values - \n");
    for(int i = 0; i<10; i++){
        scanf("%d",&arr[i]);
    }
}

void outArray(int arr[]){
    printf("Values of array in reverse order - \n");
    for(int i = 9; i>0; i--){
        printf("%d\n",arr[i]);
    }
}

int main(){
    int arr[10];
    inArray(arr);
    outArray(arr);
    return 0;
}