#include "calculator.h"
#include "ui_calculator.h"
#include "qcustomplot.h"
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

	temperature << "Kelwin" << "Celsjusz";
    ui->comboBox_2->addItems(temperature);
    ui->comboBox_3->addItems(temperature);
    time << "Sekunda" << "Minuta" << "Godzina";
    power << "KM" << "kW";
    speed << "Mile na godzine" << "Kilometry na godzine";
    data << "Kb" << "KB" << "Mb" << "MB" << "Gb" << "GB" << "Tb" << "TB";
    measure << "Centymetry" << "Metry" << "Kilometry";

	ui->calendarWidget->setMinimumDate(QDate::currentDate());
    chart(ui->chart);



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

void Calculator::on_actionPrzelicznik_jednostek_triggered()
{
    int max_width = 620;
    for(int i = this->width() ;i <= max_width; i+=10)
    {
       this->resize(i,this->height());
    }
}


void Calculator::on_comboBox_activated(int index)
{
    ui->input->clear();
    ui->output->clear();

    index = ui->comboBox->currentIndex();
    switch (index)
    {
    case 0:
        if (ui->comboBox->itemText(index) == "Temperatura")
        {
            if (!ui->comboBox->currentText().isEmpty())
            {
                ui->comboBox_2->clear();
                ui->comboBox_3->clear();
            }
            if(ui->comboBox_2->currentText().isEmpty())
            {
                ui->comboBox_2->addItems(temperature);
                ui->comboBox_3->addItems(temperature);
            }
        }
        break;
    case 1:
        if (ui->comboBox->itemText(index) == "Czas")
        {
            if (!ui->comboBox->currentText().isEmpty())
            {
                ui->comboBox_2->clear();
                ui->comboBox_3->clear();
            }
            if(ui->comboBox_2->currentText().isEmpty())
            {
                ui->comboBox_2->addItems(time);
                ui->comboBox_3->addItems(time);
            }
        }
        break;
    case 2:
        if (ui->comboBox->itemText(index) == "Moc")
        {
            if (!ui->comboBox->currentText().isEmpty())
            {
                ui->comboBox_2->clear();
                ui->comboBox_3->clear();
            }
            if(ui->comboBox_2->currentText().isEmpty())
            {
                ui->comboBox_2->addItems(power);
                ui->comboBox_3->addItems(power);
            }
        }
        break;
    case 3:
        if (ui->comboBox->itemText(index) == "Prędkość")
        {
            if (!ui->comboBox->currentText().isEmpty())
            {
                ui->comboBox_2->clear();
                ui->comboBox_3->clear();
            }
            if(ui->comboBox_2->currentText().isEmpty())
            {
                ui->comboBox_2->addItems(speed);
                ui->comboBox_3->addItems(speed);
            }
        }
        break;
    case 4:
        if (ui->comboBox->itemText(index) == "Dane")
        {
            if (!ui->comboBox->currentText().isEmpty())
            {
                ui->comboBox_2->clear();
                ui->comboBox_3->clear();
            }
            if(ui->comboBox_2->currentText().isEmpty())
            {
                ui->comboBox_2->addItems(data);
                ui->comboBox_3->addItems(data);
            }
        }
        break;
    case 5:
        if (ui->comboBox->itemText(index) == "Długość")
        {
            if (!ui->comboBox->currentText().isEmpty())
            {
                ui->comboBox_2->clear();
                ui->comboBox_3->clear();
            }
            if(ui->comboBox_2->currentText().isEmpty())
            {
                ui->comboBox_2->addItems(measure);
                ui->comboBox_3->addItems(measure);
            }
        }
        break;
     default:
        break;
    }
}

