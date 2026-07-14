#include "nutritional_info.h";
#include "extra_nutritional_info.h";
#include "vitamins.h";

#ifndef ingredients
#define ingredients

/**
 * A structure for holding information about generic ingredients.
 * 
 * All values are in grams unless otherwise noted
 */
typedef struct {
    char *name;
    char *description;
    float  portion_size;

    // Nutrional Information
    nutri_info *nutrition;
    extra_nutri_info *extra_nutrition;
    vitamin_info *vitamin
} ingredient;

ingredient  *create_ingredient(char *name, char *description, float portion_size);
int fill_ingredient(ingredient *ingred, nutri_info *info, extra_nutri_info *extra_info, 
                    vitamin_info *vit_info);


int set_ingred_nutri_info(ingredient *ingred, nutri_info *info);
int set_ingred_extra_nutri_info(ingredient *ingred, extra_nutri_info *info);
int set_ingred_vitamins(ingredient *ingred, vitamin_info *info);

ingredient *duplicate_ingredient(ingredient *ingred);

void destroy_ingredient(ingredient *ingred);

#endif 
