int find(vector<int>&p,int x){
	    if(p[x]!=x) p[x] = find(p,p[x]);
	    return p[x];
	}
	
	void unionn(vector<int>&p,vector<int>&rank,int a,int b){
	    int x = find(p,a);
	    int y = find(p,b);
	    if(x == y) return;
	    if(rank[x] > rank[y])
	        p[y] = x;
        if(rank[y] > rank[x])
	        p[x] = y;
        else{
            rank[x]++;
            p[y] = x;
        }	        
        return;
	}
