class Solution
{
    public:
    vector<int> productExceptSelf(vector<int>& nums) 
    {
        int size = nums.size();
        vector<int> suffix;
        vector<int> prefix;
        prefix.push_back(1);
        // prefix.push_back(nums[0]);
        suffix.insert(suffix.begin(), 1);
        // suffix.insert(suffix.begin(), prefix[0] * nums[size - 1]);

        int i = 0;
        int j = size - 1;
        while (i < size - 1)
        {
            prefix.push_back(nums[i] * prefix[i]);
            suffix.insert(suffix.begin(), nums[j] * suffix[0]);
            i++;
            j--;
        }
        vector<int> result;
        for(int x = 0; x < size; x++)
        {
            result.push_back(prefix[x] * suffix[x]);
        }
        return result;
    }
};
