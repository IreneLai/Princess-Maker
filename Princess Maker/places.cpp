#include<stdio.h>
#include<string.h>
#include"princess.h"
#include"places.h"
void PrintPlace(const Place place)
{
    printf("%20s $ %+5d\n",place.name,place.cost_reward);
}
void PrintAllplace(const AllPlaces ap)
{
    printf("All %d places to go:\n\n",ap.num_places);
    for(int i = 0; i < ap.num_places; i+=1)
    {
        printf("[%02d]",i+1);
        PrintPlace(ap.places[i]);
    }
}
void PrintEffect(const Place place)
{
    printf("%20s %+5d\n","Money",place.cost_reward);
    for(int i=0; i<place.num_effects; i++)
    {
        printf("%20s %+d\n",place.effects[i].name,place.effects[i].offset);
    }
}
int GoToPlace(Princess *p, const AllPlaces allp,int choose)
{
    if( p->money >= (-allp.places[choose-1].cost_reward) )
    {
        printf("\nAfter going to %s,Princess %s gets her ability better:\n\n",allp.places[choose-1].name,p->name);
        p->money+=allp.places[choose-1].cost_reward;
        PrintEffect(allp.places[choose-1]);
        for(int i=0; i<allp.places[choose-1].num_effects; i++)
        {
            for(int j=0; j<4; j++)
            {
                if(strcmp(allp.places[choose-1].effects[i].name,p->attribute[j].name)==0)
                {
                    p->attribute[j].val+=allp.places[choose-1].effects[i].offset;
                    if(p->attribute[j].val<0) p->attribute[j].val=0;
                    break;
                }
            }
        }
        return 1;
    }
    else
    {
        printf("Sorry,Princess %s,we don't have enough money to go to %s.\n",p->name,allp.places[0].name);
        return 0;
    }
}
bool ReadPlaces(AllPlaces *allp)
{
    char notname[5]="#";
    FILE *fp=fopen("places.txt","r");
    if(fp==0) return 0;
    int i=0;
    while(fscanf(fp,"%s %d",allp->places[i].name,&allp->places[i].cost_reward)!=EOF)
    {
        while(fscanf(fp,"%s",allp->places[i].effects[allp->places[i].num_effects].name))
        {
            if(strcmp(allp->places[i].effects[allp->places[i].num_effects].name,notname)==0) break;
            fscanf(fp,"%d",&allp->places[i].effects[allp->places[i].num_effects].offset);
            allp->places[i].num_effects++;
        }
        allp->num_places++;
        i++;
    }
    fclose(fp);
    return 1;
}
