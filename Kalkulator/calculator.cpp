#include "calculator.h"
#include "ui_calculator.h"
#include <QDebug>
#include <QSound>
#include <QDate>
#include <QtMath>

Calculator::Calculator(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Calculator)
{
    ui->setupUi(this);

    waitingForOperand = true;

    addClicked = false;
    subtractClicked = false;
    multiplyClicked = false;
    divideClicked = false;

    sumTemp = 0.0;
    factorTemp = 0.0;

    length = 15;






}

Calculator::~Calculator()
{
    delete ui;
}

void Calculator::on_button_0_clicked()
{
    QSound::play(":/new/sounds/metal_click_1.wav");

    if (ui->screen->text() == "0" && ui->button_0->text().toInt() == 0.0)
    {
        return;
    }
    if (waitingForOperand)
    {
        ui->screen->clear();
        waitingForOperand = false;
    }
    ui->screen->setText(ui->screen->text() + "0");
}

void Calculator::on_button_1_clicked()
{
    QSound::play(":/new/sounds/metal_click_1.wav");

    if (ui->screen->text() == "0" && ui->button_1->text().toInt() == 0.0)
        return;

    if (waitingForOperand)
    {
        ui->screen->clear();
        waitingForOperand = false;
    }
    ui->screen->setText(ui->screen->text() + "1");
}

void Calculator::on_button_2_clicked()
{
    QSound::play(":/new/sounds/metal_click_1.wav");

    if (ui->screen->text() == "0" && ui->button_2->text().toInt() == 0.0)
        return;

    if (waitingForOperand)
    {
        ui->screen->clear();
        waitingForOperand = false;
    }
    ui->screen->setText(ui->screen->text() + "2");
}

void Calculator::on_button_3_clicked()
{
    QSound::play(":/new/sounds/metal_click_1.wav");

    if (ui->screen->text() == "0" && ui->button_3->text().toInt() == 0.0)
        return;

    if (waitingForOperand)
    {
        ui->screen->clear();
        waitingForOperand = false;
    }
    ui->screen->setText(ui->screen->text() + "3");
}

void Calculator::on_button_4_clicked()
{
    QSound::play(":/new/sounds/metal_click_1.wav");

    if (ui->screen->text() == "0" && ui->button_4->text().toInt() == 0.0)
        return;

    if (waitingForOperand)
    {
        ui->screen->clear();
        waitingForOperand = false;
    }
    ui->screen->setText(ui->screen->text() + "4");
}

void Calculator::on_button_5_clicked()
{
    QSound::play(":/new/sounds/metal_click_1.wav");

    if (ui->screen->text() == "0" && ui->button_5->text().toInt() == 0.0)
        return;

    if (waitingForOperand)
    {
        ui->screen->clear();
        waitingForOperand = false;
    }
    ui->screen->setText(ui->screen->text() + "5");
}

void Calculator::on_button_6_clicked()
{
    QSound::play(":/new/sounds/metal_click_1.wav");

    if (ui->screen->text() == "0" && ui->button_6->text().toInt() == 0.0)
        return;

    if (waitingForOperand)
    {
        ui->screen->clear();
        waitingForOperand = false;
    }
    ui->screen->setText(ui->screen->text() + "6");
}

void Calculator::on_button_7_clicked()
{
    QSound::play(":/new/sounds/metal_click_1.wav");

    if (ui->screen->text() == "0" && ui->button_7->text().toInt() == 0.0)
        return;

    if (waitingForOperand)
    {
        ui->screen->clear();
        waitingForOperand = false;
    }
    ui->screen->setText(ui->screen->text() + "7");
}

void Calculator::on_button_8_clicked()
{
    QSound::play(":/new/sounds/metal_click_1.wav");

    if (ui->screen->text() == "0" && ui->button_8->text().toInt() == 0.0)
        return;

    if (waitingForOperand)
    {
        ui->screen->clear();
        waitingForOperand = false;
    }
    ui->screen->setText(ui->screen->text() + "8");
}

void Calculator::on_button_9_clicked()
{
    QSound::play(":/new/sounds/metal_click_1.wav");

    if (ui->screen->text() == "0" && ui->button_9->text().toInt() == 0.0)
        return;

    if (waitingForOperand)
    {
        ui->screen->clear();
        waitingForOperand = false;
    }
    ui->screen->setText(ui->screen->text() + "9");
}

void Calculator::on_buttonComma_clicked()
{
    if(!ui->screen->text().contains("."))
    {
        ui->screen->setMaxLength(ui->screen->maxLength()+1);
        ui->screen->setText(ui->screen->text() + ".");
    }
    waitingForOperand = false;
}

void Calculator::on_buttonAdd_clicked()
{
    QSound::play(":/new/sounds/operations_sound.wav");

    double operand = ui->screen->text().toDouble();
    qDebug() << operand;

    if(addClicked)
    {
        if(true)
        {
            sumTemp += operand;
        }
        ui->screen->setText(QString::number(sumTemp));
    }
    else
    {
        sumTemp = operand;
    }

    addClicked = true;

    ui->screen_1->setText(ui->screen_1->text().append(QString::number(operand) + " + "));
    ui->screen->setMaxLength(length);
    waitingForOperand = true;
}

