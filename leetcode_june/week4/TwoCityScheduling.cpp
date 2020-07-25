class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& v) {
        multimap<int,int>m;
        int n=v.size();
        cout<<n<<endl;
        for(int i=0;i<n;i++)
        {
            int diff=(v[i][0]-v[i][1]);
            
            m.insert({abs(diff),i});
        }
        for(auto i:m)
        {
            cout<<i.first<<" "<<i.second<<endl;
        }
        int t[n];memset(t,0,sizeof(t));
        auto p=m.rbegin();
        int sum=0;
        int c1=0,c2=0;
       
       // cout<<p->first<<" "<<v[p->second][0]<<" "<<v[p->second][1]<<endl;
         for(int i=0;i<n;i++)
         {
            if(v[p->second][0]<v[p->second][1])
            {
               
                
                if(c1<n/2)
                {
                     cout<<"1 "<<v[p->second][0]<<" "<<v[p->second][1]<<endl;
                    sum+=v[p->second][0];
                    c1++;
                }
                else
                {
                     cout<<"2  "<<v[p->second][0]<<" "<<v[p->second][1]<<endl;
                    sum+=v[p->second][1];
                    c2++;
                }
            }
             else
             {
                 if(c2<n/2)
                {
                     cout<<"2 "<<v[p->second][0]<<" "<<v[p->second][1]<<endl;
                    sum+=v[p->second][1];
                     c2++;
                }
                else
                {
                    cout<<"1  "<<v[p->second][0]<<" "<<v[p->second][1]<<endl;
                    sum+=v[p->second][0];
                    c1++;
                }
             }
             p++;
         }
        return sum;
        
    }
};