#include <stdio.h>
#include <windows.h> // To access GetLocalTime()

int date_check(int start_day, int start_month, int start_year, int end_day, int end_month, int end_year)
{
    SYSTEMTIME t ; // Declaring SYSTEMTIME struct variable, present in windows.h

    GetLocalTime(&t) ;     // For getting the present date and time from windows.h

    int start_date_count, end_date_count , num_days;
    int days_in_year;

    printf("\n\t\t\t\tDATE OF BOOKING : %d/%d/%d\n", t.wDay, t.wMonth, t.wYear);       // Displaying date of booking

    start_date_count = day_number(start_day, start_month, start_year) ;    // To calculate the day count of check-in date of the particular year
    end_date_count = day_number(end_day, end_month, end_year) ;         // To calculate the day count of check-out date of the particular year

    if(start_year == end_year)
       {
          num_days = end_date_count - start_date_count + 1 ;   // Calculates number of days of stay ( including check-in and check-out date)
          period_check(num_days);       // To check if number of days of stay is within limits
       }
          else
             {
                // day number returns the day count of the last date of the year(31st December) i.e number of days in the respective year
                days_in_year = day_number(31, 12, start_year);       // returns 366 if leap year and 365 if non leap year

                num_days = (days_in_year - start_date_count) + end_date_count + 1 ;    // Calculates number of days of stays for bookings from December to January
                period_check(num_days);      // To check if number of days of stay is within limits
             }

     // Checking if check in dates are ahead of the booking date

    if(start_year < t.wYear)     // If the year entered is before the year of booking
      return 1 ;

    else if(start_year == t.wYear )      // If booking is done in the same year
       {
          num_days = day_number(start_day, start_month, start_year) - day_number(t.wDay, t.wMonth, t.wYear);   // Calculates number of days till check in date

          if(num_days > 30)
            return 1 ;

          if(start_month < t.wMonth )     // If entered month is before the month of booking
            return 1 ;
               else if(start_month == t.wMonth)    // If booking is done in the same month
                  {
                     if(start_day < t.wDay)        // If entered day is before the day of booking
                        return 1 ;
                     else
                        return 0 ;
                  }
                     else if(start_year > t.wYear )
                     {
                        //day number returns the day count of the last date of the year(31st December) i.e number of days in the respective year
                        days_in_year = day_number(31, 12, t.wYear);       // returns 366 if leap year and 365 if non leap year
                        num_days = (days_in_year - day_number(t.wDay, t.wMonth, t.wYear)) + day_number(start_day, start_month, start_year);    // Calculates number of days till check in date for bookings from December to January

                        if(num_days > 30)
                           return 1 ;     // returns 1 if check-in date is in the future(beyond the 30 day limit)
                        else
                           return 0 ;

                     }
       }

    else if(start_year > t.wYear)      // If booking for is for next year from the current year
    {
       // If booking is done for next year, it can only be done only for January in December (considering the 30 day pre-booking limit permitted by the hotel)
       if(t.wMonth == 12 && start_month == 1)
         return 0 ;
            else
               return 1 ;
    }

    return 0 ;

}