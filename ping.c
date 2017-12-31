#include <stdlib.h>
#include <stdio.h>

int Start(char ssid[20],char passwd[10]);   //For starting the hotspot
int Restart(char ssid[20],char passwd[10]);                              //For restarting the hotspot
int Close();                                //For closing the hotspot
int main()
{
    char ssid[20],passwd[10];                                                                             //Used for storing ssid and password
    char a,c;


    FILE *fptr1;                                                                                            //File pointer to access the file which has ssid and passwrord

    fptr1 = fopen("wifi.txt","r+");
    fscanf(fptr1,"%s %s",ssid,passwd);
    fclose(fptr1);

    do{

    printf(" Enter a choice no. : \n 1.Start hotspot \n 2.Restart hotspot \n 3.Stop hotspot \n");
    scanf("%c",&a);


    switch(a){                                                                                               //Swicth statement for deciding the function to call based on the input
    case '1':   printf("Starting hotspot...... \n");
                Start(ssid,passwd);
                break;
    case '2':   printf("Restarting...... \n");
                Restart(ssid,passwd);
                break;
    case '3':   printf("Closing..... \n");
                Close();
                break;

    }

    printf("Do you want to exit? (y/n)");
    c = getchar();

    }while(c == 'y'||c == 'Y');

    return 0;

}

int Start(char ssid[20],char passwd[10])                                                //Function defination of Start()
{
    FILE *fStart;

    fStart = fopen("Start.bat","w");

    fprintf(fStart,"%s\n","echo off");
    fprintf(fStart,"%s\n","netsh wlan set hostnetwork mode=allow");
    fprintf(fStart,"%s%s %s%s %s\n","netsh wlan set hostnetwork ssid=",ssid,"key=",passwd,"keyUsage=persistant");
    fprintf(fStart,"%s","netsh wlan start hostednetwork");
    fclose(fStart);
    system("start Start.bat");
    printf("Hotspot started \n");
    system("pause");

    return 0;

}
int Restart(char ssid[20],char passwd[10])                                              //Function defination for Restart()
{
    FILE *fRestart;

    fRestart = fopen("Restart.bat","w");

    fprintf(fRestart,"%s\n","echo off");
    fprintf(fRestart,"%s\n","netsh wlan set hostnetwork mode=allow");
    fprintf(fRestart,"%s%s %s%s %s\n","netsh wlan set hostnetwork ssid=",ssid,"key=",passwd,"keyUsage=persistant");
    fprintf(fRestart,"%s","netsh wlan start hostednetwork");
    fclose(fRestart);
    system("start Restart.bat");
    printf("Hotspot restarted \n");
    system("pause");
    return 0;

}
int Close()                                                                                //Function defination fro Close()
{
    FILE *fClose;

    fClose = fopen("Close.bat","w");

    fprintf(fClose,"%s\n","echo off");
    fprintf(fClose,"%s","netsh wlan stop hostednetwork");
    fclose(fClose);
    system("start Close.bat");
    printf("Hotspot closed \n");
    system("pause");


    return 0;
}

