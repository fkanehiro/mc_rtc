// This file is generated by omniidl (C++ backend)- omniORB_4_1. Do not edit.

#include "MCControlService.hh"
#include <omniORB4/IOP_S.h>
#include <omniORB4/IOP_C.h>
#include <omniORB4/callDescriptor.h>
#include <omniORB4/callHandle.h>
#include <omniORB4/objTracker.h>


OMNI_USING_NAMESPACE(omni)

static const char* _0RL_library_version = omniORB_4_1;



OpenHRP::MCControlService_ptr OpenHRP::MCControlService_Helper::_nil() {
  return ::OpenHRP::MCControlService::_nil();
}

::CORBA::Boolean OpenHRP::MCControlService_Helper::is_nil(::OpenHRP::MCControlService_ptr p) {
  return ::CORBA::is_nil(p);

}

void OpenHRP::MCControlService_Helper::release(::OpenHRP::MCControlService_ptr p) {
  ::CORBA::release(p);
}

void OpenHRP::MCControlService_Helper::marshalObjRef(::OpenHRP::MCControlService_ptr obj, cdrStream& s) {
  ::OpenHRP::MCControlService::_marshalObjRef(obj, s);
}

OpenHRP::MCControlService_ptr OpenHRP::MCControlService_Helper::unmarshalObjRef(cdrStream& s) {
  return ::OpenHRP::MCControlService::_unmarshalObjRef(s);
}

void OpenHRP::MCControlService_Helper::duplicate(::OpenHRP::MCControlService_ptr obj) {
  if( obj && !obj->_NP_is_nil() )  omni::duplicateObjRef(obj);
}

OpenHRP::MCControlService_ptr
OpenHRP::MCControlService::_duplicate(::OpenHRP::MCControlService_ptr obj)
{
  if( obj && !obj->_NP_is_nil() )  omni::duplicateObjRef(obj);
  return obj;
}

OpenHRP::MCControlService_ptr
OpenHRP::MCControlService::_narrow(::CORBA::Object_ptr obj)
{
  if( !obj || obj->_NP_is_nil() || obj->_NP_is_pseudo() ) return _nil();
  _ptr_type e = (_ptr_type) obj->_PR_getobj()->_realNarrow(_PD_repoId);
  return e ? e : _nil();
}


OpenHRP::MCControlService_ptr
OpenHRP::MCControlService::_unchecked_narrow(::CORBA::Object_ptr obj)
{
  if( !obj || obj->_NP_is_nil() || obj->_NP_is_pseudo() ) return _nil();
  _ptr_type e = (_ptr_type) obj->_PR_getobj()->_uncheckedNarrow(_PD_repoId);
  return e ? e : _nil();
}

OpenHRP::MCControlService_ptr
OpenHRP::MCControlService::_nil()
{
#ifdef OMNI_UNLOADABLE_STUBS
  static _objref_MCControlService _the_nil_obj;
  return &_the_nil_obj;
#else
  static _objref_MCControlService* _the_nil_ptr = 0;
  if( !_the_nil_ptr ) {
    omni::nilRefLock().lock();
    if( !_the_nil_ptr ) {
      _the_nil_ptr = new _objref_MCControlService;
      registerNilCorbaObject(_the_nil_ptr);
    }
    omni::nilRefLock().unlock();
  }
  return _the_nil_ptr;
#endif
}

const char* OpenHRP::MCControlService::_PD_repoId = "IDL:OpenHRP/MCControlService:1.0";


OpenHRP::_objref_MCControlService::~_objref_MCControlService() {
  
}


OpenHRP::_objref_MCControlService::_objref_MCControlService(omniIOR* ior, omniIdentity* id) :
   omniObjRef(::OpenHRP::MCControlService::_PD_repoId, ior, id, 1)
   
   
{
  _PR_setobj(this);
}

