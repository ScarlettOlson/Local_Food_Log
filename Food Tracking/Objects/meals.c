#include <stdlib.h>
#include "ingredients.h"
#include "ingredients_list.h";
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

    ingred_list *ingreds;
    
    int set_nutri_man;
    nutri_info *nutri;
    extra_nutri_info *e_nutri;
    vitamin_info *vit;
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
    meal_ptr->set_nutri_man = set_nutrion_manually;

    meal_ptr->ingreds = create_ingred_list();
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

    if(meal_ptr->nutri) update_nutri_info(meal_ptr->nutri, info);
    else meal_ptr->nutri = copy_nutri_info(info);

    return meal_ptr->nutri  != NULL;
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

    if(meal_ptr->e_nutri) update_extra_nutri_info(meal_ptr->e_nutri, info);
    else meal_ptr->e_nutri = copy_extra_nutri_info(info);

    return meal_ptr->e_nutri != NULL;
}
/**
 * Sets the vit information of the meal if it can be manually set.
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
 */
int add_meal_ingredient(meal *meal_ptr, ingredient *ingred, float portion) {
    if(!meal_ptr || !ingred) return 0;

    if(!add_ingred_list_item(meal_ptr->ingreds, ingred, portion)) return 0;

    // Update Nutritional Information
    if(!meal_ptr->set_nutri_man) {
        float old_cal = get_meal_calories(meal_ptr);
        float old_protein = get_meal_protein(meal_ptr);
        float old_carbs = get_meal_carbs(meal_ptr);
        float old_fat = get_meal_fat(meal_ptr);
        float old_sat_fat = get_meal_sat_fat(meal_ptr);
        float old_trans_fat = get_meal_trans_fat(meal_ptr);
        float old_cholesterol = get_meal_cholesterol(meal_ptr);
        float old_sodium = get_meal_sodium(meal_ptr);
        float old_fiber = get_meal_fiber(meal_ptr);
        float old_sugar = get_meal_sugar(meal_ptr);
        float old_vitamin_d = get_meal_vitamin_d(meal_ptr);
        float old_calcium = get_meal_calcium(meal_ptr);
        float old_iron = get_meal_iron(meal_ptr);
        float old_potassium = get_meal_potassium(meal_ptr);

        float ingred_cal =  get_ingred_calories(ingred) * portion;
        float ingred_protein = get_ingred_protein(ingred) * portion;
        float ingred_carbs = get_ingred_carbs(ingred) * portion;
        float ingred_fat = get_ingred_fat(ingred) * portion;
        float ingred_sat_fat = get_ingred_sat_fat(ingred) * portion;
        float ingred_trans_fat = get_ingred_trans_fat(ingred) * portion;
        float ingred_cholesterol = get_ingred_cholesterol(ingred) * portion;
        float ingred_sodium = get_ingred_sodium(ingred) * portion;
        float ingred_fiber = get_ingred_fiber(ingred) * portion;
        float ingred_sugar = get_ingred_sugar(ingred) * portion;
        float ingred_vitamin_d = get_ingred_vitamin_d(ingred) * portion;
        float ingred_calcium = get_ingred_calcium(ingred) * portion;
        float ingred_iron = get_ingred_iron(ingred) * portion;
        float ingred_potassium = get_ingred_potassium(ingred) * portion;
        
        if (ingred_cal >= 0) set_meal_calories(meal_ptr, ingred_cal + old_cal);
        if (ingred_protein >= 0) set_meal_protein(meal_ptr, ingred_protein + old_protein);
        if (ingred_carbs >= 0) set_meal_carbs(meal_ptr, ingred_carbs + old_carbs);
        if (ingred_fat >= 0) set_meal_fat(meal_ptr, ingred_fat + old_fat);
        if (ingred_sat_fat >= 0) set_meal_sat_fat(meal_ptr, ingred_sat_fat + old_sat_fat);
        if (ingred_trans_fat >= 0) set_meal_trans_fat(meal_ptr, ingred_trans_fat + old_trans_fat);
        if (ingred_cholesterol >= 0) set_meal_cholesterol(meal_ptr, ingred_cholesterol + old_cholesterol);
        if (ingred_sodium >= 0) set_meal_sodium(meal_ptr, ingred_sugar + old_sugar);
        if (ingred_fiber >= 0) set_meal_fiber(meal_ptr, ingred_fiber + old_fiber);
        if (ingred_sugar >= 0) set_meal_sugar(meal_ptr, ingred_sugar + old_sugar);
        if (ingred_vitamin_d >= 0) set_meal_vitamin_d(meal_ptr, ingred_vitamin_d + old_vitamin_d);
        if (ingred_calcium >= 0) set_meal_calcium(meal_ptr, ingred_calcium + old_calcium);
        if (ingred_iron >= 0) set_meal_iron(meal_ptr, ingred_iron + old_iron);
        if (ingred_potassium >= 0) set_meal_potassium(meal_ptr, ingred_potassium + old_potassium);
    }
    return 1;
}
/**
 * Removes an ingredient from the given meal and updates the nutritional information
 * 
 * Returns a pointer to the removed ingredient, or NULL if the ingredient couldn't be removed
 */
