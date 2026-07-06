#include <stdlib.h>
#include "ingredients.h"
#include "nutritional_info.h";
#include "extra_nutritional_info.h";
#include "vitamins.h";
#include "meals.h";

meal *create_meal(char *name, char *description, int portions, int set_nutrion_manually) {
    if(!name || !description) return NULL;

    meal *meal_ptr = malloc(sizeof(meal));
    if(!meal_ptr) return NULL;

    // Create a copy of the info and description
    meal_ptr->name = malloc((strlen(name)+1) * sizeof(char));
    if(!meal_ptr->name) return 
    strcpy(meal_ptr->name, name);
    meal_ptr->description = malloc((strlen(description)+1) * sizeof(char));
    strcpy(meal_ptr->description, description);

    meal_ptr->portions = portions;
    meal_ptr->set_nutrion_manually = set_nutrion_manually;
}

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