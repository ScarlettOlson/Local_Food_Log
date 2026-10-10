#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

#include "../Food Tracking/Objects/nutritional_info.h"
#include "../Food Tracking/Objects/extra_nutritional_info.h"
#include "../Food Tracking/Objects/vitamins.h"
#include "../Food Tracking/Objects/ingredients.h"
#include "../Food Tracking/Objects/ingredients_list.h"
#include "../Food Tracking/Objects/meals.h"


void nutri_creation_tests(float *cal_vals, float *prot_vals, float *carb_vals, 
                         float *fat_vals, nutri_info **objs, int num) {
    int fail = 0;
    
    float cal, protein, carbs, fat;
    for(int i=0; i<num; i++) {
        cal     = (cal_vals[i] < 0)  ? -1.0 : cal_vals[i];
        protein = (prot_vals[i] < 0) ? -1.0 : prot_vals[i];
        carbs   = (carb_vals[i] < 0) ? -1.0 : carb_vals[i];
        fat     = (fat_vals[i] < 0)  ? -1.0 : fat_vals[i];

        objs[i] = create_nutri_info(cal_vals[i], prot_vals[i], carb_vals[i], fat_vals[i]);
        if(!objs[i]) { 
            printf("Unable to create nutritional info object with the following values:\n");
            printf("cal=%f, protein=%f, carbs=%f, fat=%f\n\n", cal_vals[i], prot_vals[i], carb_vals[i], fat_vals[i]);
            fail = 1;
            continue;
        }
        
        if(cal != get_cal(objs[i])) {
            printf("Calorie value incorrect after creation:\n");
            printf("Expected Value=%f\t Actual Value=%f\n\n", cal, get_cal(objs[i]));
            fail = 1;
        }
        if(protein != get_protein(objs[i])) {
            printf("Protein value incorrect after creation:\n");
            printf("Expected Value=%f\t Actual Value=%f\n\n", protein, get_protein(objs[i]));
            fail = 1;
        }
        if(carbs != get_carbs(objs[i])) {
            printf("Carbs value incorrect after creation:\n");
            printf("Expected Value=%f\t Actual Value=%f\n\n", carbs, get_carbs(objs[i]));
            fail = 1;
        }
        if(fat != get_fat(objs[i])) {
            printf("Fat value incorrect after creation: ");
            printf("Expected Value=%f\t Actual Value=%f\n\n", fat, get_fat(objs[i]));
            fail = 1;
        }
    }
    if(!fail) printf("All Nutritional Creation Tests Passed\n");
}
void nutri_duplication_tests (float *cal_vals, float *prot_vals, float *carb_vals, 
                             float *fat_vals, nutri_info **objs, 
                             nutri_info **objs2, nutri_info **objs3, int num) {
    /**
     * TODO: Add Tests to check that values in one object are not affected by changes in children or parents 
     */
    int fail = 0;

    // Test Duplicated Values are correct
    float cal, protein, carbs, fat;
    for(int i=0; i<num; i++) {
        cal     = (cal_vals[i] < 0)  ? -1.0 : cal_vals[i];
        protein = (prot_vals[i] < 0) ? -1.0 : prot_vals[i];
        carbs   = (carb_vals[i] < 0) ? -1.0 : carb_vals[i];
        fat     = (fat_vals[i] < 0)  ? -1.0 : fat_vals[i];

        objs2[i] = duplicate_nutri_info(objs[i]);
        if(!objs2[i]) {
            printf("Unable to duplicate nutritional info object with the following values:\n");
            printf("cal=%f, protein=%f, carbs=%f, fat=%f\n", cal_vals[i], prot_vals[i], carb_vals[i], fat_vals[i]);
            fail = 1;
            continue;
        };

        if(cal != get_cal(objs2[i])) {
            printf("Calorie value incorrect in duplicated object");
            printf("Expected Value=%f\t Actual Value=%f\n\n", cal, get_cal(objs2[i]));
            fail = 1;
        }
        if(protein != get_protein(objs2[i])) {
            printf("Protein value incorrect in duplicated object");
            printf("Expected Value=%f\t Actual Value=%f\n\n", protein, get_protein(objs2[i]));
            fail = 1;
        }
        if(carbs != get_carbs(objs2[i])) {
            printf("Carbs value incorrect in duplicated object");
            printf("Expected Value=%f\t Actual Value=%f\n\n", carbs, get_carbs(objs2[i]));
            fail = 1;
        }
        if(fat != get_fat(objs2[i])) {
            printf("Fat value incorrect in duplicated object");
            printf("Expected Value=%f\t Actual Value=%f\n\n", fat, get_fat(objs2[i]));
            fail = 1;
        }
    }

    // Test Original values are correct after duplication
    for(int i=0; i<num; i++) {
        cal     = get_cal(objs[i]);
        protein = get_protein(objs[i]);
        carbs   = get_carbs(objs[i]);
        fat     = get_fat(objs[i]);

        objs3[i] = duplicate_nutri_info(objs[i]);
        if(!objs3[i]) {
            printf("Unable to duplicate nutritional info object with the following values:\n");
            printf("cal=%f, protein=%f, carbs=%f, fat=%f\n", cal_vals[i], prot_vals[i], carb_vals[i], fat_vals[i]);
            fail = 1;
            continue;
        }

        if(cal != get_cal(objs[i])) {
            printf("Original calorie value incorrect after duplication:\n");
            printf("Expected Value=%f\t Actual Value=%f\n\n", cal, get_cal(objs[i]));
            fail = 1;
        } 
        if(protein != get_protein(objs[i])) {
            printf("Original protein value incorrect after duplication:\n");
            printf("Expected Value=%f\t Actual Value=%f\n\n", cal, get_cal(objs[i]));
            fail = 1;
        }
        if(carbs != get_carbs(objs[i])) {
            printf("Original carbs value incorrect after duplication:\n");
            printf("Expected Value=%f\t Actual Value=%f\n\n", cal, get_cal(objs[i]));
            fail = 1;
        }
        if(fat != get_fat(objs[i])) {
            printf("Original fat value incorrect after duplication:\n");
            printf("Expected Value=%f\t Actual Value=%f\n\n", cal, get_cal(objs[i]));
            fail = 1;
        }
    }
    

    if(!fail) printf("All Nutritional Info Duplication Tests Passed\n");
}
void nutri_copy_tests(float *cal_vals, float *prot_vals, float *carb_vals, float *fat_vals,
                     nutri_info **objs, nutri_info **objs2, int num) {
    int fail = 0;
    // Test Object Copying
    float cal, protein, carbs, fat;
    for(int i=0; i<num; i++) {
        cal     = (cal_vals[i] < 0)  ? -1.0 : cal_vals[i];
        protein = (prot_vals[i] < 0) ? -1.0 : prot_vals[i];
        carbs   = (carb_vals[i] < 0) ? -1.0 : carb_vals[i];
        fat     = (fat_vals[i] < 0)  ? -1.0 : fat_vals[i];

        if(!copy_nutri_info(objs2[(num-1)-i], objs[i])) { 
            printf("Unable to copy nutritional info object with the following values:\n");
            printf("cal=%f, protein=%f, carbs=%f, fat=%f\n\n", cal_vals[i], prot_vals[i], carb_vals[i], fat_vals[i]);
            fail = 1; 
            continue;
        }
        
        if(cal     != get_cal(objs[i])) {
            printf("Original calorie value incorrect after copying:\n");
            printf("Expected Value=%f\t Actual Value=%f\n\n", cal, get_cal(objs[i]));
            fail = 1;
        }
        if(protein != get_protein(objs[i])) {
            printf("Original protein value incorrect after copying:\n");
            printf("Expected Value=%f\t Actual Value=%f\n\n", protein, get_protein(objs[i]));
            fail = 1;
        }
        if(carbs   != get_carbs(objs[i])) {
            printf("Original carbs value incorrect after copying:\n");
            printf("Expected Value=%f\t Actual Value=%f\n\n", carbs, get_carbs(objs[i]));
            fail = 1;
        }
        if(fat     != get_fat(objs[i])) {
            printf("Original fat value incorrect after copying:\n");
            printf("Expected Value=%f\t Actual Value=%f\n\n", fat, get_fat(objs[i]));
            fail = 1;
        }

        if(cal     != get_cal(objs2[num-1-i])) {
            printf("Copied calorie value incorrect");
            printf("Expected Value=%f\t Actual Value=%f\n\n", cal, get_cal(objs2[i]));
            fail = 1;
        }
        if(protein != get_protein(objs2[num-1-i])) {
            printf("Copied protein value incorrect");
            printf("Expected Value=%f\t Actual Value=%f\n\n", protein, get_protein(objs2[i]));
            fail = 1;
        }
        if(carbs   != get_carbs(objs2[num-1-i])) {
            printf("Copied carbohydrate value incorrect");
            printf("Expected Value=%f\t Actual Value=%f\n\n", carbs, get_carbs(objs2[i]));
            fail = 1;
        }
        if(fat     != get_fat(objs2[num-1-i])) {
            printf("Copied fat value incorrect");
            printf("Expected Value=%f\t Actual Value=%f\n\n", fat, get_fat(objs2[i]));
            fail = 1;
        }
    }

    // Test Coping Values to self
    for(int i=0; i<num; i++) {
        cal     = get_cal(objs2[i]);
        protein = get_protein(objs2[i]);
        carbs   = get_carbs(objs2[i]);
        fat     = get_fat(objs2[i]);

        if(!copy_nutri_info(objs2[i], objs2[i])) {
            printf("Unable to copy nutritional info object to itself with the following values:\n");
            printf("cal=%f, protein=%f, carbs=%f, fat=%f\n\n", cal_vals[i], prot_vals[i], carb_vals[i], fat_vals[i]);
            fail = 1; 
            continue;
        }

        if(cal != get_cal(objs2[i])) {
            printf("Calorie Value incorrect when copying nutritional value to itself:\n");
            printf("Expected Value=%f\t Actual Value=%f\n\n", cal, get_cal(objs[i]));
            fail = 1;
        }
        if(protein != get_protein(objs2[i])) {
            printf("Protein Value incorrect when copying nutritional value to itself:\n");
            printf("Expected Value=%f\t Actual Value=%f\n\n", protein, get_protein(objs[i]));
            fail = 1;
        }
        if(carbs != get_carbs(objs2[i])) {
            printf("Carbohydrate Value incorrect when copying nutritional value to itself:\n");
            printf("Expected Value=%f\t Actual Value=%f\n\n", carbs, get_carbs(objs[i]));
            fail = 1;
        }
        if(fat != get_fat(objs2[i])) {
            printf("Fat Value incorrect when copying nutritional value to itself:\n");
            printf("Expected Value=%f\t Actual Value=%f\n\n", fat, get_fat(objs[i]));
            fail = 1;
        }
    }

    if(!fail) printf("All Nutritional Info Copy Tests Passed\n");
}
void nutri_setter_tests(float *cal_vals, float *prot_vals, float *carb_vals, 
                         float *fat_vals, nutri_info **objs, int num) {
    int fail = 0;

    // Test Setters
    float cal, protein, carbs, fat;
    for(int i=0; i<num; i++) {
        cal     = (cal_vals[i] < 0)  ? -1.0 : cal_vals[i];
        protein = (prot_vals[i] < 0) ? -1.0 : prot_vals[i];
        carbs   = (carb_vals[i] < 0) ? -1.0 : carb_vals[i];
        fat     = (fat_vals[i] < 0)  ? -1.0 : fat_vals[i];

        set_cal(objs[num-1-i], cal);
        set_protein(objs[num-1-i], protein);
        set_carbs(objs[num-1-i], carbs);
        set_fat(objs[num-1-i], fat);

        if(cal != get_cal(objs[i])) {
            printf("Calorie Value incorrect after setter used\n");
            printf("Expected Value=%f\t Actual Value=%f\n\n", cal, get_cal(objs[i]));
            fail = 1;
        }
        if(protein != get_protein(objs[i])) {
            printf("Protein Value incorrect after setter used\n");
            printf("Expected Value=%f\t Actual Value=%f\n\n", protein, get_protein(objs[i]));
            fail = 1;
        }
        if(carbs != get_carbs(objs[i])) {
            printf("Carbohydrate Value incorrect after setter used\n");
            printf("Expected Value=%f\t Actual Value=%f\n\n", carbs, get_carbs(objs[i]));
            fail = 1;
        }
        if(fat != get_fat(objs[i])) {
            printf("Fat Value incorrect after setter used\n");
            printf("Expected Value=%f\t Actual Value=%f\n\n", fat, get_fat(objs[i]));
            fail = 1;
        }
    }

    if(!fail) printf("All Nutritional Info Setter Tests Passed");
}
void nutri_null_tests(nutri_info *info) {
    int fail = 0;
    if(duplicate_nutri_info(NULL))   fail = 1;

    if(copy_nutri_info(NULL, NULL)) fail = 1;
    if(copy_nutri_info(info, NULL)) fail = 1;
    if(copy_nutri_info(NULL, info)) fail = 1;

    if(get_cal(NULL) != -1.0f) fail = 1;
    if(get_protein(NULL) != -1.0f) fail = 1;
    if(get_carbs(NULL) != -1.0f) fail = 1;
    if(get_fat(NULL) != -1.0f) fail = 1;

    // No return values. Failure May or May not cause faults
    set_cal(NULL, 0.0f);
    set_protein(NULL, 0.0f);
    set_carbs(NULL, 0.0f);
    set_fat(NULL, 0.0f);
    destroy_nutri_info(NULL);

    if(!fail) printf("All Nutritional Info NULL Tests Passed\n");
}
void *nutri_tests() {

    // Test a variety of values. Positive, negative, Zero and Near Zero
    // Use seperate values for each property in a given object
    int num = 7;
    float cal_vals[]     = { -10.0f, -1.0f, -0.99f, 0.0f, 0.99f, 1.0f, 10.0f };
    float prot_vals[] = { -11.0f, 0.0f, 1.0f, 0.99f, 10.0f, -1.0f, -0.99f };
    float carb_vals[]   = { 16.0f, 1.0f, 0.99f, .99f, 0.0f, -1.0f, -0.05f, -80.0f };
    float fat_vals[]     = { 1.0f, -12.0f, 0.0f, 12.0f, -1.0f, 0.5f, -0.11f };
    nutri_info *objs[] = { NULL, NULL, NULL, NULL, NULL, NULL, NULL };
    nutri_info *objs2[] = { NULL, NULL, NULL, NULL, NULL, NULL, NULL };
    nutri_info *objs3[] = { NULL, NULL, NULL, NULL, NULL, NULL, NULL };

    nutri_creation_tests(cal_vals, prot_vals, carb_vals, fat_vals, objs, num);
    nutri_duplication_tests(cal_vals, prot_vals, carb_vals, fat_vals, objs, objs2, objs3, num);
    nutri_copy_tests(cal_vals, prot_vals, carb_vals, fat_vals, objs, objs2, num);
    nutri_setter_tests(cal_vals, prot_vals, carb_vals, fat_vals, objs, num);
    nutri_null_tests(objs[0]);

    // Destroy Remaining Objects and return
    for(int i=0; i<num; i++) { 
        destroy_nutri_info(objs[i]);
        destroy_nutri_info(objs2[i]);
        destroy_nutri_info(objs3[i]);
    }
    return NULL;
}