void Calculator::on_input_textChanged(const QString &arg1)
{
    double number;

    if (ui->comboBox_2->currentText() == ui->comboBox_3->currentText())
    {
        ui->output->setText(arg1);
    }
    else if(ui->comboBox_2->currentIndex() == 0)
    {
        if (ui->comboBox_2->currentText() == "Kelwin")
        {
            number = arg1.toDouble()-273.15;
            ui->output->setText(QString::number(number));
        }
        else if (ui->comboBox_2->currentText() == "KM")
        {
            number = arg1.toDouble()*0.7456998;
            ui->output->setText(QString::number(number));
        }
        else if (ui->comboBox_2->currentText() == "Mile na godzine")
        {
            number = arg1.toDouble()*1.609344;
            ui->output->setText(QString::number(number));
        }
        else if (ui->comboBox_2->currentText() == "Centymetry")
        {
            if (ui->comboBox_3->currentText() == "Metry")
            {
                number = arg1.toDouble()/100;
                ui->output->setText(QString::number(number));
            }
            else if (ui->comboBox_3->currentText() == "Kilometry")
            {
                number = arg1.toDouble()/100000;
                ui->output->setText(QString::number(number));
            }
        }
        else if (ui->comboBox_2->currentText() == "Sekunda")
        {
            if (ui->comboBox_3->currentText() == "Minuta")
            {
                number = arg1.toDouble()/60;
                ui->output->setText(QString::number(number));
            }
            else if (ui->comboBox_3->currentText() == "Godzina")
            {
                number = arg1.toDouble()/3600;
                ui->output->setText(QString::number(number));
            }
        }
        else if (ui->comboBox_2->currentText() == "Kb")
        {
            if (ui->comboBox_3->currentText() == "KB")
            {
                number = arg1.toDouble()/8;
                ui->output->setText(QString::number(number));
            }
            else if (ui->comboBox_3->currentText() == "Mb")
            {
                number = arg1.toDouble()/1024;
                ui->output->setText(QString::number(number));
            }
            else if (ui->comboBox_3->currentText() == "MB")
            {
                number = arg1.toDouble()/8192;
                ui->output->setText(QString::number(number));
            }
            else if (ui->comboBox_3->currentText() == "Gb")
            {
                number = arg1.toDouble()/1048576;
                ui->output->setText(QString::number(number));
            }
            else if (ui->comboBox_3->currentText() == "GB")
            {
                number = arg1.toDouble()/8388608;
                ui->output->setText(QString::number(number));
            }
            else if (ui->comboBox_3->currentText() == "Tb")
            {
                number = arg1.toDouble()/1073741824;
                ui->output->setText(QString::number(number));
            }
            else if (ui->comboBox_3->currentText() == "TB")
            {
                number = arg1.toDouble()/8589934592;
                ui->output->setText(QString::number(number));
            }
        }
    }
    else if(ui->comboBox_2->currentIndex() == 1)
    {
        if (ui->comboBox_2->currentText() == "Celsjusz")
        {
            number = arg1.toDouble()+273.15;
            ui->output->setText(QString::number(number));
        }
        else if (ui->comboBox_2->currentText() == "kW")
        {
            number = arg1.toDouble()/0.7456998;
            ui->output->setText(QString::number(number));
        }
        else if (ui->comboBox_2->currentText() == "Kilometry na godzine")
        {
            number = arg1.toDouble()*0.621371192;
            ui->output->setText(QString::number(number));
        }
        else if (ui->comboBox_2->currentText() == "Metry")
        {
            if (ui->comboBox_3->currentText() == "Centymetry")
            {
                number = arg1.toDouble()*100;
                ui->output->setText(QString::number(number));
            }
            else if (ui->comboBox_3->currentText() == "Kilometry")
            {
                number = arg1.toDouble()/1000;
                ui->output->setText(QString::number(number));
            }
        }
        else if (ui->comboBox_2->currentText() == "Minuta")
        {
            if (ui->comboBox_3->currentText() == "Sekunda")
            {
                number = arg1.toDouble()*60;
                ui->output->setText(QString::number(number));
            }
            else if (ui->comboBox_3->currentText() == "Godzina")
            {
                number = arg1.toDouble()/60;
                ui->output->setText(QString::number(number));
            }
        }
        else if (ui->comboBox_2->currentText() == "KB")
        {
            if (ui->comboBox_3->currentText() == "Kb")
            {
                number = arg1.toDouble()*8;
                ui->output->setText(QString::number(number));
            }
            else if (ui->comboBox_3->currentText() == "Mb")
            {
                number = arg1.toDouble()/128;
                ui->output->setText(QString::number(number));
            }
            else if (ui->comboBox_3->currentText() == "MB")
            {
                number = arg1.toDouble()/1024;
                ui->output->setText(QString::number(number));
            }
            else if (ui->comboBox_3->currentText() == "Gb")
            {
                number = arg1.toDouble()/131072;
                ui->output->setText(QString::number(number));
            }
            else if (ui->comboBox_3->currentText() == "GB")
            {
                number = arg1.toDouble()/1048576;
                ui->output->setText(QString::number(number));
            }
            else if (ui->comboBox_3->currentText() == "Tb")
            {
                number = arg1.toDouble()/134217728;
                ui->output->setText(QString::number(number));
            }
            else if (ui->comboBox_3->currentText() == "TB")
            {
                number = arg1.toDouble()/1073741824;
                ui->output->setText(QString::number(number));
            }
        }
    }
    else if(ui->comboBox_2->currentIndex() == 2)
    {
        if (ui->comboBox_2->currentText() == "Kilometry")
        {
            if (ui->comboBox_3->currentText() == "Centymetry")
            {
                number = arg1.toDouble()*100000;
                ui->output->setText(QString::number(number));
            }
            else if (ui->comboBox_3->currentText() == "Metry")
            {
                number = arg1.toDouble()*1000;
                ui->output->setText(QString::number(number));
            }
        }
        else if (ui->comboBox_2->currentText() == "Godzina")
        {
            if (ui->comboBox_3->currentText() == "Sekunda")
            {
                number = arg1.toDouble()*3600;
                ui->output->setText(QString::number(number));
            }
            else if (ui->comboBox_3->currentText() == "Minuta")
            {
                number = arg1.toDouble()*60;
                ui->output->setText(QString::number(number));
            }
        }
        else if (ui->comboBox_2->currentText() == "Mb")
        {
            if (ui->comboBox_3->currentText() == "Kb")
            {
                number = arg1.toDouble()*1024;
                ui->output->setText(QString::number(number));
            }
            else if (ui->comboBox_3->currentText() == "KB")
            {
                number = arg1.toDouble()*128;
                ui->output->setText(QString::number(number));
            }
            else if (ui->comboBox_3->currentText() == "MB")
            {
                number = arg1.toDouble()/8;
                ui->output->setText(QString::number(number));
            }
            else if (ui->comboBox_3->currentText() == "Gb")
            {
                number = arg1.toDouble()/1024;
                ui->output->setText(QString::number(number));
            }
            else if (ui->comboBox_3->currentText() == "GB")
            {
                number = arg1.toDouble()/8192;
                ui->output->setText(QString::number(number));
            }
            else if (ui->comboBox_3->currentText() == "Tb")
            {
                number = arg1.toDouble()/1048576;
                ui->output->setText(QString::number(number));
            }
            else if (ui->comboBox_3->currentText() == "TB")
            {
                number = arg1.toDouble()/8388608;
                ui->output->setText(QString::number(number));
            }
        }
    }
    else if(ui->comboBox_2->currentIndex() == 3)
    {
        if (ui->comboBox_2->currentText() == "MB")
        {
            if (ui->comboBox_3->currentText() == "Kb")
            {
                number = arg1.toDouble()*8192;
                ui->output->setText(QString::number(number));
            }
            else if (ui->comboBox_3->currentText() == "KB")
            {
                number = arg1.toDouble()*1024;
                ui->output->setText(QString::number(number));
            }
            else if (ui->comboBox_3->currentText() == "Mb")
            {
                number = arg1.toDouble()*8;
                ui->output->setText(QString::number(number));
            }
            else if (ui->comboBox_3->currentText() == "Gb")
            {
                number = arg1.toDouble()/128;
                ui->output->setText(QString::number(number));
            }
            else if (ui->comboBox_3->currentText() == "GB")
            {
                number = arg1.toDouble()/1024;
                ui->output->setText(QString::number(number));
            }
            else if (ui->comboBox_3->currentText() == "Tb")
            {
                number = arg1.toDouble()/131072;
                ui->output->setText(QString::number(number));
            }
            else if (ui->comboBox_3->currentText() == "TB")
            {
                number = arg1.toDouble()/1048576;
                ui->output->setText(QString::number(number));
            }
        }
    }
    else if(ui->comboBox_2->currentIndex() == 4)
    {
        if (ui->comboBox_2->currentText() == "Gb")
        {
            if (ui->comboBox_3->currentText() == "Kb")
            {
                number = arg1.toDouble()*1048576;
                ui->output->setText(QString::number(number));
            }
            else if (ui->comboBox_3->currentText() == "KB")
            {
                number = arg1.toDouble()*131072;
                ui->output->setText(QString::number(number));
            }
            else if (ui->comboBox_3->currentText() == "Mb")
            {
                number = arg1.toDouble()*1024;
                ui->output->setText(QString::number(number));
            }
            else if (ui->comboBox_3->currentText() == "MB")
            {
                number = arg1.toDouble()*128;
                ui->output->setText(QString::number(number));
            }
            else if (ui->comboBox_3->currentText() == "GB")
            {
                number = arg1.toDouble()/8;
                ui->output->setText(QString::number(number));
            }
            else if (ui->comboBox_3->currentText() == "Tb")
            {
                number = arg1.toDouble()/1024;
                ui->output->setText(QString::number(number));
            }
            else if (ui->comboBox_3->currentText() == "TB")
            {
                number = arg1.toDouble()/8192;
                ui->output->setText(QString::number(number));
            }
        }
    }
    else if(ui->comboBox_2->currentIndex() == 5)
    {
        if (ui->comboBox_2->currentText() == "GB")
        {
            if (ui->comboBox_3->currentText() == "Kb")
            {
                number = arg1.toDouble()*8388608;
                ui->output->setText(QString::number(number));
            }
            else if (ui->comboBox_3->currentText() == "KB")
            {
                number = arg1.toDouble()*1048576;
                ui->output->setText(QString::number(number));
            }
            else if (ui->comboBox_3->currentText() == "Mb")
            {
                number = arg1.toDouble()*8192;
                ui->output->setText(QString::number(number));
            }
            else if (ui->comboBox_3->currentText() == "MB")
            {
                number = arg1.toDouble()*1024;
                ui->output->setText(QString::number(number));
            }
            else if (ui->comboBox_3->currentText() == "Gb")
            {
                number = arg1.toDouble()*8;
                ui->output->setText(QString::number(number));
            }
            else if (ui->comboBox_3->currentText() == "Tb")
            {
                number = arg1.toDouble()/128;
                ui->output->setText(QString::number(number));
            }
            else if (ui->comboBox_3->currentText() == "TB")
            {
                number = arg1.toDouble()/1024;
                ui->output->setText(QString::number(number));
            }
        }
    }
    else if(ui->comboBox_2->currentIndex() == 6)
    {
        if (ui->comboBox_2->currentText() == "Tb")
        {
            if (ui->comboBox_3->currentText() == "Kb")
            {
                number = arg1.toDouble()*1073741824;
                ui->output->setText(QString::number(number));
            }
            else if (ui->comboBox_3->currentText() == "KB")
            {
                number = arg1.toDouble()*134217728;
                ui->output->setText(QString::number(number));
            }
            else if (ui->comboBox_3->currentText() == "Mb")
            {
                number = arg1.toDouble()*1048576;
                ui->output->setText(QString::number(number));
            }
            else if (ui->comboBox_3->currentText() == "MB")
            {
                number = arg1.toDouble()*131072;
                ui->output->setText(QString::number(number));
            }
            else if (ui->comboBox_3->currentText() == "Gb")
            {
                number = arg1.toDouble()*1024;
                ui->output->setText(QString::number(number));
            }
            else if (ui->comboBox_3->currentText() == "GB")
            {
                number = arg1.toDouble()*128;
                ui->output->setText(QString::number(number));
            }
            else if (ui->comboBox_3->currentText() == "TB")
            {
                number = arg1.toDouble()/8;
                ui->output->setText(QString::number(number));
            }
        }
    }
    else if(ui->comboBox_2->currentIndex() == 7)
    {
        if (ui->comboBox_2->currentText() == "TB")
        {
            if (ui->comboBox_3->currentText() == "Kb")
            {
                number = arg1.toDouble()*8589934592;
                ui->output->setText(QString::number(number));
            }
            else if (ui->comboBox_3->currentText() == "KB")
            {
                number = arg1.toDouble()*1073741824;
                ui->output->setText(QString::number(number));
            }
            else if (ui->comboBox_3->currentText() == "Mb")
            {
                number = arg1.toDouble()*8388608;
                ui->output->setText(QString::number(number));
            }
            else if (ui->comboBox_3->currentText() == "MB")
            {
                number = arg1.toDouble()*1048576;
                ui->output->setText(QString::number(number));
            }
            else if (ui->comboBox_3->currentText() == "Gb")
            {
                number = arg1.toDouble()*8192;
                ui->output->setText(QString::number(number));
            }
            else if (ui->comboBox_3->currentText() == "GB")
            {
                number = arg1.toDouble()*1024;
                ui->output->setText(QString::number(number));
            }
            else if (ui->comboBox_3->currentText() == "Tb")
            {
                number = arg1.toDouble()*8;
                ui->output->setText(QString::number(number));
            }
        }
    }
}

