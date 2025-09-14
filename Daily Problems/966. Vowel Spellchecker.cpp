class Solution {
private:
    bool isVowel(char ch){
        string s = "aeiou";
        return (s.find(ch) != string::npos);
    }

    string replaceVowel(string s){
        string x = "";
        s = toLower(s);
        for(auto i : s){
            if(isVowel(i)){
                x += '*';
            }
            else
            {
                x += i;
            }
        }
        cout<<"From replace vowel : "<<x<<endl;
        return x;
    }

    string toLower(string s){
        string lowerString = "";
        for(auto i : s){
            lowerString += tolower(i);
        }
        return lowerString;
    }

public:
    unordered_set<string> exactSet;
    unordered_map<string, string> caseMap;
    unordered_map<string, string> vowelMap;

    vector<string> spellchecker(vector<string>& wordList, vector<string>& queries) {
        exactSet.clear();
        caseMap.clear();
        vowelMap.clear();

        for(string word : wordList){
            exactSet.insert(word);

            string lowerCase = toLower(word);
            if(caseMap.find(lowerCase) == caseMap.end()){
                caseMap[lowerCase] = word;
            }

            string vowelCase = replaceVowel(lowerCase);
            if(vowelMap.find(vowelCase) == vowelMap.end()){
                vowelMap[vowelCase] = word;
            }
        }

        vector<string> ans;
        for(auto query : queries){
            auto capQuery = toLower(query);
            auto vowelQuery = replaceVowel(query);

            cout<<"Cap query : "<< capQuery<<"\n Vowel query : "<<vowelQuery<<endl;
            if(exactSet.find(query) != exactSet.end()){
                ans.push_back(query);
            }
            else if(caseMap.find(capQuery) != caseMap.end()){
                ans.push_back(caseMap[capQuery]);
            }
            else if(vowelMap.find(vowelQuery) != vowelMap.end()){
                ans.push_back(vowelMap[vowelQuery]);
            }
            else
            {
                ans.push_back("");
            }
        }

        return ans;
    }
};
