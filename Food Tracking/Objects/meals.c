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
}

int set_meal_nutri_info(meal *meal_ptr, nutri_info *info) {
    if(!meal_ptr || !info) return 0;
    if(!meal_ptr->set_nutrion_manually) return 0;

    if(meal_ptr->nutrition) update_nutri_info(meal_ptr->nutrition, info);
    else meal_ptr->nutrition = copy_nutri_info(info);

    return meal_ptr->nutrition  != NULL;
}
int set_meal_extra_nutri_info(meal *meal_ptr, extra_nutri_info *info) {
    if(!meal_ptr || !info) return 0;
    if(!meal_ptr->set_nutrion_manually) return 0;

    if(meal_ptr->extra_nutrition) update_extra_nutri_info(meal_ptr->extra_nutrition, info);
    else meal_ptr->extra_nutrition = copy_extra_nutri_info(info);

    return meal_ptr->extra_nutrition != NULL;
}
int set_meal_vitamin_info(meal *meal_ptr, vitamin_info *info) {
    if(!meal_ptr || !info) return 0;
    if(meal_ptr->set_nutrion_manually) return 0;

    if(meal_ptr->viatmins) update_extra_nutri_info(meal_ptr->viatmins, info);
    else meal_ptr->viatmins = copy_vitamin_info(info);

    return meal_ptr->viatmins != NULL;
}

int add_meal_ingredient(ingredient ingred, int portion);
int remove_meal_ingreient(ingredient ingred);
int set_portion_meal_ingredient(char *name, int portion);

nutri_info get_meal_portion_nutri_info(meal *meal_ptr);
extra_nutri_info get_meal_portion_extra_nutri_info(meal *meal_ptr);
vitamin_info get_meal_portion_vitamin_info(meal *meal_ptr);

int destory_meal(meal *meal_ptr);