/*******************************************************************************************************************/
/************** AUTHOR:             ********************************************************************************/
/************** DATE: 12/4/2023     ********************************************************************************/
/************** VERSION: 0.1        ********************************************************************************/
/************** FILE: STD_TYPES.h   ********************************************************************************/
/*******************************************************************************************************************/

// This file contains the standard types used in the project to make the code more readable and portable to other platforms and compilers 
#ifndef STD_TYPES_H_
#define STD_TYPES_H_

typedef unsigned char          u8;
typedef unsigned short         u16;
typedef unsigned int           u32;
typedef unsigned long          u64;


typedef  signed char           s8;
typedef  signed short          s16;
typedef  signed int            s32;
typedef  signed long           s64;

typedef  float                 f8;
typedef  double                f46;
typedef  long double           f96;

typedef  u8                    Std_ReturnType; // used to return the status of the function 

#define E_OK                   (Std_ReturnType)1 // used to return the status of the function if it is successful
#define E_NOT_OK               (Std_ReturnType)0 // used to return the status of the function if it is not successful


#endif // STD_TYPES_H_