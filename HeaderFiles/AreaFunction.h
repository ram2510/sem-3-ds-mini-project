//========================================================================================
/*                                                                                      *
 *                                    include guards                                    *
 *                                                                                      */
//=======================================================================================
#ifndef _AREA_H_
#define _AREA_H_
//########################################################################################

//========================================================================================
/*                                                                                      *
 *                            import essential header files                             *
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
#include "../Strutures/AreaStructure.h"
//########################################################################################

//========================================================================================
/*                                                                                      *
 *                                 function declartions                                 *
 *                                                                                      */
//========================================================================================

/*
*@description  This function will check wheter a property esist or not
*@param A pointer pointing towards the structure which consists of the area details
*@returns 1 if the details is present 0 if not
*/
int containsProperty(area *areaDetails);

/*
*@description  This function will check wheter a property esist or not
*@param A pointer pointing towards the structure which consists of the area details
*@returns 1 if the details is added 0 if not
*/
int AddArea(area *areaDetails);

/*
*@description  This function will display all the area
*@param Array of the strings which contains all the strings for area names
*@returns -
*/
char* displayAreaAndReturnName(char *areaArr[]);

/*
*@description  This function will delete the selcted property
*@param string with the rea name
*@returns 1 if the details is deleted 0 if not
*/
int incrementView(char *area);
//########################################################################################


#endif