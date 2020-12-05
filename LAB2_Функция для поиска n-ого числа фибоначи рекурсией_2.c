#include <stdio.h>

long long get_fibbonachi_via_recursion(int number);

int main()
{
  int N;
  printf("what Fibbonacci number to output :");
  scanf("%d", &N);  
  printf("%lld ", get_fibbonachi_via_recursion(N) );
  getchar(); 
  getchar();

  return 0;
}

long long get_fibbonachi_via_recursion(int number) 
{
  if( number == 0 )
  {

    return 0;
  }
  if ( number == 1 || number == 2 )
  {

    return 1;
  }

  static long long array[] = {1, 1};
  if( array[number] == 0 )
  {
    array[number] = get_fibbonachi_via_recursion(number - 1) + get_fibbonachi_via_recursion(number - 2); 
  }
	
  return array[number];
}
