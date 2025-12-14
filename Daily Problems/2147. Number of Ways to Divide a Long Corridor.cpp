class Solution {
public:
    const int mod = 1e9 + 7;

    int numberOfWays(string corridor) {
        int n = corridor.size();
        int seatsCount = 0;
        for(auto i : corridor)
            if(i == 'S')
                seatsCount++;
        
        if(seatsCount < 2 || (seatsCount%2 != 0))
            return 0;
        
        vector<int> seatsIndexes;
        for(int i = 0;i < n;i++)
            if(corridor[i] == 'S')
                seatsIndexes.push_back(i);
        
        long long ans = 1;

        int prevIndex = seatsIndexes[1];
        for(int i = 2;i < seatsIndexes.size();i+=2){
            int curr = (seatsIndexes[i] - prevIndex);
            ans = (ans*curr)%mod;
            prevIndex=seatsIndexes[i+1];
        }
        
        return ans;
    }
};
