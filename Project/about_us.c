void about_us(void)
{
      system("cls");

      printf("\n  --------------------------------------------------------------------------------------------\n");
      printf("\033[1;32m");
      printf("\t\t\t\t        THE WIZARD'S CHAMBER\n");
      printf("\033[0m");
      printf("  --------------------------------------------------------------------------------------------\n\n");

      int option ;

      printf("\n Enter,");
      printf("\033[1;31m");
      printf("\n  1 for room types.");
      printf("\033[1;33m");
      printf("\n  2 for rooms available for booking.");
      printf("\033[1;34m");
      printf("\n  3 for amenities available.");
      printf("\033[1;35m");
      printf("\n  4 for contact details.");
      printf("\033[1;36m");
      printf("\n  5 to go back to main menu.\n");

      printf("\033[1;37m");
      printf("\n  Enter you choice :  ");
      scanf("%d", &option);
      printf("\033[0m");

      switch(option)
      {
         case 1:
                        type_of_rooms();
         case 2:
                        display();
         case 3:
                        amenities();
         case 4:
                        contact_details();
         case 5:
                        choice();

         default:
                        printf("\n  Invalid choice.\n  Please try again.\n");
                        about_us();
      }

}

void type_of_rooms();

void type_of_rooms()
{
      system("cls");

      printf("\n  --------------------------------------------------------------------------------------------\n");
      printf("\033[1;32m");
      printf("\t\t\t\t       THE WIZARD'S CHAMBER\n");
      printf("\033[0m");
      printf("  --------------------------------------------------------------------------------------------\n");

      printf("\033[1;35m");
      printf("\n\t\tThe wizard's chamber is the ultimate Harry Potter themed accommodation, ");
      printf("\n     located in the heart of New York. It features the perfect wizarding experience with ");
      printf("\n     floating candles, a wizard common room themed lounge and a heated swimming pool. ");
      printf("\n     All rooms in our hotel are themed based on the harry potter books.");
      printf("\n     There are plenty of themed artifacts which make you feel like you are in a real ");
      printf("\n     witch\'s or wizard\'s house. The wizard's chamber accommodates kids of all ages.");
      printf("\n     We have toys, wands, candies and cos-play costumes.\n");
      printf("\033[1;31m");
      printf("\n\t        A wizard's gathering will be held at the party hall, every evening.");
      printf("\n\t     Let your inner wizard or witch experience whimsy and fun in every corner.\n");

      printf("\033[1;36m");
      printf("\n  All rooms consist of");
      printf("\n    ~ Air conditioning");
      printf("\n    ~ Free Wi-Fi");
      printf("\n    ~ 3+ Charging ports");
      printf("\n    ~ Ironing facilities");
      printf("\n    ~ Satellite/cable channels");
      printf("\n    ~ Shower");
      printf("\n    ~ Walk-in closet");
      printf("\n    ~ Towels");

      printf("\n  Read more... - ");
      system("pause");

      printf("\033[0m");
      printf("\n\t\t\t\t            Room Types\n");
      printf("\033[1;33m");
      printf("\n The top floor consists of five wizard themed rooms which embrace the wizarding experience.");
      printf("\n Four of which are based on the four Hogwarts houses and a common wizarding room \n with access to the terrace.");
      printf("\n The Wizard themed suite rooms comes with 4 single sized four poster beds, ");
      printf("\n a grand fire place, and flickering candles all surrounding a cozy living space with it\'s own");
      printf("\n fully equipped kitchen with a coffee maker and a mini fridge for beverages.\n");
      printf("\033[0m");

      printf("\n\t\t\t\t\tFloor - 5 [$690.13]");
      printf("\033[1;34m");
      printf("\n  501 - Gryffindor common room ");
      printf("\n  502 - Slytherin common room");
      printf("\n  503 - Ravenclaw common room");
      printf("\n  504 - Hufflepuff common room");
      printf("\n  505 - The order of the Phoenix [With Terrace access]\n\n  ");
      printf("\033[0m");

      printf("\n\t\t\t\t\tFloor - 4 [$289.12]");
      printf("\033[1;34m");
      printf("\n  401 - Deluxe room with 1 King size bed with and a balcony lake view");
      printf("\n  402 - Deluxe room with 1 King size bed with and a balcony lake view");
      printf("\n  403 - Deluxe room with 1 King size bed with and a garden lake view");
      printf("\n  404 - Deluxe room with 1 King size bed with and a garden lake view");
      printf("\n  405 - Double room with 1 King size bed and 1 single bed");
      printf("\n  406 - Double room with 1 King size bed and 1 single bed");
      printf("\n  Read more... - ");
      system("pause");
      printf("\n  407 - Double room with 1 King size bed and 1 single bed");
      printf("\n  408 - Double bedroom with 2 double beds");
      printf("\n  409 - Double bedroom with 2 double beds");
      printf("\n  410 - Double bedroom with 2 double beds\n\n");
      printf("\033[0m");

      printf("\n\t\t\t\t\tFloor - 3 [$199.20]");
      printf("\033[1;34m");
      printf("\n  301 - Family room with 1 Queen size bed and a 2-bunk beds");
      printf("\n  302 - Family room with 1 Queen size bed and a 2-bunk beds");
      printf("\n  303 - Family room with 1 Queen size bed and a 2-bunk beds");
      printf("\n  304 - Family room with 1 Queen size bed and a 2-bunk beds");
      printf("\n  305 - Family room with 1 Queen size bed and a 2-bunk beds");
      printf("\n  306 - Deluxe room with 1 Queen size bed and 1 double bed");
      printf("\n  307 - Deluxe room with 1 Queen size bed and 1 double bed");
      printf("\n  308 - Deluxe room with 1 Queen size bed and 1 double bed");
      printf("\n  309 - Deluxe room with 1 double bed and 2 single beds");
      printf("\n  310 - Deluxe room with 1 double bed and 2 single beds");
      printf("\033[0m");

      printf("\n\n\t\t\t\t\tFloor - 2 [$130.89]");
      printf("\033[1;34m");
      printf("\n  201 - Murphy room with 1 double bed, 1 single bed and a murphy bed");
      printf("\n  202 - Murphy room with 1 double bed, 1 single bed and a murphy bed");
      printf("\n  203 - Murphy room with 1 double bed, 1 single bed and a murphy bed");
      printf("\n  204 - Murphy room with 1 double bed, 1 single bed and a murphy bed");
      printf("\n  205 - Room with 1 double bed and 1 bunk bed");
      printf("\n  206 - Room with 1 double bed and 1 bunk bed");
      printf("\n  207 - Room with 1 double bed and 1 bunk bed");
      printf("\n  208 - Room with 1 double bed and 1 bunk bed");
      printf("\n  209 - Room with 2 bunk beds");
      printf("\n  210 - Room with 2 bunk beds");
      printf("\033[0m");

      printf("\n\n\t\t\t\t\tFloor - 1 [$89.13]");
      printf("\033[1;34m");
      printf("\n  101 - Single room with 1 double bed");
      printf("\n  102 - Single room with 1 double bed");
      printf("\n  103 - Single room with 1 double bed");
      printf("\n  104 - Single room with 1 double bed");
      printf("\n  105 - Single room with 2 single beds");
      printf("\n  106 - Single room with 2 single beds");
      printf("\n  107 - Single room with 2 single beds");
      printf("\n  108 - Single room with 2 single beds");
      printf("\n  109 - Single room with 1 Queen size bed");
      printf("\n  110 - Single room with 1 Queen size bed\n\n  ");
      printf("\033[0m");

      system("pause");
      about_us();

}

