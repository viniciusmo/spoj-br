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
int memorization_result[10000];


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

void init_memorization_result(){
   for (int i = 0; i < 10000+1;i++){
       memorization_result[i] = -1;
   }
}

int compare (Task * t1 , Task * t2){
   return t1->finish_time_minute < t2->finish_time_minute;	
}

int find_largest_index_smaller_by(vector<Task*> tasks , Task * task , int index_task){

	for (int i = index_task ; i >=0 ; i--){
		Task * atual_task =  tasks[i];
		if (atual_task->finish_time_minute <= task->start_time_minute){

		    return i;
		}	
	}
    return -1;
}



int maximum_points_tasks (vector<Task *> tasks , int j){
    
    if (j == -1 ){
		return 0;
	} else{
	    int pj = find_largest_index_smaller_by (tasks,tasks[j],j);
		return max(tasks[j]->point + maximum_points_tasks(tasks,pj),maximum_points_tasks(tasks,j-1));
	}
}

int maximum_points_tasks_faster (vector<Task *> tasks , int j){
   
    if (j == -1){
       return 0;
    }else if (memorization_result[j] != -1){
   	   return memorization_result[j];
    }else {
       int pj = find_largest_index_smaller_by (tasks,tasks[j],j);
       memorization_result[j] = max(tasks[j]->point + maximum_points_tasks_faster(tasks,pj),maximum_points_tasks_faster(tasks,j-1));
       return memorization_result[j];
    }

}




int main (){
	int n;
    int result[5];
    int total = 0;
	while (1){ 
	
		 scanf ("%d",&n);
		 if (n == 0) break;
		 init_tasks_with_days_of_week();
		 init_memorization_result();
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
		 	  result[i] = maximum_points_tasks_faster(vec,vec.size()-1);	
		 	  total += result[i];	 	
		 	  init_memorization_result();
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
