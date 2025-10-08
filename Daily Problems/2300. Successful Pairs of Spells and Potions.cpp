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

// Optimal
class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> res;
        sort(begin(potions), end(potions));
        int n = potions.size();
        int maxPotion = potions[n - 1];
        for(auto i : spells){
            long long currSpell = i;
            long long ans = 0;
            long long minPotion = ceil((success*1.0)/currSpell);
            if(minPotion > maxPotion){
                res.push_back(0);
                continue;
            }
            auto it = lower_bound(begin(potions), end(potions),minPotion) - begin(potions);
            cout<<"Lower bound : it = : "<<it<<endl;
            ans += potions.size() - it;
            res.push_back(ans);
        }
        return res;
    }
};
