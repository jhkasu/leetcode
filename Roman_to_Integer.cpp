class Solution {
public:
    int romanToInt(string s) {
        int arr[26];
        arr['I'-'A']=1;
        arr['V'-'A']=5;
        arr['X'-'A']=10;
        arr['L'-'A']=50;
        arr['C'-'A']=100;
        arr['D'-'A']=500;
        arr['M'-'A']=1000;

        int res=0;
        int prev=0;

        for (int i=s.length()-1; i>=0; i--) {
            int curr = arr[s[i]-'A'];
            if (curr>=prev) {
                res += curr;
            } else {
                res -= curr;
            }
            prev = curr;
        }

        return res;
    }
};