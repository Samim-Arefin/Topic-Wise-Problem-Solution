#include<bits/stdc++.h>
#define Max 10001
std::vector<int> graph[Max];
std::bitset<Max>visit;
int distance[Max];

void reset()
{
	for (int i = 0; i < Max; i++)
	{
		graph[i].clear();
	}
}

void bfs(int source, int dis)
{
	visit[source] = true;
	distance[source] = dis;
	std::queue < int>q;
	q.push(source);
	while (!q.empty())
	{
		int first = q.front();
		q.pop();
		for (auto node : graph[first])
		{
			if (visit[node] == 0)
			{
				visit[node] = true;
				distance[node] = distance[first] + 1;
				q.push(node);
			}
		}
	}
}

int main()
{
	int test;
	std::cin >> test;
	while (test--)
	{
		memset(distance, INT_MAX, sizeof(distance));
		int nodes, edges;
		std::cin >> nodes >> edges;
		for (int i = 0; i < edges; i++)
		{
			int u, v;
			std::cin >> u >> v;
			graph[u].push_back(v);
			graph[v].push_back(u);
		}
		bfs(1, 0);

		std::cout << distance[nodes] << '\n';
		visit.reset();
		reset();
	}
}