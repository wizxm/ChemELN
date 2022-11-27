#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
	: QMainWindow(parent)
	, ui(new Ui::MainWindow)
{
	setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);

	ui->setupUi(this);
}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::mousePressEvent(QMouseEvent* e)
{
	if (e->button() == Qt::LeftButton)
	{
		is_drag_ = true;
		//������ĳ�ʼλ��
		window_start_y = e->y();
		mouse_start_point_ = e->globalPos();
		//��ô��ڵĳ�ʼλ��
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
	//�ж��Ƿ�����ק�ƶ�
	if (is_drag_)
	{
		//�������ƶ��ľ���
		QPoint move_distance = e->globalPos() - mouse_start_point_;
		//�ı䴰�ڵ�λ��
		this->move(window_start_point_ + move_distance);
	}
}




