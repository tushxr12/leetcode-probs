// With external sort
class Solution {
private:
    bool isVowel(char c){
        set<char> st = {'a', 'A', 'e' , 'E', 'i', 'I' ,'o', 'O', 'u', 'U'};
        return (st.find(c) != st.end());
    }
public:
    string sortVowels(string s) {
        string ans = "";
        vector<char> vowels;
        for(auto i: s){
            if(isVowel(i))
                vowels.push_back(i);
        }

        sort(begin(vowels), end(vowels));
        cout<<"Sorted vowels : ";
        for(auto i : vowels)
            cout<<i<<" ";
        cout<<endl;
        int index = 0;

        for(auto i : s){
            if(!isVowel(i))
            {
                ans.push_back(i);
            }
            else
            {
                ans.push_back(vowels[index++]);
            }
        }
        return ans;
    }
};


// Without using external sort [Better]
class Solution {
private:
    bool isVowel(char c){
        set<char> st = {'a', 'A', 'e' , 'E', 'i', 'I' ,'o', 'O', 'u', 'U'};
        return (st.find(c) != st.end());
    }
public:
    string sortVowels(string s) {
        string ans = "";
        // vector<char> vowels;
        unordered_map<char, int> mpp;
        for(auto i: s){
            if(isVowel(i))
                mpp[i]++;
        }

        // sort(begin(vowels), end(vowels));

        string vowels = "AEIOUaeiou";
        // cout<<"Sorted vowels : ";
        // for(auto i : vowels)
        //     cout<<i<<" ";
        // cout<<endl;

        int index = 0;

        for(auto i : s){
            if(!isVowel(i))
            {
                ans.push_back(i);
            }
            else
            {
                while(mpp[vowels[index]] == 0)
                    index++;
                
                ans.push_back(vowels[index]);
                mpp[vowels[index]]--;
            }
        }
        return ans;
    }
};
