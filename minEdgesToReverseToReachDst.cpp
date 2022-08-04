#include <bits/stdc++.h>

using namespace std;

int reverseMin(int e,int v,int src,int dst,vector<int>edges){
    vector<pair<int,int>>adj[v];
    for(int i=0;i<edges.size();i+=2){
        int u = edges[i];
        int v = edges[i+1];
        adj[u].push_back({v,0});
        adj[v].push_back({u,1});
    }
    // for(int i=0;i<v;i++){
    //     for(auto it:adj[i]){
    //         cout<<" ;"<<i<<" "<<it.first<<" "<<it.second;
    //     }
    //     cout<<endl;
    // }

// ;0 1 0
//  ;1 0 1 ;1 2 1 ;1 5 1
//  ;2 1 0 ;2 3 0
//  ;3 2 1 ;3 6 1
//  ;4 6 1 ;4 5 0
//  ;5 4 1 ;5 1 0
//  ;6 3 0 ;6 4 0

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    vector<int> dist(v,INT_MAX);
    dist[src]  = 0;
    pq.push(make_pair(0,src));
    while(!pq.empty()){
        auto n = pq.top();
        pq.pop();
        int node = n.second;
        // cout<<"Node: "<<node<<endl;
        for(auto it:adj[node]){
            int v = it.first;
            int w = it.second;
            // cout<<" "<<v<<" "<<w<<endl;
            // cout<<dist[node]<<endl;
            if(dist[v]> w+dist[node]){                
                dist[v] = w + dist[node];
                pq.push(make_pair(dist[v],v));
            }
        }        
    }
    if(dist[dst] == INT_MAX) return -1;
    return dist[dst];
}

int main(){
   int e,v,src,dst;
   cin>>v>>e>>src>>dst;
   vector<int>edges(2*e);
   for(int i=0;i<2*e;i++)
        cin>>edges[i];
   cout<<reverseMin(e,v,src,dst,edges);

}
