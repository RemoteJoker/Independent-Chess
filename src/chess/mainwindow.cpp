#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "utils/utils.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowTitle(tr("象棋"));
    setFixedSize(800,600);

    m_user_select_mode = NoneModule;
    s_show_mode = false;
    s_ai_level = Easy;

    t_chess_internet = new ChessInternet;
    t_chess_local = new ChessLocal;

    const int BTN_WIDTH = width()*0.4;
    const int BTN_HEIGHT = height()*0.08;
    const int SUB_WIDGET_HEIGHT = height()*0.3;

    g_game_entity = new GameEntity;

    /*----------------------------------------------------------*/
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
    QHBoxLayout* v_game_main_layout = new QHBoxLayout(m_game_view);
    v_game_main_layout->setContentsMargins(0, 0, 0, 0);
    v_game_main_layout->setSpacing(0);
    QWidget* v_game_left_widget = new QWidget(this);
    v_game_left_widget->setStyleSheet("background-color: #f0f0f0;");
    int v_game_view_height = m_game_view->height();
    int v_game_view_width = v_game_view_height / 12 * 10;
    v_game_left_widget->setFixedWidth(v_game_view_width);
    QWidget* v_game_right_widget = new QWidget(this);
    QVBoxLayout* v_game_right_layout = new QVBoxLayout(v_game_right_widget);
    v_game_right_layout->setContentsMargins(10, 10, 10, 10);
    v_game_right_layout->setSpacing(15);
    v_game_right_layout->setAlignment(Qt::AlignCenter);
    QWidget* v_game_top_1_widget = new QWidget(this);
    QWidget* v_game_top_2_widget = new QWidget(this);
    v_game_top_1_widget->setFixedSize(BTN_WIDTH, SUB_WIDGET_HEIGHT);
    v_game_top_2_widget->setFixedSize(BTN_WIDTH, SUB_WIDGET_HEIGHT);
    v_game_top_1_widget->setStyleSheet("background-color: #d0e8ff;");
    v_game_top_2_widget->setStyleSheet("background-color: #d0e8ff;");
    v_game_right_layout->addWidget(v_game_top_1_widget, 0, Qt::AlignCenter);
    v_game_right_layout->addWidget(v_game_top_2_widget, 0, Qt::AlignCenter);
    QPushButton* v_game_1_btn = new QPushButton("准备");
    QPushButton* v_game_2_btn = new QPushButton("返回");
    QPushButton* v_game_3_btn = new QPushButton("退出");
    QList<QPushButton*> v_game_btn_list = {v_game_1_btn, v_game_2_btn, v_game_3_btn};
    for (auto btn : v_game_btn_list) {
        btn->setFixedSize(BTN_WIDTH, BTN_HEIGHT);
        v_game_right_layout->addWidget(btn, 0, Qt::AlignCenter);
    }
    v_game_right_layout->addStretch();
    v_game_main_layout->addWidget(v_game_left_widget);
    v_game_main_layout->addWidget(v_game_right_widget);

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
    QPushButton* v_setting_7_btn = new QPushButton("返回");
    QList<QPushButton*> v_setting_btn_list = {v_setting_1_btn, v_setting_2_btn, v_setting_3_btn, v_setting_4_btn, v_setting_5_btn, v_setting_6_btn, v_setting_7_btn};
    for (auto btn : v_setting_btn_list) {
        btn->setFixedSize(BTN_WIDTH, BTN_HEIGHT);
    }
    gridLayout->addWidget(v_setting_1_btn, 0, 0, Qt::AlignCenter);
    gridLayout->addWidget(v_setting_2_btn, 1, 0, Qt::AlignCenter);
    gridLayout->addWidget(v_setting_3_btn, 2, 0, Qt::AlignCenter);
    gridLayout->addWidget(v_setting_4_btn, 0, 1, Qt::AlignCenter);
    gridLayout->addWidget(v_setting_5_btn, 1, 1, Qt::AlignCenter);
    gridLayout->addWidget(v_setting_6_btn, 2, 1, Qt::AlignCenter);
    gridLayout->addWidget(v_setting_7_btn, 3, 0, 1, 2, Qt::AlignCenter);

    /*----------------------------------------------------------*/
    connect(v_init_single_btn,&QPushButton::clicked,this,[=](){m_init_view->hide();m_single_view->show();});
    connect(v_init_local_btn,&QPushButton::clicked,this,[=](){m_init_view->hide();m_local_view->show();});
    connect(v_init_internet_btn,&QPushButton::clicked,this,[=](){m_init_view->hide();m_internet_view->show();});
    connect(v_init_set_btn,&QPushButton::clicked,this,[=](){m_init_view->hide();m_setting_view->show();});

    connect(v_single_start_btn,&QPushButton::clicked,this,[=](){m_single_view->hide();m_game_view->show();m_user_select_mode = SingleModule;g_game_entity->FlushGame(v_game_left_widget,m_user_select_mode);});
    connect(v_single_return_btn,&QPushButton::clicked,this,[=](){m_single_view->hide();m_init_view->show();});
    connect(v_local_start_btn,&QPushButton::clicked,this,[=](){m_local_view->hide();m_game_view->show();m_user_select_mode = LocalModule;g_game_entity->FlushGame(v_game_left_widget,m_user_select_mode);});
    connect(v_local_return_btn,&QPushButton::clicked,this,[=](){m_local_view->hide();m_init_view->show();});
    connect(v_internet_start_btn,&QPushButton::clicked,this,[=](){m_internet_view->hide();m_game_view->show();m_user_select_mode = InteretModule;g_game_entity->FlushGame(v_game_left_widget,m_user_select_mode);});
    connect(v_internet_return_btn,&QPushButton::clicked,this,[=](){m_internet_view->hide();m_init_view->show();});

    connect(v_result_btn,&QPushButton::clicked,this,[=](){m_result_view->hide();m_init_view->show();});

    connect(v_game_1_btn,&QPushButton::clicked,this,[=](){});
    connect(v_game_2_btn,&QPushButton::clicked,this,[=](){m_game_view->hide();m_init_view->show();});
    connect(v_game_3_btn,&QPushButton::clicked,this,[=](){qApp->quit();});

    connect(v_setting_1_btn,&QPushButton::clicked,this,[=](){CheckShowMode();});
    connect(v_setting_2_btn,&QPushButton::clicked,this,[=](){SelectAiLevel();});
    connect(v_setting_3_btn,&QPushButton::clicked,this,[=](){SetBackMusic();});
    connect(v_setting_4_btn,&QPushButton::clicked,this,[=](){EnableStart();});
    connect(v_setting_5_btn,&QPushButton::clicked,this,[=](){SavePath();});
    connect(v_setting_6_btn,&QPushButton::clicked,this,[=](){DeleteGame();});
    connect(v_setting_7_btn,&QPushButton::clicked,this,[=](){m_setting_view->hide();m_init_view->show();});

    t_chess_internet->start();
    t_chess_local->start();
}

