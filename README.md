# Final-Project

Luis Parra 5/28/25


This program has:
    - A custom graph representation
    - A complete implementation of Kruskal's algorithm
    - Union-Find data structure for cycle detection
    - Unit tests using the Catch2 framework

The sample input could be:
    Graph g(4);
    g.addEdge(0, 1, 1.0);
    g.addEdge(0, 2, 3.0);
    g.addEdge(0, 3, 4.0);
    g.addEdge(1, 2, 2.0);
    g.addEdge(2, 3, 5.0);

The sample output would be:
    (0 - 1) weight 1.0
    (1 - 2) weight 2.0
    (0 - 3) weight 4.0