// ------------------------------------ lib ----------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <iostream>
#include <cstring>

// -------------------------------------- h ----------------------------------------------




// -------------------------------------- cpp ---------------------------------------------


// ---------------------------------------code --------------------------------------------




int choose_loop()
{

 if (rule_is_used == 1)
 {

     cout << "Loop nr. 3 (slow)" << endl;
     loop_type = 3;
     return 0;

 }

 if (( rule_is_used == 0 ) && ((invert_set == 1) || (concat_at_begining != NULL) || (concat_at_end != NULL)))

 {

     cout << "Loop nr. 2 (normal)" << endl;
     loop_type = 2;
     return 0;

 }

 if  (( rule_is_used == 0 ) && (invert_set == 0) && (concat_at_begining == NULL) && (concat_at_end == NULL))
 {

     cout << "Loop nr. 1 (fast)" << endl;
     loop_type = 1;
     return 0;

 }


 cout << "Something went wrong ..." << endl;
 return -1;

}
