// ------------------------------------ lib ----------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <iostream>
#include <cstring>

// -------------------------------------- h ----------------------------------------------




// -------------------------------------- cpp ---------------------------------------------


// ---------------------------------------code --------------------------------------------


int get_summary()
{

    cout << "Min Length\t" << min_length << "\t(-m)" << endl;
    cout << "Max Length\t" << max_length << "\t(-x)" <<  endl;


// -----------------------------------randomize ---------------------------------------------
    if (randomize_set == 1)
    {

        cout << "Randomize\tYes" << "\t(-R) "<< endl;

    }
    else
    {

        cout << "Randomize\tNo" << "\t(-R) "<< endl;

    }

     if (parallel_randomize_seed == 0)
    {

        cout << "Seed\t\tRand" << "\t(-F) "<< endl;

    }
    else
    {

        cout << "Seed\t\t" << parallel_randomize_seed << "\t(-F) "<< endl;

    }

// ----------------------------------- backword ------------------------------------------------

    if (backword_set == 1)
    {

        cout << "Backword\tYes" << "\t(-D) "<< endl;

    }
    else
    {

        cout << "Backword\tNo"  << "\t(-D) "<< endl;

    }

// ----------------------------------------invert -----------------------------------------------

    if (invert_set == 1)
    {

        cout << "Invert\t\tYes"  << "\t(-I) "<< endl;

    }
    else
    {

        cout << "Invert\t\tNo"  << "\t(-I) "<< endl;

    }


// --------------------------------------convert to hex ------------------------------------------

    if (convert_to_hex == 1)
    {

        cout << "Hex\t\tYes"  << "\t(-H) "<< endl;

    }
    else
    {

        cout << "Hex\t\tNo"  << "\t(-H) "<< endl;

    }

// ---------------------------------------concat -----------------------------------------------

    if (concat_at_begining == NULL)
    {

        cout << "Start with\tN/A"  << "\t(-B) "<< endl;
    }
    else
    {

        cout << "Start with\t" << concat_at_begining  << "\t(-B) "<< endl;

    }


    if (concat_at_end == NULL)
    {

        cout << "End with\tN/A"  << "\t(-E) "<< endl;
    }
    else
    {

        cout << "End with\t" << concat_at_end << "\t(-E) "<< endl;

    }

// ---------------------------------- same in row -----------------------------------------------

    if (rule_same_in_row == 0)
    {

        cout << "(R) In Row\tN/A" << "\t(-W) "<< endl;

    }
    else
    {

       cout << "(R) In Row\t" << rule_same_in_row << "\t(-W) "<< endl;

    }

// ---------------------------------- AD password complex -------------------------------------


    if (rule_complex_password == 1)
    {

        cout << "(R) Complexity\tYes" << "\t(-A) "<< endl;

    }
    else
    {

       cout << "(R) Complexity\tNo" << "\t(-A) "<< endl;


    }


// ------------------------------------- Custo Password complex ----------------------------------

    if (rule_minimum_lower != 0)
    {

        cout << "(R) Min Lower\t" << rule_minimum_lower << "\t(-L) "<< endl;

    }
    else
    {

       cout << "(R) Min Lower\tN/A" << "\t(-L) "<< endl;


    }



    if (rule_minimum_upper != 0)
    {

        cout << "(R) Min Upper\t" << rule_minimum_upper << "\t(-U) "<< endl;

    }
    else
    {

       cout << "(R) Min Upper\tN/A" << "\t(-U) "<< endl;


    }

    if (rule_minimum_numer != 0)
    {

        cout << "(R) Min Numeric\t" << rule_minimum_numer << "\t(-N) "<< endl;

    }
    else
    {

       cout << "(R) Min Numeric\tN/A"<< "\t(-N) "<< endl;

    }


    if (rule_minimum_special != 0)
    {

        cout << "(R) Min Special\t" << rule_minimum_special << "\t(-S) "<< endl;

    }
    else
    {

       cout << "(R) Min Special\tN/A" << "\t(-S) "<< endl;


    }

// ------------------------------------------ mask --------------------------------------


    if (rule_password_mask != NULL)
    {

        cout << "(R) Mask\t" << rule_password_mask << "\t(-K) "<< endl;

    }
    else
    {

       cout << "(R) Mask\tN/A" << "\t(-K) "<< endl;


    }


// ------------------------------------------ obligatory char --------------------------------------


    if (obligatory_set != NULL)
    {

        cout << "(R) Obligatory\t" << obligatory_set << "\t(-G) "<< endl;

    }
    else
    {

       cout << "(R) Obligatory\tN/A" << "\t(-G) "<< endl;


    }



// ------------------------------------------ REGEX --------------------------------------


    if (regex_mask != NULL)
    {

        cout << "(R) Regex\t" << regex_mask << "\t(-X) "<< endl;

    }
    else
    {

       cout << "(R) Regex\tN/A" << "\t(-X) "<< endl;


    }





// -----------------------------------------contain ----------------------------------------


    if (rule_cannot_contain != NULL)
    {

        cout << "(R) Not Contain\t" << rule_cannot_contain << "\t(-C) "<< endl;

    }
    else
    {

       cout << "(R) Not Contain\tN/A" << "\t(-C) "<< endl;


    }



// ----------------------------------------- only once ----------------------------------------



    if (rule_only_one == 1)
    {

        cout << "(R) Only Once\tYes" << "\t(-O) "<< endl;

    }
    else
    {

       cout << "(R) Only Once\tNo" << "\t(-O) "<< endl;


    }


// ----------------------------------------file for filtered passwords ------------------------


    if (rule_store_filtered_password_file != NULL)
    {

        cout << "(R) Store\t" << rule_store_filtered_password_file << "\t(-d) "<< endl;

    }
    else
    {
        cout << "(R) Store\tN/A"<< "\t(-d) "<< endl;

    }



// ---------------------------------------------- paralell independent processing ----------------------------------



    if (parallel_process_current_element != 0)
    {

        cout << "(P) PIM Number\t" << parallel_process_current_element  << "\t(-P) "<< endl;

    }
    else
    {

       cout << "(P) PIM Number\tN/A"   << "\t(-P) "<< endl;


    }




    if (parallel_process_count != 0)
    {

        cout << "(P) PIM Count\t" << parallel_process_count  << "\t(-P) "<< endl;

    }
    else
    {

        cout << "(P) PIM Count\tN/A"   << "\t(-P) "<< endl;


    }



// ------------------------------------- stop afer ---------------------------------------------


    if (stop_after_flag != 0)
    {

        cout << "(R) Stop after\t" << stop_after_number  << "\t(-Z) "<< endl;

    }
    else
    {

        cout << "(R) Stop after\tN/A"   << "\t(-Z) "<< endl;


    }


// ------------------------------------- password list ---------------------------------------------


    if (list_flag != 0)
    {

        cout << "(R) List\t" << "Yes"  << "\t(-Q) "<< endl;

    }
    else
    {

        cout << "(R) List\tNo"   << "\t(-Q) "<< endl;


    }



// -------------------------------------print set-----------------------------------------------


    cout << endl;
    cout << "Created Sets:" << endl << endl;

    for (int i = 0 ; i < max_length; i++)
        {

            cout << i+1 << ".  " <<  line_buffer2[i];
            cout << endl;

        }

// --------------------------------------print modified set ------------------------------------

    if ((randomize_set == 1) || (backword_set == 1))
    {


        cout << endl;
        cout << "Set:" << endl << endl;

        for (int i = 0 ; i < max_length; i++)
            {

                cout << i+1 << ".  " <<  line_buffer[i];
                cout << endl;

            }
    }


// --------------------------------------print files ------------------------------------------

        cout << endl;
        cout << "Output Files:" << endl;

        for (int i = 0 ; i < files_in_table ; i++)
        {

             cout << i+1 << ".  " << file_output_names[i] << endl;

        }

    cout << endl;


return 0;

}
