#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

class QSlider;
class QDoubleSpinBox;
class QPushButton;
class QRadioButton;
class QComboBox;
class QLabel;

class LittleFibo : public QDialog
{
    Q_OBJECT

public:
    LittleFibo(QWidget *parent = nullptr);
    ~LittleFibo();
signals:
    //void exitButtonClicked();

private slots:
    void calculateClicked();
    void radioButtonClicked();
    void sliderOfFirstPriseSeting();
    void sliderOfSecondPriseSeting();


private:
    QDoubleSpinBox *spinboxFirstPrise;
    QDoubleSpinBox *spinboxSecondPrise;
    QSlider *sliderOfFirstPrise;
    QLabel *xLabelofFirstPrise;
    QLabel *xLabelofSecondPrise;
    QSlider *sliderOfSecondPrise;
    QRadioButton *radioButton1618;
    QRadioButton *radioButton0618;
    QComboBox *positionComboBox;
    QPushButton *calculate;
    QPushButton *exitButton;
    QLabel *resultLabel;



};

#endif // DIALOG_H
