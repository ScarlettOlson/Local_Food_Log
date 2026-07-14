#include <stdlib.h>;
#include "ingredients.h";
#include "ingredients_list.h";

/**
 * A structure for holding a list of ingredients
 */
typedef struct {
    int num;
    int max;
    float *portions;
    ingredient  **ingreds;
} ingred_list;

// Creates an empty ingredient list
ingred_list *create_ingred_list() {
    ingred_list *list = malloc(sizeof(ingred_list));

    int max = 10;

    list->num = 0;
    list->max = max;
    list->portions = malloc(max * sizeof(float));
    list->ingreds = malloc(max * sizeof(ingredient*));
    
    return list;
}

/**
 * Adds an ingredient to the ingredient list or increases the portion if 
 *      the ingredient already exists.
 * 
 * Returns non-zero if the operation completed successfuly, otherwise returns 0
 */
int add_ingred_list_item(ingred_list *list, ingredient *ingred, float portion) {
    if(!list || !ingred) return 0;

    // Allocate more memory
    if(list->num == list->max) {
        int tmp_max = 2 * list->max;
        int tmp_portions = malloc(tmp_max * sizeof(float));
        if(!tmp_portions) return 0;
        ingredient **tmp_ingreds = malloc(tmp_max * sizeof(*ingred_list));
        if(!tmp_ingreds) return 0;

        for(int i=0; i<list->max; i++) {
            tmp_portions[i] = list->portions[i];
            tmp_ingreds[i] = list->ingreds[i];
        }
        free(list->portions);
        free(list->ingreds);
        list->max = tmp_max;
        list->portions = tmp_portions;
        list->ingreds = tmp_ingreds;
    }

    list->portions[list->num] = portion;
    list->ingreds[list->num] = ingred;
    list->num++;

    return 1;
}
/** 
 * Removes an ingredient from the ingredient list
 * 
 * Returns 0 if the ingredient does not exist or the operation failed, otherwise returns 1
 */
int remove_ingred_list_item(ingred_list *list, char *name) {
    if(!list | !name) return 0;

    // Find ingredient in list
    int pos = -1;
    for(int i=0; i<list->num; i++) {
        if(strcmp(list->ingreds[i]->name, name)) {
            pos = i;
            break;
        }
    }
    if(pos = -1) return 0;

    // Remove ingredient and shift list left
    list->num--;
    for(int i=pos; i<list->num; i++) {
        list->ingreds[i] = list->ingreds[i+1];
        list->portions[i] = list->portions[i+1];
    }
    return 1;
}

/**
 * Searchs the ingredient list for an ingredient with the given name
 * 
 * Returns a pointer to the ingredient if it exists, Otherwise returns a NULL pointer
 */
ingredient *search_ingred_list(ingred_list *list, char *name) {
    if(!list || !name) return NULL;

    for(int i=0; i<list->num; i++) {
        if(strcmp(list->ingreds[i]->name, name)) return list->ingreds[i];
    }

    return NULL;
}
/**
 * Searchs the ingredient list for the portion for the ingredient with the given name
 * 
 * Returns the portion for the given ingredient if it exists, Otherwise returns -1.0
 */
float search_ingred_list_portion(ingred_list *list, char *name) {
    if(!list || !name) return -1.0;

    for(int i=0; i<list->num; i++) {
        if(strcmp(list->ingreds[i]->name, name)) return list->portions[i];
    }

    return -1.0;
}
/**
 * Replaces an ingredient in the list with the given ingredient and portion.
 *      If the ingredient does not exist it is simply added to the list
 *      The new ingredient is copied and the passed ingredient is unchanged
 * 
 * Returns the old ingredient if it exists, Otherwise returns a NULL pointer
 */
ingredient *replace_ingred_list(ingred_list *list, ingredient *ingred, float portion) {
    if(!list || !ingred) return NULL;

    char *name = ingred->name;
    for(int i=0; i<list->num; i++) {
        if(strcmp(name, list->ingreds[i]->name)) {
            ingredient *new_ingred = duplicate_ingredient(ingred);
            if(!new_ingred) return NULL;
            else {
                ingredient *old_ingred = list->ingreds[i];
                list->ingreds[i] = new_ingred;
                return old_ingred;
            }
        }
    }
    
    return NULL;
}
ingred_list *duplicate_ingred_list(ingred_list *list) {
    if(!list) return NULL;

    int num = list->num;
    int max = list->max;

    ingred_list *new_list = malloc(sizeof(ingred_list));
    new_list->num = num;
    new_list->max = max;
    new_list->ingreds = malloc(max * sizeof(ingredient));
    new_list->portions = malloc(max * sizeof(float));

    for(int i=0; i<num; i++) {
        new_list->ingreds[i] = list->ingreds[i];
        new_list->portions[i] = list->portions[i];
    }
    return new_list;
}

int destory_ingred_list(ingred_list *list) {

}

