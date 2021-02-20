

#include <iostream>
#include <vector> 
using namespace std;

//student class
class Student {
private:
	string name;
	string rollNo;
	int semester;
	float GPA;
public:

	Student() {
		name = "";
		rollNo = "";
		semester = 0;
		GPA = 0.0;
	}

	Student(string n, string rn, int sem, float gpa) {
		name = n;
		rollNo = rn;
		semester = sem;
		GPA =gpa;
	}

	string getName() {
		return this->name;
	}

	string getRollNo() {
		return this->rollNo;
	}

	float getGPA() {
		return this->GPA;
	}
	int getSem() {
		return this->semester;
	}


};
//convert to lower case
string GetLowerCase(string input) {
	string lower = "";

	//lower
	for (int i = 0; i < input.length(); ++i) {
		if (input[i] >= 65 && input[i] <= 90) {
			lower += input[i] + 32;
		}
		else {
			lower += input[i];
		}
	}
	return lower;
}

//find student in vector
void findStudent(vector<Student> v,string name) {
	bool found = false;

	name = GetLowerCase(name);  //convert to lower case for search

	for (int i = 0; i < v.size(); ++i) {

		string vectorName= GetLowerCase(v.at(i).getName()); //convert to lower case for search

		if (vectorName == name) {
			cout << "\nStudent found\n";

			cout << "Name : " << v.at(i).getName()<<endl;
			cout << "GPA : " << v.at(i).getGPA() << endl;
			cout << "Semester : " << v.at(i).getSem() << endl;
			cout << "Roll Number : " << v.at(i).getRollNo() << endl;

			found = true;
		}
	
	}

	if (found==false) {
		cout << "\nStudent not found\n";
	}
}



int main()
{
    
	vector<Student> stuVector;  //vector of type Student

	//initialize students

	Student s1 =  Student("Brian zaifac","160042",8,3.0);
	Student s2 = Student("Edward", "170032", 7, 2.35);
	Student s3 = Student("Brad", "160125", 8, 3.26);
	Student s4 = Student("Richard", "150217", 9, 2.49);


	//add student to vector

	stuVector.push_back(s1);
	stuVector.push_back(s2);
	stuVector.push_back(s3);
	stuVector.push_back(s4);

	//dipslay all the students
	cout << "\nAll Available Students\n";
	for (int i = 0; i < stuVector.size(); ++i) {
		
		cout << "\nStudent " << i + 1 << endl;

			cout << "Name : " << stuVector.at(i).getName() << endl;
			cout << "GPA : " << stuVector.at(i).getGPA() << endl;
			cout << "Semester : " << stuVector.at(i).getSem() << endl;
			cout << "Roll Number : " << stuVector.at(i).getRollNo() << endl;
	}

	
	//input name of student to search

	string name = "";
	cout << "\n\nEnter Name to search for student : ";
	cin >> name;

	//funtion to find student
	findStudent(stuVector, name);

	

}

