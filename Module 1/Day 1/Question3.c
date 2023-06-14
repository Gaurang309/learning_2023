#include <stdio.h>

int main() {

  int roll_no;
  char name[100];
  int physics_marks, math_marks, chemistry_marks;
  int total_marks;
  float percentage;

  printf("Enter the roll no: ");
  scanf("%d", &roll_no);

  printf("Enter the name: ");
  scanf("%s", name);

  printf("Enter the marks of physics: ");
  scanf("%d", &physics_marks);

  printf("Enter the marks of math: ");
  scanf("%d", &math_marks);

  printf("Enter the marks of chemistry: ");
  scanf("%d", &chemistry_marks);

  total_marks = physics_marks + math_marks + chemistry_marks;

  percentage = (total_marks / (300.0) )* 100;

  printf("\nRoll No: %d\n", roll_no);
  printf("Name: %s\n", name);
  printf("Marks in Physics: %d\n", physics_marks);
  printf("Marks in Math: %d\n", math_marks);
  printf("Marks in Chemistry: %d\n", chemistry_marks);
  printf("Total Marks: %d\n", total_marks);
  printf("Percentage: %.2f%%\n", percentage);

  return 0;
}