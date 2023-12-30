/************** AUTHOR:             ********************************************************************************/
/************** DATE: 12/8/2023     ********************************************************************************/
/************** VERSION: 0.1        ********************************************************************************/
/************** FILE:  Machine.cpp  ********************************************************************************/
/*******************************************************************************************************************/


// include the header file of the class
#include "Machine.hpp"
#include <iostream>
#include <limits>

using namespace std;


// constructor
/**
 * @brief Construct a new Machine:: Machine object
 * 
 */
Machine::Machine()
{
    // initialize the array of products
    products = vector<Product>(1);
    // initialize the array of requests
    requests = vector<Request>(1);
    // initialize the variable to store [product, qty sold, total money from this product]
    sales = vector<Sales>(0);
    // initialize the variable to store the total money
    totalMoney = 0;
}


// destructor
Machine::~Machine()
{
}



/**
 * @brief handel the display products
 * 
 */
void Machine::handleDisplayProducts()
{
    cout << "Product Size: " << (products.size()-1) << endl;

    // Display products in boxes for each category
    for (int i = 1; i < products.size(); i++)
    {
        //display product for eac category 
        if (products[i].getCategory() == Soda)
        {
            cout << "Soda: "<<"\n";
            string productName = products[i].getName(); // Get the product name

        // Display the product name
        
        cout << i << " - " << productName << endl;

        // Display the product price
        cout <<"Price: "<< products[i].getPrice() << endl;

        // Display the product quantity
        cout <<"Available: " << products[i].getQuantity() << endl;
        }

        else if (products[i].getCategory() == Water)
        {
            cout << "Water: "<<"\n";
            string productName = products[i].getName(); // Get the product name

        // Display the product name
        
        cout << i << " - " << productName << endl;

        // Display the product price
        cout <<"Price: "<< products[i].getPrice() << endl;

        // Display the product quantity
        cout <<"Available: " << products[i].getQuantity() << endl;
        }

        else if (products[i].getCategory() == Juice)
        {
            cout << "Juice: "<<"\n";
            string productName = products[i].getName(); // Get the product name

        // Display the product name
        
        cout << i << " - " << productName << endl;

        // Display the product price
        cout <<"Price: "<< products[i].getPrice() << endl;

        // Display the product quantity
        cout <<"Available: " << products[i].getQuantity() << endl;
        }
        

        if (isProgramMode)
        {
            // Display the product expiry date in days
            cout << products[i].getTimeToExpiryDate() << endl;
        }
    }
}



/**
 * @brief handel the user input
 * 
 */
void Machine::handleUserInput()
{
    Request request;
    
    // Print the welcome message
    cout << "Welcome to our vending machine" << endl;
    
    // Print the products to the user
    handleDisplayProducts();
    
    // Prompt the user to enter the product he wants to buy
    cout << "Please enter the product number you want to buy (or 0 to cancel, or 123 for program mode): ";
    
    // Get the product number the user wants to buy
    cin >> request.productNumber;

    // Check if the input is valid
    while (cin.fail() || (request.productNumber != 0 && request.productNumber != 123 &&
                              (request.productNumber < 1 || request.productNumber > products.size())))
    {
        // Clear input errors and discard the invalid input
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        // Prompt the user to re-enter a valid product number or cancel
        cout << "Invalid input. Please enter a valid product number (or 0 to cancel, or 123 for program mode): ";

        // Get the product number again
        cin >> request.productNumber;
    }

    // Check if the user wants to cancel the operation
    if (request.productNumber == 0)
    {
        cout << "Operation cancelled" << endl;
        cout << "Thank you for using our vending machine" << endl;
        return;
    }
    // Check if the user wants to enter program mode
    else if (request.productNumber == 123)
    {
        enterProgramMode();
        return;
    }

    // Enter operation mode
    enterOperationMode(request);
}



/**
 * @brief enters operation mode
 * @param sales 
 **/
