#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setRates();     
    fillCurrencies();

    connect(ui->convertButton, &QPushButton::clicked, this, &MainWindow::convertCurrency);
}

MainWindow::~MainWindow()
{
    delete ui;
}
                        
void MainWindow::setRates(){   
    rates["INR"]=1.0;     
    rates["USD"]=0.012;  
    rates["EUR"]=0.01109; 
    rates["GBP"]=0.00949;
    rates["JPY"]=1.88679;  
}

void MainWindow::fillCurrencies(){  
    ui->fromCurrencyCombo->addItems(rates.keys());
    ui->toCurrencyCombo->addItems(rates.keys());
}

void MainWindow::convertCurrency(){
    QString from =ui->fromCurrencyCombo->currentText();
    QString to =ui->toCurrencyCombo->currentText();
    double amount=ui->amountlineEdit->text().toDouble(); 
    
    if(from==to){
        ui->resultLabel->setText(QString::number(amount)+" "+from + "="+QString::number(amount)+" "+from);
    }                                               
    
    if(!rates.contains(from)||!rates.contains(to)){
        QMessageBox::warning(this,"Error","Invalid Currency");
        return;
    }

    double inrAmount=amount/rates[from];     
    double convertedAmount= inrAmount * rates[to]; 

    ui->resultLabel->setText(QString::number(amount)+" " + from +" = " + QString::number(convertedAmount,'f',2)+" "+ to);                                        
}

void MainWindow::on_convertButton_clicked()
{
    convertCurrency();
}

