#include "Dialog.h"
#include <QApplication>
#include <QGridLayout>
#include <QFile>
#include <QDataStream>
#include <QShortcut>
#include <QMessageBox>

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
  , licenseFileGen(new LicenseFileGen(cwDate->selectedDate(), cwDate->selectedDate()))
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

    connect(bSetStartDate, SIGNAL(clicked()), this, SLOT(setStartDate()));
    connect(bSetEndDate, SIGNAL(clicked()), this, SLOT(setEndDate()));
    connect(bGenerateLicenseFile, SIGNAL(clicked()), this, SLOT(generateLicenseFile()));

    connect(licenseFileGen, SIGNAL(openFileError(QString)), this, SLOT(openFileError(QString)));
    connect(licenseFileGen, SIGNAL(writeFileError(QString)), this, SLOT(writeFileError(QString)));

    QShortcut *aboutShortcut = new QShortcut(QKeySequence("F1"), this);
    connect(aboutShortcut, SIGNAL(activated()), qApp, SLOT(aboutQt()));
}

Dialog::~Dialog()
{
}

void Dialog::setStartDate()
{
    licenseFileGen->setStartDate(cwDate->selectedDate());
    lStartDate->setText(cwDate->selectedDate().toString());
}

void Dialog::setEndDate()
{
    licenseFileGen->setEndDate(cwDate->selectedDate());
    lEndDate->setText(cwDate->selectedDate().toString());
}

void Dialog::generateLicenseFile()
{
    if(leLicenseFileName->text().isEmpty()) {
        licenseFileGen->setLicenseFileName("LicenseFile.dat");
    } else {
        licenseFileGen->setLicenseFileName(leLicenseFileName->text());
    }

    licenseFileGen->generate();
}

void Dialog::openFileError(const QString &fileName)
{
    QMessageBox::critical(this,
                          QString::fromUtf8("Open File Error"),
                          QString::fromUtf8("Could not create file: ") + fileName);
}

void Dialog::writeFileError(const QString &fileName)
{
    QMessageBox::critical(this,
                          QString::fromUtf8("Write File Error"),
                          QString::fromUtf8("Could not write into file: ") + fileName);
}
