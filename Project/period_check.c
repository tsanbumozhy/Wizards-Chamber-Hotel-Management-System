
void period_check(int nodays)
{
    // To check if number of days of stay is within limits
   if(nodays >= 30)     // If days of stay is more than the maximum limit permitted by the hotel
    {
       printf("\nEntered interval of days exceeds Limit.\n\nRedirecting to Booking page.\n\n");
       system("pause");
       booking();
    }

       else if(nodays < 1)    // If days of stay is 0 or negative
          {
             printf("\nEntered interval of days is Invalid.\n\nRedirecting to Booking page.\n\n");
             system("pause");
             booking();
          }

}
