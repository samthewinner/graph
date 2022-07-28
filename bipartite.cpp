 bool dfs(vector<int>adj[],vector<int>&color,int node){
         if(color[node] == -1)color[node] = 1;
        for(auto it:adj[node]){
            if(color[it] == -1){
                color[it] = 1 - color[node];
                if(dfs(adj,color,it))
                    return true;
                if(color[it] == color[node]) return true;
            }
            else if(color[it] == color[node]) return true;
        }
        return false;
    }

	bool isBipartite(int V, vector<int>adj[]){
	    vector<int>color(V,-1);
	    for(int i=0;i<V;i++){
	        if(color[i] == -1){
	            if(dfs(adj,color,i)) return false;
	        }
	            
	    }
	    return true;
	}
