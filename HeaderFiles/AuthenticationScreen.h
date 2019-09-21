//========================================================================================
/*                                                                                      *
 *                                    include guards                                    *
 *                                                                                      */
//=======================================================================================
#ifndef _AUTH_H_
#define _AUTH_H_
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
 *                                 function declartions                                 *
 *                                                                                      */
//========================================================================================
/*
*@description  This function will handle and call all the function in the authentication screen
*@param None
*@retuens 1 if the user is present 0 if not
*/
int Authenticate();

/*
*@description  This function will add new admins
*@param username and password of the user to add
*@retuens 1 if the user is added 0 if error occured
*/
int AddUser(char username[],char password[]);

/*
*@description  This function will authenticate user based on input
*@param username and password of the user to authenticate
*@retuens 1 if the user is preset 0 if not
*/
int compareAndAuthenticate(char username[],char pass[]);
//########################################################################################


#endif