/* 
   Exercicio http://br.spoj.pl/problems/SENHA/
   by Vinicius Moises de Oliveira - FATEC - Carapicuiba
   vinicius.moises.oliveira@gmail.com
   
*/

#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int get_more_repeated_array (vector<int> arr) {
    int current_candidate = arr[0], counter = 0, i;
    for (i = 0; i < arr.size(); ++i) {
        if (current_candidate == arr[i]) {
            ++counter;
        } else if (counter == 0) {
            current_candidate = arr[i];
            ++counter;
        } else {
            --counter;
        }
    }
    return current_candidate;
}

int main (){
    
    int n;
    int mat_digit[11][11];
    char digit;
    int index;
    vector< vector<int> > digits;
    int teste = 1;
    
    for (int i = 0 ;  i < 10 ; i++){
 		vector <int>  vec;
        digits.push_back(vec);
    }
        
    while (1){
        scanf ("%d",&n);
        if (n == 0) break;
        
        for (int i = 0; i < n; i++){
             
             for (int j = 1; j < 11; j++){
                  scanf ("%d",&mat_digit[i][j]);
             }
             for (int j = 0; j < 6;j++){
                scanf (" %c",&digit);
                index = digit -'A';
                index +=1;
                digits[j].push_back( mat_digit[i][ (index*2)-1]  );
                digits[j].push_back( mat_digit[i][ index*2 ]);                       
             } 
        }
      printf ("Teste %d\n",teste++);
      for (int i = 0; i < 6; i++){
		   sort(digits[i].begin(),digits[i].end());
		   printf ("%d ",get_more_repeated_array(digits[i]));
		   digits[i].clear();
      }    
      printf ("\n\n");

      
    }
    
  return 0;
}
