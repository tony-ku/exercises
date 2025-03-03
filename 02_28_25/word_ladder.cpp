#include <queue>
#include <iostream>
#include <unordered_map>

using namespace std;

/*
A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:

Every adjacent pair of words differs by a single letter.
Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
sk == endWord
Given two words, beginWord and endWord, and a dictionary wordList, return the number of words in the shortest transformation sequence from beginWord to endWord, or 0 if no such sequence exists.

 

Example 1:

Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
Output: 5
Explanation: One shortest transformation sequence is "hit" -> "hot" -> "dot" -> "dog" -> cog", which is 5 words long.
Example 2:

Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
Output: 0
Explanation: The endWord "cog" is not in wordList, therefore there is no valid transformation sequence.

Constraints:

1 <= beginWord.length <= 10
endWord.length == beginWord.length
1 <= wordList.length <= 5000
wordList[i].length == beginWord.length
beginWord, endWord, and wordList[i] consist of lowercase English letters.
beginWord != endWord
All the words in wordList are unique.

*/


/*
 *  Create a lookup table of wordlist.   All permutations.   for example, hot means it can be +ot, h+t, ho+ where + is the character that can chagne
 *      THe lookup then allows each stage to find the next permutation using the key word that has + in different permuatations.
 *  Each word traversal is a level, so need to keep track of that level
 */
class Solution {
    public:
        int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
            unordered_map<string, vector<string>> lookup_map;

            int word_len = beginWord.size();
            for (string word : wordList)
            {
                for (int i = 0; i < word_len; i++)
                {
                    string key_word = word.substr(0, i) + '+' + word.substr(i + 1, word_len);
                    printf ("Key_word: %s word: %s\n", key_word.c_str(), word.c_str());
                    lookup_map[key_word].push_back(word);
                }
            }

            /* queue consists of string + level */
            queue<pair<string, int>> queue;
            queue.push({beginWord, 1});

            unordered_map<string, bool> seen;
            seen[beginWord] = true;

            int num_words = 0;
            while (!queue.empty())
            {
                pair<string, int> node = queue.front();
                queue.pop(); 
                string curr_word = node.first;
                int level = node.second;

                for (int i = 0; i < word_len; i++)
                {
                    /* create list of lookup words subst each char */
                    string test_word = curr_word.substr(0, i) + '+' + curr_word.substr(i + 1, word_len);

                    /* Grab all the next words */
                    for (string neighbor_word : lookup_map[test_word])
                    {
                        if (neighbor_word == endWord)
                            return level + 1;

                        if (!seen[neighbor_word]) {
                            seen[neighbor_word] = true;
                            queue.push({neighbor_word, level+1});
                        }
                    }
                }
            }
            return 0;
        }
    };


int main(void)
{
    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList = { 
        "hot", "dot", "dog", "lot", "log", "cog"
    };

    Solution X;
    int levels = X.ladderLength(beginWord, endWord,wordList);
    printf ("levels: %d\n", levels);
    return 0;
}