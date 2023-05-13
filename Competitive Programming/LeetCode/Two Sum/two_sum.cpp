#include <iostream>
#include <vector>
#include <map>

#define f first
#define s second
using namespace std;


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int, int>> modified(nums.size());
        for (int i = 0; i < nums.size(); i++)
            modified[i] = make_pair(nums[i], i);
        
        sort(modified.begin(), modified.end());
        
        int first_pointer = 0, second_pointer = nums.size() - 1;
        vector<int> ans(2);
        while (first_pointer < second_pointer) {
            if (modified[first_pointer].f + modified[second_pointer].f == target) {
                ans[0] = modified[first_pointer].s;
                ans[1] = modified[second_pointer].s;
                break;
            }
            else if (modified[first_pointer].f + modified[second_pointer].f < target)
                first_pointer++;
            else if (modified[first_pointer].f + modified[second_pointer].f > target)
                second_pointer--;
        }
        
        return ans;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    vector<int> nums = {3, 2, 4};
    int target = 6;

    Solution ans;
    vector<int> output = ans.twoSum(nums, target);
    cout << "[" << output[0] << ", " << output[1] << "]" << endl;
    
    return 0;
}
