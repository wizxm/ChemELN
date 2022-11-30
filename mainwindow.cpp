#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <QStyleOption>
#include <QPainter>


MainWindow::MainWindow(QWidget* parent)
	: QMainWindow(parent)
	, ui(new Ui::MainWindow)
{
	setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
	QIcon icon;
	icon.addFile(":/new/prefix1/close.png");
	ui->setupUi(this);
}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::paintEvent(QPaintEvent*)
{
	QStyleOption option;
	option.init(this);
	QPainter painter(this);
	style()->drawPrimitive(QStyle::PE_Widget, &option, &painter, this);
}

void MainWindow::mousePressEvent(QMouseEvent* e)
{
	if (e->button() == Qt::LeftButton)
	{
		is_drag_ = true;
		//获得鼠标的初始位置
		window_start_y = e->y();
		mouse_start_point_ = e->globalPos();
		//获得窗口的初始位置
		window_start_point_ = this->frameGeometry().topLeft();
	}
}

void MainWindow::mouseReleaseEvent(QMouseEvent* e)
{

	if (e->button() == Qt::LeftButton)
	{
		is_drag_ = false;
	}
}

void MainWindow::mouseMoveEvent(QMouseEvent* e)
{
	//
	if (window_start_y >= 50)
	{
		return;
	}
	//判断是否在拖拽移动
	if (is_drag_)
	{
		//获得鼠标移动的距离
		QPoint move_distance = e->globalPos() - mouse_start_point_;
		//改变窗口的位置
		this->move(window_start_point_ + move_distance);
	}
}





