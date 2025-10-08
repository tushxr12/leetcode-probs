// Brute
class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> res;
        for(auto i : spells){
            long long currSpell = i;
            long long ans = 0;
            for(auto j : potions){
                if(currSpell * j >= success){
                    ans++;
                }
            }
            res.push_back(ans);
        }
        return res;
    }
};
