/************** AUTHOR: AMIN FADEL  ********************************************************************************/
/************** DATE: 12/8/2023     ********************************************************************************/
/************** VERSION: 0.1        ********************************************************************************/
/************** FILE:  Machine.cpp  ********************************************************************************/
/*******************************************************************************************************************/

#include "Machine.hpp"

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
    // display products in boxes
    for (u8 i = 0; i < products.size(); i++)
    {
        // display the product name
        printf("%i - %s\n", i, products[i].getName());
        // display the product price
        printf("%f\n", products[i].getPrice());
        // display the product quantity
        printf("%d\n", products[i].getQuantity());
        if (isProgramMode)
        {
            // display the product expiry date
            printf("%f\n", products[i].getTimeToExpiryDate());
        }
    }
}
// function to handle the user input
void Machine::handleUserInput()
{
    Request request;
    // print the welcome message
    printf("Welcome to our vending machine\n");
    // print the products to the user
    handleDisplayProducts();
    // prompt the user to enter the product he wants to buy
    printf("Please enter the product you want to buy: ");
    // get the product the user wants to buy
    scanf("%d", &request.productNumber);

    // if input product is 98989898 then enter program mode
    if (request.productNumber == 98989898)
    {
        // enter program mode
        enterProgramMode();
    }
    // else if input is in valid range enter operation mode
    else if (request.productNumber >= 0 &&
             request.productNumber < products.size() &&
             products[request.productNumber].getQuantity() > 0 &&
             products[request.productNumber].getTimeToExpiryDate() > 0)
    {
        // enter operation mode
        enterOperationMode(request);
    }
}

// function to enter operation mode
void Machine::enterOperationMode(Request request)
{
    // prompt the user to enter the money he wants to pay
    printf("Please enter the money (%f): ", products[request.productNumber].getPrice());
    // get the money the user wants to pay
    scanf("%d", &request.money);
    // while money is less than the product price
    while (request.money < products[request.productNumber].getPrice())
    {
        // prompt the user to enter additional money
        printf("Please enter additional money (%f) or press 0 to cancel: ", products[request.productNumber].getPrice() - request.money);
        // get the additional money the user wants to pay
        f8 additionalMoney;
        scanf("%f", &additionalMoney);
        // if additional money is 0 then cancel the operation
        if (additionalMoney <= 0)
        {
            printf("Operation cancelled\nThank you for using our vending machine\n");
            return;
        }
        // add the additional money to the money
        request.money += additionalMoney;
    }
    // calculate the change
    request.change = request.money - products[request.productNumber].getPrice();
    // if change is 0 then display message
    if (request.change == 0)
    {
        // display message
        request.message = 1;
    }
    // else if change is less than 0 then display error
    else if (request.change < 0)
    {
        // display error
        request.error = 1;
    }
    // else if change is greater than 0 then display change
    else if (request.change > 0)
    {
        // display change
        printf("Your change is %f\n", request.change);
        request.message = 1;
    }
    printf("Thank you for using our vending machine\n");
    // add the request to the requests array
    requests.push_back(request);
    // update the product quantity
    products[request.productNumber].setQuantity(products[request.productNumber].getQuantity() - 1);
    // update the total money
    totalMoney += products[request.productNumber].getPrice();
}

// function to enter program mode
void Machine::enterProgramMode()
{
    // check if the user is authorized
    // prompt the user to enter the password
    printf("Please enter the password: ");
    // get the password
    u8 password;
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
    u8 operation;
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

    // prompt the user to enter the product name
    printf("Please enter the product name: ");
    // get the product name
    string name = "";
    scanf("%s", name);
    // prompt the user to enter the product price
    printf("Please enter the product price: ");
    // get the product price
    f8 price;
    scanf("%f", &price);
    // prompt the user to enter the product quantity
    printf("Please enter the product quantity: ");
    // get the product quantity
    u8 quantity;
    scanf("%d", &quantity);
    // prompt the user to enter the product expiry date
    printf("Please enter the product expiry (day/month/year): ");
    // get the product expiry day
    u8 day;
    scanf("%d", &day);
    // get the product expiry month
    u8 month;
    scanf("%d", &month);
    // get the product expiry year
    u8 year;
    scanf("%d", &year);
    // create the product expiry date
    struct tm expiryDate;
    expiryDate.tm_mday = day;
    expiryDate.tm_mon = month;
    expiryDate.tm_year = year;
    // prompt the user to enter the product category
    printf("Please enter the product category:\n1- Soda\n2- Water\n3- Juice\n");
    // get the product category
    u8 category;
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
    u8 productNumber;
    scanf("%d", &productNumber);
    // if product number is in valid range
    if (productNumber >= 0 && productNumber < products.size())
    {
        // prompt the user to enter the product name
        printf("Please enter the product name: ");
        // get the product name
        string name = "";
        scanf("%s", name);
        // prompt the user to enter the product price
        printf("Please enter the product price: ");
        // get the product price
        f8 price;
        scanf("%f", &price);
        // prompt the user to enter the product quantity
        printf("Please enter the product quantity: ");
        // get the product quantity
        u8 quantity;
        scanf("%d", &quantity);
        // prompt the user to enter the product expiry date
        printf("Please enter the product expiry \n");
        // get the product expiry day
        u8 day;
        scanf("Day: %d", &day);
        // get the product expiry month
        u8 month;
        scanf("Month: %d", &month);
        // get the product expiry year
        u8 year;
        scanf("Year: %d", &year);
        // create the product expiry date
        struct tm expiryDate;
        expiryDate.tm_mday = day;
        expiryDate.tm_mon = month;
        expiryDate.tm_year = year;
        // prompt the user to enter the product category
        printf("Please enter the product category:\n1- Soda\n2- Water\n3- Juice\n");
        // get the product category
        u8 category;
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