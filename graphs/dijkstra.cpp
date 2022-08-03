#include <iostream>
#include <array>
#include <queue>

constexpr int NN = 6;

int graph[NN][NN] = {{0, 6, 4, 0, 0, 0},
                     {6, 0, 1, 5, 0, 0},
                     {4, 1, 0, 7, 0, 0},
                     {0, 5, 7, 0, 7, 10},
                     {0, 0, 0, 7, 0, 2},
                     {0, 0, 0, 10, 2, 0}};

struct QueueItem
{
    int dist;
    int idx;
};
auto cmp = [](QueueItem left, QueueItem right)
{ return left.dist > right.dist; };

std::array<int, NN> dijkstra(int start)
{
    std::priority_queue<QueueItem, std::vector<QueueItem>, decltype(cmp)> queue(cmp);
    std::array<int, NN> dist;
    for (auto &val : dist)
    {
        val = INT32_MAX;
    }
    std::array<bool, NN> marked;
    for (auto &val : marked)
    {
        val = false;
    }

    dist[start] = 0;
    queue.push({0, start});
    while (queue.size() > 0)
    {
        auto current = queue.top();
        queue.pop();
        if (marked[current.idx] == true)
            continue;

        marked[current.idx] = true;
        for (int ii = 0; ii < NN; ii++)
        {
            if (graph[current.idx][ii] > 0 && marked[ii] == false) // have connection and not visited
            {
                if (dist[ii] > dist[current.idx] + graph[current.idx][ii])
                {
                    dist[ii] = dist[current.idx] + graph[current.idx][ii];
                    queue.push({dist[ii], ii});
                }
            }
        }
    }

    return dist;
}

int main()
{
    auto dists = dijkstra(0);
    for (int ii = 0; ii < NN; ii++)
    {
        std::cout << ii << " " << dists[ii] << "\n";
    }

    return 0;
}
