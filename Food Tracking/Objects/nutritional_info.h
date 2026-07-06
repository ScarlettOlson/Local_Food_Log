#ifndef nutronal_info
#define nutritional_info

typedef struct {
    int calories;
    int protein;
    int carbs;
    int fat;
} nutri_info;

nutri_info *create_nutri_info(int cal, int protein, int carbs, int fat);
nutri_info *copy_nutri_info(nutri_info *info);

#endif