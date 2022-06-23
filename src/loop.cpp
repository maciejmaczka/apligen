// ------------------------------------ lib ----------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <iostream>
#include <cstring>
#include <regex.h>
#include <assert.h>
// -------------------------------------- h ----------------------------------------------




// -------------------------------------- cpp ---------------------------------------------


// ---------------------------------------code --------------------------------------------
void print_with_formatting( const unsigned int value );
bool find_in_string ( char* text , char* character);

int generate ()
{

    int SECONDS_IN_AN_HOUR    =	3600;       // for time calc
    int SECONDS_IN_A_MINUTE   =	60;         // for time calc
    int time_elapsed;                       // for time calc

    int counters[max_length + 1];           // counters for each position in output stream + 1 for end condition state
    int *p_counters;                                        // counter[gen max + 1 ] indicates overflow of last counter [gen max]
    p_counters = counters;


    char output[max_length];
    char *p_output;
    p_output = output;

    char output_invert[max_length];
    char *p_output_invert;
    p_output_invert = output_invert;

    char *p_line_buffer[50];



    int write_error_flag = 0;
    int current_file = 0;
    int switch_file_counter = 0;
    int end_condition = 0;
    int k, h, i, m, x , p;

    int output_length;
    int output_length_invert;

    char write_line[100];
    char *p_write_line;
    p_write_line = write_line;

    char write_line_temp[100];
    char *p_write_line_temp;
    p_write_line_temp = write_line_temp;

     int count = 0;
     int break_flag = -1;
     int mask_number;



    int count_lower = 0;
    int count_upper = 0;
    int count_number = 0;
    int count_special = 0;


    int ascii_value;
    char hex_value[4];
    char hex_stream[100];

    int ad = 0;

    int pim_counter = 0;

    char *str_cont;

    regmatch_t match;              // regex match obiect

    long int stop_counter = 0;

  //  char temp_rand_buffer[100];


   for ( int i = 0 ; i < max_length + 1 ; i++)        // set -1 for all counters
    {

        p_line_buffer[i] = line_buffer[i];
    }


    for ( int i = 0 ; i < max_length + 1 ; i++)        // set -1 for all counters
    {

        p_counters[i] = -1;

    }


    for ( int i = 0 ; i < max_length ; i++)            // set 0 for initial counters
    {

        p_counters[i] = 0;

    }





    // when -1 no character is copied from line_buffer to output file
    // whne 0 character is copied
    // f.e.
    // gen max = 5
    // gen min = 3
    // counters state
    // 0  0  0  -1 -1
    // generated will be password with length 3 - 5


    cout << "Start ... " << endl << endl ;    // start
    clock_t start = clock();        // start a clock
    bzero(output, max_length + 1);      // clear structure



    if (loop_type == 1)
    {


        do
        {


            for (k = 0 ; k < max_length ; k++)
            {

                if(p_counters[k] == -1)
                {

                    break;

                }

                p_output[k] = p_line_buffer[k][p_counters[k]];


            }


        // ---------------------------------- PIM processing start -----------------------------------



       //   cout << ((pim_counter ) % parallel_process_count )  ;

        {


            if (pim_counter == 100)
            {

                pim_counter = 0;

            }



            if ( (pim_counter   % (parallel_process_count)) == (parallel_process_current_element -1))
            {






           //         pim_counter = -1;









        // ----------------------------- writing to file ---------------------------------------


            write_error_flag = fprintf(file_output[current_file], "%s\n", p_output);




        // ------------------------------ pim processing stop ----------------------------


            }
        }


        pim_counter++;



        // --------------------- if many outpu files - switch file ----------------------

            if (files_in_table != 1)
            {

                switch_file_counter++;
                if (switch_file_counter == 200)
                {

                    switch_file_counter = 0;
                    current_file++;



                    if (current_file == files_in_table)
                    {

                        current_file = 0;


                    }



                }
            }

            if (write_error_flag < 0)
            {

                cout << "Write Error" << endl;
                return -1;

            }

            p_counters[0]++;

            // increase counters

            for ( h = 0 ; h < max_length ; h++)
            {

                if (p_counters[h] == (signed int) strlen(p_line_buffer[h]))
                {

                    p_counters[h] = 0;
                    p_counters[h+1]++;

                    if (h + 1 == max_length -1)
                    {

                            // progress indicator

                            printf ("%3.1f %% \n",(float)  p_counters[max_length -1] / strlen(p_line_buffer[h])  * 100 );


                    }


                }




            }


            if (p_counters[max_length] == 0)
            {

                end_condition = 1;

            }

        }while(end_condition == 0);

    }







    if (loop_type == 2)
    {


        do
        {


            for (k = 0 ; k < max_length ; k++)
            {

                if(p_counters[k] == -1)
                {

                    break;

                }

                p_output[k] = p_line_buffer[k][p_counters[k]];
                strcpy(p_write_line, p_output);

            }


        // ---------------------------------- PIM processing start -----------------------------------



       //   cout << ((pim_counter ) % parallel_process_count )  ;

        {


            if (pim_counter == 100)
            {

                pim_counter = 0;

            }



            if ( (pim_counter   % (parallel_process_count)) == (parallel_process_current_element -1))
            {






           //         pim_counter = -1;










        //  ------------------------------- invert ---------------------------------------------


            if (invert_set == 1)
            {

                output_length = strlen(p_output);
                output_length_invert = output_length;


                for( i = 0 ; i < output_length ; i++)
                {

                    p_output_invert[i] = p_output[output_length_invert - 1];
                    output_length_invert--;




                }

                strncpy(p_output, p_output_invert, output_length );
                strcpy(p_write_line, p_output);

            }

        // -----------------------------concat --------------------------------------------------



                if (concat_at_begining !=NULL)
                {

                    strcpy(p_write_line, concat_at_begining);
                    strcat(p_write_line, p_output);


                }


                if (concat_at_end != NULL)
                {

                    if (concat_at_begining == NULL)
                    {
                            strcpy(p_write_line, p_output);
                            strcat(p_write_line, concat_at_end);
                    }
                    else
                    {
                            strcpy(p_write_line, concat_at_begining);
                            strcat(p_write_line, p_output);
                            strcat(p_write_line, concat_at_end);


                    }


                }



        // ----------------------------- writing to file ---------------------------------------


            write_error_flag = fprintf(file_output[current_file], "%s\n", p_write_line);








        // ------------------------------ pim processing stop ----------------------------


            }
        }


        pim_counter++;




        // --------------------- if many outpu files - switch file ----------------------

            if (files_in_table != 1)
            {

                switch_file_counter++;
                if (switch_file_counter == 200)
                {

                    switch_file_counter = 0;
                    current_file++;



                    if (current_file == files_in_table)
                    {

                        current_file = 0;


                    }



                }
            }

            if (write_error_flag < 0)
            {

                cout << "Write Error" << endl;
                return -1;

            }

            p_counters[0]++;

            // increase counters

            for ( h = 0 ; h < max_length ; h++)
            {

                if (p_counters[h] == (signed int) strlen(p_line_buffer[h]))
                {

                    p_counters[h] = 0;
                    p_counters[h+1]++;

                    if (h + 1 == max_length -1)
                    {

                            // progress indicator


                            printf ("%3.1f %% \n",(float)  p_counters[max_length -1] * 100 / strlen(p_line_buffer[h])   );


                    }


                }

            }


            if (p_counters[max_length] == 0)
            {

                end_condition = 1;

            }

        }while(end_condition == 0);


    }


    if (loop_type == 3)
    {


        do
        {

            if (list_flag != 0)
            {

                // randomizing line buffer each time



                  for (int x = 0 ; x < max_length ; x ++)        // randomize all sets seperatly
                    {

                        int  characters_left = 0;                   // number of characters
                        int  current_character = 0;

                        char temp_buffer[100];                            // temporary buffer for calcs
                        int line_buffer_size = 0;                             // size of buffer - foc calcs

                        line_buffer_size = strlen(line_buffer[x]);        // get structure length

                        bzero(temp_buffer, 100);                              // clear structure
                        srand ( time(NULL) * x);                                // randozmie



                        for (int i = 0 ; i < line_buffer_size ; i++)        // get all characters
                        {

                            characters_left = strlen(line_buffer[x]);          // check how mamy characters left
                            current_character = rand() % characters_left;            // from left characters get random character


                            temp_buffer[i] = line_buffer[x][current_character];    // copy selected character to temp_buffer;


                            for (int j = current_character; j < characters_left ; j++)          // remove selected character from line_buffer
                            {

                                line_buffer[x][j] = line_buffer[x][j+1];           // move next characters to prev position


                            }

                          //  line_buffer_output[x][characters_left - 1] = NULL;                    // finish string with null


                        }


                        strcpy(line_buffer[x],temp_buffer);                    // copy to line_buffer to proceed
                       // strcpy(line_buffer_output[x+1], temp_buffer);


                    }



                   for ( int i = 0 ; i < max_length + 1 ; i++)        // set -1 for all counters
                    {

                        p_line_buffer[i] = line_buffer[i];
                  //      cout << p_line_buffer[i] << endl;





                    }


                        for (k = 0 ; k < max_length ; k++)
                        {

                            if(p_counters[k] == -1)
                            {

                                break;

                            }

                            p_output[k] = p_line_buffer[k][p_counters[k]];
                            strcpy(p_write_line, p_output);

                        }


            }
            else
            {

                for (k = 0 ; k < max_length ; k++)
                {

                    if(p_counters[k] == -1)
                    {

                        break;

                    }

                    p_output[k] = p_line_buffer[k][p_counters[k]];
                    strcpy(p_write_line, p_output);

                }

            }
        // ---------------------------------- rule password list --------------------------------

        // randomize at each iteration

        if (list_flag == 1)
        {


        }
        // ---------------------------------- PIM processing start -----------------------------------



       //   cout << ((pim_counter ) % parallel_process_count )  ;

        {


            if (pim_counter == 100)
            {

                pim_counter = 0;

            }



            if ( (pim_counter   % (parallel_process_count)) == (parallel_process_current_element -1))
            {






           //         pim_counter = -1;












        //  ------------------------------- invert ---------------------------------------------


            if (invert_set == 1)
            {

                output_length = strlen(p_output);
                output_length_invert = output_length;


                for( i = 0 ; i < output_length ; i++)
                {

                    p_output_invert[i] = p_output[output_length_invert - 1];
                    output_length_invert--;




                }

                strncpy(p_output, p_output_invert, output_length );
                strcpy(p_write_line, p_output);

            }

        // -----------------------------concat --------------------------------------------------



                if (concat_at_begining !=NULL)
                {

                    strcpy(p_write_line, concat_at_begining);
                    strcat(p_write_line, p_output);


                }


                if (concat_at_end != NULL)
                {

                    if (concat_at_begining == NULL)
                    {
                            strcpy(p_write_line, p_output);
                            strcat(p_write_line, concat_at_end);
                    }
                    else
                    {
                            strcpy(p_write_line, concat_at_begining);
                            strcat(p_write_line, p_output);
                            strcat(p_write_line, concat_at_end);


                    }


                }


        // --------------------------------- rule mask ----------------------------------------
            break_flag = 0;


            if (rule_password_mask != NULL)
            {

                //break_flag = 0;

                for (m = 0 ; m < (signed) strlen(p_write_line) ; m++)
                {

                    mask_number = mask_table[m];

                    for( x = m + 1; x < (signed) strlen(p_write_line); x++)
                    {

                        if (mask_table[x] == mask_number)
                        {


                            if ( p_write_line[x] == p_write_line[m])
                            {




                            }
                            else
                            {


                                break_flag = 1;


                            }
                        }
                        else
                        {

                            if (p_write_line[x] == p_write_line[m])
                            {


                                break_flag = 1;

                            }
                            else
                            {




                            }




                        }


                    }


                }


            }







        // --------------------------------- rule row -----------------------------------------

            if ((rule_same_in_row != 0) && (break_flag != 1))
            {

                //break_flag = 2;

                for ( i = 0 ; i < (signed) strlen(p_write_line); i++)
                {

                    count = 0;

                    for ( x = 0 ; x < rule_same_in_row ; x++)
                    {

                        if (p_write_line[i] == p_write_line[i+x])
                        {

                            count++;

                        }

                        if ( count == rule_same_in_row)
                        {

                            break_flag = 1;
                            break;


                        }



                    }





                }




            }



        // --------------------------- rule password policy ------------------------------------


            if ((rule_minimum_lower == 0) && (rule_minimum_upper == 0) && (rule_minimum_numer == 0) && (rule_minimum_special == 0))
            {






            }
            else
            {

                if (break_flag != 1)
                {


                    count_lower = 0;
                    count_upper = 0;
                    count_number = 0;
                    count_special = 0;

                    for ( p = 0 ; p < (signed) strlen(p_write_line); p++ )
                    {

                        if ( islower(p_write_line[p]) != 0)
                        {

                            count_lower++;
                            continue;


                        }

                        if ( isupper(p_write_line[p]) != 0)
                        {

                            count_upper++;
                            continue;


                        }

                        if ( isdigit(p_write_line[p]) != 0)
                        {

                            count_number++;
                            continue;


                        }



                        count_special++;


                    }


                    if (( count_lower >= rule_minimum_lower) && (count_upper >= rule_minimum_upper) && (count_number >= rule_minimum_numer) && (count_special >= rule_minimum_special))
                    {


                        break_flag = 2;


                    }
                    else
                    {

                        break_flag = 1;

                    }
                }

            }

        // ------------------------------ password complexity -----------------------------------

            if ((rule_complex_password == 1) && (break_flag != 1))
            {


                ad = 0;
                count_lower = 0;
                count_upper = 0;
                count_number = 0;
                count_special = 0;

                for ( p = 0 ; p < (signed) strlen(p_write_line); p++ )
                {

                    if ( islower(p_write_line[p]) != 0)
                    {

                        count_lower++;
                        continue;


                    }

                    if ( isupper(p_write_line[p]) != 0)
                    {

                        count_upper++;
                        continue;


                    }

                    if ( isdigit(p_write_line[p]) != 0)
                    {

                        count_number++;
                        continue;


                    }



                    count_special++;


                }
                 if ( count_lower >= 1)
                 {

                     ad++;


                 }


                if (count_upper >= 1)
                {

                    ad++;

                }



                if (count_number >= 1)
                {

                    ad++;

                }


                if(count_special >= 1)
                {


                    ad++;

                }

                if (ad < 3)
                {

                    break_flag = 1;


                }
                else
                {


                }




            }


        // ----------------------------------- rule cannot contain word-----------------------------

            if ((rule_cannot_contain != NULL ) && (break_flag != 1))
            {


                str_cont = strstr(p_write_line, rule_cannot_contain);

                if (str_cont != NULL)
                {

                    break_flag = 1;

                }


            }

        // -------------------------------- rule must contain  characters-------------------------------------

           if ((obligatory_set != NULL ) && (break_flag != 1))
           {


                if (find_in_string(p_write_line , obligatory_set) == true)
                {


                }
                else
                {

                    break_flag = 1;

                }



           }




        //  -------------------------------- rule one apperance ---------------------------------

            if ((rule_only_one == 1 ) && (break_flag != 1))


            for ( h = 0 ; h < (signed) strlen(p_write_line); h++)
            {


                    for (int j = 1 ; j < (signed) strlen(p_write_line) - h ; j++)
                    {


                        if (p_write_line[h] == p_write_line[h + j])
                        {

                            break_flag = 1;
                            break;


                        }



                    }




            }


        // --------------------------------- rule regex ------------------------------------------


            if (regex_mask != NULL)
            {



                if (regexec(&regex_mask_expr, p_write_line , 1 , &match , 0) == 0 )
                {

                 //   break_flag = 0;
                 //   cout << "found " << endl;


                }
                else
                {


                    break_flag = 1;
                   //   cout << "not found " << endl;
                     //   cout << "not found " << endl;
                }



            }








        // ---------------------------------- convert to hex ------------------------------------


            if (convert_to_hex == 1)
            {


                for ( h = 0 ; h < (signed) strlen(p_write_line); h++)
                {


                    ascii_value = (int) p_write_line[h];
                    sprintf(hex_value, "%x", ascii_value);
                    strcat(hex_stream, hex_value);




                }

                strcpy (p_write_line, hex_stream);
                bzero(hex_stream, strlen(hex_stream));




            }











        // ----------------------------- writing to file ---------------------------------------
        // break flag == 1 - skip


            if (break_flag != 1)
            {



                write_error_flag = fprintf(file_output[current_file], "%s\n", p_write_line);


                if (stop_after_flag == 1)
                {
                   stop_counter++;

                    if (stop_counter >= stop_after_number)
                    {

                      end_condition = 1;

                    }
                }

            }
            else
            {

                if (file_for_deleted_passwords != NULL)
                {


                    write_error_flag = fprintf(file_for_deleted_passwords, "%s\n", p_write_line);



                }



            }



        // ------------------------------ pim processing stop ----------------------------





            }
        }


        pim_counter++;









        // --------------------- if many outpu files - switch file ----------------------

            if (files_in_table != 1)
            {

                if (break_flag != 1)
                {

                    switch_file_counter++;

                }



                if (switch_file_counter == 200)
                {

                    switch_file_counter = 0;
                    current_file++;



                    if (current_file == files_in_table)
                    {

                        current_file = 0;


                    }



                }
            }

            if (write_error_flag < 0)
            {

                cout << "Write Error" << endl;
                return -1;

            }

            p_counters[0]++;

            // increase counters

            for ( h = 0 ; h < max_length ; h++)
            {

                if (p_counters[h] == (signed int) strlen(p_line_buffer[h]))
                {

                    p_counters[h] = 0;
                    p_counters[h+1]++;

                    if (h + 1 == max_length -1)
                    {

                            // progress indicator

                            printf ("%3.1f %% \n",(float)  p_counters[max_length -1] / strlen(p_line_buffer[h])  * 100 );



                    }


                }

            }


            if (p_counters[max_length] == 0)
            {

                end_condition = 1;

            }

        }while(end_condition == 0);



    }





    clock_t stop = clock();

    time_elapsed = (stop - start) / CLOCKS_PER_SEC ;


    cout << endl <<  "Done in  " ;

    if( time_elapsed > 0 )
    {

        print_with_formatting( (int)(time_elapsed / SECONDS_IN_AN_HOUR) );
        cout << ":";     // :
        print_with_formatting( (int)((time_elapsed % SECONDS_IN_AN_HOUR) / SECONDS_IN_A_MINUTE) );
        cout << ":";       // :
        print_with_formatting( (int)((time_elapsed % SECONDS_IN_AN_HOUR) % (SECONDS_IN_A_MINUTE)) );

    }
    else
    {

        cout << "00:00:00"; // 00:00:00

    }







        return 0;
}

