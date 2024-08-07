// Approach -> Time Complexity: O(N) or O(N*logN) depending on which map data structure

//     First, we will declare a map to store the prefix sums and their counts.
//     Then, we will set the value of 0 as 1 on the map.
//     Then we will run a loop(say i) from index 0 to n-1(n = size of the array).
//     For each index i, we will do the following:
//         We will add the current element i.e. arr[i] to the prefix sum.
//         We will calculate the prefix sum i.e. x-k, for which we need the occurrence.
//         We will add the occurrence of the prefix sum x-k i.e. mpp[x-k] to our answer.
//         Then we will store the current prefix sum in the map increasing its occurrence by 1.

class Solution {
public:
    int subarraySum(vector<int>& arr, int k) {
    int n = arr.size(); // size of the given array.
    unordered_map<int,int> mpp;
    int preSum = 0, cnt = 0;

    mpp[0] = 1; // Setting 0 in the map.
    for (int i = 0; i < n; i++) {
        // add current element to prefix Sum:
        preSum += arr[i];

        // Calculate x-k:
        int remove = preSum - k;

        // Add the number of subarrays to be removed:
        cnt += mpp[remove];

        // Update the count of prefix sum
        // in the map.
        mpp[preSum] += 1;
    }
    return cnt;
    }
};