class Solution {//TC:O(nlogn)   SC:O(n)
public:
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size() - 1);
        return nums;
    }

    void mergeSort(vector<int>& arr,int l,int r) {
	if(l>=r) {
		return;///returns recursively
	}
	int m =l+ (r-l)/2;
	mergeSort(arr,l,m);
	mergeSort(arr,m+1,r);
	merge(arr,l,m,r);
}

void merge(vector<int>& arr, int l, int m, int r) {
	int n1 = m - l + 1;
	int n2 = r - m;

	/// Create temp arrays
	int L[n1], R[n2];

	/// Copy data to temp arrays L[] and R[]
	for (int i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (int j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];

	/// Merge the temp arrays back into arr[l..r]

	/// Initial index of first sub array
	int i = 0;

	/// Initial index of second sub array
	int j = 0;

	/// Initial index of merged sub array
	int k = l;

	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
		}else {
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	/// Copy the remaining elements of
	/// L[], if there are any
	while (i < n1) {
		arr[k] = L[i];
		i++;
		k++;
	}

	/// Copy the remaining elements of
	/// R[], if there are any
	while (j < n2) {
		arr[k] = R[j];
		j++;
		k++;
	}
}

};

//////////////////////using sort function
// class Solution {
// public:
//     vector<int> sortArray(vector<int>& nums) {
//         sort(begin(nums),end(nums));
//         return nums;
//     }
// };
