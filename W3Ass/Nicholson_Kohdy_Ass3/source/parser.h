/* 
    parser.h

    Description:
    Header file for parser.h
    
    Author: 
    Kohdy Nicholson
    
    Date: 
    2020-05-24
*/

int find_occurrences(char* contents, char* current);
int is_letter(char ch);
int is_num(char ch);
int is_comment(char* start);
void remove_comment(char* start);