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

private slots:            //QT specific slots-designed to respond to signals(like button clicks)
    void convertCurrency();
    void on_convertButton_clicked();

private:                //func called only inside mainwindow class
    Ui::MainWindow *ui;

    QMap<QString, double> rates;  //qt container/map to store key value pair(key=currency name,val=1.0)
    void fillCurrencies();
    void setRates();
};
#endif // MAINWINDOW_H
