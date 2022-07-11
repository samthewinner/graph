 bool dfs(vector<int>adj[],int*vis,int*dfsvis,int node){
        vis[node] = dfsvis[node] = 1;
        for(auto it: adj[node]){
            if(vis[it] and dfsvis[it]) return true;
            if(!vis[it]) if(dfs(adj,vis,dfsvis,it)) return true;
        }
        dfsvis[node] = 0;
        return false;
    }
    
    bool isCycle(vector<int>adj[],int n){
        int vis[n] = {};
        int dfsvis[n] = {};
        for(int i=0;i<n;i++){
            if(!vis[i]){
                
                if(dfs(adj,vis,dfsvis,i)) return true;
            }
        }return false;
    }

    
	bool isPossible(int N, vector<pair<int, int> >& pre) {
	    vector<int>adj[N];
	    for(int i=0;i<pre.size();i++){
	        adj[pre[i].first].push_back(pre[i].second);
	    }
	    return !(isCycle(adj,N));
	}
