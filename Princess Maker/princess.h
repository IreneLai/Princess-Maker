#include<string.h>
#include<stdio.h>
#ifndef PRINCESS_H___
#define PRINCESS_H___
const int MaxLenName=17;
const int MaxNumAttributes=10;
struct Attribute
{
    char name[MaxLenName+1] = "";
    int val= 0;
};
struct Princess
{
    char name[MaxLenName+1]="";
    int money=1000;
    Attribute attribute[MaxNumAttributes];
    int num_attrs=0;
};
#endif // PRINCESS_H___
void Create(Attribute *attr, const char name[], int v);
void Print(const Attribute *attr);
void AddValue(Attribute *attr, int offset);
void Create(Princess *pri);// read attribute names from attributes.txt
void Print(const Princess *pri);
void PrintPrincess(const Princess *pri);
bool AddAttribute(Princess *pri, Attribute attr); // return 0 if not successful
const Attribute *GetAttribute(const Princess *pri, const char attr_name[]);

