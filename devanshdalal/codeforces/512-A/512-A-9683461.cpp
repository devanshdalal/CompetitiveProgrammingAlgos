// A C++ program to print topological sorting of a DAG
#include<iostream>
#include <list>
#include <stack>
#include <cstring>
using namespace std;
 
// Class to represent a graph
class Graph
{
    int V;    // No. of vertices'
 
    // Pointer to an array containing adjacency listsList
    list<int> *adj;
    bool isCyclicUtil(int v, bool visited[], bool *rs);  // used by isCyclic()
 
    // A function used by topologicalSort
    void topologicalSortUtil(int v, bool visited[], stack<int> &Stack);
public:
    Graph(int V);   // Constructor
 
     // function to add an edge to graph
    void addEdge(int v, int w);
 
    // prints a Topological Sort of the complete graph
    bool isCyclic();    // returns true if there is a cycle in this graph
    void topologicalSort();
};

 
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}
 
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to v’s list.
}
 
// A recursive function used by topologicalSort
void Graph::topologicalSortUtil(int v, bool visited[], stack<int> &Stack)
{
    // Mark the current node as visited.
    visited[v] = true;
 
    // Recur for all the vertices adjacent to this vertex
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            topologicalSortUtil(*i, visited, Stack);
 
    // Push current vertex to stack which stores result
    Stack.push(v);
}

bool Graph::isCyclicUtil(int v, bool visited[], bool *recStack)
{
    if(visited[v] == false)
    {
        // Mark the current node as visited and part of recursion stack
        visited[v] = true;
        recStack[v] = true;
 
        // Recur for all the vertices adjacent to this vertex
        list<int>::iterator i;
        for(i = adj[v].begin(); i != adj[v].end(); ++i)
        {
            if ( !visited[*i] && isCyclicUtil(*i, visited, recStack) )
                return true;
            else if (recStack[*i])
                return true;
        }
 
    }
    recStack[v] = false;  // remove the vertex from recursion stack
    return false;
}

bool Graph::isCyclic()
{
    // Mark all the vertices as not visited and not part of recursion
    // stack
    bool *visited = new bool[V];
    bool *recStack = new bool[V];
    for(int i = 0; i < V; i++)
    {
        visited[i] = false;
        recStack[i] = false;
    }
 
    // Call the recursive helper function to detect cycle in different
    // DFS trees
    for(int i = 0; i < V; i++)
        if (isCyclicUtil(i, visited, recStack))
            return true;
 
    return false;
}
 
// The function to do Topological Sort. It uses recursive topologicalSortUtil()
void Graph::topologicalSort()
{
    stack<int> Stack;
 
    // Mark all the vertices as not visited
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;
 
    // Call the recursive helper function to store Topological Sort
    // starting from all vertices one by one
    for (int i = 0; i < V; i++)
      if (visited[i] == false)
        topologicalSortUtil(i, visited, Stack);
 
    // Print contents of stack
    while (Stack.empty() == false)
    {
        cout << char(Stack.top()+'a') ;
        Stack.pop();
    }
}
 
// Driver program to test above functions
int main()
{
    // Create a graph given in the above diagram
    // g.addEdge(5, 2);
    // g.addEdge(5, 0);
    // g.addEdge(4, 0);
    // g.addEdge(4, 1);
    // g.addEdge(2, 3);
    // g.addEdge(3, 1);
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    Graph g(26);
    char a[101][101];
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    for (int i = 1; i < n; ++i)
    {
        int j;
        int mi=min(strlen(a[i-1]),strlen(a[i]));
        for ( j= 0; j < mi ; ++j)
        {
            if(a[i-1][j]!=a[i][j]){
                g.addEdge(a[i-1][j]-'a',a[i][j]-'a');
                break;
            }
        }
        if(j==mi and strlen(a[i-1])>strlen(a[i]))n=0;
    }
    if (n==0 or g.isCyclic())
    {
        cout << "Impossible\n";
    }else{
        g.topologicalSort();
    }

 
    // cout << "Following is a Topological Sort of the given graph \n";
    // g.topologicalSort();
 
    return 0;
}