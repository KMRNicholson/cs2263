/* 
    parser.h

    Description:
    Header file for parser.h
    
    Author: 
    Kohdy Nicholson
    
    Date: 
    2020-05-24
*/

int is_letter(char ch);
int is_num(char ch);
char* extract_tag(char* tag_start);
int check_tag_list(char** list, char* tag, int n);
int is_comment(char* start);
void remove_comment(char* start);