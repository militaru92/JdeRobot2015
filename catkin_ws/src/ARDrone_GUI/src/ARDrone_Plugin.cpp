#include <ARDrone_GUI/ARDrone_Plugin.h>

//namespace my_namespace
//{

ARDrone_Plugin::ARDrone_Plugin() : ui(new Ui::MainWindow)
{

    this->takeOff.data = false;
    this->cmdVelData.linearX=this->cmdVelData.linearY=this->cmdVelData.linearZ = 0;
    this->cmdVelData.angularZ = 0;
    this->cmdVelData.angularX = 0.5;
    this->cmdVelData.angularY = 1.0;

    ui->setupUi(this);
    loadUiFile();

    this->teleop = new TeleopWidget(this);
    this->teleop->setVisible(true);

    ui->tlLayout->addWidget(this->teleop);

    this->teleop->repaint();

    QObject::connect(ui->rotationDial,SIGNAL(valueChanged(int)),this,SLOT(setRotationDialValue(int)));
    QObject::connect(ui->altdSlider,SIGNAL(valueChanged(int)),this,SLOT(altitudeChange(int)));
    QObject::connect(ui->stopButton,SIGNAL(clicked(bool)),this->teleop,SLOT(stop()));
    QObject::connect(ui->stopButton,SIGNAL(clicked(bool)),this,SLOT(stop()));
    QObject::connect(ui->takeoffButton,SIGNAL(clicked(bool)),this,SLOT(takeOffClicked()));
    QObject::connect(this->teleop,SIGNAL(setXY(double,double)),this,SLOT(setXYValues(double,double)));

    /*
    std::string nodeName("ARDrone_GUI");
    int argc = 0;

    ros::init(argc, NULL, nodeName);

    */
    RosNode = new ros::NodeHandle;

    this->takeOffPublisher = new ros::Publisher(RosNode->advertise<std_msgs::Bool>("takeOff", 500));
    this->cmdVelPublisher = new ros::Publisher(RosNode->advertise<RosIceMessage::CMDVelData>("cmdVel",500));


}

ARDrone_Plugin::~ARDrone_Plugin()
{
    delete teleop;
    delete ui;
    delete RosNode;
    delete takeOffPublisher;
    delete cmdVelPublisher;

}


QWidget* ARDrone_Plugin::loadUiFile()
{
    QUiLoader loader;

    QFile file("ui_gui.ui");
    file.open(QFile::ReadOnly);

    QWidget *formWidget = loader.load(&file, this);
    file.close();


    return formWidget;
}

void ARDrone_Plugin::setXYValues(double newX, double newY)
{
    this->setVX(newX);
    this->setVY(newY);
    this->sendVelocities();

}

void ARDrone_Plugin::setVX(double vx)
{
    this->cmdVelData.linearX = vx;
}

void ARDrone_Plugin::setVY(double vy)
{
    this->cmdVelData.linearY = vy;
}

void ARDrone_Plugin::setVZ(double vz)
{
    this->cmdVelData.linearZ = vz;
}

void ARDrone_Plugin::setYaw(double yaw)
{
    this->cmdVelData.angularZ = yaw;
}

void ARDrone_Plugin::setRoll(double roll)
{
    this->cmdVelData.angularX = roll;
}

void ARDrone_Plugin::setPitch(double pitch)
{
    this->cmdVelData.angularY = pitch;
}

void ARDrone_Plugin::sendVelocities()
{
    this->cmdVelPublisher->publish(this->cmdVelData);
}


void ARDrone_Plugin::setRotationDialValue(int value)
{
    double val = (1.0/(this->ui->rotationDial->maximum()/2))*(value - (this->ui->rotationDial->maximum()/2));
    this->ui->rotValue->setNum(val);

    this->setYaw(val);

    this->cmdVelPublisher->publish(this->cmdVelData);

}

void ARDrone_Plugin::altitudeChange(int value)
{
    double val= (1.0/(this->ui->altdSlider->maximum()/2))*(value - (this->ui->altdSlider->maximum()/2));
    this->ui->altdValue->setNum(val);

    this->setVZ(val);

    this->cmdVelPublisher->publish(this->cmdVelData);

}

void ARDrone_Plugin::stop()
{
    this->ui->rotationDial->setValue(this->ui->altdSlider->maximum()/2);
    this->ui->altdSlider->setValue(this->ui->altdSlider->maximum()/2);
}


void ARDrone_Plugin::takeOffClicked()
{
    if(this->takeOff.data == true)
    {
        this->takeOff.data = false;
        this->ui->takeoffButton->setText("Take Off");
    }

    else
    {
        this->takeOff.data = true;
        this->ui->takeoffButton->setText("Land");
    }

    this->takeOffPublisher->publish(this->takeOff);

}
