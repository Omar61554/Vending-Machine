/************** AUTHOR:             ********************************************************************************/
/************** DATE: 12/8/2023     ********************************************************************************/
/************** VERSION: 0.1        ********************************************************************************/
/************** FILE:  Machine.cpp  ********************************************************************************/
/*******************************************************************************************************************/

#include "Machine.hpp"
#include <iostream>
#include <limits>

using namespace std;
// constructor
Machine::Machine()
{
    // initialize the array of products
    products = vector<Product>(0);
    // initialize the array of requests
    requests = vector<Request>(0);
    // initialize the variable to store [product, qty sold, total money from this product]
    sales = vector<Sales>(0);
    // initialize the variable to store the total money
    totalMoney = 0;
}

// destructor
Machine::~Machine()
{
}

// function to handle the display products
void Machine::handleDisplayProducts()
{
    cout << "Product Size: " << products.size() << endl;

    // Display products in boxes
    for (int i = 0; i < products.size(); i++)
    {
        string productName = products[i].getName(); // Get the product name

        // Display the product name
        
        cout << i+1 << " - " << productName << endl;

        // Display the product price
        cout <<"Price: "<< products[i].getPrice() << endl;

        // Display the product quantity
        cout <<"Available: " << products[i].getQuantity() << endl;

        if (isProgramMode)
        {
            // Display the product expiry date in days
            cout << products[i].getTimeToExpiryDate() << endl;
        }
    }
} 