void enutri_creation_tests(float *sat_vals, float *trans_vals, float *chol_vals,
                          float *sod_vals, float *fiber_vals, float *sug_vals, 
                          extra_nutri_info **info_list, int num) {
        int fail = 0;

        float sat, trans, chol, sod, fiber, sug;
        for(int i=0; i<num; i++) {
            sat   = (sat_vals[i] < 0)   ? -1.0 : sat_vals[i];
            trans = (trans_vals[i] < 0) ? -1.0 : trans_vals[i];
            chol  = (chol_vals[i] < 0)  ? -1.0 : chol_vals[i];
            sod   = (sod_vals[i] < 0)   ? -1.0 : sod_vals[i];
            fiber = (fiber_vals[i] < 0) ? -1.0 : fiber_vals[i];
            sug   = (sug_vals[i] < 0)   ? -1.0 : sug_vals[i];

            *(info_list + i) = create_extra_nutri_info(sat_vals[i], trans_vals[i], 
                chol_vals[i], sod_vals[i], fiber_vals[i], sug_vals[i]);
            if(!info_list[i]) { 
                printf("Unable to create extra_nutri_info object with the following values:\n");
                printf("sat_fat=%f, trans_fat=%f, cholesterol=%f, ", sat_vals[i], trans_vals[i], chol_vals[i]);
                printf("sodium=%f, fiber=%f, and sugar=%f/n", sod_vals[i], fiber_vals[i], sug_vals[i]);
                fail = 1;
                continue;
            }

            if(sat != get_sat_fat(info_list[i])) {
                printf("Saturated Fat value incorrect after creation:\n");
                printf("Expected Value=%f\t Actual Value=%f\n\n", sat, get_sat_fat(info_list[i]));
                fail = 1;
            } 
            if(trans != get_trans_fat(info_list[i])) {
                printf("Trans Fat value incorrect after creation:\n");
                printf("Expected Value=%f\t Actual Value=%f\n\n",trans , get_trans_fat(info_list[i]));
                fail = 1;
            }
            if(chol != get_cholesterol(info_list[i])) {
                printf("Cholesterol value incorrect after creation:\n");
                printf("Expected Value=%f\t Actual Value=%f\n\n", chol, get_cholesterol(info_list[i]));
                fail = 1;
            } 
            if(sod != get_sodium(info_list[i])) {
                printf("Sodium value incorrect after creation:\n");
                printf("Expected Value=%f\t Actual Value=%f\n\n", sod, get_sodium(info_list[i]));
                fail = 1;
            } 
            if(fiber != get_fiber(info_list[i])) {
                printf("Fiber value incorrect after creation:\n");
                printf("Expected Value=%f\t Actual Value=%f\n\n", fiber, get_fiber(info_list[i]));
                fail = 1;
            } 
            if(sug != get_sugar(info_list[i])) {
                printf("Sugar value incorrect after creation:\n");
                printf("Expected Value=%f\t Actual Value=%f\n\n", sug, get_sugar(info_list[i]));
                fail = 1;
            }
        }
        
        if(fail == 1) printf("All Extra Nutritional Info Creation Tests Passed\n");
    }
