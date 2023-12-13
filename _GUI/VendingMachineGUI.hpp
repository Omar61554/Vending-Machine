#ifndef VENDINGMACHINEGUI_HPP
#define VENDINGMACHINEGUI_HPP

#include <QMainWindow>
#include <QLabel>
#include <QVBoxLayout>
#include "Machine.hpp"

class VendingMachineGUI : public QMainWindow {
    Q_OBJECT

public:
    explicit VendingMachineGUI(Machine* machine, QWidget *parent = nullptr);

public slots:
    void updateProducts();

private:
    Machine* machine;
    QLabel* productLabel;
    QVBoxLayout* productLayout;
};

#endif // VENDINGMACHINEGUI_HPP