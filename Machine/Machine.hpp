/************** AUTHOR:             ********************************************************************************/
/************** DATE: 12/8/2023     ********************************************************************************/
/************** VERSION: 0.1        ********************************************************************************/
/************** FILE:  Machine.hpp  ********************************************************************************/
/*******************************************************************************************************************/




#ifndef MACHINE_HPP_
#define MACHINE_HPP_

#include "../LIB/STD_TYPES.hpp"
#include "../LIB/Products.hpp"
#include <vector>
<<<<<<< HEAD
#include <iostream>
=======
#include <stdio.h>
#include <string>
>>>>>>> 5e6f0efc516e7ec124f615da9de52053c16d8ee2
using namespace std;


// struct Request to store the request data 
typedef struct Request
{
    Product product;
    string productNumber;
    float money;
    float change;
    string message;
    string error;
} Request;


//sales struct to store the sales data 
typedef struct Sales
{
    Product product;
    int quantity;
    float soldMoney;
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
    void displaySales();

    // function to display requests
    void displayRequests();


private:
    // array of products
    vector<Product> products; 
    
    // array of requests
    vector<Request> requests;

    // variable to store [product, qty sold, total money from this product]
    vector<Sales> sales;

    // variable to store the total money
    float totalMoney;
    // variable for mode
    bool isProgramMode;

    // variable for the secret code
    int secretCode;
    // variable for the password
    int password;
};

#endif /* MACHINE_HPP_ */