void Calculator::on_buttonSubtract_clicked()
{
    QSound::play(":/new/sounds/operations_sound.wav");

    double operand = ui->screen->text().toDouble();
    qDebug() << operand;

    if(subtractClicked)
    {
        if(true)
        {
            sumTemp -= operand;
        }
        ui->screen->setText(QString::number(sumTemp));
    }
    else
    {
        sumTemp = operand;
    }

    subtractClicked = true;

    ui->screen_1->setText(ui->screen_1->text().append(QString::number(operand) + " - "));
    ui->screen->setMaxLength(length);
    waitingForOperand = true;
}

void Calculator::on_buttonMultiply_clicked()
{
    QSound::play(":/new/sounds/operations_sound.wav");

    double operand = ui->screen->text().toDouble();
    qDebug() << operand;

    if(multiplyClicked)
    {
        if(true)
        {
            factorTemp *= operand;
        }
        ui->screen->setText(QString::number(factorTemp));
    }
    else
    {
        factorTemp = operand;
    }

    multiplyClicked = true;

    ui->screen_1->setText(ui->screen_1->text().append(QString::number(operand) + " * "));
    ui->screen->setMaxLength(length);
    waitingForOperand = true;
}

void Calculator::on_buttonShare_clicked()
{
    QSound::play(":/new/sounds/operations_sound.wav");

    double operand = ui->screen->text().toDouble();
    qDebug() << operand;

    if(divideClicked)
    {
        if(true)
        {
            factorTemp /= operand;
        }
        ui->screen->setText(QString::number(factorTemp));
    }
    else
    {
        factorTemp = operand;
    }

    divideClicked = true;

    ui->screen_1->setText(ui->screen_1->text().append(QString::number(operand) + " / "));
    ui->screen->setMaxLength(length);
    waitingForOperand = true;
}

void Calculator::on_buttonEqual_clicked()
{
    QString text = ui->screen_1->text();
    double operand = ui->screen->text().toDouble();

    if(text.remove(0,(text.length()-3)) == " + ")
    {
        sumTemp += operand;
        ui->screen->setText(QString::number(sumTemp));
        ui->screen_1->clear();
    }
    if(text.remove(0,(text.length()-3)) == " - ")
    {
        sumTemp -= operand;
        ui->screen->setText(QString::number(sumTemp));
        ui->screen_1->clear();
    }
    if(text.remove(0,(text.length()-3)) == " * ")
    {
        factorTemp *= operand;
        ui->screen->setText(QString::number(factorTemp));
        ui->screen_1->clear();
    }
    if(text.remove(0,(text.length()-3)) == " / ")
    {
        if (operand == 0.0)
        {
            ui->screen->setText("Nie przez zero!");
            return;
        }
        factorTemp /= operand;
        ui->screen->setText(QString::number(factorTemp));
        ui->screen_1->clear();
    }
    sumTemp = 0.0;
    factorTemp = 0.0;

    addClicked = false;
    subtractClicked = false;
    multiplyClicked = false;
    divideClicked = false;

    ui->screen->setMaxLength(length);

    waitingForOperand = true;
}

void Calculator::on_buttonReplace_clicked()
{
    QString text = ui->screen->text();
    double value = text.toDouble();

    if(value > 0.0)
    {
        ui->screen->setMaxLength(ui->screen->maxLength()+1);
        text.prepend(tr("-"));
    }
    else if (value < 0.0)
    {
        text.remove(0,1);
        ui->screen->setMaxLength(ui->screen->maxLength()-1);
    }
    ui->screen->setText(text);
}

void Calculator::on_backSpace_clicked()
{
    QSound::play(":/new/sounds/backspace_sound.wav");

    QString text = ui->screen->text();

    if (text.indexOf("-",0) == true || text.length() <= 2)
    {
        if (text.toDouble() > 0.0)
        {
            ui->screen->backspace();
        }
        else
        {
            ui->screen->setText("0");
            ui->screen->setMaxLength(ui->screen->maxLength()-1);
            waitingForOperand = true;
        }
        //text.clear();
    }
    else if( text.length() > 2 )
    {
        ui->screen->backspace();
    }
    if (text.endsWith(".") == true)
    {
        ui->screen->setMaxLength(ui->screen->maxLength()-1);
    }
}

void Calculator::on_reset_clicked()
{
    QSound::play(":/new/sounds/delete.wav");

    ui->screen->clear();
    ui->screen_1->clear();
    ui->screen->setText("0");
    ui->screen->setMaxLength(length);

    sumTemp = 0.0;
    factorTemp = 0.0;

    addClicked = false;
    subtractClicked = false;
    multiplyClicked = false;
    divideClicked = false;

    waitingForOperand = true;
}

void Calculator::on_back_clicked()
{
    if (waitingForOperand)
    {
        if(ui->screen->text() == "0")
        {
            return;
        }
        else
        {
            ui->screen->setText("0");
        }
    }
    else
    {
        ui->screen->setText("0");
        waitingForOperand = true;
    }
    ui->screen->setMaxLength(length);
}


void Calculator::on_actionKalkulator_triggered()
{
    int width = 415;
    for(int i = this->width() ;i <= width; i+=10)
    {
       this->resize(i,this->height());
    }
}


