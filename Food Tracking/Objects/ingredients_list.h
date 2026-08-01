#include "ingredients.h";

/**
 * A structure for holding a list of ingredients
 */
typedef struct ingred_list ingred_list;

/**
 * Structure for returing both an ingredient and it's associated portion
 */
typedef struct {
    ingredient  *ingred;
    float       portion;
} ingred_return;


ingred_list *create_ingred_list();

int add_ingred_list_item(ingred_list *list, ingredient *ingred, float portion);
ingred_return *remove_ingred_list_item(ingred_list *list, char *name);
int update_ingred_list_item_portion(ingred_list *list, char *name, float portion);

ingred_return *search_ingred_list_item(ingred_list *list, char *name);
float search_ingred_list_portion(ingred_list *list, char *name);
ingred_return *replace_ingred_list_item(ingred_list *list, ingredient *ingred, float portion);
ingred_list *duplicate_ingred_list(ingred_list *list);

int destroy_ingred_list(ingred_list *list);

