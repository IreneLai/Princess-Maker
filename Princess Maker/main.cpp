#include"princess.h"
#include"places.h"
#include"rule.h"
#include<iostream>
#include<stdlib.h>
using namespace std;
int main()
{
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
        printf("\nWhich place would you like to go?...(1 ~ 5)>");
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
    AllTitleRules allr;
    int ruleNum=0;
    PrintPrincess(&pri);
    cout<<endl;
    if(!Create(&allr)) printf("allrules create fail!\n");
    else
    {
        for(int i=0;i<allr.num_rules;++i)
        {
            int matchCon=0;
            for(int j=0;j<allr.rules[i].num_conditions;++j)
            {
                int lhs=0,rhs=0;

                const Attribute *attrlhs=GetAttribute(&pri,allr.rules[i].conditions[j].lhs);
                const Attribute *attrrhs=GetAttribute(&pri,allr.rules[i].conditions[j].rhs);

                if(attrlhs!=nullptr)lhs=attrlhs->val;
                else lhs=atoi(allr.rules[i].conditions[j].lhs);

                if(attrrhs!=nullptr)rhs=attrrhs->val;
                else rhs=atoi(allr.rules[i].conditions[j].rhs);

                switch (allr.rules[i].conditions[j].relation)
                {
                case '=':
                    if(lhs==rhs) matchCon++;
                    break;
                case '<':
                    if(lhs<rhs) matchCon++;
                    break;
                case '>':
                    if(lhs>rhs) matchCon++;
                    break;
                }

                if(matchCon==allr.rules[i].num_conditions)
                {
                    ruleNum++;
                    cout<<"After "<<day<<" days, Princess "<<pri.name<<" becomes a "<<allr.rules[i].title<<"."<<endl;
                }
            }
        }
    }
    if(ruleNum==0)
    {
        cout<<"After "<<day<<" days, Princess "<<pri.name<<" becomes a nobody."<<endl;
    }
    system("pause");
    return 0;
}
