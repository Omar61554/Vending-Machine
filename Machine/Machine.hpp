/************** AUTHOR: AMIN FADEL  ********************************************************************************/
/************** DATE: 12/8/2023     ********************************************************************************/
/************** VERSION: 0.1        ********************************************************************************/
/************** FILE:  Machine.hpp  ********************************************************************************/
/*******************************************************************************************************************/

#ifndef MACHINE_HPP_
#define MACHINE_HPP_

#include "../LIB/STD_TYPES.hpp"
#include "../LIB/Products.hpp"
#include <vector>
#include <stdio.h>
using namespace std;

typedef struct Request
{
    Product product;
    u8 productNumber;
    u8 money;
    u8 change;
    u8 message;
    u8 error;
} Request;

typedef struct Sales
{
    Product product;
    u8 quantity;
    f8 soldMoney;
} Sales;

// class Machine to store the machine data and functions to get and set the machine data

class Machine
{
public:
    // constructor
    Machine();
    // destructor
    ~Machine();
    // function to handle the user input
    void handleUserInput();
    // function to handle the display products
    void handleDisplayProducts();
    // function to enter program mode
    void enterProgramMode();
    // function to enter operation mode
    void enterOperationMode(Request request);
    // function to add product
    void addProduct();
    // function to edit product
    void editProduct();
    // function to delete product
    void deleteProduct();

private:
    // array of products
    vector<Product> products;
    // array of requests
    vector<Request> requests;
    // variable to store [product, qty sold, total money from this product]
    vector<Sales> sales;
    // variable to store the total money
    f8 totalMoney;
    // variable for size of products array
    u8 productsSize;
    // variable for mode
    bool isProgramMode;
};

#endif /* MACHINE_HPP_ */