#include <stdlib.h>;
#include "vitamins.h"


typedef struct{
    float     vitamin_d;      // mcg
    float     calcium;    // mg
    float     iron;       // mg
    float     potassium;   // mg
} vitamin_info;

/**
 * Creates a vitamin info object with the given information
 * 
 * Returns a pointer to the newly created object or NULL if it couldn't be created
 */
vitamin_info *create_vitamin_info(int vitamin_d, int calcium, int iron, int potassium) {
    vitamin_info *info = malloc(sizeof(vitamin_info));
    if(!info) return NULL;

    info->vitamin_d = vitamin_d;
    info->calcium = calcium;
    info->iron = iron;
    info->potassium = potassium;
    return info;
};

/**
 * Creates a duplicate copy of the given vitamin information
 * 
 * Returns a pointer to the newly created object or NULL if it couldn't be created
 */
vitamin_info *duplicate_vitamin_info(vitamin_info *info){
    vitamin_info *new_info = malloc(sizeof(vitamin_info));
    if(!new_info) return NULL;

    new_info->vitamin_d = info->vitamin_d;
    new_info->calcium = info->calcium;
    new_info->iron = info->iron;
    new_info->potassium = info->potassium;
    return new_info;
}

/**
 * Copies vitamin information from a source object to a destination
 * 
 * Returns 1 if the information was sucessfully copied and 0 if it was not
 */
int copy_vitamin_info(vitamin_info *src, vitamin_info *dst) {
    if(!src | !dst) return 0;

    src->vitamin_d = dst->vitamin_d;
    src->calcium = dst->calcium;
    src->iron = dst->iron;
    src->potassium = dst->potassium;
    return 1;
}

// Getters and Setters
// The Value -1.0 is used to items that are not being set
float get_vitamin_d(vitamin_info *info) { return info ? info->vitamin_d : -1.0; }
float get_calcium(vitamin_info *info) { return info ? info->calcium : -1.0; }
float get_iron(vitamin_info *info) { return info ? info->iron : -1.0; }
float get_potassium(vitamin_info *info) { return info ? info->potassium : -1.0; }

void set_vitamin_d(vitamin_info *info, float vitamin_d) {
    if(info) info->vitamin_d = (vitamin_d < 0) ? -1 : vitamin_d;
}
void set_calcium(vitamin_info *info, float calcium) {
    if(info) info->calcium = (calcium < 0) ? -1 : calcium;
}
void set_iron(vitamin_info *info, float iron) {
    if(info) info->iron = (iron < 0) ? -1 : iron;
}
void set_potassium(vitamin_info *info, float potassium) {
    if(info) info->potassium = (potassium < 0) ? -1 : potassium;
}

/**
 * Destroys the given vitamin information and frees the associated memory
 */
void destory_vitamin_info(vitamin_info *info) {
    free(info);
    return;
}
