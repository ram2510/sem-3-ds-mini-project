//========================================================================================
/*                                                                                      *
 *                                    include guards                                    *
 *                                                                                      */
//=======================================================================================
#ifndef _PROP_H_
#define _PROP_H_
//########################################################################################
//========================================================================================
/*                                                                                      *
 *                            import essential header files                             *
 *                                                                                      */
//========================================================================================
#include<stdio.h>
#include <string.h> 
//########################################################################################

//========================================================================================
/*                                                                                      *
 *                             import user defined functions                            *
 *                                                                                      */
//========================================================================================
#include "../Strutures/UserStruct.h"
#include "../Strutures/PropertyStrutures.h"
#include "../Strutures/SetStruct.h"
#include "../Strutures/AreaStructure.h"
#include "../HeaderFiles/AreaFunction.h"
#include "../HeaderFiles/SetADT.h"
//########################################################################################

//========================================================================================
/*                                                                                      *
 *                                 function declartions                                 *
 *                                                                                      */
//=======================================================================================

/*
*@description  This function will add new properties
*@param 1) A pointer pointing towards the struture which contains property details
*       2) A pointer pointing towards the set structure which contains all the prop details
*@returns 1 if the property is added 0 if error occured
*/
int AddProperty(propStrut* propertyDetails);

/*
*@description  This function will display properties and description the user selectes
*@param 1) A pointer pointing towards the mem block containg the selected area strings
*@returns -
*/
void displayPropertyAndDescription(char *areaName);
//########################################################################################

#endif