// ------------------------------------ lib ----------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <iostream>
#include <string.h>

// -------------------------------------- h ----------------------------------------------


#include "variables.h"


// -------------------------------------- cpp ---------------------------------------------


#include "get_opt.cpp"
#include "check_args.cpp"
#include "summary.cpp"
#include "mod_set.cpp"
#include "choose_loop.cpp"
#include "loop.cpp"
#include "help.cpp"


using namespace std;
// ----------------------------------------func--------------------------------------------

int get_options(int argc, char* argv[]);

int generate (int loop_type);



// ---------------------------------------code --------------------------------------------






int main(int argc, char* argv[])
{


    int func_result;
    int i;
    i = get_options(argc, argv);                // check for switches


    if (i == 0)
    {
                                                // everything went well


    }


    if ( i == 1)
    {                                           // pring about

        about();
        return 0;





    }

    if (i == 2)                                 // print help
    {

        printhelp();
        return 0;

    }




    cout << endl << "apligen 2.05" << endl;
    cout << "-----------" << endl << endl;

    func_result = check_args();
    if (func_result == 0)
    {


       func_result = modify_set();

    }
    else
    {

        cout << endl << "Aborting..." << endl << endl;
        return 0;

    }


    if (func_result == 0)
    {
       get_summary();
       choose_loop();
       generate();

    }
    else
    {

        cout << endl << "Aborting..." << endl << endl;
        return 0;

    }


    fcloseall();
    cout << endl << endl;



    return 0;







}
