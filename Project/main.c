
/* **********************************************************HOTEL MANAGEMENT SYSTEM********************************************************** */

                                                                     //  ------------------------------------------------------------------------------------ NOTE:----------------------------------------------------------------------------------//
                                       /*
                                          ------------------------------------------------------------- FONT USED : COURIER NEW [BOLD FONTS]----------------------------------------------------------
                                          ------------------------------------------------------------------------------------ FONT SIZE : 27----------------------------------------------------------------------------------
                                                                                    All alignments are according to the above mentioned font type and font size.
                                                                  These changes need to be made in the Defaults setting of the Output Terminal before running the code.             */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>     // For pause and sleep function
#include <dos.h>        // to access current date and time

void login(void);    // Login page
void choice(void);      // Displays the menu
void booking(void);     // For booking rooms
void cancellation(void);      // For cancelling booked rooms
void check_inout(void);    // For checking-in and checking-out on the respective dates
void customer_records(void);     // For displaying all the records of previous bookings and cancellation
void about_us(void);           // For information about the hotel and rooms
void customer_details(int, int, int, int, int, int, int );     // For receiving and storing customer details
void display_rooms(int , int , int , int , int , int );              // To display available rooms and it's status
void availability_status(int , int , int, int , int , int , int , int);       // To change the availability of booked and cancelled rooms
int day_number(int, int, int);         // Returns the day count of the respective year
int date_check(int, int, int, int, int, int);   // Checking validity of date entered
void period_check(int);                   // Checking validity of period of stay
int check_roomnumber(int);         // Checking validity of room number entered

void main()
{
   login();
}