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
    name = "NONE"; // 100 is the maximum number of characters in the product name , new is used to allocate memory in the heap instead of the stack to avoid stack overflow
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
/**
 * @brief Construct a new Product:: Product object  with the given parameters
 *
 * @param name
 * @param price
 * @param quantity
 * @param expiryDate
 * @param category
 */
Product::Product(string name, f8 price, u32 quantity, int expiryDate, ProductCategory category)
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

/*******************************************************************************************************************/
// destructor
Product::~Product()
{
    // delete the product name
    name = "";
}

/****************************************************************************************************************************/

// setters

/**
 * @brief Set the Name object
 *
 * @param name
 */
void Product::setName(string name)
{
    // set the product name
    this->name = name;
}

/**
 * @brief Set the Price object
 *
 * @param price
 */
void Product::setPrice(f8 price)
{
    // set the product price
    this->price = price;
}

/**
 * @brief Set the Quantity object
 *
 * @param quantity
 */
void Product::setQuantity(u32 quantity)
{
    // set the product quantity
    this->quantity = quantity;
}

/**
 * @brief Set the Expiry Date object
 *
 * @param expiryDate
 */
void Product::setExpiryDate(int expiryDate)
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

/**
 * @brief Set the Category object
 *
 * @param category
 */
void Product::setCategory(ProductCategory category)
{
    // set the category of the product
    this->category = category;
}

/****************************************************************************************************************************/

// getters

/**
 * @brief  Get the Name object
 *
 * @return string
 */
string Product::getName()
{
    // return the product name
    return name;
}

/**
 * @brief Get the Price object
 *
 * @return f8
 */
f8 Product::getPrice()
{
    // return the product price
    return price;
}

// function to get the product quantity
/**
 * @brief Get the Quantity object
 *
 * @return u32
 */
u32 Product::getQuantity()
{
    // return the product quantity
    return quantity;
}

/**
 * @brief Get the Time To Expiry Date object
 *
 * @return f8
 */
int Product::getExpiryDate()
{
    string date = "";

    date += this->expiryDate % 100;
    date += "/";
    date += (this->expiryDate / 100) % 100;
    date += "/";
    date += this->expiryDate / 10000;
    return this->expiryDate;
}

/**
 * @brief Get the Category object
 *
 * @return ProductCategory
 */
ProductCategory Product::getCategory()
{
    // return the category of the product
    return category;
}

bool Product::isExpired()
{
    time_t now = time(0);
    tm nowtm = *(gmtime(&now));
    int today = (nowtm.tm_year + 1900) * 10000 + (nowtm.tm_mon + 1) * 100 + nowtm.tm_mday;
    if (today > expiryDate)
        return true;
    else
        return false;
}
/*******************************************************************************************************************/