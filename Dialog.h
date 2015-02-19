#ifndef DIALOG_H
#define DIALOG_H

#ifdef DEBUG
#include <QDebug>
#endif

#include <QDialog>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QCalendarWidget>
#include <QGroupBox>
#include <QStatusBar>
#include "LicenseFileGen.h"

class Dialog : public QDialog
{
    Q_OBJECT
public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();
private:
    QCalendarWidget *cwDate;
    QPushButton *bSetStartDate;
    QPushButton *bSetEndDate;
    QGroupBox *gbInfo;
    QLabel *lStartDate;
    QLabel *lEndDate;
    QLabel *lLicenseFileName;
    QLineEdit *leLicenseFileName;
    QPushButton *bGenerateLicenseFile;
    QStatusBar *sbarInfo;

    LicenseFileGen *licenseFileGen;
private slots:
    void setStartDate();
    void setEndDate();
    void generateLicenseFile();
    void openFileError(const QString &fileName);
    void writeFileError(const QString &fileName);
    void licenseFileGenerated(const QString &fileName);
};

#endif // DIALOG_H
