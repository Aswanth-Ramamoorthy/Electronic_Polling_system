#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#pragma warning(disable:4996)
void cast_vote(char*province, char*name)
{
    FILE* cd_fp;
    char buf[1024];
    char buffer[1024];
    char* first_name;
    printf("\n==========================================\n");
    printf("\nCANDIDATE INFORMATION\n\n");
    cd_fp = fopen("candidate_details.csv", "r");
    if (!cd_fp)
    {
        printf("Can't open file\n");
        exit(0);
    }
    char* cd_province;
    while (fgets(buf, 1024, cd_fp))
    {
        cd_province = strtok(buf, ",");

        if (strcmp(cd_province, province) == 0)
        {
            break;
        }
    }
    char* cand1 = cd_province;
    cand1 = strtok(NULL, ",");

    char* cand2 = cand1;
    cand2 = strtok(NULL, ",");

    char* cand3 = cand2;
    cand3 = strtok(NULL, ",");

    char* cand4 = cand3;
    cand4 = strtok(NULL, ",");

    char* cand5 = cand4;
    cand5 = strtok(NULL, ",");


    printf("Press 1 to vote for %s\n", cand1);
    printf("Press 2 to vote for %s\n", cand2);
    printf("Press 3 to vote for %s\n", cand3);
    printf("Press 4 to vote for %s\n", cand4);
    printf("Press 5 to vote for %s\n", cand5);

    //    FILE *ud_fp = fopen("userdetails.csv", "r");
    //    while (fgets(buffer, 1024, ud_fp))
    //    {
    //        first_name = strtok(buffer, ",");
    //        if(strcmp(first_name,name)==0)
    //        {
    //            while(first_name!=NULL)
    //            {
    //                if(first_name=='N')
    //                {
    //                    printf("in if %s\n",first_name);
    //                    break;
    //                }
    //                else
    //                {
    //                    first_name = strtok(NULL,",");
    //                    printf("in else %s\n",first_name);
    //                }
    //            }
    //            break;
    //        }
    //    }
    //    printf("%s\n",first_name);
    //    fclose(ud_fp);
    //    int t=0;
    printf("\n\n\t\t\t\tPress Enter to vote...!!");
    if (getch() == 13)
        printf("\n\n\t\t\t\tENTER YOUR CHOICE: ");
REP:
    scanf("%d", &n);
    char* temp;
     FILE *f=fopen("Vote_record.csv","a+");
     if (!f)
    {
        printf("Can't open file\n");
    }
    switch (n)
    {
    case 1:
        printf("\n\n\t\t\t\tYou voted %s\n", cand1);
         printf("\nData Saved into Voter_record.csv\n\n");
        for (int i=0; i<1; i++)
        {
            fprintf(f,"\n%s,%s",name,cand1);
        }
        fclose(f);
        break;
        exit(0);
    case 2:
        printf("\n\n\t\t\t\tYou voted %s", cand2);
        printf("\nData Saved into Voter_record.csv\n\n");
        for (int i=0; i<1; i++)
        {
            fprintf(f,"\n%s,%s",name,cand2);
        }
        fclose(f);
        break;
        exit(0);
    case 3:
        printf("\n\n\t\t\t\tYou voted %s", cand3);
        printf("\nData Saved into Voter_record.csv\n\n");
        for (int i=0; i<1; i++)
        {
            fprintf(f,"\n%s,%s",name,cand3);
        }
        fclose(f);
        break;
        exit(0);
    case 4:
        printf("\n\n\t\t\t\tYou voted %s", cand4);
        printf("\nData Saved into Voter_record.csv\n\n");
        for (int i=0; i<1; i++)
        {
            fprintf(f,"\n%s,%s",name,cand4);
        }
        fclose(f);
        break;
        exit(0);
    case 5:
        printf("\n\n\t\t\t\tYou voted %s", cand5);
          printf("\nData Saved into Voter_record.csv\n\n");
        for (int i=0; i<1; i++)
        {
            fprintf(f,"\n%s,%s",name,cand5);
        }
        fclose(f);
        break;
        exit(0);
    default:
        printf("\n\n\t\t\t\tPlease choose a valid candidate!\n");
        goto REP;
    }
    fclose(cd_fp);
}