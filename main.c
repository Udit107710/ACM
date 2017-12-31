#include <stdio.h>
#include <stdlib.h>

int main()
{
    char ssid[20],passwd[10];
    FILE *ftp;

    ftp = fopen("wifi.txt","w");

     if(ftp == NULL)
   {
      printf("Error!");
      exit(1);
   }

   printf("Enter the SSID (Max 20 characters) : ");
   gets(ssid);

   printf("Enter password (MAX 10 characters) : ");
   gets(passwd);

   fprintf(ftp,"%s %s",ssid,passwd);                                                                //saving the data in txt file named 'wifi'

   fclose(ftp);

   return 0;


}
