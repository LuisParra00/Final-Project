#include "graph.hpp"

int Graph::find(int u, std::vector<int>& parent) {
    if (parent[u] != u)
        parent[u] = find(parent[u], parent);
    return parent[u];
}

void Graph::unite(int u, int v, std::vector<int>& parent, std::vector<int>& rank) {
    int rootU = find(u, parent);
    int rootV = find(v, parent);

    if (rootU != rootV) {
        if (rank[rootU] < rank[rootV]) {
            parent[rootU] = rootV;
        } else if (rank[rootU] > rank[rootV]) {
            parent[rootV] = rootU;
        } else {
            parent[rootV] = rootU;
            rank[rootU]++;
        }
    }
}

std::vector<Edge> Graph::findMST() {
    std::vector<Edge> result;
    std::sort(edges.begin(), edges.end());

    std::vector<int> parent(V);
    std::vector<int> rank(V, 0);
    for (int i = 0; i < V; ++i) parent[i] = i;

    for (const Edge& e : edges) {
        int setU = find(e.src, parent);
        int setV = find(e.dest, parent);

        if (setU != setV) {
            result.push_back(e);
            unite(setU, setV, parent, rank);
        }

        if (result.size() == V - 1) break; // its anarly exit for MST
    }

    return result;
}