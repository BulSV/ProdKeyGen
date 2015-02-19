#ifndef LICENSEFILEGEN_H
#define LICENSEFILEGEN_H

#include <QObject>
#include <QDate>
#include <QString>
#include <QFile>

class LicenseFileGen : public QObject
{
    Q_OBJECT
public:
    LicenseFileGen(QDate startDate,
                   QDate endDate,
                   const QString &fileName = "LicenseFile.dat",
                   QObject *parent = 0);
public slots:
    void generate();
    void setStartDate(QDate startDate);
    void setEndDate(QDate endDate);
    void setLicenseFileName(const QString &fileName);
signals:
    void licenseFileGenerated(QString);
    void writeFileError(QString);
    void openFileError(QString);
private:
    QDate m_StartDate;
    QDate m_EndDate;
    QFile m_LicenseFile;
};

#endif // LICENSEFILEGEN_H
