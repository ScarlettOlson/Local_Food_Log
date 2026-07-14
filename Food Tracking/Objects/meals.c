#include <stdlib.h>
#include "ingredients.h"
#include "nutritional_info.h";
#include "extra_nutritional_info.h";
#include "vitamins.h";
#include "meals.h";

/**
 * Create a new meal object
 * 
 * set_nutrition_manually: A flag that when set allows nutritional values to be
 *      manually set instead of based on the ingredients
 */
meal *create_meal(char *name, char *description, int portions, int set_nutrion_manually) {
    if(!name || !description) return NULL;
    meal *meal_ptr = malloc(sizeof(meal));
    if(!meal_ptr) return NULL;

    meal_ptr->name = malloc((strlen(name)+1) * sizeof(char));
    if(!meal_ptr->name) return NULL;
    strcpy(meal_ptr->name, name);
    meal_ptr->description = malloc((strlen(description)+1) * sizeof(char));
    if(!meal_ptr->description) {
        free(meal_ptr->name);
        return NULL;
    }
    strcpy(meal_ptr->description, description);

    meal_ptr->portions = portions;
    meal_ptr->set_nutrion_manually = set_nutrion_manually;

    meal_ptr->num_ingredients = 0;
    meal_ptr->max_ingredients = 20;
    meal_ptr->ingred_portions
}

/**
 * Sets the nutrional information of the meal if it can be manually set. The info
 *      is copied and the orginal object is unchanged.
 * 
 * Returns non-zero if the information was succesfully set.
 */
int set_meal_nutri_info(meal *meal_ptr, nutri_info *info) {
    if(!meal_ptr || !info) return 0;
    if(!meal_ptr->set_nutrion_manually) return 0;

    if(meal_ptr->nutrition) update_nutri_info(meal_ptr->nutrition, info);
    else meal_ptr->nutrition = copy_nutri_info(info);

    return meal_ptr->nutrition  != NULL;
}
/**
 * Sets the extra nutrional information of the meal if it can be manually set.
 *      The info is copied and the orginal object is unchanged.
 * 
 * Returns non-zero if the information was succesfully set.
 */
int set_meal_extra_nutri_info(meal *meal_ptr, extra_nutri_info *info) {
    if(!meal_ptr || !info) return 0;
    if(!meal_ptr->set_nutrion_manually) return 0;

    if(meal_ptr->extra_nutrition) update_extra_nutri_info(meal_ptr->extra_nutrition, info);
    else meal_ptr->extra_nutrition = copy_extra_nutri_info(info);

    return meal_ptr->extra_nutrition != NULL;
}
/**
 * Sets the vitamin information of the meal if it can be manually set.
 *      The info is copied and the orginal object is unchanged.
 * 
 * Returns non-zero if the information was succesfully set.
 */
int set_meal_vitamin_info(meal *meal_ptr, vitamin_info *info) {
    if(!meal_ptr || !info) return 0;
    if(meal_ptr->set_nutrion_manually) return 0;

    if(meal_ptr->viatmins) update_extra_nutri_info(meal_ptr->viatmins, info);
    else meal_ptr->viatmins = copy_vitamin_info(info);

    return meal_ptr->viatmins != NULL;
}

/**
 * Adds an ingredient to the given meal as long as it's not already apart of the meal.
 *      The nutritional information is also updated if it's not manually set.
 *      The ingredient is copied and the orginal object is unchanged.
 * 
 * Returns:
 *      0 if adding the ingredient failed.
 *      1 if the ingredient was added and the nutritional info was updated.
 *      2 if the ingredient was added and the nutritional info was not updated.
 */
int add_meal_ingredient(meal *meal_ptr, ingredient *ingred, int portion) {
    if(!meal_ptr || !ingred) return 0;

    for(int i=0; i<meal_ptr->num_ingredients; i++) {
        *ingredient tmp = meal_ptr->ingred_list[i];
        if(strcmp(tmp->name, ingred->name)) return 0;
    }

    // Allocate more memory for 
}
int remove_meal_ingreient(meal *meal_ptr, ingredient *ingred);
int set_portion_meal_ingredient(meal *meal_ptr, char *name, int portion);

nutri_info get_meal_portion_nutri_info(meal *meal_ptr);
extra_nutri_info get_meal_portion_extra_nutri_info(meal *meal_ptr);
vitamin_info get_meal_portion_vitamin_info(meal *meal_ptr);

int destory_meal(meal *meal_ptr);