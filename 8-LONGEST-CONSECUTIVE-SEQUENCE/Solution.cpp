// 1- SOLUTION EXPLANATION
// Use a HASH MAP to store the LENGTH of each CONSECUTIVE SEQUENCE at its BOUNDARIES.
// For each NUMBER, combine the LEFT and RIGHT SEQUENCES, then update the new BOUNDARIES.

// 2- NEW CONCEPTS LEARNED
// BOUNDARY MERGING: joins two existing CONSECUTIVE SEQUENCES using the current NUMBER.
// HASH MAP LOOKUP: quickly gets the LENGTH of the LEFT and RIGHT neighboring SEQUENCES.

// 3- CODE
class Solution
{
    public:
    int longestConsecutive(vector<int>& nums) 
    {
        std::unordered_map<int, int> myMap;
        int longest = 0;

        for (int x : nums)
        {
            if (myMap[x] != 0)
                continue;

            int right = myMap[x + 1];
            int left = myMap[x - 1];
            int length = left + 1 + right;

            myMap[x] = length;
            myMap[x - left] = length;
            myMap[x + right] = length;

            longest = std::max(length, longest);
        }

        return longest;
    }
};