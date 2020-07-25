class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector<int> prev(n+1,INT_MAX);
        prev[src]=0;
        for(int i=0;i<=K;i++){
            vector<int> curr(prev);
            
            for(int i=0;i<flights.size();i++){
                int s = flights[i][0];
                int d = flights[i][1];
                int w = flights[i][2];
                if(prev[s]!=INT_MAX && (prev[s]+w)<curr[d])
                {
                    curr[d] = prev[s]+w;
                }                                
            }
            prev=curr;
        }
        if(prev[dst]==INT_MAX) return -1;
        return prev[dst];
    }
};