void enutri_duplication_tests(float *sat_vals, float *trans_vals, float *chol_vals,
                          float *sod_vals, float *fiber_vals, float *sug_vals, extra_nutri_info **objs,
                          extra_nutri_info **objs2, extra_nutri_info **objs3, int num) {
    int fail = 0;

    // Test Duplicated Values are correct
    float sat, trans, chol, sod, fiber, sug;
    for(int i=0; i<num; i++) {
        sat   = (sat_vals[i] < 0)     ? -1.0 : sat_vals[i];
        trans = (trans_vals[i] < 0)   ? -1.0 : trans_vals[i];
        chol      = (chol_vals[i] < 0) ? -1.0 : chol_vals[i];
        sod    = (sod_vals[i] < 0)      ? -1.0 : sod_vals[i];
        fiber     = (fiber_vals[i] < 0)       ? -1.0 : fiber_vals[i];
        sug     = (sug_vals[i] < 0)       ? -1.0 : sug_vals[i];

        objs2[i] = duplicate_extra_nutri_info(objs[i]);
        if(!objs2[i]) {
            printf("Unable to duplicate extra nutritional info object with the following values:\n");
            printf("sat_fat=%f, trans_fat=%f, chol=%f, ", sat_vals[i], trans_vals[i], chol_vals[i]);
            printf("sodium=%f, fiber=%f, sugar=%f\n\n", sod_vals[i], fiber_vals[i], sug_vals[i]);
            fail = 1;
            continue;
        };

        if(sat != get_sat_fat(objs2[i])) {
            printf("Saturated fat value incorrect in duplicated object");
            printf("Expected Value=%f\t Actual Value=%f\n\n", sat, get_sat_fat(objs2[i]));
            fail = 1;
        }
        if(trans != get_trans_fat(objs2[i])) {
            printf("Trans Fat value incorrect in duplicated object");
            printf("Expected Value=%f\t Actual Value=%f\n\n", trans, get_trans_fat(objs2[i]));
            fail = 1;
        }
        if(chol != get_cholesterol(objs2[i])) {
            printf("Cholesterol value incorrect in duplicated object");
            printf("Expected Value=%f\t Actual Value=%f\n\n", chol, get_cholesterol(objs2[i]));
            fail = 1;
        }
        if(sod != get_sodium(objs2[i])) {
            printf("Sodium value incorrect in duplicated object");
            printf("Expected Value=%f\t Actual Value=%f\n\n", sod, get_sodium(objs2[i]));
            fail = 1;
        }
        if(fiber != get_fiber(objs2[i])) {
            printf("Fiber value incorrect in duplicated object");
            printf("Expected Value=%f\t Actual Value=%f\n\n", fiber, get_fiber(objs2[i]));
            fail = 1;
        }
        if(sug != get_sugar(objs2[i])) {
            printf("Sugar value incorrect in duplicated object");
            printf("Expected Value=%f\t Actual Value=%f\n\n", sug, get_sugar(objs2[i]));
            fail = 1;
        }
    }

    // Test Original values are correct after duplication
    for(int i=0; i<num; i++) {
        sat   = get_sat_fat(objs[i]);
        trans = get_trans_fat(objs[i]);
        chol      = get_cholesterol(objs[i]);
        sod    = get_sodium(objs[i]);
        fiber     = get_fiber(objs[i]);
        sug     = get_sugar(objs[i]);

        objs3[i] = duplicate_extra_nutri_info(objs[i]);
        if(!objs[i]) {
            printf("Unable to duplicated nutritional info object with the following values:\n");
            printf("sat_fat=%f, trans_fat=%f, chol=%f, ", sat, trans, chol);
            printf("sodium=%f, fiber=%f, sugar=%f\n\n", sod, fiber, sug);
            fail = 1;
            continue;
        }

        if(sat != get_sat_fat(objs[i])) {
            printf("Original saturated fat value incorrect after duplication:\n");
            printf("Expected Value=%f, Actual Value=%f\n\n", sat, get_sat_fat(objs[i]));
            fail = 1;
        }
        if(trans != get_trans_fat(objs[i])) {
            printf("Original trans fat value incorrect after duplication:\n");
            printf("Expected Value=%f, Actual Value=%f\n\n", trans, get_trans_fat(objs[i]));
            fail = 1;
        }
        if(chol != get_cholesterol(objs[i])) {
            printf("Original cholesterol value incorrect after duplication:\n");
            printf("Expected Value=%f, Actual Value=%f\n\n", chol, get_cholesterol(objs[i]));
            fail = 1;
        }
        if(sod != get_sodium(objs[i])) {
            printf("Original sodium value incorrect after duplication:\n");
            printf("Expected Value=%f, Actual Value=%f\n\n", sod, get_sodium(objs[i]));
            fail = 1;
        }
        if(fiber != get_fiber(objs[i])) {
            printf("Original fiber value incorrect after duplication:\n");
            printf("Expected Value=%f, Actual Value=%f\n\n", fiber, get_fiber(objs[i]));
            fail = 1;
        }
        if(sug != get_sugar(objs[i])) {
            printf("Original sugar value incorrect after duplication:\n");
            printf("Expected Value=%f, Actual Value=%f\n\n", sug, get_sugar(objs[i]));
            fail = 1;
        }
    }

    if(!fail) printf("All Extra Nutrition Info Duplication Tests Passed\n");
}
void enutri_copy_test(float *sat_vals, float *trans_vals, float *chol_vals, float *sod_vals, 
                float *fiber_vals, float *sug_vals, extra_nutri_info **objs, extra_nutri_info **objs2, int num) {
    int fail = 0;
    // Test Object Copying
    float sat, trans, chol, sodium, fiber, sugar;
    for(int i=0; i<num; i++) {
        sat    = (sat_vals[i] < 0) ? -1.0 : sat_vals[i];
        trans  = (trans_vals[i] < 0) ? -1.0 : trans_vals[i];
        chol   = (chol_vals[i] < 0) ? -1.0 : chol_vals[i];
        sodium = (sod_vals[i] < 0) ? -1.0 : sod_vals[i];
        fiber  = (fiber_vals[i] < 0) ? -1.0 : fiber_vals[i];
        sugar  =  (sug_vals[i] < 0) ? -1.0 : sug_vals[i];

        // If copy fails skip value checks
        if(!copy_extra_nutri_info(objs2[num-1-i], objs[num-1-i])) { 
            printf("Unable to copy extra nutritional info object with the following values:\n");
            printf("sat_fat=%f, trans_fat=%f, cholesterol=%f, ", sat_vals[i], trans_vals[i], chol_vals[i]);
            printf("sodium=%f, fiber=%f, sugar=%f\n\n", sod_vals[i], fiber_vals[i], sug_vals[i]);
            fail = 1;
            continue;
        }

        if(sat    != get_sat_fat(objs[i])) {
            printf("Original sat_fat value incorrect after copying:\n");
            printf("Expected Value=%f\t Actual Value=%f\n\n", sat, get_sat_fat(objs[i]));
            fail = 1;
        }
        if(trans  != get_trans_fat(objs[i])) {
            printf("Original trans_fat value incorrect after copying:\n");
            printf("Expected Value=%f\t Actual Value=%f\n\n", trans, get_trans_fat(objs[i]));
            fail = 1;
        }
        if(chol   != get_cholesterol(objs[i])) {
            printf("Original cholesterol value incorrect after copying:\n");
            printf("Expected Value=%f\t Actual Value=%f\n\n", chol, get_cholesterol(objs[i]));
            fail = 1;
        }
        if(sodium != get_sodium(objs[i])) {
            printf("Original sodium value incorrect after copying:\n");
            printf("Expected Value=%f\t Actual Value=%f\n\n", sodium, get_sodium(objs[i]));
            fail = 1;
        }
        if(fiber  != get_fiber(objs[i])) {
            printf("Original fiber value incorrect after copying:\n");
            printf("Expected Value=%f\t Actual Value=%f\n\n", fiber, get_fiber(objs[i]));
            fail = 1;
        }
        if(sugar  != get_sugar(objs[i])) {
            printf("Original sugar value incorrect after copying:\n");
            printf("Expected Value=%f\t Actual Value=%f\n\n", sugar, get_sugar(objs[i]));
            fail = 1;
        }

        if(sat    != get_sat_fat(objs2[i])) {
            printf("Copied sat_fat value incorrect");
            printf("Expected Value=%f\t Actual Value=%f\n\n", sat, get_sat_fat(objs2[i]));
            fail = 1;
        }
        if(trans  != get_trans_fat(objs2[i])) {
            printf("Copied trans_fat value incorrect");
            printf("Expected Value=%f\t Actual Value=%f\n\n", trans, get_trans_fat(objs2[i]));
            fail = 1;
        }
        if(chol   != get_cholesterol(objs2[i])) {
            printf("Copied cholesterol value incorrect");
            printf("Expected Value=%f\t Actual Value=%f\n\n", chol, get_cholesterol(objs2[i]));
            fail = 1;
        }
        if(sodium != get_sodium(objs2[i])) {
            printf("Copied sodium value incorrect");
            printf("Expected Value=%f\t Actual Value=%f\n\n", sodium, get_sodium(objs2[i]));
            fail = 1;
        }
        if(fiber  != get_fiber(objs2[i])) {
            printf("Copied fiber value incorrect");
            printf("Expected Value=%f\t Actual Value=%f\n\n", fiber, get_fiber(objs2[i]));
            fail = 1;
        }
        if(sugar  != get_sugar(objs2[i])) {
            printf("Copied sugar value incorrect");
            printf("Expected Value=%f\t Actual Value=%f\n\n", sugar, get_sugar(objs2[i]));
            fail = 1;
        }
    }
    
    // Test Copying Values to self
    for(int i=0; i<num; i++) {
        sat    = get_sat_fat(objs2[i]);
        trans  = get_trans_fat(objs2[i]);
        chol   = get_cholesterol(objs2[i]);
        sodium = get_sodium(objs2[i]);
        fiber  = get_fiber(objs2[i]);
        sugar = get_sugar(objs2[i]);

        if(!copy_extra_nutri_info(objs2[i], objs2[i])) {
            printf("Unable to copy extra nutritional info object to itself with the following values:\n");
            printf("sat_fat=%f, trans_fat=%f, cholesterol=%f, ", sat_vals[i], trans_vals[i], chol_vals[i]);
            printf("sodium=%f, fiber=%f, sugar=%f\n\n", sod_vals[i], fiber_vals[i], sug_vals[i]);
            fail = 1; 
            continue;
        }

        if(sat != get_sat_fat(objs2[i])) {
            printf(" Value incorrect when copying nutritional value to itself:\n");
            printf("Expected Value=%f\t Actual Value=%f\n\n", sat, get_sat_fat(objs[i]));
            fail = 1;
        }
        if(trans != get_trans_fat(objs2[i])) {
            printf(" Value incorrect when copying nutritional value to itself:\n");
            printf("Expected Value=%f\t Actual Value=%f\n\n", trans, get_trans_fat(objs[i]));
            fail = 1;
        }
        if(chol != get_cholesterol(objs2[i])) {
            printf(" Value incorrect when copying nutritional value to itself:\n");
            printf("Expected Value=%f\t Actual Value=%f\n\n", chol, get_chol(objs[i]));
            fail = 1;
        }
        if(sodium != get_sodium(objs2[i])) {
            printf(" Value incorrect when copying nutritional value to itself:\n");
            printf("Expected Value=%f\t Actual Value=%f\n\n", sodium, get_sodium(objs[i]));
            fail = 1;
        }
        if(fiber != get_fiber(objs2[i])) {
            printf(" Value incorrect when copying nutritional value to itself:\n");
            printf("Expected Value=%f\t Actual Value=%f\n\n", fiber, get_fiber(objs[i]));
            fail = 1;
        }
        if(sugar != get_sugar(objs2[i])) {
            printf("Sugar Value incorrect when copying nutritional value to itself:\n");
            printf("Expected Value=%f\t Actual Value=%f\n\n", sugar, get_sugar(objs[i]));
            fail = 1;
        }
    }

    if(!fail) printf("All Extra Nutritional Info Copy Tests Passed\n");
}
void enutri_setter_tests(float *sat_vals, float *trans_vals, float *chol_vals, float *sod_vals, 
                float *fiber_vals, float *sug_vals, extra_nutri_info **info_list, int num) {
    int fail = 0;

    // Test Setters
    float sat, trans, chol, sodium, fiber, sugar;
    for(int i=0; i<num; i++) {
        sat    = (sat_vals[i] < 0)   ? -1.0 : sat_vals[i];
        trans  = (trans_vals[i] < 0) ? -1.0 : trans_vals[i];
        chol   = (chol_vals[i] < 0)  ? -1.0 : chol_vals[i];
        sodium = (sod_vals[i] < 0)   ? -1.0 : sod_vals[i];
        fiber  = (fiber_vals[i] < 0) ? -1.0 : fiber_vals[i];
        sugar  = (sug_vals[i] < 0)   ? -1.0 : sug_vals[i];

        set_sat_fat(info_list[num-1-i], sat);
        set_trans_fat(info_list[num-1-i], trans);
        set_cholesterol(info_list[num-1-i], chol);
        set_sodium(info_list[num-1-i], sodium);
        set_fiber(info_list[num-1-i], fiber);
        set_sugar(info_list[num-1-i], sugar);

        if(sat    != get_sat_fat(info_list[i])) {
            printf("Sat_fat Value incorrect after setter used\n");
            printf("Expected Value=%f\t Actual Value=%f\n\n", sat, get_sat_fat(objs[i]));
            fail = 1;
        }
        if(trans  != get_trans_fat(info_list[i])) {
            printf("Trans_fat Value incorrect after setter used\n");
            printf("Expected Value=%f\t Actual Value=%f\n\n", trans, get_trans_fat(objs[i]));
            fail = 1;
        }
        if(chol   != get_cholesterol(info_list[i])) {
            printf("Cholesterol Value incorrect after setter used\n");
            printf("Expected Value=%f\t Actual Value=%f\n\n", chol, get_cholesterol(objs[i]));
            fail = 1;
        }
        if(sodium != get_sodium(info_list[i])) {
            printf("Sodium Value incorrect after setter used\n");
            printf("Expected Value=%f\t Actual Value=%f\n\n", sodium, get_sodium(objs[i]));
            fail = 1;
        }
        if(fiber  != get_fiber(info_list[i])) {
            printf("Fiber Value incorrect after setter used\n");
            printf("Expected Value=%f\t Actual Value=%f\n\n", fiber, get_fiber(objs[i]));
            fail = 1;
        }
        if(sugar  != get_sugar(info_list[i])) {
            printf("Sugar Value incorrect after setter used\n");
            printf("Expected Value=%f\t Actual Value=%f\n\n", sugar, get_sugar(objs[i]));
            fail = 1;
        }
    }

    if(!fail) printf("All Extra Nutritional Info Setter Tests Passed");
}
void enutri_null_tests(extra_nutri_info *info) {
    int fail = 0;
    if(duplicate_extra_nutri_info(NULL)) fail = 1;

    if(copy_extra_nutri_info(NULL, NULL)) fail = 1;
    if(copy_extra_nutri_info(info, NULL)) fail = 1;
    if(copy_extra_nutri_info(NULL, info)) fail = 1;

    if(get_sat_fat(NULL) != -1.0f)      fail = 1;
    if(get_trans_fat(NULL) != -1.0f)    fail = 1;
    if(get_cholesterol(NULL) != -1.0f)  fail = 1;
    if(get_sodium(NULL) != -1.0f)       fail = 1;
    if(get_fiber(NULL) != -1.0f)        fail = 1;
    if(get_sugar(NULL) != -1.0f)        fail = 1;

    // No return values. Failure may or may not cause faults
    set_sat_fat(NULL, 0.0f);
    set_tran_fat(NULL, 0.0f);
    set_cholesterol(NULL, 0.0f);
    set_sodium(NULL, 0.0f);
    set_fiber(NULL, 0.0f);
    set_sugar(NULL, 0.0f);
    destroy_extra_nutri_info(NULL);

    if(!fail) printf("All Extra Nutritional Info NULL Tests Passes\n");

}

