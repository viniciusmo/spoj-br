/*
  Exercicio http://br.spoj.pl/problems/PENA/
  by Vinicius Moises de Oliveira - FATEC - Carapicuiba
  vinicius.moises.oliveira@gmail.com
*/
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string.h>
#include <map>

using namespace std;


class Task{

  public :
   int id;
   int point;
   int start_time_minute;
   int finish_time_minute;
   char * day_of_week;
};

/* Simulate instance variables */
map < char * , vector < Task * > > tasks;
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

int main (){
	int n;

	while (1){ 
		 scanf ("%d",&n);
		 if (n == 0) break;
		 init_tasks_with_days_of_week();
		 for (int i = 0; i < n; i++){
		 	char * start_time_read;
		 	char * finish_time_read;

		 	Task * task  = new Task();
		 	scanf ("%d",&task->id);
		 	scanf ("%d",&task->point);
		 	scanf ("%s",task->day_of_week);
		 	scanf ("%s",start_time_read);
		 	scanf  ("%s",finish_time_read);
		 	task->start_time_minute  = convert_time_day_to_int (start_time_read);
		 	task->finish_time_minute  = convert_time_day_to_int (finish_time_read);
		 	tasks[task->day_of_week].push_back(task);
		 }

		 for (int i = 0; i < TOTAL_DAYS_OF_WEEK; i++){
		 	 vector<Task *> vec = tasks[DAYS_OF_WEEK[i]];
		 	 sort(vec.begin(),vec.end(),compare);

		 }
		 tasks.clear();
	}

	return 0;
}