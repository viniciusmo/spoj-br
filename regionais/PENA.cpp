/*
  Exercicio http://br.spoj.pl/problems/PENA/
  by Vinicius Moises de Oliveira - FATEC - Carapicuiba
  vinicius.moises.oliveira@gmail.com
*/

#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string.h>
#include <string>
#include <map>

using namespace std;


class Task{

  public :
   int id;
   int point;
   char  day_of_week[100];
   int start_time_minute;
   int finish_time_minute;

  
};

map < string , vector < Task * > > tasks;
char DAYS_OF_WEEK [][5] = {"Seg", "Ter", "Qua" , "Qui", "Sex"};
int TOTAL_DAYS_OF_WEEK = 5;

int convert_time_day_to_int (char  time_of_day [] ){
	 char  copy_time_of_day [100];
	 strcpy(copy_time_of_day,time_of_day);
	 char * time_of_day_split;
	 int result_convert_time;

	 time_of_day_split = strtok (copy_time_of_day,":");
     result_convert_time = atoi(time_of_day_split) * 60;
     time_of_day_split = strtok(NULL,":");
     result_convert_time += atoi (time_of_day_split);
     return result_convert_time;
}

void init_tasks_with_days_of_week(){
	for (int i = 0; i < TOTAL_DAYS_OF_WEEK; i++){
		vector <Task*> vec;
        tasks[DAYS_OF_WEEK [i]] = vec;
	}
}


int compare (Task * t1 , Task * t2){
   return t1->finish_time_minute < t2->finish_time_minute;	
}


int  search_bin (vector<Task*> tasks, Task * task , int index) {
   
   int inf = 0;
   int sup = index-1;
   int m;
   int ret = -1;
   while (inf <= sup){
   		m = (inf + sup) / 2;
   		Task * atual = tasks[m];
   		Task * next  = tasks[m+1];
   		
   		if (atual->finish_time_minute <= task->start_time_minute && next->finish_time_minute > task->start_time_minute){
   			return m;
   		} 
   		if (atual->finish_time_minute <= task->start_time_minute){
   		    ret = m;
   		    inf = m + 1;
   		}else{
   			sup = m -1;
   		}
   }
  
   return ret;
}


int maximum_points_tasks_faster (vector<Task *> tasks){

    int memorization_result[tasks.size()];
    fill_n(memorization_result, tasks.size(), 0);
    
    for (int  j = 0; j < tasks.size() ; j++){
         int pj =  search_bin (tasks,tasks[j],j);
         memorization_result[j] = max(tasks[j]->point + memorization_result[pj], memorization_result[j-1]);
    }
   
   return  memorization_result[tasks.size()-1];
}




int main (){
	int n;
    int result[5];
    int total = 0;
	while (1){ 
	
		 scanf ("%d",&n);
		 if (n == 0) break;
		 init_tasks_with_days_of_week();
		 for (int i = 0; i < n; i++){
		 	 char start_time_read[100];
		 	 char finish_time_read[100];
		 	 Task * t  = new Task();
		     scanf ("%d",&t->id);
         	 scanf ("%d",&t->point);
             scanf ("%s",t->day_of_week);
             scanf ("%s",start_time_read);
             scanf ("%s",finish_time_read);
             t->start_time_minute =  convert_time_day_to_int (start_time_read);
             t->finish_time_minute = convert_time_day_to_int (finish_time_read);
             string str(t->day_of_week);
             tasks[str].push_back(t);
		 }
		 for (int i = 0; i < TOTAL_DAYS_OF_WEEK; i++){
		 
		 	  string key(DAYS_OF_WEEK[i]);
		 	  vector<Task*> vec = tasks[key];
		 	  sort (vec.begin(),vec.end(),compare);
		 	  result[i] = maximum_points_tasks_faster(vec);	
		 	  total += result[i];	 	
				
		 }
		 printf ("Total de pontos: %d\n",total);
		 for (int i = 0;  i < TOTAL_DAYS_OF_WEEK;i++){
		    printf ("%s: %d\n",DAYS_OF_WEEK[i],result[i]);
		 }
		 total = 0;
		 tasks.clear();
	}
	return 0;
}
