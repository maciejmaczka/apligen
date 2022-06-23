// ------------------------------------ lib ----------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <iostream>
#include <cstring>
#include <regex.h>
// -------------------------------------- h ----------------------------------------------




// -------------------------------------- cpp ---------------------------------------------


// ---------------------------------------code --------------------------------------------

using namespace std;

int check_args()
{


//
//    extern int min_length;
//    extern int max_length;
//    extern int pre_lower;
//    extern int pre_upper;
//    extern int pre_numeric;
//    extern int pre_special;
//    extern char* set_add_local;
//    extern char* set_add_global;
//    extern char* set_load_from_file;
//    extern char* output_single_file;
//    extern int multiple_output_file;
//    extern char* output_read_from_file;
//    extern char* output_read_from_switch;
//    extern char file_output_names[50][100];
//    extern int files_in_table;
   int file_error = 0;
//    extern FILE *file_for_deleted_passwords;


// ----------------------------------------- check length -------------------------------------------------

    if ( min_length <= 0)
    {

        cout << "Minimum length - Wrong argument or not set (-m)" << endl;
        return -1;

    }

    if ( max_length <= 0)
    {

        cout << "Maximum length - Wrong argument or not set (-x)" << endl;
        return -1;

    }

    if ( min_length > max_length)
    {

        cout << "Minimum and Maximum length - Wrong argument (-m -x)" << endl;
        return -1;

    }


// ----------------------------------------- creat_global_set----------------------------------------------



    if (pre_lower == 1)
    {

        strcat(line_buffer[0], lower_case_letters);

    }

    if (pre_upper == 1)
    {

         strcat(line_buffer[0], upper_case_letters);

    }

    if (pre_numeric == 1)
    {

        strcat(line_buffer[0], numbers);

    }

    if (pre_special == 1)
    {

         strcat(line_buffer[0], special_characters);

    }


    if (set_add_global != NULL)
    {

        strcat(line_buffer[0], set_add_global);

    }

// ------------------------------------copy set to all locations -------------------------


    for (int i = 1; i < max_length; i++)
    {
            strcpy(line_buffer[i], line_buffer[0]);


    }





// ---------------------------------- add local characters -----------------------------


    if (set_add_local != NULL)
    {


        char local_char_set_temp[100];
        char *token;
        int current_line = 0;

        strcpy (local_char_set_temp, set_add_local);
        token = strtok(local_char_set_temp,"%");

        while(token != NULL)
        {

            for ( int i = 0 ; i < (signed) strlen(token); i++)
            {

                if (strcmp(token, "-") == 0 )
                {

                    strcpy(token, "");

                }


                if ((token[i] == '-') && (token[i+1] == '1'))
                {

                    for (int j = i ; j <  (signed) strlen(token) -1; j++)
                    {

                        token[j] = token[j+2];

                    }
                    strcat(token, "-");

                }

                if ((token[i] == '-') && (token[i+1] == '2'))
                {

                    for (int j = i ; j <  (signed) strlen(token) -1; j++)
                    {

                        token[j] = token[j+2];

                    }
                    strcat(token, "%");

                }
            }


            strcat(line_buffer[current_line],token);



            current_line++;
            token = strtok(NULL, "%");


        }


        if (current_line > max_length)
        {

            cout << "Add local characters - To many positions (-p)" << endl;
            return -1;

        }



    }




// ---------------------------- load characters from file ------------------------------------------


    if (set_load_from_file != NULL)
    {
        char file_line_temp[100];
        int file_line_length = 0;
        int current_number = 0;
        char *line_read;
        FILE *set_source_file = fopen(set_load_from_file, "r");
        if (set_source_file == NULL)
        {

            cout << "File Error: " << set_load_from_file << "\n";
            file_error = 1;

        }

        if (set_source_file != NULL)
        {

            while (!feof(set_source_file))
            {


                line_read = fgets(file_line_temp, 100, set_source_file);
                if (line_read == NULL)
                {

                }
                file_line_length = strlen(file_line_temp);


                strncat(line_buffer[current_number], file_line_temp, file_line_length-1);
                current_number++;



            }



            fclose(set_source_file);

        }

    }



// -----------------------------test set--------------------------------------------------

    int set_check = 0;
    for (int i = 0 ; i < max_length; i++)
    {

        if ( strlen(line_buffer[i]) == 0)
        {

            //cout << "No characters in line - " << i + 1 << endl;
            set_check = 1;

        }

    }



    if (set_check == 1)
    {

        cout << endl << "Set Error:" << endl;
        cout << "------------------------------" << endl;
        for (int i = 0 ; i < max_length; i++)
        {

            cout << i+1 << ".  " <<  line_buffer[i];
            cout << endl;
        }

        cout << "------------------------------" << endl;
        cout << "(-n -m -l -u -n -s -g -p -c)"  << endl;
        return -1;


    }


// ----------------------------- only one output file ---------------------------------------



    if ((output_single_file != NULL) && (multiple_output_file == 0))
    {

         file_output[0] = fopen64(output_single_file, "w");
         strcpy(file_output_names[0] , output_single_file);




         if ( file_output[0] == NULL)
         {

             file_error = 1;


         }
        files_in_table++;


    }


// ----------------------------- many files with multiple option-----------------------------------



    if ((output_single_file != NULL) && (multiple_output_file != 0))
    {

        char file_path[50];
        char file_number[5];

        for (int i = 0 ; i < multiple_output_file; i++)
        {

            bzero(file_path,50);
            strcpy(file_path, output_single_file);

            bzero(file_number, 5);
            sprintf(file_number, "%d", i);

            strcat(file_path, file_number);

            file_output[i] = fopen64(file_path, "w");
            strcpy(file_output_names[i] , file_path);




            if (file_output == NULL)
            {

                file_error = 1;

            }

            files_in_table++;



        }



    }





// ----------------------------- output file from switch-----------------------------------------

    if (output_read_from_switch != NULL)
    {


        char *token;




        token = strtok(output_read_from_switch,"%");
        while(token != NULL)
        {



            file_output[files_in_table] = fopen64(token, "w");
            strcpy(file_output_names[files_in_table] , token);


            if( file_output[files_in_table] == NULL)
            {

                file_error = 1;

            }
            files_in_table++;


            token = strtok(NULL, "%");


        }



    }




// ----------------------------- output file from file-----------------------------------------

    if (output_read_from_file != NULL)
    {


        char *line_read;
        char temp[100];

        FILE *read_from_file = fopen(output_read_from_file, "r");    // open file
        if (read_from_file == NULL)              // error
        {

            cout << output_read_from_file << " - Can't read file" << endl;
            return  -1;

        }



        while (!feof(read_from_file))
        {

            line_read = fgets (temp , 100 , read_from_file);
            if (line_read == NULL)
            {

            }


            file_output[files_in_table] = fopen64(temp, "w");
            strncpy(file_output_names[files_in_table] , temp , strlen(temp) - 1);


            if( file_output[files_in_table] == NULL)
            {

                file_error = 1;

            }
            files_in_table++;


        }

        fclose (read_from_file);


    }


// ----------------------------- test output files-----------------------------------------------------
        //files_in_table--;


        if (file_error == 1 || files_in_table == 0)
        {



        cout << endl << "File Error:" << endl;
        cout << "------------------------------" << endl;
        for (int i = 0 ; i < files_in_table ; i++)
        {

            cout <<" " << file_output_names[i];
            file_output[files_in_table] = fopen64(file_output_names[i], "w");
            if (file_output[i] == NULL)
            {
                    cout << "\t\tERROR" << endl;

            }
            else
            {
                    cout << "\t\tOK" << endl;

            }




        }

            cout << "------------------------------" << endl;
            cout << "(-o -e -f -w)"  << endl;
            return -1;

        }


// --------------------------------- test ouput for deleted files --------------------------------

    if (rule_store_filtered_password_file != NULL)
    {

        file_for_deleted_passwords = fopen64(rule_store_filtered_password_file, "w");


        if (file_for_deleted_passwords == NULL)
        {

            cout << rule_store_filtered_password_file << " - File Error (-d)" << endl;
            return -1;

        }
    }




  // --------------------------------- parallel processing --------------------------------


    if (parallel_processing_string != NULL)
    {


        char *token;
        token = strtok(parallel_processing_string,"//");


        parallel_process_current_element = atoi(token);

        token = strtok(NULL, "//");

        parallel_process_count = atoi(token);

        if (( parallel_process_count == 0 ) || (parallel_process_current_element == 0 ) )
        {

             cout << endl << "PIM Error" << endl;
             return -1;
        }


        if (( parallel_process_current_element > parallel_process_count))
        {

             cout << endl << "PIM Error" << endl;
             return -1;

        }
   //    cout << "PIM count" << parallel_process_count << " | " << parallel_process_current_element ;



    }


 // ---------------------------------- regex ----------------------------------------------------------------------

    if (regex_mask != NULL)
    {
        int regex_true;


	   regex_true = regcomp(&regex_mask_expr , regex_mask , REG_EXTENDED);

	    if (regex_true != 0)
	    {

	    	cout << "REGEX Error" << endl;
	    	return -1;

	    }

    }


// ---------------------------------- stop -----------------------------------------------------------------------


    if (stop_after_flag == 1)
    {

        if (stop_after_number <= 0)
        {
            cout << "STOP NUMBER Error" << endl;
	    	return -1;

        }


    }


 // ------------------------------ stron password list ------------------------------------------------------------


    if (list_flag)
    {


            if (stop_after_flag == 0)
            {

                cout << "Error - define number of passwords (-Z)" << endl;
                return -1;


            }







    }


    return 0;

}
