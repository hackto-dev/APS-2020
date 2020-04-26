#include <iostream>
#include <vector>
#include <cstring>
#include <iomanip>
using namespace std;

// Number of vertices in the graph
#define N 4

// data structure to store graph edges
struct Edge
{
    int src, dest;
};

// class to represent a graph object
class Graph
{
public:
    // An array of vectors to represent adjacency list
    vector<int> adjList[N];

    // Constructor
    Graph(vector<Edge> const &edges)
    {
        // add edges to the directed graph
        for (int i = 0; i < edges.size(); i++)
        {
            int src = edges[i].src;
            int dest = edges[i].dest;

            adjList[src].push_back(dest);
        }
    }
};

// C is connectivity matrix and stores transitive closure of graph
// root is the topmost node in DFS tree(it is starting vertex of DFS)
// descendant is current vertex to be explored in DFS
// Invariant: A path already exists from root -> descendant in graph
void DFS(Graph const &graph, bool C[N][N], int root, int descendant)
{
    for (int child : graph.adjList[descendant])
    {
        // if child is an adjacent vertex of descendant, we have
        // found a path from root->child
        if (!C[root][child])
        {
            C[root][child] = true;
            DFS(graph, C, root, child);
        }
    }
}

// main function
int main()
{
    // array of graph edges as per above diagram
    vector<Edge> edges = {
        {0, 2}, {1, 0}, {3, 1}};

    // create a graph from edges
    Graph graph(edges);

    // C is connectivity matrix and stores the transitive closure
    // of the graph. The value of C[i][j] is 1 only if a directed
    // path exists from vertex i to vertex j.
    bool C[N][N];
    memset(C, false, sizeof C);

    // consider each vertex and start DFS from it
    for (int v = 0; v < N; v++)
    {
        C[v][v] = true;
        DFS(graph, C, v, v);

        // print path info for vertex v
        for (int u = 0; u < N; u++)
            cout << left << setw(4) << C[v][u];
        cout << endl;
    }

    return 0;
}