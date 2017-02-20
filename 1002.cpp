#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

struct Node{
	int exp;
	double coe;
	Node(int exp, double coe) :exp(exp), coe(coe){}
};

vector<Node> poly[2], res;

int main(){
	int l1, l2;
	cin >> l1;
	for (int i = 0; i < l1; i++){
		int exp;
		double coe;
		cin >> exp >> coe;
		Node node(exp, coe);
		poly[0].push_back(node);
	}
	cin >> l2;
	for (int i = 0; i < l2; i++){
		int exp;
		double coe;
		cin >> exp >> coe;
		Node node(exp, coe);
		poly[1].push_back(node);
	}
	while (!poly[0].empty() || !poly[1].empty()){
		double coe;
		int exp;
		if (poly[0].empty()){
			res.push_back(poly[1][0]);
			poly[1].erase(poly[1].begin());
			continue;
		}
		else if (poly[1].empty()){
			res.push_back(poly[0][0]);
			poly[0].erase(poly[0].begin());
			continue;
		}
		if (poly[0][0].exp == poly[1][0].exp){
			coe = poly[0][0].coe + poly[1][0].coe;
			exp = poly[0][0].exp;
			Node node(exp, coe);
			if(coe!=0)res.push_back(node);
			poly[0].erase(poly[0].begin());
			poly[1].erase(poly[1].begin());
		}
		else if (poly[0][0].exp>poly[1][0].exp){
			coe = poly[0][0].coe;
			exp = poly[0][0].exp;
			Node node(exp, coe);
			res.push_back(node);
			poly[0].erase(poly[0].begin());
		}
		else{
			coe = poly[1][0].coe;
			exp = poly[1][0].exp;
			Node node(exp, coe);
			res.push_back(node);
			poly[1].erase(poly[1].begin());
		}
	}
	cout << res.size();
	cout.setf(ios::fixed);
	for (int i = 0; i<res.size(); i++){
		cout << ' ' << res[i].exp << ' ' << fixed << setprecision(1)  << res[i].coe;
	}
}
