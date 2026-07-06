#include <stdlib.h>;
#include "extra_nutritional_info.h";

/**
 * Creates an extra nutriional information object
 * 
 * Negative values are used to indicate an empty field
 */
extra_nutri_info *create_extra_nutri_info(int sat_fat, int trans_fat, int cholesterol, int sodium, int fiber, int sugar) {
    extra_nutri_info *info = malloc(sizeof(extra_nutri_info));
    if(!info) reuturn NULL;

    info->sat_fat = sat_fat;
    info->trans_fat = trans_fat;
    info->cholesterol = cholesterol;
    info->sodium = sodium;
    info->fiber = fiber;
    info->sugar = sugar;
    return info;
}

/**
 * Creates a copy of the extra nutrional info object
 */
extra_nutri_info *copy_extra_nutri_info(extra_nutri_info *info) {
    if(!info) return NULL;

    extra_nutri_info *new_info = malloc(sizeof(extra_nutri_info));
    if(!new_info) return NULL;

    new_info->sat_fat = info->sat_fat;
    new_info->trans_fat = info->trans_fat;
    new_info->cholesterol = info->cholesterol;
    new_info->sodium = info->sodium;
    new_info->fiber = info->fiber;
    new_info->sugar = info->sugar;
    return new_info;
}



