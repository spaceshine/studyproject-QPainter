#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <QResizeEvent>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    h = this->size().height();
    w = this->size().width();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::resizeEvent(QResizeEvent* e)
{
    h = e->size().height();
    w = e->size().width();
    repaint();
}

QPen MainWindow::roundPen(QColor color, int width=3){
    QPen pen;
    pen.setWidth(width*sc());
    pen.setBrush(color);
    pen.setCapStyle(Qt::RoundCap);
    pen.setJoinStyle(Qt::RoundJoin);
    return pen;
}

QBrush MainWindow::fillBrush(QColor color){
    return QBrush(color, Qt::SolidPattern);
}

float MainWindow::sc(){
    return (w/900.0f+h/600.0f)/2;
}

void MainWindow::paintEvent(QPaintEvent *event){
    Q_UNUSED(event);
    QPainter p(this);

    // 600 x 900
    // #23b6f5

    p.setPen(roundPen(QColor("#6ad2ff")));
    p.setBrush(fillBrush(QColor("#6ad2ff")));
    p.drawRect(-15*sc(), -15*sc(), w+15*sc(), h+15*sc());

    p.setPen(roundPen(Qt::green));
    p.setBrush(fillBrush(Qt::green));
    p.drawRect(0, h-300*sc(), w, 300*sc());

    p.setPen(roundPen(Qt::yellow, 15));
    p.setBrush(fillBrush(QColor("#6a97ff")));
    p.drawRect(-15*sc(), h-180*sc(), w+40*sc(), 100*sc());

    p.setPen(roundPen(QColor("#713b08")));
    p.setBrush(fillBrush(QColor("#713b08")));
    p.drawRect(150*sc(), h-380*sc(), 40*sc(), 130*sc());
    p.setPen(roundPen(Qt::green));
    p.setBrush(fillBrush(Qt::green));
    p.drawEllipse(95*sc(), h-465*sc(), 150*sc(), 150*sc());

    p.setPen(roundPen(QColor("#713b08")));
    p.setBrush(fillBrush(QColor("#713b08")));
    p.drawRect(500*sc(), h-380*sc(), 40*sc(), 130*sc());
    p.setPen(roundPen(Qt::green));
    p.setBrush(fillBrush(Qt::green));
    p.drawEllipse(445*sc(), h-465*sc(), 150*sc(), 150*sc());

    p.setPen(roundPen(QColor("#713b08")));
    p.setBrush(fillBrush(QColor("#713b08")));
    p.drawRect(700*sc(), h-380*sc(), 40*sc(), 130*sc());
    p.setPen(roundPen(Qt::green));
    p.setBrush(fillBrush(Qt::green));
    p.drawEllipse(645*sc(), h-465*sc(), 150*sc(), 150*sc());

    ui->lblEifel->setGeometry(235*sc(), h-530*sc(), 225*sc(), 300*sc());
    ui->lblPlazh->setGeometry(100*sc(), h-180*sc(), 180*sc(), 160*sc());

    p.setPen(roundPen(Qt::yellow));
    p.setBrush(fillBrush(Qt::yellow));
    p.drawEllipse(w-100*sc(), -50, 150*sc(), 150*sc());

    p.setPen(roundPen(Qt::white)); p.setBrush(fillBrush(Qt::white));
    p.drawEllipse(w-400*sc(), -50, 150*sc(), 100*sc());
    p.setPen(roundPen(Qt::white)); p.setBrush(fillBrush(Qt::white));
    p.drawEllipse(w-500*sc(), 10, 150*sc(), 100*sc());
    p.setPen(roundPen(Qt::white)); p.setBrush(fillBrush(Qt::white));
    p.drawEllipse(w-420*sc(), 10, 150*sc(), 100*sc());

    p.setPen(roundPen(Qt::white)); p.setBrush(fillBrush(Qt::white));
    p.drawEllipse(w-700*sc(), -50, 150*sc(), 100*sc());
    p.setPen(roundPen(Qt::white)); p.setBrush(fillBrush(Qt::white));
    p.drawEllipse(w-760*sc(), 10, 150*sc(), 100*sc());
    p.setPen(roundPen(Qt::white)); p.setBrush(fillBrush(Qt::white));
    p.drawEllipse(w-720*sc(), 10, 150*sc(), 100*sc());
}

