#include<stdio.h>

int mygrade(int marks)
{
    if((marks>=90) && (marks<=100)){

        printf("\nYour Grade is A.");

    }else if((marks>=75) && (marks<=89)){

        printf("\nYour Grade is B.");

    }else if((marks>=60) && (marks<=74)){

        printf("\nYour Grade is C.");

    }else if((marks>=50) && (marks<=59)){

        printf("\nYour Grade is D.");

    }else if((marks>=0) && (marks<=49)){

        printf("\nYour Grade is F.");

    }else{

        printf("Enter a valid number!!!");

    }


}

int main(){

    int num;

    printf("Enter Your Percentage : ");
    scanf("%d",&num);

    mygrade(num);

    return 0;
}