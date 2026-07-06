#include <stdlib.h>;
#include "nutritional_info.h";


nutri_info *create_nutri_info(int cal, int protein, int carbs, int fat) {
    nutri_info *info = malloc(sizeof(nutri_info));
    if(!info) return NULL;
    
    info->calories = cal;
    info->protein = protein;
    info->carbs = carbs;
    info->fat = fat;
    return info;
}

nutri_info *copy_nutri_info(nutri_info *info) {
    nutri_info *new_info = malloc(sizeof(nutri_info));
    if(!new_info) return NULL;

    new_info->calories = info->calories;
    new_info->protein = info->protein;
    new_info->carbs = info->carbs;
    new_info->fat = info->fat;
    return new_info;
}

int update_nutri_info(nutri_info *dst, nutri_info *src) {
    if(!dst || !src) return 0;

    dst->calories = src->calories;
    dst->protein = src->protein;
    dst->carbs = src->carbs;
    dst->fat = src->fat;
    return 1;
}

