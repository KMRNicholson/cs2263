/* 
    Link.h

    Description:
    Header file which contains function signatures for a link

    Author: 
    Kohdy Nicholson
    
    Date: 
    2020-06-14
*/

#ifndef LINK_H
#define LINK_H

#include <stdio.h>
#include "Point2D.h"

// Struct typedef
typedef struct link{
    pPoint2D point;
    struct link* next;
} Link, *pLink;

/* CRUD functions */

// Creates a List struct given x and y coordinates
pLink createLink(pPoint2D point);
// Read the link
void readLink(pLink link);
// Read a list of links to the console
void readLinks(pLink link);
// Delete the link.
void destroyLink(pLink link);
// Deletes the links. Calls free recursively on all proceeding links.
void destroyLinks(pLink link);

#endif