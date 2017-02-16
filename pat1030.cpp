#include <iostream>
#include <vector>
#include <stack>
#include <deque>
#include <algorithm>
using namespace std;

const int N = 40;
const int inf = 100000;
const int nil = -1;
struct Node{
	int no, dis, cos;
	Node(int no, int dis = inf, int cos = inf) :no(no), dis(dis), cos(cos){}
};

//用dijkstra 算法
vector<int> set;
vector<Node> node[N];
int result[N][3];
int n, m, s, d;

void initial()
{
	cin >> n >> m >> s >> d;
	for (int i = 0; i<N; i++){
		result[i][0] = inf;
		result[i][1] = inf;
		result[i][2] = nil;
	}
	for (int i = 0; i<m; i++){
		int a, b, dis, cos;
		cin >> a >> b;
		cin >> dis >> cos;
		node[a].push_back(Node(b, dis, cos));
		node[b].push_back(Node(a, dis, cos));
		if (a == s){
			result[b][0] = dis; result[b][1] = cos; result[b][2] = s;
		}
		else if (b == s){
			result[a][0] = dis; result[a][1] = cos; result[a][2] = s;
		}
	}
	for (int i = 0; i<n; i++){
		set.push_back(i);
	}
	result[s][0] = 0;
	result[s][1] = 0;
	result[s][2] = nil;
}//initial result[][]

bool lessNode(const Node &a, const Node &b)
{
	int i = a.no;
	int j = b.no;
	if (result[i][0]<result[j][0])
		return true;
	else if (result[i][0] == result[j][0])
		return result[i][1]<result[j][1];
	else return false;
}

void function(){
	set.erase(set.begin() + s);
	sort(set.begin(), set.end(), lessNode);
	while (!set.empty()){
		int a = set[0];
		set.erase(set.begin());
		for (int i = 0; i<node[a].size(); i++){
			int v = node[a][i].no;
			int u = a;
			if (result[u][0] + node[u][i].dis<result[v][0]||(result[u][0]+node[u][i].dis==result[v][0]&&result[u][1]+node[u][i].cos<result[v][1])){
				result[v][0] = result[u][0] + node[u][i].dis;
				result[v][1] = result[u][1] + node[u][i].cos;
				result[v][2] = u;
			}
		}
		sort(set.begin(), set.end(), lessNode);
	}
}

void printpath(int a){
		if (a != s) {
			printpath(result[a][2]);
			cout << a << ' ';
		}
		else cout << a <<' ';
}
int main(){
	initial();
	function();
	printpath(d);
	cout << result[d][0] <<' '<< result[d][1];
}




