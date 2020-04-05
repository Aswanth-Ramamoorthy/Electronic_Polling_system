#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#pragma warning(disable:4996)
void cast_vote(char *candidate)
{
    char buffer[1024];
    char *first_name;
    int cnt=0;
    FILE *v_fp = fopen("votes.csv", "r");
    while (fgets(buffer, 1024, v_fp))
    {
        first_name = strtok(buffer, ",");
        cnt++;
        if(strcmp(first_name,candidate)==0)
        {
            break;
        }
    }
    int vote_val;
    char *vote = first_name;
    vote = strtok(NULL,",");
    sscanf(vote,"%d",&vote_val);
    vote_val++;
    printf("%d\n",vote_val);
    fclose(v_fp);
//    FILE *v_fpw = fopen("votes.csv", "a");
//    while(cnt)
//    {
//        fprintf(v_fpw,"\n");
//        cnt--;
//    }
//    fprintf(v_fpw,"\t");
//    fprintf(v_fpw,"%d",vote_val);
//    printf("Updated\n");
//    fclose(v_fpw);
}
void candidate_details(char* province,char *name)
{
    FILE* cd_fp;
    char buf[1024];
    char buffer[1024];
    char *first_name;
    printf("\n==========================================\n");
    printf("\nCANDIDATE INFORMATION\n\n");
    cd_fp = fopen("candidate_details.csv", "r");
    if (!cd_fp)
    {
        printf("Can't open file\n");
        exit(0);
    }
    char *cd_province;
    while (fgets(buf, 1024, cd_fp))
    {
        cd_province = strtok(buf, ",");

        if(strcmp(cd_province,province)==0)
        {
            break;
        }
    }
    char *cand1 = cd_province;
    cand1 = strtok(NULL,",");

    char *cand2 = cand1;
    cand2 = strtok(NULL,",");

    char *cand3 = cand2;
    cand3 = strtok(NULL,",");

    char *cand4 = cand3;
    cand4 = strtok(NULL,",");

    char *cand5 = cand4;
    cand5 = strtok(NULL,",");


    printf("Press 1 to vote for %s\n",cand1);
    printf("Press 2 to vote for %s\n",cand2);
    printf("Press 3 to vote for %s\n",cand3);
    printf("Press 4 to vote for %s\n",cand4);
    printf("Press 5 to vote for %s\n",cand5);

    printf("\n\n\t\t\t\tPress Enter to vote...!!");
    if (getch() == 13)
        printf("\n\n\t\t\t\tENTER YOUR CHOICE: ");
    REP:
    scanf("%d", &n);
    char *temp;
    switch(n)
    {
    case 1:
        cast_vote(cand1);
        //printf("\n\n\t\t\t\tYou voted %s\n",cand1);
        break;
        exit(0);
    case 2:
        printf("\n\n\t\t\t\tYou voted %s",cand2);
        break;
        exit(0);
    case 3:
        printf("\n\n\t\t\t\tYou voted %s",cand3);
        break;
        exit(0);
    case 4:
        printf("\n\n\t\t\t\tYou voted %s",cand4);
        break;
        exit(0);
    case 5:
        printf("\n\n\t\t\t\tYou voted %s",cand5);
        break;
        exit(0);
    default:
        printf("\n\n\t\t\t\tPlease choose a valid candidate!\n");
        goto REP;
    }
    fclose(cd_fp);
}