/*******************************************************************************************************************/
/************** AUTHOR:             ********************************************************************************/
/************** DATE: 12/8/2023     ********************************************************************************/
/************** VERSION: 0.1        ********************************************************************************/
/************** FILE:  Products.cpp ********************************************************************************/
/*******************************************************************************************************************/



/*this file is the implementation of the main functions */



/******************************************includes*********************************************************/


#include "Products.hpp"


/*******************************************************************************************************************/


// constructor
Product::Product()
{
    // initialize the product name
    name = "NONE";  // 100 is the maximum number of characters in the product name , new is used to allocate memory in the heap instead of the stack to avoid stack overflow 
    // initialize the product price
    price = 0;
    // initialize the product quantity
    quantity = 0;
    // initialize the product expiry date
    expiryDate = time(NULL);
    // initialize the category of the product
    category = None;
}

// constructor
Product::Product(string name, f8 price, u32 quantity, time_t expiryDate, ProductCategory category)
{
    // initialize the product name
    this->name = name;
    // initialize the product price
    this->price = price;
    // initialize the product quantity
    this->quantity = quantity;
    // initialize the product expiry date
    this->expiryDate = expiryDate; 
    // initialize the category of the product
    this->category = category;
}

Product::Product(string name, f8 price, u32 quantity, tm expiryDate, ProductCategory category)
{
    // initialize the product name
    this->name = name;
    // initialize the product price
    this->price = price;
    // initialize the product quantity
    this->quantity = quantity;
    // initialize the product expiry date
    this->expiryDate = mktime(&expiryDate); // mktime is a function to convert tm struct to time_t 
    // initialize the category of the product
    this->category = category;
}

// destructor
Product::~Product()
{
    // delete the product name
    name = "";
    
}

/****************************************************************************************************************************/

//setters



// function to set the product name
void Product::setName(string name)
{
    // set the product name
    this->name = name;
}

// function to set the product price
void Product::setPrice(f8 price)
{
    // set the product price
    this->price = price;
}

// function to set the product quantity
void Product::setQuantity(u32 quantity)
{
    // set the product quantity
    this->quantity = quantity;
}

// function to set the product expiry date
void Product::setExpiryDate(time_t expiryDate)
{
    // set the product expiry date
    this->expiryDate = expiryDate;  
}

// void Product::setExpiryDate(tm expiryDate)
// {
//     tm expiry = expiryDate;
//     expiry.tm_hour = 0;
//     expiry.tm_min = 0;
//     expiry.tm_sec = 0;
//     // set the product expiry date
//     this->expiryDate = mktime(&expiry);
// }

// function to set the category of the product
void Product::setCategory(ProductCategory category)
{
    // set the category of the product
    this->category = category;
}

/****************************************************************************************************************************/

//getters



// function to get the product name
string Product::getName()
{
    // return the product name
    return name;
}

// function to get the product price
f8 Product::getPrice()
{
    // return the product price
    return price;
}

// function to get the product quantity
u32 Product::getQuantity()
{
    // return the product quantity
    return quantity;
}

// function to get time to expiry date
f8 Product::getTimeToExpiryDate()
{
    // return the time to expiry date from now in days
    return difftime(expiryDate, time(NULL)) / (60 * 60 * 24);
}

// function to get the category of the product
ProductCategory Product::getCategory()
{
    // return the category of the product
    return category;
}

