
#include <iostream>
#include <string>
#include <stdio.h>
#include <unordered_map>

using std::string;
using std::unordered_map;

class Solution {
    public:
        int maxNumberOfBalloons(string text) {
            unordered_map<char, int> map = { {'b', 0},
                                             {'a', 0},
                                             {'l', 0},
                                             {'o', 0},
                                             {'n', 0}
                                            };
            
            for (char c: text)
            {
                switch(c)
                {
                    case 'b':
                        map['b']++;
                        break;
                    case 'a':
                        map['a']++;
                        break;
                    case 'l':
                        map['l']++;
                        break;
                    case 'o':
                        map['o']++;
                        break;
                    case 'n':
                        map['n']++;
                        break;
                }
            }
            int count = 0;
            while(1)
            {
                if (map['b'] >= 1 &&
                    map['a'] >= 1 &&
                    map['l'] >= 2 &&
                    map['o'] >= 2 &&
                    map['n'] >= 1)
                {
                    count++;
                    map['b']--;
                    map['a']--;
                    map['l'] -= 2;
                    map['o'] -= 2;
                    map['n']--;
                }
                else
                {
                    break;
                }

            }
            return count;
        }
 };


 int main(void)
 {
    Solution x;
    int count;
    std::string one =  "nlaebolko";
    count = x.maxNumberOfBalloons(one);
    printf ("count :%d\n", count);
 }
