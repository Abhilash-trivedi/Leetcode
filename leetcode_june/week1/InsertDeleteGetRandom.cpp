class RandomizedSet {
    vector<int>v;
    
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        int n=v.size();
        for(int i=0;i<n;i++)
        {
            if(v[i]==val)return false;
        }
        v.push_back(val); return true;
    }
    
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        int n=v.size();
        for(int i=0;i<n;i++)
        {
            if(v[i]==val)
            {
                v.erase(v.begin()+i);
                return true;
            }
        }
        return false;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        
       int c=(rand()%v.size());
        return v[c];
        
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */