#include "Dialog.h"
#include <QApplication>
#include <QGridLayout>
#include <QFile>
#include <QShortcut>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent)
  , cwDate(new QCalendarWidget(this))
  , bSetStartDate(new QPushButton(QString::fromUtf8("Set Start Date"), this))
  , bSetEndDate(new QPushButton(QString::fromUtf8("Set End Date"), this))
  , gbInfo(new QGroupBox(QString::fromUtf8("Information"), this))
  , lStartDate(new QLabel(this))
  , lEndDate(new QLabel(this))
  , lLicenseFileName(new QLabel(QString::fromUtf8("License File Name:"), this))
  , leLicenseFileName(new QLineEdit(this))
  , bGenerateLicenseFile(new QPushButton(QString::fromUtf8("Generate License File"), this))
{
    QGridLayout *mainLayout = new QGridLayout;
    setLayout(mainLayout);

    QGridLayout *gridInfo = new QGridLayout;
    gridInfo->addWidget(new QLabel(QString::fromUtf8("Start Date:"), this), 0, 0);
    gridInfo->addWidget(lStartDate, 0, 1);
    gridInfo->addWidget(new QLabel(QString::fromUtf8("End Date:"), this), 1, 0);
    gridInfo->addWidget(lEndDate, 1, 1);
    gridInfo->setSpacing(5);

    gbInfo->setLayout(gridInfo);

    mainLayout->addWidget(cwDate, 0, 0, 7, 1);
    mainLayout->addWidget(bSetStartDate, 0, 1, 1, 2);
    mainLayout->addWidget(bSetEndDate, 1, 1, 1, 2);
    mainLayout->addWidget(gbInfo, 2, 1, 2, 2);
    mainLayout->addWidget(lLicenseFileName, 4, 1, 1, 2);
    mainLayout->addWidget(leLicenseFileName, 5, 1, 1, 2);
    mainLayout->addWidget(bGenerateLicenseFile, 6, 1, 1, 2);
    mainLayout->setSpacing(5);

    // делает окно фиксированного размера
    this->layout()->setSizeConstraint(QLayout::SetFixedSize);

    connect(bSetStartDate, SIGNAL(clicked()), this, SLOT(openPort()));
    connect(bSetEndDate, SIGNAL(clicked()), this, SLOT(closePort()));

    QShortcut *aboutShortcut = new QShortcut(QKeySequence("F1"), this);
    connect(aboutShortcut, SIGNAL(activated()), qApp, SLOT(aboutQt()));
}

Dialog::~Dialog()
{
}
