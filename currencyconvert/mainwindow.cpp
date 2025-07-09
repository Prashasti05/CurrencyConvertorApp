#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setRates();     //calls custom func to set exchange rates in map and fill combobox with  currency names
    fillCurrencies();

    connect(ui->convertButton, &QPushButton::clicked, this, &MainWindow::convertCurrency);
}

MainWindow::~MainWindow()
{
    delete ui;
}
//step1: set exchange rates
void MainWindow::setRates(){   //map kind of func to set coversion rates(key, val)
    rates["INR"]=1.0;     //base currency {1Rupee}
    rates["USD"]=0.012;  //   1/83.33  = (1 usd=83.33 rupee)  ==(1/83.33 usd =1 rupee)
    rates["EUR"]=0.01109; //  1/90.12
    rates["GBP"]=0.00949; //  1/105.40
    rates["JPY"]=1.88679;  // 1/0.53
}

//step 2: fill combobox with currency options
void MainWindow::fillCurrencies(){   //fills keys from rate map into combo box
    ui->fromCurrencyCombo->addItems(rates.keys());
    ui->toCurrencyCombo->addItems(rates.keys());
}

//step 3: Perform conversion
void MainWindow::convertCurrency(){
    QString from =ui->fromCurrencyCombo->currentText();//getcurrently selected currency from combobox
    QString to =ui->toCurrencyCombo->currentText();
    double amount=ui->amountlineEdit->text().toDouble(); // converts QString text (amount) input by user to double

                                                           //if same currencies,return same result
    if(from==to){
        ui->resultLabel->setText(QString::number(amount)+" "+from + "="+QString::number(amount)+" "+from);
    }                                               //100 USD = 100 USD

                                                        // if currency is not in list,return error
    if(!rates.contains(from)||!rates.contains(to)){
        QMessageBox::warning(this,"Error","Invalid Currency");
        return;
    }

    double inrAmount=amount/rates[from];     //divide by base currency
    double convertedAmount= inrAmount * rates[to];   //multiply by target currency

    ui->resultLabel->setText(QString::number(amount)+" " + from +" = " + QString::number(convertedAmount,'f',2)+" "+ to);
                                                         //100 USD = 92.34 EUR

    //set text in resultLbel(convert  (initial amount user entered) from double to QString  =  convert converted ans to Qstring,
    //f-fixed point notation,
    // 2 digits after decimal point
}

void MainWindow::on_convertButton_clicked()
{
    convertCurrency();
}

