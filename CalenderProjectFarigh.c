#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void addNote();
void showNote();
void printCalendar();
void findDayOfWeek();
int isLeapYear(int year);

int main()
{
    int choice;
    
    //Printing choices
    do
    {
        printf("\nMenu\n");
        printf("1. Add Note\n");
        printf("2. Show Note\n");
        printf("3. Print Calendar\n");
        printf("4. Find Day of Week\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        //calling required function as per input choice
        switch(choice)
        {
            case 1:
                addNote();
                break;
            case 2:
                showNote();
                break;
            case 3:
                printCalendar();
                break;
            case 4:
                findDayOfWeek();
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
    } while(choice != 5);
    //continues the above loop up until 5 isnot input

    return 0;
}


//function add note
void addNote()
{
    int year, date, month;
    char note[100];

    printf("\nEnter the year: ");
    scanf("%d", &year);
    printf("Enter the date: ");
    scanf("%d", &date);
    printf("Enter the month: ");
    scanf("%d", &month);
    printf("Enter the note: ");
    scanf(" %[^\n]", note);

    FILE *fp;
    fp = fopen("calendar.txt", "a");

    if(fp == NULL)
    {
        printf("Error in opening file!\n");
        return;
    }

    fprintf(fp, "%d %d %d %s\n", year, date, month, note);
    printf("Note added successfully!\n");

    fclose(fp);
}

void showNote()
{
    int year, date, month;
    char note[100];

    printf("\nEnter the year: ");
    scanf("%d", &year);
    printf("Enter the date: ");
    scanf("%d", &date);
    printf("Enter the month: ");
    scanf("%d", &month);

    FILE *fp;
    fp = fopen("calendar.txt", "r");

    if(fp == NULL)
    {
        printf("Error in opening file!\n");
        return;
    }

    int found = 0;

    while(fscanf(fp, "%d %d %d %[^\n]\n", &year, &date, &month, note) != EOF)
    {
        if(year == year && date == date && month == month)
        {
            printf("Note for %02d/%02d/%04d: %s\n", date, month, year, note);
            found = 1;
            break;
        }
    }

    if(!found)
    {
        printf("No note found for %02d/%02d/%04d.\n", date, month, year);
    }

    fclose(fp);
}

void printCalendar()
{
    int year, month, day;
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    printf("\nEnter the year: ");
    scanf("%d", &year);

    if(isLeapYear(year))
    {
        daysInMonth[1] = 29;
    }

    printf("\n");
    printf("      Calendar - %d\n", year);

    for(month = 0; month < 12; month++)
    {
            printf("---------------\n");

    // Print the days of the week
    printf(" Sun Mon Tue Wed Thu Fri Sat\n");

    // Determine the day of the week for the first day of the month
    day = 1;
    for(int i = 0; i < month; i++)
    {
        day += daysInMonth[i];
    }
    day %= 7;

    // Print the calendar for the month
    for(int i = 0; i < day; i++)
    {
        printf("    ");
    }
    for(int i = 1; i <= daysInMonth[month]; i++)
    {
        printf("%4d", i);
        day++;
        if(day % 7 == 0)
        {
            printf("\n");
        }
    }

    printf("\n");
}

}

void findDayOfWeek(){
int day, month, year, totalDays;

printf("\nEnter a valid date (dd/mm/yyyy): ");
scanf("%d/%d/%d", &day, &month, &year);

int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

if(isLeapYear(year))
{
    daysInMonth[1] = 29;
}

if(year < 1900 || year > 9999 || month < 1 || month > 12 || day < 1 || day > daysInMonth[month-1])
{
    printf("Invalid date!\n");
    return;
}

totalDays = 0;
for(int i = 1900; i < year; i++)
{
    if(isLeapYear(i))
    {
        totalDays += 366;
    }
    else
    {
        totalDays += 365;
    }
}

for(int i = 0; i < month - 1; i++)
{
    totalDays += daysInMonth[i];
}

if(isLeapYear(year) && month > 2)
{
    totalDays++;
}

totalDays += day - 1;

switch(totalDays % 7)
{
    case 0:
        printf("The day is Sunday.\n");
        break;
    case 1:
        printf("The day is Monday.\n");
        break;
    case 2:
        printf("The day is Tuesday.\n");
        break;
    case 3:
        printf("The day is Wednesday.\n");
        break;
    case 4:
        printf("The day is Thursday.\n");
        break;
    case 5:
        printf("The day is Friday.\n");
        break;
    case 6:
        printf("The day is Saturday.\n");
        break;
}
}

int isLeapYear(int year)
{
if(year % 400 == 0)
{
return 1;
}
else if(year % 100 == 0)
{
return 0;
}
else if(year % 4 == 0)
{
return 1;
}
else
{
return 0;
}
}