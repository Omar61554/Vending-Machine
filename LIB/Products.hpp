/*******************************************************************************************************************/
/************** AUTHOR:             ********************************************************************************/
/************** DATE: 12/7/2023     ********************************************************************************/
/************** VERSION: 0.1        ********************************************************************************/
/************** FILE:  Products.hpp ********************************************************************************/
/*******************************************************************************************************************/

#ifndef PRODUCT_HPP_
#define PRODUCT_HPP_

#include "STD_TYPES.hpp"
#include <time.h>
#include <stdio.h>
using namespace std;

typedef enum ProductCategory
{
    Soda,
    Water,
    Juice,
    None
} ProductCategory; // enum to store the category of the product

// class Product to store the product data and functions to get and set the product data

class Product
{
public:

    // constructor
    Product();
    Product(u8 *name, f8 price, u32 quantity, time_t expiryDate, ProductCategory category);
    Product(u8 *name, f8 price, u32 quantity, tm expiryDate, ProductCategory category);

    // destructor
    ~Product();

    // function to set the product name
    void setName(u8 *name);

    // function to set the product price
    void setPrice(f8 price);

    // function to set the product quantity
    void setQuantity(u32 quantity);

    // function to set the product expiry date
    void setExpiryDate(time_t expiryDate); // time_t is a typedef of long int to store the time in seconds 
    void setExpiryDate(tm expiryDate);     // tm is a struct to store the time in year, month, day, hour, minute, second

    // function to set the category of the product
    void setCategory(ProductCategory category);

    // function to get the product name
    u8 *getName();

    // function to get the product price
    f8 getPrice();

    // function to get the product quantity
    u32 getQuantity();

    // function to get time to expiry date
    f8 getTimeToExpiryDate();

    // function to get the category of the product
    ProductCategory getCategory();

private:
    // variable to store the product name
    u8 *name;

    // variable to store the product price
    f8 price;

    // variable to store the product quantity
    u32 quantity;

    // variable to store the product expiry date
    time_t expiryDate;

    // variable to store the category of the product
    ProductCategory category;
};

#endif // PRODUCT_HPP_