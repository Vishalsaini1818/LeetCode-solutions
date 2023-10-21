class Solution {
public:
    bool detectCapitalUse(string word) {
        bool allcapital = false;
        if (isupper(word[0]))
            allcapital = true;
        for(int i=1; i<word.size(); ++i){
            if(islower(word[i]) and allcapital){
                if(i==1) allcapital=false;
                else return false;
            }
            
            if(isupper(word[i]) and !allcapital)
                return false;
        }

        return true;
    }
};
