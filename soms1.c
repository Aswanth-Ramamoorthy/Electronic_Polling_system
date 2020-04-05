#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#pragma warning(disable:4996)
int n;
void ulogin(void);
void alogin(void);
int main()
{
    printf("\n\t\t\t\t==========================================");
    printf("\n\t\t\t\tWELCOME TO THE PRESIDENTIAL ELECTIONS 2020");
    printf("\n\t\t\t\t==========================================");
    printf("\n\nInstructions:\n\n");
    printf("1.You can vote only once.\n2.Login using your User-ID and Password.\n3.Proceed to vote if your information displayed is correct.\n4.Please be fair and impartial in voting");
    printf("\n\n\t\t\t\tIf you agree Press Enter to proceed...!!");
    if (getch() == 13)
        XY:
    printf("\n\n\n\t\t\t\t1. Admin Login\t\t2. User Login");
    printf("\n\n\n\t\t\t\t\tENTER YOUR CHOICE: ");
    scanf("%d", &n);
    switch (n)
    {
    case 1:
        alogin();
        break;
    case 2:
        ulogin();
        break;
    default: printf("\n\n\t\t\t\tNO MATCH FOUND");
        printf("\n\n\t\t\tPress Enter to re-Enter the choice");
        if (getch() == 13)
        goto XY;
    }
    return 0;
}
void alogin()
{
    char adminID[15];
    char adminpass[12];
    char c;
    int i=0;
    printf("Enter your Admin-ID:\n");
    scanf("%s", adminID);
    printf("Enter your password:\n");
    while( (c=getch())!= '\r')
    {
        adminpass[i] = c;
        printf("*");
        i++;
    }
    adminpass[i] = '\0';
    if (strcmp(adminID, "Admin") == 0)
    {
        if (strcmp(adminpass, "white!23") == 0)
        {
            printf("\nWelcome.Login Success!");
        }
        else {
            printf("\nwrong password");
        }
    }
    else {
        printf("\nUser doesn't exist");
    }

}
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

void userdetails(char* name[15])
{
    FILE* fp;
    char buf[1024];
    printf("\n==========================================\n");
    printf("\nUSER INFORMATION\n\n");
    fp = fopen("userdetails.csv", "r");
    if (!fp)
    {
        printf("Can't open file\n");
        return 0;
    }
    char *first_name;
    while (fgets(buf, 1024, fp))
    {
        first_name = strtok(buf, ",");

        if(strcmp(first_name,name)==0)
        {
            break;
        }
    }

    char* last_name = first_name;
    last_name = strtok(NULL, ",");

    char *age = last_name;
    age = strtok(NULL,",");

    char *contact = age;
    contact = strtok(NULL,",");

    char *postal_code = contact;
    postal_code = strtok(NULL,",");

    char *province = postal_code;
    province = strtok(NULL,",");

    printf("First Name : %s\n",first_name);
    printf("Last Name : %s\n",last_name);
    printf("Age : %s\n",age);
    printf("Contact Number : %s\n",contact);
    printf("Postal Code : %s\n",postal_code);
    printf("Province : %s\n",province);

    candidate_details(province,name);
    fclose(fp);
}

void ulogin()
{
    char username[15];
    char password[12];
    int flag=0;
    char c;

    FILE* fp;
    fp = fopen("auth.csv", "r");

    printf("Enter your username:\n");
    scanf("%s", username);

    printf("Enter your password:\n");
    int i=0;
    while( (c=getch())!= '\r')
    {
        password[i] = c;
        printf("*");
        i++;
    }
    password[i] = '\0';
    char string[1024];
    char *field;
    if (!fp) {
        printf("Can't open file\n");
        return 0;
    }
    while (fgets(string, 1024, fp) && flag==0)
    {
        field = strtok(string, ",");
        if (strcmp(field, username) == 0)
        {
            field = strtok(NULL, ",");
            if (strcmp(field, password) == 0)
            {
                    flag++;
            }
        }
    }
    if (flag == 0)
        printf("\nStatus : Invalid login");
    else
    {
        printf("\nStatus : Successful Login");
        userdetails(username);
    }
    fclose(fp);
    return 0;
}
