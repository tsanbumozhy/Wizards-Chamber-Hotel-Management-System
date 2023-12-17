void choice(void)
   {
      system("cls");    // command to clear screen

       int choice;

      printf("\n ---------------------------------------------------------------------------------------------\n");
      printf("\033[1;32m");
      printf("\t\t\t\t\t    MAIN MENU\n");
      printf("\033[0m");
      printf(" ---------------------------------------------------------------------------------------------\n");

      printf("\n Enter,");
      printf("\033[1;31m");
      printf("\n  1 for Booking.");
      printf("\033[1;32m");
      printf("\n  2 for Cancellation.");
      printf("\033[1;33m");
      printf("\n  3 for Check in/Check out.");
      printf("\033[1;34m");
      printf("\n  4 for Displaying customer records.");
      printf("\033[1;35m");
      printf("\n  5 for Details about the rooms.");
      printf("\033[1;36m");
      printf("\n  6 for Logout.");
      printf("\033[1;37m");
      printf("\n  7 for Exit.\n");
      printf("\033[0m");

      do
      {
         printf("\n Enter your choice :  ");
         scanf("%d", &choice);
         getchar();      // To  clear buffer

         switch(choice)
            {
               case 1:
                  booking();
               case 2:
                  cancellation();
               case 3:
                  check_inout();
               case 4:
                  customer_records();
               case 5:
                  about_us();
               case 6:
                  printf("\n\tLogging out.\n");
                  sleep(3);
                  login();
               case 7:
                  break;
               default:
                  printf("\n  Invalid choice.\n");
                  continue;
            }
         system("cls");
         printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t   Thank You.");
         sleep(5);
         system("cls");
         exit(0);
      }while(1);
   }