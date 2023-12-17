#include<stdio.h>

struct room_data
{
    int room_no;
    int days[366];
};

void availability_status(int room, int start_day, int start_month, int start_year, int end_day, int end_month, int end_year, int status)
{
    FILE *p ;     // Declaring file pointer
    struct room_data temp_days[366], rdata ;      // Declaring structure variables

    int i = 0, j ;
    int start_date_count, end_date_count ;

    start_date_count = day_number(start_day, start_month, start_year);      // Returns the day number of the respective year
    end_date_count = day_number(end_day, end_month, end_year);           // Returns the day number of the respective year

    p = fopen("availability.dat","rb");            // Opening the file in read mode

    if (p == NULL)      // Display message if there is a problem in opening the file
    {
        puts("Cannot read file\n");
        exit(0);
    }

    while ((fread(&rdata,sizeof(rdata),1,p)) == 1)     // Reading records one by one till the end of file
    {
        if (rdata.room_no == room)        // changing the room status for the given room number
        {
            for (j = start_date_count ; j <= end_date_count ; j++)
                {
                   if(status == 1 && rdata.days[j-1] == 0)
                      rdata.days[j-1] = status;
                        else if(status == 1 && rdata.days[j-1] == 1)       // If the user tries to book a pre booked room
                           {
                              printf("\n  The Selected room is already Booked on the respective dates.\n  Redirecting to Booking Page.\n");
                              system("pause");
                              booking();
                           }

                   if(status == 0 && rdata.days[j-1] == 1)
                      rdata.days[j-1] = status;
                         else if(status == 0 && rdata.days[j-1] == 0)      // If the user tries to cancel a canceled booked room
                           {
                              printf("\n  Cancellation Unsuccessful.\n  The selected room has already been Canceled or Checked out of.\n  Please try again.\n");
                              cancellation();
                           }

                }
        }
        temp_days[i].room_no = rdata.room_no;

        for (j = 0 ; j < day_number(31, 12, start_year); j++)     // Storing the data in temporary array
            temp_days[i].days[j] = rdata.days[j];

        i++;
    }
    fclose(p);          // closing the file

    p = fopen("availability.dat","wb");       // Opening the file in write mode
    for (i = 0 ; i < 45 ; i++)
    {
        rdata = temp_days[i];
        fwrite(&rdata,sizeof(rdata),1,p);    // Writing the data in temporary array to the file as the file gets overwritten in write mode
    }
    fclose(p);          // closing the file

}