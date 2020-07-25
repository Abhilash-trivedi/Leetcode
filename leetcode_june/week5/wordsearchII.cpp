class Solution {

		struct node
		{
			char data;
		    node* child[26];
			string word;
			int end;
		};
		struct node *new_node(char c)
		{
			node *newnode = new node;
			newnode->data=c;
			newnode->end=0;
			newnode->word="";
			for(int i=0; i<26; i++)
			{
				newnode->child[i]=NULL;
			}
			return newnode;

		}
		node *root=new_node('/');

			void insert(string s)		
			{
				node *curr=root;
				int index,i=0;
				while(s[i])
				{
					index=s[i]-'a';
					if(curr->child[index]==NULL)
					{
						curr->child[index]=new_node(s[i]);
					}
                    
					curr=curr->child[index];
					i++;
				}
				curr->end+=1;
				curr->word=s;
			}

		void solve(vector<vector<char>>& board, int i,int j,int r,int c,vector<string>& ans,node * curr)
		{
			int index=board[i][j]-'a';
			if(board[i][j]=='$'||curr->child[index]==NULL)
			{
				return;
			}
			curr=curr->child[index];

			if(curr->end>0)
			{
				ans.push_back(curr->word);
				curr->end-=1;
			}

			char ch=board[i][j];
			board[i][j]='$';
			if(i>0)
			{
				solve(board,i-1,j,r,c,ans,curr);
			}
			if(i<r-1)
			{
				solve(board,i+1,j,r,c,ans,curr);
			}
			if(j>0)
			{
				solve(board,i,j-1,r,c,ans,curr);
			}
			if(j<c-1)
			{
				solve(board,i,j+1,r,c,ans,curr);
			}

			board[i][j]=ch;
		}
public:
	
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) 
    {
        int r=board.size();
        int c=board[0].size();
        for (int i = 0; i < words.size(); ++i)
        {
        	insert(words[i]);
        }
        std::vector<string> ans;

        for(int i=0;i<r;i++)
        {
        	for(int j=0;j<c;j++)
        	{
        		solve(board,i,j,r,c,ans,root);
        	}
        }
        return ans;
        
    }
};