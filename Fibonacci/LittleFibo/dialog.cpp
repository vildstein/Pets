
#include "dialog.h"
#include "const.h"

#include <QHBoxLayout>
#include <QVBoxLayout>

#include <QSlider>
#include <QDoubleSpinBox>
#include <QPushButton>
#include <QRadioButton>
#include <QComboBox>
#include <QLabel>

LittleFibo::LittleFibo(QWidget *parent)
    : QDialog(parent)
{
    //Win Elements Building BEGIN
    //FIRST SPINBOX
    spinboxFirstPrise = new QDoubleSpinBox;
    spinboxFirstPrise -> setMaximum(10000000);
    spinboxFirstPrise -> setMinimum(-100);
    spinboxFirstPrise -> setDecimals(5);

    //LABEL FOR sliderOfFirstPrise SLIDER
    xLabelofFirstPrise = new QLabel("X.    X    X    X    X    X");

    //SLIDER OF FIRST SPIN BOX
    sliderOfFirstPrise = new QSlider;
    sliderOfFirstPrise -> setOrientation(Qt::Horizontal);
    sliderOfFirstPrise -> setSingleStep(1);
    sliderOfFirstPrise -> setMaximum(5);
    connect(sliderOfFirstPrise, SIGNAL(valueChanged(int)), this, SLOT(sliderOfFirstPriseSeting()));

    //SECOND SPINBOX
    spinboxSecondPrise = new QDoubleSpinBox;
    spinboxSecondPrise -> setMaximum(10000000);
    spinboxSecondPrise -> setMinimum(-100);
    spinboxSecondPrise -> setDecimals(5);

    //LABEL FOR sliderOfSecondPrise SLIDER
    xLabelofSecondPrise = new QLabel("X.    X    X    X    X    X");

    //SLIDER OF SECOND SPIN BOX

    sliderOfSecondPrise = new QSlider;
    sliderOfSecondPrise -> setOrientation(Qt::Horizontal);
    sliderOfSecondPrise -> setSingleStep(1);
    sliderOfSecondPrise -> setMaximum(5);
    connect(sliderOfSecondPrise, SIGNAL(valueChanged(int)), this, SLOT(sliderOfSecondPriseSeting()));

    //FIRST RADIOBUTTON 1.618
    radioButton1618 = new QRadioButton("1.618");
    radioButton1618 -> setChecked(true);
    connect(radioButton1618, SIGNAL(clicked()), this, SLOT(radioButtonClicked()));

    //SECOND RADIOBUTTON 0.618
    radioButton0618 = new QRadioButton("0.618");
    connect(radioButton0618, SIGNAL(clicked()), this, SLOT(radioButtonClicked()));

    //COMBOBOX
    positionComboBox = new QComboBox;
    positionComboBox -> insertItem(0, "LONG");
    positionComboBox -> insertItem(1, "SHORT");

    //PUSHBUTTON
    calculate = new QPushButton("Do");
    calculate -> setDefault(true);
    connect(calculate,SIGNAL(clicked()), this,SLOT(calculateClicked()));

    //PUSHBUTTON EXIT
    exitButton = new QPushButton("Close");
    connect(exitButton, SIGNAL(clicked()), this, SLOT(close()));


    //RESULT LABEL
    resultLabel = new QLabel;
    //Win Elements Building END

    //Layout Building BEGIN
    //left block BEGIN
    QVBoxLayout *leftLayout = new QVBoxLayout;
    leftLayout -> addWidget(spinboxFirstPrise);
    leftLayout -> addWidget(xLabelofFirstPrise);
    leftLayout -> addWidget(sliderOfFirstPrise);
    leftLayout -> addWidget(spinboxSecondPrise);
    leftLayout -> addWidget(xLabelofSecondPrise);
    leftLayout -> addWidget(sliderOfSecondPrise);
    leftLayout -> addStretch();
    //left block END

    //middle block BEGIN
    QVBoxLayout *middleLayout = new QVBoxLayout;
    middleLayout -> addWidget(radioButton1618);
    middleLayout -> addWidget(radioButton0618);
    middleLayout -> addWidget(positionComboBox);

    //right block BEGIN
    QVBoxLayout *rightLayout = new QVBoxLayout;
    rightLayout -> addWidget(calculate);
    rightLayout -> addWidget(exitButton);
    rightLayout -> addStretch();
    //right block END

    //complete window BEGIN
    QHBoxLayout *mainLayout = new QHBoxLayout;
    mainLayout -> addLayout(leftLayout);
    mainLayout -> addLayout(middleLayout);
    mainLayout -> addLayout(rightLayout);
    mainLayout -> addWidget(resultLabel);
    //complete window END

    setLayout(mainLayout);
    //Layout Building END
    setWindowTitle("Little Fibo");
}

LittleFibo::~LittleFibo()
{
}

void LittleFibo::calculateClicked()
{
    double first_prize = spinboxFirstPrise -> text().toDouble();
    double second_prize = spinboxSecondPrise -> text().toDouble();
    double result(0);

    bool first_prize_greatter_then_second_prize = first_prize > second_prize;
    bool second_prize_greatter_then_first_prize = first_prize < second_prize;


    switch (positionComboBox -> currentIndex())
    {
    case 0: //LONG
        if (radioButton1618 -> isChecked()) //radioButton = 1.618
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
        else if (radioButton0618 -> isChecked()) //radioButton_2 = 0.618
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
        if (radioButton1618 -> isChecked()) //radioButton = 1.618
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
        else if (radioButton0618 -> isChecked()) //radioButton_2 = 0.618
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


    resultLabel -> setText(QString::number(result));

}

void LittleFibo::radioButtonClicked()///// not works right
{
    if (resultLabel)//!!!!!
    {
        LittleFibo::calculateClicked();
    }
}

void LittleFibo::sliderOfFirstPriseSeting() // rewrite function to prevent code doubling
{
    switch (sliderOfFirstPrise -> sliderPosition())
    {
    case 0:
        {
            spinboxFirstPrise -> setSingleStep(1);
        break;
        }
    case 1:
    {
        spinboxFirstPrise -> setSingleStep(0.1);
        break;
    }
    case 2:
    {
        spinboxFirstPrise -> setSingleStep(0.01);
        break;
    }
    case 3:
    {
        spinboxFirstPrise -> setSingleStep(0.001);
        break;
    }
    case 4:
    {
        spinboxFirstPrise -> setSingleStep(0.0001);
        break;
    }
    case 5:
    {
        spinboxFirstPrise -> setSingleStep(0.00001);
        break;
    }
        default: break;
    }
}
void LittleFibo::sliderOfSecondPriseSeting() // rewrite function to prevent code doubling
{
    switch (sliderOfSecondPrise -> sliderPosition())
    {
    case 0:
    {
        spinboxSecondPrise -> setSingleStep(1);
        break;
    }
    case 1:
    {
        spinboxSecondPrise -> setSingleStep(0.1);
        break;
    }
    case 2:
    {
        spinboxSecondPrise -> setSingleStep(0.01);
        break;
    }
    case 3:
    {
        spinboxSecondPrise -> setSingleStep(0.001);
        break;
    }
    case 4:
    {
        spinboxSecondPrise -> setSingleStep(0.0001);
        break;
    }
    case 5:
    {
        spinboxSecondPrise -> setSingleStep(0.00001);
        break;
    }
    default: break;
    }
}
