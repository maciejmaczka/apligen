
// ------------------------------------ lib ----------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <iostream>
#include <cstring>

// -------------------------------------- h ----------------------------------------------




// -------------------------------------- cpp ---------------------------------------------


// ---------------------------------------code --------------------------------------------

void printhelp()
{

    cout << " apligen 2.06" << endl  << endl;
    cout << " USAGE:" << endl;
    cout << " apligen LENGTH USED_CHAR OUTPUT [MOD] [RULES]" << endl  << endl;

    cout << "LENGTH:" << endl;
    cout << " -m <number> \t Minimum length" << endl;
    cout << " -x <number> \t Maximum length" << endl << endl;

    cout << "USED CHARACTERS:" << endl;
    cout << " -l \t\t Lower case letters - abcde...z" << endl;
    cout << " -u \t\t Upper case letters - ABCDE...Z" << endl;
    cout << " -n \t\t Numbers - 0123...9" << endl;
    cout << " -s \t\t Special characters - !@#...?" << endl;
    cout << " -g <string> \t Additional characters for all positions" << endl;
    cout << " -p <string> \t Additional characters for each position" << endl;
    cout << "\t %  - Seperate position" << endl;
    cout << "\t -  - No adds" << endl;
    cout << "\t -1 - Will be replaced by - " << endl;
    cout << "\t -2 - Will be replaced by % " << endl;
    cout << " -c <file> \t Load characters sets from file (one set per line)" << endl << endl;

    cout << "OUTPUT FILES:" << endl;
    cout << " -o <file> \t Output file" << endl;
    cout << " -e <number> \t Multiple output in one folder (use with -o)" << endl;
    cout << " -f <file> \t Read destinations from file (one destination per line)" << endl;
    cout << " -w <string> \t Destination paths seperated by % " << endl << endl;

    cout << "MODIFICATORS:" << endl;
    cout << " -B <string> \t Start with string" << endl;
    cout << " -E <string> \t End with string " << endl;
    cout << " -R \t\t Randomize characters order" << endl;
    cout << " -I \t\t Invert characters order" << endl;
    cout << " -D \t\t Invert output before write" << endl ;
    cout << " -H \t\t Convert to hex" <<endl << endl;

    cout << "OTHER:" << endl;
    cout << " -Z <number> \t Stop generating after x password" << endl;
    cout << " -Q \t\t Strong password list (use with -Z options) " << endl;
    cout << " -P <string> \t Parallel processing"  << endl;
    cout << " -F <number> \t Fixed seed for parallel processing (use with -P nad -R options) " << endl << endl;

    cout << "RULES:" << endl;
    cout << " -W <number> \t (RULE) Skip password with some characters in row" << endl;
    cout << " -K <string> \t (RULE) Match password to mask" << endl;
    cout << " -X <string> \t (RULE) Match password to regex expr (use \"regex\") " << endl;
    cout << " -L <number> \t (RULE) Minimum lower case letters in password" << endl;
    cout << " -U <number> \t (RULE) Minimum upper case letters in password" << endl;
    cout << " -S <number> \t (RULE) Minimum special characters in password" << endl;
    cout << " -N <number> \t (RULE) Minimum numbers in password" << endl;
    cout << " -A \t\t (RULE) Password must have 3 different characters types" << endl;
    cout << " -C <string> \t (RULE) Password can't contain string " << endl;
    cout << " -O \t\t (RULE) Each character can be used only once in password " << endl;
    cout << " -G \t\t (RULE) Following characters must appear in password " << endl;
    cout << " -d <file> \t Output file for filtered passwords (use with rules)" << endl << endl;

    cout << "HELP:" << endl;
    cout << " -h \t\t Print this help" << endl;
    cout << " -a \t\t About" << endl << endl;
    cout << "------------------------------------------------------------------" << endl;
    cout << "USED CHARACTERS: "<< endl;
    cout << " \t Lower case letters: " << lower_case_letters << endl;
    cout << " \t Upper case letters: " << upper_case_letters << endl;
    cout << " \t Numbers           : " << numbers << endl;
    cout << " \t Special characters: " << special_characters << endl << endl;

    cout << "EXAMPLE:" << endl;
    cout << "  apligen -m 3 -x 3 -lun -o output.txt" << endl;
    cout << "  apligen -m 5 -x 5 -lun -o output.txt -K 1%2%3%2%1 -R" << endl;
    cout << "  apligen -m 1 -x 8 -luns -o output.txt -A -H" <<endl << endl;


    cout << "  (PIM-1) apligen -m 6 -x 6 -n -o output1.txt -P 1/4" <<endl ;
    cout << "  (PIM-2) apligen -m 6 -x 6 -n -o output2.txt -P 2/4" <<endl ;
    cout << "  (PIM-3) apligen -m 6 -x 6 -n -o output3.txt -P 3/4" <<endl ;
    cout << "  (PIM-4) apligen -m 6 -x 6 -n -o output4.txt -P 4/4" <<endl << endl;
    return;


}


void about()
{
    cout << " apligen" << endl ;
    cout << " Advanced Password List Generator" << endl ;
    cout << " Version : 2.06" << endl ;
    cout << " Author  : Maciej mac Maczka" << endl;
    cout << " Contact : maciej.maczka@gmail.com " << endl;
    cout << " Home    : apligen.sf.net" << endl << endl;

}
