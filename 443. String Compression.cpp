// Leetcode problem link
// https://leetcode.com/problems/string-compression/

class Solution {
public:
    int compress(vector<char>& chars) {
        int i = 0;
        int valid = 0;
        int n = chars.size();
        while(i<n)
        {
            char curr = chars[i];
            int count = 0;

            // counting the number of occurance for current character
            while(i<n && chars[i] == curr)
            {
                i++;
                count++;
            }

            // Updating the character
            chars[valid] = curr;
            valid++;

            // Adding number of count of that character
            if(count > 1)
            {
                string ct = to_string(count);
                for(char& ch : ct)
                    chars[valid++] = ch;
            }
        }
        return valid;
    }
};
