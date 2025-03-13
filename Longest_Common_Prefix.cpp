class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // If the input vector is empty, return an empty string
        if (strs.size() == 0) { return ""; }

        // If there is only one string, return it as the prefix
        if (strs.size() == 1) { return strs[0]; }

        // Initialize minLength with the length of the first string
        // This will be used to limit the comparison to the shortest string
        int minLength = strs[0].size();

        // Iterate through all strings to find the length of the shortest string
        for (const string& s : strs) {
            if (s.size() < minLength) {
                // Update minLength if a shorter string is found
                minLength = s.size();
            }
        }

        // Initialize an empty string to store the common prefix
        string prefix;

        // Iterate through each character position up to minLength
        for (int i = 0; i < minLength; i++) {
            // Get the character at position i from the first string
            char c = strs[0][i];

            // Compare this character with the same position in all other strings
            for (const string& s : strs) {
                // If the character differs, return the prefix found so far
                if (s[i] != c) {
                    return prefix;
                }
            }

            // If all strings match at this position, add the character to the prefix
            prefix += c;
        }

        // Return the longest common prefix found
        return prefix;
    }
};
