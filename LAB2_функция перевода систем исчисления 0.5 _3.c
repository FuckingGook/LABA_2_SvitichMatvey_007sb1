#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void power(int number, int source, int target);

int main()
{
  int number, source, target;
  printf("enter numbers ( number, current notation, total notation ) : ");
  scanf("%d%d%d", &number, &source, &target );
  power(number, source, target);
  getchar(); 
  getchar();
  
  return 0;
}

void power(int number, int source, int target)
{     
  if( source <= 10  && target < 10 )
  {
    int array[100];
    int score = number;
    int res = 0;
    int i = 0;
    while( score > 0 )// разложение по разрядам 
    { 
      array[i] = number / (pow (10, i) );
      array[i] = array[i] % 10;
      i++;
      score = score / 10;                         
    }
    int j = 0;
    while( j != i )// перевод в ведённую систему исчисления 
    {
      res += array[j] * (pow (source, j) );   
      j++;
    }
    i = 0, score = res;
    int res_char; 
    while( score > 0 )// разложение по разрядам 
    { 
      res_char = res % target;
      res= res / target;     
      i++;
      array[i] = res_char;
      score = score / target;
    }
    while( i > 0 )
    {
      printf("%d", array[i]);
      i--;
    }                    
  }
  else if( source == 0 || source == 1 || target == 0 || target == 1 )
  {
    printf("0");
     
  }
  else if( target >= 10 && source >= 2 )// перевод из любой в любую систему содержащую символьные значения
  {
    int  array[100], score = number;
    int res = 0;
    int i = 0;
    while( score > 0 )// разложение по разрядам 
    { 
      array[i] = number / (pow (10, i) );           
      array[i] = array[i] % 10;            
      i++;
      score = score / 10;                       
    }
    int j = 0;
    while( j != i )// перевод в ведённую систему исчисления 
    {
      res += array[j] * (pow (source, j) );   
      j++;    
    }        
    if( target > 10 )
    {   
      char array_char[ i + 1 ];
      char res_char = 0;
      j = 0;
      if( i <= 1)
      {
        while( j != i )
        {
          array_char[j] = (char) array[j];   
          if( array_char[j] < 10 )
          {
            res_char += ( array_char[j] + 48 )* (pow (source, j ));   
          }
          else
          {
            char ch = (char) array_char[j];
            res_char += ( ch + 55 ) * (pow (source, j )) ;
          }
          j++;
        }
        printf("%c", res_char);     
      }
      else
      {   
        char array_char[100] ;
        int score = res;        
        int i = 0, res_char;
        while( score > 0 )
        {  
          res_char = res / target;              
          res_char = res % target;
          res = res / target;
          array_char[i] = (char) res_char;
          score = score / target;
          i++;                              
        }
        i -= 1;
        while( i >= 0 )
        {
          if( array_char[i] < 10 )
          {
            printf("%c", array_char[i] + 48);
          }
          else
          {
            printf("%c", array_char[i] + 55);
          }
          i--;
        }
      }           
    }
    else
    {
      printf("%d\n", res);    
    }
  }
}
