#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWebFrame>
#include <QWebView>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void loadHtmLFIle();

private:
    QWidget* widget;
    QWebView* webView;
};

#endif // MAINWINDOW_H
