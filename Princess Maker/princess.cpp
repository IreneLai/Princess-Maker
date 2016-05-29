#include"princess.h"
#include<iostream>
#include <iomanip>
using namespace std;
void Create(Attribute *attr, const char name[], int v)
{
    strcpy(attr->name,name);
    attr->val=v;

}
void Print(const Attribute *attr)
{
    cout<<setw(18)<<attr->name<<setw(5)<<attr->val<<setw(8);
    for(int i=0;i<attr->val/30;++i) cout<<"*";
    cout<<endl;
}
void AddValue(Attribute *attr, int offset)
{
    attr->val+=offset;
}
void Create(Princess *pri)// read attribute names from attributes.txt
{
    strcpy(pri->name,"");
    pri->money=1000;
    pri->num_attrs=0;
    FILE *fp=fopen("attributes.txt","r");
    if(fp)
    {
        Attribute attr;
        char name[MaxLenName]="";
        while(fscanf(fp,"%s",name)==1)
        {
            Create(&attr,name,0);
            if(!AddAttribute(pri,attr))
            {
                cout<<"Cannot add the attribute"<<endl;
                break;
            }
        }
        fclose(fp);
    }
}
void Print(const Princess *pri)
{
    cout<<"Princess "<<pri->name<<": ($ "<<pri->money<<")"<<endl;

}
void PrintPrincess(const Princess *pri)
{
    Print(pri);
    cout<<endl;
    for(int i=0; i<pri->num_attrs; ++i) Print(&pri->attribute[i]);
}
bool AddAttribute(Princess *pri, Attribute attr) // return 0 if not successful
{
    if(GetAttribute(pri,attr.name)!=nullptr)
    {
        return false;
    }
    if(pri->num_attrs<MaxNumAttributes-1)
    {
        pri->attribute[pri->num_attrs]=attr;
        pri->num_attrs++;
        return true;
    }
    return false;
}
const Attribute *GetAttribute(const Princess *pri, const char attr_name[])
{
    for(int i=0; i<pri->num_attrs; ++i)
    {
        if(strcmp(pri->attribute[i].name,attr_name)==0)
        {
            return &pri->attribute[i];
        }
    }
    return nullptr;
}
