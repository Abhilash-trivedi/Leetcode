class Solution {
public:
    map<string,priority_queue <string, vector<string>, greater<string>>>q;
    vector<string>ans;
    void dfs(string from)
    {
        auto point=q.find(from);
        if(point!=q.end())
        {priority_queue <string, vector<string>, greater<string>> destination=point->second;
        
            while(!point->second.empty())
                { 
                    
       
                     
                    string a=point->second.top();
                    point->second.pop();
                    dfs(a);      
                }
        }
        ans.push_back(from);
        
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
       
        int n=tickets.size();
        int m=tickets[0].size();
        for(int i=0;i<n;i++)
            {
                
                    string from=tickets[i][0];
                    string to=tickets[i][1];
                    auto point=q.find(from);
                    
                    if(point!=q.end())
                    {
                        point->second.push(to);
                    }
                    else
                    {
                        priority_queue <string, vector<string>, greater<string>>v;
                        
                        v.push(to);
                        //cout<<v.top();
                        q.insert({from,v});
                    }
                
            }
            // for(auto i:q)
            // {
            //     cout<<i.first<<": ";
            //     while(!i.second.empty())
            //     {
            //         cout<<i.second.top()<<" ";
            //         i.second.pop();
            //     }
            //     cout<<endl;
            // }
        
            dfs("JFK");
            int sz=ans.size();
            for(int i=0;i<sz/2;i++)
            {
                swap(ans[i],ans[sz-1-i]);
            }
         return ans;   
            
    }
};