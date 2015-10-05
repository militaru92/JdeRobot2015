#ifndef ARDRONE_PLUGIN_H
#define ARDRONE_PLUGIN_H

#include "ros/ros.h"
#include <ui_ui_gui.h>
#include <ARDrone_GUI/TeleopWidget.h>
#include <ARDrone_GUI/CMDVelData.h>
#include <std_msgs/Bool.h>
#include <QMainWindow>
#include <QtUiTools/QUiLoader>
#include <QFile>




class ARDrone_Plugin : public QMainWindow
{
    Q_OBJECT
public:

    ARDrone_Plugin();
    virtual ~ARDrone_Plugin();



    void setVX(double vx);

    void setVY(double vy);

    void setVZ(double vz);

    void setYaw(double yaw);

    void setRoll(double roll);

    void setPitch(double pitch);

    void sendVelocities();

public slots:

    void setRotationDialValue(int value);
    void altitudeChange(int value);
    void takeOffClicked();
    void stop();
    void setXYValues(double newX, double newY);


private:
    Ui::MainWindow *ui;

    TeleopWidget *teleop;

    QWidget* loadUiFile();

    std_msgs::Bool takeOff;

    RosIceMessage::CMDVelData cmdVelData;


    ros::NodeHandle* RosNode;
    ros::Publisher* takeOffPublisher;
    ros::Publisher* cmdVelPublisher;
};


#endif // ARDRONE_PLUGIN_H
