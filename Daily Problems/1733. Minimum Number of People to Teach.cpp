class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        unordered_set<int> sadUsers;

        for(auto friends: friendships){
            int u = friends[0] - 1;
            int v = friends[1] - 1;

            unordered_set<int> langSet(begin(languages[u]) , end(languages[u]));

            bool canTheyTalk = false;
            for(auto lang: languages[v]){
                if(langSet.count(lang)){
                    canTheyTalk = true;
                    break;
                }
            }

            if(!canTheyTalk){
                sadUsers.insert(u);
                sadUsers.insert(v);
            }
        }


        unordered_map<int,int> mpp;
        int mostKnown = 0;

        for(auto user: sadUsers){
            for(int lang: languages[user]){
                mpp[lang]++;
                mostKnown = max(mostKnown, mpp[lang]);
            }
        }
        return sadUsers.size() - mostKnown;
    }
};
