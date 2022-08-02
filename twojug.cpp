int minSteps(int m, int n, int d)
	{
	    
	   // if(m==d or n == d) return 0;
        vector<vector<int>>vis(m+1,vector<int>(n+1,0));
	    bool found = false;
	    queue<pair<int,int>>q;
	    q.push({0,0});
	    int ans = 0;
	    while(!q.empty()){
// cout<<a<<endl;
// a++;
	        int s = q.size();
            // cout<<"Size of queue: "<<s<<endl;
	        while(s--){
	            int j1 = q.front().first;
	        int j2 = q.front().second;
            // cout<<"{"<<j1<<" ,"<<j2<<"}"<<endl;
	        q.pop();
            // if(j1 > n+1 or j2 > m+1) cout<<"This is the problem";
            if(vis[j2][j1]) continue;
            vis[j2][j1] = 1;
            // cout<<"Hi"<<endl;
	        if(j1 == d or j2 == d){found = true;break;};
	       // empty j1
	        if(j1 !=0 ) q.push({0,j2});
	       // empty j2
	        if(j2 !=0 ) q.push({j1,0});
	       // fill j1
	        if(j1 == 0 ) q.push({n,j2});
	       // fill j2 
	       if(j2 == 0 ) q.push({j1,m});
	    //    cout<<"pour from j1 to j2 "<<endl;
	       if(j2 != m and (j1+j2 != 0)){
	           if(j2+j1<=m) q.push({0,j1+j2});
	           else q.push({j1-(m-j2),m});
	       }
	       //pour from j2 to j1
	       if(j1 != n and (j1+j2 != 0)){
	           if(j2+j1<=n) q.push({j1+j2,0});
	           else q.push({n,j2-(n-j1)});
	       }
	        }
            
	        if(found)break;
            
	       ans++;
	        
	    }
        // cout<<"Out of loop:";
	    if(found)return ans;
	    return -1;
	}
