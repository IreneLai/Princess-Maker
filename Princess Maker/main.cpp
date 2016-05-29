#include"princess.h"
#include"places.h"
#include"rule.h"
#include<iostream>
#include<stdlib.h>
using namespace std;
int GetValue(const Princess &p, const char str[])
{
    if (isdigit(str[0])) return atoi(str);
    else return GetAttribute(&p, str)->val;
}
bool Satisfy(const Princess &p, const Condition &cond)
{
    if(cond.relation=='>') if( GetValue(p, cond.lhs) > GetValue(p, cond.rhs) ) return true;
        else if(cond.relation=='=') if( GetValue(p, cond.lhs) == GetValue(p, cond.rhs) ) return true;
            else if( GetValue(p, cond.lhs) < GetValue(p, cond.rhs) ) return true;

    return false;
}
int main()
{
    /*
    int day=10;
    int countDay=day-1,op=0;

    Princess pri;
    Place plc;
    AllPlaces allp;
    //Create Princess, Rule and Place
    Create(&pri);
    if(!ReadPlaces(&allp)) printf("Create place failed!\n");
    //user interface
    cout<<"========================================="<<endl
        <<"|   Princess Maker Extremely Simplied   |"<<endl
        <<"========================================="<<endl<<endl;
    cout<<"Hello Princess, what's your name?...(no more than "<<MaxLenName<<" chars)>";
    cin>>pri.name;
    cout<<endl<<"Princess "<<pri.name<<", let's start the "<<day<<"-day journey!"<<endl<<endl;
    system("pause");
    system("cls");
    while(countDay>=0)
    {
        //print princess
        cout<<"Day   "<<day-countDay<<" (  "<<countDay<<" days left)        ";
        PrintPrincess(&pri);
        cout<<"=================================================================="<<endl;
        PrintAllplace(allp);
        printf("==================================================================\n");
        printf("\nWhich place would you like to go?...(1~5)>");
        scanf("%d",&op);
        if(op>=1&&op<=5)
        {
            if(pri.money + allp.places[op-1].cost_reward < 0) //If princess have no money
            {
                printf("\nSorry, Princess %s, we don't have enough money to go to %s.\n",pri.name, allp.places[op-1].name);
            }
            else //Go to somewhere
            {
                if(GoToPlace(&pri, allp, op)) countDay--; //If have enough money, then need to countDay--
                //Else no money no need to countDay--
            }
        }
        else
        {
            cout<<endl<<"Princess "<<pri.name<<" keeps idle today. Nothing happens."<<endl;
            countDay--;
        }
        system("pause");
        system("cls");
    }

    //Princess becomes which class
   */
    AllTitleRules allr;
    if(!Create(&allr)) printf("allrules create fail!\n");
    for(int i=0;i<allr.num_rules;++i)
    {
        cout<<allr.rules[i].title<<"-----------"<<endl;
        for(int j=0;j<allr.rules[j].num_conditions;++j)
        {
            cout<<allr.rules[i].conditions[j].lhs<<endl;
            cout<<allr.rules[i].conditions[j].relation<<endl;
            cout<<allr.rules[i].conditions[j].rhs<<endl;
        }

    }
     /*
    else
    {
        int nobody=0; //0 as NO, 1 as YES
        PrintPrincess(&pri);
        //Print(&allr); //To see all rules
        printf("\nAfter %d days, Princess %s becomes a ", day, pri.name);
        for (int i=0; i<allr.num_rules; i++) //rule i
        {
            for(int j=0; j<allr.rules[i].num_conditions; j++) //condition j
            {
                if( Satisfy(pri, allr.rules[i].conditions[j]) ) continue;
                else break;
                if( j==(allr.num_rules-1) ) nobody=1, printf("%s.\n", allr.rules[j].title); //All conditions have been checked, and become SOMEBODY
            }
        }
        if(nobody!=1) printf("nobody.\n"); //become NOBODY
    }*/

    system("pause");
    return 0;
}
