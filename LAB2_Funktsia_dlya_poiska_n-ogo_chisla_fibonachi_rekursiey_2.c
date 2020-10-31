#include <stdio.h>

long get_fibbonachi_via_recursion(int number)
{
  if (number == 1 || number == 2)
  {
    return 1;
  } 
  return get_fibbonachi_via_recursion(number - 1) + get_fibbonachi_via_recursion(number - 2); 
}

int main()
{
  int N;
  printf("какое число Фиббоначи вывести :");
  scanf("%d", &N);  
  printf("%ld ", get_fibbonachi_via_recursion(N));
  getchar(); getchar(); 
  return 0;
}
