class Solution {
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        vector<string> ans;
        int codeSize = code.size();
        int b = businessLine.size();
        int isActiveSize = isActive.size();
        unordered_map<string,int> st = {{"electronics",0}, {"grocery",1}, {"pharmacy",2}, {"restaurant",3}};
        vector<pair<int, string>> temp;

        for(int i = 0;i < codeSize;i++)
        {
            auto currCode = code[i];
            auto codesBusinessLine = businessLine[i];
            auto active = isActive[i];

            if(currCode == "" || currCode.size() == 0)
                continue;

            bool isValidCode = true;
            for(auto j : currCode)
            {
                if(!isalnum(j) && !(j == '_')){
                    isValidCode = false;
                    break;
                }
            }

            if(st.find(codesBusinessLine) == st.end() || !active){
                isValidCode = false;
            }

            if(isValidCode){
                temp.push_back({st[codesBusinessLine], currCode});
            }
        }
        sort(begin(temp), end(temp));
        for(auto i : temp)
            ans.push_back(i.second);
        
        return ans;
    }
};