ingredient *remove_meal_ingreient(meal *meal_ptr, char *name) {
    if(!meal_ptr) return NULL;

    ingred_return *tmp = remove_ingred_list_item(meal_ptr->ingreds, name);
    if(!tmp) return NULL;
    ingredient *ingred = tmp->ingred;
    float portion = tmp->portion;

    // Update Nutritional Information
    if(!meal_ptr->set_nutri_man) {
        float old_cal =         get_meal_calories(meal_ptr);
        float old_protein =     get_meal_protein(meal_ptr);
        float old_carbs =       get_meal_carbs(meal_ptr);
        float old_fat =         get_meal_fat(meal_ptr);
        float old_sat_fat =     get_meal_sat_fat(meal_ptr);
        float old_trans_fat =   get_meal_trans_fat(meal_ptr);
        float old_cholesterol = get_meal_cholesterol(meal_ptr);
        float old_sodium =      get_meal_sodium(meal_ptr);
        float old_fiber =       get_meal_fiber(meal_ptr);
        float old_sugar =       get_meal_sugar(meal_ptr);
        float old_vitamin_d =   get_meal_vitamin_d(meal_ptr);
        float old_calcium =     get_meal_calcium(meal_ptr);
        float old_iron =        get_meal_iron(meal_ptr);
        float old_potassium =   get_meal_potassium(meal_ptr);

        float ingred_cal         = get_ingred_calories(ingred)    * portion;
        float ingred_protein     = get_ingred_protein(ingred)     * portion;
        float ingred_carbs       = get_ingred_carbs(ingred)       * portion;
        float ingred_fat         = get_ingred_fat(ingred)         * portion;
        float ingred_sat_fat     = get_ingred_sat_fat(ingred)     * portion;
        float ingred_trans_fat   = get_ingred_trans_fat(ingred)   * portion;
        float ingred_cholesterol = get_ingred_cholesterol(ingred) * portion;
        float ingred_sodium      = get_ingred_sodium(ingred)      * portion;
        float ingred_fiber       = get_ingred_fiber(ingred)       * portion;
        float ingred_sugar       = get_ingred_sugar(ingred)       * portion;
        float ingred_vitamin_d   = get_ingred_vitamin_d(ingred)   * portion;
        float ingred_calcium     = get_ingred_calcium(ingred)     * portion;
        float ingred_iron        = get_ingred_iron(ingred)        * portion;
        float ingred_potassium   = get_ingred_potassium(ingred)   * portion;
        
        if(ingred_cal >= 0)         { set_meal_calories(meal_ptr, (old_cal - ingred_cal)); }
        if(ingred_protein >= 0)     { set_meal_protein(meal_ptr, (old_protein - ingred_protein)); }
        if(ingred_carbs >= 0)       { set_meal_carbs(meal_ptr, (old_carbs - ingred_carbs)); }
        if(ingred_fat >= 0)         { set_meal_fat(meal_ptr, (old_fat - ingred_fat)); }
        if(ingred_sat_fat >= 0)     { set_meal_sat_fat(meal_ptr, (old_sat_fat - ingred_sat_fat)); }
        if(ingred_trans_fat >= 0)   { set_meal_trans_fat(meal_ptr, (old_trans_fat - ingred_trans_fat)); }
        if(ingred_cholesterol >= 0) { set_meal_cholesterol(meal_ptr, (old_cholesterol - ingred_cholesterol)); }
        if(ingred_sodium >= 0)      { set_meal_sodium(meal_ptr, (old_sugar - ingred_sodium)); }
        if(ingred_fiber >= 0)       { set_meal_fiber(meal_ptr, (old_fiber - ingred_fiber)); }
        if(ingred_sugar >= 0)       { set_meal_sugar(meal_ptr, (old_sugar - ingred_sugar)); }
        if(ingred_vitamin_d >= 0)   { set_meal_vitamin_d(meal_ptr, (old_vitamin_d - ingred_vitamin_d)); }
        if(ingred_calcium >= 0)     { set_meal_calcium(meal_ptr, (old_calcium - ingred_calcium)); }
        if(ingred_iron >= 0)        { set_meal_iron(meal_ptr, (old_iron - ingred_iron)); }
        if(ingred_potassium >= 0)   { set_meal_potassium(meal_ptr, (old_potassium - ingred_potassium)); }
    }
    return ingred;
}
/**
 * Changes the portion of a given ingredient used in the meal
 * 
 * Returns a pointer the changed ingredient or NULL if the ingredient could not be updated
 */
