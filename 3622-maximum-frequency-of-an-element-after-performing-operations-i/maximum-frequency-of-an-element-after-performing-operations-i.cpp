class Solution {
public:
    int maxFrequency(vector<int>& nums, int limit, int numOperations) {
        sort(nums.begin(),nums.end());
        int maxi=*max_element(nums.begin(),nums.end());
        vector<int> freq(maxi+1,0);
        vector<int> sumfreq(maxi+1);
        for(auto num:nums){
            freq[num]++;
        }
        sumfreq[0]=freq[0];
        for(int i=1;i<maxi+1;i++){
            sumfreq[i]=freq[i]+sumfreq[i-1];
        }
        int i=0;
        int n=nums.size();
        int ans=0;
        while(i<=maxi){
            int j=max(0,i-limit);
            int k=min(maxi,i+limit);

            int total=sumfreq[k]-(j==0?0:sumfreq[j-1]);
            total-=freq[i];
            total=min(total,numOperations);
            ans=max(ans,total+freq[i]);
            i++;
        }
        return ans;
    }
};