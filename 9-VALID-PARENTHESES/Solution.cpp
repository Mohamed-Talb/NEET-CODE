// 1- SOLUTION EXPLANATION
// Use a STACK to store OPENING BRACKETS as they appear.
// For each CLOSING BRACKET, check if it matches the most recent OPENING BRACKET.
// At the end, the STACK must be EMPTY for the STRING to be VALID.

// 2- NEW CONCEPTS LEARNED
// STACK: follows LIFO, so the last OPENING BRACKET must be closed first.
// BRACKET MATCHING: each CLOSING BRACKET must match the corresponding OPENING BRACKET.

// 3- CODE
class Solution {
public:
    std::unordered_map<char, char> openClose = {
        {'(', ')'},
        {'{', '}'},
        {'[', ']'}
    };

    bool isValid(string s) 
    {
        std::stack<char> openBracket;
        int ss = s.size();

        for (int i = 0; i < ss; i++)
        {
            if (s[i] == '{' || s[i] == '(' || s[i] == '[')
                openBracket.push(s[i]);

            else if (s[i] == '}' || s[i] == ')' || s[i] == ']')
            {
                if (openBracket.size() == 0 || openClose[openBracket.top()] != s[i])
                    return false;

                openBracket.pop();
            }

            else
                return false;
        }

        if (openBracket.size() != 0)
            return false;

        return true;
    }
};