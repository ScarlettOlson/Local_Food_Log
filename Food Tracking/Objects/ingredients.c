#include <stdlib.h>;
#include "ingredients.h";
#include "nutritional_info.h";
#include "extra_nutritional_info.h";
#include "vitamins.h";



/**
 * Creates a new ingredient with a copy of the name, description and portion size.
 * 
 * Returns a pointer to the new ingredient or NULL if the creation failed
 */
ingredient  *create_ingredient(char *name, char *description, float portion_size) {
    if(!name || !description) return NULL;
    ingredient *ingred = malloc(sizeof(ingredient));
    if(!ingred) return NULL;


    ingred->name = malloc((strlen(name)+1) * sizeof(char));
    if(!ingred->name) return NULL;
    strcpy(ingred->name, name);

    ingred->description = malloc((strlen(description)+1) * sizeof(char));
    if(!ingred->description) {
        free(name);
        return NULL;
    } 
    strcpy(ingred->description, description);

    
    ingred->portion_size = portion_size;
    return ingred;
}

/**
 * Fills the ingredient with a copy of the nutritional info, extra nutritional info
 *      and the vitamin info
 * 
 * Returns 0 if the information could not be copied otherwise Returns 1
 */
int fill_ingredient(ingredient *ingred, nutri_info *info, extra_nutri_info *extra_info, 
    vitamin_info *vit_info) {
        if(!ingred || !info || !extra_info || !vit_info) return 0;

        // Copy information safely
        nutri_info *new_info = duplicate_nutri_info(info);
        if(!new_info) return 0;
        extra_nutri_info *new_extra_info = duplicate_extra_nutri_info(extra_info);
        if(!new_extra_info) {
            free(new_info);
            return 0;
        }
        vitamin_info *new_vit_info = duplicate_vitamin_info(vit_info);
        if(!new_vit_info) {
            free(new_info);
            free(new_extra_info);
            return 0;
        }

        // Free old information
        if(ingred->nutrition) free(ingred->nutrition);
        if(ingred->extra_nutrition) free(ingred->extra_nutrition);
        if(ingred->vitamin) free(ingred->vitamin);

        // Update informaiton
        ingred->nutrition = new_info;
        ingred->extra_nutrition = new_extra_info;
        ingred->vitamin = new_vit_info;
        return 1;
};

/**
 * Fills the ingredient with a copy of the nutritional info
 * 
 * Returns 0 if the information could not be copied otherwise Returns 1
 */
int set_ingred_nutri_info(ingredient *ingred, nutri_info *info) {
    if(!ingred || !info) return 0;

    if(ingred->nutrition) copy_nutri_info(ingred->nutrition, info);
    else ingred->nutrition = duplicate_nutri_info(info);
    
    return ingred->nutrition != NULL;
}
/**
 * Fills the ingredient with a copy of the extra nutritional info
 * 
 * Returns 0 if the information could not be copied otherwise Returns 1
 */
int set_ingred_extra_nutri_info(ingredient *ingred, extra_nutri_info *info) {
    if(!ingred || !info) return 0;

    if(ingred->extra_nutrition) copy_extra_nutri_info(ingred->extra_nutrition, info);
    else ingred->extra_nutrition = duplicate_extra_nutri_info(info);

    return ingred->extra_nutrition != NULL;
}
/**
 * Fills the ingredient with a copy of the vitamin info
 * 
 * Returns 0 if the information could not be copied otherwise Returns 1
 */
int set_ingred_vitamins(ingredient *ingred, vitamin_info *info) {
    if(!ingred || !info) return 0;

    if(ingred->vitamin) copy_nutri_info(ingred->vitamin, info);
    else ingred->vitamin = duplicate_vitamin_info(info);

    return ingred->vitamin != NULL;
}


/**
 * Creates a copy of the given ingredient, including making copies of all of the data
 * 
 * Returns a pointer to the new copy of the ingredient or NULL if it could not be created
 */
ingredient *duplicate_ingredient(ingredient *ingred) {
    if(!ingred) return NULL;
    ingredient *new_ingred = create_ingredient(ingred->name, ingred->description, ingred->portion_size);
    if(!new_ingred) return NULL;

    new_ingred->nutrition = duplicate_nutri_info(ingred->nutrition);
    new_ingred->extra_nutrition = duplicate_extra_nutri_info(ingred->extra_nutrition);
    new_ingred->vitamin = duplicate_vitamin_info(ingred->vitamin);

    return new_ingred;
}

/**
 * Destroys the ingredient and frees all associated memory
 */
void destroy_ingredient(ingredient *ingred) {
    if(!ingred) return;

    if(ingred->nutrition) free(ingred->nutrition);
    if(ingred->extra_nutrition) free(ingred->extra_nutrition);
    if(ingred->vitamin) free(ingred->vitamin);

    free(ingred);
}
