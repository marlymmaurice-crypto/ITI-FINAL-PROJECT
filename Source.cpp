#include<iostream>
#include <queue>
#include <stack>
#include <vector>
#include <string>
using namespace std;
void Menu() {
	cout << "----Adventure Task Manager----" << endl;
	cout << "1- View pending tasks" << endl;
	cout << "2- Add a new task" << endl;
	cout << "3- Complete next task" << endl;
	cout << "4- Undo last completed task" << endl;
	cout << "5- Show completed tasks" << endl;
}
void viewtasks(queue<string> tasks) {
	cout << "Pending tasks:" << endl;
	if (tasks.empty()) {
		cout << "You have completed all tasks" << endl;
	}
	while (!tasks.empty()) {
		cout << tasks.front() << endl;
		tasks.pop();
	}
}
void addtask(queue<string>& tasks) {
	cin.ignore();
	string newtask;
	cout << "Enter new task:";
	getline(cin, newtask);
	tasks.push(newtask);
}
void completetask(queue<string>& tasks, vector<string>& donetasks, stack<string>& memory) {
	if (!tasks.empty())
	{
		string made = tasks.front();
		tasks.pop();
		donetasks.push_back(made);
		memory.push(made);
		cout << "You have completed " << made << " task " << endl;
	}
	else {
		cout << "No tasks to complete" << endl;
	}
}
void undotask(queue<string>& tasks, vector<string>& donetasks, stack<string>& memory) {
	if (!memory.empty()) {
		string undo = memory.top();
		memory.pop();
		donetasks.pop_back();
		tasks.push(undo);
		cout << "Task " << undo << " had been undo" << endl;
	}
	else {
		cout << "No tasks in memory" << endl;
	}
}
void showCompletedtasks(vector<string>& donetasks) {
	if (!donetasks.empty()) {
		cout << "---Completed tasks---" << endl;
		for (int i = 0;i < donetasks.size();i++)
		{
			cout << i + 1 << "-" << donetasks[i] << endl;
		}
	}
	else {
		cout << "No completed tasks" << endl;
	}

}


int main()
{
	queue<string> tasks;
	vector<string> donetasks;
	stack<string> memory;

	string Tasks[5] = { "Find the Hidden Treasure","Defeat the Fire Dragon","Collect 10 Healing Herbs","Explore the Dark Cave",
	 "Build a Wooden Bridge" };

	for (int i = 0; i < 5; i++) {
		tasks.push(Tasks[i]);
	}

	int choice;
	char answer;
	do {
		Menu();
		cout << "Choice:";
		cin >> choice;

		switch (choice) {
		case 1: viewtasks(tasks); break;
		case 2: addtask(tasks); break;
		case 3: completetask(tasks, donetasks, memory); break;
		case 4: undotask(tasks, donetasks, memory); break;
		case 5: showCompletedtasks(donetasks); break;
		}
		cout << "Do you want to continue? (y,n)";
		cin >> answer;
	} while (answer == 'Y' || answer == 'y');
	return 0;
}

//some tasks you can add:
//Deliver a Message to the King
//Catch the Thief in the Market
//Train with the Master Warrior
//Defend the Village from Bandits