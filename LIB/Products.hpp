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
<<<<<<< HEAD
#include <iostream>
=======
#include <stdio.h>
#include <string>

>>>>>>> 5e6f0efc516e7ec124f615da9de52053c16d8ee2
using namespace std;

typedef enum ProductCategory{Soda,Water,Juice,None}      ProductCategory; // enum to store the category of the product

// class Product to store the product data and functions to get and set the product data

class Product
{
public:

    // constructor
    Product();
<<<<<<< HEAD
    //Product(string name, f8 price, u32 quantity, time_t expiryDate, ProductCategory category);
    Product(string name, f8 price, u32 quantity, tm expiryDate, ProductCategory category);
=======
>>>>>>> 5e6f0efc516e7ec124f615da9de52053c16d8ee2

    Product(string name, float price, int quantity, time_t expiryDate, ProductCategory category);
    Product(string name, float price, int quantity, tm expiryDate, ProductCategory category);
    // destructor
    ~Product();  

    // function to set the product name
    void setName(string name);
<<<<<<< HEAD

=======
>>>>>>> 5e6f0efc516e7ec124f615da9de52053c16d8ee2
    // function to set the product price
    void setPrice(float price);
    // function to set the product quantity
    void setQuantity(int quantity);
    // function to set the product expiry date
    void setExpiryDate(time_t expiryDate);  // time_t is a typedef of long int to store the time in seconds 
    //void setExpiryDate(tm expiryDate);     // tm is a struct to store the time in year, month, day, hour, minute, second

    // function to set the category of the product
    void setCategory(ProductCategory category);

    // function to get the product name
    string getName();
<<<<<<< HEAD

=======
>>>>>>> 5e6f0efc516e7ec124f615da9de52053c16d8ee2
    // function to get the product price
    float getPrice();
    // function to get the product quantity
    int getQuantity();
    // function to get time to expiry date
    f8 getTimeToExpiryDate();

    // function to get the category of the product
    ProductCategory getCategory();

private:
    // variable to store the product name
    string name;
<<<<<<< HEAD

=======
>>>>>>> 5e6f0efc516e7ec124f615da9de52053c16d8ee2
    // variable to store the product price
    float price;
    // variable to store the product quantity
    int quantity;

    // variable to store the product expiry date
    time_t expiryDate;

    // variable to store the category of the product
    ProductCategory category;
};



#endif // PRODUCT_HPP_