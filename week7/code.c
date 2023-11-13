#include "utilities.h"
#include "math.h"

int main()
{
    // array of daily readings
    reading daily_readings[100];

    char line[buffer_size];
    char filename[buffer_size];

    // get filename from the user
    printf("Please enter the name of the data file: ");

    // these lines read in a line from the stdin (where the user types)
    // and then takes the actual string out of it
    // this removes any spaces or newlines.
    fgets(line, buffer_size, stdin);
    sscanf(line, " %s ", filename);

    char choice;
    int counter = 0;
    float mean = 0;
    float lowest = 0;
    float highest = 0;
    char month[4];
    float range = 0;
    float sum = 0;
    float sd = 0;


    FILE *input = open_file(filename, "r");

    while (fgets(line, buffer_size, input))
    {
        // split up the line and store it in the right place
        // using the & operator to pass in a pointer to the bloodIron so it stores it
        tokeniseRecord(line, ",", daily_readings[counter].date, &daily_readings[counter].bloodIron);
        counter++;
        sum += daily_readings[counter].bloodIron;
    }

    while (1)
    {

        printf("A: View all your blood iron levels\n");                       // BRONZE
        printf("B: View your average blood iron level\n");                    // BRONZE
        printf("C: View your lowest blood iron level\n");                     // SILVER
        printf("D: View your highest blood iron level\n");                    // SILVER
        printf("E: View the blood iron levels for a specific month\n");       // SILVER/GOLD
        printf("F: See some additional statistics about your iron levels\n"); // GOLD - see readme.md
        printf("G: Generate a graph of your iron levels\n");                  // GOLD/PLATINUM - see readme.md
        printf("Q: Exit the program\n");

        // get the next character typed in and store in the 'choice'
        choice = getchar();

        // this gets rid of the newline character which the user will enter
        // as otherwise this will stay in the stdin and be read next time
        while (getchar() != '\n');


        // switch statement to control the menu.
        switch (choice)
        {
        // this allows for either capital or lower case
        case 'A':
        case 'a':
            for (int i = 0; i < counter; i++)
            {
                printf("%s - Blood iron: %.1f\n", daily_readings[i].date, daily_readings[i].bloodIron);
            }
            fclose(input);
            break;

        case 'B':
        case 'b':
            mean = find_mean(daily_readings, counter);
            printf("Your average blood iron was %.2f\n", mean);
            break;

        case 'C':
        case 'c':
            lowest = find_lowest(daily_readings,counter);
            printf("Your lowest reading of blood iron is %.2f\n", lowest);
            break;

        case 'D':
        case 'd':
            highest = find_highest(daily_readings,counter);
            printf("Your highest reading of blood iron is %.2f\n", highest);
            break;

        case 'E':
        case 'e':
            printf("enter month to read data from (use 3 char format):");
            scanf("%s", month);
            
            monthly_iron(daily_readings, counter, month);

            break;

        case 'F':
        case 'f':
            highest = find_highest(daily_readings, counter);
            lowest = find_lowest(daily_readings, counter);
            range = highest - lowest;
            sd = calcSD(daily_readings, mean, sum, counter);


            printf("Blood iron range: %.2f\n", range);
            printf("Blood iron standard deviation: %.2f\n",sd);
            break;

        case 'G':
        case 'g':
            return 0;
            break;

        case 'Q':
        case 'q':
            return 0;
            break;

        // if they type anything else:
        default:
            printf("Invalid choice\n");
            break;
        }
    }
}