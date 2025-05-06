#include <iostream>

using namespace std;

int mat_adj[11][11], mat_ind[11][11], mat_distante[11][11], n, m;

void Warshall_Floyd() {
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (mat_distante[i][k] + mat_distante[k][j] < mat_distante[i][j]) {
					mat_distante[i][j] = mat_distante[i][k] + mat_distante[k][j];
				}
			}
		}
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> mat_adj[i][j];
		}
	}

    for (int i = 0; i < n; i++)
        for (int j = 0; j < 11; j++)
            mat_ind[i][j] = 0;

    int col = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (mat_adj[i][j] == 1) {
                mat_ind[i][col] = 1;
                mat_ind[j][col] = 1;
                col++; 
            }
        }
    }
	Warshall_Floyd();

    cout << "\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < col; j++) {
            cout << mat_distante[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}