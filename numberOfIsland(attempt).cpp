bool isValid(vector<vector<char>>&g, int n,int m,int x,int y){
    if (x>=0 and x<n and y>=0 and y<m and g[x][y] == '1') return true;
    return false;
}

void bfs(vector<vector<char>>& g,int n,int m,int i,int j){
    queue<pair<int,int>>q;
    q.push({i,j});
    int dx[8] = {-1,-1,-1,0,0,1,1,1,};
    int dy[8] = {-1,0,1,-1,1,-1,0,1};
    while(!q.empty()){
        auto p = q.front();q.pop();
        int x = p.first;
        int y = p.second;
        g[x][y] = '0';
        for(int k =0;k<8;k++){
            int nx = x + dx[k];
            int ny = y + dy[k];
            if(isValid(g,n,m,nx,ny)) {q.push({nx,ny});}
        }
    }
}

// int countIslands(int g[][COL], int n, int m) {
//     int ans = 0;
//     // vector<vector<int>>g(n,vector<int> (m,0));
//     // for(int i=0;i<n;i++){
//     //     for(int j=0;j<m;j++){
//     //         g[i][j] = graph[i][j];
//     //     }
//     // }
//     for(int i=0;i<n;i++){
//         for(int j=0;j<m;j++){
//             if(g[i][j] == 1){
//                 ans++;
//                 bfs((int*)g,n,m,i,j);
//             }
//         }
//     }
//     return ans;
// }
    
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        int n = grid.size();
        int m = grid[0].size();
        for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j] == '1'){
                ans++;
                bfs(grid,n,m,i,j);
            }
        }
    }
    return ans;
    }
