#include <iostream>
#include <deque>
#include <map>

using namespace std;

deque<int> commands;
deque<int> commands_history;
map<int,int> position_map;
int start_size_command_history = 0;
int total = 0;

bool read_input();
void update_total_movements_when_not_exists_in_map();
void update_total_movements_when_exists_in_map();
void update_position_command_in_map();
int count_position_command_history();
void calculate_total_movements_commands();
void clear_input();

int main (){
	while (read_input()){
		calculate_total_movements_commands();
		cout << total << endl;
		clear_input();
	}
	return 0;
}

bool read_input(){
	int n;
	cin >> n;
	for (int i = 0; i < n; i++){
		int input;
		cin >> input;
		if (input > start_size_command_history){
			start_size_command_history = input;
		}
		commands.push_front(input);
	}
	return ((n > 0) ? true : false); 
}

void update_total_movements_when_not_exists_in_map(){
	total+=commands.back()+ commands_history.size();
}

void update_total_movements_when_exists_in_map(){
	int size_total_commands_history = (commands_history.size()+start_size_command_history);
	int position_command = position_map[commands.back()];
	int result = size_total_commands_history - position_command;
	total+= result;
	total+=1;
}

void update_position_command_in_map(){
	position_map[commands.back()] = commands_history.size() + 1 + start_size_command_history;
}

int count_position_command_history(){
	if (position_map.find(commands.back()) == position_map.end()){
		update_total_movements_when_not_exists_in_map();
	}else{
		update_total_movements_when_exists_in_map();
	}
	update_position_command_in_map();
}

void calculate_total_movements_commands(){
	while (!commands.empty()){
		count_position_command_history();
		commands_history.push_back(commands.back());
		commands.pop_back();
	}
}

void clear_input(){
	total = 0;
	commands_history.clear();
	commands.clear();
	position_map.clear();
	start_size_command_history = 0;
}