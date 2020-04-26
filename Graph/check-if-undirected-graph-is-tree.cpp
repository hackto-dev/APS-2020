#include <iostream>
#include <vector>
using namespace std;

// data structure to store graph edges
struct Edge
{
    int src, dest;
};

// class to represent a graph object
class Graph
{
public:
    // construct a vector of vectors to represent an adjacency list
    vector<vector<int>> adjList;

    // Graph Constructor
    Graph(vector<Edge> const &edges, int N)
    {
        // resize the vector to N elements of type vector<int>
        adjList.resize(N);

        // add edges to the undirected graph
        for (auto &edge : edges)
        {
            adjList[edge.src].push_back(edge.dest);
            adjList[edge.dest].push_back(edge.src);
        }
    }
};

// Perform DFS on graph and returns true if any back-edge
// is found in the graph
bool DFS(Graph const &graph, int v, vector<bool> &discovered, int parent)
{
    // mark current node as discovered
    discovered[v] = true;

    // do for every edge (v -> w)
    for (int w : graph.adjList[v])
    {
        // w is not discovered
        if (!discovered[w])
        {
            if (!DFS(graph, w, discovered, v))
                return false;
        }

        // w is discovered and w is not a parent
        else if (w != parent)
        {
            // we found a back-edge (cycle)
            return false;
        }
    }

    // No back-edges found in the graph
    return true;
}

// Determine if an undirected graph is a Tree (Acyclic Connected Graph)
int main()
{
    // initialize edges as per above diagram
    vector<Edge> edges =
        {
            {0, 1}, {1, 2}, {2, 3}, {3, 4}, {4, 5}, {5, 0}
            // edge (5->0) introduces a cycle in the graph
        };

    // Number of nodes in the graph
    int N = 6;

    // create a graph from edges
    Graph graph(edges, N);

    // stores vertex is discovered or not
    vector<bool> discovered(N);

    // boolean flag to store if the graph is tree or not
    bool isTree = true;

    // Do DFS traversal from first vertex
    isTree = DFS(graph, 0, discovered, -1);

    for (int i = 0; isTree && i < N; i++)
    {
        // any undiscovered vertex means graph is not connected
        if (!discovered[i])
            isTree = false;
    }

    if (isTree)
        cout << "Graph is a Tree";
    else
        cout << "Graph is not a Tree";

    return 0;
}