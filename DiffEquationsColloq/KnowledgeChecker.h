#include <vector>
#include <string>
//#include <ncurses.h>
#include <iostream>
//#include <conio.h>
//#include <Windows.h>
#include <time.h>
#include <random>

using namespace std;

#ifndef KNOWLEDGECHECKER
#define KNOWLEDGECHECKER

class qaa{
	public:
	string question;
	string answer;
	bool used;
};

class Knowledgechecker{
	string name_of_subject;
	qaa* mass;
	int _size;
	public:
	Knowledgechecker(string name): name_of_subject(name), _size(0){
		mass = new qaa[100];
	}
	void Add(string q, string a, bool u){
		mass[_size].question = q;
		mass[_size].answer = a;
		mass[_size].used = u;
		_size++;
	}
	void Check(int first, int last){
		srand(time(NULL));
		while(true)
		{
			CheckQuestion(first + rand() % (last - first));
		}	
		//for(int i = first; i <= last; i++)
			//CheckQuestion(i);
	}
	void CheckQuestion(int n){
		if(mass[n].used){
			cout << "----QUESTION " << n << ":  "<<mass[n].question << '\n';
			char m;
		//	initscr();
    		//	cbreak();
    		//	noecho();
    		//	scrollok(stdscr, TRUE);
    		//	nodelay(stdscr, TRUE);
			//if( kbhit() ){
			//if (getch() == 'g') {
				cin >> m;
				cout << '\n'<< "----ANSWER " << mass[n].answer << '\n' << '\n';
			//}
		}
	}
};

#endif