void*
OpenHRP::_objref_MCControlService::_ptrToObjRef(const char* id)
{
  if( id == ::OpenHRP::MCControlService::_PD_repoId )
    return (::OpenHRP::MCControlService_ptr) this;
  
  if( id == ::CORBA::Object::_PD_repoId )
    return (::CORBA::Object_ptr) this;

  if( omni::strMatch(id, ::OpenHRP::MCControlService::_PD_repoId) )
    return (::OpenHRP::MCControlService_ptr) this;
  
  if( omni::strMatch(id, ::CORBA::Object::_PD_repoId) )
    return (::CORBA::Object_ptr) this;

  return 0;
}

// Proxy call descriptor class. Mangled signature:
//  _cboolean
class _0RL_cd_893794e416423500_00000000
  : public omniCallDescriptor
{
public:
  inline _0RL_cd_893794e416423500_00000000(LocalCallFn lcfn,const char* op_,size_t oplen,_CORBA_Boolean upcall=0):
     omniCallDescriptor(lcfn, op_, oplen, 0, _user_exns, 0, upcall)
  {
    
  }
  
  
  void unmarshalReturnedValues(cdrStream&);
  void marshalReturnedValues(cdrStream&);
  
  
  static const char* const _user_exns[];

  ::CORBA::Boolean result;
};

void _0RL_cd_893794e416423500_00000000::marshalReturnedValues(cdrStream& _n)
{
  _n.marshalBoolean(result);

}

void _0RL_cd_893794e416423500_00000000::unmarshalReturnedValues(cdrStream& _n)
{
  result = _n.unmarshalBoolean();

}

const char* const _0RL_cd_893794e416423500_00000000::_user_exns[] = {
  0
};

// Local call call-back function.
static void
_0RL_lcfn_893794e416423500_10000000(omniCallDescriptor* cd, omniServant* svnt)
{
  _0RL_cd_893794e416423500_00000000* tcd = (_0RL_cd_893794e416423500_00000000*)cd;
  OpenHRP::_impl_MCControlService* impl = (OpenHRP::_impl_MCControlService*) svnt->_ptrToInterface(OpenHRP::MCControlService::_PD_repoId);
  tcd->result = impl->EnablePostureController();


}

::CORBA::Boolean OpenHRP::_objref_MCControlService::EnablePostureController()
{
  _0RL_cd_893794e416423500_00000000 _call_desc(_0RL_lcfn_893794e416423500_10000000, "EnablePostureController", 24);


  _invoke(_call_desc);
  return _call_desc.result;


}
// Proxy call descriptor class. Mangled signature:
//  _cboolean_i_cstring
class _0RL_cd_893794e416423500_20000000
  : public omniCallDescriptor
{
public:
  inline _0RL_cd_893794e416423500_20000000(LocalCallFn lcfn,const char* op_,size_t oplen,_CORBA_Boolean upcall=0):
     omniCallDescriptor(lcfn, op_, oplen, 0, _user_exns, 0, upcall)
  {
    
  }
  
  void marshalArguments(cdrStream&);
  void unmarshalArguments(cdrStream&);

  void unmarshalReturnedValues(cdrStream&);
  void marshalReturnedValues(cdrStream&);
  
  
  static const char* const _user_exns[];

  ::CORBA::String_var arg_0_;
  const char* arg_0;
  ::CORBA::Boolean result;
};

void _0RL_cd_893794e416423500_20000000::marshalArguments(cdrStream& _n)
{
  _n.marshalString(arg_0,0);

}

void _0RL_cd_893794e416423500_20000000::unmarshalArguments(cdrStream& _n)
{
  arg_0_ = _n.unmarshalString(0);
  arg_0 = arg_0_.in();

}

void _0RL_cd_893794e416423500_20000000::marshalReturnedValues(cdrStream& _n)
{
  _n.marshalBoolean(result);

}

void _0RL_cd_893794e416423500_20000000::unmarshalReturnedValues(cdrStream& _n)
{
  result = _n.unmarshalBoolean();

}

const char* const _0RL_cd_893794e416423500_20000000::_user_exns[] = {
  0
};

