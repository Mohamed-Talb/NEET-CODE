// 1- SOLUTION EXPLANATION
// ENCODE joins every STRING using a special DELIMITER.
// DECODE searches for the DELIMITER, extracts each SUBSTRING, and stores it in the RESULT.

// 2- NEW CONCEPTS LEARNED
// DELIMITER: a special SEPARATOR used to distinguish STRINGS inside one combined STRING.
// FIND and SUBSTR: FIND locates a SEQUENCE, while SUBSTR extracts part of a STRING.

// 3- CODE
class Solution 
{
public:
    string encode(vector<string>& strs) 
    {
        std::string result;
        size_t size = strs.size();

        if (size == 0)
            return result;

        std::string del = "\xE2\x80\xA2";

        for (size_t i = 0; i < size; i++)
            result += strs[i] + del;

        return result;
    }

    std::vector<std::string> decode(std::string str)
    {
        std::vector<std::string> result;

        if (str.size() == 0)
            return result;

        std::string del = "\xE2\x80\xA2";
        size_t start = 0;
        size_t pos;

        while ((pos = str.find(del, start)) != std::string::npos)
        {
            result.push_back(str.substr(start, pos - start));
            start = pos + del.length();
        }

        return result;
    }
};