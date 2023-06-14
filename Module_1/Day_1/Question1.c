#include<stdio.h>

int biggest_num(int a, int b);                                      // function prototype

int main(){
    int number1,number2;

    printf("Enter a Number1 : \n");
    scanf("%d",&number1);

    printf("Enter a Number2 : \n");
    scanf("%d",&number2);

    biggest_num(number1,number2);                                   // Function Call

    return 0;
}

int biggest_num(int a, int b)                                       // function definition 
{

    // if...else Statement
    if(a>b){

        printf("%d is Biggest number.",a);

    }else{

        printf("%d is Biggest number.",b);

    }

    //ternary operator

   // (a>b) ?  printf("%d is Biggest number.",a):printf("%d is Biggest number.",b);


}