// Local call call-back function.
static void
_0RL_lcfn_893794e416423500_30000000(omniCallDescriptor* cd, omniServant* svnt)
{
  _0RL_cd_893794e416423500_20000000* tcd = (_0RL_cd_893794e416423500_20000000*)cd;
  OpenHRP::_impl_MCControlService* impl = (OpenHRP::_impl_MCControlService*) svnt->_ptrToInterface(OpenHRP::MCControlService::_PD_repoId);
  tcd->result = impl->change_joint(tcd->arg_0);


}

::CORBA::Boolean OpenHRP::_objref_MCControlService::change_joint(const char* jname)
{
  _0RL_cd_893794e416423500_20000000 _call_desc(_0RL_lcfn_893794e416423500_30000000, "change_joint", 13);
  _call_desc.arg_0 = jname;

  _invoke(_call_desc);
  return _call_desc.result;


}
// Local call call-back function.
static void
_0RL_lcfn_893794e416423500_40000000(omniCallDescriptor* cd, omniServant* svnt)
{
  _0RL_cd_893794e416423500_00000000* tcd = (_0RL_cd_893794e416423500_00000000*)cd;
  OpenHRP::_impl_MCControlService* impl = (OpenHRP::_impl_MCControlService*) svnt->_ptrToInterface(OpenHRP::MCControlService::_PD_repoId);
  tcd->result = impl->joint_up();


}

::CORBA::Boolean OpenHRP::_objref_MCControlService::joint_up()
{
  _0RL_cd_893794e416423500_00000000 _call_desc(_0RL_lcfn_893794e416423500_40000000, "joint_up", 9);


  _invoke(_call_desc);
  return _call_desc.result;


}
// Local call call-back function.
static void
_0RL_lcfn_893794e416423500_50000000(omniCallDescriptor* cd, omniServant* svnt)
{
  _0RL_cd_893794e416423500_00000000* tcd = (_0RL_cd_893794e416423500_00000000*)cd;
  OpenHRP::_impl_MCControlService* impl = (OpenHRP::_impl_MCControlService*) svnt->_ptrToInterface(OpenHRP::MCControlService::_PD_repoId);
  tcd->result = impl->joint_down();


}

::CORBA::Boolean OpenHRP::_objref_MCControlService::joint_down()
{
  _0RL_cd_893794e416423500_00000000 _call_desc(_0RL_lcfn_893794e416423500_50000000, "joint_down", 11);


  _invoke(_call_desc);
  return _call_desc.result;


}
// Proxy call descriptor class. Mangled signature:
//  _cboolean_i_cstring_i_cdouble
class _0RL_cd_893794e416423500_60000000
  : public omniCallDescriptor
{
public:
  inline _0RL_cd_893794e416423500_60000000(LocalCallFn lcfn,const char* op_,size_t oplen,_CORBA_Boolean upcall=0):
     omniCallDescriptor(lcfn, op_, oplen, 0, _user_exns, 0, upcall)
  {
    
  }
  
  void marshalArguments(cdrStream&);
  void unmarshalArguments(cdrStream&);

  void unmarshalReturnedValues(cdrStream&);
  void marshalReturnedValues(cdrStream&);
  
  
  static const char* const _user_exns[];

  ::CORBA::String_var arg_0_;
  const char* arg_0;
  ::CORBA::Double arg_1;
  ::CORBA::Boolean result;
};

void _0RL_cd_893794e416423500_60000000::marshalArguments(cdrStream& _n)
{
  _n.marshalString(arg_0,0);
  arg_1 >>= _n;

}

void _0RL_cd_893794e416423500_60000000::unmarshalArguments(cdrStream& _n)
{
  arg_0_ = _n.unmarshalString(0);
  arg_0 = arg_0_.in();
  (::CORBA::Double&)arg_1 <<= _n;

}

void _0RL_cd_893794e416423500_60000000::marshalReturnedValues(cdrStream& _n)
{
  _n.marshalBoolean(result);

}

void _0RL_cd_893794e416423500_60000000::unmarshalReturnedValues(cdrStream& _n)
{
  result = _n.unmarshalBoolean();

}

const char* const _0RL_cd_893794e416423500_60000000::_user_exns[] = {
  0
};

