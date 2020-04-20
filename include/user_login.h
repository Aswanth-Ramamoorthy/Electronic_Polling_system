/**
 * @file user_login.h
 *
 * @brief Implementation of user login login function with encryption .
 * 
 *
 * @author vignesh balaji - vigneshbalaji@cmail.carleton.ca
 * 
 **/
#ifndef _USER_LOGIN_H_
#define _USER_LOGIN_H_
/**
* @brief This function acts as a Authentication for the user to cast vote
*
* @param[in] The function takes the user_name and password as the input parameter
* and compare it with the data in the file.
*
* @param[out] This function  gives user authentication on successful user login details and 
* calls the function secondary_authentication.
*
* @return Returns 0 if file cant't open return 1 on successful login and return -1 on
* unsuccessful login. 
**/
extern int user_login();
#endif 
