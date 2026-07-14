#include <stdlib.h>;
#include "extra_nutritional_info.h";

typedef struct {
    float     sat_fat;
    float     trans_fat;
    float     cholesterol; // mg
    float     sodium;      // mg
    float     fiber;
    float     sugar;
} extra_nutri_info;

/**
 * Creates an extra nutriional information object
 * 
 * Negative values are used to indicate an empty field
 */
extra_nutri_info *create_extra_nutri_info(float sat_fat, float trans_fat, float cholesterol, float sodium, float fiber, float sugar) {
    extra_nutri_info *info = malloc(sizeof(extra_nutri_info));
    if(!info) return NULL;

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
extra_nutri_info *duplicate_extra_nutri_info(extra_nutri_info *info) {
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

int copy_extra_nutri_info(extra_nutri_info *dst, extra_nutri_info *src) {
    if(!dst || !src) return 0;

    dst->sat_fat = src->sat_fat;
    dst->trans_fat = src->trans_fat;
    dst->cholesterol = src->cholesterol;
    dst->sodium = src->sodium;
    dst->fiber = src->fiber;
    dst->sugar = src->sugar;
    return 1;
}

float get_sat_fat(extra_nutri_info *info) { return info ? info->sat_fat : -1.0f; }
float get_trans_fat(extra_nutri_info *info) { return info ? info->trans_fat : -1.0f; }
float get_cholesterol(extra_nutri_info *info) { return info ? info->cholesterol : -1.0f; }
float get_sodium(extra_nutri_info *info) { return info ? info->sodium : -1.0f; }
float get_fiber(extra_nutri_info *info) { return info ? info->fiber : -1.0f; }
float get_sugar(extra_nutri_info *info) { return info ? info->sugar : -1.0f; }

void set_sat_fat(extra_nutri_info *info, float sat_fat) {
    if (info) info->sat_fat = sat_fat < 0 ? -1.0f : sat_fat;
}
void set_trans_fat(extra_nutri_info *info, float trans_fat) {
    if (info) info->trans_fat = trans_fat < 0 ? -1.0f : trans_fat;
}
void set_cholesterol(extra_nutri_info *info, float cholesterol) {
    if (info) info->cholesterol = cholesterol < 0 ? -1.0f : cholesterol;
}
void set_sodium(extra_nutri_info *info, float sodium) {
    if (info) info->sodium = sodium < 0 ? -1.0f : sodium;
}
void set_fiber(extra_nutri_info *info, float fiber) {
    if (info) info->fiber = fiber < 0 ? -1.0f : fiber;
}
void set_sugar(extra_nutri_info *info, float sugar) {
    if (info) info->sugar = sugar < 0 ? -1.0f : sugar;
}


void destroy_extra_nutri_info(extra_nutri_info *info) {
    free(info);
    return;
}

