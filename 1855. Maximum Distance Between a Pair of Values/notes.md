Since both arrays are non-increasing, you can start with i = 0 and j = 0 and move j forward as long as nums1[i] <= nums2[j].
When it fails, move i forward — but don’t move j back.
This way, we  only scan each array once.
