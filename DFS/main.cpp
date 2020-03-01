// Depth-first search
// Graph is specified as an adjacency list

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int DFS(vector<vector<int>>&, int&, int&);

int main() {
    vector<vector<int>> G{
        {1, 2, 5, 6, 7},
        {0, 7},
        {0, 7},
        {4, 5},
        {3, 5, 6, 7},
        {0, 3, 4},
        {0, 4},
        {0, 1, 2, 4}
    };

    int start, finish; // start and end vertices
    cout << "Enter start node => "; cin >> start;
    cout << "Enter finish node => ";  cin >> finish;
    cout << "Path min length "
        << DFS(G, start, finish)
        << endl;

    return 0;
}

int DFS(vector<vector<int>>& myG, int& s, int& u) {
    size_t n = myG.size();  // number of vertices

    stack<int> S;
    S.push(s);

    vector<bool> used(n, false);
    used[s] = true;

    vector<int> D(n);   // path length vector
    vector<int> P(n);   // vector of ancestors for route output
    P[s] = -1;

    while (!S.empty()) {
        size_t v = S.top();
        S.pop();
        auto first = myG[v].begin();
        auto last = myG[v].end();
        while (first != last) {
            if (!used[*first]) {
                S.push(*first);
                used[*first] = true;
                D[*first] = D[v] + 1;
                P[*first] = v;
            }
            first++;
        }
    }
    return D[u];
}