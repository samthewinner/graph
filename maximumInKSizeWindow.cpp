vector<int> max_of_subarrays(vector<int> arr, int n, int k) {
        list<int>q;
        if(k==1 || n==1) return arr;
        int l,r;l=r=0;
        vector<int> ans;
        while(r<n){
             while(!q.empty() and arr[q.back()]<= arr[r])q.pop_back();
            q.push_back(r);
            if(r<k-1)r++;
            else{
                ans.emplace_back(arr[q.front()]);
                if(q.front() == l) q.pop_front();
                l++;r++;
            }
        }
        return ans;
    }
