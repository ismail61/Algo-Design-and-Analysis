#include<bits/stdc++.h>
using namespace std;
#define V 6
bool bfs(int rgraph[V][V],int s,int t,int parent[V]){
    bool visited[V];
    memset(visited,0,sizeof(visited));
    queue<int>q;
    q.push(s);
    visited[s]=true;
    parent[s]=-1;
    while(!q.empty()){
        int u = q.front();
        q.pop();

        for(int v=0;v<V;v++){
            if(visited[v]==false && rgraph[u][v]>0){
                q.push(v);
                parent[v]=u;
                visited[v]=true;
            }
        }
    }
    return (visited[t] == true);
}
int fordFulkerson(int graph[V][V],int s,int t){
    int rgraph[V][V];//residual graph
    int u,v;
    for(u=0;u<V;u++){
        for(v=0;v<V;v++){
            rgraph[u][v]=graph[u][v];
        }
    }
    int parent[V];
    int max_flow = 0;
    while(bfs(rgraph,s,t,parent)){
        int path_flow = INT_MAX;
        for(int v=t;v!=s;v=parent[v]){
            int u=parent[v];
            path_flow = min(path_flow,rgraph[u][v]);
        }
        cout<<path_flow<<" : ";
        for(v=t;v!=s;v=parent[v]){
            u=parent[v];
            rgraph[u][v] -= path_flow;
            rgraph[v][u] += path_flow;
        }
        max_flow += path_flow;
    }
    return max_flow;
}
int main()
{
    int edges,graph[V][V];
    memset(graph,0,sizeof(graph));
    cin>>edges;
    while(edges--)
    {
        int u,v,w;
        cin>>u>>v>>w;
        graph[u][v]=w;
    }
    cout << "The maximum possible flow is " << fordFulkerson(graph, 0, 5);
    return 0;

}
/*
9
0 1 10
0 2 10
1 3 4
1 2 2
1 4 8
2 4 9
3 5 10
4 3 6
4 5 10
*/
