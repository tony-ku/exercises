#include <iostream>
#include <string>

using namespace::std;

class Solution {
    public:
        bool canConstruct(string ransomNote, string magazine) {
            int mag_dict[26] = {0};
            for (char c : magazine)
            {
                int x = (int)c - 'a';
                mag_dict[x]++;
            }
            
            for (char c: ransomNote)
            {
                int x = (int)c - 'a';
                if (mag_dict[x] == 0)
                    return false;
                else
                    mag_dict[x]--;
            }
            return true;
        }
    };


int main(void)
{
    string ransomNote = "aa", magazine = "aab";
    Solution X;
    if (X.canConstruct(ransomNote, magazine))
        printf ("true\n");
    else
        printf ("false\n");

    return 0;
}