MainWindow::~MainWindow()
{
    delete ui;
}

//全屏/窗口
void MainWindow::CheckShowMode(){
    if(s_show_mode){
        setFixedSize(800,600);
        this->move(30,30);
    }else{
        setFixedSize(QGuiApplication::primaryScreen()->geometry().width(),QGuiApplication::primaryScreen()->geometry().height());
        this->move(0,0);
    }
    s_show_mode = !s_show_mode;
}

//人机难度
void MainWindow::SelectAiLevel(){
    QDialog v_dialog;
    v_dialog.setWindowTitle("选择人机难度");
    v_dialog.setFixedSize(300, 200);
    QRadioButton* v_simple_btn = new QRadioButton("简单", &v_dialog);
    QRadioButton* v_normal_btn = new QRadioButton("正常", &v_dialog);
    QRadioButton* v_master_btn = new QRadioButton("大师", &v_dialog);
    v_normal_btn->setChecked(true);
    QButtonGroup* v_level_group = new QButtonGroup(&v_dialog);
    v_level_group->addButton(v_simple_btn, Easy);
    v_level_group->addButton(v_normal_btn, Normal);
    v_level_group->addButton(v_master_btn, Master);
    QPushButton* v_ok_btn = new QPushButton("确认", &v_dialog);
    QPushButton* v_cancel_btn = new QPushButton("取消", &v_dialog);
    QVBoxLayout* v_main_layout = new QVBoxLayout(&v_dialog);
    QHBoxLayout* v_btn_layout = new QHBoxLayout();
    v_main_layout->addWidget(v_simple_btn);
    v_main_layout->addWidget(v_normal_btn);
    v_main_layout->addWidget(v_master_btn);
    v_main_layout->addStretch();
    v_btn_layout->addStretch();
    v_btn_layout->addWidget(v_ok_btn);
    v_btn_layout->addWidget(v_cancel_btn);
    v_btn_layout->addStretch();
    v_main_layout->addLayout(v_btn_layout);
    QObject::connect(v_ok_btn, &QPushButton::clicked, &v_dialog, &QDialog::accept);
    QObject::connect(v_cancel_btn, &QPushButton::clicked, &v_dialog, &QDialog::reject);
    int v_result = v_dialog.exec();

    if (v_result == QDialog::Accepted) {
        s_ai_level = static_cast<E_Ai_Level>(v_level_group->checkedId());
    } else {
        QMessageBox::information(&v_dialog, "提示", "未选择难度，默认使用简单难度");
    }
}

//背景音乐
void MainWindow::SetBackMusic(){
    QUrl v_file_url = QUrl::fromLocalFile(QFileDialog::getOpenFileName(this, "选择音频文件", "", "音频文件 (*.wav)"));
    if(!v_file_url.isEmpty()){
        if(Utils::ChangeMusic(v_file_url)){
            QMessageBox::information(nullptr,"信息","设置音乐成功");
        }else{
            QMessageBox::warning(nullptr,"信息","设置音乐失败");
        }
    }
}

//开机自启动
void MainWindow::EnableStart(){
    if(Utils::EnableGame()){
        QMessageBox::information(nullptr,"信息","设置开机自启动成功");
    }else{
        QMessageBox::information(nullptr,"信息","设置开机自启动失败");
    }
}

//保存路径
void MainWindow::SavePath(){
    QString v_selected_path = QFileDialog::getExistingDirectory(nullptr,"选择保存路径",QDir::homePath(),QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
    if(Utils::SavePath(v_selected_path)){
        QMessageBox::information(nullptr,"信息","保存路径修改成功");
    }else{
        QMessageBox::information(nullptr,"信息","保存路径修改失败");
    }
}

//卸载游戏
void MainWindow::DeleteGame(){
    if(Utils::DeleteGame()){
        QMessageBox::information(nullptr,"信息","卸载成功");
    }else{
        QMessageBox::information(nullptr,"信息","卸载失败");
    }
}


void MainWindow::resizeEvent(QResizeEvent *event)
{
    QMainWindow::resizeEvent(event);

    int w = this->width();
    int h = this->height();
    int btnW = w * 0.4;
    int btnH = h * 0.08;
    for (QPushButton *btn : findChildren<QPushButton*>()) {
        btn->setFixedSize(btnW, btnH);
    }
    QList<QWidget*> views = {m_init_view, m_single_view, m_local_view,
                              m_internet_view, m_hall_view, m_game_view,
                              m_result_view, m_setting_view};
    for (QWidget *view : views) {
        view->setFixedSize(w, h);
    }
}
