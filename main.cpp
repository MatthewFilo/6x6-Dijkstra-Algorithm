#include <iostream>
#include <algorithm>
#include <cmath>
#include <climits>
using namespace std;

// Program this with a 6x6 matrix in mind

#define inf INT_MAX

int minimumdistance(int dist[], bool tset[])
{
    int min = inf;
    int index;

    for(int i = 0; i < 6; i++)
    {
        if(tset[i] == false && dist[i] <= min)
        {
            min = dist[i];
            index = i;
        }
    }

    return index;
}


void dijkstra(int graph[6][6], int source)
{
    int dist[6]; // Calculate minimum distance for each node.
    bool tset[6]; // Used to mark visited or unvisited for each node


    for(int i = 0; i < 6; i++) // setting all the nodes other then the source node to unvisited and "infinite" distance.
    {
        dist[i] = inf;
        tset[i] = false;
    }

    dist[source] = 0;

    for(int i = 0; i < 6; i++)
    {
        int j = minimumdistance(dist, tset); 
        tset[j] = true;

        for(int l = 0; l < 6; l++)
        {
            if(!tset[l] && graph[j][l] && dist[j] + graph[j][l] < dist[l] && dist[j] != inf)
            {
                dist[l] = graph[j][l] + dist[j];
            }
        }
        
    }

	cout<<"Vertex\t\tDistance from source"<<endl;
	for(int i = 0; i<6; i++)                      
	{ 
		char str=65+i; 
		cout<<str<<"\t\t\t"<<dist[i]<<endl;
	} 

}



int main()
{
    int graph[6][6]=
    {
		{0, 10, 20, 0, 0, 0},
		{10, 0, 0, 50, 10, 0},
		{20, 0, 0, 20, 33, 0},
		{0, 50, 20, 0, 20, 2},
		{0, 10, 33, 20, 0, 1},
		{0, 0, 0, 2, 1, 0}
    };

	dijkstra(graph,0);

    return 0;
}