void Calculator::on_calendarWidget_selectionChanged()
{
    QDate day;

    int diff;
    diff = ui->calendarWidget->selectedDate().toJulianDay()-day.currentDate().toJulianDay();


    if (diff==0)
    {
        ui->label_4->setText("To jest dzisiaj!");
    }
    else if (diff==1)
    {
        ui->label_4->setText("Różnica to: "+QString::number(diff)+" dzień");
    }
    else
    {
        ui->label_4->setText("Różnica to: "+QString::number(diff)+" dni");
    }

}

void Calculator::chart(QCustomPlot *customPlot)
{
    customPlot->addGraph();
    customPlot->graph(0)->setPen(QPen(Qt::red));
    customPlot->addGraph();
    customPlot = ui->chart;
    int a = ui->a->value();
    int b = ui->b->value();
    int c = ui->c->value();
    int d = ui->d->value();

    int a2 = ui->a2->value();
    int b2 = ui->b2->value();
    int c2 = ui->c2->value();
    int d2 = ui->d2->value();
    QVector<double> x(500), y(500);
    QVector<double> x2(500), y2(500);


        for (int i=0; i<500; ++i)
        {
          x[i] = i/50.0-5;
          y[i] = a*(pow(x[i],3))+b*(pow(x[i],2))+c*x[i]+d;

          x2[i] = i/50.0-5;
          y2[i] = a2*(pow(x2[i],3))+b2*(pow(x2[i],2))+c2*x2[i]+d2;
        }





    customPlot->graph(0)->setData(x, y);

    customPlot->graph(1)->setData(x2, y2);

    customPlot->xAxis->setLabel("x");
    customPlot->yAxis->setLabel("y");


    customPlot->xAxis->setRange(-5,5);
    customPlot->yAxis->setRange(-5,5);



    customPlot->replot();
}




void Calculator::on_a_valueChanged()
{
    chart(ui->chart);
}

void Calculator::on_b_valueChanged()
{
    chart(ui->chart);
}

void Calculator::on_c_valueChanged()
{
    chart(ui->chart);
}

void Calculator::on_d_valueChanged()
{
    chart(ui->chart);
}

void Calculator::on_a2_valueChanged()
{
    chart(ui->chart);
}

void Calculator::on_b2_valueChanged()
{
    chart(ui->chart);
}

void Calculator::on_c2_valueChanged()
{
    chart(ui->chart);
}

void Calculator::on_d2_valueChanged()
{
    chart(ui->chart);
}

void Calculator::on_actionKalkulator_triggered()
{
    int width = 415;
    for(int i = this->width() ;i <= width; i+=10)
    {
       this->resize(i,this->height());
    }
}


