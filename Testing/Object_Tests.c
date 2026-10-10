#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

#include "../Food Tracking/Objects/nutritional_info.h"
#include "../Food Tracking/Objects/extra_nutritional_info.h"
#include "../Food Tracking/Objects/vitamins.h"
#include "../Food Tracking/Objects/ingredients.h"
#include "../Food Tracking/Objects/ingredients_list.h"
#include "../Food Tracking/Objects/meals.h"


void nutri_creation_tests(float *cal_list, float *protein_list, float *carbs_list, 
                         float *fat_list, nutri_info **info_list, int num) {
    int fail = 0;
    
    float cal, protein, carbs, fat;
    for(int i=0; i<num; i++) {
        cal     = (cal_list[i] < 0)     ? -1.0 : cal_list[i];
        protein = (protein_list[i] < 0) ? -1.0 : protein_list[i];
        carbs   = (carbs_list[i] < 0)   ? -1.0 : carbs_list[i];
        fat     = (fat_list[i] < 0)     ? -1.0 : fat_list[i];

        info_list[i] = create_nutri_info(cal_list[i], protein_list[i], carbs_list[i], fat_list[i]);
        if(!info_list[i]) { 
            printf("Unable to create nutritional info object with the following values:\n");
            printf("cal=%f, protein=%f, carbs=%f, fat=%f\n\n", cal_list[i], protein_list[i], carbs_list[i], fat_list[i]);
            fail = 1;
            continue;
        }
        
        if(cal != get_cal(info_list[i])) {
            printf("Calorie value incorrect after creation:\n");
            printf("Expected Value=%f\t Actual Value=%f\n\n", cal, get_cal(info_list[i]));
            fail = 1;
        }
        if(protein != get_protein(info_list[i])) {
            printf("Protein value incorrect after creation:\n");
            printf("Expected Value=%f\t Actual Value=%f\n\n", protein, get_protein(info_list[i]));
            fail = 1;
        }
        if(carbs != get_carbs(info_list[i])) {
            printf("Carbs value incorrect after creation:\n");
            printf("Expected Value=%f\t Actual Value=%f\n\n", carbs, get_carbs(info_list[i]));
            fail = 1;
        }
        if(fat != get_fat(info_list[i])) {
            printf("Fat value incorrect after creation: ");
            printf("Expected Value=%f\t Actual Value=%f\n\n", fat, get_fat(info_list[i]));
            fail = 1;
        }
    }
    if(!fail) printf("All Nutritional Creation Tests Passed\n");
}
void nutri_duplication_tests (float *cal_list, float *protein_list, float *carbs_list, 
                             float *fat_list, nutri_info **info_list, 
                             nutri_info **info_list2, nutri_info **info_list3, int num) {
    /**
     * TODO: Add Tests to check that values in one object are not affected by changes in children or parents 
     */
    int fail = 0;

    // Test Duplicated Values are correct
    float cal, protein, carbs, fat;
    for(int i=0; i<num; i++) {
        cal     = (cal_list[i] < 0)     ? -1.0 : cal_list[i];
        protein = (protein_list[i] < 0) ? -1.0 : protein_list[i];
        carbs   = (carbs_list[i] < 0)   ? -1.0 : carbs_list[i];
        fat     = (fat_list[i] < 0)     ? -1.0 : fat_list[i];

        info_list2[i] = duplicate_nutri_info(info_list[i]);
        if(!info_list2[i]) {
            printf("Unable to duplicate nutritional info object with the following values:\n");
            printf("cal=%f, protein=%f, carbs=%f, fat=%f\n", cal_list[i], protein_list[i], carbs_list[i], fat_list[i]);
            fail = 1;
            continue;
        };

        if(cal != get_cal(info_list2[i])) {
            printf("Calorie value incorrect in duplicated object");
            printf("Expected Value=%f\t Actual Value=%f\n\n", cal, get_cal(info_list2[i]));
            fail = 1;
        }
        if(protein != get_protein(info_list2[i])) {
            printf("Protein value incorrect in duplicated object");
            printf("Expected Value=%f\t Actual Value=%f\n\n", protein, get_protein(info_list2[i]));
            fail = 1;
        }
        if(carbs != get_carbs(info_list2[i])) {
            printf("Carbs value incorrect in duplicated object");
            printf("Expected Value=%f\t Actual Value=%f\n\n", carbs, get_carbs(info_list2[i]));
            fail = 1;
        }
        if(fat != get_fat(info_list2[i])) {
            printf("Fat value incorrect in duplicated object");
            printf("Expected Value=%f\t Actual Value=%f\n\n", fat, get_fat(info_list2[i]));
            fail = 1;
        }
    }

    // Test Original values are correct after duplication
    for(int i=0; i<num; i++) {
        cal     = get_cal(info_list[i]);
        protein = get_protein(info_list[i]);
        carbs   = get_carbs(info_list[i]);
        fat     = get_fat(info_list[i]);

        info_list3[i] = duplicate_nutri_info(info_list[i]);
        if(!info_list3[i]) {
            printf("Unable to duplicate nutritional info object with the following values:\n");
            printf("cal=%f, protein=%f, carbs=%f, fat=%f\n", cal_list[i], protein_list[i], carbs_list[i], fat_list[i]);
            fail = 1;
            continue;
        }

        if(cal != get_cal(info_list[i])) {
            printf("Original calorie value incorrect after duplication:\n");
            printf("Expected Value=%f\t Actual Value=%f\n\n", cal, get_cal(info_list[i]));
            fail = 1;
        } 
        if(protein != get_protein(info_list[i])) {
            printf("Original protein value incorrect after duplication:\n");
            printf("Expected Value=%f\t Actual Value=%f\n\n", cal, get_cal(info_list[i]));
            fail = 1;
        }
        if(carbs != get_carbs(info_list[i])) {
            printf("Original carbs value incorrect after duplication:\n");
            printf("Expected Value=%f\t Actual Value=%f\n\n", cal, get_cal(info_list[i]));
            fail = 1;
        }
        if(fat != get_fat(info_list[i])) {
            printf("Original fat value incorrect after duplication:\n");
            printf("Expected Value=%f\t Actual Value=%f\n\n", cal, get_cal(info_list[i]));
            fail = 1;
        }
    }
    

    if(!fail) printf("All Nutritional Info Duplication Tests Passed\n");
}
void nutri_copy_tests(float *cal_list, float *protein_list, float *carbs_list, float *fat_list,
                     nutri_info **info_list, nutri_info **info_list2, int num) {
    int fail = 0;
    // Test Object Copying
    float cal, protein, carbs, fat;
    for(int i=0; i<num; i++) {
        cal     = (cal_list[i] < 0)     ? -1.0 : cal_list[i];
        protein = (protein_list[i] < 0) ? -1.0 : protein_list[i];
        carbs   = (carbs_list[i] < 0)   ? -1.0 : carbs_list[i];
        fat     = (fat_list[i] < 0)     ? -1.0 : fat_list[i];

        if(!copy_nutri_info(info_list2[(num-1)-i], info_list[i])) { fail = 1; continue; }
        
        if(cal     != get_cal(info_list[i]))     fail = 1;
        if(protein != get_protein(info_list[i])) fail = 1;
        if(carbs   != get_carbs(info_list[i]))   fail = 1;
        if(fat     != get_fat(info_list[i]))     fail = 1;

        if(cal     != get_cal(info_list2[num-1-i]))     fail = 1;
        if(protein != get_protein(info_list2[num-1-i])) fail = 1;
        if(carbs   != get_carbs(info_list2[num-1-i]))   fail = 1;
        if(fat     != get_fat(info_list2[num-1-i]))     fail = 1;
    }

    // Test Coping Values to self
    for(int i=0; i<num; i++) {
        cal     = get_cal(info_list2[i]);
        protein = get_protein(info_list2[i]);
        carbs   = get_carbs(info_list2[i]);
        fat     = get_fat(info_list2[i]);

        if(!copy_nutri_info(info_list2[i], info_list2[i])) fail = 1;

        if(cal     != get_cal(info_list2[i]))     fail = 1;
        if(protein != get_protein(info_list2[i])) fail = 1;
        if(carbs   != get_carbs(info_list2[i]))   fail = 1;
        if(fat     != get_fat(info_list2[i]))     fail = 1;
    }

    if(!fail) printf("All Nutritional Info Copy Tests Passed\n");
}
void nutri_setter_tests(float *cal_list, float *protein_list, float *carbs_list, 
                         float *fat_list, nutri_info **info_list, int num) {
    int fail = 0;

    // Test Setters
    float cal, protein, carbs, fat;
    for(int i=0; i<num; i++) {
        cal     = (cal_list[i] < 0)     ? -1.0 : cal_list[i];
        protein = (protein_list[i] < 0) ? -1.0 : protein_list[i];
        carbs   = (carbs_list[i] < 0)   ? -1.0 : carbs_list[i];
        fat     = (fat_list[i] < 0)     ? -1.0 : fat_list[i];

        set_cal(info_list[num-1-i], cal);
        set_protein(info_list[num-1-i], protein);
        set_carbs(info_list[num-1-i], carbs);
        set_fat(info_list[num-1-i], fat);

        if(cal     != get_cal(info_list[i]))     fail = 1;
        if(protein != get_protein(info_list[i])) fail = 1;
        if(carbs   != get_carbs(info_list[i]))   fail = 1;
        if(fat     != get_fat(info_list[i]))     fail = 1;
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
    float cal_list[]     = { -10.0f, -1.0f, -0.99f, 0.0f, 0.99f, 1.0f, 10.0f };
    float protein_list[] = { -11.0f, 0.0f, 1.0f, 0.99f, 10.0f, -1.0f, -0.99f };
    float carbs_list[]   = { 16.0f, 1.0f, 0.99f, .99f, 0.0f, -1.0f, -0.05f, -80.0f };
    float fat_list[]     = { 1.0f, -12.0f, 0.0f, 12.0f, -1.0f, 0.5f, -0.11f };
    nutri_info *info_list[] = { NULL, NULL, NULL, NULL, NULL, NULL, NULL };
    nutri_info *info_list2[] = { NULL, NULL, NULL, NULL, NULL, NULL, NULL };
    nutri_info *info_list3[] = { NULL, NULL, NULL, NULL, NULL, NULL, NULL };

    nutri_creation_tests(cal_list, protein_list, carbs_list, fat_list, info_list, num);
    nutri_duplication_tests(cal_list, protein_list, carbs_list, fat_list, info_list, info_list2, info_list3, num);
    nutri_copy_tests(cal_list, protein_list, carbs_list, fat_list, info_list, info_list2, num);
    nutri_setter_tests(cal_list, protein_list, carbs_list, fat_list, info_list, num);
    nutri_null_tests(info_list[0]);

    // Destroy Remaining Objects and return
    for(int i=0; i<num; i++) { 
        destroy_nutri_info(info_list[i]);
        destroy_nutri_info(info_list2[i]);
        destroy_nutri_info(info_list3[i]);
    }
    return NULL;
}

void enutri_creation_tests(float *sat_fat_list, float *trans_fat_list, float *cholesterol_list,
                          float *sodium_list, float *fiber_list, float *sugar_list, 
                          extra_nutri_info **info_list, int num) {
        int fail = 0;

        float sat_fat, trans_fat, chol, sodium, fiber, sugar;
        for(int i=0; i<num; i++) {
            sat_fat   = (sat_fat_list[i] < 0)     ? -1.0 : sat_fat_list[i];
            trans_fat = (trans_fat_list[i] < 0)   ? -1.0 : trans_fat_list[i];
            chol      = (cholesterol_list[i] < 0) ? -1.0 : cholesterol_list[i];
            sodium    = (sodium_list[i] < 0)      ? -1.0 : sodium_list[i];
            fiber     = (fiber_list[i] < 0)       ? -1.0 : fiber_list[i];
            sugar     = (sugar_list[i] < 0)       ? -1.0 : sugar_list[i];

            *(info_list + i) = create_extra_nutri_info(sat_fat_list[i], trans_fat_list[i], 
                cholesterol_list[i], sodium_list[i], fiber_list[i], sugar_list[i]);
            if(!info_list[i]) { 
                printf("Unable to create extra_nutri_info object with the following values:\n");
                printf("sat_fat=%f, trans_fat=%f, cholesterol=%f, ", sat_fat_list[i], trans_fat_list[i], cholesterol_list[i]);
                printf("sodium=%f, fiber=%f, and sugar=%f/n", sodium_list[i], fiber_list[i], sugar_list[i]);
                fail = 1;
                continue;
            }

            if(sat_fat != get_sat_fat(info_list[i])) {
                printf("Saturated Fat value incorrect after creation:\n");
                printf("Expected Value=%f\t Actual Value=%f\n\n", sat_fat, get_sat_fat(info_list[i]));
                fail = 1;
            } 
            if(trans_fat != get_trans_fat(info_list[i])) {
                printf("Trans Fat value incorrect after creation:\n");
                printf("Expected Value=%f\t Actual Value=%f\n\n",trans_fat , get_trans_fat(info_list[i]));
                fail = 1;
            }
            if(chol != get_cholesterol(info_list[i])) {
                printf("Cholesterol value incorrect after creation:\n");
                printf("Expected Value=%f\t Actual Value=%f\n\n", chol, get_cholesterol(info_list[i]));
                fail = 1;
            } 
            if(sodium != get_sodium(info_list[i])) {
                printf("Sodium value incorrect after creation:\n");
                printf("Expected Value=%f\t Actual Value=%f\n\n", sodium, get_sodium(info_list[i]));
                fail = 1;
            } 
            if(fiber != get_fiber(info_list[i])) {
                printf("Fiber value incorrect after creation:\n");
                printf("Expected Value=%f\t Actual Value=%f\n\n", fiber, get_fiber(info_list[i]));
                fail = 1;
            } 
            if(sugar != get_sugar(info_list[i])) {
                printf("Sugar value incorrect after creation:\n");
                printf("Expected Value=%f\t Actual Value=%f\n\n", sugar, get_sugar(info_list[i]));
                fail = 1;
            }
        }
        
        if(fail == 1) printf("All Extra Nutritional Info Creation Tests Passed\n");
    }
void enutri_duplication_tests(float *sat_fat_list, float *trans_fat_list, float *cholesterol_list,
                          float *sodium_list, float *fiber_list, float *sugar_list, extra_nutri_info **info_list,
                          extra_nutri_info **info_list2, extra_nutri_info **info_list3, int num) {
    int fail = 0;

    // Test Duplicated Values are correct
    float sat_fat, trans_fat, chol, sodium, fiber, sugar;
    for(int i=0; i<num; i++) {
        sat_fat   = (sat_fat_list[i] < 0)     ? -1.0 : sat_fat_list[i];
        trans_fat = (trans_fat_list[i] < 0)   ? -1.0 : trans_fat_list[i];
        chol      = (cholesterol_list[i] < 0) ? -1.0 : cholesterol_list[i];
        sodium    = (sodium_list[i] < 0)      ? -1.0 : sodium_list[i];
        fiber     = (fiber_list[i] < 0)       ? -1.0 : fiber_list[i];
        sugar     = (sugar_list[i] < 0)       ? -1.0 : sugar_list[i];

        info_list2[i] = duplicate_extra_nutri_info(info_list[i]);
        if(!info_list2[i]) {
            printf("Unable to duplicate extra nutritional info object with the following values:\n");
            printf("sat_fat=%f, trans_fat=%f, chol=%f, ", sat_fat_list[i], trans_fat_list[i], cholesterol_list[i]);
            printf("sodium=%f, fiber=%f, sugar=%f\n\n", sodium_list[i], fiber_list[i], sugar_list[i]);
            fail = 1;
            continue;
        };

        if(sat_fat != get_sat_fat(info_list2[i])) {
            printf("Saturated fat value incorrect in duplicated object");
            printf("Expected Value=%f\t Actual Value=%f\n\n", sat_fat, get_sat_fat(info_list2[i]));
            fail = 1;
        }
        if(trans_fat != get_trans_fat(info_list2[i])) {
            printf("Trans Fat value incorrect in duplicated object");
            printf("Expected Value=%f\t Actual Value=%f\n\n", trans_fat, get_trans_fat(info_list2[i]));
            fail = 1;
        }
        if(chol != get_cholesterol(info_list2[i])) {
            printf("Cholesterol value incorrect in duplicated object");
            printf("Expected Value=%f\t Actual Value=%f\n\n", chol, get_cholesterol(info_list2[i]));
            fail = 1;
        }
        if(sodium != get_sodium(info_list2[i])) {
            printf("Sodium value incorrect in duplicated object");
            printf("Expected Value=%f\t Actual Value=%f\n\n", sodium, get_sodium(info_list2[i]));
            fail = 1;
        }
        if(fiber != get_fiber(info_list2[i])) {
            printf("Fiber value incorrect in duplicated object");
            printf("Expected Value=%f\t Actual Value=%f\n\n", fiber, get_fiber(info_list2[i]));
            fail = 1;
        }
        if(sugar != get_sugar(info_list2[i])) {
            printf("Sugar value incorrect in duplicated object");
            printf("Expected Value=%f\t Actual Value=%f\n\n", sugar, get_sugar(info_list2[i]));
            fail = 1;
        }
    }

    // Test Original values are correct after duplication
    for(int i=0; i<num; i++) {
        sat_fat   = get_sat_fat(info_list[i]);
        trans_fat = get_trans_fat(info_list[i]);
        chol      = get_cholesterol(info_list[i]);
        sodium    = get_sodium(info_list[i]);
        fiber     = get_fiber(info_list[i]);
        sugar     = get_sugar(info_list[i]);

        info_list3[i] = duplicate_extra_nutri_info(info_list[i]);
        if(!info_list[i]) {
            printf("Unable to duplicated nutritional info object with the following values:\n");
            printf("sat_fat=%f, trans_fat=%f, chol=%f, ", sat_fat, trans_fat, chol);
            printf("sodium=%f, fiber=%f, sugar=%f\n\n", sodium, fiber, sugar);
            fail = 1;
            continue;
        }

        if(sat_fat != get_sat_fat(info_list[i])) {
            printf("Original saturated fat value incorrect after duplication:\n");
            printf("Expected Value=%f, Actual Value=%f\n\n", sat_fat, get_sat_fat(info_list[i]));
            fail = 1;
        }
        if(trans_fat != get_trans_fat(info_list[i])) {
            printf("Original trans fat value incorrect after duplication:\n");
            printf("Expected Value=%f, Actual Value=%f\n\n", trans_fat, get_trans_fat(info_list[i]));
            fail = 1;
        }
        if(chol != get_cholesterol(info_list[i])) {
            printf("Original cholesterol value incorrect after duplication:\n");
            printf("Expected Value=%f, Actual Value=%f\n\n", chol, get_cholesterol(info_list[i]));
            fail = 1;
        }
        if(sodium != get_sodium(info_list[i])) {
            printf("Original sodium value incorrect after duplication:\n");
            printf("Expected Value=%f, Actual Value=%f\n\n", sodium, get_sodium(info_list[i]));
            fail = 1;
        }
        if(fiber != get_fiber(info_list[i])) {
            printf("Original fiber value incorrect after duplication:\n");
            printf("Expected Value=%f, Actual Value=%f\n\n", fiber, get_fiber(info_list[i]));
            fail = 1;
        }
        if(sugar != get_sugar(info_list[i])) {
            printf("Original sugar value incorrect after duplication:\n");
            printf("Expected Value=%f, Actual Value=%f\n\n", sugar, get_sugar(info_list[i]));
            fail = 1;
        }
    }

    if(!fail) printf("All Extra Nutrition Info Duplication Tests Passed\n");
}
void enutri_copy_test(float *sat_fat_list, float *trans_fat_list, float *cholesterol_list, float *sodium_list, 
                float *fiber_list, float *sugar_list, extra_nutri_info **info_list, extra_nutri_info **info_list2, int num) {
    int fail = 0;
    // Test Object Copying
    float sat, trans, chol, sodium, fiber, sugar;
    for(int i=0; i<num; i++) {
        sat    = (sat_fat_list[i] < 0) ? -1.0 : sat_fat_list[i];
        trans  = (trans_fat_list[i] < 0) ? -1.0 : trans_fat_list[i];
        chol   = (cholesterol_list[i] < 0) ? -1.0 : cholesterol_list[i];
        sodium = (sodium_list[i] < 0) ? -1.0 : sodium_list[i];
        fiber  = (fiber_list[i] < 0) ? -1.0 : fiber_list[i];
        sugar  =  (sugar_list[i] < 0) ? -1.0 : sugar_list[i];

        // If copy fails skip value checks
        if(!copy_extra_nutri_info(info_list2[num-1-i], info_list[num-1-i])) { fail = 1; continue; };

        if(sat    != get_sat_fat(info_list[i]))     fail=1;
        if(trans  != get_trans_fat(info_list[i]))   fail=1;
        if(chol   != get_cholesterol(info_list[i])) fail=1;
        if(sodium != get_sodium(info_list[i]))      fail=1;
        if(fiber  != get_fiber(info_list[i]))       fail=1;
        if(sugar  != get_sugar(info_list[i]))       fail=1;

        if(sat    != get_sat_fat(info_list2[i]))     fail=1;
        if(trans  != get_trans_fat(info_list2[i]))   fail=1;
        if(chol   != get_cholesterol(info_list2[i])) fail=1;
        if(sodium != get_sodium(info_list2[i]))      fail=1;
        if(fiber  != get_fiber(info_list2[i]))       fail=1;
        if(sugar  != get_sugar(info_list2[i]))       fail=1;
    }
    
    // Test Copying Values to self
    for(int i=0; i<num; i++) {
        sat    = get_sat_fat(info_list2[i]);
        trans  = get_trans_fat(info_list2[i]);
        chol   = get_cholesterol(info_list2[i]);
        sodium = get_sodium(info_list2[i]);
        fiber  = get_fiber(info_list2[i]);
        sugar = get_sugar(info_list2[i]);

        if(!copy_extra_nutri_info(info_list2[i], info_list2[i]));

        if(sat    != get_sat_fat(info_list2[i]))     fail=1;
        if(trans  != get_trans_fat(info_list2[i]))   fail=1;
        if(chol   != get_cholesterol(info_list2[i])) fail=1;
        if(sodium != get_sodium(info_list2[i]))      fail=1;
        if(fiber  != get_fiber(info_list2[i]))       fail=1;
        if(sugar  != get_sugar(info_list2[i]))       fail=1;
    }

    if(!fail) printf("All Extra Nutritional Info Copy Tests Passed\n");
}
void enutri_setter_tests(float *sat_fat_list, float *trans_fat_list, float *cholesterol_list, float *sodium_list, 
                float *fiber_list, float *sugar_list, extra_nutri_info **info_list, int num) {
    int fail = 0;

    // Test Setters
    float sat, trans, chol, sodium, fiber, sugar;
    for(int i=0; i<num; i++) {
        sat    = (sat_fat_list[i] < 0) ? -1.0 : sat_fat_list[i];
        trans  = (trans_fat_list[i] < 0) ? -1.0 : trans_fat_list[i];
        chol   = (cholesterol_list[i] < 0) ? -1.0 : cholesterol_list[i];
        sodium = (sodium_list[i] < 0) ? -1.0 : sodium_list[i];
        fiber  = (fiber_list[i] < 0) ? -1.0 : fiber_list[i];
        sugar  =  (sugar_list[i] < 0) ? -1.0 : sugar_list[i];

        set_sat_fat(info_list[num-1-i], sat);
        set_trans_fat(info_list[num-1-i], trans);
        set_cholesterol(info_list[num-1-i], chol);
        set_sodium(info_list[num-1-i], sodium);
        set_fiber(info_list[num-1-i], fiber);
        set_sugar(info_list[num-1-i], sugar);

        if(sat    != get_sat_fat(info_list[i]))     fail=1;
        if(trans  != get_trans_fat(info_list[i]))   fail=1;
        if(chol   != get_cholesterol(info_list[i])) fail=1;
        if(sodium != get_sodium(info_list[i]))      fail=1;
        if(fiber  != get_fiber(info_list[i]))       fail=1;
        if(sugar  != get_sugar(info_list[i]))       fail=1;
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
    float sat_vals[]     = { -15.6f, -13.7f, 12.0f,  01.0f, 0.80f, -0.6f,  0.00f, -1.000f, 13.50f, 6.600f };
    float trans_vals[]    = { -11.0f,  0.00f, 1.00f,  0.99f, 10.0f, -1.0f, -0.99f, 12.000f, -99.0f, 7.500f };
    float chol_vals[] = { 16.00f,  1.00f, 0.99f, -0.99f, 0.00f, -1.0f, -0.05f, -80.00f, 12.50f, -10.7f };
    float sodium_vals[]      = {  1.00f, -12.0f, 0.00f,  12.0f, -1.0f, 0.50f, -0.11f, 19.600f, -19.5f, 100.0f };
    float fiber_vals[]       = { 99.0f,  -13.0f, 0.00f, -12.5f, 12.5f, 1.00f, -1.00f, -0.005f, 0.012f, 86.00f };
    float sugar_vals[]       = { 123.4f, -1.00f, -1.0f, 0.000f, 1.00f, -0.05f, 0.50f, -123.4f, 0.104f, -15.0f };
    extra_nutri_info *info_list[] = { NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL };
    extra_nutri_info *info_list2[] = { NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL };
    extra_nutri_info *info_list3[] = { NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL };

    enutri_creation_tests(sat_vals, trans_vals, chol_vals, sodium_vals, fiber_vals, sugar_vals, info_list, num);
    enutri_duplication_tests(sat_vals, trans_vals, chol_vals, sodium_vals, fiber_vals, sugar_vals, info_list, info_list2, info_list3, num);
    enutri_copy_test(sat_vals, trans_vals, chol_vals, sodium_vals, fiber_vals, sugar_vals, info_list, info_list2, num);
    enutri_setter_tests(sat_vals, trans_vals, chol_vals, sodium_vals, fiber_vals, sugar_vals, info_list, num);
    enutri_null_tests(info_list[0]);


    // Destroy Remaining Objects and return
    cleanup:
    for(int i=0; i<num; i++) { 
        destroy_extra_nutri_info(info_list[i]);
        destroy_extra_nutri_info(info_list2[i]);
        destroy_extra_nutri_info(info_list3[i]);
    }
    return NULL;
}

void *vitamin_tests(void *arg) {
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
