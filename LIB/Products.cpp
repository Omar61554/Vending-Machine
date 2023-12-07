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
    name = new u8[20];
    // initialize the product price
    price = 0;
    // initialize the product quantity
    quantity = 0;
    // initialize the product expiry date
    expiryDate = 0;
    // initialize the category of the product
    category = None;
}

// constructor
Product::Product(u8 *name, f8 price, u8 quantity, time_t expiryDate, ProductCategory category)
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

// destructor
Product::~Product()
{
    // delete the product name
    delete[] name;
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
void Product::setQuantity(u8 quantity)
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
u8 Product::getQuantity()
{
    // return the product quantity
    return quantity;
}

// function to get the product expiry date
time_t Product::getExpiryDate()
{
    // return the product expiry date
    return expiryDate;
}

// function to get the category of the product
ProductCategory Product::getCategory()
{
    // return the category of the product
    return category;
}
