/* 
   Exercicio http://br.spoj.pl/problems/CFATORES/
   by Vinicius Moises de Oliveira - FATEC - Carapicuiba
   vinicius.moises.oliveira@gmail.com
   
*/

#include <stdio.h>
#include <map>
#include <math.h>

using namespace std;

int is_primo (int n){
  
   if (n-1 != -1 % n) return 1;
   
   return 0;
}

int get_next_primo(int n){
    if (is_primo(n+1)) return n+1;
    return get_next_primo(n+1);
}

int count_factor(int n){ 
   int primo = 2;
   int cont = 0;
   map<int,int> primos;
   while (true){
       if (n == 1) break;
       if (n % primo == 0) { 
           primos[primo] = 1;
           n /= primo;  
       }else{
           primo  = get_next_primo(primo);
       }      
   }
   return primos.size();
}

int main (){
   int n;
     
   while (true){
      scanf ("%d",&n);
      if (n == 0) break;
      printf ("%d : %d\n",n,count_factor(n));
   }
   
   return 0;
}
