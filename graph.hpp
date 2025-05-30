#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <vector>
#include <algorithm>
#include <memory>

struct Edge {
    int src;
    int dest;
    double weight;

    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

class Graph {
public:
    Graph(int vertices) : V(vertices) {}

    void addEdge(int u, int v, double w) {
        edges.emplace_back(Edge{u, v, w});
    }

    std::vector<Edge> findMST();

private:
    int V;
    std::vector<Edge> edges;

    // Union-Find helpers
    int find(int u, std::vector<int>& parent);
    void unite(int u, int v, std::vector<int>& parent, std::vector<int>& rank);
};

#endif