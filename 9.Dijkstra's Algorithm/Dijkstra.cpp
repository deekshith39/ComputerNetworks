#include <bits/stdc++.h>

using namespace std;

int minKey(int dist[], bool visited[], int V)
{
    int mini = INT_MAX;
    int index;

    for (int i = 0; i < V; i++)
    {
        if(visited[i] == false && dist[i] <= mini)
        {
            mini = dist[i];
            index = i;
        }
    }

    return index;   
}

void printPath(int parent[], int x)
{
    if(x == -1) return;
    else {
        printPath(parent, parent[x]);
        cout << " -> " << x ;
    }
}

void printSol(int dist[], int V, int parent[])
{
    cout << "Vertex" << "   " << " Distance from source " << endl;
    for(int i=0; i<V; i++)
    cout << i << " \t\t " << dist[i] << endl;
    cout << endl;
    cout << "Path from source to all vertices : " << endl;
    for(int i=0;i<V;i++)
    {
        cout << "VERTEX " << i << " : " ; printPath(parent, i);
        cout << endl;
    }
}



void ShortestPath(vector < vector < int > > &graph, int src, int V)
{
    int dist[V];
    int parent[V];
    bool visited[V];
    for (int i = 0; i < V; i++) 
        {dist[i] = INT_MAX; visited[i] = false; parent[i] = -1; }
  
    
    dist[src] = 0;
    parent[src] = -1;
    for(int c=0;c<V-1;c++)
    {
        int u = minKey(dist, visited, V);
        visited[u] = true;
        
        for(int v=0;v<V;v++)
        {
            if( !visited[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }
    printSol(dist, V, parent);
}

int main()
{
    int V;
    cout << "Enter the number of vertices : ";
    cin >> V;
    cout << endl;
    

    vector < vector < int > > graph = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 }, 
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 }, 
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 }, 
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 }, 
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 }, 
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 }, 
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 }, 
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 }, 
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } }; 
    // cout << "Enter the adjacency matrix : " << endl;
    // for(int i=0;i<V;i++)
    // {
    //     vector < int > temp;
    //     for(int j=0;j<V;j++)
    //     {
    //         int val;
    //         cin >> val;
    //         temp.push_back(val);
    //     }
    //     graph.push_back(temp);
    // }

    cout << "The entered Matrix is : " << endl;
    for(int i=0;i<V;i++)
    {    for(int j=0;j<V;j++)
            cout << graph[i][j] << " ";
          cout << endl;  
    }

    cout << endl;

    int src;
    cout << "enter the source : ";
    cin >> src;

    cout << endl;

    ShortestPath(graph, src, V);

    return 0;
}