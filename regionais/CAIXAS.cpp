/*
  Exercicio http://br.spoj.com/problems/CAIXAS/
  by Vinicius Moises de Oliveira - FATEC - Carapicuiba
  vinicius.moises.oliveira@gmail.com
*/

#include <stdio.h>
#include <vector>
#include <algorithm>


using namespace std;

vector<vector<int> >pilhas;
int pos_caixa;
int pos_col;
int total;

int get_next(int value){
   return ++value;
}

int get_back(int value){
   return --value;
}

int exists_pos (int pos){
   int size  = pilhas[pos].size();
   if (pos == 0)return 0;
   if (pos == -1) return 0;
   return -1;
}


void calculate_min_box (int pos, int (*getfunction)(int)){
    int aux;
    
    if (pos == pos_col){
       aux =  pilhas[pos].size()-(pos_caixa+1);
    }else{
       aux =  pilhas[pos].size()-pos_caixa;
       if (aux <= 0) return;
    }

    total+= aux;
    if (exists_pos(pos)){
    		int next = getfunction(pos);
    	   calculate_min_box(next,getfunction);	
    }
}


int main (){
  
  int n, p;  
  while (1){
     scanf ("%d%d",&n,&p);
     if (n == 0 && p == 0) break;
     for (int i = 0; i < p; i++){
         int n_p;
         scanf ("%d",&n_p);
         vector<int>pilha;
         
         for (int j = 0; j < n_p; j++){
              int n_read;
              scanf ("%d",&n_read);
              pilha.push_back(n_read);
              if (n_read == 1){
                 pos_caixa = j;
                 pos_col = i;
              }
         }
         pilhas.push_back(pilha);
     }
       
	  if (pos_col == 0 || pos_col == p-1){
		  total += pilhas[pos_col].size() - (pos_caixa+1);
	  }else{
		  calculate_min_box(pos_col,&get_next);
		  int next  = total;
		  total = 0;
		  calculate_min_box(pos_col,&get_back);
		  int back = total;
		  total = std::min(back,next);		  
	  }
	   printf ("%d\n",total);
	   pilhas.clear();
	   total = 0;
  }
  
  return 0;
}


