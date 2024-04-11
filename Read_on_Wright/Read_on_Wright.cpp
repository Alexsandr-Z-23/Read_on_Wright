#include <iostream>
#include<fstream>
#include<vector>
#include<iomanip>
using namespace std;

class Person
{
public:
	Person(string name, unsigned age) :name{ name }, age{ age } {};
	
	string getName()const { return name; }
	unsigned getAge() const { return age; }

	void setName(string person_name) { name = person_name; }
	void setAge(unsigned person_age) { age = person_age; }
private:
	string name;
	unsigned age;

};

ostream& operator<<(ostream& os, const Person& person)
{
	return os<<"\n"<< setw(15) << person.getName() <<  setw(30) << person.getAge();
}
istream& operator>>(istream& in,  Person& person)
{
	string name;
	unsigned age;
	in >> name  >> age;
	if (in)
	{	
		person.setName(name);
		person.setAge(age);
	}
	return in;
}


int main()
{
	setlocale(LC_ALL, "ru");
	vector<Person> people =
	{
		Person{"Tom",23},
		Person{"Bob",29},
		Person{"Ani",20},
		Person{"Tim",35},
		Person{"Anjelina",26}

	};

	ofstream out("people.txt");
	if (out.is_open())
	{
		for (const Person& person : people)
		{
			out << person << endl;
		}

	}
	out.close();
	vector<Person> new_people;
	ifstream in("people.txt");
	if (in.is_open())
	{
		Person person{ "",0 };
		while (in>>person)
		{
			new_people.push_back(person);
		}
	}
	in.close();

	cout << " NEW Список наших сотрудников : \n";
	for (const Person& person : new_people)
	{
		cout << person << endl;
	}
	cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ \n";

	cout << " Список наших сотрудников : \n";
	for  (const Person& person:people)
	{
		cout << person << endl;
	}

	cin.get();
}

