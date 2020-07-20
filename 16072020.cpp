// поліморфізм
#include <iostream>
using namespace std;

class Human {
private:
	char* pib;
	int age;
public:
	Human(const char* pib1, int age1) {
		pib = _strdup(pib1);
		age = age1;
	}
	virtual void Show() {
		cout << "PIB: " << pib << endl;
		cout << "Age: " << age << endl;
	}
	virtual	~Human() {
		delete[]pib;
		cout << "delete Human" << endl;
	}
	virtual void Test(int x) {

		cout << x << endl;
	}
};

class Worker :public Human {
private:
	char* job;
	double salary;
public:
	Worker(const char* pib1, int age1, const char* job1, double salary1) :Human(pib1, age1) {
		job = _strdup(job1);
		salary = salary1;
	}
	void Show() {
		Human::Show();
		cout << "Job: " << job << endl;
		cout << "Salary: " << salary << endl;
	}
	~Worker() {
		delete[]job;
		cout << "delete Worker" << endl;
	}
};

class Student :public Human {
private:
	char* univer;
	double avg;
public:
	Student(const char* pib1, int age1, const char* univer1, double avg1) :Human(pib1, age1) {
		univer = _strdup(univer1);
		avg = avg1;
	}
	void Show() {
		Human::Show();
		cout << "University: " << univer << endl;
		cout << "Avg: " << avg << endl;
	}
	~Student() {
		delete[]univer;
		cout << "delete Student" << endl;
	}
	void Test(int x) override {

		cout << x * 2 << endl;
	}
};

class Teacher :public Human {
private:
	char* subject;
	double exp;
public:
	Teacher(const char* pib1, int age1, const char* subject1, double exp1) :Human(pib1, age1) {
		subject = _strdup(subject1);
		exp = exp1;
	}
	void Show() {
		Human::Show();
		cout << "Subject: " << subject << endl;
		cout << "Exp: " << exp << endl;
	}
	~Teacher() {
		delete[]subject;
		cout << "delete Teacher" << endl;
	}
};

int main() {
	Human* pH, H("Ivan", 20);
	H.Show();
	pH = &H;
	pH->Show();
	cout << "--------------------------------\n";
	Student* pS, st("Ira", 18, "ITStep", 11.5);
	st.Show();
	pS = &st;
	pS->Show();
	cout << "--------------------------------\n";
	pH = &st;
	//((Student*)pH)->Show(); // приведення типу
	//pH->Show();
	pH->Test(5);

	{
		Human* h = new Student("Ira", 22, "IT", 10);
		h->Show();
		delete h;
	}

	/*Human Hmn("Ivan",30);
	Worker Wrkr("Petrov", 25, "Slesar", 10000);
	Student St("2", 2, "2", 2);
	Teacher C("3", 3, "3", 3);
	cout << "--------------------------------\n";
	Wrkr.Show();
	cout << "--------------------------------\n";
	St.Show();
	cout << "--------------------------------\n";
	C.Show();*/
}