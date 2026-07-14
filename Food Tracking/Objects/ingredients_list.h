#include "ingredients.h";

/**
 * A structure for holding a list of ingredients
 */
typedef struct ingred_list ingred_list;


ingred_list *create_ingred_list();

int add_ingred_list_item(ingred_list *list, ingredient *ingred, float portion);
int remove_ingred_list_item(ingred_list *list, char *name);

ingredient *search_ingred_list(ingred_list *list, char *name);
float search_ingred_list_portion(ingred_list *list, char *name);
ingredient *replace_ingred_list(ingred_list *list, ingredient *ingred, float portion);
ingred_list *duplicate_ingred_list(ingred_list *list);

int destory_ingred_list(ingred_list *list);

