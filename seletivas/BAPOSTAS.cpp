/* 
   Exercicio http://br.spoj.pl/problems/BAPOSTAS/
   by Vinicius Moises de Oliveira - FATEC - Carapicuiba
   vinicius.moises.oliveira@gmail.com
   
*/

#include <stdio.h>

int main (){
   int n;
   int maximo = -1;
   int atual = 0;
   int in = 0;
   int i = 0;
   
   while (1){
      scanf ("%d",&n);
      if (n == 0) break;
      for (i = 0; i < n; i++){
            scanf ("%d",&in);
            atual += in;
      	    if (atual > maximo){
          		maximo = atual;
      	    }else if (atual < 0){
          	   atual = 0;
           }
      }
      if (maximo > 0){
         printf ("The maximum winning streak is %d.\n",maximo);
      }else{
         printf ("Losing streak.\n");
      }
      maximo = -1;
      atual = 0;
   }
   return 0;
}
