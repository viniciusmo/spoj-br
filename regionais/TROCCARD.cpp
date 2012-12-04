/*
  Exercicio http://br.spoj.pl/problems/TROCCARD/
  by Vinicius Moises de Oliveira - FATEC - Carapicuiba
  vinicius.moises.oliveira@gmail.com
 
 */

#include <stdio.h>
#include <map>

using namespace std;

int main (){
   int n1;
   int n2;
   map <int,int> alice;
   map <int,int> beatriz;
   map<int, int>::iterator it;

   int quantidade1;
   int quantidade2;

   while (1){
   		scanf ("%d%d",&n1,&n2);
   		if (n1 == 0 && n2 == 0) break;
 		
 		for (int i = 0 ; i <  n1 ; i++){
 			int read;
 			scanf ("%d",&read);
 			alice[read] = read; 
 		}

 		for (int i = 0 ; i <  n2 ; i++){
 			int read;
 			scanf ("%d",&read);
 			beatriz[read] = read; 
 		}

 		for (it = alice.begin() ; it != alice.end(); it++){
 			int value  = it->first;
 			if (beatriz.find(value) == beatriz.end()){
 				quantidade1++;
 			}

 		}

 		for (it = beatriz.begin() ; it != beatriz.end(); it++){
 			int value  = it->first;
 			if (alice.find(value) == alice.end()){
 				quantidade2++;
 			}
 		}
        
        if (quantidade1 < quantidade2){
        	printf ("%d\n",quantidade1);
        }else{
        	 printf ("%d\n",quantidade2);
        }

        quantidade1 = 0;
        quantidade2 = 0;
        beatriz.clear();
        alice.clear();
   }


  return 0;	
}