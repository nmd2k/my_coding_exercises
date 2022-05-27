#include <iostream>
#include <vector>
using namespace std;

vector<int> searchRange(vector<int>& nums, int target) {
    // simple answer
    int first = -1, last = -1;
    for (int i=0; i<nums.size(); i++) {
        if (nums[i] == target) {
            if (first == -1) {
                first = i;
            }
            last = i;
        }
    }
    
    if (first == -1) {
        return {-1, -1};
    }

    return vector<int>{first, last};
}

vector<int> biSearchRange(vector<int>& nums, int target) {
    // binary search
    int left = 0, right = nums.size() - 1;
    int first = -1, last = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target) {
            first = mid;
            right = mid - 1;
        }
        else if (nums[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    if (first != -1) {
        last = first + 1;
        while (nums[last] == target) {
            last++;
        }
    }

    return vector<int>{left, right};
}

int main() {
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    int target = 8;

    vector<int> res = searchRange(nums, target);
    cout << res[0] << " " << res[1] << endl;
}