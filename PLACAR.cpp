/* 
   Exercicio http://br.spoj.pl/problems/PLACAR/
   by Vinicius Moises de Oliveira - FATEC - Carapicuiba
   vinicius.moises.oliveira@gmail.com
   
*/


#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string.h>



using namespace std;

class Aluno{
  public:
  char nome[100];
  int nota;
};

int compare(const void * s1, const void * s2){
  Aluno *  a1 = (Aluno *)s1;
  Aluno *  a2 = (Aluno *)s2;
  
  if (a1->nota < a2->nota){ 
     return 1;
  }else if (strcmp(a1->nome,a2->nome) > 0  && a1->nota == a2->nota) {
     return 1;
  }
  return 0;
  
}






int main (){
  int n;
  vector <Aluno *> alunos;
  int instancia = 1;
   while (scanf ("%d",&n) != EOF){
        for (int i = 0; i < n;i++){
   		  Aluno * aluno  = new Aluno();
   		  scanf (" %s",aluno->nome);
   		  scanf (" %d",&aluno->nota);
   	      alunos.push_back(aluno);
   	    }
   	    
   	    sort(alunos.begin(), alunos.end(), compare);
   	    Aluno * aluno = alunos[0];
   	    printf ("Instancia %d\n",instancia++);
   	    printf ("%s\n\n",aluno->nome);
   	    alunos.clear();  
   }
   
  return 0;
}
