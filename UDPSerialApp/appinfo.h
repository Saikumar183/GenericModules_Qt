#pragma once

#include <QString>
#include <QStringList>
#include <QtGlobal>

// If you define this in your .pro / CMake, it will override "unknown"
#ifndef GIT_COMMIT_HASH
#define GIT_COMMIT_HASH "unknown"
#endif

struct AppInfo
{
    QString appName;
    QString version;
    QString releaseDate;   // human release date (can be different from build)
    QString buildDate;     // compiler date
    QString buildTime;     // compiler time
    QString buildType;     // Debug / Release
    QString qtVersion;

    QString author;
    QString company;
    QString email;
    QString website;

    QString gitCommitHash;
    QString description;

    QStringList features;  // e.g. {"Modbus Master", "Modbus Slave", "UDP", "Serial"}
};

inline AppInfo getAppInfo()
{
    AppInfo info;

    // 🔹 BASIC APP INFO – EDIT THESE
    info.appName     = "ProtocolsApp";
    info.version     = "1.0.1";
    info.releaseDate = "2026-01-09";  // <- update on official release

    // 🔹 BUILD INFO – AUTOMATIC
    info.buildDate   = __DATE__;
    info.buildTime   = __TIME__;
#ifdef QT_DEBUG
    info.buildType   = "Debug";
#else
    info.buildType   = "Release";
#endif
    info.qtVersion   = QT_VERSION_STR;

    // 🔹 AUTHOR / COMPANY
    info.author      = "SaiKumarBilla";
    info.company     = "Your Company";
    info.email       = "you@example.com";
    info.website     = "https://example.com";

    // 🔹 GIT COMMIT (override in .pro if you want)
    info.gitCommitHash = GIT_COMMIT_HASH;

    // 🔹 DESCRIPTION + FEATURES
    info.description =
        "ProtocolsApp is a Modbus, Serial and UDP testing and debug tool "
        "for embedded and PC-side development.";

    info.features << "Modbus Master"
                  << "Modbus Slave"
                  << "UDP"
                  << "Serial"
                  << "Hex / Dec / Bin views"
                  << "Endian viewer";

    return info;
}
