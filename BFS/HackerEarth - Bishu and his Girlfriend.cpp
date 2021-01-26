#include<bits/stdc++.h>
#define Max 1001
std::vector<int>graph[Max];
std::bitset<Max>visit;
int distance[Max];
void reset()
{
	for (int i = 0; i < Max; i++)
	{
		graph[i].clear();
	}
}

void bfs(int node, int dis)
{
	visit[node] = true;
	distance[node] = dis;
	std::queue < int>q;
	q.push(node);
	while (!q.empty())
	{
		int first = q.front();
		q.pop();
		for (auto nod : graph[first])
		{
			if (visit[nod] == 0)
			{
				visit[nod] = true;
				distance[nod] = distance[first] + 1;
				q.push(nod);
			}
		}
	}
}


int main()
{
	int nodes;
	while (std::cin >> nodes)
	{
		memset(distance, INT_MAX, sizeof(distance));
		int edges = nodes - 1;
		for (int i = 0; i < edges; i++)
		{
			int u, v;
			std::cin >> u >> v;
			graph[u].push_back(v);
			graph[v].push_back(u);
		}
		bfs(1, 0);

		int q;
		std::cin >> q;
		int shortdistance = INT_MAX, check = INT_MAX;
		for (int i = 1; i <= q; i++)
		{
			int temp;
			std::cin >> temp;

			if (distance[temp] <= shortdistance && temp < check)
			{
				shortdistance = distance[temp];
				check = temp;
			}
			std::cout << "Nodes " << i << ":" << distance[i] << '\n';
		}
		std::cout << check << '\n';
		visit.reset();
		reset();
	}
}