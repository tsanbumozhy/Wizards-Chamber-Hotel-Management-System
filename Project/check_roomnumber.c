int check_roomnumber(int roomno)
{
   int rooms[45];
   int i , j ;

   // Assigning room numbers to array rooms
   for(i=0; i<10; i++)
   {
      rooms[i] = 101 + i ;
      rooms[i+ 10]  = 201 + i ;
      rooms[i + 20] = 301 + i ;
      rooms[i + 30] = 401 + i ;
   }

   for(i=40,j=0; j<5; j++)
      rooms[i+j] = 501 + j ;

   for(i=0; i<45; i++)
   {
      if(roomno == rooms[i])     // Checking if room number belongs to array rooms
         return 1 ;     // returns 1 if room number is valid
   }

   printf("\nInvalid Room number.\nChoose again.\n");    // Error message
   return 0 ;
}