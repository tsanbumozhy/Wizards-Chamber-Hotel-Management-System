// File 3
#include <stdio.h>

int main()
{
   int booking_id = 1000000 ;    // initializing booking id to a number

    FILE *p;      // declaring file pointer

    p = fopen("booking_id.txt","w");      // Opening text file in write mode

    fprintf(p, "%d", booking_id);      // Storing booking id in file

    fclose(p);    // Closing file
}

