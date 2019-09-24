//========================================================================================
/*                                                                                      *
 *                                    include guards                                    *
 *                                                                                      */
//========================================================================================
#pragma once
#ifndef _SET_ADT_H_
#define _SET_ADT_H_
//########################################################################################
//========================================================================================
/*                                                                                      *
 *                             import essential header files                            *
 *                                                                                      */
//========================================================================================
#include<stdio.h>
#include<stdlib.h>
#include <string.h> 
//########################################################################################
//========================================================================================
/*                                                                                      *
 *                             import user defined functions                            *
 *                                                                                      */
//========================================================================================
#include "../Strutures/PropertyStrutures.h"
#include "../Strutures/SetStruct.h"
//########################################################################################
//========================================================================================
/*                                                                                      *
 *                                 function declartions                                 *
 *                                                                                      */
//========================================================================================

/*
*@description  This function will check whether a particular property exist in set ADT
*@param A pointer to the struct which has the details of the property 
*@returns 1 if the property is present in set 0 if not
*/
int contains(propStrut *propDetails);


/*
*@description  This function will display or the elements in a set
*@param 1) A pointer to the set of which you would like to diplay elements
*       2) A pointer to the struct which has the details of the property 
*@returns 1 if the property is present in set 0 if not
*/
int display(SetADT *set);

//########################################################################################

#endif