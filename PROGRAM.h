#ifndef PROGRAM
#define PROGRAM

#include<iostream>
#include<string>
#include"QUEUE.h"
#include<fstream>
using namespace std;

class MAINPRO {
private:
	struct patient {
		int id;
		string firstname;
		string lastname;
		int age;
		string email;
	};
QUEUE_LIST l;  //  database, if make time make BST
QUEUE_LIST u;  //  urgent
QUEUE_LIST r;  //  regular

public:
	void import(string);
	void write(string);
	void retrieve();
	void consult();
	void find();
	void newPatient();
	void del();
};

void MAINPRO::import(string file) {
	fstream f;
	f.open(file, ios::in);
	int i;string fn; string ln; int a; string e;

	while (!f.eof()) {
		f >> i >> fn >> ln >> a >> e;
		l.pushQueue(i, fn, ln, a, e);
	}
	f.close();
}

void MAINPRO::newPatient() {
	//  id
	int id = 0;
	cout << "Please enter your insurance ID:  ";
	cin >> id;
	string first = " ";
	string last = " ";

	//  name
	cout << "Please enter your first and last name:  ";
	cin >> first >> last;
	cin.ignore();
	cin.clear();

	//  age
	int age = 0;
	cout << "Please enter your age:  ";
	cin >> age;

	//  email
	string email = " ";
	cout << "Please enter your email:  ";
	cin >> email;
	cin.ignore();
	cin.clear();

	l.pushQueue(id, first, last, age, email);

	int choice = 0;
	cout << "Do you want to be put on the:  " << endl
		<< "1.  Urgent Care Waitlist" << endl
		<< "2.  Regular Care Waitlist" << endl;
	cin >> choice;
	while (choice < 1 || choice > 2) {
		cout << "Invalid choice." << endl;
		cin >> choice;
	}
	if (choice == 1) {
		u.pushQueue(id, first, last, age, email);
	}
	if (choice == 2) {
		r.pushQueue(id, first, last, age, email);
	}

}

void MAINPRO::retrieve() {
	int id;
	cout << "Please insert the insurance ID  ";
	cin >> id;
	if (l.retrieve(id) == false) {
		cout << "Patient not found" << endl;
	} 
	else {
		string first = l.getFirst(id);
		string last =l.getLast(id);
		string email = l.getEmail(id);
		int age = l.getAge(id);
		cout << "Welcome back " << first << " " << last << "!  Which list would you like to be on?" << endl;
		int choice = 0;
		cout << "Do you want to be put on the:  " << endl
			<< "1.  Urgent Care Waitlist" << endl
			<< "2.  Regular Care Waitlist" << endl;
		cin >> choice;
		while (choice < 1 || choice > 2) {
			cout << "Invalid choice." << endl;
			cin >> choice;
		}
		if (choice == 1) {
			u.pushQueue(id, first, last, age, email);
		}
		if (choice == 2) {
			r.pushQueue(id, first, last, age, email);
		}
	}
}

void MAINPRO::find() {
	int id;
	cout << "Please insert the insurance ID  ";
	cin >> id;
	if (l.retrieve(id) == false) {
		cout << "Patient not found" << endl;
	}
	else {
		string first = l.getFirst(id);
		string last = l.getLast(id);
		string email = l.getEmail(id);
		int age = l.getAge(id);
		cout << id << "\t" << last << ", " << first << " \t" << age << "\t" << email << endl;
	}
}

void MAINPRO::consult() {
	if (u.queueEmpty() == false) {
		u.moveQueue();
	}
	else if (r.queueEmpty() == false) {
		r.moveQueue();
	}
	else cout << "Waitlists are empty." << endl;
}

void MAINPRO::del() {
	int id;
	cout << "Please insert the insurance ID  ";
	cin >> id;
}

void MAINPRO::write(string file) {
	l.displayQueue();
	l.write(file);
}


#endif
