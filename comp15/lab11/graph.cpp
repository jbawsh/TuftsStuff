#include "graph.h"
#include <queue>

Graph::Graph()
{
    //Create two dynamic arrays, the adjacency
    //matrix to store the graph and the marked
    //set --- initialized to false for all to start
    //The adjacent matrix is all false, it is an
    //empty graph.
    
    adjacencyMatrix = new bool*[NODE_COUNT];
    markedVertices = new bool[NODE_COUNT];
    
    
    // a loop to create all rows (vertices) an inner
    //loop to create the adjacent vertices (columns)
    //intialized to empty graph
    for(int i=0; i < NODE_COUNT; i++)
    {
        adjacencyMatrix[i] = new bool[NODE_COUNT];
            for (int j=0; j < NODE_COUNT; j++)
            {
                adjacencyMatrix[i][j] = false;
            }
        markedVertices[i]=false;
        
    }
}


Graph::Graph(bool adjM[][NODE_COUNT])
{
    //Create two dynamic arrays, the adjacency
    //matrix to store the graph and the marked
    //set --- initialized to false for all to start
    
    
    adjacencyMatrix = new bool*[NODE_COUNT];
    markedVertices = new bool[NODE_COUNT];
    
    
    // a loop to create all rows (vertices) an inner
    //loop to create the adjacent vertices (columns)
    //intialized to empty graph
    for(int i=0; i < NODE_COUNT; i++)
    {
        adjacencyMatrix[i] = new bool[NODE_COUNT];
        for (int j=0; j < NODE_COUNT; j++)
        {
            adjacencyMatrix[i][j] = adjM[i][j];
        }
        markedVertices[i]=false;
        
    }
}


bool Graph::createEdge(int u, int v)
{
    //if u and v are in bounds then add the edge and return true
    //if edge has been previously added, nothing happens, if
    //out of nounds returns false
    if(u >=0 && u <= NODE_COUNT && v >= 0 && v <= NODE_COUNT)
    {
        adjacencyMatrix[u][v] = true;
        adjacencyMatrix[v][u] = true;
        return true;
    }
    return false;
}



//returns true if there is an edge between
//u and v
bool Graph::isAdjacent(int u, int v)
{
    return adjacencyMatrix[u][v];
}

//marks a vertex true --- public
//could be private
bool Graph::markVertex(int u)
{
    if (u >= 0 && u <= NODE_COUNT)
    {
        markedVertices[u]=true;
        return true;
    }
    return false;
}



bool Graph::isMarked(int u)
{
    return markedVertices[u];
}




//unmark all vertices, also could be
//private
void Graph::unmarkAll()
{
    for (int i = 0; i < NODE_COUNT; i++) {
        markedVertices[i] = false;
    }
}



//BREAD FIRST SEARCH
void Graph::BFS()
{
        unmarkAll();
        int x = 0;
        markVertex(x);
        queue<int> q1;
        q1.push(x);
        while (q1.size() != 0) {
                int u = q1.front();
                q1.pop();
                cout << u << " ";
                for (int i = 0; i < NODE_COUNT; i++) {
                        if (isAdjacent(u,i) && !isMarked(i)){
                                markVertex(i);
                                q1.push(i);
                        }
                }
        }
}


//DEPTH FIRST SEARCH

void Graph::DFS()
{
        unmarkAll();
        helpDFS(0);
        
}

void Graph::helpDFS(int x)
{
        markVertex(x);
        cout << x << " ";
        for (int i = 0; i <NODE_COUNT; i++) {
                if (isAdjacent(x,i) && !isMarked(i)){
                        helpDFS(i);
                }
        }
}
