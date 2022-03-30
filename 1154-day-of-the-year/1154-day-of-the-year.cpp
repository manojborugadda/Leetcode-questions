class Solution {
public:
    int dayOfYear(string date) {
        int res = 0;
        int year = stoi(date.substr(0,4));
        int month = stoi(date.substr(5,2));
        int day = stoi(date.substr(8,2));
        
        vector<int> months = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
		if(year % 4 == 0 and (year % 100 != 0 or year % 400 == 0)){ // checking if year is LEAP year or not
			months[2] += 1;  // if it is leap year FEBRUARY has 29 days
		}
		for (int i = 1; i < month; i++)
		{
			res += months[i];
		}
		res += day;
		return res;
	}
};
