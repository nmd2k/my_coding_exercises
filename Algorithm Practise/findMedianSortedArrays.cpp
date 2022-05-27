#include <iostream>
#include <vector>

using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
            int size1 = nums1.size();
        int size2 = nums2.size();
        int size = size1+size2;
        
        int merge[size];
        int i=0;
    
        int l1=0, l2=0;
        while (l1<size1 || l2<size2) {
            if (l1<size1 && l2<size2) {
                if (nums1[l1] <= nums2[l2]) {
                    merge[i++] = nums1[l1];
                    l1++;
                }
                else if (nums1[l1] > nums2[l2]) {
                    merge[i++] = nums2[l2];
                    l2++;
                }
            }
            else if (l1<size1 && l2>=size2) {
                merge[i++] = nums1[l1];
                l1++;
            }

            else if (l1>=size1 && l2<size2) {
                merge[i++] = nums2[l2];
                l2++;
            }
        }

        for (int i=0; i<size; i++) {
            cout << merge[i] << " ";
        }

        if (size%2==0) {
            return (double)(merge[size/2] + merge[size/2-1])/2;
        }
        return (double)merge[size/2];
}

int main() {
    vector<int> nums1 = {1,3,5,9};
    vector<int> nums2 = {2,4,5,10};
    cout << findMedianSortedArrays(nums1, nums2);
    return 0;
}