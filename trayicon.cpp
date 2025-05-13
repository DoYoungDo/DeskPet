#include "trayicon.h"

#include "pet.h"
#include "petfactory.h"
#include "petmanager.h"

#include <QApplication>
#include <QMenu>
#include <QPointer>
#include <QPushButton>
#include <QSlider>
#include <QTimer>
#include <QWidgetAction>


TrayIcon::TrayIcon(QObject *parent)
    : QSystemTrayIcon{parent}
{
    setup();
}

void TrayIcon::setup()
{
    this->setIcon(QIcon(":/icon.svg"));
    this->setToolTip("Pet");

    QMenu* menu = new QMenu;
    menu->addAction("偏好设置", QKeySequence::Preferences, [](){
    });
    menu->addAction("孵化", [this](){
        if(PetManager::instance()->petCount() > 0)
        {
            this->showMessage("","已经存在一个宠物了。。。");
            return;
        }

        Pet* pet = PetFactory::instance()->createPet();
        if(!pet)
        {
            qInfo() << "pet created failed.";
            return;
        }
        qInfo() << "pet created, show it.";
        pet->show();
    });


    menu->addSeparator();
    QAction * mouseTransparent = new QAction("鼠标穿透");
    mouseTransparent->setCheckable(true);
    mouseTransparent->setChecked(true);
    connect(mouseTransparent, &QAction::toggled, this, [mouseTransparent](bool checked){
        auto pets = PetManager::instance()->pets();
        for(auto pet : pets)
        {
            pet->setMouseTransparent(checked);
            QTimer::singleShot(0,[pet]{
               pet->show();
            });
        }
    });
    menu->addAction(mouseTransparent);


    QSlider* opacitySlider = new QSlider(Qt::Horizontal);
    opacitySlider->setRange(0, 100);
    opacitySlider->setValue(70);
    connect(opacitySlider, &QSlider::valueChanged, this, [](int value){
        auto pets = PetManager::instance()->pets();
        for(auto pet : pets)
        {
            double o = (double)value / (double)100;
            qDebug() << value << o;
            pet->setWindowOpacity(o);
        }
    });
    QMenu* opacityMenu = new QMenu("不透明度");
    QWidgetAction* a = new QWidgetAction(opacityMenu);
    a->setDefaultWidget(opacitySlider);
    opacityMenu->addAction(a);
    menu->addMenu(opacityMenu);


    menu->addSeparator();
    menu->addAction("退出", QKeySequence::Quit, [](){
        qApp->quit();
    });

    this->setContextMenu(menu);

}
