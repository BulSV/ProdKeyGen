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

class Dialog : public QDialog
{
    Q_OBJECT

    QCalendarWidget *cwDate;
    QPushButton *bSetStartDate;
    QPushButton *bSetEndDate;
    QLabel *lStartDate;
    QGroupBox *gbInfo;
    QLabel *lEndDate;
    QLabel *lLicenseFileName;
    QLineEdit *leLicenseFileName;
    QPushButton *bGenerateLicenseFile;
private slots:

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();
};

#endif // DIALOG_H
