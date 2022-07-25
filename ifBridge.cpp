void dfs(vector<int> adj[],int c,int d,vector<int> &dis,vector<int> &low,int node,int parent,int&ans){
	    static int timer = 0;
	    low[node] = dis[node] = timer;
	    timer++;
	    for(auto it: adj[node]){
	        if(dis[it] == -1){
	            dfs(adj,c,d,dis,low,it,node,ans);
	            low[node] = min(low[node],low[it]);
	            if(low[it] > dis[node])
	            {
	                if( (c==it || c==node) and (d==it || d==node) )
	                    ans = 1;
	            }
	        }
	        else if(it!=parent){
	            low[node] = min(low[node],dis[it]);
	        }
	    }
	}
	
    //Function to find if the given edge is a bridge in graph.
    int isBridge(int V, vector<int> adj[], int c, int d) 
    {
        int ans=0;
        vector<int>dis(V,-1),low(V,-1);
        for(int i=0;i<V;i++)
            if(dis[i] == -1) 
                dfs(adj,c,d,dis,low,i,-1,ans);
        return ans;
    }
