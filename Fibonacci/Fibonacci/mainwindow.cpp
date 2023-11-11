#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "const.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    double first_prize = ui -> lineEdit -> text().toDouble();
    double second_prize = ui -> lineEdit_2 -> text().toDouble();
    double result(0);

    bool first_prize_greatter_then_second_prize = first_prize > second_prize;
    bool second_prize_greatter_then_first_prize = first_prize < second_prize;


    switch (ui -> comboBox -> currentIndex())
    {
    case 0: //LONG
        if (ui -> radioButton -> isChecked()) //radioButton = 1.618
        {
            if (first_prize_greatter_then_second_prize)
            {
                result = first_prize + (first_prize - second_prize) * Constants::ratio_1_618;
            }
            else if (second_prize_greatter_then_first_prize)
            {
                result = second_prize + (second_prize - first_prize) * Constants::ratio_1_618;
            }
        }
        else if (ui -> radioButton_2 -> isChecked()) //radioButton_2 = 0.618
        {
            if (first_prize_greatter_then_second_prize)
            {
                result = first_prize + (first_prize - second_prize) * Constants::ratio_0_618;
            }
            else if (second_prize_greatter_then_first_prize)
            {
                result = second_prize + (second_prize - first_prize) * Constants::ratio_0_618;
            }
        }
        break;
    case 1: //SHORT
        if (ui -> radioButton -> isChecked()) //radioButton = 1.618
        {
            if (first_prize_greatter_then_second_prize)
            {
                result = second_prize - (first_prize - second_prize) * Constants::ratio_1_618;
            }
            else if (second_prize_greatter_then_first_prize)
            {
                result = first_prize - (second_prize - first_prize) * Constants::ratio_1_618;
            }
        }
        else if (ui -> radioButton_2 -> isChecked()) //radioButton_2 = 0.618
        {
            if (first_prize_greatter_then_second_prize)
            {
                result = second_prize - (first_prize - second_prize) * Constants::ratio_0_618;
            }
            else if (second_prize_greatter_then_first_prize)
            {
                result = first_prize - (second_prize - first_prize) * Constants::ratio_0_618;
            }
        }

        break;
    }

    ui -> lineEdit_3 -> setText(QString::number(result));

}