void enutri_tests() {
    // Test a variety of values. Positive, negative, Zero and Near Zero
    // Use seperate values for each property in a given object
    static int num = 10;
    float sat_vals[]    = { -15.6f, -13.7f, 12.0f,  01.0f, 0.80f, -0.6f,  0.00f, -1.000f, 13.50f, 6.600f };
    float trans_vals[]  = { -11.0f,  0.00f, 1.00f,  0.99f, 10.0f, -1.0f, -0.99f, 12.000f, -99.0f, 7.500f };
    float chol_vals[]   = { 16.00f,  1.00f, 0.99f, -0.99f, 0.00f, -1.0f, -0.05f, -80.00f, 12.50f, -10.7f };
    float sodium_vals[] = {  1.00f, -12.0f, 0.00f,  12.0f, -1.0f, 0.50f, -0.11f, 19.600f, -19.5f, 100.0f };
    float fiber_vals[]  = { 99.0f,  -13.0f, 0.00f, -12.5f, 12.5f, 1.00f, -1.00f, -0.005f, 0.012f, 86.00f };
    float sugar_vals[]  = { 123.4f, -1.00f, -1.0f, 0.000f, 1.00f, -0.05f, 0.50f, -123.4f, 0.104f, -15.0f };
    extra_nutri_info *objs[]  = { NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL };
    extra_nutri_info *objs2[] = { NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL };
    extra_nutri_info *objs3[] = { NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL };

    enutri_creation_tests(sat_vals, trans_vals, chol_vals, sodium_vals, fiber_vals, sugar_vals, objs, num);
    enutri_duplication_tests(sat_vals, trans_vals, chol_vals, sodium_vals, fiber_vals, sugar_vals, objs, objs2, objs3, num);
    enutri_copy_test(sat_vals, trans_vals, chol_vals, sodium_vals, fiber_vals, sugar_vals, objs, objs2, num);
    enutri_setter_tests(sat_vals, trans_vals, chol_vals, sodium_vals, fiber_vals, sugar_vals, objs, num);
    enutri_null_tests(objs[0]); // TODO Call this in a seperate thread or process incase it crashes


    // Destroy Remaining Objects and return
    cleanup:
    for(int i=0; i<num; i++) { 
        destroy_extra_nutri_info(objs[i]);
        destroy_extra_nutri_info(objs2[i]);
        destroy_extra_nutri_info(objs3[i]);
    }
    return NULL;
}

