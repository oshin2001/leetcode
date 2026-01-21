struct ST{
    ST(){}
    int n;
    vector<pair<int,int>> st;
    ST(vector<int>& arr){
        n = arr.size();
        st.resize(4*n);
        build(0,0,n-1,arr);
    }
    void build(int node,int l ,int r, vector<int>& arr){
        if(l == r){
            st[node] = {arr[l],1};
            return;
        }
        int mid = (r+l)/2;
        build(2*node+1,l,mid,arr);
        build(2*node+2,mid+1,r,arr);
        auto [le,lf] = st[2*node+1];
        auto [re,rf] = st[2*node+2];
        if(le == re){
            st[node] = {le , lf + rf};
            return;
        }
        if(lf > rf){
            st[node] = {le,lf-rf};
        }else{
            st[node] = {re,rf-lf};
        }
    }
    pair<int,int> query(int node,int l ,int r, int ql ,int qr){
        if(r < ql or l > qr){
            return {-1,0};
        }
        if(ql <= l and r <= qr){
            return st[node];
        }
        int mid = (r+l)/2;
        auto [le,lf] = query(2*node+1,l,mid,ql,qr);
        auto [re,rf] = query(2*node+2,mid+1,r,ql,qr);
        if(le == re){
            return {le , lf + rf};
        }
        if(lf > rf){
            return {le,lf-rf};
        }else{
            return {re,rf-lf};
        }
    }
};
class MajorityChecker {
public:
    unordered_map<int,vector<int>> mp;
    ST st;
    int n;
    MajorityChecker(vector<int>& arr) {
        n = arr.size();
        st = ST(arr);
        for(int i = 0; i < n ; i++){
            mp[arr[i]].push_back(i);
        }
    }
    
    int query(int left, int right, int threshold) {
        auto [e,f] = st.query(0,0,n-1,left,right);
        if(e == -1) return -1;
        auto temp = freq(left,right,e);
        return temp >= threshold ? e : -1;
    }

    int freq(int l ,int r, int x){
        if(mp.count(x) == 0) return 0;
        auto it1 = ranges::lower_bound(mp[x],l);
        auto it2 = ranges::upper_bound(mp[x],r);
        return distance(it1,it2);
    }
};

/**
 * Your MajorityChecker object will be instantiated and called as such:
 * MajorityChecker* obj = new MajorityChecker(arr);
 * int param_1 = obj->query(left,right,threshold);
 */

/**
 * Your MajorityChecker object will be instantiated and called as such:
 * MajorityChecker* obj = new MajorityChecker(arr);
 * int param_1 = obj->query(left,right,threshold);
 */