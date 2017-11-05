#include "unity.h"
#include "MergeSort.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

void setUp(void){}

void tearDown(void){}

void test_MergeSort_given_NULL_expected_NULL(void)
{
 uint8_t *arrIn =  NULL;
 MergeSort(arrIn,0,0);
 TEST_ASSERT_NULL(arrIn);
}

void test_MergeSort_given_3_2_1_expected_1_2_3(void)
{
 uint8_t arrIn[] = {3,2,1};
 int arrSize = sizeof(arrIn)/(sizeof(arrIn[0]));
 uint8_t arrExpected[] = {1,2,3};
 MergeSort(arrIn,0,arrSize-1);
 TEST_ASSERT_EQUAL_UINT8_ARRAY(arrIn, arrExpected, 3);
}

/*           5 8 3 1 9
 *            /     \        <- merge sort
 *         5 8 3    1 9
 *         /  \     / \     <- merge sort
 *      5 8    3   1   9
 *      / \    /            <- merge sort
 *    5   8   /
 *    \  /  /               <- merge(within left sub)
*    5 8  /
 *    \ /                   <- merge(within left sub)
 *    3 5 8   |  1 9
 *      \       /           <- merge left sub with right sub
 *      1 3 5 8 9
 */
void test_MergeSort_given_5_8_3_1_9_expected_1_3_5_8_9(void)
{
 uint8_t arrIn[] = {5,8,3,1,9};
 int arrSize = sizeof(arrIn)/(sizeof(arrIn[0]));
 uint8_t arrExpected[] = {1,3,5,8,9};
 MergeSort(arrIn,0,arrSize-1);
 TEST_ASSERT_EQUAL_UINT8_ARRAY(arrExpected,arrIn ,5);
}


/*        (2)         (1)
 *          \         /
 *             merge
 *               |
 *               v
 *             (1,2)
 */
void test_Merge_given_2_1_expected_12(void)
{
  uint8_t arrayIn[] = {2,1};
 int l = 0;
 int r = 1;
 int m = l + ( r-l )/2;
 uint8_t arrExpected[] = {1,2};
 Merge(arrayIn,l,r,m);
 TEST_ASSERT_EQUAL_UINT8_ARRAY(arrExpected,arrayIn ,2);
}

/*        (2 , 3)    (1)
 *          \         /
 *             merge
 *               |
 *               v
 *            (1,2,3)
 */
void test_Merge_given_2_3_1_expected_123(void)
{
  uint8_t arrayIn[] = {2,3,1}; // Assuming the leftsub is sorted (2,3)
 int l = 0;                    // left index
 int r = 2;
 int m = l + ( r-l )/2;
 uint8_t arrExpected[] = {1,2,3};
 Merge(arrayIn,l,r,m);
 TEST_ASSERT_EQUAL_UINT8_ARRAY(arrExpected,arrayIn ,3);

}

/*        (3,4)      (2,5)
 *          \         /
 *             merge
 *               |
 *               v
 *            (1,2,3)
 */
void test_Merge_given_3_4_2_5_expected_2345(void)
{
  uint8_t arrayIn[] = {3,4,2,5}; // Assuming the leftsub is sorted (3,4)
 int l = 0;                    // left index
 int r = 3;
 int m = l + ( r-l )/2;
 uint8_t arrExpected[] = {2,3,4,5};
 Merge(arrayIn,l,r,m);
 TEST_ASSERT_EQUAL_UINT8_ARRAY(arrExpected,arrayIn ,4);

}
