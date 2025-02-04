1. Accumulate the current sum as long as the sequence is ascending.
2. Whenever the sequence breaks, update the ans (maximum sum encountered) and reset sum with the current element.
3. After the loop, ensure you check sum one final time to account for the last ascending subarray.
