///python solution----------------
dic = {}
sum = count = 0
for i in range(len(nums)):
sum += 1 if nums[i] == 1 else -1
if sum == 0:
count = max(count,i + 1)
elif(sum in dic):
count = max(count,i - dic[sum])
else:
dic[sum] = i
return count