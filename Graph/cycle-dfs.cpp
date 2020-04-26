#include <iostream>
#include <vector>
#include <queue>
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
bool DFS(Graph const &graph, int v, vector<bool> &discovered,
         int parent)
{
    // mark current node as discovered
    discovered[v] = true;

    // do for every edge (v -> w)
    for (int w : graph.adjList[v])
    {
        // w is not discovered
        if (!discovered[w])
        {
            if (DFS(graph, w, discovered, v))
                return true;
        }

        // w is discovered and w is not a parent
        else if (w != parent)
        {
            // we found a back-edge (cycle)
            return true;
        }
    }

    // No back-edges found in the graph
    return false;
}

// Check if an undirected graph contains cycle or not
int main()
{
    // initialize edges as per above diagram
    vector<Edge> edges =
        {
            {1, 2}, {1, 7}, {1, 8}, {2, 3}, {2, 6}, {3, 4}, {3, 5}, {8, 9}, {8, 12}, {9, 10}, {9, 11}, {11, 12}
            // edge (11->12) introduces a cycle in the graph
        };

    // Number of nodes in the graph
    int N = 13;

    // create a graph from given edges
    Graph graph(edges, N);

    // stores vertex is discovered or not
    vector<bool> discovered(N);

    // Do DFS traversal from first vertex
    if (DFS(graph, 1, discovered, -1))
        cout << "Graph contains cycle";
    else
        cout << "Graph doesn't contain any cycle";

    return 0;
}