/*
  Exercicio http://br.spoj.pl/problems/BALDES/
  by Vinicius Moises de Oliveira - FATEC - Carapicuiba
  vinicius.moises.oliveira@gmail.com
*/

#include <stdio.h>
 
using namespace std;

long long  total_changes = 0;

void merge(int*,int*,int,int,int);
void mergesort(int *a, int*b, int low, int high)
{
    int pivot;
    if(low<high)
    {
        pivot=(low+high)/2;
        mergesort(a,b,low,pivot);
        mergesort(a,b,pivot+1,high);
        merge(a,b,low,pivot,high);
    }
}
void merge(int *a, int *b, int low, int pivot, int high)
{
    int h,i,j,k;
    h=low;
    i=low;
    j=pivot+1;
 
    while((h<=pivot)&&(j<=high))
    {
        if(a[h]< a[j]){
            b[i]=a[h];
            h++;
        }else{
            b[i]=a[j];
            total_changes+= j - i;
            j++;
        }
        i++;
    }
    if(h>pivot){
        for(k=j; k<=high; k++){
            b[i]=a[k];
            i++;
        }
    }else{
        for(k=h; k<=pivot; k++){
            b[i]=a[k];
            i++;
        }
    }
    for(k=low; k<=high; k++) a[k]=b[k];
}
 
int main(){
   int n;
   while (1){
      scanf ("%d",&n);  
      if (n == 0) break;
      int a[n];
      int b[n];
      for (int i = 0; i < n; i++){
          scanf ("%d",&a[i]);
      }
      mergesort(a,b,0,n-1);
      printf ("%s\n",(total_changes % 2 == 1) ? "Marcelo" : "Carlos");
      total_changes =0;
   }
}
