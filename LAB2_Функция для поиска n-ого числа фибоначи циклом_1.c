#include <stdio.h>

long get_fibbonachi_via_cycle(int number);

int main()
{
  int fib_num;
  printf("what Fibbonacci number to output: ");
  scanf("%d", &fib_num);
  printf( "%ld", get_fibbonachi_via_cycle(fib_num) );
  getchar(); 
  getchar();
  
  return 0;
}

long get_fibbonachi_via_cycle(int number)
{
  long fib1 = 1, fib2 = 0, fib3 = 0 ;
  for(int i = 1; i <= number; i++)
  {
    fib3 = fib1 + fib2;
    fib1 = fib2;
    fib2 = fib3; 
  }
  
  return fib3;
}
