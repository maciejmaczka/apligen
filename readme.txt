Install:

use:
	 make

or:
	g++ main.cpp -o apligen


Version: 2.06
- Fixed seed for randomization. You can now use set randomization in parallel processing
- Rule - Folowing characters must be used in passowrd 

For example:   -G aabc     password will have to have:
- 2 letters 'a'
- 1 letter 'b'
- 1 letter 'c'
- Rest of characters could be any 



Version: 2.05

Bugfix
- Segmentation fault when character file couldn't be opened
- Minimum length checking




Version: 2.04

- Rule - Regex - Match password to regex expr
- Rule - Password counter - Stop after x passwords
- Rule - Strong password list - Generate list of x random passwords.  



Version: 2.03

- Parallel Processing:	you can use many cores or computers to speed up generating process. Each PIM (Parallel Independent Module) will generate his part. There is no communication between PIMs. PIM will write only 1 of x passowrd - where x is PIMs count.

Usage:
  (PIM-1) apligen -m 6 -x 6 -n -o output1.txt -P 1/4
  (PIM-2) apligen -m 6 -x 6 -n -o output2.txt -P 2/4
  (PIM-3) apligen -m 6 -x 6 -n -o output3.txt -P 3/4
  (PIM-4) apligen -m 6 -x 6 -n -o output4.txt -P 4/4


Bug
- bugs in help 


Version: 2.02
- 1 Rule - Each character can be used only once in password
- Simple progress indicator

Bug 
- print to stdout in medium loop is disabled




Version: 2.01
- 1 Rule - String cannot be apart of password
- Whole code rewrite
- 1-10 % speed up
- Makefile



Version 1.26
New
- 1 Rule - Password must meat password policy complexity


Version 1.25
New
- 1 Rule - Convert to hex
- Load characters set from file (one set per line)

Bug
- some minors bugs

Version 1.24
New
- 1 Rule - Match password to the mask
- uml diagrams 

Version 1.23
New
- 1 Rule - skip passwords that have the same characters in row
- Removed dialog 
- Manipulate characters from command line
- Extended Help


Version 1.22
New:
- 5 generation loop (time saving)
- Inversed characters order
- Many output for command line
- Summary before generation


Version 1.21
New:
- Adding constant stirng (both end and start)
- Randomized characters order
- Inverse output 
Implemented for command line mode. Dialog mode remain the same


Version 1.12
Bug fix:
Segment fault - for more than 8 line passwords in command line mode
Segment fault - for more than 5 output files in dialog mode
	

Version 1.11
Bug fix:
2GB limit
Speed up - delete std output for each line


