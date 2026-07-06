#ifndef extra_nutritional_info
#define extra_nutriontal_info

typedef struct {
    int     sat_fat;
    int     trans_fat;
    int     cholesterol; // mg
    int     sodium;      // mg
    int     fiber;
    int     sugar;
} extra_nutri_info;

extra_nutri_info *create_extra_nutri_info(int sat_fat, int trans_fat, int cholesterol, int sodium, int fiber, int sugar);

extra_nutri_info *copy_extra_nutri_info(extra_nutri_info *info);

#endif


