#include "VendingMachineGUI.hpp"

VendingMachineGUI::VendingMachineGUI(Machine* machine, QWidget *parent)
    : QMainWindow(parent), machine(machine)
{
    setWindowTitle("Vending Machine");
    setGeometry(100, 100, 400, 300);

    productLabel = new QLabel("Products:");
    productLayout = new QVBoxLayout();

    QVBoxLayout* layout = new QVBoxLayout();
    layout->addWidget(productLabel);
    layout->addLayout(productLayout);

    QWidget* centralWidget = new QWidget();
    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);

    updateProducts();
}

void VendingMachineGUI::updateProducts() {
    // Clear the product layout
    QLayoutItem* item;
    while ((item = productLayout->takeAt(0)) != nullptr) {
        delete item->widget();
        delete item;
    }

    // Display products in boxes
    const std::vector<Product>& products = machine->getProducts();
    for (int i = 0; i < products.size(); ++i) {
        const Product& product = products[i];
        const std::string& productName = product.getName();
        double productPrice = product.getPrice();
        int productQuantity = product.getQuantity();

        QLabel* productInfo = new QLabel(QString::fromStdString(
            std::to_string(i + 1) + " - " + productName + "\n"
            "Price: " + std::to_string(productPrice) + "\n"
            "Available: " + std::to_string(productQuantity) + "\n"
        ));
        productLayout->addWidget(productInfo);
    }
}