#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct month
{
    short id;
    char *name;
    int *dateList;
    int offset;
    short currentMonth;
    short currentDay;
    short eventDay;
    char **eventName;
    short eventIndex;
};
struct year
{
    int num;
};

void newline()
{
    printf("\n");
}
void clearit()
{
    system("clear");
}
void textWrapper(char *text)
{
    short size = 48;
    short side1 = size/2;
    short side2 = size/2;
    short textLen = strlen(text);

    side1 -= (textLen/2);
    while ((side1 + side2 + textLen) > size) 
    {
        side2--;
    }
    for (size_t i = 0; i<side1; i++) 
    {
        printf("=");
    }
    printf("|%s|",text);
    for (size_t i = 0; i<side2; i++) 
    {
        printf("=");
    }
    newline();
}

void printDay(struct month that)
{
    short spaces = 8;
    newline();
    for (size_t i = 0; i<spaces; i++) 
    {
        printf(" ");
    }
    printf("[S]  [M]  [T]  [W]  [T]  [F]  [S] \n");
    for (size_t i = 0; i<that.offset; i++) 
    {
        printf("     ");
    }
    
    short point = 0;
    short currentIndex = 0;
    for (size_t i = 0; i<6; i++)
    {
        for (size_t i = 0; i<spaces; i++) 
        {
            printf(" ");
        }
        if (point == 0) 
        {
            for (size_t i = point; i<(7-that.offset); i++) 
            {
                if (that.currentMonth && that.currentDay == that.dateList[i]) 
                {
                    printf(" \e[44m%d\e[0m   ",that.dateList[i]);
                }
                else 
                {
                    printf(" %d   ",that.dateList[i]);                
                }
                currentIndex = i;
            }
            point = currentIndex + 1;
        }
        else 
        {
            for (size_t i = point; i<(7+point); i++) 
            {
                if (that.dateList[i]==0) { break;}

                if (that.dateList[i] > 9)
                {
                    if (that.currentMonth && that.currentDay == that.dateList[i]) 
                    {
                        printf(" \e[44m%d\e[0m  ",that.dateList[i]);
                    }
                    else 
                    {
                        printf(" %d  ",that.dateList[i]);                
                    }                
                }
                else 
                {
                    if (that.currentMonth && that.currentDay == that.dateList[i]) 
                    {
                        printf(" \e[44m%d\e[0m   ",that.dateList[i]);
                    }
                    else 
                    {
                        printf(" %d   ",that.dateList[i]);                
                    }
                }
                currentIndex = i;
            }
            point = currentIndex+1;
        }
        newline();
    }
}
void printMonth(struct month that)
{
    textWrapper(that.name);
    printDay(that);
}
void assignMonth(int *that, short size)
{
    for (size_t i = 1; i<=size; i++) 
    {
        that[(i-1)] = i;
    }
}
void currentMonth(struct month that, short day)
{
    that.currentMonth = 1;
    that.currentDay = day;
    printMonth(that);
}
void insertEvent(struct month that1,struct month that2,struct month that3,struct month that4
,struct month that5,struct month that6,struct month that7,struct month that8,
struct month that9,struct month that10,struct month that11,struct month that12,
int mid, int day, char *eventName)
{
    if (mid == 1) 
    {
        that1.eventDay = day;
        that1.eventName[that1.eventIndex] = eventName;
        that1.eventIndex++;
    }
}
void checkMD(struct month that1,struct month that2,struct month that3,struct month that4
,struct month that5,struct month that6,struct month that7,struct month that8,
struct month that9,struct month that10,struct month that11,struct month that12,
int mid, int day)
{
    if (mid == 1) 
    {
        currentMonth(that1, day);
    }
    if (mid == 2) 
    {
        currentMonth(that2, day);
    
    }
    if (mid == 3) 
    {
        currentMonth(that3, day);
    }
    if (mid == 4) 
    {
        currentMonth(that4, day);    
    }
    if (mid == 5) 
    {
        currentMonth(that5, day);
    }
    if (mid == 6) 
    {
        currentMonth(that6, day);
    }
    if (mid == 7) 
    {
        currentMonth(that7, day);
    }
    if (mid == 8) 
    {
        currentMonth(that8, day);
    }
    if (mid == 9) 
    {
        currentMonth(that9, day);
    }
    if (mid == 10) 
    {
        currentMonth(that10, day);
    }
    if (mid == 11) 
    {
        currentMonth(that11, day);
    }
    if (mid == 12) 
    {
        currentMonth(that12, day);
    }
}
int main(int argc, char **argv)
{
    clearit();
    short id = 1;
    textWrapper("CalenderSystem");
    
    struct year y_1;
    y_1.num = 2025;
    
    struct month m_1;
    struct month m_2;
    struct month m_3;
    struct month m_4;
    struct month m_5;
    struct month m_6;
    struct month m_7;
    struct month m_8;
    struct month m_9;
    struct month m_10;
    struct month m_11;
    struct month m_12;

    m_1.id = id;
    id++;
    m_2.id = id;
    id++;
    m_3.id = id;
    id++;
    m_4.id = id;
    id++;
    m_5.id = id;
    id++;
    m_6.id = id;
    id++;
    m_7.id = id;
    id++;
    m_8.id = id;
    id++;
    m_9.id = id;
    id++;
    m_10.id = id;
    id++;
    m_11.id = id;
    id++;
    m_12.id = id;

    m_1.name = "January";
    m_2.name = "February";
    m_3.name = "March";
    m_4.name = "April";
    m_5.name = "May";
    m_6.name = "June";
    m_7.name = "July";
    m_8.name = "August";
    m_9.name = "September";
    m_10.name = "October";
    m_11.name = "November";
    m_12.name = "December";

    m_1.dateList = (int*)malloc(50*sizeof(int));
    m_2.dateList = (int*)malloc(50*sizeof(int));
    m_3.dateList = (int*)malloc(50*sizeof(int));
    m_4.dateList = (int*)malloc(50*sizeof(int));
    m_5.dateList = (int*)malloc(50*sizeof(int));
    m_6.dateList = (int*)malloc(50*sizeof(int));
    m_7.dateList = (int*)malloc(50*sizeof(int));
    m_8.dateList = (int*)malloc(50*sizeof(int));
    m_9.dateList = (int*)malloc(50*sizeof(int));
    m_10.dateList = (int*)malloc(50*sizeof(int));
    m_11.dateList = (int*)malloc(50*sizeof(int));
    m_12.dateList = (int*)malloc(50*sizeof(int));

    m_1.eventName = (char**)malloc(200*sizeof(double));
    m_2.eventName = (char**)malloc(200*sizeof(double));
    m_3.eventName = (char**)malloc(200*sizeof(double));
    m_4.eventName = (char**)malloc(200*sizeof(double));
    m_5.eventName = (char**)malloc(200*sizeof(double));
    m_6.eventName = (char**)malloc(200*sizeof(double));
    m_7.eventName = (char**)malloc(200*sizeof(double));
    m_8.eventName = (char**)malloc(200*sizeof(double));
    m_9.eventName = (char**)malloc(200*sizeof(double));
    m_10.eventName = (char**)malloc(200*sizeof(double));
    m_11.eventName = (char**)malloc(200*sizeof(double));
    m_12.eventName = (char**)malloc(200*sizeof(double));

    m_1.offset = 3;
    m_2.offset = 6;
    m_3.offset = 6;
    m_4.offset = 2;
    m_5.offset = 4;
    m_6.offset = 0;
    m_7.offset = 2;
    m_8.offset = 5;
    m_9.offset = 1;
    m_10.offset = 3;
    m_11.offset = 6;
    m_12.offset = 1;

    m_1.eventIndex = 
    m_2.eventIndex = 
    m_3.eventIndex = 
    m_4.eventIndex = 
    m_5.eventIndex = 
    m_6.eventIndex = 
    m_7.eventIndex = 
    m_8.eventIndex = 
    m_9.eventIndex = 
    m_10.eventIndex = 
    m_11.eventIndex = 
    m_12.eventIndex = 0;

    assignMonth(m_1.dateList, 31);
    assignMonth(m_2.dateList, 28);
    assignMonth(m_3.dateList, 31);
    assignMonth(m_4.dateList, 30);
    assignMonth(m_5.dateList, 31);
    assignMonth(m_6.dateList, 30);
    assignMonth(m_7.dateList, 31);
    assignMonth(m_8.dateList, 31);
    assignMonth(m_9.dateList, 30);
    assignMonth(m_10.dateList, 31);
    assignMonth(m_11.dateList, 30);
    assignMonth(m_12.dateList, 31);

    if (m_1.dateList == NULL)
    {
        printf("memory failed to reserved");
        newline();
        return 1;
    }

    printf("4.8KB of memory reserved!");
    newline();

    //Initialize

    printf("Year %d\n", y_1.num);

    int mid;
    int day;

    while (1) 
    {
        printf("Set Current Month(id): ");
        scanf("%2d", &mid);

        printf("Set Current Day: ");
        scanf("%2d", &day);
        if (mid > 12 || day > 31) 
        {
            clearit();
            printf("please input the right format (id/day)\n");
        }
        else
        {
            break;
        }
    }

    checkMD(m_1, m_2, m_3, m_4, 
    m_5, m_6, m_7, m_8,
     m_9, m_10, m_11, m_12, 
     mid, day);

    textWrapper("");

    newline();
    return (0);
}