class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int l=0,r=1;
        int n=nums.size();
        if(n<3) return 0;
        int diff=nums[r]-nums[r-1];
        r++;
        int count=0;
        while(r<n){
            if(nums[r]-nums[r-1]==diff){
                if(r-l+1>=3){
                    count+=(r-l-1);
                }
            }else{
                diff=nums[r]-nums[r-1];
                l=r-1;
            }
            r++;
        }
        return count;
    }
};