/************** AUTHOR:             ********************************************************************************/
/************** DATE: 12/8/2023     ********************************************************************************/
/************** VERSION: 0.1        ********************************************************************************/
/************** FILE:  Machine.hpp  ********************************************************************************/
/*******************************************************************************************************************/

#ifndef MACHINE_HPP_
#define MACHINE_HPP_

// include the standard types used in the project

#include "../LIB/STD_TYPES.hpp"
#include "../LIB/Products.hpp"
#include <vector>
#include <iostream>

using namespace std;

// struct Request to store the request data
typedef struct Request
{
    Product product;
    u32 productNumber;
    f8 money;
    f8 change;
    u32 message;
    u32 error;
} Request;

// sales struct to store the sales data
typedef struct Sales
{
    Product product;
    u32 quantity;
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

    // function to display sales
    void displaySales(); // to be added

    // function to display requests
    void displayRequests(); // to be added

private:
    // array of products
    vector<Product> products;

    // array of requests
    vector<Request> requests;

    // variable to store [product, qty sold, total money from this product]
    vector<Sales> sales;

    // variable to store the total money
    f8 totalMoney;

    // variable for mode
    bool isProgramMode = false;

    // variable for the secret code
    u32 secretCode = 123;

    // variable for the password
    u32 password = 1234;
};

#endif /* MACHINE_HPP_ */