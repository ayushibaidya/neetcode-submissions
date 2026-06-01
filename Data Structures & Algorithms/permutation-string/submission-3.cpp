class Solution {
public:

    bool checkFreq(vector<int> &freq1, vector<int> &freq2){
        for(int j = 0; j < 26; j++){
                if(freq1[j] != freq2[j]){
                    return false; 
                }
            }
            return true; 
    }

    bool checkInclusion(string s1, string s2) {
        vector<int> freq1(26, 0); 
        
        //count of chars in s1 stored in freq1
        for(int i = 0; i < s1.size(); i++){
            freq1[s1[i]-'a']++; 
        }
        //window size will be size of s1 
        int winSize = s1.size(); 

        //traverse s2-> and search each window space 
        for(int i = 0; i < s2.size(); i++){
            int winIdx = 0; int idx = i; 
            vector<int> freq2(26, 0); 
            //get the count of letters in s2 in the given window size
            while(idx < s2.size() && winIdx < winSize){
                freq2[s2[idx]-'a']++; 
                winIdx++; idx++; 
            }
            if(checkFreq(freq1, freq2)){
                return true; 
            }
        }
        return false; 
    }
};
