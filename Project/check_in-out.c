#include<stdio.h>
#include <windows.h> // To access GetLocalTime()

// Structure for storing customer details in file.
struct details
   {
       int booking_id ;
       char name[50];
       char address[100];
       long long int phone_number;               // STRUCTURE FOR FILE 2
       int room_number;
       int start_date[3];
       int end_date[3];
       float price;
       int check_in;
       int check_out;
       int payment_status;
   };

void check_inout()
{
   SYSTEMTIME t ; // Declaring SYSTEMTIME struct variable, present in windows.h

   GetLocalTime(&t) ;     // For getting the present date and time from windows.h

    FILE *p ;               // Declaring file pointer
    struct details a, b[1000];             // Declaring structure variables
    int check_bid, c_inout, rn ;
    int count = 0, status = 0 ;
    int i=0, j ;
    char payment ;
    int flag = 0 ;

    system("cls");

    printf("\n ---------------------------------------------------------------------------------------------\n");
    printf("\033[1;32m");
    printf("\t\t\t\t CHECK IN / CHECK OUT\n");
    printf("\033[0m");
    printf(" ---------------------------------------------------------------------------------------------\n");

    printf("\n  ENTER THE BOOKING ID :    ");
   scanf("%d", &check_bid);

   do
   {
      printf("\n  ENTER 1 FOR CHECK-IN AND 2 FOR CHECK-OUT :   ");
      scanf("%d", &c_inout);

      if(c_inout == 1 || c_inout == 2)
         break;

      printf("\n  Invalid input, please try again.\n");
   }while(1);

   p = fopen("details.dat", "rb");        // opening the file in read mode

   if (p == NULL)    // Display message if there is a problem in opening the file
    {
        puts("Cannot read file\n");
        exit(0);
    }

   while(fread(&a, sizeof(a),1,p) == 1)
   {
      if(a.booking_id == check_bid)
         {
            if(c_inout == 1)
            {
               // If attempted to check-in to a room that is booked for a different date
               if(t.wDay != a.start_date[0] || t.wMonth != a.start_date[1] || t.wYear != a.start_date[2])
               {
                  printf("\n  Check-in should be done on %d/%d/%d.\n  Today's date is %d/%d/%d.\n\n  ", a.start_date[0], a.start_date[1], a.start_date[2], t.wDay, t.wMonth, t.wYear);
                  system("pause");
                  choice();
               }
            }
            else
                  {
                      // If attempted to check-out of a room that is booked for different dates
                     if(t.wDay != a.end_date[0] || t.wMonth != a.end_date[1] || t.wYear != a.end_date[2])
                     {
                        printf("\n  Check-out should be done on %d/%d/%d.\n  Today's date is %d/%d/%d.\n\n  ", a.end_date[0], a.end_date[1], a.end_date[2], t.wDay, t.wMonth, t.wYear);
                        system("pause");
                        choice();
                     }
                  }
         }
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
         printf("\n  BOOKING ID DOES NOT EXIST\n  ");    // Error message if booking id does not exist
         system("pause");
         check_inout();
      }

   while(fread(&a, sizeof(a),1, p) == 1)     // Reading records one by one till the end of file
  {
      if(a.booking_id == check_bid)
         {
            if(a.payment_status != 1)        // if Payment is incomplete
                  {
                     do
                     {
                        printf("\n  PAYMENT STATUS(Y/N)  :   ");
                        scanf(" %c", &payment);

                        payment = toupper(payment);

                         // printing yes and no for 1 and 0
                        if(payment == 'Y')
                           a.payment_status = 1;
                        else if(payment == 'N')
                           a.payment_status = 0;
                        else
                           {
                              printf("\n  Invalid input, please enter again.\n");
                              continue;
                           }

                        if(c_inout == 2 && a.payment_status != 1)       // If attempted to check out without paying
                          {
                           printf("\n  Payment is pending.\n  please complete payment before check-out.\n");
                           continue ;
                          }
                     break;
                     }while(1);
                  }

            rn = a.room_number ;       // rn stores respective room number to check in and check out of

            if(c_inout == 1 && a.check_in == 1)       // If attempted to check in to a room that has already been checked in to
            {
               printf("\n  Already Checked-in.\n  Redirecting to Main menu\n\n  ");
               system("pause");
               choice();
            }

            if(c_inout == 2 && a.check_out == 1)      // If attempted to check out of a room that has already been checked out of
            {
               printf("\n  Already Checked-out.\n  Redirecting to Main menu\n\n  ");
               system("pause");
               choice();
            }

            if(c_inout == 1 && a.check_out == 0)            // If attempted to check in to a room that is canceled
               {
                  printf("\n  SUCCESSFULLY CHECKED-IN \n  ");
                  a.check_in = 1 ;
               }
            else if(c_inout == 1 && a.check_out != 0)
               {
                  printf("\n  THE ROOM HAS BEEN CANCELED.\nCHECK-IN UNSUCCESSFUL\n  ");
                  system("pause");
                  check_inout();
               }

            if(c_inout == 2 && a.check_in == 1)            // If attempted to check out of a room that has not been checked in to
               {
                  printf("\n  SUCCESSFULLY CHECKED-OUT \n  ");
                  a.check_out = 1 ;
                  availability_status(rn , a.start_date[0], a.start_date[1], a.start_date[2], a.end_date[0], a.end_date[1], a.end_date[2], status );
               }
            else if(c_inout == 2 && a.check_in != 1)
               {
                  printf("\n  THE ROOM HAS NOT BEEN CHECKED IN TO\n  ");
                  system("pause");
                  check_inout();
               }
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

   p = fopen("details.dat", "wb");        // opening the file in write mode

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

   choice() ;                   // Going back to main menu

}