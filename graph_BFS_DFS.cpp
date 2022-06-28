#include <bits/stdc++.h>

using namespace std;

void bfs(vector<int> g[], vector<int>&ans,int *vis,int node){
    queue<int>q;
    q.push(node);
    vis[node] = 1;
    while (!q.empty())
    {
        int n = q.front();
        q.pop();        
        ans.push_back(n);
        for(auto it: g[n]){
            if(!vis[it]){
                vis[it] = 1;
                q.push(it);
            }
        }
    }
    
}

void dfs(vector<int> g[], vector<int>&ans,int *vis,int node){
    vis[node] = 1;
    cout<<"Node: "<<node<<endl;
    for(auto it: g[node]){
        if(!vis[it]){
            dfs(g,ans,vis,it);
        }
    }
    ans.push_back(node);
}

int main(){
    int v,e;
    cout<<"Enter vertices and edges: \n";
    cin >> v >> e;
    vector<int> g[v+1];
    for(int i=0;i<e;i++)
   {
       int a,b;
       cin >> a >> b;
       g[a].push_back(b);
       g[b].push_back(a);
   }
//    for(int i=1;i<=v;i++){
//        for(auto it:g[i])
//         cout<<it<<" ";
//         cout<<"\n";
//    }
   vector<int> ans;
   int vis[v+1] = {0};
    for(int i=1;i<=v;i++){
        if(!vis[i])
            // dfs(g,ans,vis,i);
            bfs(g,ans,vis,i);
    }
   for(auto it: ans)
        cout<<it<<" ";
   
}