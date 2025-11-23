// Approach - 1
class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int sum = 0;
        
        vector<int> remain1, remain2;

        for(auto i : nums){
            sum += i;

            if(i%3 == 1)
                remain1.push_back(i);
            else if(i%3 == 2)
                remain2.push_back(i);

        }

        if(sum%3 == 0){
            return sum;
        }

        sort(begin(remain1), end(remain1));
        sort(begin(remain2), end(remain2));

        int ans = 0;
        int rem = sum % 3;

        if(rem == 1){
            int remove1 = remain1.size() >= 1 ? remain1[0] : INT_MAX;
            int remove2 = remain2.size() >= 2 ? (remain2[0] + remain2[1]) : INT_MAX;

            ans = max(ans, sum - min(remove1, remove2));
        }
        else
        {
            int remove2 = remain2.size() >= 1 ? remain2[0] : INT_MAX;
            int remove1 = remain1.size() >= 2 ? (remain1[0] + remain1[1]) : INT_MAX;

            ans = max(ans, sum - min(remove1, remove2));
        }

        return ans;
    }
};