// function to handle the user input
void Machine::handleUserInput()
{
    Request request;
    
    // Print the welcome message
    std::cout << "Welcome to our vending machine" << std::endl;
    
    // Print the products to the user
    handleDisplayProducts();
    
    // Prompt the user to enter the product he wants to buy
    std::cout << "Please enter the product number you want to buy (or 0 to cancel, or 123 for program mode): ";
    
    // Get the product number the user wants to buy
    std::cin >> request.productNumber;

    // Check if the input is valid
    while (std::cin.fail() || (request.productNumber != 0 && request.productNumber != 123 &&
                              (request.productNumber < 1 || request.productNumber > products.size())))
    {
        // Clear input errors and discard the invalid input
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignore up to 1000 characters or until a new line is found
    // numeric limits is a template class that has a static member called max() that returns the maximum value of the type passed to it
        // Prompt the user to re-enter a valid product number or cancel
        std::cout << "Invalid input. Please enter a valid product number (or 0 to cancel, or 123 for program mode): ";

        // Get the product number again
        std::cin >> request.productNumber;
    }

    // Check if the user wants to cancel the operation
    if (request.productNumber == 0)
    {
        std::cout << "Operation cancelled" << std::endl;
        std::cout << "Thank you for using our vending machine" << std::endl;
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

// function to enter operation mode
void Machine::enterOperationMode(Request request)
{
    // Prompt the user to enter the money he wants to pay
    std::cout << "Please enter the money (" << products[request.productNumber - 1].getPrice() << "): ";

    // Get the money the user wants to pay
    std::cin >> request.money;

    // Check if the input is valid
    while (std::cin.fail() || request.money < products[request.productNumber - 1].getPrice())
    {
        // Clear input errors and discard the invalid input
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        // Prompt the user to enter additional money or cancel
        std::cout << "Please enter additional money (" << products[request.productNumber - 1].getPrice() - request.money << ") or press 0 to cancel: ";

        // Get the additional money the user wants to pay
        std::cin >> request.money;

        // Check if the user wants to cancel the operation
        if (request.money == 0)
        {
            std::cout << "Operation cancelled" << std::endl;
            std::cout << "Thank you for using our vending machine" << std::endl;
            return;
        }
    }

    // Calculate the change
    request.change = request.money - products[request.productNumber - 1].getPrice();

    // If change is 0 then display message
    if (request.change == 0)
    {
        // Display message
        request.message = 1;
    }
    // Else if change is less than 0 then display error
    else if (request.change < 0)
    {
        // Display error
        request.error = 1;
    }
    // Else if change is greater than 0 then display change
    else if (request.change > 0)
    {
        // Display change
        std::cout << "Your change is " << request.change << std::endl;
        request.message = 1;
    }

    std::cout << "Thank you for using our vending machine" << std::endl;

    // Add the request to the requests array
    requests.push_back(request);

    // Update the product quantity
    products[request.productNumber - 1].setQuantity(products[request.productNumber - 1].getQuantity() - 1);

    // Update the total money
    totalMoney += products[request.productNumber - 1].getPrice();
}

// function to enter program mode
void Machine::enterProgramMode()
{
    // check if the user is authorized
    // prompt the user to enter the password
    printf("Please enter the password: ");
    // get the password
    int password;
    scanf("%d", &password);
    // if password is 1234 then enter program mode
    if (password != 1234)
    {
        printf("Wrong password\n");
        return;
    }
    // set the mode to program mode
    isProgramMode = true;
    // prompt the user to enter the operation he wants to do
    printf("Please enter the operation you want to do:\n1- Add product\n2- Edit product\n3- Delete product\n");
    // get the operation the user wants to do
    u32 operation;
    scanf("%d", &operation);
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

// function to add product
void Machine::addProduct()
{


    printf("Please enter the product name: ");
    // get the product name
    string name ;
    cin >> name;

    // prompt the user to enter the product price
    printf("Please enter the product price: ");
    // get the product price
    float price;
    cin >> price;
    // prompt the user to enter the product quantity
    printf("Please enter the product quantity: ");
    // get the product quantity
    unsigned int quantity;
    cin >> quantity;
    // prompt the user to enter the product expiry date
    printf("Please enter the product expiry (day/month/year): \n");
    // get the product expiry day
    u32 day;
    printf("\nDay: ");
    scanf("%d", &day);
    // get the product expiry month
    u32 month;
    printf("\nMonth: ");
    scanf("%d", &month);
    // get the product expiry year
    u32 year;
    printf("\nYear: ");
    scanf("%d", &year);
    // create the product expiry date
    struct tm expiryDate;
    expiryDate.tm_mday = day;
    expiryDate.tm_mon = month;
    expiryDate.tm_year = year;
    // prompt the user to enter the product category
    printf("Please enter the product category:\n1- Soda\n2- Water\n3- Juice\n");
    // get the product category
    u32 category;
    scanf("%d", &category);
    // create the product
    Product product(name, price, quantity, expiryDate, (ProductCategory)category);
    // add the product to the products array
    products.push_back(product);

    // display the product
    printf("Product added successfully\n");
    // display the products
    handleDisplayProducts();
}

// function to edit product
void Machine::editProduct()
{
    // display the products
    handleDisplayProducts();
    // prompt the user to enter the product number
    printf("Please enter the product number: ");
    // get the product number
    u32 productNumber;
    scanf("%d", &productNumber);
    // if product number is in valid range
    if (productNumber >= 0 && productNumber < products.size())
    {
        // prompt the user to enter the product name
        printf("Please enter the product name: ");
        // get the product name
        string name ;
        scanf("%s", name);
        // prompt the user to enter the product price
        printf("Please enter the product price: ");
        // get the product price
        f8 price;
        scanf("%f", &price);
        // prompt the user to enter the product quantity
        printf("Please enter the product quantity: ");
        // get the product quantity
        u32 quantity;
        scanf("%d", &quantity);
        // prompt the user to enter the product expiry date
        printf("Please enter the product expiry \n");
        // get the product expiry day
        u32 day;
        scanf("Day: %d", &day);
        // get the product expiry month
        u32 month;
        scanf("Month: %d", &month);
        // get the product expiry year
        u32 year;
        scanf("Year: %d", &year);
        // create the product expiry date
        struct tm expiryDate;
        expiryDate.tm_mday = day;
        expiryDate.tm_mon = month;
        expiryDate.tm_year = year;
        // prompt the user to enter the product category
        printf("Please enter the product category:\n1- Soda\n2- Water\n3- Juice\n");
        // get the product category
        u32 category;
        scanf("%d", &category);
        // create the product
        Product product(name, price, quantity, expiryDate, (ProductCategory)category);
        // update the product
        products[productNumber] = product;
        // display the product
        printf("Product updated successfully\n");
        // display the products
        handleDisplayProducts();
    }
    else
    {
        printf("Invalid product number\n");
    }
}

void Machine::deleteProduct()
{
    printf("Please enter the product number: ");
    // get the product number
    int productNumber;
    scanf("%d", &productNumber);
    // if product number is in valid range
    if (productNumber >= 0 && productNumber < products.size())
    {
        // delete the product
        products.erase(products.begin() + productNumber);
        // display the product
        printf("Product deleted successfully\n");
        // display the products
        handleDisplayProducts();
    }
    else
    {
        printf("Invalid product number\n");
    }
}
/*******************************************************************************************************************/
/*******************************************************************************************************************/
