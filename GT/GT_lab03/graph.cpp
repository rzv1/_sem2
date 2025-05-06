#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>

using std::vector;
using std::pair;
using std::queue;
using std::string;
using std::ifstream;
using std::ofstream;
using std::min;
using std::cin;

typedef vector<pair<int, int>> Lista;
typedef vector<vector<int>> Matrix;

class Graph {
private:
	const string inputFile;
	int V, E;
	int inf = 9999;
	int start;
	Matrix adjMatrix, adjList, incMatrix, disMatrix;
	Lista edgesList;

	void readFromFile(const string& inputFile, const string& outputFile) {
		ifstream fin(inputFile);
		ofstream fout(outputFile);
		fin >> V >> E >> start;
		int a, b, w;
		while (fin >> a && fin >> b && fin >> w) {
			a--; b--;
			edgesList.emplace_back(a, b);
		}
		fin.close();
		fout.close();
	}
	void init_adjMatrix() {
		adjMatrix.clear();
		adjMatrix.assign(V, vector<int>(V, 0));
	}
	void init_disMatrix() {
		disMatrix.clear();
		disMatrix.assign(V, vector<int>(V, 0));
	}
	void init_incMatrix() {
		incMatrix.clear();
		incMatrix.assign(V, vector<int>(E, 0));
	}
	void init_adjList() {
		adjList.clear();
		adjList.assign(V, {});
	}
public:
	Graph(const string& filepath) : inputFile{ filepath }, V{ 0 }, E{ 0 } {
		readFromFile(inputFile);
		init_adjMatrix();
		init_disMatrix();
		init_incMatrix();
		init_adjList();
	}

	void edgesList_to_adjMatrix() {
		for (const auto& edge : edgesList) {
			auto a = edge.first, b = edge.second;
			adjMatrix[a][b] = 1;
		}
	}

	void adjMatrix_to_adjList() {
		for (int i = 0; i < V; i++)
			for (int j = 0; j < V; j++)
				if (adjMatrix[i][j] == 1) {
					adjList[i].push_back(j);
				}
	}

	void print_adjMatrix() {
		printf("Matricea de adiacenta este:\n");
		for (int i = 0; i < V; i++, printf("\n"))
			for (int j = 0; j < V; j++)
				printf("%d ", adjMatrix[i][j]);
		printf("\n");
	}

	void print_incMatrix() {
		printf("Matricea de incidenta este:\n");
		for (int i = 0; i < V; i++, printf("\n"))
			for (int j = 0; j < E; j++)
				printf("%d ", incMatrix[i][j]);
		printf("\n");
	}

	void print_adjList() {
		printf("Lista de adiacenta este:\n");
		for (int i = 0; i < V; i++, printf("\n")) {
			printf("%d: ", i + 1);
			for (int j = 0; j < adjList[i].size(); j++)
				printf("%d ", adjList[i][j] + 1);
		}
		printf("\n");
	}

	void print_edgesList() {
		printf("Lista de muchii este:\n");
		for (int i = 0; i < edgesList.size(); i++)
			printf("%d %d\n", edgesList[i].first + 1, edgesList[i].second + 1);
		printf("\n");
	}
};

int main(int argc, char* argv[]) {
	ifstream fin(argv[1]);
	ofstream fout(argv[2]);
	Graph G(argv[1], argv[2]);

	fin.close();
	fout.close();
	return 0;
}