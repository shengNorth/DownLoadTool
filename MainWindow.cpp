#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    dT = new DownloadTool("https://desktop.docker.com/win/main/amd64/Docker%20Desktop%20Installer.exe",
                          QApplication::applicationDirPath() + "/download");
    connect(ui->pushButton, &QPushButton::clicked, this, [this](){
          dT->startDownload();
    });

    qDebug() << QSslSocket::sslLibraryBuildVersionNumber();	// 返回编译时SSL(静态库)版本号
    qDebug() << QSslSocket::sslLibraryBuildVersionString();	// 返回编译时SSL(静态库)版本字符串
    qDebug() << QSslSocket::sslLibraryVersionNumber();      // 返回运行时SSL库版本号
    qDebug() << QSslSocket::sslLibraryVersionString();		// 返回运行时SSL库版本字符串
    qDebug() << QSslSocket::supportsSsl();                  // 返回是否支持SSL true支持/false不支持
}

MainWindow::~MainWindow()
{
    delete ui;
}