// Local call call-back function.
static void
_0RL_lcfn_893794e416423500_70000000(omniCallDescriptor* cd, omniServant* svnt)
{
  _0RL_cd_893794e416423500_60000000* tcd = (_0RL_cd_893794e416423500_60000000*)cd;
  OpenHRP::_impl_MCControlService* impl = (OpenHRP::_impl_MCControlService*) svnt->_ptrToInterface(OpenHRP::MCControlService::_PD_repoId);
  tcd->result = impl->set_joint_pos(tcd->arg_0, tcd->arg_1);


}

::CORBA::Boolean OpenHRP::_objref_MCControlService::set_joint_pos(const char* jname, ::CORBA::Double v)
{
  _0RL_cd_893794e416423500_60000000 _call_desc(_0RL_lcfn_893794e416423500_70000000, "set_joint_pos", 14);
  _call_desc.arg_0 = jname;
  _call_desc.arg_1 = v;

  _invoke(_call_desc);
  return _call_desc.result;


}
OpenHRP::_pof_MCControlService::~_pof_MCControlService() {}


omniObjRef*
OpenHRP::_pof_MCControlService::newObjRef(omniIOR* ior, omniIdentity* id)
{
  return new ::OpenHRP::_objref_MCControlService(ior, id);
}


::CORBA::Boolean
OpenHRP::_pof_MCControlService::is_a(const char* id) const
{
  if( omni::ptrStrMatch(id, ::OpenHRP::MCControlService::_PD_repoId) )
    return 1;
  
  return 0;
}

const OpenHRP::_pof_MCControlService _the_pof_OpenHRP_mMCControlService;

OpenHRP::_impl_MCControlService::~_impl_MCControlService() {}


::CORBA::Boolean
OpenHRP::_impl_MCControlService::_dispatch(omniCallHandle& _handle)
{
  const char* op = _handle.operation_name();

  if( omni::strMatch(op, "EnablePostureController") ) {

    _0RL_cd_893794e416423500_00000000 _call_desc(_0RL_lcfn_893794e416423500_10000000, "EnablePostureController", 24, 1);
    
    _handle.upcall(this,_call_desc);
    return 1;
  }

  if( omni::strMatch(op, "change_joint") ) {

    _0RL_cd_893794e416423500_20000000 _call_desc(_0RL_lcfn_893794e416423500_30000000, "change_joint", 13, 1);
    
    _handle.upcall(this,_call_desc);
    return 1;
  }

  if( omni::strMatch(op, "joint_up") ) {

    _0RL_cd_893794e416423500_00000000 _call_desc(_0RL_lcfn_893794e416423500_40000000, "joint_up", 9, 1);
    
    _handle.upcall(this,_call_desc);
    return 1;
  }

  if( omni::strMatch(op, "joint_down") ) {

    _0RL_cd_893794e416423500_00000000 _call_desc(_0RL_lcfn_893794e416423500_50000000, "joint_down", 11, 1);
    
    _handle.upcall(this,_call_desc);
    return 1;
  }

  if( omni::strMatch(op, "set_joint_pos") ) {

    _0RL_cd_893794e416423500_60000000 _call_desc(_0RL_lcfn_893794e416423500_70000000, "set_joint_pos", 14, 1);
    
    _handle.upcall(this,_call_desc);
    return 1;
  }


  return 0;
}

void*
OpenHRP::_impl_MCControlService::_ptrToInterface(const char* id)
{
  if( id == ::OpenHRP::MCControlService::_PD_repoId )
    return (::OpenHRP::_impl_MCControlService*) this;
  
  if( id == ::CORBA::Object::_PD_repoId )
    return (void*) 1;

  if( omni::strMatch(id, ::OpenHRP::MCControlService::_PD_repoId) )
    return (::OpenHRP::_impl_MCControlService*) this;
  
  if( omni::strMatch(id, ::CORBA::Object::_PD_repoId) )
    return (void*) 1;
  return 0;
}

const char*
OpenHRP::_impl_MCControlService::_mostDerivedRepoId()
{
  return ::OpenHRP::MCControlService::_PD_repoId;
}

POA_OpenHRP::MCControlService::~MCControlService() {}