void print_with_formatting( const unsigned int value )
{
    if( value == 0 )
    {
        cout << "00";

    }
    else if( value < 10 )
    {
        cout << "0" << value;

    }
    else
    {
        cout << value;

    }
}


bool find_in_string ( char* text , char* character)
{



        char * text_temp = text;
        char * characters_temp = character;

        int found_number = 0;

        int found_in[100];

        bool found_bool = false;

        for (int i = 0 ; i < 100; i++)
        {

                found_in[i] = -1;

        }

        for ( int i = 0 ; i < (signed) strlen(text_temp) ; i++)          //
        {



            // move throug p_write_line

            // if character from text is already founded skip this character



            for (int j = 0 ; j < (signed) strlen(characters_temp) ; j++)
            {


                // move throu obligatory character

                found_bool = false;

            // search if this character was already found


                for (int q = 0 ; q < 100 ; q++)
                {

                        if (found_in[q] == -1)
                        {

                                break;

                        }



                        if (found_in[q] == j)
                        {

                                // this character was marked as found do not use it again


                            found_bool = true;

                        }





                }

                if (found_bool == true)
                {

                    continue;

                }

                if (text_temp[i] == characters_temp[j])
                {




                    found_in[found_number] = j;         // mark this character as already founded
                    found_number++;


                    break;
                    //continue;

                }



            }




        }

        if (found_number >= (signed) strlen(characters_temp))
        {

                return true;
        }
        else
        {
                return false;
        }





}

