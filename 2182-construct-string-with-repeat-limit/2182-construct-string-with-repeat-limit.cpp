class Solution {
public:
    string repeatLimitedString(string s, int limit) {
        sort(s.begin(), s.end(), greater<>());
          int i = 0, j = 0;
          while (i < s.size() and j < s.size())
          {
            int val = 0;
            while (j < s.size() and s[i] == s[j])
            {
              val++;
              j++;
            }
            while (j<s.size() and val > limit)
            {
              i += limit;
              swap(s[i], s[j]);
              j++, i++;
              val -= limit;
            } 
            if (j >= s.size())
            {
              i += limit;
              break;
            }
            if (val <= limit)
              i += val;
          }
        if(i>=s.size())return s;
        return s.substr(0,i);
    }
};