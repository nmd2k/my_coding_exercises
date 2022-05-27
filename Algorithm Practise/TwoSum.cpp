#include <iostream>
#include <vector>
#include <map>
#include <iterator>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    int size = nums.size();
    map <int, int> hash_map;
    
    for (int i=0; i<size; i++) {

        if (hash_map.find(target - nums[i]) != hash_map.end()) {
            return {hash_map[target - nums[i]], i};
        }

        hash_map[nums[i]] = i;
    }

    return {-1, -1};
    
}

int main() {
    vector <int> nums = {2, 7, 11, 15};
    int target = 9;

    cout << endl;

    vector<int> result = twoSum(nums, target);

    cout << result[0] << " " << result[1];
    return 0;
}