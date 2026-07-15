#include <stdlib.h>
#include "ingredients.h"
#include "nutritional_info.h";
#include "extra_nutritional_info.h";
#include "vitamins.h";
#include "meals.h";

/**
 * A structure for holding information about a user created meal.
 * 
 * All values are in grams unless otherwise noted
 */
typedef struct {
    char *name;
    char *description;
    int  portions;

    int num_ingredients;
    int max_ingredients;
    ingredient_list ingredients;
    
    int man_set_nutri;
    nutri_info *nutrition;
    extra_nutri_info *extra_nutrition;
    vitamin_info *viatmins;
} meal;


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

    // Safely copy the name and description into the new object
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
    meal_ptr->man_set_nutri = set_nutrion_manually;

    meal_ptr->ingredient_list = create_ingred_list();
    return meal_ptr;
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

    if(!add_ingred_list_item(meal_ptr->ingredients, ingred, portion)) return 0;

    if(!meal_ptr->man_set_nutri) {
        if(get_ingred_cal)
    }
    
}
int remove_meal_ingreient(meal *meal_ptr, ingredient *ingred);
int set_portion_meal_ingredient(meal *meal_ptr, char *name, int portion);


nutri_info get_meal_nutri_info(meal *meal_ptr);
extra_nutri_info get_meal_extra_nutri_info(meal *meal_ptr);
vitamin_info get_meal_vitamin_info(meal *meal_ptr);
nutri_info get_meal_portion_nutri_info(meal *meal_ptr);
extra_nutri_info get_meal_portion_extra_nutri_info(meal *meal_ptr);
vitamin_info get_meal_portion_vitamin_info(meal *meal_ptr);

float get_meal_calories(meal *meal_ptr) {
    (meal_ptr && meal_ptr->set_nutrition_manually) ? get_cal(meal_ptr->nutrition) : -1.0;
}
float get_meal_portion_calories(meal *meal_ptr) {
    (meal_ptr && meal_ptr->set_nutrion_manually) ? get_cal(meal_ptr->nutrition)/meal_ptr-> : -1.0;
}
float get_meal_protein(meal *meal_ptr);
float get_meal_portion_protein(meal *meal_ptr);
float get_meal_carbs(meal *meal_ptr);
float get_meal_portion_carbs(meal *meal_ptr);
float get_meal_fat(meal *meal_ptr);
float get_meal_portion_fat(meal *meal_ptr);
float get_meal_sat_fat(meal *meal_ptr);
float get_meal_portion_sat_fat(meal *meal_ptr);
float get_meal_trans_fat(meal *meal_ptr);
float get_meal_portion_trans_fat(meal *meal_ptr);
float get_meal_cholesterol(meal *meal_ptr);
float get_meal_portion_cholesterol(meal *meal_ptr);
float get_meal_sodium(meal *meal_ptr);
float get_meal_portion_sodium(meal *meal_ptr);
float get_meal_fiber(meal *meal_ptr);
float get_meal_portion_fiber(meal *meal_ptr);
float get_meal_sugar(meal *meal_ptr);
float get_meal_portion_sugar(meal *meal_ptr);
float get_meal_vitamin_d(meal *meal_ptr);
float get_meal_portion_vitamin_d(meal *meal_ptr);
float get_meal_calcium(meal *meal_ptr);
float get_meal_portion_calcium(meal *meal_ptr);
float get_meal_iron(meal *meal_ptr);
float get_meal_portion_iron(meal *meal_ptr);
float get_meal_potassium(meal *meal_ptr);
float get_meal_portion_potassium(meal *meal_ptr);

void set_meal_calories(meal *meal_ptr, float cal);
void set_meal_portion_calories(meal *meal_ptr, float cal);
void set_meal_protein(meal *meal_ptr, float protein);
void set_meal_portion_protein(meal *meal_ptr, float protein);
void set_meal_carbs(meal *meal_ptr, float carbs);
void set_meal_portion_carbs(meal *meal_ptr, float carbs);
void set_meal_fat(meal *meal_ptr, float fat);
void set_meal_portion_fat(meal *meal_ptr, float fat);
void set_meal_sat_fat(meal *meal_ptr, float sat_fat);
void set_meal_portion_sat_fat(meal *meal_ptr, float sat_fat);
void set_meal_trans_fat(meal *meal_ptr, float trans_fat);
void set_meal_portion_trans_fat(meal *meal_ptr, float trans_fat);
void set_meal_cholesterol(meal *meal_ptr, float cholesterol);
void set_meal_portion_cholesterol(meal *meal_ptr, float cholesterol);
void set_meal_sodium(meal *meal_ptr, float sodium);
void set_meal_portion_sodium(meal *meal_ptr, float sodium);
void set_meal_fiber(meal *meal_ptr, float fiber);
void set_meal_portion_fiber(meal *meal_ptr, float fiber);
void set_meal_sugar(meal *meal_ptr, float sugar);
void set_meal_portion_sugar(meal *meal_ptr, float sugar);
void set_meal_vitamin_d(meal *meal_ptr, float vit_d);
void set_meal_portion_vitamin_d(meal *meal_ptr, float vit_d);
void set_meal_calcium(meal *meal_ptr, float calcium);
void set_meal_portion_calcium(meal *meal_ptr, float calcium);
void set_meal_iron(meal *meal_ptr, float iron);
void set_meal_portion_iron(meal *meal_ptr, float iron);
void set_meal_potassium(meal *meal_ptr, float potassium);
void set_meal_portion_potassium(meal *meal_ptr, float potassium);

int destory_meal(meal *meal_ptr);