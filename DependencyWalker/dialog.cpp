#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog),
    p_ms(QString("C:/Users/yumig/source/ProjectRepo/vsa/Endpoint/src"))
{
    ui->setupUi(this);


}

Dialog::~Dialog()
{
    delete ui;
}
