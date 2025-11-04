class Solution {
private:
    typedef pair<int,int> P;

    int findSum(unordered_map<int,int> mpp, int x)
    {
        priority_queue<P, vector<P> , greater<P>> pq;

        for(auto i : mpp){
            pq.push({i.second, i.first});
            if(pq.size() > x)
            pq.pop();
        }

        
        
        int sum = 0;
        while(!pq.empty())
        {
            auto [freq, val] = pq.top();
            pq.pop();

            sum += freq*val;
        }
        return sum;
    }
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        unordered_map<int,int> mpp;

        vector<int> res;
        int i = 0,j = 0;

        while(j < n)
        {
            mpp[nums[j]]++;

            if(j - i + 1 == k){
                res.push_back(findSum(mpp, x));

                mpp[nums[i]]--;
                if(mpp[nums[i]] == 0)
                    mpp.erase(nums[i]);
                i++;
            }
            j++;
        }
        return res;
    }
};
