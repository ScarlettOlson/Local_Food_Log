#ifndef vitamins
#define vitamins

typedef struct {
    int     vitamin_d;      // mcg
    int     calcium;    // mg
    int     iron;       // mg
    int     potassium;   // mg
} vitamin_info;

vitamin_info *create_vitamin_info(int vitamin_d, int calcium, int iron, int potassium);
vitamin_info *copy_vitamin_info(vitamin_info *info);

int update_vitamin_info(vitamin_info *src, vitamin_info *dst);

#endif

