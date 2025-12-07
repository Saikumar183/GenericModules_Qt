#include "AppVersionDialog.h"
#include "AppInfo.h"

#include <QDialog>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QDialogButtonBox>
#include <QPixmap>
#include <QIcon>
#include <QApplication>

void AppVersionDialog::show(QWidget *parent)
{
    AppInfo info = getAppInfo();

    QDialog dlg(parent);
    dlg.setWindowTitle(QString("%1 - About").arg(info.appName));
    dlg.setWindowModality(Qt::ApplicationModal);
    dlg.setMinimumWidth(420);

    // --------- Layouts ---------
    auto *mainLayout = new QVBoxLayout(&dlg);

    // Top area: logo + title
    auto *topLayout = new QHBoxLayout;

    // LOGO (from resources, adjust path)
    QLabel *logoLabel = new QLabel(&dlg);
    QPixmap logoPixmap(":/icons/app_logo.png");  // <-- put your icon in .qrc
    if (!logoPixmap.isNull())
    {
        logoLabel->setPixmap(logoPixmap.scaled(64, 64,
                                               Qt::KeepAspectRatio,
                                               Qt::SmoothTransformation));
    }
    else
    {
        logoLabel->setMinimumSize(64, 64);
    }

    auto *titleLayout = new QVBoxLayout;
    QLabel *titleLabel = new QLabel(
                QString("<b>%1</b>  v%2").arg(info.appName, info.version),
                &dlg);
    titleLabel->setTextFormat(Qt::RichText);

    QLabel *subtitleLabel = new QLabel(
                QString("Release date: %1").arg(info.releaseDate),
                &dlg);

    titleLayout->addWidget(titleLabel);
    titleLayout->addWidget(subtitleLabel);
    titleLayout->addStretch();

    topLayout->addWidget(logoLabel);
    topLayout->addLayout(titleLayout);
    topLayout->addStretch();

    mainLayout->addLayout(topLayout);

    // --------- Build / system info ---------
    QString buildText;
    buildText += QString("Build: %1 %2 (%3)\n")
                 .arg(info.buildDate)
                 .arg(info.buildTime)
                 .arg(info.buildType);
    buildText += QString("Qt version: %1\n").arg(info.qtVersion);
    buildText += QString("Git commit: %1\n").arg(info.gitCommitHash);

    QLabel *buildLabel = new QLabel(buildText, &dlg);
    buildLabel->setTextInteractionFlags(Qt::TextSelectableByMouse);
    mainLayout->addWidget(buildLabel);

    // --------- Author / company ---------
    QString authorText;
    if (!info.author.isEmpty())
        authorText += QString("Author: %1\n").arg(info.author);
    if (!info.company.isEmpty())
        authorText += QString("Company: %1\n").arg(info.company);
    if (!info.email.isEmpty())
        authorText += QString("Email: %1\n").arg(info.email);

    if (!authorText.isEmpty())
    {
        QLabel *authorLabel = new QLabel(authorText, &dlg);
        authorLabel->setTextInteractionFlags(Qt::TextSelectableByMouse);
        mainLayout->addWidget(authorLabel);
    }

    // --------- Website (clickable) ---------
    if (!info.website.isEmpty())
    {
        QLabel *linkLabel = new QLabel(&dlg);
        linkLabel->setTextFormat(Qt::RichText);
        linkLabel->setText(
            QString("<a href=\"%1\">%1</a>").arg(info.website));
        linkLabel->setTextInteractionFlags(Qt::TextBrowserInteraction);
        linkLabel->setOpenExternalLinks(true);
        mainLayout->addWidget(linkLabel);
    }

    // --------- Description & features ---------
    if (!info.description.isEmpty())
    {
        QLabel *descLabel = new QLabel(info.description, &dlg);
        descLabel->setWordWrap(true);
        mainLayout->addWidget(descLabel);
    }

    if (!info.features.isEmpty())
    {
        QString featText = "<b>Features:</b><br>";
        for (const QString &f : info.features)
            featText += "• " + f + "<br>";

        QLabel *featLabel = new QLabel(featText, &dlg);
        featLabel->setTextFormat(Qt::RichText);
        mainLayout->addWidget(featLabel);
    }

    // --------- Buttons ---------
    auto *buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok, &dlg);
    QObject::connect(buttonBox, &QDialogButtonBox::accepted,
                     &dlg, &QDialog::accept);
    mainLayout->addWidget(buttonBox);

    dlg.exec();
}
