#ifndef extra_nutritional_info
#define extra_nutriontal_info

typedef struct extra_nutri_info extra_nutri_info;

extra_nutri_info *create_extra_nutri_info(float sat_fat, float trans_fat, float cholesterol, float sodium, float fiber, float sugar);
extra_nutri_info *duplicate_extra_nutri_info(extra_nutri_info *info);

int copy_extra_nutri_info(extra_nutri_info *dst, extra_nutri_info *src);

float get_sat_fat(extra_nutri_info *info);
float get_trans_fat(extra_nutri_info *info);
float get_cholesterol(extra_nutri_info *info);
float get_sodium(extra_nutri_info *info);
float get_fiber(extra_nutri_info *info);
float get_sugar(extra_nutri_info *info);

void set_sat_fat(extra_nutri_info *info, float sat_fat);
void set_trans_fat(extra_nutri_info *info, float trans_fat);
void set_cholesterol(extra_nutri_info *info, float cholesterol);
void set_sodium(extra_nutri_info *info, float sodium);
void set_fiber(extra_nutri_info *info, float fiber);
void set_sugar(extra_nutri_info *info, float sugar);

void destroy_extra_nutri_info(extra_nutri_info *info);

#endif


