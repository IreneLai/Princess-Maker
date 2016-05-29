#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "rule.h"

bool Create(AllTitleRules *allrules)
{
    FILE *fp=fopen("titlerules.txt","r");
    if(fp==0)
    {
        printf("titlerules.txt open fail!\n");
        return false;
    }
    char title_name[MaxLenName]="";
    while(fscanf(fp,"%s",title_name)==1)
    {
        TitleRule rule;
        title_name[strlen(title_name)-1]='\0';   //delete ':'

        Create(&rule,title_name,fp);

        if(!AddRule(allrules,&rule))
        {
            printf("AddRule fail!\n");
            break;
        }
    }
    fclose(fp);

    return true;
}

void Create(TitleRule *rule,const char title_name[],FILE *fp)
{
    strcpy(rule->title,title_name);

    Condition con;
    char lhs_condition[MaxLenName]="";
    char rhs_condition[MaxLenName]="";
    char relation='\0';
    char temp='\0';
    fscanf(fp,"%c",&temp);   //' '
    while(temp!='\n')
    {
        fscanf(fp,"%s %c %s",lhs_condition,&relation,rhs_condition);
        for(int i=0; i<strlen(lhs_condition)-1; ++i)
        {
            lhs_condition[i]=lhs_condition[i+1];
        }
        lhs_condition[strlen(lhs_condition)-1]='\0';   //delete '(';
        rhs_condition[strlen(rhs_condition)-1]='\0';   //delete ')';

        Create(&con,lhs_condition,rhs_condition,relation);

        if(!AddCondition(rule,&con))
        {
            printf("AddCondition fail!\n");
            break;
        }
        fscanf(fp,"%c",&temp);   //' '

        int e=0;
        if(fscanf(fp,"%d",&e)==EOF)
        {
            break;
        }
    }
}

void Create(Condition *con,const char lhs_condition[],const char rhs_condition[],char relation)
{
    strcpy(con->lhs,lhs_condition);
    strcpy(con->rhs,rhs_condition);
    con->relation=relation;
}

bool AddCondition(TitleRule *rule,const Condition *con)
{
    if(rule->num_conditions<MaxNumConditions-1)
    {
        rule->conditions[rule->num_conditions]=*con;
        rule->num_conditions+=1;

        return true;
    }
    return false;
}

bool AddRule(AllTitleRules *allrules,const TitleRule *rule)
{
    if(allrules->num_rules<MaxNumRules-1)
    {
        allrules->rules[allrules->num_rules]=*rule;
        allrules->num_rules+=1;

        return true;
    }
    return false;
}

void Print(const AllTitleRules *allrules)
{
    printf("num_rules : %d\n",allrules->num_rules);
    for(int i=0; i<allrules->num_rules; ++i)
    {
        Print(&allrules->rules[i]);
        printf("\n");
    }
}

void Print(const TitleRule *rule)
{
    printf("title : %s\n",rule->title);
    printf("num_conditions : %d\n",rule->num_conditions);
    for(int i=0; i<rule->num_conditions; ++i)
    {
        Print(&rule->conditions[i]);
    }
}

void Print(const Condition *con)
{
    printf("%s %c %s\n",con->lhs,con->relation,con->rhs);
}
