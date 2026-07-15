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

float get_ingred_calories();
float get_ingred_protein();
float get_ingred_carbs();
float get_ingred_fat();
float get_ingred_sat_fat();
float get_ingred_trans_fat();
float get_ingred_cholesterol();
float get_ingred_sodium();
float get_ingred_fiber();
float get_ingred_sugar();
float get_ingred_vitamin_d();
float get_ingred_calcium();
float get_ingred_iron();
float get_ingred_potassium();

ingredient *duplicate_ingredient(ingredient *ingred);

void destroy_ingredient(ingredient *ingred);

#endif 
