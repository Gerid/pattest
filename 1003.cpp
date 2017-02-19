#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 500;
const int inf = 100000;
const int nil = -1;

struct Node{
	int no, dis;
	Node(int no, int dis = inf) :no(no), dis(dis){}
};

vector<int> set;
vector<Node> node[N];
int result[N][4];//r[][0]-dis r[][1]-team r[][2]-pre r[][3]-pathscount
int n, m, s, d;
int team[N] = {0};




void initial(){
	cin >> n >> m >> s >> d;
	for (int i = 0; i<N; i++){
		result[i][0] = inf;
		result[i][1] = 0;
		result[i][2] = nil;
		result[i][3] = 0;
	}
	for (int i = 0; i < n; i++)
	{
		cin >> result[i][1];
		team[i] = result[i][1];
	}
	for (int i = 0; i<m; i++){
		int a, b, dis;
		cin >> a >> b >> dis;
		node[a].push_back(Node(b, dis));
		node[b].push_back(Node(a, dis));
		if (a == s){
			result[b][0] = dis; result[b][2] = s; result[b][3] = 1;
		}
		else if (b == s){
			result[a][0] = dis; result[a][2] = s; result[a][3] = 1;
		}
	}
	for (int i = 0; i<n; i++)
		set.push_back(i);
	result[s][0] = 0;
	result[s][2] = nil;
	result[s][3] = 1;
}

bool lessNode(const int &a, const int &b){
	return result[a][0]<result[b][0];
}

void function(){
	set.erase(set.begin() + s);
	while (!set.empty()){
		sort(set.begin(), set.end(), lessNode);
		int a = set[0];
		set.erase(set.begin());
		for (int i = 0; i<node[a].size(); i++){
			Node u = node[a][i];
			if (u.dis + result[a][0] <= result[u.no][0]){
				if (u.dis + result[a][0] == result[u.no][0])
				{
					result[u.no][3] += result[a][3];
				}
				else result[u.no][3] = result[a][3];
				if (team[u.no] + result[a][1]>result[u.no][1])
					result[u.no][1] = result[a][1] + team[u.no];
				result[u.no][0] = u.dis + result[a][0];
				result[u.no][2] = a;
			}
		}

	}
}

void print(){
	if (d != s)
		cout << result[d][3] << ' ' << result[d][1] + team[s];//这里考虑第二个测试点 d==s
	else
		cout << result[d][3] << ' ' << result[d][1];
}

int main(){
	initial();
	function();
	print();
}
