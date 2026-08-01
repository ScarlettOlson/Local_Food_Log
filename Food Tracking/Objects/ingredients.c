#include <stdlib.h>;
#include "ingredients.h";
#include "nutritional_info.h";
#include "extra_nutritional_info.h";
#include "vitamins.h";

/**
 * A structure for holding information about generic ingredients.
 * 
 * All values are in grams unless otherwise noted
 */
typedef struct {
    char *name;
    char *description;
    float  portion_size;

    // Nutrional Information
    nutri_info *nutri;
    extra_nutri_info *e_nutri;
    vitamin_info *vit
} ingredient;

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
 *      and the vit info
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
        if(ingred->nutri) free(ingred->nutri);
        if(ingred->e_nutri) free(ingred->e_nutri);
        if(ingred->vit) free(ingred->vit);

        // Update informaiton
        ingred->nutri = new_info;
        ingred->e_nutri = new_extra_info;
        ingred->vit = new_vit_info;
        return 1;
};

/**
 * Fills the ingredient with a copy of the nutritional info
 * 
 * Returns 0 if the information could not be copied otherwise Returns 1
 */
int set_ingred_nutri_info(ingredient *ingred, nutri_info *info) {
    if(!ingred || !info) return 0;

    if(ingred->nutri) copy_nutri_info(ingred->nutri, info);
    else ingred->nutri = duplicate_nutri_info(info);
    
    return ingred->nutri != NULL;
}
/**
 * Fills the ingredient with a copy of the extra nutritional info
 * 
 * Returns 0 if the information could not be copied otherwise Returns 1
 */
int set_ingred_extra_nutri_info(ingredient *ingred, extra_nutri_info *info) {
    if(!ingred || !info) return 0;

    if(ingred->e_nutri) copy_extra_nutri_info(ingred->e_nutri, info);
    else ingred->e_nutri = duplicate_extra_nutri_info(info);

    return ingred->e_nutri != NULL;
}
/**
 * Fills the ingredient with a copy of the vit info
 * 
 * Returns 0 if the information could not be copied otherwise Returns 1
 */
int set_ingred_vitamins(ingredient *ingred, vitamin_info *info) {
    if(!ingred || !info) return 0;

    if(ingred->vit) copy_nutri_info(ingred->vit, info);
    else ingred->vit = duplicate_vitamin_info(info);

    return ingred->vit != NULL;
}

// Getters and Setters
float get_ingred_calories(ingredient *ingred) {
    return (ingred) ? get_calories(ingred->nutri) : -1.0;
}
float get_ingred_protein(ingredient *ingred) {
    return (ingred) ? get_protein(ingred->nutri) : -1.0;
}
float get_ingred_carbs(ingredient *ingred) {
    return (ingred) ? get_carbs(ingred->nutri) : -1.0;
}
float get_ingred_fat(ingredient *ingred) {
    return (ingred) ? get_fat(ingred->nutri) : -1.0;
}
float get_ingred_sat_fat(ingredient *ingred) {
    return (ingred) ? get_sat_fat(ingred->e_nutri) : -1.0;
}
float get_ingred_trans_fat(ingredient *ingred) {
    return (ingred) ? get_trans_fat(ingred->e_nutri) : -1.0;
}
float get_ingred_cholesterol(ingredient *ingred) {
    return (ingred) ? get_cholesterol(ingred->e_nutri) : -1.0;
}
float get_ingred_sodium(ingredient *ingred) {
    return (ingred) ? get_sodium(ingred->e_nutri) : -1.0;
}
float get_ingred_fiber(ingredient *ingred) {
    return (ingred) ? get_fiber(ingred->e_nutri) : -1.0;
}
float get_ingred_sugar(ingredient *ingred) {
    return (ingred) ? get_sugar(ingred->e_nutri) : -1.0;
}
float get_ingred_vitamin_d(ingredient *ingred) {
    return (ingred) ? get_vitamin_d(ingred->vit) : -1.0;
}
float get_ingred_calcium(ingredient *ingred) {
    return (ingred) ? get_calcium(ingred->vit) : -1.0;
}
float get_ingred_iron(ingredient *ingred) {
    return (ingred) ? get_iron(ingred->vit) : -1.0;
}
float get_ingred_potassium(ingredient *ingred) {
    return (ingred) ? get_potassium(ingred->vit) : -1.0;
}

void set_ingred_calories(ingredient *ingred, float val) { if(ingred) set_calories(ingred->nutri, val); }
void set_ingred_protein(ingredient *ingred, float val) { if(ingred) set_protein(ingred->nutri, val); }
void set_ingred_carbs(ingredient *ingred, float val) { if(ingred) set_carbs(ingred->nutri, val); }
void set_ingred_fat(ingredient *ingred, float val) { if(ingred) set_fat(ingred->nutri, val); }
void set_ingred_sat_fat(ingredient *ingred, float val) { if(ingred) set_sat_fat(ingred->e_nutri, val); }
void set_ingred_trans_fat(ingredient *ingred, float val) { if(ingred) set_trans_fat(ingred->e_nutri, val); }
void set_ingred_cholesterol(ingredient *ingred, float val) { if(ingred) set_cholesterol(ingred->e_nutri, val); }
void set_ingred_sodium(ingredient *ingred, float val) { if(ingred) set_sodium(ingred->e_nutri, val); }
void set_ingred_fiber(ingredient *ingred, float val) { if(ingred) set_fiber(ingred->e_nutri, val); }
void set_ingred_sugar(ingredient *ingred, float val) { if(ingred) set_sugar(ingred->e_nutri, val); }
void set_ingred_vitamin_d(ingredient *ingred, float val) { if(ingred) set_vitamin_d(ingred->vit, val); }
void set_ingred_calcium(ingredient *ingred, float val) { if(ingred) set_calcium(ingred->vit, val); }
void set_ingred_iron(ingredient *ingred, float val) { if(ingred) set_iron(ingred->vit, val); }
void set_ingred_potassium(ingredient *ingred, float val) { if(ingred) set_potassium(ingred->vit, val); }

/**
 * Creates a copy of the given ingredient, including making copies of all of the data
 * 
 * Returns a pointer to the new copy of the ingredient or NULL if it could not be created
 */
ingredient *duplicate_ingredient(ingredient *ingred) {
    if(!ingred) return NULL;
    ingredient *new_ingred = create_ingredient(ingred->name, ingred->description, ingred->portion_size);
    if(!new_ingred) return NULL;

    new_ingred->nutri = duplicate_nutri_info(ingred->nutri);
    new_ingred->e_nutri = duplicate_extra_nutri_info(ingred->e_nutri);
    new_ingred->vit = duplicate_vitamin_info(ingred->vit);

    return new_ingred;
}

/**
 * Destroys the ingredient and frees all associated memory
 */
void destroy_ingredient(ingredient *ingred) {
    if(!ingred) return;

    if(ingred->nutri) free(ingred->nutri);
    if(ingred->e_nutri) free(ingred->e_nutri);
    if(ingred->vit) free(ingred->vit);

    free(ingred);
}
