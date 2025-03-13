class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size()==0) {return "";}
        if (strs.size()==1) {return strs[0];}

        int minLength=strs[0].size();
        for (const string& s:strs) {
            if (s.size() < minLength) {
                minLength = s.size();
            }
        }
        string prefix;
        for (int i=0; i<minLength; i++) {
            char c = strs[0][i];
            for(const string& s:strs) {
                if (s[i] != c) {
                    return prefix;
                }
            }
            prefix += c;
        }
        return prefix;
    }
};