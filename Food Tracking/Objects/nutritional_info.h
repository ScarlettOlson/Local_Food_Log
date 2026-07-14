#ifndef nutronal_info
#define nutritional_info

typedef struct nutri_info nutri_info;

nutri_info *create_nutri_info(float cal, float protein, float carbs, float fat);
nutri_info *duplicate_nutri_info(nutri_info *info);
int copy_nutri_info(nutri_info *dst, nutri_info *src);

float get_cal(nutri_info *info);
float get_protein(nutri_info *info);
float get_carbs(nutri_info *info);
float get_fat(nutri_info *info);

void set_cal(nutri_info *info, float cal);
void set_protein(nutri_info *info, float protein);
void set_carbs(nutri_info *info, float carbs);
void set_fat(nutri_info *info, float fat);

void destory_nutri_info(nutri_info *info);

#endif