#include "mainwindow.h"

#include <QHBoxLayout>
#include <QWebView>
#include <QUrl>
#include <QFileDialog>
#include <QMessageBox>

#include "investmentpluginfactory.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    widget = new QWidget;
    setCentralWidget(widget);
    QHBoxLayout* layout = new QHBoxLayout;
    webView = new QWebView(this);
    layout->addWidget(webView);
    widget->setLayout(layout);
    this->setWindowTitle("Browser As Plugin");
    loadHtmLFIle ();
}

MainWindow::~MainWindow()
{

}

void MainWindow::loadHtmLFIle ()
{
    QString filename = QFileDialog::getOpenFileName(this, "Choose an html file:", "../*.html", "Files(*.html,*.htm)");
    if(!filename.isEmpty()){
        QUrl page = QUrl::fromLocalFile(filename);
        webView->load(page);
        webView->page()->settings()->setAttribute(QWebSettings::PluginsEnabled, true);
        webView->page()->setPluginFactory(new InvestmentPluginFactory());
    }
    else
    QMessageBox::warning(this,"Error", "Choose an appropriate file");
}
