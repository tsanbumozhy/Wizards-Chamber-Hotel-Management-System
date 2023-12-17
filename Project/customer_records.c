#include<stdio.h>

// Structure for storing customer details in file.
struct details
   {
       int booking_id;
       char name[50];
       char address[100];
       long long int phone_number;           // STRUCTURE FOR FILE 2
       int room_number;
       int start_date[3];
       int end_date[3];
       float price;
       int check_in;
       int check_out;
       int payment_status;
   };

void customer_records()
{
   FILE *p ;             // Declaring file pointer
   struct details display ;             // Declaring structure variable
   int count = 0 ;      // temporary variable to count number of records

   system("cls");

   p = fopen("details.dat", "rb");        // opening the file in read mode

   if (p == NULL)   // Display message if there is a problem in opening the file
    {
        puts("Cannot read file\n");
        exit(0);
    }

    printf("\n ---------------------------------------------------------------------------------------------\n");
    printf("\t\t\t\t\tCUSTOMER RECORDS\n");
    printf(" ---------------------------------------------------------------------------------------------\n");

   while(fread(&display, sizeof(display), 1, p) == 1)     // Reading records one by one till the end of file
      {
         count++ ;
         // Displaying all the records in file
         printf("\n\t\t\t\t\t   RECORD - %d", count);
         printf("\n ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
         printf("\n \t\t\t\t     BOOKING ID : %d\n", display.booking_id);
         printf("\n  Name         : %s", display.name);
         printf("\n  Address      : %s", display.address);
         printf("\n  Phone number : %lld", display.phone_number);
         printf("\n  Room number  : %d", display.room_number);
         printf("\n  Start date   : %d/%d/%d", display.start_date[0], display.start_date[1], display.start_date[2] );
         printf("\n  End date     : %d/%d/%d", display.end_date[0], display.end_date[1], display.end_date[2] );
         printf("\n  Price        : $%.2f", display.price);
         printf("\n  Payment      : ");
         display.payment_status ? printf("SUCCESSFUL\n") : printf("PENDING\n");        // printing successful and unsuccessful for 1 and 0

         if(display.check_in == 8 && display.check_out == 8)        //  8 indicates the booking is cancelled
            printf("\n  Room status  :  CANCELLED\n");
         else
            {
               display.check_in ? printf("\n    Check in   : YES") : printf("\n    Check in   : NO") ;             // printing yes and no for 1 and 0
               display.check_out ? printf("\n    Check out  : YES\n") : printf("\n    Check out  : NO\n") ;           // printing yes and no for 1 and 0
            }
         printf("\n ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
      }

   printf("\n\tTotal number of customer records : %d\n\n\t", count);

   fclose(p);       // closing the file

   system("pause");

   choice() ;                  // Going back to main menu

}