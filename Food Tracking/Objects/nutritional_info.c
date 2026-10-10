#include <stdlib.h>
#include "nutritional_info.h"

struct nutri_info {
    float calories;
    float protein;
    float carbs;
    float fat;
};

/**
 * Creates a nutritional info object with the given information
 * 
 * Returns a pofloater to the new object or NULL if the object couldn't be created
 */
nutri_info *create_nutri_info(float cal, float protein, float carbs, float fat) {
    nutri_info *info = malloc(sizeof(nutri_info));
    if(!info) return NULL;
    
    info->calories = (cal < 0)      ? -1.0 : cal;
    info->protein  = (protein < 0)  ? -1.0 : protein;
    info->carbs    = (carbs < 0)    ? -1.0 : carbs;
    info->fat      = (fat < 0)      ? -1.0 : fat;
    return info;
}

/**
 * Creates a duplicate copy of the given nutritional information.
 * 
 * Returns a pofloater to the new object or NULL if the object couldn't be created
 */
nutri_info *duplicate_nutri_info(nutri_info *info) {
    if(!info) return NULL;

    nutri_info *new_info = malloc(sizeof(nutri_info));
    if(!new_info) return NULL;

    new_info->calories = info->calories;
    new_info->protein  = info->protein;
    new_info->carbs    = info->carbs;
    new_info->fat      = info->fat;
    return new_info;
}

/**
 * Copies nutriontion information from a source object to a destination object
 * 
 * Returns 1 if the information was sucessfully copied otherwise returns 0
 */
int copy_nutri_info(nutri_info *dst, nutri_info *src) {
    if(!dst || !src) return 0;

    dst->calories = src->calories;
    dst->protein = src->protein;
    dst->carbs = src->carbs;
    dst->fat = src->fat;
    return 1;
}

// Getter and Setter Methods
float get_cal(nutri_info *info) { return info ? info->calories : -1.0; }
float get_protein(nutri_info *info) { return info ? info->protein : -1.0; }
float get_carbs(nutri_info *info) { return info ? info->carbs : -1.0; }
float get_fat(nutri_info *info) { return info ? info->fat : -1.0; }

void set_cal(nutri_info *info, float val) { if(info) info->calories = (val < 0) ? -1 : val; }
void set_protein(nutri_info *info, float val) { if(info) info->protein = (val < 0) ? -1 : val; }
void set_carbs(nutri_info *info, float val) { if(info) info->carbs = (val < 0) ? -1 : val; }
void set_fat(nutri_info *info, float val) { if(info) info->fat = (val < 0) ? -1 : val; }



/**
 * Destroys the nutritional information object and frees the associated memory
 */
void destroy_nutri_info(nutri_info *info) {
    if(!info) return;
    
    free(info);
    return;
}

