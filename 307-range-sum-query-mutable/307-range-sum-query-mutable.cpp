class NumArray {
public:
    
    vector<int> st;
    int n;
    void build(int si,int ss,int se,vector<int> &nums){
        if(ss==se){
            st[si] = nums[ss];
            return;
        }
        int mid = (ss+se)/2;
        
        build(2*si+1,ss,mid,nums);
        build(2*si+2,mid+1,se,nums);
        st[si] = st[2*si+1]+st[2*si+2];
    }
    
    void pointUpdate(int si,int ss,int se,int ind,int val){
        if(ss==se){
            st[si] = val;
            return;
        }
        int mid = (ss+se)/2;
        if(ind<=mid)
            pointUpdate(2*si+1,ss,mid,ind,val);
        else
             pointUpdate(2*si+2,mid+1,se,ind,val);
         st[si] = st[2*si+1]+st[2*si+2];
        
    }
    
    int query(int si,int ss, int se,int l,int r){
        if(ss>r || se<l)
            return 0;
        if(ss>=l && se<=r)
            return st[si];
        int mid = (ss+se)/2;
        return query(2*si+1,ss,mid,l,r)+query(2*si+2,mid+1,se,l,r);
        
    }
    NumArray(vector<int>& nums) {
        n = nums.size();
        st.resize(4*n+1,0);
        build(0,0,n-1,nums);
        
    }
    
    void update(int index, int val) {
        
        pointUpdate(0,0,n-1,index,val);
        
    }
    
    int sumRange(int left, int right) {
        return query(0,0,n-1,left,right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */