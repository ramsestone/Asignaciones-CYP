#include <stdio.h>

int main()
{
    int day, month, year, nextDay, nextMonth, nextYear;

    scanf_s("%i %i %i", &day, &month, &year);

    if (day == 4 && month == 10 && year == 1582)
    {
        nextDay = 15;
        nextMonth = 10;
        nextYear = 1582;
    }
    else
    {
        if (day >= 28)
        {
            switch (month)
            {
            case 2:
                if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) // El año es biciesto
                {
                    nextDay = 29;
                    nextMonth = 2;
                }
                else
                {
                    nextDay = 1;
                    nextMonth = 3;
                }
                nextYear = year;
                break;
            case 12:
                if (day == 31 && month == 12)
                {
                    nextDay = 1;
                    nextMonth = 1;
                    nextYear = year + 1;
                }
                else
                {
                    nextDay = day + 1;
                    nextMonth = month;
                    nextYear = year;
                }
                break;
            default:
                if (day == 30)
                {
                    if (month >= 1 && month <= 7) 
                    {
                        if (month % 2 == 0) // El mes tiene 30 días
                        {
                            nextDay = 1;
                            nextMonth = month + 1;
                            nextYear = year;
                        }
                        else
                        {
                            nextDay = 31;
                            nextMonth = month;
                            nextYear = year;
                        }
                    }
                    else
                    {
                        if (month % 2 != 0) // El mes tiene 30 días
                        {
                            nextDay = 1;
                            nextMonth = month + 1;
                            nextYear = year;
                        }
                        else
                        {
                            nextDay = 31;
                            nextMonth = month;
                            nextYear = year;
                        }
                    }
                }
                else
                {
                    if (day == 31)
                    {
                        nextDay = 1;
                        nextMonth = month + 1;
                        nextYear = year;
                    }
                    else
                    {
                        nextDay = day + 1;
                        nextMonth = month;
                        nextYear = year;
                    }
                }
                break;
            }
        }
	    else
	    {
		    nextDay = day + 1;
		    nextMonth = month;
		    nextYear = year;
	    }
    }

    printf("%2i %2i %4i", nextDay, nextMonth, nextYear);

    return 0;
}