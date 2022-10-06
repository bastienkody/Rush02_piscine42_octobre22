#ifndef NUMBER_MGMT_H
# define NUMBER_MGMT_H
#include <stdlib.h>
#include <stdio.h>

typedef struct s_number
{
	char centaine[2];
	char dizaine[2];
	char unite[2];
	char *pos;
}	t_number;

t_number	*parse_number(char *nbr);
void	print_t_number(t_number *number);

#endif

/*
Cut nbr in 3digits parts and stores it in an array of structures; nbr keeps being a *char : 
Store each part in a struct of 4 (char *) elements : centaine, diziane, unite and pos (centaine, thousand, bilion etc)
we can use the array index (0-nothing, 1-thousand, 2-milion) to multiply the pos it hmmm carfeul it is a *char ... 
multiplication can be: 1000 ** arr_index
can't use integer since it is limited to 2^31-1.
we'll generate a char *pos composed of 1 + x0 according to array_index
--> 123 456 789 must be cut in 3 parts
--> struct0 = 7, 8, 9, 1 ; struct1 = 4, 5, 6, 1000 ; struct2 = 1, 2, 3, 1000000
When the centaine is printed out as a simple digit, we must directly then print out "hundred"
This leads to 2 pb with the dizaine :
- first, there is a special treatment with the unite frm 10 to 19 (only occurs when dizaine == 1)
- second, its different from the centaine (digit + hundred) : we must multiply it by ten and look for 20, 30 ... 90

Another problem : if nb is given like 00000123
We must not print for any triplet of 000, 
This is true for any triplet (except only 0): 
higher as in 000 000 123 -> ... ... 1hundred twenty three
middle as in 1 000 123 -> 1mil ... 1hundred twentry three
lastee as in 1 123 000 -> 1mil 1hundred twenty three thousands ...
exception : 000 000 000 -> ... ... zero 

printf treatment in two steps : 
1 - Each triplet treated as a centaine : 
-------------------------------------------------------------------------
-centaine : if > 0 : print digit and then hundred
			if == 0 : do nothing
-------------------------------------------------------------------------
-dizaine :  if > 1, mutliply by ten and look for it in the dict, print it
		  	if == 1 : look for dizaine et unité together in the dict
		  	if == 0 : do nothing
-------------------------------------------------------------------------
-unite : 	if > 0 : printf digit
			if == 0 : if no printed before && if arr_index == 0 : print 0
-------------------------------------------------------------------------
2 - Quantifier for the triplet : directly after the triplet is printed, 
print the corresponding quantifier (thousand/milion/bilion etc)

repeat until you reach the last 3digits
*/
