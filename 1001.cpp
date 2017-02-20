#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main(){
	int a, b;
	cin >> a >> b;
	int sum = a + b;
	int is_positive;
	string number;
	if (sum < 0){
		cout << "-";
		sum = -1 * sum;
	}
	int res=sum;
	int ind=0;
	while (res != 0){
		res /= 10;
		ind++;
	}
	res = sum;
	int temp = res;
	int flag = ind % 3;//10000 ind =4 flag=1
	int f1 = 0;
	int i = 0;
	number = to_string(res);
	while (i < ind) {
		if (flag == 0){
			if(i!=0)
				cout << ',';
			flag = 2;
		}
		else flag--;
		cout << number[i];
		i++;
	}

}