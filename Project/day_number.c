int day_number(int day, int month, int year)
{
    int day_flag = 0, day_count, feb_days = 28 ;

   if((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
      feb_days = 29 ;       // In a leapy year, February has 29 days.

   if(month==1 || month==3 || month==5 || month==7 || month==8 || month==10 || month==12)       // For months with 31 days
      {
         if(day < 0 || day > 31)
               day_flag = 1 ;
      }
         else if( month==4 || month==6 || month==9 || month==11 )       // For months with 30 days
            {
               if(day < 0 || day > 30)
                     day_flag = 1 ;
            }
            else if(month==2)    // For February, depending on leap years
               {
                  if(day < 0 || day > feb_days)
                        day_flag = 1 ;
               }

    if(day_flag == 1)      // Checks if the entered date exists
       {
          printf("\n  The Entered date is Invalid.\n  Redirecting to Booking page.\n\n");
          system("pause");
          getchar();
          booking();
       }

    switch (month)      // passing month to determine the day number (1 to 366 or 365) in a year for a date that is given
    {
        case 1:   day_count = day ;
                        break ;

        case 2:   day_count = 31 + day ;
                         break ;

        case 3:   day_count = 31 + feb_days + day ;
                         break ;

        case 4:   day_count = feb_days + 62 + day ;
                         break ;

        case 5:   day_count = feb_days + 92 + day ;
                         break ;

        case 6:   day_count = feb_days + 123 + day ;
                         break ;

        case 7:   day_count = feb_days + 153 + day ;
                         break ;

        case 8:   day_count = feb_days + 184 + day ;
                         break ;

        case 9:   day_count = feb_days + 215 + day ;
                         break ;

        case 10:  day_count = feb_days + 245 + day ;
                          break ;

        case 11:  day_count = feb_days + 276 + day ;
                         break ;

        case 12:  day_count = feb_days + 306 + day ;
                          break ;

         default:
                          printf("\n  The Entered date is Invalid.\n\n  Redirecting to Booking page.\n\n  ");      // If entered month does not exist
                          system("pause");
                          getchar();
                          booking();
    }
    return day_count ;     // Returns the day number of the respective year
}