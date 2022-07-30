class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        
        vector<int> freq(26,0);
        vector<string> ans;
        
        for(string b: words2){
            vector<int> temp(26,0);
            for(char c: b){
                temp[c-'a']++;
            }
            for(int i=0;i<26;i++)
                freq[i] = max(freq[i],temp[i]);
        }
        for(string b: words1){
            vector<int> temp(26,0);
              for(char c: b){
                temp[c-'a']++;
            }
            for(int i=0;i<26;i++){
                if(temp[i]<freq[i])
                    break;
                if(i==25){
                    ans.push_back(b);
                }
            }
        }
        return ans;
        
    }
};