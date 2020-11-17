/**********
*╔╦╗╦╔╦╗╔═╗*
* ║ ║║║║║╣ *
* ╩ ╩╩ ╩╚═╝*
***********/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct Time //Structures declaration
{
  int hour;
  int minute;
}Time;

void adder(Time time, int add); //Function declaration

int main()
{
  Time time; //Program variables
  int add, flag;
  do //Do while loop, validating time is makes sense
  {
    rewind(stdin); //Reset input, avoiding infinite loop
    printf("Enter current time and minutes to add: ");
    flag = ((scanf("%d %d %d", &time.hour, &time.minute, &add) && (time.hour >= 0) && (time.hour <= 23) && (time.minute >= 0) && (time.minute <= 59) && (add >= 0))); //Logic test for sold amount to be a positive integer
    flag == 0 ? printf("Enter time properly.\n") : 0; //Error printing if necessary
  }
  while (flag == 0); //If test failed, retuning to another round
  adder(time, add);
  return 0;
}

/*Function name: adder
Input: Time structure and integer represent the time to add in minutes
Output: None
Algorithm: Define time as 60 minutes, calculate and print*/
void adder(Time time, int add)
{
  int hours, minutes, swtichVal; //Function variables
  time.hour < 10 && time.minute < 10 ? swtichVal = 0 : 0; //Logic test
  time.hour < 10 && time.minute >= 10 ? swtichVal = 1 : 0; //To check
  time.hour >= 10 && time.minute < 10 ? swtichVal = 2 : 0; //How to print
  time.hour >= 10 && time.minute >= 10 ? swtichVal = 3 : 0; //Properly
  switch (swtichVal)
  {
    case 0: printf("The time is: 0%d:0%d\n", time.hour, time.minute); break; //Printing the right time
    case 1: printf("The time is: 0%d:%d\n", time.hour, time.minute); break;
    case 2: printf("The time is: %d:0%d\n", time.hour, time.minute); break;
    case 3: printf("The time is: %d:%d\n", time.hour, time.minute); break;
  }
  hours = add/60; //Calculate the time to add
  minutes = add%60;
  time.minute+minutes >= 60 ? (time.minute += (minutes-60), time.hour++) : (time.minute += minutes); //Foramting the time properly
  time.hour+hours >= 24 ? (time.hour += (hours-24)) : (time.hour += hours);
  time.hour < 10 && time.minute < 10 ? swtichVal = 0 : 0; //Logic test
  time.hour < 10 && time.minute >= 10 ? swtichVal = 1 : 0; //To check
  time.hour >= 10 && time.minute < 10 ? swtichVal = 2 : 0; //How to print
  time.hour >= 10 && time.minute >= 10 ? swtichVal = 3 : 0; //Properly
  switch (swtichVal)
  {
    case 0: printf("The new time is: 0%d:0%d\n", time.hour, time.minute); break; //Printing the right time
    case 1: printf("The new time is: 0%d:%d\n", time.hour, time.minute); break;
    case 2: printf("The new time is: %d:0%d\n", time.hour, time.minute); break;
    case 3: printf("The new time is: %d:%d\n", time.hour, time.minute); break;
  }
}
