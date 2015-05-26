// **********************************************************************
//
// Copyright (c) 2003-2013 ZeroC, Inc. All rights reserved.
//
// This copy of Ice is licensed to you under the terms described in the
// ICE_LICENSE file included in this distribution.
//
// **********************************************************************
//
// Ice version 3.5.1
//
// <auto-generated>
//
// Generated from file `Num.ice'
//
// Warning: do not edit this file.
//
// </auto-generated>
//

#include <Num.h>
#include <Ice/LocalException.h>
#include <Ice/ObjectFactory.h>
#include <Ice/BasicStream.h>
#include <Ice/Object.h>
#include <IceUtil/Iterator.h>

#ifndef ICE_IGNORE_VERSION
#   if ICE_INT_VERSION / 100 != 305
#       error Ice version mismatch!
#   endif
#   if ICE_INT_VERSION % 100 > 50
#       error Beta header file detected
#   endif
#   if ICE_INT_VERSION % 100 < 1
#       error Ice patch level mismatch!
#   endif
#endif

namespace
{

const ::std::string __Message__Monitor__publish2_name = "publish2";

}

namespace Ice
{
}
::IceProxy::Ice::Object* ::IceProxy::Message::upCast(::IceProxy::Message::Monitor* p) { return p; }

void
::IceProxy::Message::__read(::IceInternal::BasicStream* __is, ::IceInternal::ProxyHandle< ::IceProxy::Message::Monitor>& v)
{
    ::Ice::ObjectPrx proxy;
    __is->read(proxy);
    if(!proxy)
    {
        v = 0;
    }
    else
    {
        v = new ::IceProxy::Message::Monitor;
        v->__copyFrom(proxy);
    }
}

void
IceProxy::Message::Monitor::publish2(const ::Message::Num& m, const ::Ice::Context* __ctx)
{
    ::IceInternal::InvocationObserver __observer(this, __Message__Monitor__publish2_name, __ctx);
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __delBase = __getDelegate(false);
            ::IceDelegate::Message::Monitor* __del = dynamic_cast< ::IceDelegate::Message::Monitor*>(__delBase.get());
            __del->publish2(m, __ctx, __observer);
            return;
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapper(__delBase, __ex, __observer);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, true, __cnt, __observer);
        }
    }
}

::Ice::AsyncResultPtr
IceProxy::Message::Monitor::begin_publish2(const ::Message::Num& m, const ::Ice::Context* __ctx, const ::IceInternal::CallbackBasePtr& __del, const ::Ice::LocalObjectPtr& __cookie)
{
    ::IceInternal::OutgoingAsyncPtr __result = new ::IceInternal::OutgoingAsync(this, __Message__Monitor__publish2_name, __del, __cookie);
    try
    {
        __result->__prepare(__Message__Monitor__publish2_name, ::Ice::Normal, __ctx);
        ::IceInternal::BasicStream* __os = __result->__startWriteParams(::Ice::DefaultFormat);
        __os->write(m);
        __result->__endWriteParams();
        __result->__send(true);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __result->__exceptionAsync(__ex);
    }
    return __result;
}

void
IceProxy::Message::Monitor::end_publish2(const ::Ice::AsyncResultPtr& __result)
{
    __end(__result, __Message__Monitor__publish2_name);
}

const ::std::string&
IceProxy::Message::Monitor::ice_staticId()
{
    return ::Message::Monitor::ice_staticId();
}

::IceInternal::Handle< ::IceDelegateM::Ice::Object>
IceProxy::Message::Monitor::__createDelegateM()
{
    return ::IceInternal::Handle< ::IceDelegateM::Ice::Object>(new ::IceDelegateM::Message::Monitor);
}

::IceInternal::Handle< ::IceDelegateD::Ice::Object>
IceProxy::Message::Monitor::__createDelegateD()
{
    return ::IceInternal::Handle< ::IceDelegateD::Ice::Object>(new ::IceDelegateD::Message::Monitor);
}

::IceProxy::Ice::Object*
IceProxy::Message::Monitor::__newInstance() const
{
    return new Monitor;
}

