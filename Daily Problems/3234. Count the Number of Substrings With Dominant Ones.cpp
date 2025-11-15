// Brute force
class Solution {
private:
    bool isDominant(string &s)
    {
        int z = 0, o = 0;
        for(auto i : s)
            if(i == '0')
                z++;
            else
                o++;
        
        return (o >= z*z);
    }
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int ans = 0;
        for(int i = 0;i < n;i++){
            string currSbstr = "";
            for(int j = i;j < n;j++){
                currSbstr += s[j];
                // cout<<currSbstr<<"\n";

                if(isDominant(currSbstr))
                {
                    cout<<"Dominant substr : "<<currSbstr<<"\n";
                    ans++;
                }
                    
            }
        }
        return ans;
    }
};
