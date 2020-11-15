/*
A BOOK ON C EXERCISE 10
The following program writes a large letter I on the screen:
See Page 62
Write a similar program that prints a large letter C on the screen 
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#define BOTTOM_SPACE "\n\n\n\n\n"
#define HEIGHT       12
#define TOP_SPACE    "\n\n\n\n\n"
#define ROW          "CCCCCC"

char *concat_char(char basechar, int times, int counter_offset, int reversed){
    char char_to_string[2];
    char_to_string[1] = '\0';
    char_to_string[0] = basechar;
    char* thestring;
    if (reversed) {
        thestring = (char*) malloc((times + 6 + counter_offset) * sizeof(char));
    } else {
        thestring = (char*) malloc((times + 1 + counter_offset) * sizeof(char));
    }
    for (int i=0; i< times; ++i){
        strcat(thestring, char_to_string);
    }
    return thestring;
}

int main(void)
{
    int j, intoffset;
    double offset;
    printf(TOP_SPACE);
    for (j=0; j < HEIGHT; ++j)
    {
        offset = ((float)1/(j+6))*192;
        intoffset = round(offset);
        char* concatstring; 
        concatstring = (char*) malloc((intoffset + 7) * sizeof(char));
        concatstring = concat_char(' ', intoffset, j, 0);
        printf("%s", concatstring);
        printf(ROW);
        printf("\n");
        free(concatstring);
    }
    for (j = HEIGHT; j > -1; --j)
    {
        offset = ((float)1/(j+6))*192;
        intoffset = round(offset);
        char* concatstring; 
        concatstring = (char*) malloc((intoffset + 7) * sizeof(char));
        concatstring = concat_char(' ', intoffset, j, 1);
        printf("%s", concatstring);
        printf(ROW);
        printf("\n");
        free(concatstring);
    }
    printf(BOTTOM_SPACE);
    return 0;
}
