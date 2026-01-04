class Solution {
public:
    void update(vector<int>& tree,int i,int val) {
        while(i<tree.size()) {
            tree[i]+=val;
            i+=(i&(-i));
        }
    }
    
    int getSum(vector<int>& tree,int i) {
        int s = 0;
        while(i>0) {
            s+=tree[i];
            i-=(i&(-i));
        }
        return s;
    }
    
    vector<int> processQueries(vector<int>& queries, int m) {
        vector<int> res,tree((2*m)+1,0);
        unordered_map<int,int> hmap;
        for(int i=1;i<=m;++i) {
            hmap[i] = i+m;
            update(tree,i+m,1);
        }

        for(int querie : queries) {
            res.push_back(getSum(tree,hmap[querie])-1);
            update(tree,hmap[querie],-1);
            update(tree,m,1);
            hmap[querie] = m;
            m--;
        }  
        return res;     
    }
};