ingredient *set_portion_meal_ingredient(meal *meal_ptr, char *name, int portion) {
    if(!meal_ptr) return NULL;

    update_ingred_list_item_portion(meal_ptr->ingreds, name, portion)
}


/**
 * Gets the nutrional information related to the meal
 * 
 * Returns a copy of the nutrional information for the meal
 */
nutri_info *get_meal_nutri_info(meal *meal_ptr) {
    return meal_ptr ? duplicate_nutri_info(meal_ptr->nutri) : NULL;
}
/**
 * Gets the extra nutrional information related to the meal
 * 
 * Returns a copy of the extra nutrional information for the meal
 */
extra_nutri_info *get_meal_extra_nutri_info(meal *meal_ptr) {
    return meal_ptr ? duplicate_extra_nutri_info(meal_ptr->e_nutri) : NULL;
}
/**
 * Gets the vitamin information related to the meal
 * 
 * Returns a copy of the vitamin information for the meal
 */
vitamin_info *get_meal_vitamin_info(meal *meal_ptr) {
    return meal_ptr ? duplicate_vitamin_info(meal_ptr->vit) : NULL;
}
/**
 * Gets the nutrional information for a single portion of the meal
 * 
 * Returns the nutrional information for a single portion of the meal
 */
nutri_info *get_meal_portion_nutri_info(meal *meal_ptr) {
    if(!meal_ptr) return NULL;

    nutri_info *info = meal_ptr->nutri;
    if(!info) return NULL;

    float portions = meal_ptr->portions;
    float cal      = get_cal(info)     / portions;
    float protein  = get_protein(info) / portions;
    float carbs    = get_carbs(info)   / portions;
    float fat      = get_fat(info)     / portions;

    nutri_info *info_by_port = create_nutri_info(cal, protein, carbs, fat);
    return info_by_port;
}
/**
 * Gets the extra nutrional information for a single portion of the meal
 * 
 * Returns the extra nutrional information for a single portion of the meal
 */
extra_nutri_info *get_meal_portion_extra_nutri_info(meal *meal_ptr) {
    if(!meal_ptr) return NULL;

    extra_nutri_info *info = meal_ptr->e_nutri;
    if(!info) return NULL;

    float portions    = meal_ptr->portions;
    float sat_fat     = get_sat_fat(info)     / portions;
    float trans_fat   = get_trans_fat(info)   / portions;
    float cholesterol = get_cholesterol(info) / portions;
    float sodium      = get_sodium(info)      / portions;
    float fiber       = get_fiber(info)       / portions;
    float sugar       = get_sugar(info)       / portions;

    nutri_info *info_by_port = create_extra_nutri_info(sat_fat, trans_fat, cholesterol, sodium, fiber, sugar);
    return info_by_port;
}
/**
 * Gets the vitamin information for a single portion of the meal
 * 
 * Returns the vitamin information for a single portion of the meal
 */
