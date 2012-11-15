/* 
   Exercicio http://br.spoj.pl/submit/F91/
   by Vinicius Moises de Oliveira - FATEC - Carapicuiba
   vinicius.moises.oliveira@gmail.com
   
*/

#include <stdio.h>


int f91 (int n){
   if ( n <= 100) f91 (f91 (n + 11));
   else if (n >=101) return n -10;
}

int main (){
  
   int n; 
   
   while (1){
      scanf ("%d",&n);
      if (n == 0) break;
      printf ("f91(%d) = %d\n",n,f91(n));
   }

  return 0;
}
