#include "LicenseFileGen.h"
#include <QDataStream>
#include <QMessageBox>

LicenseFileGen::LicenseFileGen(QDate startDate,
                               QDate endDate,
                               const QString &fileName,
                               QObject *parent) :
    QObject(parent)
  , m_StartDate(startDate.year(), startDate.month(), startDate.day())
  , m_EndDate(endDate.year(), endDate.month(), endDate.day())
  , m_LicenseFile(fileName)
{
}

void LicenseFileGen::generate()
{
    QDataStream stream(&m_LicenseFile);
    stream.setVersion(QDataStream::Qt_5_2);

    if(m_LicenseFile.open(QFile::WriteOnly)) {
        stream << m_StartDate;
        stream << m_EndDate;
        stream << m_StartDate;

        if(stream.status() != QDataStream::Ok)
        {
            emit writeFileError(QString::fromUtf8("Could not write into file: ") + m_LicenseFile.fileName());
        }

        m_LicenseFile.close();

        emit licenseFileGenerated(m_LicenseFile.fileName());
    } else {
        emit openFileError(QString::fromUtf8("Could not create file: ") + m_LicenseFile.fileName());
    }
}

void LicenseFileGen::setStartDate(QDate startDate)
{
    m_StartDate.setDate(startDate.year(), startDate.month(), startDate.day());
}

void LicenseFileGen::setEndDate(QDate endDate)
{
    m_EndDate.setDate(endDate.year(), endDate.month(), endDate.day());
}

void LicenseFileGen::setLicenseFileName(const QString &fileName)
{
    m_LicenseFile.setFileName(fileName);
}
