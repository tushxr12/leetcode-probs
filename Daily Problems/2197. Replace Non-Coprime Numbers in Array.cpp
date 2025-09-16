// TC -> O(2*N*LogX)
// SC -> O(1)

class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> ans;
        for(auto i : nums){
            while(!ans.empty()){
                int prev = ans.back();

                int currNum = i;

                int GCD = gcd(prev, currNum); // Log(Min(a,b))

                if(GCD == 1){
                    break;
                }

                ans.pop_back();
                int LCM = prev/GCD * currNum;

                i = LCM;
            }
            ans.push_back(i);
        }
        return ans;
    }
};
