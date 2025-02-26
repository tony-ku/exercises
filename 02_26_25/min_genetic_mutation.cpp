/*
Minimum Genetic Mutation

A gene string can be represented by an 8-character long string, with choices from 'A', 'C', 'G', and 'T'.

Suppose we need to investigate a mutation from a gene string startGene to a gene string endGene where one mutation is defined as one single character changed in the gene string.

For example, "AACCGGTT" --> "AACCGGTA" is one mutation.
There is also a gene bank bank that records all the valid gene mutations. A gene must be in bank to make it a valid gene string.

Given the two gene strings startGene and endGene and the gene bank bank, return the minimum number of mutations needed to mutate from startGene to endGene. If there is no such a mutation, return -1.

Note that the starting point is assumed to be valid, so it might not be included in the bank.

Example 1:

Input: startGene = "AACCGGTT", endGene = "AACCGGTA", bank = ["AACCGGTA"]
Output: 1
Example 2:

Input: startGene = "AACCGGTT", endGene = "AAACGGTA", bank = ["AACCGGTA","AACCGCTA","AAACGGTA"]
Output: 2
 

Constraints:

0 <= bank.length <= 10
startGene.length == endGene.length == bank[i].length == 8
startGene, endGene, and bank[i] consist of only the characters ['A', 'C', 'G', 'T'].

*/

class Solution {
    public:
        int minMutation(string startGene, string endGene, vector<string>& bank) {
            unordered_set<string> seen;
            queue<string> queue;
            queue.push (startGene);
            seen.insert(startGene);
    
            int mutation_steps = 0;
            while (!queue.empty())
            {
                int nodes_in_queue  = queue.size();
                for (int j = 0; j < nodes_in_queue; j++)
                {
                    string node = queue.front();
                    queue.pop();
    
                    if (node == endGene)
                    {
                        return mutation_steps;
                    }
    
                    for (char c: "ACGT")
                    {
                        for (int i = 0; i < node.size(); i++)
                        {
                            string neighbor = node;
    
                            /* Change one char at a time */
                            neighbor[i] = c;
                            /* If it's not yet seen and is in the bank, then it's a valid next sequence */
                            if (!seen.count(neighbor) && find(bank.begin(), bank.end(), neighbor) != bank.end())
                            {
                                queue.push(neighbor);
                                seen.insert(neighbor);
                            }
    
                        }
                    }
                }
                mutation_steps++;
            }
            return -1;
        }
    };