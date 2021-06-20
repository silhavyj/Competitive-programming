class Solution {
public:
    int months[12] = {31,28,31,30,31,30,
                      31,31,30,31,30,31};
    
    int daysInYear(int day, int month, int year) {
        int i = 0;
        int k = day;
        for (; i < month-1; i++)
            k += months[i];
        if (month > 2)
            if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
                k++;
        return k;
    }
    
    long countDays(int day1, int month1, int year1,
                   int day2, int month2, int year2) {
        long k = 365 * (year2 - year1);
        k += daysInYear(day2, month2, year2) - daysInYear(day1, month1, year1);
        year2--;
        year1--;
        k += (year2/4 - year2/100 + year2/400) - (year1/4 - year1/100 + year1/400);
        return k % 7;
    }
    
    string dayOfTheWeek(int day, int month, int year) {
        int k = countDays(26,12,1599,day,month,year);
        switch (k) {
            case 0: return "Sunday";
            case 1: return "Monday";
            case 2: return "Tuesday";
            case 3: return "Wednesday";
            case 4: return "Thursday";
            case 5: return "Friday";
            case 6: return "Saturday";
        }
        return "";
    }
};