void Machine::enterOperationMode(Request request)
{
    // Prompt the user to enter the money he wants to pay
    cout << "Please enter the money (" << products[request.productNumber].getPrice() << "): ";

    // Get the money the user wants to pay
    cin >> request.money;
    //cin fail check
    if(request.money < 0)
    {
        cout << "Invalid input. Please enter a valid money: ";
        cin >> request.money;
    }

    // check if the user entered the exact money
    if (request.money == products[request.productNumber].getPrice())
    {
        // handle the request
          // handle the request
            cout << "Thank you for using our vending machine" << endl;

    // Add the request to the requests array
        requests.push_back(request);

    // Update the product quantity
        products[request.productNumber ].setQuantity(products[request.productNumber  ].getQuantity() -1 );
    //when the quantity is 0 delete the product
        if(products[request.productNumber ].getQuantity() == 0)
        {
        products.erase(products.begin() + request.productNumber );
    }
    //if the product expiryDate is less than 0 delete the product
        if(products[request.productNumber ].getTimeToExpiryDate() < 0)
        {
        products.erase(products.begin() + request.productNumber );
        }

    // Update the total money
        totalMoney += products[request.productNumber ].getPrice();
        return;
    }
    
    // check if the user entered more money
    else if (request.money > products[request.productNumber].getPrice())
    {
        // handle the request
        cout << "Please take your change: " << ( -(products[request.productNumber].getPrice() - request.money)) << endl;
    }
    // check if the user entered less money

    else
    {
        // handle the request
        cout << "Please enter the remaining money (" << (products[request.productNumber].getPrice() - request.money) << "): ";
        // Get the remaining money the user wants to pay
        u32 remainingMoney;
        cin >> remainingMoney;
        //cin fail check
        if(remainingMoney < 0)
        {
            cout << "Invalid input. Please enter a valid money: ";
            cin >> request.money;
        }

        // check if the user entered the exact money
        if (remainingMoney == products[request.productNumber].getPrice()-request.money)
        {
            // handle the request
            cout << "Thank you for using our vending machine" << endl;

        // Add the request to the requests array
        requests.push_back(request);

        // Update the product quantity
        products[request.productNumber ].setQuantity(products[request.productNumber  ].getQuantity() -1 );
        //when the quantity is 0 delete the product
        if(products[request.productNumber ].getQuantity() == 0)
        {
        products.erase(products.begin() + request.productNumber );
        }
        //if the product expiryDate is less than 0 delete the product
        if(products[request.productNumber ].getTimeToExpiryDate() < 0)
        {
            products.erase(products.begin() + request.productNumber );
        }

    // Update the total money
    totalMoney += products[request.productNumber ].getPrice();
            return;
        }

        // check if the user entered more money
        else if (remainingMoney > products[request.productNumber].getPrice()- request.money)
        {
            // handle the request
            cout << "Please take your change: " << ( remainingMoney - (products[request.productNumber].getPrice() - request.money )) << endl;
        }
        // check if the user entered less money
        else
        {
            // handle the request
            cout << "Operation cancelled" << endl;
            cout << "Thank you for using our vending machine" << endl;
            return;
        }
    }


    cout << "Thank you for using our vending machine" << endl;

    // Add the request to the requests array
    requests.push_back(request);

    // Update the product quantity
    products[request.productNumber ].setQuantity(products[request.productNumber  ].getQuantity() -1 );
    //when the quantity is 0 delete the product
    if(products[request.productNumber ].getQuantity() == 0)
    {
        products.erase(products.begin() + request.productNumber );
    }
    //if the product expiryDate is less than 0 delete the product
    if(products[request.productNumber ].getTimeToExpiryDate() < 0)
    {
        products.erase(products.begin() + request.productNumber );
    }

    // Update the total money
    totalMoney += products[request.productNumber ].getPrice();
}



/**
 * @brief enters program mode
 * 
 */
void Machine::enterProgramMode()
{
    // check if the user is authorized
    // prompt the user to enter the password for the first time the password is 1234 
    cout << "Please enter the password(1234): ";

    // get the password
    int password;
    cin >> password;
    // if password is 1234 then enter program mode
    if (password != 1234)
    {
        cout << "Invalid password" << endl;
        return;
    }

    // set the mode to program mode
    isProgramMode = true;
    // prompt the user to enter the operation he wants to do
    cout << "Please enter the operation you want to do:\n1- Add product\n2- Edit product\n3- Delete product\n";
    // get the operation the user wants to do
    u32 operation;
    cin >> operation;
    // if operation is 1 then add product
    if (operation == 1)
    {
        // add product
        addProduct();
    }
    // else if operation is 2 then edit product
    else if (operation == 2)
    {
        // edit product
        editProduct();
    }
    // else if operation is 3 then delete product
    else if (operation == 3)
    {
        // delete product
        deleteProduct();
    }
    // set the mode to operation mode
    isProgramMode = false;
}



/**
 * @brief add new product in program mode
 * 
 */
