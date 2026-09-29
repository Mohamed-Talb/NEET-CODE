// 1- SOLUTION EXPLANATION
// Build a PREFIX PRODUCT from the LEFT and a SUFFIX PRODUCT from the RIGHT.
// For each INDEX, multiply PREFIX[index] * SUFFIX[index] to get the PRODUCT EXCEPT SELF.

// 2- NEW CONCEPTS LEARNED
// PREFIX PRODUCT: product of all ELEMENTS before the current INDEX.
// SUFFIX PRODUCT: product of all ELEMENTS after the current INDEX.

// 3- CODE
class Solution
{
public:
    vector<int> productExceptSelf(vector<int>& nums) 
    {
        int size = nums.size();
        int i = 0;
        int j = size - 1;
        
        vector<int> suffix(size);
        vector<int> prefix(size);
        vector<int> result(size);

        prefix[0] = 1;
        suffix[j] = 1;

        while (i < size - 1)
        {
            prefix[i + 1] = nums[i] * prefix[i];
            suffix[j - 1] = nums[j] * suffix[j];

            i++;
            j--;
        }

        for (int x = 0; x < size; x++)
        {
            result[x] = prefix[x] * suffix[x];
        }

        return result;
    }
};