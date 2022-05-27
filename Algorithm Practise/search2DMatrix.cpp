#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // for row
        int i=0;
        for (i; i<matrix.size()-1; i++) {
            if (matrix[i][0] == target || matrix[i+1][0] == target) {
                return true;
            }
            
            else if (matrix[i][0] < target && target < matrix[i+1][0]) {
                break;
            }
        }
        
        
        int l = 0, r = matrix[0].size() - 1;
        while (l<=r) {
            int mid = l + (r-l)/2;
            if (matrix[i][mid] == target) {
                return true;
            }
            
            else if (matrix[i][mid] > target) {
                r = mid-1;
            }
            
            else {l = mid+1;}
        }
        return false;
    }
};

int main() {
    return 0;
}