/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

void dfs(int node,vector<int>adj[],vector<int>&visited,vector<int>&ans) //recursive code for depth first search
{
    for(auto it:adj[node])
    {
        if(!visited[it])
        {
            ans.push_back(it);
            visited[it]=1;
            dfs(it,adj,visited,ans);
        }
    }
    return;
}

void bfs(int node,vector<int>adj[]) //breadth-first-search traversal
{
    vector<int>ans;
    vector<int>visited(node+1,0);
    visited[1]=1;
    queue<int>q;
    q.push(1);
    while(!q.empty())
    {
        int top=q.front();
        q.pop();
        ans.push_back(top);
        for(auto it:adj[top]){
            if(!visited[it])
            {
                q.push(it);
                visited[it]=1;
            }
        }
    }
    for(auto it:ans)
{
    cout<<it<<" ";
}
    return ;
}

int main()
{
 int node;
 int edges;
 cin>>node>>edges;
 vector<int>adj[node+1];
 
for(int i=0;i<edges;i++) //storing edges of a undirected graph
{
    int u,v;
    cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
}
for(auto it:adj)
{
    for(auto it1 :it)
    cout<<it1<<" ";
    cout<<endl;
}

//bfs(node,adj);

//depth first search

vector<int>visited(node+1,0);
visited[1]=1;
vector<int>ans;
ans.push_back(1);
dfs(1,adj,visited,ans);
for(auto it:ans)
cout<<it<<" ";

    return 0;
}
