#include "vitamins.h"

/**
 * Creates a vitamin object with the given information
 * 
 * Any negative values indicate that the value is not set
 */
vitamin_info *create_vitamin_info(int vitamin_d, int calcium, int iron, int potassium){
    vitamin_info *info = malloc(sizeof(vitamin_info));
    info->vitamin_d = vitamin_d;
    info->calcium = calcium;
    info->iron = iron;
    info->potassium = potassium;
    return info;
};

/**
 * Crates a copy of the vitamin object
 */
vitamin_info *copy_vitamin_info(vitamin_info *info){
    vitamin_info *new_info = malloc(sizeof(vitamin_info));
    new_info->vitamin_d = info->vitamin_d;
    new_info->calcium = info->calcium;
    new_info->iron = info->iron;
    new_info->potassium = info->potassium;
    return new_info;
}

int destroy_vitamin_info(vitamin_info *info)  {
    free(info);
}



