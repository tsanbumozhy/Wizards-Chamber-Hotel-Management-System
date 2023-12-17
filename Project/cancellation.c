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

void cancellation()
{
   FILE *p ;       // Declaring file pointer
   struct details a, b[1000];             // Declaring structure variables

   int check_bid, rn;
   int i=0, j ;
   int status = 0 ;
   int flag = 0 ;

   system("cls");

    printf("\n ---------------------------------------------------------------------------------------------\n");
    printf("\033[1;32m");
    printf("\t\t\t\t\t    CANCELLATION\n");
    printf("\033[0m");
    printf(" ---------------------------------------------------------------------------------------------\n");

   printf("\n  ENTER THE BOOKING ID :    ");
   scanf("%d", &check_bid);
   getchar();

   p = fopen("details.dat", "rb");        // opening the file in read mode

   if (p == NULL)   // a message if there is a problem in opening the file
    {
        puts("Cannot read file\n");           // Error message if booking id does not exist
        exit(0);
    }

    while(fread(&a, sizeof(a),1, p) == 1)     // Reading records one by one till the end of file
      {
         // to check if the entered booking id is valid
         if(a.booking_id == check_bid)
            {
               flag = 0;
               break;
            }
         else
            flag = 1;
      }
      rewind(p);

      if(flag == 1)
         {
            printf("\n  BOOKING ID DOES NOT EXIST\n\n  ");    // Error message if booking id does not exist
            system("pause");
            cancellation();
         }

   while(fread(&a, sizeof(a),1, p) == 1)      // Reading records one by one till the end of file
   {
      if(a.booking_id == check_bid)
      {
         if(a.check_in == 0 && a.check_out == 0)      // If attempted to book a room that has been cancelled or checked-in to
         {
            a.check_in = 8 ;           // Assigns eight to check-in to indicate that booking is cancelled
            a.check_out = 8 ;        // Assigns eight to check-out to indicate that booking is cancelled

            printf("\n  CANCELLATION SUCCESSFUL\n\n  ");

            printf("\n\t\t\t\t\t  CANCELLED RECORD");
            printf("\n ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
            printf("\n \t\t\t\t     BOOKING ID : %d\n", a.booking_id);
            printf("\n  Name         : %s", a.name);
            printf("\n  Address      : %s", a.address);
            printf("\n  Phone number : %lld", a.phone_number);
            printf("\n  Room number  : %d", a.room_number);
            printf("\n  Start date   : %d/%d/%d", a.start_date[0], a.start_date[1], a.start_date[2] );
            printf("\n  End date     : %d/%d/%d", a.end_date[0], a.end_date[1], a.end_date[2] );
            printf("\n  Price        : $%.2f", a.price);
            printf("\n  Payment      : ");
            a.payment_status ? printf("REFUNDED\n") : printf("NOT DONE\n");        // printing successful and unsuccessful for 1 and 0
            printf("\n  Room status  : CANCELLED\n");
            printf("\n ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");

         }
         else if(a.check_in == 8)
         {
            printf("\n  ROOM HAS ALREADY BEEN CANCELLED\n\n  ");
            system("pause");
            choice();
         }
         else
         {
            printf("\n  CANCELLATION DATE IS EXCEEDED\n\n  ");
            system("pause");
            choice();
         }

         rn = a.room_number ;       // rn stores respective room number to cancel booking

         // status = 0 is passed since it is passed from canceling function
         availability_status (rn , a.start_date[0], a.start_date[1], a.start_date[2], a.end_date[0], a.end_date[1], a.end_date[2], status);   // passing room number, status and check in and check out dates to function
      }

      // Storing the data in temporary array
      b[i].booking_id = a.booking_id ;
      strcpy( b[i].name, a.name) ;
      strcpy( b[i].address, a.address) ;
      b[i].phone_number = a.phone_number ;
      b[i].room_number = a.room_number ;
      b[i].start_date[0] = a.start_date[0] ;
      b[i].start_date[1] = a.start_date[1] ;
      b[i].start_date[2] = a.start_date[2] ;
      b[i].end_date[0] = a.end_date[0] ;
      b[i].end_date[1] = a.end_date[1] ;
      b[i].end_date[2] = a.end_date[2] ;
      b[i].price = a.price ;
      b[i].check_in = a.check_in ;
      b[i].check_out = a.check_out ;
      b[i].payment_status = a.payment_status ;

      i++ ;
   }
   fclose(p) ;       // closing the file

   p = fopen("details.dat", "wb");          // opening the file in write mode

   if (p == NULL)
    {
        puts("Cannot read file\n");        // Error message if booking id does not exist
        exit(0);
    }

   for(j=0; j< i ; j++)
   {
      a = b[j] ;
      fwrite(&a, sizeof(a), 1, p) ;     // Writing the data in temporary array to the file as the file gets overwritten in write mode
   }
   fclose(p) ;       // closing the file

   system("pause");

   choice() ;              // Going back to main menu
}