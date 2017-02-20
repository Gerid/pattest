#include <iostream>
#include <string>
using namespace std;

int main(){
	string temp;
	string N;
	cin >> N;
	temp = N;
	int sum = 0;
	for (int i = 0; i < N.length(); i++){
		sum+=N[i]-'0';
	}
	string res = to_string(sum);
	for (int i = 0; i < res.length(); i++){
		char a = res[i];
		switch (a){
		case '0': cout << "zero"; break;
		case '1': cout << "one"; break;
		case '2': cout << "two"; break;
		case '3': cout << "three"; break;
		case '4': cout << "four"; break;
		case '5': cout << "five"; break;
		case '6': cout << "six"; break;
		case '7': cout << "seven"; break;
		case '8': cout << "eight"; break;
		case '9': cout << "nine"; break;
		default: cout << "error"; break;
		}
		if (i<res.length()-1) cout << " ";
	}
}