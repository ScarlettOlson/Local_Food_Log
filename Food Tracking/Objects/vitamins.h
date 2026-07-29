#ifndef vitamins
#define vitamins

typedef struct {} vitamin_info;

vitamin_info *create_vitamin_info(int vitamin_d, int calcium, int iron, int potassium);
vitamin_info *duplicate_vitamin_info(vitamin_info *info);

int copy_vitamin_info(vitamin_info *src, vitamin_info *dst);

float get_vitamin_d(vitamin_info *info);
float get_calcium(vitamin_info *info);
float get_iron(vitamin_info *info);
float get_potassium(vitamin_info *info);

void set_vitamin_d(vitamin_info *info, float val);
void set_calcium(vitamin_info *info, float val);
void set_iron(vitamin_info *info, float val);
void set_potassium(vitamin_info *info, float val);

void destory_vitamin_info(vitamin_info *info);

#endif

