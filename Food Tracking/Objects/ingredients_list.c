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
    if(!list || !ingred || (portion <= 0)) return 0;

    // Allocate more memory
    if(list->num == list->max) {
        int tmp_max = 2 * list->max;
        int tmp_portions = malloc(tmp_max * sizeof(float));
        if(!tmp_portions) return 0;
        ingredient **tmp_ingreds = malloc(tmp_max * sizeof(ingred_list*));
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
 * Returns an ingred_return object with the removed ingredient or NULL if removal failed
 */
ingred_return *remove_ingred_list_item(ingred_list *list, char *name) {
    if(!list | !name) return NULL;

    // Find ingredient in list
    int pos = -1;
    ingredient *ingred = NULL;
    float portion = 0;
    for(int i=0; i<list->num; i++) {
        if(strcmp(list->ingreds[i]->name, name)) {
            pos = i;
            ingred = list->ingreds[i];
            portion = list->portions[i];
            break;
        }
    }
    if(!ingred) return NULL;
    
    // Create Returnable Object
    ingred_return *return_val = malloc(sizeof(ingred_return));
    if(!return_val) return NULL;
    return_val->ingred = ingred;
    return_val->portion = portion;

    // Remove ingredient and shift list left
    list->num--;
    for(int i=pos; i<list->num; i++) {
        list->ingreds[i] = list->ingreds[i+1];
        list->portions[i] = list->portions[i+1];
    }
    return return_val;
}
/**
 * Searches for an ingredient by name and updates it's portion in the list
 * 
 * Returns 1 if the portion was updated othersie returns 0
 */
int update_ingred_list_item_portion(ingred_list *list, char *name, float portion) {
    if(!list || !name) return 0;

    for(int i=0; i<list->num; i++) {
        if(strcmp(list->ingreds[i]->name, name)) {
            list->portions[i] = (portion < 0) ? -1.0 : portion;
            return 1;
        }
    }
    
    return 0;
}



/**
 * Searchs the ingredient list for an ingredient with the given name
 * 
 * Returns an ingred_return object with the given ingredient
 **/
ingred_return *search_ingred_list_item(ingred_list *list, char *name) {
    if(!list || !name) return NULL;

    for(int i=0; i<list->num; i++) {
        if(strcmp(list->ingreds[i]->name, name)) {
            ingred_return *return_val = malloc(sizeof(ingred_return));
            if(!return_val) return NULL;

            ingredient *ingred = list->ingreds[i];
            float portion = list->portions[i];

            // Create Return object
            return_val->ingred = ingred;
            return_val->portion = portion;
            return return_val;
        }
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
 * Returns an ingred_return object with the ingredient and portion that was 
 *      replaced, if the ingredient couldn't be replaced a NULL pointer is returned
 */
ingred_return *replace_ingred_list_item(ingred_list *list, ingredient *ingred, float portion) {
    if(!list || !ingred) return NULL;

    char *name = ingred->name;
    for(int i=0; i<list->num; i++) {
        if(strcmp(name, list->ingreds[i]->name)) {
            // Allocate new memory
            ingredient *new_ingred = duplicate_ingredient(ingred);
            ingred_return *return_val = malloc(sizeof(ingred_return));
            if(!return_val) destroy_ingred(new_ingred);
            if(!new_ingred) return NULL;

            // Save old ingredient info
            ingredient *old_ingred = list->ingreds[i];
            float old_portion = list->portions[i];
            return_val->ingred = old_ingred;
            return_val->portion = old_portion;

            // Set new ingredient information
            list->ingreds[i] = new_ingred;
            list->portions[i] = portion;

            return return_val;
        }
    }
    
    return NULL;
}
/**
 * Creates an exact copy of the given ingredient list without modifying the original
 * 
 * Returns the copy of the ingredient list or NULL if the operation failed
 */
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

int destroy_ingred_list(ingred_list *list) {
    if(!list) return 0;

    for(int i=0; i<list->num; i++) {
        destroy_ingredient(list->ingreds[i]);
    }
    free(list);
}

