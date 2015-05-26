/*#include "Bridge.h"

template<class IcePrx>

void Bridge<IcePrx>::rosCallback(RosIceBridge::Num n)
{
    Message::Num m;
    m.value = n.num;
    icePublish(m);


}

template<class IcePrx>
void Bridge<IcePrx>::icePublish(Message::Num message)
{
    this->Proxy->publish2(message);
}
*/