void *vitamin_tests(void *arg) {
    static int num = 10;
    float vitd_vals[] = { -15.6f, -13.7f, 12.0f,  01.0f, 0.80f, -0.6f,  0.00f, -1.000f, 13.50f, 6.600f };
    float calc_vals[] = { 16.00f,  1.00f, 0.99f, -0.99f, 0.00f, -1.0f, -0.05f, -80.00f, 12.50f, -10.7f };
    float iron_vals[] = { 123.4f, -1.00f, -1.0f, 0.000f, 1.00f, -0.05f, 0.50f, -123.4f, 0.104f, -15.0f };
    float pot_vals[]  = {  1.00f, -12.0f, 0.00f,  12.0f, -1.0f, 0.50f, -0.11f, 19.600f, -19.5f, 100.0f };
    vitamin_info *objs  = { NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL };
    vitamin_info *objs2 = { NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL };
    vitamin_info *objs3 = { NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL };

    vit_creation_tests();
    vit_duplication_tests();
    vit_copy_tests();
    vit_setter_tests();
    vit_null_tests();


    // Destroy Remaining Objects and return
    cleanup:
    for(int i=0; i<num; i++) { 
        destroy_extra_nutri_info(objs[i]);
        destroy_extra_nutri_info(objs2[i]);
        destroy_extra_nutri_info(objs3[i]);
    }
    return NULL;
}


void *ingred_tests(void *arg) {
    return NULL;
}


void *ingred_list_tests(void *arg) {
    return NULL;
}


int main(int args, char **argv) {
    nutri_tests();
    enutri_tests();
}
