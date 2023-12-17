// File 2
#include <stdio.h>

int main()
{
    FILE *p;   // File pointer

    p = fopen("details.dat","wb");     // opening file in write mode

    fclose(p);    // Closing file
}

