#include <ARDrone_GUI/ARDrone_Plugin.h>


int main(int argc, char **argv)
{
    ros::init(argc,argv,"main");

    ros::AsyncSpinner RosSpinner(4);
    RosSpinner.start();


    QApplication app(argc, argv);
    QMainWindow *mainWindow = new ARDrone_Plugin;

    mainWindow->show();
    return app.exec();

}
