#include <iostream>
#include <vector>
using namespace std;

struct Node{
	int PID;
	vector<int> Child;
	int ID;
	Node(int PID = -1, int ID = 0) :PID(PID), ID(ID){}
};
vector< vector<int> > level;
Node node[100];
int main(){
	int N, M;
	cin >> N >> M;
	for (int i = 0; i<M; i++){
		int ID, K;
		cin >> ID >> K;
		for (int j = 0; j<K; j++){
			int child;
			cin >> child;
			node[ID].Child.push_back(child);
			node[child].PID = ID;
		}
	}
	for (int i = 1; i<=N; i++){
		vector<int> a;
		int l = 0, temp = i;
		while (temp != -1){
			temp = node[temp].PID;
			l++;
		}
		while (level.size()<l){
			level.push_back(a);
		}
		if (node[i].Child.size() == 0)
			level[l - 1].push_back(i);
	}
	for (int i = 0; i<level.size() - 1; i++){
		cout << level[i].size() << ' ';
	}
	cout << level[level.size()-1].size() << endl;
}