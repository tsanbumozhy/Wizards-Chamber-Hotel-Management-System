#include<stdio.h>

struct room_data
   {
       int room_no;
       int days[366];
   };

void display_rooms(int start_day, int start_month, int start_year, int end_day, int end_month, int end_year)
{
    FILE *p ;     // Declaring file pointer
    struct room_data display ;      // Declaring structure variable

    p = fopen("availability.dat","rb");      // Opening the file in read mode

    if (p == NULL)   // Display message if there is a problem in opening the file
    {
        puts("\nFile open unsuccessful.\n");
        exit(0);
    }

    char month_name[12][4] = {"JAN","FEB","MAR","APR","MAY","JUN","JUL","AUG","SEP","OCT","NOV","DEC"} ;    // Initializing month names to array

    int start_date_count, end_date_count, temp_date_count ;
    int i, no_of_days, month_change_count, temp ;

    system("cls");

    printf("\n  ---------------------------------------------------------------------------------------------\n");
    printf("\033[1;32m");
    printf("\t\t\t\t\t   AVAILABILITY\n");
    printf("\033[0m");
    printf(" ---------------------------------------------------------------------------------------------\n");

    // Displays check in and check out dates for confirmation
    printf("DATE OF CHECK-IN: %d/%d/%d\n",start_day, start_month, start_year);
    printf("DATE OF CHECK-OUT: %d/%d/%d\n",end_day, end_month, end_year);

    start_date_count = day_number(start_day, start_month, start_year) ;    // Returns the day number of the respective year
    end_date_count = day_number(end_day, end_month, end_year) ;         // Returns the day number of the respective year

    temp_date_count = day_number(31,12, start_year);     //  returns the day count of 31st December i.e number of days in the respective year(366 if leap else 365)

    if(start_year == end_year)
       no_of_days = end_date_count - start_date_count + 1 ;    // calculating number of dates if booking is done for dates in the same year
          else
             no_of_days = (temp_date_count - start_date_count) + end_date_count + 1 ;  // calculating number of dates if booking is done between years

    printf("\nNUMBER OF DAYS OF STAY :  %d\n", no_of_days);    // displays number of days of stay for confirmation

    printf("\nROOM ");

    if (start_month != end_month)      // if booking is done between months
       {
           month_change_count = no_of_days - end_day ;

           for (i = 0 ; i < month_change_count ; i++)
               printf("%s %2d  ",month_name[start_month-1] , start_day+i) ;

           for (i = 1 ; i <= end_day ; i++)
               printf("%s %2d  ",month_name[end_month-1] , i) ;
       }
          else    // if check-in and check-out  is in the same month
             {
                 for (i = start_day ; i <= end_day ; i++)
                     printf("%s %2d  ",month_name[start_month-1],i);
             }

    printf("\n");

    while (fread(&display,sizeof(display),1,p) == 1)     // Reading records one by one till the end of file
       {
           temp = 0;                // temp = 1 indicates that the room is booked on the mentioned days to avoid printing the respective room number
           if(start_year == end_year)
           {
              for (i = start_date_count - 1 ; i < end_date_count ; i++)
                    if(display.days[i] != 0)
                        {
                           temp = 1;
                           break;
                        }

              if(temp == 0)
              {
                 printf("%d :",display.room_no);

                 for (i = start_date_count - 1 ; i < end_date_count ; i++)
                    printf("%6d  ",display.days[i]);

                  printf("\n");
              }

           }
           else
           {
               for(i = start_date_count - 1 ; i < temp_date_count; i++)
                  if(display.days[i] != 0)
                     {
                        temp = 1;
                        break;
                     }

               if(temp == 0)
               {
                  for(i = 0; i < end_date_count; i++)
                     if(display.days[i] != 0)
                        {
                           temp = 1;
                           break;
                        }
               }

               if(temp == 0)
                 {
                    printf("%d :",display.room_no);

                    for (i = start_date_count - 1 ; i < temp_date_count ; i++)
                        printf("%6d  ",display.days[i]);
                    for (i = 0; i < end_date_count; i++)
                        printf("%6d  ",display.days[i]);

                     printf("\n");
                 }
           }
       }

    fclose(p);       // closing the file
}