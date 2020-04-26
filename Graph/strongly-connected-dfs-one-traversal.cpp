#include <iostream>
#include <vector>
using namespace std;

// data structure to store graph edges
struct Edge
{
    int src, dest;
};

class Graph
{
public:
    // construct a vector of vectors to represent an adjacency list
    vector<vector<int>> adjList;

    // Graph Constructor
    Graph(const vector<Edge> &edges, int N)
    {
        // resize the vector to N elements of type vector<int>
        adjList.resize(N);

        // add edges to the directed graph
        for (auto &edge : edges)
            adjList[edge.src].push_back(edge.dest);
    }
};

// Perform DFS on graph starting from vertex v
int DFS(Graph const &graph, int v, vector<bool> &discovered, int arrival[], bool &isSC, int &time)
{
    // terminate the search if graph is not strongly
    // connected
    if (!isSC)
        return false;

    // set arrival time of vertex v
    arrival[v] = ++time;

    // mark vertex as discovered
    discovered[v] = true;

    // initialize arr to arrival time of vertex v
    int arr = arrival[v];

    // do for every edge (v -> w)
    for (int w : graph.adjList[v])
    {
        // vertex w is not yet explored
        if (!discovered[w])
            arr = min(arr, DFS(graph, w, discovered,
                               arrival, isSC, time));
        // vertex w is explored before
        else
            // If the vertex is w is already discovered,
            // that means there is either a cross edge
            // or a back edge starting from v. Note that
            // the arrival time is already defined for w
            arr = min(arr, arrival[w]);
    }

    // if v is not root node and value of arr didn't
    // change i.e. it is still set to arrival time of
    // vertex v, the graph is not strongly connected
    if (v != 0 && arr == arrival[v])
        isSC = false;

    // we return the minimum arrival time
    return arr;
}

// Check if given Graph is Strongly Connected or not
int main()
{
    // vector of graph edges as per above diagram
    vector<Edge> edges = {
        {0, 4}, {1, 0}, {1, 2}, {2, 1}, {2, 4}, {3, 1}, {3, 2}, {4, 3}};

    // Number of vertices in the graph
    int N = 5;

    // create a graph from given edges
    Graph graph(edges, N);

    // stores vertex is discovered or not
    vector<bool> discovered(N);

    // array to store arrival time of vertex.
    int arrival[N];

    // flag to determine if graph is strongly connected
    // or not
    bool isSC = true;
    int time = -1;

    // Do DFS traversal starting from first vertex.
    DFS(graph, 0, discovered, arrival, isSC, time);

    // If DFS traversal doesn’t visit all vertices,
    // then graph is not strongly connected
    for (int i = 0; i < N; i++)
        if (discovered[i] == false)
            isSC = false;

    if (isSC)
        cout << "Graph is Strongly Connected";
    else
        cout << "Graph is not Strongly Connected";

    return 0;
}