class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        int n = text.size();
        int untypableWords = 0, totalWords = 0;
        
        for(int i = 0;i < n;i++){
            string currWord = "";
            bool flag = false;

            while(i < n && text[i] != ' '){
                currWord += text[i++];
                flag = true;
            }

            if(flag)
            {
                totalWords++;
            }

            for(auto i : brokenLetters){
                if(currWord.find(i) != string::npos){
                    untypableWords += 1;
                    break;
                }
            }
        }

        return totalWords - untypableWords;
    }
};
