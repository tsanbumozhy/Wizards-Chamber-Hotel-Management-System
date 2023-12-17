void booking()
{
    int start_day, start_month, start_year ;
    int end_day, end_month, end_year ;
    int selected_room, status ,temp;

    int flag_date = 0 ;

    char day[10], month[10], year[10] ;

    do
    {
       system("cls");

       printf("\n ---------------------------------------------------------------------------------------------\n");
       printf("\033[1;32m");
       printf("\t\t\t\t\t     BOOKING\n");
       printf("\033[0m");
       printf(" ---------------------------------------------------------------------------------------------\n");

        printf("\nDATE OF CHECK-IN\n");
        printf("DD : ");
        scanf("%d",&start_day);
        printf("MM : ");
        scanf("%d",&start_month);
        printf("YYYY : ");
        scanf("%d",&start_year);

        printf("\nDATE OF CHECK-OUT\n");
        printf("DD : ");
        scanf("%d",&end_day);
        printf("MM : ");
        scanf("%d",&end_month);
        printf("YYYY : ");
        scanf("%d",&end_year);
        printf("\n ---------------------------------------------------------------------------------------------\n");

        // Calling date_check to check validity of entered date
        flag_date = date_check(start_day, start_month, start_year, end_day, end_month, end_year);

        if(flag_date == 0)       // Loop is terminated if entered date is valid
            break;

        // Displays message if date is in the past or future(beyond the 30 day limit)
        printf("\n\t\t\tOOh! Looks like you're trying to time travel.");
        printf("\n\t The hotel has a 30 day pre-booking limit and a 30 day maximum stay limit.");
        printf("\n\t\t\t\tPlease enter a valid date.");
        printf("\n ---------------------------------------------------------------------------------------------\n");
        system("pause");

    }while(1);

      system("cls");

      // Calling display rooms function to display available rooms
      display_rooms(start_day, start_month, start_year, end_day, end_month, end_year);

      do
      {
         printf("\n\nROOM SELECTED : ");
         scanf("%d",&selected_room);

         temp = check_roomnumber(selected_room);         // To check if entered room number exists, returns 1 if room number exists else 0

         if(temp == 1)
            break ;                    // loop terminates when temp is 1

      }while(1);

      status = 1;       // status is 1 since it is passed from booking function

      availability_status(selected_room , start_day, start_month, start_year, end_day, end_month, end_year, status);    // passing room number, status and check in and check out dates to function
      customer_details(selected_room, start_day, start_month, start_year, end_day, end_month, end_year);                   // passing check in and check out dates to function

      choice();         // Going back to main menu
}