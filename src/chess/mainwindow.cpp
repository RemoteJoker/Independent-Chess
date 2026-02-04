#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    const int BTN_WIDTH = width()*0.4;
    const int BTN_HEIGHT = height()*0.08;
    const int SUB_WIDGET_HEIGHT = height()*0.3;

    g_game_entity = new GameEntity;

    m_init_view = new QWidget(this);
    m_init_view->setFixedSize(width(), height());
    QVBoxLayout* v_init_layout = new QVBoxLayout(m_init_view);
    v_init_layout->setContentsMargins(0, 0, 0, 0);
    v_init_layout->setSpacing(0);
    v_init_layout->addStretch(1);
    QPushButton* v_init_single_btn = new QPushButton("单人模式", m_init_view);
    QPushButton* v_init_local_btn = new QPushButton("局域网模式", m_init_view);
    QPushButton* v_init_internet_btn = new QPushButton("互联网模式", m_init_view);
    QPushButton* v_init_set_btn = new QPushButton("设置", m_init_view);
    v_init_single_btn->setFixedSize(BTN_WIDTH, BTN_HEIGHT);
    v_init_local_btn->setFixedSize(BTN_WIDTH, BTN_HEIGHT);
    v_init_internet_btn->setFixedSize(BTN_WIDTH, BTN_HEIGHT);
    v_init_set_btn->setFixedSize(BTN_WIDTH, BTN_HEIGHT);
    v_init_layout->addWidget(v_init_single_btn, 0, Qt::AlignCenter);
    v_init_layout->addStretch(1);
    v_init_layout->addWidget(v_init_local_btn, 0, Qt::AlignCenter);
    v_init_layout->addStretch(1);
    v_init_layout->addWidget(v_init_internet_btn, 0, Qt::AlignCenter);
    v_init_layout->addStretch(1);
    v_init_layout->addWidget(v_init_set_btn, 0, Qt::AlignCenter);
    v_init_layout->addStretch(1);


    m_single_view = new QWidget(this);
    m_single_view->setFixedSize(width(), height());
    m_single_view->hide();
    QVBoxLayout* v_single_layout = new QVBoxLayout(m_single_view);
    v_single_layout->setContentsMargins(0, 0, 0, 0);
    v_single_layout->setSpacing(0);
    v_single_layout->addStretch(1);
    QLabel* v_single_label = new QLabel("单人模式", m_single_view);
    v_single_label->setAlignment(Qt::AlignCenter);
    v_single_label->setStyleSheet("font-size:16px; color:#333;");
    v_single_layout->addWidget(v_single_label, 0, Qt::AlignCenter);
    v_single_layout->addStretch(1);
    QPushButton* v_single_start_btn = new QPushButton("开始", m_single_view);
    v_single_start_btn->setFixedSize(BTN_WIDTH, BTN_HEIGHT);
    v_single_layout->addWidget(v_single_start_btn, 0, Qt::AlignCenter);
    v_single_layout->addStretch(1);
    QPushButton* v_single_return_btn = new QPushButton("返回", m_single_view);
    v_single_return_btn->setFixedSize(BTN_WIDTH, BTN_HEIGHT);
    v_single_layout->addWidget(v_single_return_btn, 0, Qt::AlignCenter);
    v_single_layout->addStretch(1);


    m_local_view = new QWidget(this);
    m_local_view->setFixedSize(width(), height());
    m_local_view->hide();
    QVBoxLayout* v_local_layout = new QVBoxLayout(m_local_view);
    v_local_layout->setContentsMargins(0, 0, 0, 0);
    v_local_layout->setSpacing(0);
    v_local_layout->addStretch(1);
    QLabel* v_local_label = new QLabel("在线模式", m_local_view);
    v_local_label->setAlignment(Qt::AlignCenter);
    v_local_label->setStyleSheet("font-size:16px; color:#333;");
    v_local_layout->addWidget(v_local_label, 0, Qt::AlignCenter);
    v_local_layout->addStretch(1);
    QPushButton* v_local_start_btn = new QPushButton("开始", m_local_view);
    v_local_start_btn->setFixedSize(BTN_WIDTH, BTN_HEIGHT);
    v_local_layout->addWidget(v_local_start_btn, 0, Qt::AlignCenter);
    v_local_layout->addStretch(1);
    QPushButton* v_local_return_btn = new QPushButton("返回", m_local_view);
    v_local_return_btn->setFixedSize(BTN_WIDTH, BTN_HEIGHT);
    v_local_layout->addWidget(v_local_return_btn, 0, Qt::AlignCenter);
    v_local_layout->addStretch(1);


    m_internet_view = new QWidget(this);
    m_internet_view->setFixedSize(width(), height());
    m_internet_view->hide();
    QVBoxLayout* v_internet_layout = new QVBoxLayout(m_internet_view);
    v_internet_layout->setContentsMargins(0, 0, 0, 0);
    v_internet_layout->setSpacing(0);
    v_internet_layout->addStretch(1);
    QLabel* v_internet_label = new QLabel("在线模式", m_internet_view);
    v_internet_label->setAlignment(Qt::AlignCenter);
    v_internet_label->setStyleSheet("font-size:16px; color:#333;");
    v_internet_layout->addWidget(v_internet_label, 0, Qt::AlignCenter);
    v_internet_layout->addStretch(1);
    QPushButton* v_internet_start_btn = new QPushButton("开始", m_internet_view);
    v_internet_start_btn->setFixedSize(BTN_WIDTH, BTN_HEIGHT);
    v_internet_layout->addWidget(v_internet_start_btn, 0, Qt::AlignCenter);
    v_internet_layout->addStretch(1);
    QPushButton* v_internet_return_btn = new QPushButton("返回", m_internet_view);
    v_internet_return_btn->setFixedSize(BTN_WIDTH, BTN_HEIGHT);
    v_internet_layout->addWidget(v_internet_return_btn, 0, Qt::AlignCenter);
    v_internet_layout->addStretch(1);


    m_hall_view = new QWidget(this);
    m_hall_view->setFixedSize(width(),height());
    m_hall_view->hide();


    m_game_view = new QWidget(this);
    m_game_view->setFixedSize(width(), height());
    m_game_view->hide();
    QHBoxLayout* v_hall_main_layout = new QHBoxLayout(m_game_view);
    v_hall_main_layout->setContentsMargins(0, 0, 0, 0);
    v_hall_main_layout->setSpacing(0);
    QWidget* v_hall_left_widget = new QWidget(this);
    v_hall_left_widget->setStyleSheet("background-color: #f0f0f0;");
    int v_hall_view_height = m_game_view->height();
    int v_hall_view_width = v_hall_view_height / 12 * 10;
    v_hall_left_widget->setFixedWidth(v_hall_view_width);
    QWidget* v_hall_right_widget = new QWidget(this);
    QVBoxLayout* v_hall_right_layout = new QVBoxLayout(v_hall_right_widget);
    v_hall_right_layout->setContentsMargins(10, 10, 10, 10);
    v_hall_right_layout->setSpacing(15);
    v_hall_right_layout->setAlignment(Qt::AlignCenter);
    QWidget* v_hall_top_1_widget = new QWidget(this);
    QWidget* v_hall_top_2_widget = new QWidget(this);
    v_hall_top_1_widget->setFixedSize(BTN_WIDTH, SUB_WIDGET_HEIGHT);
    v_hall_top_2_widget->setFixedSize(BTN_WIDTH, SUB_WIDGET_HEIGHT);
    v_hall_top_1_widget->setStyleSheet("background-color: #d0e8ff;");
    v_hall_top_2_widget->setStyleSheet("background-color: #d0e8ff;");
    v_hall_right_layout->addWidget(v_hall_top_1_widget, 0, Qt::AlignCenter);
    v_hall_right_layout->addWidget(v_hall_top_2_widget, 0, Qt::AlignCenter);
    QPushButton* v_hall_1_btn = new QPushButton("游戏开始");
    QPushButton* v_hall_2_btn = new QPushButton("暂停");
    QPushButton* v_hall_3_btn = new QPushButton("退出");
    QList<QPushButton*> v_hall_btn_list = {v_hall_1_btn, v_hall_2_btn, v_hall_3_btn};
    for (auto btn : v_hall_btn_list) {
        btn->setFixedSize(BTN_WIDTH, BTN_HEIGHT);
        v_hall_right_layout->addWidget(btn, 0, Qt::AlignCenter);
    }
    v_hall_right_layout->addStretch();
    v_hall_main_layout->addWidget(v_hall_left_widget);
    v_hall_main_layout->addWidget(v_hall_right_widget);


    m_result_view = new QWidget(this);
    m_result_view->setFixedSize(width(), height());
    m_result_view->hide();
    QVBoxLayout* v_result_layout = new QVBoxLayout(m_result_view);
    v_result_layout->setContentsMargins(0, 0, 0, 0);
    v_result_layout->setSpacing(0);
    v_result_layout->addStretch(1);
    QLabel* v_result_label = new QLabel("结果展示区域", m_result_view);
    v_result_label->setAlignment(Qt::AlignCenter);
    v_result_label->setStyleSheet("font-size:16px; color:#333;");
    v_result_layout->addWidget(v_result_label, 0, Qt::AlignCenter);
    v_result_layout->addStretch(1);
    QPushButton* v_result_btn = new QPushButton("确认", m_result_view);
    v_result_btn->setFixedSize(BTN_WIDTH, BTN_HEIGHT);
    v_result_layout->addWidget(v_result_btn, 0, Qt::AlignCenter);
    v_result_layout->addStretch(1);


    m_setting_view = new QWidget(this);
    m_setting_view->setFixedSize(width(), height());
    m_setting_view->hide();
    QGridLayout* gridLayout = new QGridLayout(m_setting_view);
    gridLayout->setContentsMargins(0, 0, 0, 0);
    gridLayout->setSpacing(20);
    gridLayout->setAlignment(Qt::AlignCenter);
    QPushButton* v_setting_1_btn = new QPushButton("全屏/窗口");
    QPushButton* v_setting_2_btn = new QPushButton("人机难度");
    QPushButton* v_setting_3_btn = new QPushButton("背景音乐");
    QPushButton* v_setting_4_btn = new QPushButton("开机自启动");
    QPushButton* v_setting_5_btn = new QPushButton("保存路径");
    QPushButton* v_setting_6_btn = new QPushButton("卸载游戏");
    QList<QPushButton*> v_setting_btn_list = {v_setting_1_btn, v_setting_2_btn, v_setting_3_btn, v_setting_4_btn, v_setting_5_btn, v_setting_6_btn};
    for (auto btn : v_setting_btn_list) {
        btn->setFixedSize(BTN_WIDTH, BTN_HEIGHT);
    }
    gridLayout->addWidget(v_setting_1_btn, 0, 0, Qt::AlignCenter);
    gridLayout->addWidget(v_setting_2_btn, 1, 0, Qt::AlignCenter);
    gridLayout->addWidget(v_setting_3_btn, 2, 0, Qt::AlignCenter);
    gridLayout->addWidget(v_setting_4_btn, 0, 1, Qt::AlignCenter);
    gridLayout->addWidget(v_setting_5_btn, 1, 1, Qt::AlignCenter);
    gridLayout->addWidget(v_setting_6_btn, 2, 1, Qt::AlignCenter);

    /*----------------------------------------------------------*/
    connect(v_init_single_btn,&QPushButton::clicked,this,[=](){m_init_view->hide();m_single_view->show();});
    connect(v_init_local_btn,&QPushButton::clicked,this,[=](){m_init_view->hide();m_local_view->show();});
    connect(v_init_internet_btn,&QPushButton::clicked,this,[=](){m_init_view->hide();m_internet_view->show();});
    connect(v_init_set_btn,&QPushButton::clicked,this,[=](){m_init_view->hide();m_setting_view->show();});

    connect(v_single_start_btn,&QPushButton::clicked,this,[=](){m_single_view->hide();m_game_view->show();});
    connect(v_single_return_btn,&QPushButton::clicked,this,[=](){m_single_view->hide();m_init_view->show();});
    connect(v_local_start_btn,&QPushButton::clicked,this,[=](){m_local_view->hide();m_game_view->show();});
    connect(v_local_return_btn,&QPushButton::clicked,this,[=](){m_local_view->hide();m_init_view->show();});
    connect(v_internet_start_btn,&QPushButton::clicked,this,[=](){m_internet_view->hide();m_game_view->show();});
    connect(v_internet_return_btn,&QPushButton::clicked,this,[=](){m_internet_view->hide();m_init_view->show();});

    connect(v_result_btn,&QPushButton::clicked,this,[=](){m_result_view->hide();m_init_view->show();});
}

MainWindow::~MainWindow()
{
    delete ui;
}
