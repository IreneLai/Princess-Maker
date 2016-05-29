#include "princess.h"
#ifndef RULES_H_INCLUDED
#define RULES_H_INCLUDED
const int MaxNumConditions=10;
const int MaxNumRules=10;

struct Condition
{
    char lhs[MaxLenName] = "", rhs[MaxLenName] = "";
    char relation;
};
void Create(Condition *con,const char lhs_condition[],const char rhs_condition[],char relation);
void Print(const Condition *con);

struct TitleRule
{
    char title[MaxLenName] = "";
    Condition conditions[MaxNumConditions];
    int num_conditions = 0;
};
void Create(TitleRule *rule,const char title_name[],FILE *fp);
bool AddCondition(TitleRule *rule,const Condition *con);
void Print(const TitleRule *rule);

struct AllTitleRules
{
    TitleRule rules[MaxNumRules];
    int num_rules = 0;
};
bool Create(AllTitleRules *allrules);
bool AddRule(AllTitleRules *allrules,const TitleRule *rule);
void Print(const AllTitleRules *allrules);

#endif // RULES_H_INCLUDED
