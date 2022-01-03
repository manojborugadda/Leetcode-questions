class Solution {
public:
    bool isHappy(int n)
    {
        int sum = 0;

        while (n > 0)
        {
            sum += pow(n % 10, 2);
            n /= 10;
        }

        if (sum == 4)
        {
            return 0;
        }

        if (sum != 1)
        {
            return isHappy(sum);
        }

        return sum;
    }
};