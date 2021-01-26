
#include<bits/stdc++.h>
#define Max 101
std::vector<int> graph[Max];
std::bitset<Max> visit;

void reset()
{
    for(int i=0;i<Max;i++)
    {
        graph[i].clear();
    }
}

void dfs(int source)
{
    visit[source]=true;

    for(auto child:graph[source])
    {
        if(visit[child]==false)
        {
            dfs(child);
        }
    }

}


int main()
{
    int nodes,edges;
    while(std::cin>>nodes>>edges)
    {
        for(int i=0;i<edges;i++)
        {
            int u,v;
            std::cin>>u>>v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        int count=0;
        for(int i=1;i<=nodes;i++)
        {
            if(visit[i]==0)
            {
                count++;
                dfs(i);
            }
        }
        std::cout<<count<<'\n';


        visit.reset();
        reset();
    }
}

