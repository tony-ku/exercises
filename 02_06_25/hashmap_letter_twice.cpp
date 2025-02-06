#include <iostream>
#include <string>
#include <unordered_map>

class test {

public:
    char repeatedCharacter(std::string s) {
        uint32_t counter = 0;
        std::unordered_map<char, int> dic;
        for (char c: s) {
            if (dic.find(c) != dic.end()) {
                return c;
            }
            printf ("counter: %d, c: %c\n", counter, c);
            dic[c] = counter++;
        }
        return ' ';
    }
};

int main(void)
{
    std::string s = "abcdeda";
    char result;
    test X;
    
    result = X.repeatedCharacter(s);
    printf ("result: %c\n", result);
    return 0;
}