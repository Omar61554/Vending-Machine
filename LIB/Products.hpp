/*******************************************************************************************************************/
/************** AUTHOR: AMIN FADEL  ********************************************************************************/
/************** DATE: 12/7/2023     ********************************************************************************/
/************** VERSION: 0.1        ********************************************************************************/
/************** FILE:  Products.hpp ********************************************************************************/
/*******************************************************************************************************************/

#ifndef PRODUCT_HPP_
#define PRODUCT_HPP_

#include "../../LIB/STD_TYPES.hpp"
#include <time.h>

typedef enum ProductCategory
{
    Soda,
    Water,
    Juice,
    None
} ProductCategory;

// class Product to store the product data and functions to get and set the product data

class Product
{
public:
    // constructor
    Product();
    Product(u8 *name, f8 price, u8 quantity, time_t expiryDate, ProductCategory category);
    // destructor
    ~Product();
    // function to set the product name
    void setName(u8 *name);
    // function to set the product price
    void setPrice(f8 price);
    // function to set the product quantity
    void setQuantity(u8 quantity);
    // function to set the product expiry date
    void setExpiryDate(time_t expiryDate);
    // function to set the category of the product
    void setCategory(ProductCategory category);
    // function to get the product name
    u8 *getName();
    // function to get the product price
    f8 getPrice();
    // function to get the product quantity
    u8 getQuantity();
    // function to get the product expiry date
    time_t getExpiryDate();
    // function to get the category of the product
    ProductCategory getCategory();

private:
    // variable to store the product name
    u8 *name;
    // variable to store the product price
    f8 price;
    // variable to store the product quantity
    u8 quantity;
    // variable to store the product expiry date
    time_t expiryDate;
    // variable to store the category of the product
    ProductCategory category;
};

#endif // PRODUCT_HPP_