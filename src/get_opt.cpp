// ------------------------------------ lib ----------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <iostream>


// -------------------------------------- h ----------------------------------------------




// -------------------------------------- cpp ---------------------------------------------


// ---------------------------------------code --------------------------------------------



using namespace std;




int get_options(int argc, char* argv[])
{

  // ------------- for loop handle ------------------
    extern  int next_option;
    extern char* p_get_option;


    // --------------  password length ---------------
    extern int min_length;
    extern int max_length;


    // -------------- used characters ----------------
    extern int pre_lower;
    extern int pre_upper;
    extern int pre_numeric;
    extern int pre_special;

    extern char* set_add_local;
    extern char* set_add_global;
    extern char* set_load_from_file;


    // --------------- output files -----------------
    extern char* output_single_file;
    extern int multiple_output_file;

    extern char* output_read_from_file;
    extern char* output_read_from_switch;


    // ----------------- modificators ---------------

    extern int randomize_set;
    extern int invert_set;
    extern int backword_set;
    extern int convert_to_hex;
    extern char* concat_at_begining;
    extern char* concat_at_end;


    // ------------------ rules ----------------------

    extern int rule_same_in_row;
    extern int rule_complex_password;
    extern int rule_minimum_lower;
    extern int rule_minimum_upper;
    extern int rule_minimum_numer;
    extern int rule_minimum_special;
    extern char* rule_password_mask;
    extern char* rule_cannot_contain;
    extern char* rule_store_filtered_password_file;





    if (argc == 1)
    {

        return 2;


    }


    do
    {

        next_option = getopt_long(argc, argv , short_options , long_options, NULL);
        switch (next_option)
        {

            case 'm':                                   // minimum length



                p_get_option = optarg;
                min_length = atoi(p_get_option);
                break;


            case 'x':                                   // maximum length

                p_get_option = optarg;
                max_length = atoi(p_get_option);
                break;

            case 'l':                                   // use predefined lower case characters set

                pre_lower = 1;
                break;

            case 'u':                                   // use predefined upper case characters set

                pre_upper = 1;
                break;

            case 'n':                                   // use predefined numeric characters set

                pre_numeric = 1;
                break;

            case 's':                                   // use predefined special characters set

                pre_special = 1;
                break;


            case 'p':

                set_add_local = optarg;
                break;


            case 'g':

                set_add_global = optarg;
                break;

            case 'c':

                set_load_from_file = optarg;
                break;

            case 'a':

                return 1;

            case 'h':

                return 2;


            case 'o':

                output_single_file = optarg;
                break;

            case 'e' :

                p_get_option = optarg;
                multiple_output_file = atoi(p_get_option);
                break;


            case 'f' :

                output_read_from_file = optarg;
                break;

            case 'w' :

                output_read_from_switch = optarg;
                break;

            case 'R' :

                randomize_set = 1;
                break;

            case 'I' :

                invert_set = 1;
                break;

            case 'D' :

                backword_set = 1;
                break;

            case 'B' :

                concat_at_begining = optarg;
                break;

            case 'E' :

                concat_at_end = optarg;
                break;

            case 'H' :

                convert_to_hex = 1;
                rule_is_used = 1;
                break;

            case 'W' :

                p_get_option = optarg;
                rule_same_in_row = atoi(p_get_option);
                rule_is_used = 1;
                break;

            case 'K' :

                rule_password_mask = optarg;
               rule_is_used = 1;
                break;


            case 'A' :

               rule_complex_password = 1;
               rule_is_used = 1;
                break;

            case 'L' :

                p_get_option = optarg;
                rule_minimum_lower = atoi(p_get_option);
                rule_is_used = 1;
                break;

            case 'U' :

                p_get_option = optarg;
                rule_minimum_upper = atoi(p_get_option);
                rule_is_used = 1;
                break;

            case 'N' :

                p_get_option = optarg;
                rule_minimum_numer = atoi(p_get_option);
                rule_is_used = 1;
                break;

            case 'S' :

                p_get_option = optarg;
                rule_minimum_special = atoi(p_get_option);
                rule_is_used = 1;
                break;

            case 'C' :

                rule_cannot_contain = optarg;
                rule_is_used = 1;
                break;

            case 'd' :

                rule_store_filtered_password_file = optarg;
                rule_is_used = 1;
                break;


            case 'O' :

                rule_only_one = 1;
                rule_is_used = 1;
                break;


            case 'P' :


                parallel_processing_string = optarg;
                break;

            case 'Z' :


                stop_after_flag = 1;
                p_get_option = optarg;
                stop_after_number = atoi(p_get_option);
                rule_is_used = 1;
                break;

            case 'Q' :


                //stop_afer_flag = 1;
                list_flag = atoi(p_get_option);
                rule_is_used = 1;
                break;



            case 'X' :


                regex_mask = optarg;
                rule_is_used = 1;
                break;


            case 'F' :

                p_get_option = optarg;
                parallel_randomize_seed = atoi(p_get_option);
                rule_is_used = 1;
                break;


            case 'G' :


                obligatory_set = optarg;
                rule_is_used = 1;
                break;





            case '?':                  // invalid option

                    break;

            case -1 :                  // done with options

                    break;


            default:                   // something else unexpected

                    break;




        }


    }while(next_option != -1);




 return 0;
}
