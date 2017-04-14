#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/utility.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <QMessageBox>
#include <QFileDialog>
#include <QTextCodec>

#include "genarate.h"
#include "recognize.h"

using namespace cv;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->textEdit->setPlaceholderText("输入字符");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::DisplayMat(cv::Mat image, QLabel* output)
{
    cv::Mat rgb;
    QImage img;
    if(image.channels() == 3)
    {
        cvtColor(image,rgb,CV_BGR2RGB);
        img = QImage((const unsigned char*)(rgb.data),
                     rgb.cols,rgb.rows,rgb.cols*rgb.channels(),//rgb.cols*rgb.channels()可以替换为image.step
                     QImage::Format_RGB888);
    }
    else
    {
        img = QImage((const unsigned char*)(image.data),
                     image.cols,image.rows,rgb.cols*image.channels(),
                     QImage::Format_Indexed8);
    }
    output->setPixmap(QPixmap::fromImage(img).scaled(output->size()));//setPixelmap(QPixmap::fromImage(img));
    output->resize(output->pixmap()->size());//resize(ui->label->pixmap()->size());
}

void MainWindow::on_pushButton_clicked()
{
    QString str = ui->textEdit->toPlainText();
    if(str == NULL)
    {
        QMessageBox msgBox;
        msgBox.setText("输入字符为空");
        msgBox.exec();
        return;
    }
    QByteArray buffer = str.toLatin1();
    char* input = buffer.data();
    int lenth = strlen(input);
    if(code_template.empty())
    {
        QMessageBox msgBox;
        msgBox.setText("尚未载入模板");
        msgBox.exec();
    }
    code_pic = genarate((unsigned char*)input, lenth, code_template);

    DisplayMat(code_pic, ui->labelimage_genarate);
}

void MainWindow::on_pushButton_2_clicked()
{
    code_template = imread("template.jpg");
    DisplayMat(code_template, ui->labelimage_genarate);
}

void MainWindow::on_pushButton_3_clicked()
{
    code_template = imread("template1.jpg");
    DisplayMat(code_template, ui->labelimage_genarate);
}

void MainWindow::on_pushButton_4_clicked()
{
    code_template = imread("template2.jpg");
    DisplayMat(code_template, ui->labelimage_genarate);
}

void MainWindow::on_pushButton_5_clicked()
{
    if(code_pic.empty())
    {
        QMessageBox msgBox;
        msgBox.setText("尚未生成二维码！");
        msgBox.exec();
        return;
    }
    QMessageBox msgBox;
    msgBox.setText("已输出code.jpg");
    msgBox.exec();
    imwrite("code.jpg", code_pic);
}

void MainWindow::on_pushButton_6_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this,
                       tr("Open Image"),".",tr("Image File (*.jpg *.png *.bmp)"));
    QTextCodec *code = QTextCodec::codecForName("gb18030");
    std::string name = code->fromUnicode(filename).data();//filename.toAscii().data()
    code_pic = cv::imread(name);
    if(code_pic.empty())
    {
        return;
    }
    else {
       DisplayMat(code_pic, ui->labelimage_recognize);
    }
}

void MainWindow::on_pushButton_7_clicked()
{
    if(code_pic.empty())
    {
        QMessageBox msgBox;
        msgBox.setText("尚未载入图片");
        msgBox.exec();
        return;
    }
    recognize(code_pic);
}

void MainWindow::on_pushButton_8_clicked()
{
    if(code_pic.empty())
    {
        QMessageBox msgBox;
        msgBox.setText("尚未生成");
        msgBox.exec();
        return;
    }
    imshow("", code_pic);
}
