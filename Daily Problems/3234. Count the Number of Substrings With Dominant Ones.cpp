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

// Better
class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();

        vector<int> cumOnes(n, 0);
        cumOnes[0] = (s[0] == '1') ? 1 : 0;

        for(int i = 1;i < n;i++)
            cumOnes[i] = (cumOnes[i-1]) + (s[i] == '1' ? 1 : 0);

        int ans = 0;
        for(int i = 0;i < n;i++){
            for(int j = i;j < n;j++){
                int oneCount = cumOnes[j] - (i - 1 >= 0 ? cumOnes[i - 1] : 0);
                int zeroCount = (j - i + 1) - oneCount;

                if((zeroCount*zeroCount) > oneCount){
                    int waste = (zeroCount*zeroCount)-oneCount;
                    j += waste - 1;
                }
                else if((zeroCount*zeroCount) == oneCount){
                    ans += 1;
                }
                else
                {
                    ans += 1;

                    int k = sqrt(oneCount) - zeroCount;
                    int next = j + k;

                    if(next >= n){
                        ans += (n - j - 1);
                        break;
                    }
                    else
                    {
                        ans += k;
                    }
                    j = next;
                }
            }
        }
        return ans;
    }
};
