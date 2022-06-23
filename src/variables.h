#ifndef VARIABLES_H_INCLUDED
#define VARIABLES_H_INCLUDED


#include <stdlib.h>
#include <regex.h>


const struct option long_options[] = {

    // ----------------------------- length -------------------------------------------


    { "min"       ,   1   ,   NULL    ,   'm' },         // minimum lenght of passwords
    { "max"       ,   1   ,   NULL    ,   'x' },         // maximum lenght of passwords


    // ------------------------------used characters-----------------------------------

    { "pre_lower" ,   1   ,   NULL    ,   'l' },         // use predefined sets lower
    { "pre_upper" ,   1   ,   NULL    ,   'u' },         // use predefined sets upper
    { "pre_num"   ,   1   ,   NULL    ,   'n' },         // use predefined sets numeric
    { "pre_spec"  ,   1   ,   NULL    ,   's' },         // use predefined sets special


    { "global"    ,   1   ,   NULL    ,   'g' },         // add extra characters global
    { "local"     ,   1   ,   NULL    ,   'p' },         // add extra characters localy
    { "custom"    ,   1   ,   NULL    ,   'c' },         // create custom sets by reading from file


    // ------------------------------- help --------------------------------------------

    { "help"      ,   0   ,   NULL    ,   'h' },         // print help
    { "about"     ,   0   ,   NULL    ,   'a' },         // print extended help


    // ------------------------------output --------------------------------------------

    { "output"    ,   1   ,   NULL    ,   'o' },         // ouput file
    { "multiple"  ,   1   ,   NULL    ,   'e' },         // multiple output
    { "file"      ,   1   ,   NULL    ,   'f' },         // read destinations from file
    { "switch"    ,   1   ,   NULL    ,   'w' },         // destination from switch string


    // --------------------------- modifiers ---------------------------------------------

    { "randomize" ,   0   ,   NULL    ,   'R' },         // randomize
    { "start"     ,   1   ,   NULL    ,   'B' },         // start with
    { "end"       ,   1   ,   NULL    ,   'E' },         // end with
    { "invert"    ,   0   ,   NULL    ,   'I' },         // inverse write
    { "backword"  ,   0   ,   NULL    ,   'D' },         // read characters from end
    { "hex"       ,   0   ,   NULL    ,   'H' },          // conver to hex


    // --------------------------- others ---------------------------------------------

    { "stop"      ,   1   ,   NULL    ,   'S' },         // stop aferter soma number of passwords
    { "list"      ,   0   ,   NULL    ,   'Q' },         // parallel processing
    { "parallel"  ,   1   ,   NULL    ,   'P' },         // parallel processing
    { "seed"      ,   1   ,   NULL    ,   'F' },


    // ---------------------------- rules -------------------------------------------------

    { "row"       ,   1   ,   NULL    ,   'W' },         // rule number - skip password that have 3 and more same characters in row
    { "mask"      ,   1   ,   NULL    ,   'K' },         // rule - define which position must be the same
    { "adirectory",   0   ,   NULL    ,   'A' },        // active directory password complecity 3 of for rules
    { "afla"      ,   1   ,   NULL    ,   'L' },        // count lower alfa
    { "numeric"   ,   1   ,   NULL    ,   'N' },        // count numeric
    { "special"   ,   1   ,   NULL    ,   'S' },        // cout special
    { "ALFA"      ,   1   ,   NULL    ,   'U' },         // cout Upper alfa
    { "contain"   ,   1   ,   NULL    ,   'C' },         // password cannot contain string
    { "once"      ,   0   ,   NULL    ,   'O' },        // only once in password
    { "regex"     ,   1   ,   NULL    ,   'X' },         // match password to regex
    { "obligatory",   1   ,   NULL    ,   'G' },

    { "deleted"   ,   1   ,   NULL    ,   'd' },      // store filtered password


    // -------------------------------------------------------------------------------------

    { "verbose"     ,   0   ,   NULL    ,   'v' }

};



const char* const short_options = "m:x:lunsg:p:c:hao:e:f:w:RB:E:IDHP:W:K:AL:N:S:U:C:Od:X:Z:QvG:F:";




    // ------------- for loop handle ------------------
    int next_option;
    char* p_get_option;


    // --------------  password length ---------------
    int min_length;
    int max_length;


    // -------------- used characters ----------------
    int pre_lower;
    int pre_upper;
    int pre_numeric;
    int pre_special;

    char* set_add_local;
    char* set_add_global;
    char* set_load_from_file;


    // --------------- output files -----------------
    char* output_single_file;
    int multiple_output_file = 0;

    char* output_read_from_file;
    char* output_read_from_switch;


    // ----------------- modificators ---------------

    int randomize_set;
    int invert_set;
    int backword_set;
    int convert_to_hex;
    char* concat_at_begining = NULL;
    char* concat_at_end;


    // ------------------ rules ----------------------

    int rule_same_in_row;
    int rule_complex_password;
    int rule_minimum_lower = 0;
    int rule_minimum_upper = 0;
    int rule_minimum_numer = 0;
    int rule_minimum_special = 0;
    int rule_only_one = 0;

    char* rule_password_mask = NULL;
    char* rule_cannot_contain;
    char* rule_store_filtered_password_file;

    int rule_is_used = 0;
    int loop_type = 0;

    int mask_table[50];
    int rule_password_mask_length;


    char* parallel_processing_string;
    int parallel_process_count = 1;
    int parallel_process_current_element = 1;

    int parallel_randomize_seed = 0;

    int stop_after_flag = 0;
    long int stop_after_number = 0;
    int list_flag = 0;
    char* regex_mask = NULL;
    regex_t regex_mask_expr;

    char *obligatory_set = NULL;

    // ----------------- predefined sets ------------------

    char* lower_case_letters = (char *) "abcdefghijklmnopqrstuvwxyz";
    char* upper_case_letters = (char *) "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char* numbers = (char *) "0123456789";
    char* special_characters = (char *) "!@#$^&*()?";



    // ------------------- table for set per character -------------


    char line_buffer[50][100];
    char line_buffer2[50][100];

    // --------------------table for files path --------------------

    int files_in_table = 0;
    char file_output_names[50][100];
    FILE *file_output[50];
    FILE *file_for_deleted_passwords = NULL;


    // ------------------------- verbose ---------------------------


    bool verbose_switch = false;


#endif // VARIABLES_H_INCLUDED
