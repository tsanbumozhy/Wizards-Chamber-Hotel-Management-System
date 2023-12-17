void login(void)
   {
      char username[] = "THE WC HOTEL", password[] = "alohomora" ;   // Storing Login id and password
      char un[20], pwd[10] ;
      int i, count = 0 ;

      system("cls");

      printf("\n  --------------------------------------------------------------------------------------------\n");
      printf("\033[1;32m");
      printf("\t\t\t\t        THE WIZARD'S CHAMBER\n");
      printf("\033[0m");
      printf("  --------------------------------------------------------------------------------------------\n\n");

      do
      {
         printf("\n   Username :   ");
         printf("\033[1;35m");
         gets(un);                                          // Getting ID from the user
         printf("\033[0m");

         printf("   Password :   ");
         for(i = 0; i < 9; i++)                       // Loop terminates after encountering 9 characters
         {
            pwd[i] = getch() ;

            printf("\033[1;35m");
            printf("*");
         }
         pwd[i] = '\0' ;               // Appending Null character to pwd
         printf("\033[0m");

         if(strcmpi(un, username) == 0 && strcmp(pwd, password) == 0)      // checking user_id and password
            {
               printf("\n\n\tYou have successfully logged in.\n");
               sleep(3);      // to stay in the screen for 3 seconds
               break ;
            }

         if(strcmpi(un, username) != 0)
            printf("\n\n\tInvalid Username.\n");

               else if(strcmp(pwd, password) != 0)
                  printf("\n\n\tIncorrect Password.\n");

         printf("\n   You have %d attempts left.\n", 4-count);
         count++ ;         // To calculate the number of attempts left

         if(count == 5)   // Program terminates after 5 attempts
            exit(0);

      }while(count < 5);

   choice();               // Calling choice function with no arguments

   }