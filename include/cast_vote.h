/**
 * @file cast_vote.h
 *
 * @brief Implementation of cast_vote function to cast vote for the preferred candidate.
 * 
 *
 * @author Soma Sundaram Ravindran-somasundaramravindra@cmail.carleton.ca
 * 
 **/
#ifndef _CAST_VOTE_H_
#define _CAST_VOTE_H_

/**
 *
 * @brief The function to cast vote for the preferred candidate. 
 * @param[in] the function takes “Candidate_ID” as input parameter. 
 *
 * @param[out] The function returns “Vote_casted” when vote is casted for the preferred candidate. 
 * candidate number provided as input by the user. 
 *
 * @return Return 0 when file can't open and return -1 if vote is casted.
 *
 **/
extern int cast_vote(char* province);
#endif 