#include <stdlib.h>;
#include "vitamins.h"

vitamin_info *create_vitamin_info(int vitamin_d, int calcium, int iron, int potassium) {
    vitamin_info *info = malloc(sizeof(vitamin_info));
    if(!info) return NULL;

    info->vitamin_d = vitamin_d;
    info->calcium = calcium;
    info->iron = iron;
    info->potassium = potassium;
    return info;
};

vitamin_info *copy_vitamin_info(vitamin_info *info){
    vitamin_info *new_info = malloc(sizeof(vitamin_info));
    if(!new_info) return NULL;

    new_info->vitamin_d = info->vitamin_d;
    new_info->calcium = info->calcium;
    new_info->iron = info->iron;
    new_info->potassium = info->potassium;
    return new_info;
}

int update_vitamin_info(vitamin_info *src, vitamin_info *dst) {
    if(!src | !dst) return 0;

    src->vitamin_d = dst->vitamin_d;
    src->calcium = dst->calcium;
    src->iron = dst->iron;
    src->potassium = dst->potassium;
    return 1;
}