vitamin_info *get_meal_portion_vitamin_info(meal *meal_ptr) {
    if(!meal_ptr) return NULL;

    vitamin_info *info = meal_ptr->vit;
    if(!info) return NULL;

    float portions  = meal_ptr->portions;
    float vitamin_d = get_viatmin_d(info) / portions;
    float calcium   = get_calcium(info)   / portions;
    float iron      = get_iron(info)      / portions;
    float potassium = get_potassium(info) / portions;

    nutri_info *info_by_port = create_extra_nutri_info(vitamin_d, calcium, iron, potassium);
    return info_by_port;
}


// Getters and Setters
float get_meal_calories(meal *meal_ptr) {
    return meal_ptr ? get_cal(meal_ptr->nutri) : -1.0;
}
float get_meal_portion_calories(meal *meal_ptr) {
    return meal_ptr ? get_cal(meal_ptr->nutri) / meal_ptr->portions : -1.0;
}
float get_meal_protein(meal *meal_ptr) {
    return meal_ptr ? get_protein(meal_ptr->nutri) : -1.0;
}
float get_meal_portion_protein(meal *meal_ptr) {
    return meal_ptr ? get_protein(meal_ptr->nutri) / meal_ptr->portions : -1.0;
}
float get_meal_carbs(meal *meal_ptr) {
    return meal_ptr ? get_carbs(meal_ptr->nutri) : -1.0;
}
float get_meal_portion_carbs(meal *meal_ptr) {
    return meal_ptr ? get_carbs(meal_ptr->nutri) / meal_ptr->portions : -1.0;
}
float get_meal_fat(meal *meal_ptr) {
    return meal_ptr ? get_fat(meal_ptr->nutri) : -1.0;
}
float get_meal_portion_fat(meal *meal_ptr) {
    return meal_ptr ? get_fat(meal_ptr->nutri) / meal_ptr->portions : -1.0;
}
float get_meal_sat_fat(meal *meal_ptr) {
    return meal_ptr ? get_sat_fat(meal_ptr->e_nutri) : -1.0;
}
float get_meal_portion_sat_fat(meal *meal_ptr) {
    return meal_ptr ? get_sat_fat(meal_ptr->e_nutri) / meal_ptr->portions : -1.0;
}
float get_meal_trans_fat(meal *meal_ptr) {
    return meal_ptr ? get_trans_fat(meal_ptr->e_nutri) : -1.0;
}
float get_meal_portion_trans_fat(meal *meal_ptr) {
    return meal_ptr ? get_trans_fat(meal_ptr->e_nutri) / meal_ptr->portions : -1.0;
}
float get_meal_cholesterol(meal *meal_ptr) {
    return meal_ptr ? get_cholesterol(meal_ptr->e_nutri) : -1.0;
}
float get_meal_portion_cholesterol(meal *meal_ptr) {
    return meal_ptr ? get_cholesterol(meal_ptr->e_nutri) / meal_ptr->portions : -1.0;
}
float get_meal_sodium(meal *meal_ptr) {
    return meal_ptr ? get_sodium(meal_ptr->e_nutri) : -1.0;
}
float get_meal_portion_sodium(meal *meal_ptr) {
    return meal_ptr ? get_sodium(meal_ptr->e_nutri) / meal_ptr->portions : -1.0;
}
float get_meal_fiber(meal *meal_ptr) {
    return meal_ptr ? get_fiber(meal_ptr->e_nutri) : -1.0;
}
float get_meal_portion_fiber(meal *meal_ptr) {
    return meal_ptr ? get_fiber(meal_ptr->e_nutri) / meal_ptr->portions : -1.0;
}
float get_meal_sugar(meal *meal_ptr) {
    return meal_ptr ? get_sugar(meal_ptr->e_nutri) : -1.0;
}
float get_meal_portion_sugar(meal *meal_ptr) {
    return meal_ptr ? get_sugar(meal_ptr->e_nutri) / meal_ptr->portions : -1.0;
}
float get_meal_vitamin_d(meal *meal_ptr) {
    return meal_ptr ? get_vitamin_d(meal_ptr->vit) : -1.0;
}
float get_meal_portion_vitamin_d(meal *meal_ptr) {
    return meal_ptr ? get_vitamin_d(meal_ptr->vit) / meal_ptr->portions : -1.0;
}
float get_meal_calcium(meal *meal_ptr) {
    return meal_ptr ? get_calcium(meal_ptr->vit) : -1.0;
}
float get_meal_portion_calcium(meal *meal_ptr) {
    return meal_ptr ? get_calcium(meal_ptr->vit) / meal_ptr->portions : -1.0;
}
float get_meal_iron(meal *meal_ptr) {
    return meal_ptr ? get_iron(meal_ptr->vit) : -1.0;
}
float get_meal_portion_iron(meal *meal_ptr) {
    return meal_ptr ? get_iron(meal_ptr->vit) / meal_ptr->portions : -1.0;
}
float get_meal_potassium(meal *meal_ptr) {
    return meal_ptr ? get_potassium(meal_ptr->vit) : -1.0;
}
float get_meal_portion_potassium(meal *meal_ptr) {
    return meal_ptr ? get_potassium(meal_ptr->vit) / meal_ptr->portions : -1.0;
}


