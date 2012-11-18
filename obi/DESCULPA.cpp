/* 
   Exercicio http://br.spoj.pl/problems/DESCULPA/
   by Vinicius Moises de Oliveira - FATEC - Carapicuiba
   vinicius.moises.oliveira@gmail.com
   
*/

#include <stdio.h>
int max (int i, int j){
   if (i > j) return i;
   return j;
}


int knap_sack(int W, int wt[], int val[], int n)
{
   int i, w;
   int K[n+1][W+1];
 
   for (i = 0; i <= n; i++)
   {
       for (w = 0; w <= W; w++)
       {
           if (i==0 || w==0)
               K[i][w] = 0;
           else if (wt[i-1] <= w)
                 K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]],  K[i-1][w]);
           else
                 K[i][w] = K[i-1][w];
       }
   }
 
   return K[n][W];
}

int main (){
   
   int  tamanho_cartao = 0;
   int  total_frase = 0;
   int  val[1000];
   int  wt[1000];
   int teste = 1;
   
   while (1){
       scanf ("%d",&tamanho_cartao);
       scanf ("%d",&total_frase);
       if (tamanho_cartao == 0 || total_frase == 0) break;
       for (int i = 0; i < total_frase; i++){
            scanf ("%d%d",&wt[i],&val[i]);
       }     
       printf("Teste %d\n%d\n\n",teste++, knap_sack(tamanho_cartao, wt, val, total_frase));
      
   }
   return 0;
}
