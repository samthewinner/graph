//do a dfs traversal on the graph.
// Maintain a parent node.
// If the adjecent node is visited and is not a parent, then it can be concluded that the graph contains a cycle.
// if adjacent node is visited and is a parent , then do nothing
// if the adjacent node is not visited, then call the dfs

bool dfs(vector<int> adj[],int *vis,int node , int parent){
        vis[node] = 1;
        for(auto it : adj[node]){
            if(!vis[it]){
                if(dfs(adj,vis,it,node)) return true;
            }
            else if(vis[it] and parent!=it) return true;
        }
        return false;
    }
    
    bool isCycle(int V, vector<int> adj[]) {
        int vis[V]={};
        for(int i=0;i<V;i++){
            if(!vis[i])
                if(dfs(adj,vis,i,INT_MIN)) return true;
        }
        return false;
    }
