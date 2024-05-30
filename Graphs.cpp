#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)

using namespace std;
template <typename T>
//Graph implementation
/*Nodes, Edges(Object is mapped to a list/vector)
1.map<node datatype,list<node datatype>>
2.vector<vector<int>>

n-->nodes m-->edges. Tree--> n nodes, n-1edges
-Sum of degrees in a graph is 2m
-Coloring: No two adj.nodes can have the same color
-
-A graph is called bipartite if you adj have same color a bipartite graph is not possible if we have a cycle with odd no. of edges
*/

/*A graph can be represented as:
-vector<int> adj[n]
-int adj[n][n]
-vector<pair<int,int>> edges
-map<int,list<int>>*/

class graph{
    public:
    unordered_map<T, list<T>> adj;

    void addEdge(T u,T v, bool direction){
        //direction=0-->undirected graph

        //create edge from u to v;
        adj[u].push_back(v);
        if(direction==0) adj[v].push_back(u);
    }

        void printAdj(){
            for(auto i: adj){
                cout<<i.first<<"->";
                for(auto j: i.second){
                    cout<<j<< " ";
                }
                cout<<endl;
            }
        }
};
/*int main(){
    int n,m;
    cin>>n>>m;
    graph<int> g;
    rep(i,0,m){
        int u,v;
        cin>>u>>v;
        g.addEdge(u,v,0);
    }
    g.printAdj();
    
    return 0;
}
/* vector<int> adj(n)
cin>>n>>m;
rep(i,0,m){
    int u,v;
    cin>>u>>v;

    adj[u].push_back(v);
    adj[v].push_back(u);
}
*/
//DFS is implementes by recursion

/*const int N= 1e5+2;
bool vis[N];
vector<int> adj[N];

void dfs(int node){

}

int main(){
    int n,m;
    cin>>n>>m;

    for(int i=0;i<n;i++) vis[i]=false;

    int x,y;
    for(int i=0;i<m;i++){
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(1);
    return 0;
}*/

//BFS
/*notation: adj[currentnode] evaluates all elements connected to current node*/

// Function to perform Breadth First Search on a graph
// represented using adjacency list
/*void bfs(vector<vector<int> >& adjList, int startNode,
         vector<bool>& visited)
{
    // Create a queue for BFS
    queue<int> q;

    // Mark the current node as visited and enqueue it
    visited[startNode] = true;
    q.push(startNode);

    // Iterate over the queue
    while (!q.empty()) {
        // Dequeue a vertex from queue and print it
        int currentNode = q.front();
        q.pop();
        cout << currentNode << " ";

        // Get all adjacent vertices of the dequeued vertex
        // currentNode If an adjacent has not been visited,
        // then mark it visited and enqueue it
        for (int neighbor : adjList[currentNode]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

// Function to add an edge to the graph
void addEdge(vector<vector<int> >& adjList, int u, int v)
{
    adjList[u].push_back(v);
}

int main()
{
    // Number of vertices in the graph
    int vertices = 5;

    // Adjacency list representation of the graph
    vector<vector<int> > adjList(vertices);

    // Add edges to the graph
    addEdge(adjList, 0, 1);
    addEdge(adjList, 0, 2);
    addEdge(adjList, 1, 3);
    addEdge(adjList, 1, 4);
    addEdge(adjList, 2, 4);

    // Mark all the vertices as not visited
    vector<bool> visited(vertices, false);

    // Perform BFS traversal starting from vertex 0
    cout << "Breadth First Traversal starting from vertex "
            "0: ";
    bfs(adjList, 0, visited);

    return 0;
}*/

//DFS using recursion

// Function to perform DFS on a graph
void dfs(vector<vector<int>>& adjList, int node, vector<bool>& visited) {
    // Mark the current node as visited
    visited[node] = true;
    cout << node << " ";

    // Explore all unvisited neighbors
    for (int neighbor : adjList[node]) {
        if (!visited[neighbor]) {
            dfs(adjList, neighbor, visited);
        }
    }
}

int main() {
    // Number of vertices in the graph
    int vertices = 5;

    // Adjacency list representation of the graph
    vector<vector<int>> adjList(vertices);

    // Add edges to the graph
    adjList[0].push_back(1);
    adjList[0].push_back(2);
    adjList[1].push_back(3);
    adjList[1].push_back(4);
    adjList[2].push_back(4);

    // Vector to keep track of visited nodes
    vector<bool> visited(vertices, false);

    // Perform DFS starting from vertex 0
    cout << "Depth First Traversal starting from vertex 0: ";
    dfs(adjList, 0, visited);

    return 0;
}

//DFS using stack
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// Function to perform DFS on a graph using a stack
void dfs(vector<vector<int>>& adjList, int startNode, vector<bool>& visited) {
    // Create a stack for DFS
    stack<int> stk;

    // Push the start node onto the stack and mark it as visited
    stk.push(startNode);
    visited[startNode] = true;

    while (!stk.empty()) {
        // Pop a vertex from the stack and print it
        int currentNode = stk.top();
        stk.pop();
        cout << currentNode << " ";

        // Get all adjacent vertices of the popped vertex
        // If an adjacent vertex has not been visited, then push it onto the stack and mark it as visited
        for (int neighbor : adjList[currentNode]) {
            if (!visited[neighbor]) {
                stk.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }
}

int main() {
    // Number of vertices in the graph
    int vertices = 5;

    // Adjacency list representation of the graph
    vector<vector<int>> adjList(vertices);

    // Add edges to the graph
    adjList[0].push_back(1);
    adjList[0].push_back(2);
    adjList[1].push_back(3);
    adjList[1].push_back(4);
    adjList[2].push_back(4);

    // Vector to keep track of visited nodes
    vector<bool> visited(vertices, false);

    // Perform DFS starting from vertex 0
    cout << "Depth First Traversal starting from vertex 0: ";
    dfs(adjList, 0, visited);

    return 0;
}

//DFS 
// C++ program to print DFS traversal from
// a given vertex in a given graph
#include <bits/stdc++.h>
using namespace std;

// Graph class represents a directed graph
// using adjacency list representation
class Graph {
public:
	map<int, bool> visited;
	map<int, list<int> > adj;

	// Function to add an edge to graph
	void addEdge(int v, int w);

	// DFS traversal of the vertices
	// reachable from v
	void DFS(int v);
};

void Graph::addEdge(int v, int w)
{
	// Add w to v’s list.
	adj[v].push_back(w);
}

void Graph::DFS(int v)
{
	// Mark the current node as visited and
	// print it
	visited[v] = true;
	cout << v << " ";

	// Recur for all the vertices adjacent
	// to this vertex
	list<int>::iterator i;
	for (i = adj[v].begin(); i != adj[v].end(); ++i)
		if (!visited[*i])
			DFS(*i);
}

// Driver code
int main()
{
	// Create a graph given in the above diagram
	Graph g;
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 2);
	g.addEdge(2, 0);
	g.addEdge(2, 3);
	g.addEdge(3, 3);

	cout << "Following is Depth First Traversal"
			" (starting from vertex 2) \n";

	// Function call
	g.DFS(2);

	return 0;
}



