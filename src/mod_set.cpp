// ------------------------------------ lib ----------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <iostream>
#include <cstring>

// -------------------------------------- h ----------------------------------------------




// -------------------------------------- cpp ---------------------------------------------


// ---------------------------------------code --------------------------------------------

using namespace std;

int modify_set()
{


for ( int i = 0 ; i < 50 ; i++)
{


    strcpy(line_buffer2[i], line_buffer[i]);

}


// ------------------------------------------ randomize ------------------------------------

 if ( randomize_set == 1)
 {

      for (int x = 0 ; x < max_length ; x ++)        // randomize all sets seperatly
        {

            int  characters_left = 0;                   // number of characters
            int  current_character = 0;

            char temp_buffer[100];                            // temporary buffer for calcs
            int line_buffer_size = 0;                             // size of buffer - foc calcs

            line_buffer_size = strlen(line_buffer[x]);        // get structure length

            bzero(temp_buffer, 100);                              // clear structure

            if (parallel_randomize_seed == 0)
            {

                 srand ( time(NULL) * x);                                // randozmie

            }
            else
            {
                srand(parallel_randomize_seed * x);

            }





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
    }


// -------------------------------------backword--------------------------------------------------------

    if (backword_set == 1)                          // read line buffer from end
    {

        for (int x = 0 ; x < max_length ; x ++)
        {

            char temp_buffer[100];
            int line_buffer_length = strlen(line_buffer[x]) ;         // get length of line buffer
            int j = line_buffer_length;

            for (int i = 0 ; i < line_buffer_length ; i++)
            {

                temp_buffer[i] = line_buffer[x][j -1];      // flip sides
                j--;

            }

        strncpy(line_buffer[x], temp_buffer, line_buffer_length);        // copy to line buffer

        }
    }



// ---------------------------------- mask ----------------------------------------------------

    if (rule_password_mask != NULL )
    {



        char temp[100];                 // temp buffer

        char *token;                    // token for strtok
        int current_number;
        strcpy(temp, rule_password_mask);
        int i = 0;
        token = strtok(temp,"%");       //split into token
        while(token != NULL)
        {

            current_number = atoi(token);



        //    if (current_number == NULL)
            if (current_number <= -1)
            {

                cout << "Mask - Wrong argument (-K)" << endl;
                return -1;

            }


            mask_table[i] = current_number;
            token = strtok(NULL, "%");  // split into token
            i++;
        }

       rule_password_mask_length = i;


        if ((rule_password_mask_length == min_length) && (rule_password_mask_length == max_length))
        {



        }
        else
        {

            cout << "Mask must have the same length as minimum and maximum length" << endl;
            return -1;

        }


        for (int j = 0 ; j < max_length ; j++)
        {

            cout << mask_table[j] << endl;

        }


    }




 return 0;
}

