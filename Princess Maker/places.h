#ifndef PLACE_H___
#define PLACE_H___
const int MaxNumEffects = 10;
const int MaxNumPlaces = 10;
struct Effect
{
    char name[MaxLenName]="";
    int offset=0;
};
struct Place
{
    char name[MaxLenName]="";
    Effect effects[MaxNumEffects];
    int num_effects=0;
    int cost_reward=0;
};
struct AllPlaces
{
    Place places[MaxNumPlaces];
    int num_places=0;
};
void PrintPlace(Place place);
void PrintAllplace(AllPlaces ap);
void PrintEffect(Place place);
int GoToPlace(Princess *p,AllPlaces allp,int choose);
bool ReadPlaces(AllPlaces *allp);
#endif // PLACE_H___
