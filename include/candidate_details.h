/**
 * @file candidate_details.h
 *
 * @brief Implementation of Candidate_details function to display the candidates contesting in
 * particular province
 * 
 *
 * @author Priyanga Soundararajan - priyangasoundararaja@cmail.carleton.ca
 * 
 * 
 **/
#ifndef _CANDIDATE_DETAILS_H_
#define _CANDIDATE_DETAILS_H_
/** 
 * @brief The function displays a list of candidates present in the file. 
 *
 * @param[in] The function takes “province” as input parameter. 
 *
 * @param[out] The function returns “candidate_number” which is the 
 * candidate number provided as input by the user. 
 *
 * @return Return 0 when file can't open.
 *
 **/
extern int candidate_details(char* province);
#endif 