void display(void);

void display()
{
    int start_day, start_month, start_year ;
    int end_day, end_month, end_year ;
    int selected_room, status ,temp;

    int flag_date = 0 ;

    char day[10], month[10], year[10] ;

   do
    {
        system("cls");
        printf("\n  --------------------------------------------------------------------------------------------\n");
        printf("\033[1;32m");
        printf("\t\t\t\t       THE WIZARD'S CHAMBER\n");
        printf("\033[0m");
        printf("  --------------------------------------------------------------------------------------------\n");

        printf("\n\nDATE OF CHECK-IN\n");
        printf("  DD : ");
        scanf("%d",&start_day);
        printf("  MM : ");
        scanf("%d",&start_month);
        printf("  YYYY : ");
        scanf("%d",&start_year);

        printf("\nDATE OF CHECK-OUT\n");
        printf("  DD : ");
        scanf("%d",&end_day);
        printf("  MM : ");
        scanf("%d",&end_month);
        printf("  YYYY : ");
        scanf("%d",&end_year);
        printf("\n ---------------------------------------------------------------------------------------------\n");

        // Calling date_check to check validity of entered date
        flag_date = date_check(start_day, start_month, start_year, end_day, end_month, end_year);

        if(flag_date == 0)       // Loop is terminated if entered date is valid
            break;

        // Displays message if date is Invalid.
        printf("\n\t\t\tOOh! Looks like you're trying to time travel.\n\t\t\t\tPlease enter a valid date.\n");
        printf("\n ---------------------------------------------------------------------------------------------\n");
        system("pause");

    }while(1);

      system("cls");

      display_rooms(start_day, start_month, start_year, end_day, end_month, end_year);

      printf("\n\n");
      system("pause");
      about_us();
}

