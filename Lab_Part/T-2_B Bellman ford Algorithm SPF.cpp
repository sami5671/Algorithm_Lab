#include <iostream>
#include <vector>
#include <limits>

struct Edge
{
    int source, destination, weight;
};

void bellmanFord(const std::vector<Edge> &edges, int numVertices, int source)
{
    std::vector<int> distances(numVertices, std::numeric_limits<int>::max());
    distances[source] = 0;

    for (int i = 1; i < numVertices - 1; ++i)
    {
        for (const auto &edge : edges)
        {
            int u = edge.source;
            int v = edge.destination;
            int weight = edge.weight;
            if (distances[u] != std::numeric_limits<int>::max() && distances[u] + weight < distances[v])
            {
                distances[v] = distances[u] + weight;
            }
            if (distances[v] != std::numeric_limits<int>::max() && distances[v] + weight < distances[u])
            {
                distances[u] = distances[v] + weight;
            }
        }
    }

    std::cout << "Vertex\tDistance from Source\n";
    for (int i = 0; i < numVertices; ++i)
    {
        std::cout << i << "\t" << distances[i] << "\n";
    }
}

int main()
{
    int numVertices, numEdges, source;
    std::cout << "Enter the number of vertices: ";
    std::cin >> numVertices;
    std::cout << "Enter the number of edges: ";
    std::cin >> numEdges;

    std::vector<Edge> edges(numEdges);

    std::cout << "Enter the source vertex: ";
    std::cin >> source;

    std::cout << "Enter the edges (source, destination, weight):\n";
    for (int i = 0; i < numEdges; ++i)
    {
        std::cin >> edges[i].source >> edges[i].destination >> edges[i].weight;
    }

    bellmanFord(edges, numVertices, source);

    return 0;
}