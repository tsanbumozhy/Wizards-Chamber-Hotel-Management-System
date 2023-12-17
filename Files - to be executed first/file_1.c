// File 1
#include <stdio.h>

struct room_data
{
    int room_no;
    int days[366];
};

int main()
{
    FILE *p;      // p is the File pointer
    struct room_data x;    // Declaring structure variable
    int i, j;

    p = fopen("availability.dat","wb");      // opening file in write mode
    if (p == NULL)
    {
        puts("Cannot create or open file.\n");     // Displays error message if file opening is unsuccessful
        exit(0);
    }
    for (i = 101 ; i < 111 ; i++)                     // Storing room numbers
    {
        x.room_no = i;
        for (j = 0 ; j < 366 ; j++)
            x.days[j] = 0;
        fwrite(&x,sizeof(x),1,p);
    }
    for (i = 201 ; i < 211 ; i++)
    {
        x.room_no = i;
        for (j = 0 ; j < 366 ; j++)
            x.days[j] = 0;
        fwrite(&x,sizeof(x),1,p);
    }
    for (i = 301 ; i < 311 ; i++)
    {
        x.room_no = i;
        for (j = 0 ; j < 366 ; j++)
            x.days[j] = 0;
        fwrite(&x,sizeof(x),1,p);
    }
    for (i = 401 ; i < 411 ; i++)
    {
        x.room_no = i;
        for (j = 0 ; j < 366 ; j++)
            x.days[j] = 0;
        fwrite(&x,sizeof(x),1,p);
    }
    for (i = 501 ; i < 506 ; i++)
    {
        x.room_no = i;
        for (j = 0 ; j < 366 ; j++)
            x.days[j] = 0;
        fwrite(&x,sizeof(x),1,p);
    }
    fclose(p);       // Closing file

}