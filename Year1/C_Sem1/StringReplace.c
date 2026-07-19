#include <stdio.h>
#include<string.h>
#include <stdlib.h>

/*******************************************
function name: replace
description: When mode is 1, replace the first target found in source with the replacement.
             When mode is 2, replace left-most target by replacement until there are no targets in the source.
return value: Return the result after replace.
*******************************************/
char *replace(char *source, char *target, char *replacement, int mode) 
{
    if (mode == 1) rep(source, target, replacement); 

    else if (mode == 2)
    {
        while(1)
        {
            int has_sub_string = rep(source, target, replacement);
            if (has_sub_string == 0) return source;  
        }
    }
    return source; 
}                                       

int rep (char *source, char *target, char *rep)
{
    char *p = strstr(source, target); 

    if(p == NULL) return 0; 

    int size = strlen(source); 

    int size_to_be_replaced = strlen(target) - strlen(rep); 

    char new_str[size + 1];

   
    int j = 0; 
    for (char *i = source; i < p; i++)
    {
        new_str[j] = source[j];  
        j++;
    }


    for (int i = 0; i < strlen(rep); i++)
    {
        new_str[j] = rep[i]; 
        j++; 
    }

    int index = j + size_to_be_replaced; 
    for (int i = index; i < strlen(source); i++)
    {
        new_str[j] = source[i];
        j++;  
    }

    new_str[j] = '\0'; 
    for (int i = 0; i < strlen(source); i++) source[i] = new_str[i]; 

    return 1; 
}