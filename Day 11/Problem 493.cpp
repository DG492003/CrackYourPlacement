// Approach -> 
// Time Complexity: O(2N*logN) Inside the mergeSort() we call both merge() and countPairs()
//     Now, inside the function countPairs(), though we are running a nested loop, we are actually iterating the left half once and the right half once in total. That is why, the time complexity is O(N). And the merge() function also takes O(N). The mergeSort() takes O(logN) time complexity. Therefore, the overall time complexity will be O(logN * (N+N)) = O(2N*logN).
// Space Complexity: O(N), as in the merge sort We use a temporary array to store elements in sorted order.

// The steps are basically the same as they are in the case of the merge sort algorithm. The change will be just in the mergeSort() function:
//     -> In order to count the number of pairs, we will keep a count variable, cnt, initialized to 0 beforehand inside the mergeSort().
//     -> We will add the numbers returned by the previous mergeSort() calls.
//     -> Before the merge step, we will count the number of pairs using a function, named countPairs().
//     -> We need to remember that the left half starts from low and ends at mid, and the right half starts from mid+1 and ends at high.

// The steps of the countPairs() function will be as follows:
//     -> We will declare a variable, cnt, initialized with 0.
//     => We will run a loop from low to mid, to select an element at a time from the left half.
//     -> Inside that loop, we will use another loop to check how many elements from the right half can make a pair.
//     -> Lastly, we will add the total number of elements i.e. (right-(mid+1)) (where right = current index), to the cnt and return it.

class Solution {
private:
    // simple merge sort Algorithm
    void merge(vector<int>& arr, int low, int mid, int high) {
        vector<int> temp;    // temporary array
        int left = low;      // starting index of left half of arr
        int right = mid + 1; // starting index of right half of arr

        // storing elements in the temporary array in a sorted manner
        while (left <= mid && right <= high) {
            if (arr[left] <= arr[right]) {
                temp.push_back(arr[left]);
                left++;
            } else {
                temp.push_back(arr[right]);
                right++;
            }
        }

        // if elements on the left half are still left
        while (left <= mid) {
            temp.push_back(arr[left]);
            left++;
        }

        //  if elements on the right half are still left
        while (right <= high) {
            temp.push_back(arr[right]);
            right++;
        }

        // transfering all elements from temporary to arr //
        for (int i = low; i <= high; i++) {
            arr[i] = temp[i - low];
        }
    }
    int countPairs(vector<int>& arr, int low, int mid, int high) {
        int right = mid + 1;
        int cnt = 0;
        for (int i = low; i <= mid; i++) {
            while (right <= high && arr[i] > 2LL * arr[right])
                right++;
            cnt += (right - (mid + 1));
        }
        return cnt;
    }
    int mergeSort(vector<int>& arr, int low, int high) {
        int cnt = 0;
        if (low >= high)
            return cnt;
        int mid = (low + high) / 2;
        cnt += mergeSort(arr, low, mid);        // left half
        cnt += mergeSort(arr, mid + 1, high);   // right half
        cnt += countPairs(arr, low, mid, high); // Modification
        merge(arr, low, mid, high);             // merging sorted halves
        return cnt;
    }

public:
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size() - 1);
    }
};