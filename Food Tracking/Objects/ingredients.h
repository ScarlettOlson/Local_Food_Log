#include "nutritional_info.h";
#include "extra_nutritional_info.h";
#include "vitamins.h";

#ifndef ingredients
#define ingredients

typedef struct {
    char *name;
    char *description;
} ingredient;

ingredient  *create_ingredient(char *name, char *description, float portion_size);
int fill_ingredient(ingredient *ingred, nutri_info *info, extra_nutri_info *extra_info, 
                    vitamin_info *vit_info);


int set_ingred_nutri_info(ingredient *ingred, nutri_info *info);
int set_ingred_extra_nutri_info(ingredient *ingred, extra_nutri_info *info);
int set_ingred_vitamins(ingredient *ingred, vitamin_info *info);

float get_ingred_calories(ingredient *ingred);
float get_ingred_protein(ingredient *ingred);
float get_ingred_carbs(ingredient *ingred);
float get_ingred_fat(ingredient *ingred);
float get_ingred_sat_fat(ingredient *ingred);
float get_ingred_trans_fat(ingredient *ingred);
float get_ingred_cholesterol(ingredient *ingred);
float get_ingred_sodium(ingredient *ingred);
float get_ingred_fiber(ingredient *ingred);
float get_ingred_sugar(ingredient *ingred);
float get_ingred_vitamin_d(ingredient *ingred);
float get_ingred_calcium(ingredient *ingred);
float get_ingred_iron(ingredient *ingred);
float get_ingred_potassium(ingredient *ingred);

void set_ingred_calories(ingredient *ingred, float val);
void set_ingred_protein(ingredient *ingred, float val);
void set_ingred_carbs(ingredient *ingred, float val);
void set_ingred_fat(ingredient *ingred, float val);
void set_ingred_sat_fat(ingredient *ingred, float val);
void set_ingred_trans_fat(ingredient *ingred, float val);
void set_ingred_cholesterol(ingredient *ingred, float val);
void set_ingred_sodium(ingredient *ingred, float val);
void set_ingred_fiber(ingredient *ingred, float val);
void set_ingred_sugar(ingredient *ingred, float val);
void set_ingred_vitamin_d(ingredient *ingred, float val);
void set_ingred_calcium(ingredient *ingred, float val);
void set_ingred_iron(ingredient *ingred, float val);
void set_ingred_potassium(ingredient *ingred, float val);

ingredient *duplicate_ingredient(ingredient *ingred);

void destroy_ingredient(ingredient *ingred);

#endif 
