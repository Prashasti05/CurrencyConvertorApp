#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMap>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:            //QT specific slots-designed to respond to signals
    void convertCurrency();
    void on_convertButton_clicked();

private:                
    Ui::MainWindow *ui;

    QMap<QString, double> rates;  //qt container to store key value pair
    void fillCurrencies();
    void setRates();
};
#endif // MAINWINDOW_H