void
IceDelegateM::Message::Monitor::publish2(const ::Message::Num& m, const ::Ice::Context* __context, ::IceInternal::InvocationObserver& __observer)
{
    ::IceInternal::Outgoing __og(__handler.get(), __Message__Monitor__publish2_name, ::Ice::Normal, __context, __observer);
    try
    {
        ::IceInternal::BasicStream* __os = __og.startWriteParams(::Ice::DefaultFormat);
        __os->write(m);
        __og.endWriteParams();
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    if(__og.hasResponse())
    {
        try
        {
            if(!__ok)
            {
                try
                {
                    __og.throwUserException();
                }
                catch(const ::Ice::UserException& __ex)
                {
                    ::Ice::UnknownUserException __uue(__FILE__, __LINE__, __ex.ice_name());
                    throw __uue;
                }
            }
            __og.readEmptyParams();
        }
        catch(const ::Ice::LocalException& __ex)
        {
            throw ::IceInternal::LocalExceptionWrapper(__ex, false);
        }
    }
}

void
IceDelegateD::Message::Monitor::publish2(const ::Message::Num& m, const ::Ice::Context* __context, ::IceInternal::InvocationObserver&)
{
    class _DirectI : public ::IceInternal::Direct
    {
    public:

        _DirectI(const ::Message::Num& __p_m, const ::Ice::Current& __current) : 
            ::IceInternal::Direct(__current),
            _m_m(__p_m)
        {
        }
        
        virtual ::Ice::DispatchStatus
        run(::Ice::Object* object)
        {
            ::Message::Monitor* servant = dynamic_cast< ::Message::Monitor*>(object);
            if(!servant)
            {
                throw ::Ice::OperationNotExistException(__FILE__, __LINE__, _current.id, _current.facet, _current.operation);
            }
            servant->publish2(_m_m, _current);
            return ::Ice::DispatchOK;
        }
        
    private:
        
        const ::Message::Num& _m_m;
    };
    
    ::Ice::Current __current;
    __initCurrent(__current, __Message__Monitor__publish2_name, ::Ice::Normal, __context);
    try
    {
        _DirectI __direct(m, __current);
        try
        {
            __direct.getServant()->__collocDispatch(__direct);
        }
        catch(...)
        {
            __direct.destroy();
            throw;
        }
        __direct.destroy();
    }
    catch(const ::Ice::SystemException&)
    {
        throw;
    }
    catch(const ::IceInternal::LocalExceptionWrapper&)
    {
        throw;
    }
    catch(const ::std::exception& __ex)
    {
        ::IceInternal::LocalExceptionWrapper::throwWrapper(__ex);
    }
    catch(...)
    {
        throw ::IceInternal::LocalExceptionWrapper(::Ice::UnknownException(__FILE__, __LINE__, "unknown c++ exception"), false);
    }
}

::Ice::Object* Message::upCast(::Message::Monitor* p) { return p; }

namespace
{
const ::std::string __Message__Monitor_ids[2] =
{
    "::Ice::Object",
    "::Message::Monitor"
};

}

bool
Message::Monitor::ice_isA(const ::std::string& _s, const ::Ice::Current&) const
{
    return ::std::binary_search(__Message__Monitor_ids, __Message__Monitor_ids + 2, _s);
}

::std::vector< ::std::string>
Message::Monitor::ice_ids(const ::Ice::Current&) const
{
    return ::std::vector< ::std::string>(&__Message__Monitor_ids[0], &__Message__Monitor_ids[2]);
}

const ::std::string&
Message::Monitor::ice_id(const ::Ice::Current&) const
{
    return __Message__Monitor_ids[1];
}

const ::std::string&
Message::Monitor::ice_staticId()
{
    return __Message__Monitor_ids[1];
}

::Ice::DispatchStatus
Message::Monitor::___publish2(::IceInternal::Incoming& __inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.startReadParams();
    ::Message::Num m;
    __is->read(m);
    __inS.endReadParams();
    publish2(m, __current);
    __inS.__writeEmptyParams();
    return ::Ice::DispatchOK;
}

namespace
{
const ::std::string __Message__Monitor_all[] =
{
    "ice_id",
    "ice_ids",
    "ice_isA",
    "ice_ping",
    "publish2"
};

}

::Ice::DispatchStatus
Message::Monitor::__dispatch(::IceInternal::Incoming& in, const ::Ice::Current& current)
{
    ::std::pair< const ::std::string*, const ::std::string*> r = ::std::equal_range(__Message__Monitor_all, __Message__Monitor_all + 5, current.operation);
    if(r.first == r.second)
    {
        throw ::Ice::OperationNotExistException(__FILE__, __LINE__, current.id, current.facet, current.operation);
    }

    switch(r.first - __Message__Monitor_all)
    {
        case 0:
        {
            return ___ice_id(in, current);
        }
        case 1:
        {
            return ___ice_ids(in, current);
        }
        case 2:
        {
            return ___ice_isA(in, current);
        }
        case 3:
        {
            return ___ice_ping(in, current);
        }
        case 4:
        {
            return ___publish2(in, current);
        }
    }

    assert(false);
    throw ::Ice::OperationNotExistException(__FILE__, __LINE__, current.id, current.facet, current.operation);
}

void
Message::Monitor::__writeImpl(::IceInternal::BasicStream* __os) const
{
    __os->startWriteSlice(ice_staticId(), -1, true);
    __os->endWriteSlice();
}

void
Message::Monitor::__readImpl(::IceInternal::BasicStream* __is)
{
    __is->startReadSlice();
    __is->endReadSlice();
}

void 
Message::__patch(MonitorPtr& handle, const ::Ice::ObjectPtr& v)
{
    handle = ::Message::MonitorPtr::dynamicCast(v);
    if(v && !handle)
    {
        IceInternal::Ex::throwUOE(::Message::Monitor::ice_staticId(), v);
    }
}
