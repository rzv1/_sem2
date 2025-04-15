#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <vector>

using std::cout;
using std::cin;
using std::ifstream;
using std::vector;
using std::pair;

int ind_mat[11][11], n, m, a, b;
//vector<vector<int>> ind_mat(n, vector<int>(m, 0));

int main() {
	ifstream fin("./graph.txt");
	cin >> n >> m;
	vector<pair<int, int>> edges(m);
	vector<vector<int>> adj(n);
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		ind_mat[a][i] = 1;
		ind_mat[b][i] = 1;
	}
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++)
			if (ind_mat[j][i] == 1)
				adj[i].push_back(j);

	for (int i = 0; i < adj.size(); i++) {
		cout << i << ": ";
		for (int j = 0; j < adj[i].size(); j++)
			cout << adj[i][j] << " ";
		cout << "\n";
	}

	for (int i = 1; i <= n; i++, cout << "\n")
		for (int j = 1; j <= m; j++)
			cout << ind_mat[i][j] << " ";
}