/* GNG1106-A: HW 2: Calculate resistance value */

#include <stdio.h>
#include <stdlib.h>

#define CALCULATE_RESISTANCE_VALUE 1
#define HELP 2
#define EXIT 3
#define LOOP_CONTINUE 10

// function for printing menu of conversion between colour and digit of resistance
void print_colour_menu (void)
{
    printf("\t0 = black\n");
    printf("\t1 = brown\n");
    printf("\t2 = red\n");
    printf("\t3 = orange\n");
    printf("\t4 = yellow\n");
    printf("\t5 = green\n");
    printf("\t6 = blue\n");
    printf("\t7 = violet\n");
    printf("\t8 = gray\n");
    printf("\t9 = white\n");
}

// function for converting band3 number to greek metric prefix
char multiplier_to_metric_prefix (int multiplier)
{
    switch (multiplier)
    {
        case 3:
            return 'k';
        case 6:
            return 'M';
        case 9:
            return 'G';
        default:
            return 0;
    }

}

// function for validating integer input
int int_checker(float input)
{
    int checker = input;
    if (input==checker)
        return checker;
    else
    {
        checker = LOOP_CONTINUE;
        return checker;
    }
}

int main()
{
    int user_option = LOOP_CONTINUE, int_check;
    char band3_prefix;
    while (user_option != CALCULATE_RESISTANCE_VALUE)
    {
        float band4_value, band1 = LOOP_CONTINUE, band2 = LOOP_CONTINUE, band3 = LOOP_CONTINUE, band4 = LOOP_CONTINUE, band3multiplier, resistance_value;
        // print menu
        printf("\nPlease choose an option:\n");
        printf("\t%d. Calculate Resistance Value\n", CALCULATE_RESISTANCE_VALUE);
        printf("\t%d. Help\n", HELP);
        printf("\t%d. Exit\n", EXIT);

        scanf("%d", &user_option);
        switch(user_option)
        {
            case CALCULATE_RESISTANCE_VALUE:
            {
               while (band1==LOOP_CONTINUE)
               {
                    // determine first band digit
                    printf("Enter 1st band colour from menu:\n");
                    print_colour_menu();
                    scanf("%f", &band1);
                    // check if user_input is integer type
                    int_check = int_checker(band1);
                    if(int_check != band1)
                    {
                        printf("Please enter an integer between 0-9\n");
                        band1 = LOOP_CONTINUE;
                    }
                    else if (band1>9 || band1<0)
                    {
                        printf("Please enter an integer between 0-9\n");
                        band1 = LOOP_CONTINUE;
                    }
                    else
                        continue;
               }

               while (band2==LOOP_CONTINUE)
               {
                    // determine second band digit
                    printf("Enter 2nd band colour from menu:\n");
                    print_colour_menu();
                    scanf("%f", &band2);
                    // check if user_input is integer type
                    int_check = int_checker(band2);
                    if(int_check != band2)
                    {
                        printf("Please enter an integer between 0-9\n");
                        band2 = LOOP_CONTINUE;
                    }
                    else if (band2>9 || band2<0)
                    {
                        printf("Please enter an integer between 0-9\n");
                        band2 = LOOP_CONTINUE;
                    }
                    else
                        break;

               }

                // determine third band colour
                while (band3 == LOOP_CONTINUE)
                {
                    printf("Enter 3rd band colour from menu:\n");
                    print_colour_menu();
                    printf("\t-1 = Gold\n\t-2 = Silver\n");
                    scanf("%f", &band3);
                    int_check = int_checker(band3);
                    if(int_check != band3)
                    {
                        printf("Please enter an integer between -2-9\n");
                        band3 = LOOP_CONTINUE;
                    }
                    else
                    {
                        // determine multiplier value
                        switch ((int) band3)
                        {
                            case -1:
                                {
                                    band3multiplier = 0.1;
                                    band3_prefix = ' ';
                                    break;
                                }
                            case -2:
                                {
                                    band3multiplier = 0.01;
                                    band3_prefix = ' ';
                                    break;
                                }
                            case 0:
                            {
                                band3multiplier=1;
                                band3_prefix = ' ';
                                break;
                            }
                            case 1:
                            {
                                band3multiplier=10;
                                band3_prefix = ' ';
                                break;
                            }
                            case 2:
                            {
                                band3multiplier=100;
                                band3_prefix = ' ';
                                break;
                            }
                            case 3:
                            {
                                band3multiplier = 1;
                                band3_prefix = multiplier_to_metric_prefix(band3);
                                break;

                            }
                            case 4:
                            {
                                band3multiplier = 10;
                                band3_prefix = multiplier_to_metric_prefix(band3-1);
                                break;
                            }
                            case 5:
                            {
                                band3multiplier = 100;
                                band3_prefix = multiplier_to_metric_prefix(band3-2);
                                break;
                            }
                            case 6:
                            {
                                band3multiplier = 1;
                                band3_prefix = multiplier_to_metric_prefix(band3);
                                break;
                            }
                            case 7:
                            {
                                band3multiplier = 10;
                                band3_prefix = multiplier_to_metric_prefix(band3-1);
                                break;
                            }
                            case 8:
                            {
                                band3multiplier = 100;
                                band3_prefix = multiplier_to_metric_prefix(band3-2);
                                break;
                            }
                            case 9:
                            {
                                band3multiplier = 1;
                                band3_prefix = multiplier_to_metric_prefix(band3);
                            }

                            default:
                            {
                                band3 = LOOP_CONTINUE;
                                printf("Please enter a number between 0-9\n");
                                break;
                            }
                        }
                    }
                }

                // calculate resistance value
                resistance_value = (band1*10 + band2)*band3multiplier;

                // determine 4th band colour
                while (band4 == LOOP_CONTINUE)
                {
                    printf("Enter 4th band colour from menu:\n");
                    printf("\t1 = Gold\n");
                    printf("\t2 = Silver\n");
                    scanf("%f", &band4);
                    // check if user_input is an integer
                    int_check = int_checker(band4);
                    if(int_check != band4)
                    {
                        printf("Please enter an integer between 0-9\n");
                        band4 = LOOP_CONTINUE;
                    }
                    else if (band4>2 || band4<1)
                    {
                        printf("Please enter an integer between 0-9\n");
                        band4 = LOOP_CONTINUE;
                    }
                    else
                    {
                        // determine tolerance value
                        switch ((int) band4)
                        {
                            case 1:
                                {
                                    band4_value = .05*resistance_value;
                                    break;
                                }
                            case 2:
                                {
                                    band4_value = .1*resistance_value;
                                    break;
                                }
                            default:
                                {
                                    printf("Please enter either 1 or 2\n");
                                    band4 = LOOP_CONTINUE;
                                    break;
                                }
                        }
                    }
                }
                // print resistance value
                printf("The resistance value is %.02f%c Ohm ~ %.02f%c Ohm", resistance_value, band3_prefix, band4_value, band3_prefix);
                user_option = LOOP_CONTINUE;
                break;
            }
            case HELP:
            {
                printf("This program allows you to determine the resistance value of your resistor based on the colour bands.\n");
                break;
            }
            case EXIT:
                return 0;
            default:
            {
                printf("Please enter an integer option between 0-9\n");
                break;
            }
        }
    }
    return 0;
}
