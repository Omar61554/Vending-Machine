/*******************************************************************************************************************/
/************** AUTHOR:             ********************************************************************************/
/************** DATE: 12/4/2023     ********************************************************************************/
/************** VERSION: 0.1        ********************************************************************************/
/************** FILE:  UI.hpp       ********************************************************************************/
/*******************************************************************************************************************/





#ifndef UI_HPP_
#define UI_HPP_

#include "../../LIB/STD_TYPES.hpp"
//class for vending machine user interface to let him choose the product he wants to buy and asks for the money and return the change if presents 

class UI
{   
    public:
    //constructor
    UI();
    //destructor
    ~UI();
    //function to display the products to the user
    void UI_displayProducts();
    //function to get the product the user wants to buy
    void UI_getProduct();
    //function to get the money from the user
    void UI_getMoney();
    //function to return the change to the user
    void UI_returnChange();
    //function to display the change to the user
    void UI_displayChange();
    //function to display the message to the user
    void UI_displayMessage();
    //function to display the error to the user
    void UI_displayError();
    //function to display the product price to the user
    void UI_displayPrice();
    //function to display the product quantity to the user
    void UI_displayQuantity();
    //function to display the product name to the user
    void UI_displayName();
    //function to display the product expiry date to the user
    void UI_displayExpiryDate();
    //function to display the product price to the user
    void UI_displayPrice();


    private:
    //variable to store the product the user wants to buy
    u8 product;
    //variable to store the money the user wants to pay
    u8 money;
    //variable to store the change the user wants to return
    u8 change;
    //variable to store the message the user wants to display
    u8 message;
    //variable to store the error the user wants to display
    u8 error;
    //variable to store the product price the user wants to display
    u8 price;
    //variable to store the product quantity the user wants to display
    u8 quantity;
    //variable to store the product name the user wants to display
    u8 name;
    //variable to store the product expiry date the user wants to display
    u8 expiryDate;
    //variable to store the product price the user wants to display
    u8 price;
};


#endif // UI_HPP_