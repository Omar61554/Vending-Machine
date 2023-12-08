/*******************************************************************************************************************/
/************** AUTHOR: AMIN FADEL  ********************************************************************************/
/************** DATE: 12/8/2023     ********************************************************************************/
/************** VERSION: 0.1        ********************************************************************************/
/************** FILE:  Products.cpp ********************************************************************************/
/*******************************************************************************************************************/

#include "Products.hpp"

// constructor
Product::Product()
{
    // initialize the product name
    name = new u8[100];
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
Product::Product(u8 *name, f8 price, u32 quantity, time_t expiryDate, ProductCategory category)
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

Product::Product(u8 *name, f8 price, u32 quantity, tm expiryDate, ProductCategory category)
{
    // initialize the product name
    this->name = name;
    // initialize the product price
    this->price = price;
    // initialize the product quantity
    this->quantity = quantity;
    // initialize the product expiry date
    this->expiryDate = mktime(&expiryDate);
    // initialize the category of the product
    this->category = category;
}

// destructor
Product::~Product()
{
}

// function to set the product name
void Product::setName(u8 *name)
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

void Product::setExpiryDate(tm expiryDate)
{
    tm expiry = expiryDate;
    expiry.tm_hour = 0;
    expiry.tm_min = 0;
    expiry.tm_sec = 0;
    // set the product expiry date
    this->expiryDate = mktime(&expiry);
}

// function to set the category of the product
void Product::setCategory(ProductCategory category)
{
    // set the category of the product
    this->category = category;
}

// function to get the product name
u8 *Product::getName()
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
