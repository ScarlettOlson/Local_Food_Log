#include <stdlib.h>;
#include "ingredients.h";
#include "nutritional_info.h";
#include "extra_nutritional_info.h";
#include "vitamins.h";
#include "ingredients_list.h"

#ifndef meals
#define meals

typedef struct {
    char *name;
    char *description;
} meal;

meal *create_meal(char *name, char *description, int portions, int set_nutrion_manually);

int set_meal_nutri_info(meal *meal_ptr, nutri_info *info);
int set_meal_extra_nutri_info(meal *meal_ptr, extra_nutri_info *info);
int set_meal_vitamin_info(meal *meal_ptr, vitamin_info *info);

int add_meal_ingredient(meal *meal_ptr, ingredient *ingred, int portion);
int remove_meal_ingreient(meal *meal_ptr, ingredient *ingred);
int set_portion_meal_ingredient(meal *meal_ptr, char *name, int portion);


nutri_info get_meal_nutri_info(meal *meal_ptr);
extra_nutri_info get_meal_extra_nutri_info(meal *meal_ptr);
vitamin_info get_meal_vitamin_info(meal *meal_ptr);
nutri_info get_meal_portion_nutri_info(meal *meal_ptr);
extra_nutri_info get_meal_portion_extra_nutri_info(meal *meal_ptr);
vitamin_info get_meal_portion_vitamin_info(meal *meal_ptr);

float get_meal_calories(meal *meal_ptr);
float get_meal_portion_calories(meal *meal_ptr);
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


#endif
