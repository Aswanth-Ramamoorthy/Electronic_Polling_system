/**
 * @file admin_login.h
 *
 * @brief Implementation of admin login function to view the vote count .
 * 
 *
 * @author vignesh balaji - vigneshbalaji@cmail.carleton.ca
 * 
 **/
#ifndef _ADMIN_LOGIN_H_
#define _ADMIN_LOGIN_H_

/** 
 * @brief This function to authenticate admin to display the vote_count.csv.
 *
 *
 * @details This function compares the input(i.e Admin-ID and PAssword) given 
 * by the Admin.when the comparison gets successful the output will display as 
 * Welcome.Login success!.and asks the user to enter the filename to display the 
 * vote count.
 *
 * @param[in] It takes the Admin-ID, Password and File name as the input parameter. 
 *
 * @return Return 1 on successful login and 0 if login failed.
 *
 **/
extern int admin_login();
#endif 