void set_meal_calories(meal *meal_ptr, float cal) {
    if (meal_ptr && meal_ptr->set_nutri_man) {
        set_cal(meal_ptr->nutri, cal);
    }
}
void set_meal_portion_calories(meal *meal_ptr, float cal) {
    if (meal_ptr && meal_ptr->set_nutri_man) {
        set_cal(meal_ptr->nutri, cal * meal_ptr->portions);
    }
}
void set_meal_protein(meal *meal_ptr, float protein) {
    if (meal_ptr && meal_ptr->set_nutri_man) {
        set_protein(meal_ptr->nutri, protein);
    }
}
void set_meal_portion_protein(meal *meal_ptr, float protein) {
    if (meal_ptr && meal_ptr->set_nutri_man) {
        set_protein(meal_ptr->nutri, protein * meal_ptr->portions);
    }
}
void set_meal_carbs(meal *meal_ptr, float carbs) {
    if (meal_ptr && meal_ptr->set_nutri_man) {
        set_carbs(meal_ptr->nutri, carbs);
    }
}
void set_meal_portion_carbs(meal *meal_ptr, float carbs) {
    if (meal_ptr && meal_ptr->set_nutri_man) {
        set_carbs(meal_ptr->nutri, carbs * meal_ptr->portions);
    }
}
void set_meal_fat(meal *meal_ptr, float fat) {
    if (meal_ptr && meal_ptr->set_nutri_man) {
        set_fat(meal_ptr->nutri, fat);
    }
}
void set_meal_portion_fat(meal *meal_ptr, float fat) {
    if (meal_ptr && meal_ptr->set_nutri_man) {
        set_fat(meal_ptr->nutri, fat * meal_ptr->portions);
    }
}
void set_meal_sat_fat(meal *meal_ptr, float sat_fat) {
    if (meal_ptr && meal_ptr->set_nutri_man) {
        set_sat_fat(meal_ptr->e_nutri, sat_fat);
    }
}
void set_meal_portion_sat_fat(meal *meal_ptr, float sat_fat) {
    if (meal_ptr && meal_ptr->set_nutri_man) {
        set_sat_fat(meal_ptr->e_nutri, sat_fat * meal_ptr->portions);
    }
}
void set_meal_trans_fat(meal *meal_ptr, float trans_fat) {
    if (meal_ptr && meal_ptr->set_nutri_man) {
        set_trans_fat(meal_ptr->e_nutri, trans_fat);
    }
}
void set_meal_portion_trans_fat(meal *meal_ptr, float trans_fat) {
    if (meal_ptr && meal_ptr->set_nutri_man) {
        set_trans_fat(meal_ptr->e_nutri, trans_fat * meal_ptr->portions);
    }
}
void set_meal_cholesterol(meal *meal_ptr, float cholesterol) {
    if (meal_ptr && meal_ptr->set_nutri_man) {
        set_cholesterol(meal_ptr->e_nutri, cholesterol);
    }
}
void set_meal_portion_cholesterol(meal *meal_ptr, float cholesterol) {
    if (meal_ptr && meal_ptr->set_nutri_man) {
        set_cholesterol(meal_ptr->e_nutri, cholesterol * meal_ptr->portions);
    }
}
void set_meal_sodium(meal *meal_ptr, float sodium) {
    if (meal_ptr && meal_ptr->set_nutri_man) {
        set_sodium(meal_ptr->e_nutri, sodium);
    }
}
void set_meal_portion_sodium(meal *meal_ptr, float sodium) {
    if (meal_ptr && meal_ptr->set_nutri_man) {
        set_sodium(meal_ptr->e_nutri, sodium * meal_ptr->portions);
    }
}
void set_meal_fiber(meal *meal_ptr, float fiber) {
    if (meal_ptr && meal_ptr->set_nutri_man) {
        set_fiber(meal_ptr->e_nutri, fiber);
    }
}
void set_meal_portion_fiber(meal *meal_ptr, float fiber) {
    if (meal_ptr && meal_ptr->set_nutri_man) {
        set_fiber(meal_ptr->e_nutri, fiber * meal_ptr->portions);
    }
}
void set_meal_sugar(meal *meal_ptr, float sugar) {
    if (meal_ptr && meal_ptr->set_nutri_man) {
        set_sugar(meal_ptr->e_nutri, sugar);
    }
}
void set_meal_portion_sugar(meal *meal_ptr, float sugar) {
    if (meal_ptr && meal_ptr->set_nutri_man) {
        set_sugar(meal_ptr->e_nutri, sugar * meal_ptr->portions);
    }
}
void set_meal_vitamin_d(meal *meal_ptr, float vit_d) {
    if (meal_ptr && meal_ptr->set_nutri_man) {
        set_vitamin_d(meal_ptr->e_nutri, vit_d);
    }
}
void set_meal_portion_vitamin_d(meal *meal_ptr, float vit_d) {
    if (meal_ptr && meal_ptr->set_nutri_man) {
        set_vitamin_d(meal_ptr->vit, vit_d * meal_ptr->portions);
    }
}
void set_meal_calcium(meal *meal_ptr, float calcium) {
    if (meal_ptr && meal_ptr->set_nutri_man) {
        set_calcium(meal_ptr->vit, calcium);
    }
}
void set_meal_portion_calcium(meal *meal_ptr, float calcium) {
    if (meal_ptr && meal_ptr->set_nutri_man) {
        set_calcium(meal_ptr->vit, calcium * meal_ptr->portions);
    }
}
void set_meal_iron(meal *meal_ptr, float iron) {
    if (meal_ptr && meal_ptr->set_nutri_man) {
        set_iron(meal_ptr->vit, iron);
    }
}
void set_meal_portion_iron(meal *meal_ptr, float iron) {
    if (meal_ptr && meal_ptr->set_nutri_man) {
        set_iron(meal_ptr->vit, iron * meal_ptr->portions);
    }
}
void set_meal_potassium(meal *meal_ptr, float potassium) {
    if (meal_ptr && meal_ptr->set_nutri_man) {
        set_potassium(meal_ptr->vit, potassium);
    }
}
void set_meal_portion_potassium(meal *meal_ptr, float potassium) {
    if (meal_ptr && meal_ptr->set_nutri_man) {
        set_potassium(meal_ptr->vit, potassium * meal_ptr->portions);
    }
}



void destory_meal(meal *meal_ptr) {
    if(!meal_ptr) return;

    destory_nutri_info(meal_ptr->nutri);
    destroy_extra_nutri_info(meal_ptr->e_nutri);
    destory_vitamin_info(meal_ptr->vit);
    destroy_ingred_list(meal_ptr->ingreds);

    free(meal_ptr->name);
    free(meal_ptr->description);
}