void amenities();

void amenities()
{
   system("cls");

   printf("  --------------------------------------------------------------------------------------------\n");
   printf("\033[1;32m");
   printf("\t\t\t\t      THE WIZARD'S CHAMBER\n");
   printf("\033[0m");
   printf("  --------------------------------------------------------------------------------------------\n");

   printf("\n\t\t COVID MEASURES\n");
   printf("\n  What you can expect during your stay ?\n");
   printf("\n   ~  All linens sanitized in high-temperature wash");
   printf("\n   ~  Face masks required for guests and staff in public areas");
   printf("\n   ~  Floors marked for social distancing");
   printf("\n   ~  Hand sanitizer available to guests & staff");
   printf("\n   ~  Regularly sanitized high-traffic areas");
   printf("\n   ~  Staff required to regularly wash hands");
   printf("\n   ~  Contact-less check-in");
   printf("\n   ~  Contact-less check-out");
   printf("\n   ~  Contact-less food delivery");
   printf("\n   ~  Constant Temperature Monitoring\n");

   printf("\n\tCleanliness and safety measures\n");
   printf("\n  .  First aid kit");
   printf("\n  .  Hand sanitizer");
   printf("\n  .  Physical distancing of at least 1 meter");
   printf("\n  Read more... - ");
   system("pause");
   printf("\n  .  Protective screens in common areas");
   printf("\n  .  Safe dining setup");
   printf("\n  .  Staff trained in safety protocol\n");

   printf("\n\n\t\t\t\t\t AMENITIES\n");
   printf("\033[1;35m");
   printf("\n\t\t* Front desk[24 x 7]\t* Free wifi\t* Complementary breakfast");
   printf("\n\t\t* Swimming pool   \t* Kids pool\t* Fitness center");
   printf("\n\t\t* Free Car Parking\t* Casino\t* Spa\n\n");
   printf("\033[0m");

   printf("\n\tServices and conveniences\n");
   printf("\n   ~  Room service");
   printf("\n   ~  Concierge");
   printf("\n   ~  Daily housekeeping");
   printf("\n   ~  Elevator");
   printf("\n   ~  Doorman for every floor");
   printf("\n   ~  Laundry service");
   printf("\n   ~  Dry cleaning");
   printf("\n   ~  Food delivery");
   printf("\n   ~  Facilities for disabled guests");
   printf("\n   ~  Security [24 x 7]\n\n   ");

   system("pause");
   about_us();
}

void contact_details();

void contact_details()
{
   system("cls");

   printf("  --------------------------------------------------------------------------------------------\n");
   printf("\033[1;32m");
   printf("\t\t\t\t        THE WIZARD'S CHAMBER\n");
   printf("\033[0m");
   printf("  --------------------------------------------------------------------------------------------\n");

   printf("\n\n  The Wizard's chamber,");
   printf("\033[1;35m");
   printf("\n  Located @ 13 East 13th Street, Cornelia street, New York (NY), United States, 10016.\n");
   printf("\033[1;34m");
   printf("\n  Contact us @ +1 615-590-4050 (or) +1 130-120-1989");
   printf("\033[0m");
   printf("\n  available 24 x 7 \n");
   printf("\033[1;33m");
   printf("\n  Any queries, feedbacks or suggestions can be emailed at thewizardschamber@gmail.com\n\n\n  ");
   printf("\033[0m");

   system("pause");
   about_us();
}