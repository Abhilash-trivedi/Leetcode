class Solution {
public:
    bool isSafe(int x,int y,int n,int m)
    {
        return (x>=0&&x<n&&y>=0&&y<m);
    }
    void change(vector<vector<char>>& board,int m,vector<vector<bool>>& val,int x1,int y1,int n)
    {
        queue<pair<int,int>>q;
        q.push({x1,y1});
        val[x1][y1]=1;
        //cout<<x<<" "<<y<<endl;
        while(!q.empty())
        {
            pair<int,int>r=q.front();
            int x=r.first,y=r.second;
            //cout<<x<<" "<<y<<endl;
            
            q.pop();
            if(isSafe(x+1,y,n,m)&&board[x+1][y]=='O'&&val[x+1][y]==0)
            {
                val[x+1][y]=1;
                q.push({x+1,y});
            }
            if(isSafe(x,y+1,n,m)&&board[x][y+1]=='O'&&val[x][y+1]==0)
            {
                val[x][y+1]=1;
                q.push({x,y+1});
            }
            if(isSafe(x-1,y,n,m)&&board[x-1][y]=='O'&&val[x-1][y]==0)
            {
                val[x-1][y]=1;
                q.push({x-1,y});
            }
            if(isSafe(x,y-1,n,m)&&board[x][y-1]=='O'&&val[x][y-1]==0)
            {
                val[x][y-1]=1;
                q.push({x,y-1});
            }
        }
    }
    void solve(vector<vector<char>>& board) 
    {
        int n=board.size();
        if(n==0)return;
        int m=board[0].size();
        
        vector<vector<bool>>val(n);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                
                val[i].push_back(0);
            }
        }
       
        
        for(int i=0;i<n;i++)
        {
            if(board[i][0]=='O'&&val[i][0]==0)
            {int x=i,y=0;
                change(board,m,val,x,y,n);
            }
            if(board[i][m-1]=='O'&&val[i][m-1]==0)
            {int x=i,y=m-1;
                change(board,m,val,x,y,n);
            }
        }
       for(int i=0;i<m;i++)
        {
            if(board[0][i]=='O'&&val[0][i]==0)
            {int x=0,y=i;
                change(board,m,val,x,y,n);
            }
            
            if(board[n-1][i]=='O'&&val[n-1][i]==0)
            {int x=n-1,y=i;
             //cout<<"@";
                change(board,m,val,x,y,n);
            }
        }
       for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cout<<val[i][j]<<" ";
                if(val[i][j]==1)
                {
                    board[i][j]='O';
                }
                else
                {
                    board[i][j]='X';
                }
            }
           cout<<endl;
        }
    }
};