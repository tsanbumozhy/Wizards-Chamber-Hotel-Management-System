#include<stdio.h>

struct customer_details
   {
       int booking_id ;
       char name[50];
       char address[100];
       long long int phone_number;         // STRUCTURE FOR FILE 2
       int room_number;
       int start_date[3];
       int end_date[3];
       float price;
       int check_in;
       int check_out;
       int payment_status;
   };

void customer_details(selected_room, start_day, start_month, start_year, end_day, end_month, end_year)
{
    FILE *p;   // Declaring file pointer
    struct customer_details data ;      // Declaring structure variable

    float price ;
    int no_of_days ;
    float price_list[5] = {89.13,130.89,199.20, 289.12,690.13};      // Storing the prices for rooms
    int count = 0 ;
    long long int temp_pn ;      // Temporary variable for phone number validation
    int temp_bid ;              // Temporary variable for assigning booking ID
    char payment ;

      system("cls");

      printf("ENTER CUSTOMER DETAILS\n\n");

      printf("NAME : ");
      scanf(" %[^\n]",data.name);         // Getting the Name from user

      printf("\nADDRESS : ");
      scanf(" %[^\n]",data.address);     // Getting address from user

      do
      {
         printf("\nPHONE NUMBER : ");
         scanf("%lld",&data.phone_number);

         temp_pn = data.phone_number ;            // Assigning selected room number in the file

         count = 0;
         do
         {
             temp_pn /= 10;
             count++ ;

         } while(temp_pn != 0) ;                   // Checking if the entered phone number consists of 10 digits

         if(count == 10)
            break ;

         printf("\nEnter a valid 10 digit Phone number.\n\n");

      }while(1);

      data.room_number = selected_room ;        // Assigning selected room number to the file

      p = fopen("booking_id.txt", "r");            // Opening the file in read mode

      fscanf(p, "%d", &temp_bid);            // To get booking id from file

      fclose(p);        // Closing the file

      temp_bid++ ;
      data.booking_id = temp_bid ;          // Assigning new booking Id for the new customer

      p = fopen("booking_id.txt", "w");            // Opening the file in write mode

      fprintf(p, "%d", temp_bid);            // printing the booking id to the file

      fclose(p);        // Closing the file

      system("cls");

      printf("\n ---------------------------------------------------------------------------------------------\n");
      printf("\033[1;32m");
      printf("\t\t\t\t\tBOOKING CONFIRMATION\n");
      printf("\033[0m");
      printf(" ---------------------------------------------------------------------------------------------\n");

      printf("\n  BOOKING ID          :   %d", data.booking_id);
      printf("\n  NAME                :   %s", data.name);
      printf("\n  PHONE NUMBER        :   %lld", data.phone_number);
      printf("\n  ROOM NO             :   %d\n",selected_room);

      printf("  DATE OF CHECK-IN    :   %d/%d/%d\n",start_day,start_month,start_year);
         data.start_date[0] = start_day ;
         data.start_date[1] = start_month ;
         data.start_date[2] = start_year ;

      printf("  DATE OF CHECK-OUT   :   %d/%d/%d\n",end_day,end_month,end_year);
         data.end_date[0] = end_day ;
         data.end_date[1] = end_month ;
         data.end_date[2] = end_year ;

      price = price_list[(selected_room/100) - 1] ;         // finding the index of the price_list array to determine the price of the particular room

      no_of_days = day_number(end_day, end_month, end_year) - day_number(start_day, start_month, start_year) + 1;    // Calculating number of days of stay (both inclusive)

      price *= no_of_days ;   // Calculating total price for total number of days of stay

      printf("\n  PRICE               :   $%.2f\n",price);
      data.price = price;

      data.check_in = 0;      // Initially when booking check-in becomes 0
      data.check_out = 0;   // Initially when booking check-out becomes 0

      do
      {
         printf("\n  PAYMENT STATUS(Y/N) :   ");
         scanf(" %c", &payment);

         payment = toupper(payment);

         if(payment == 'Y')
            data.payment_status = 1;      // Assigning 'Y' and 'N' as 1 and 0 in file
         else if(payment == 'N')
            data.payment_status = 0;
         else
            {
               printf("\n  Invalid input, please enter again.\n");
               continue;
            }

         break;
      }while(1);                       // Checking payment status

      p = fopen("details.dat", "ab");     // Opening the file in append mode
      fwrite(&data,sizeof(data),1,p);

      printf("\n\n  BOOKING CONFIRMED FOR %s!!!\n\n  ",data.name);      // confirmation message

      fclose(p);        // Closing file

      system("pause");
}