void Machine::addProduct()
{


    cout << "Please enter the product name: ";
    // get the product name
    string name ;
    cin >> name;

    // prompt the user to enter the product price
    cout << "Please enter the product price: ";
    // get the product price
    float price;
    cin >> price;
    //cin fail check for <0 and any up normal input like charters and strings
    if(price < 0)
    {
        cout << "Invalid input. Please enter a valid price: ";
        cin >> price;
    }


    // prompt the user to enter the product quantity
    cout << "Please enter the product quantity: ";
    // get the product quantity
    unsigned int quantity;
    cin >> quantity;
    //cin fail check
    if(quantity < 0)
    {
        cout << "Invalid input. Please enter a valid quantity: ";
        cin >> quantity;
    }
    //cin fail for any up normal input like charters and strings
    if(cin.fail())
    {
        cout << "Invalid input. Please enter a valid quantity: ";
        cin >> quantity;
    }
    // prompt the user to enter the product expiry date
    cout << "Please enter the product expiry \n";
    // get the product expiry day
    u32 day;
    cout << "Day: ";
    cin >> day;
    //cin fail check
    if(day > 31 || day < 1)
    {
        cout << "Invalid input. Please enter a valid day: ";
        cin >> day;
    }
    //cin fail for any up normal input like charters and strings
    if(cin.fail())
    {
        cout << "Invalid input. Please enter a valid day: ";
        cin >> day;
    }
    // get the product expiry month
    u32 month;
    cout << "Month: ";
    cin >> month;
    //cin fail for any up normal input like charters and strings
    if(cin.fail())
    {
        cout << "Invalid input. Please enter a valid month: ";
        cin >> month;
    }
    //cin fail check
    if(month > 12 || month < 1)
    {
        cout << "Invalid input. Please enter a valid month: ";
        cin >> month;
    }
    // get the product expiry year
    u32 year;
    cout << "Year: ";
    cin >> year;
    //cin fail check
    if(year < 2024)
    {
        cout << "Invalid input. Please enter a valid year: ";
        cin >> year;
    }
    //cin fail for any up normal input like charters and strings
    if(cin.fail())
    {
        cout << "Invalid input. Please enter a valid year: ";
        cin >> year;
    }
    // create the product expiry date
    struct tm expiryDate;
    expiryDate.tm_mday = day;
    expiryDate.tm_mon = month;
    expiryDate.tm_year = year;
    // prompt the user to enter the product category
    cout << "Please enter the product category:\n1- Soda\n2- Water\n3- Juice\n";
    // get the product category
    u32 category;
    cin >> category;
    //cin fail check
    if(category > 3 || category < 1)
    {
        cout << "Invalid input. Please enter a valid category: ";
        cin >> category;
    }
    //cin fail for any up normal input like charters and strings
    if(cin.fail())
    {
        cout << "Invalid input. Please enter a valid category: ";
        cin >> category;
    }
    // create the product
    //ADD the product to its category section
    if(category == 1)
    {
        Product product(name, price, quantity, expiryDate, (ProductCategory)category);
    // add the product to the products array
    products.push_back(product);
    }
    else if(category == 2)
    {
        Product product(name, price, quantity, expiryDate, (ProductCategory)category);
    // add the product to the products array
    products.push_back(product);
    }
    else if(category == 3)
    {
        Product product(name, price, quantity, expiryDate, (ProductCategory)category);
    // add the product to the products array
    products.push_back(product);
    }
   

    // display the product
    cout << "Product added successfully" << endl;
    // display the products
    //handleDisplayProducts();
}



/**
 * @brief edit added product
 * 
 */
void Machine::editProduct()
{
    // display the products
    handleDisplayProducts();
    // prompt the user to enter the product number
    cout << "Please enter the product number: ";
    // get the product number
    u32 productNumber;
    cin >> productNumber;
    // if product number is in valid range
    if (productNumber >= 1 && productNumber < products.size())
    {
        // prompt the user to enter the product name
        cout << "Please enter the product name: ";
        // get the product name
        string name ;
        cin >> name;
        // prompt the user to enter the product price
        cout << "Please enter the product price: ";
        // get the product price
        f8 price;
        cin >> price;
        // prompt the user to enter the product quantity
        cout << "Please enter the product quantity: ";
        // get the product quantity
        u32 quantity;
        cin >> quantity;
        // prompt the user to enter the product expiry date
        cout << "Please enter the product expiry \n";
        // get the product expiry day
        u32 day;
        cout << "Day: ";
        cin >> day;
        //cin fail check
        if(day > 31 || day < 1)
        {
            cout << "Invalid input. Please enter a valid day: ";
            cin >> day;
        }
        // get the product expiry month
        u32 month;
        cout << "Month: ";
        cin >> month;
        //cin fail check
        if(month > 12 || month < 1)
        {
            cout << "Invalid input. Please enter a valid month: ";
            cin >> month;
        }
        // get the product expiry year
        u32 year;
        cout << "Year: ";
        cin >> year;
        //cin fail check
        if(year < 2024)
        {
            cout << "Invalid input. Please enter a valid year: ";
            cin >> year;
        }
        // create the product expiry date
        struct tm expiryDate;
        expiryDate.tm_mday = day;
        expiryDate.tm_mon = month;
        expiryDate.tm_year = year;
        // prompt the user to enter the product category
        cout << "Please enter the product category:\n1- Soda\n2- Water\n3- Juice\n";
        // get the product category
        u32 category;
        cin >> category;
        //cin fail check
        if(category > 3 || category < 1)
        {
            cout << "Invalid input. Please enter a valid category: ";
            cin >> category;
        }
        // create the product
        Product product(name, price, quantity, expiryDate, (ProductCategory)category);
        // update the product
        products[productNumber] = product;
        // display the product
        cout << "Product edited successfully" << endl;
        // display the products
       // handleDisplayProducts();
    }
    else
    {
        cout << "Invalid product number" << endl;
    }
}


/**
 * @brief delete product
 * 
 */
void Machine::deleteProduct()
{
    cout << "Please enter the product number: ";
    // get the product number
    int productNumber;
    cin >> productNumber;
    // if product number is in valid range
    if (productNumber >= 1 && productNumber < products.size())
    {
        // delete the product
        products.erase(products.begin() + productNumber);
        // display the product
        cout << "Product deleted successfully" << endl;
        // display the products
       // handleDisplayProducts();
    }
    else
    {
        cout << "Invalid product number" << endl;
    }
}
/*******************************************************************************************************************/
/*******************************************************************************************************************/
