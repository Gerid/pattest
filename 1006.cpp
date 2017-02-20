#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;


struct Student{
	string ID;
	string login;
	string logout;
	Student(string ID, string login, string logout) :ID(ID), login(login), logout(logout){}
};

vector<Student> student;

bool lessloginTime(const Student &a, const Student &b){
	return a.login < b.login;
}


bool laterlogoutTime(const Student &a, const Student &b){
	return a.logout>b.logout;
}

int main(){
	int n;
	cin >> n;
	for (int i = 0; i< n; i++){
		string ID;
		string login, logout;
		//cin >>ID>>login.hou >> ":" >> login.min >> ":" >> login.sec >> logout.hou >> ":" >> logout.min >> ":" >> logout.sec;
		cin >> ID >> login >> logout;
		student.push_back(Student(ID, login, logout));
	}
	sort(student.begin(), student.end(), lessloginTime);
	cout << student[0].ID << " ";
	sort(student.begin(), student.end(), laterlogoutTime);
	cout << student[0].ID;

}