#include <iostream>
#include <vector>

using namespace std;

const int INF = 1000000000;

void SetGraph(vector<vector<int>>& adj, int n) {
    for (int i = 0; i < n; i ++) {
        vector<int> row;
        for (int j = 0; j < n; j++) {
            string tmp;
            cin >> tmp;
            if (tmp == "-") {
                row.push_back(INF);
            } else {
                row.push_back(atoi(tmp.c_str()));
            }
        }
        adj.push_back(row);
    }
}

void PrintGraph(vector<vector<int>>& adj, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (adj[i][j] == INF) {
                cout << '-' << ' ';
            } else {
                cout << adj[i][j] << ' ';
            }
        }
        cout << '\n';
    }
}

int minKey(vector<int> keys, vector<bool> used, int v)
{
    int min = INF;
    int minIndex;
    for (int i = 0; i < v; i++) {
        if (!used[i] && keys[i] < min) {
            min = keys[i];
            minIndex = i;
        }
    }
    return minIndex;
}

void PrimAlgorithm(vector<vector<int>> adj, int n)
{
    vector<int> p(n); 
    vector<int> keys(n, INF); 
    vector<bool> used(n, false);

    keys[0] = 0;
    p[0] = -1;
    for (int i = 0; i < n - 1; i++) {
        int k = minKey(keys, used, n);
        used[k] = 1;
        for (int j = 0; j < n; j++) {
            if (adj[k][j] and !used[j] and adj[k][j] < keys[j]) {
                p[j] = k;
                keys[j] = adj[k][j];
            }
        }
    }

    //PrintResult
    cout << "Edges\tWeights\n";
    for (int i = 1; i < n; i++) {
        cout << p[i] << "-" << i << " \t" << adj[i][p[i]] << " \n";
    }
}

int main() {
    int n;
    cin >> n;
    vector <vector<int>> adj;
    SetGraph(adj, n);
    PrimAlgorithm(adj, n);
}
