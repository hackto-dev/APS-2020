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

        // add edges to the Directed graph
        for (auto &edge : edges)
        {
            adjList[edge.src].push_back(edge.dest);
        }
    }
};

// Perform DFS on graph and set departure time of all
// vertices of the graph
int DFS(Graph const &graph, int v, vector<bool> &discovered, vector<int> &departure, int &time)
{
    // mark current node as discovered
    discovered[v] = true;

    // do for every edge (v -> u)
    for (int u : graph.adjList[v])
    {
        // u is not discovered
        if (!discovered[u])
            DFS(graph, u, discovered, departure, time);
    }

    // ready to backtrack
    // set departure time of vertex v
    departure[v] = time++;
}

// returns true if given directed graph is DAG
bool isDAG(Graph const &graph, int N)
{
    // stores vertex is discovered or not
    vector<bool> discovered(N);

    // stores departure time of a vertex in DFS
    vector<int> departure(N);

    int time = 0;

    // Do DFS traversal from all undiscovered vertices
    // to visit all connected components of graph
    for (int i = 0; i < N; i++)
        if (discovered[i] == false)
            DFS(graph, i, discovered, departure, time);

    // check if given directed graph is DAG or not
    for (int u = 0; u < N; u++)
    {
        // check if (u, v) forms a back-edge.
        for (int v : graph.adjList[u])
        {
            // If departure time of vertex v is greater
            // than equal to departure time of u, then
            // they form a back edge

            // Note that departure[u] will be equal to
            // departure[v] only if u = v i.e vertex
            // contain an edge to itself
            if (departure[u] <= departure[v])
                return false;
        }
    }

    // no back edges
    return true;
}

// Check if given digraph is a DAG (Directed Acyclic Graph) or not
int main()
{
    // vector of graph edges as per above diagram
    vector<Edge> edges =
        {
            {0, 1}, {0, 3}, {1, 2}, {1, 3}, {3, 2}, {3, 4}, {3, 0}, {5, 6}, {6, 3}};

    // Number of nodes in the graph
    int N = 7;

    // create a graph from given edges
    Graph graph(edges, N);

    // check if given directed graph is DAG or not
    if (isDAG(graph, N))
        cout << "Graph is DAG";
    else
        cout << "Graph is not DAG";

    return 0;
}