#include<iostream>
#include <fstream>
#define INF 999

using namespace std;

class DijkstraAlg
{

    int cost[100][100]={};
    bool visited[100] ={false};
    int dist[100]{};
    int previous[100]{};
    int v{};
    int src{};
public:
    DijkstraAlg()=default;
    ~DijkstraAlg() = default;
    void init()
    {
        ifstream graph;
        graph.open(R"(C:\Users\kasia\CLionProjects\DijkstraGrafy\Graph.txt)"); /// TODO: zmienić ścieżkę w nawiasie
        if (!graph)
            exit(1);
        graph >> v;

        for (int i = 0; i < v; ++i)
        {
            for (int j = 0; j < v; ++j)
            {
                graph>>cost[i][j];
            }
        }
        graph>>src;

        for (int i = 0; i < v; ++i)
        {
            previous[i] = i;
            dist[i] = INF;
        }
        dist[src] = 0;
        graph.close();
    }

    int getNearestNode() {
        int minValue = INF;
        int minNode = 0;
        for(int i = 0; i < v; ++i)
        {
            if (dist[i] < minValue && !visited[i])
            {
                minValue = dist[i];
                minNode = i;
            }
        }
        return minNode;
    }

    void dijkstra()
    {
        for(int i=0; i < v + 1; ++i)
        {
            int nearest = getNearestNode();
            visited[nearest] = true;
            for (int k = 0; k < v; ++k) {
                if (cost[nearest][k] != INF && dist[k] > dist[nearest] + cost[nearest][k])
                {
                    dist[k] = dist[nearest] + cost[nearest][k];
                    previous[k] = nearest;
                }
            }
        }
    }

    void display()
    {
        cout<<"Source node: "<<src<<endl;
        cout<<"Node: \t\t\tCost: \t\t\tPath:\n";
        for (int i=0; i<v; ++i)
        {
            if (dist[i]==INF)
                dist[i] = -1;
            cout<<i<<"\t\t\t"<<dist[i]<<"\t\t\t"<<" "<<i<<" ";
            while (previous[i] != src)
            {
                cout<<" <- "<<previous[i]<<" ";
                if (previous[i] == previous[previous[i]])
                    break;
                else
                    previous[i] = previous[previous[i]];
            }
            cout<<endl;
        }
    }

};

int main()
{
    DijkstraAlg dijkstraAlg;
    dijkstraAlg.init();
    dijkstraAlg.dijkstra();
    dijkstraAlg.display();
}
