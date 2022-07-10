void dfs(int *vis,vector<int> adj[],stack<int> &s,int node){
	    vis[node] = 1;
	    for(auto it: adj[node]){
	        if(!vis[it])
	            dfs(vis,adj,s,it);
	    }
	    s.push(node);
	    return;
	}
	
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    stack<int>s;
	    int vis[V] = {0};
	    for(int i=0;i<V;i++){
	        if(!vis[i]) 
	            dfs(vis,adj,s,i);
	    }
	    vector<int>ans;
	    while(!s.empty()){
	        ans.push_back(s.top());
	        s.pop();
	    }
	    return ans;
	}
