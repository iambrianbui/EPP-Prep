#ifndef QUEUE
#define QUEUE

#include<iostream>
#include<string>
#include<fstream>
using namespace std;

class QUEUE_LIST {
private:
	struct patient {
		int id;
		string firstname;
		string lastname;
		int age;
		string email;
		patient *next;
	};

	patient *front;    //  front of the list
	patient *rear;  //  back of the list

public:
	QUEUE_LIST();  //  constructor to default front and rear
	~QUEUE_LIST();  //  destructor to clean up 
	bool queueEmpty();  //  is the queue empty?
	void pushQueue(int, string, string, int, string);  //  push the queue
	void moveQueue();  //  move along
	void displayQueue();  //  display the queue
	void write(string);
	bool retrieve(int);
	void del(int);

	string getFirst(int);
	string getLast(int);
	int getAge(int);
	string getEmail(int);


};

QUEUE_LIST::QUEUE_LIST() {
	front = NULL; rear = NULL;
}

QUEUE_LIST::~QUEUE_LIST() {
	patient *p;
	while (front != NULL) {
		p = front;
		front = front->next;
		delete p;
	}
	rear = NULL;
}

bool QUEUE_LIST::queueEmpty() {
	return (front == NULL);
}

void QUEUE_LIST::pushQueue(int i, string f, string l, int a, string e) {
	//  create a new patient
	patient *r = new patient;
	r->id = i;
	r->firstname = f;
	r->lastname = l;
	r->age = a;
	r->email = e;
	r->next = NULL;

	//  if it's the first
	if (front == NULL) {
		front = r;
		rear = r;
	}

	//else
	else {
		rear->next = r;
		rear = r;
		rear->next = NULL;
	}
}

void QUEUE_LIST::moveQueue() {
	//  empty
	if (queueEmpty() == true) {
		cout << "There are no more patients on this list" << endl;
	}
	//move
	else {
		patient *p = front;
		front = front->next;
		cout << p->id << "\t " << p->lastname << ", " << p->firstname << "\t" << p->age << "\t" << p->email << endl;
		cout << "The doctor will now see you." << endl;
		delete p;
	}

}

void QUEUE_LIST::displayQueue() {
	patient *p = front;
	while (p != NULL) {
		cout << p->id << "\t " << p->lastname << ", " << p->firstname << "\t" << p->age << "\t" << p->email << endl;
		p = p->next;
	}
}

bool QUEUE_LIST::retrieve(int x) {
	patient *p = front;
	while (p->id != x && p != NULL) {
		p = p->next;
	}
	if (p == NULL) {
		return false;
	}
	else
		return true;
}

void QUEUE_LIST::write(string file) {
	fstream f;
	f.open(file, ios::out);
	patient *p = front;
	while (p!=NULL) {
		f << p->id << "\t" << p->firstname << "\t" << p->lastname << "\t" << p->age << "\t" << p->email << endl;
		p = p->next;
	}
	f.clear();
	f.close();
}

void QUEUE_LIST::del(int x) {
	patient *p = front;
	patient *q = front;
	while (p->id != x && p != NULL) {
		q = p;
		p = p->next;
	}
	if (p == NULL) {
		cout << "Patient not found." << endl;
	}
	if (p == front) {
		front = NULL;
		delete p;
	}
	else {
		q->next = p->next;
		delete p;
		cout << "Patient removed from our databases." << endl;
	}
}

string QUEUE_LIST::getFirst(int x) {
	patient *p = front;
	while (p->id != x && p != NULL) {
		p = p->next;
	}
	return p->firstname;
}

string QUEUE_LIST::getLast(int x) {
	patient *p = front;
	while (p->id != x && p != NULL) {
		p = p->next;
	}
	return p->lastname;
}

int QUEUE_LIST::getAge(int x) {
	patient *p = front;
	while (p->id != x && p != NULL) {
		p = p->next;
	}
	return p->age;
}

string QUEUE_LIST::getEmail(int x) {
	patient *p = front;
	while (p->id != x && p != NULL) {
		p = p->next;
	}
	return p->email;
}
#endif
