#include <QApplication>
#include "VendingMachineGUI.hpp"
#include "Machine.hpp"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    // Create an instance of the Machine class
    Machine machine;

    // Create an instance of the VendingMachineGUI class
    VendingMachineGUI window(&machine);
    window.show();

    return app.exec();
}