#include <stdlib.h>;
#include "ingredients.h";
#include "nutritional_info.h";
#include "extra_nutritional_info.h";
#include "vitamins.h";



ingredient  *create_ingredient(char *name, char *description, int portion_size) {
    if(!name || !description) return NULL;

    ingredient *ingred = malloc(sizeof(ingredient));
    if(!ingred) return NULL;

    // Create a copy of the info and description
    ingred->name = malloc((strlen(name)+1) * sizeof(char));
    if(!ingred->name) return NULL;
    strcpy(ingred->name, name);
    ingred->description = malloc((strlen(description)+1) * sizeof(char));
    if(!ingred->description) return NULL;
    strcpy(ingred->description, description);

    ingred->portion_size = portion_size;
    return ingred;
}


int fill_ingredient(ingredient *ingred, nutri_info *info, extra_nutri_info *extra_info, 
    vitamin_info *vit_info) {
        if(!ingred || !info || !extra_info || !vit_info) return 0;

        // Copy information safely
        nutri_info *new_info = copy_nutri_info(info);
        if(!new_info) return 0;
        extra_nutri_info *new_extra_info = copy_extra_nutri_info(extra_info);
        if(!new_extra_info) {
            free(new_info);
            return 0;
        }
        vitamin_info *new_vit_info = copy_vitamin_info(vit_info);
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

                    
int set_ingred_nutri_info(ingredient *ingred, nutri_info *info) {
    if(!ingred || !info) return 0;

    nutri_info *new_info = copy_nutri_info(info);
    if(!new_info) return 0;
    if(ingred->nutrition) free(ingred->nutrition);
    ingred->nutrition = new_info;
    return 1;
}
int set_ingred_extra_nutri_info(ingredient *ingred, extra_nutri_info *info) {
    if(!ingred || !info) return 0;

    nutri_info *new_info = copy_extra_nutri_info(info);
    if(!new_info) return 0;
    if(ingred->extra_nutrition) free(ingred->extra_nutrition);
    ingred->extra_nutrition = new_info;
    return 1;
}
int set_ingred_vitamins(ingredient *ingred, vitamin_info *info) {
    if(!ingred || !info) return 0;

    nutri_info *new_info = copy_vitamin_info(info);
    if(!new_info) return 0;
    if(ingred->vitamin) free(ingred->vitamin);
    ingred->vitamin = new_info;
    return 1;
}


void destroy_ingredient(ingredient *ingred) {
    if(!ingred) return;

    if(ingred->nutrition) free(ingred->nutrition);
    if(ingred->extra_nutrition) free(ingred->extra_nutrition);
    if(ingred->vitamin) free(ingred->vitamin);

    free(ingred);
}
