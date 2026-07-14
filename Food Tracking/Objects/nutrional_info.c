#include <stdlib.h>;
#include "nutritional_info.h";

typedef struct {
    float calories;
    float protein;
    float carbs;
    float fat;
} nutri_info;

/**
 * Creates a nutritional info object with the given information
 * 
 * Returns a pofloater to the new object or NULL if the object couldn't be created
 */
nutri_info *create_nutri_info(float cal, float protein, float carbs, float fat) {
    nutri_info *info = malloc(sizeof(nutri_info));
    if(!info) return NULL;
    
    info->calories = cal;
    info->protein = protein;
    info->carbs = carbs;
    info->fat = fat;
    return info;
}

/**
 * Creates a duplicate copy of the given nutritional information.
 * 
 * Returns a pofloater to the new object or NULL if the object couldn't be created
 */
nutri_info *duplicate_nutri_info(nutri_info *info) {
    nutri_info *new_info = malloc(sizeof(nutri_info));
    if(!new_info) return NULL;

    new_info->calories = info->calories;
    new_info->protein = info->protein;
    new_info->carbs = info->carbs;
    new_info->fat = info->fat;
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

void set_cal(nutri_info *info, float cal) {
    if(info) info->calories = (cal < 0) ? -1 : cal;
}
void set_protein(nutri_info *info, float protein) {
    if(info) info->protein = (protein < 0) ? -1 : protein;
}
void set_carbs(nutri_info *info, float carbs) {
    if(info) info->carbs = (carbs < 0) ? -1 : carbs;
}
void set_fat(nutri_info *info, float fat) {
    if(info) info->fat = (fat < 0) ? -1 : fat;
}



/**
 * Destroys the nutritional information object and frees the associated memory
 */
void destroy_nutri_info(nutri_info *info) {
    free(info);
    return;
}

