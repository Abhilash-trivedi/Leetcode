class Solution {
public:
    static bool comp(vector<int> v1,vector<int> v2) {
        
        cout<<v1[0]<<" "<<v1[1]<<" : "<<v2[0]<<" "<<v2[1]<<endl;
    if(v1[0] == v2[0]) return v1[1]<v2[1];
    else return v1[0]>v2[0];
}
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        vector<vector<int>>ans;
        int n=people.size();
        if(n==0)return ans;
        sort(people.begin(),people.end(),comp);
        for(int i=0;i<n;i++)
        {
             ans.insert(ans.begin()+people[i][1],{people[i][0],people[i][1]});
        }
        return ans;
    }
};