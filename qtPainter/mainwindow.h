#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void paintEvent(QPaintEvent *event);
    void resizeEvent(QResizeEvent* e);
    QPen roundPen(QColor color, int width);
    QBrush fillBrush(QColor color);
    float sc();
    int h, w;

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
