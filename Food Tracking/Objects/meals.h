#include <stdlib.h>;
#include "ingredients.h";
#include "nutritional_info.h";
#include "extra_nutritional_info.h";
#include "vitamins.h";

#ifndef meals
#define meals

/**
 * A structure for holding information about a user created meal.
 * 
 * All values are in grams unless otherwise noted
 */
typedef struct {
    char    *name;
    char    *description;
    int     portions;

    int     *ingred_portions;
    ingredient  **ingred_list;
    
    int set_nutrion_manually;
    nutri_info nutrition;
    extra_nutri_info extra_nutrition;
    vitamin_info viatmins;
} meal;

meal *create_meal(char *name, char *description, int portions, int set_nutrion_manually);

int set_meal_nutri_info(meal *meal_ptr, nutri_info *info);
int set_meal_extra_nutri_info(meal *meal_ptr, extra_nutri_info *info);
int set_meal_vitamin_info(meal *meal_ptr, vitamin_info *info);

int add_meal_ingredient(ingredient ingred, int portion);
int remove_meal_ingreient(ingredient ingred);
int set_portion_meal_ingredient(char *name, int portion);

nutri_info get_meal_portion_nutri_info(meal *meal_ptr);
extra_nutri_info get_meal_portion_extra_nutri_info(meal *meal_ptr);
vitamin_info get_meal_portion_vitamin_info(meal *meal_ptr);

int destory_meal(meal *meal_ptr);


#endif
