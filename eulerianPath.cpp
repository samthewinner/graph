void dfs(vector<int>adj[],set<pair<int,int>>&s,vector<int>&vis,int node,int &last){
    last = node;
    vis[node]  = 1;
    // cout<<last<<endl;
    // if(node==0 and s.size()!=0) ans = 2;
    // s.insert(make_pair())
    for(auto it:adj[node]){
        if(s.count({node,it}) or s.count({it,node})) continue;
        s.insert(make_pair(node,it));
        dfs(adj,s,vis,it,last);
    }
}

	int isEularCircuit(int V, vector<int>adj[]){
	   
	   //// int vis[V] = {};
	//    cout<<"F"<<endl;
	   int count =0 ;
       int tot = 0;
	    for(int i=0;i<V;i++){
            tot+=adj[i].size();
	        if(adj[i].size()%2) count++;
	        
	    }                
	    if(count>2) return 0;
	    set<pair<int,int>>s;
        int last = 1;
        // int * vis[V] = {};
        vector<int>vis(V,0);
	    for(int i=0;i<V;i++) if(!vis[i]) dfs(adj,s,vis,i,last);
        // cout<<s.size()<<endl;
        if(last == 0) return 2;
        return 1;	    
	}
