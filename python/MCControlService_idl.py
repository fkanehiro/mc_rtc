# Python stubs generated by omniidl from ../idl/MCControlService.idl

import omniORB, _omnipy
from omniORB import CORBA, PortableServer
_0_CORBA = CORBA

_omnipy.checkVersion(3,0, __file__)


#
# Start of module "OpenHRP"
#
__name__ = "OpenHRP"
_0_OpenHRP = omniORB.openModule("OpenHRP", r"../idl/MCControlService.idl")
_0_OpenHRP__POA = omniORB.openModule("OpenHRP__POA", r"../idl/MCControlService.idl")


# interface MCControlService
_0_OpenHRP._d_MCControlService = (omniORB.tcInternal.tv_objref, "IDL:OpenHRP/MCControlService:1.0", "MCControlService")
omniORB.typeMapping["IDL:OpenHRP/MCControlService:1.0"] = _0_OpenHRP._d_MCControlService
_0_OpenHRP.MCControlService = omniORB.newEmptyClass()
class MCControlService :
    _NP_RepositoryId = _0_OpenHRP._d_MCControlService[1]

    def __init__(self, *args, **kw):
        raise RuntimeError("Cannot construct objects of this type.")

    _nil = CORBA.Object._nil


_0_OpenHRP.MCControlService = MCControlService
_0_OpenHRP._tc_MCControlService = omniORB.tcInternal.createTypeCode(_0_OpenHRP._d_MCControlService)
omniORB.registerType(MCControlService._NP_RepositoryId, _0_OpenHRP._d_MCControlService, _0_OpenHRP._tc_MCControlService)

# MCControlService operations and attributes
MCControlService._d_EnablePostureController = ((), (omniORB.tcInternal.tv_boolean, ), None)
MCControlService._d_change_joint = (((omniORB.tcInternal.tv_string,0), ), (omniORB.tcInternal.tv_boolean, ), None)
MCControlService._d_joint_up = ((), (omniORB.tcInternal.tv_boolean, ), None)
MCControlService._d_joint_down = ((), (omniORB.tcInternal.tv_boolean, ), None)
MCControlService._d_set_joint_pos = (((omniORB.tcInternal.tv_string,0), omniORB.tcInternal.tv_double), (omniORB.tcInternal.tv_boolean, ), None)

# MCControlService object reference
class _objref_MCControlService (CORBA.Object):
    _NP_RepositoryId = MCControlService._NP_RepositoryId

    def __init__(self):
        CORBA.Object.__init__(self)

    def EnablePostureController(self, *args):
        return _omnipy.invoke(self, "EnablePostureController", _0_OpenHRP.MCControlService._d_EnablePostureController, args)

    def change_joint(self, *args):
        return _omnipy.invoke(self, "change_joint", _0_OpenHRP.MCControlService._d_change_joint, args)

    def joint_up(self, *args):
        return _omnipy.invoke(self, "joint_up", _0_OpenHRP.MCControlService._d_joint_up, args)

    def joint_down(self, *args):
        return _omnipy.invoke(self, "joint_down", _0_OpenHRP.MCControlService._d_joint_down, args)

    def set_joint_pos(self, *args):
        return _omnipy.invoke(self, "set_joint_pos", _0_OpenHRP.MCControlService._d_set_joint_pos, args)

    __methods__ = ["EnablePostureController", "change_joint", "joint_up", "joint_down", "set_joint_pos"] + CORBA.Object.__methods__

omniORB.registerObjref(MCControlService._NP_RepositoryId, _objref_MCControlService)
_0_OpenHRP._objref_MCControlService = _objref_MCControlService
del MCControlService, _objref_MCControlService

# MCControlService skeleton
__name__ = "OpenHRP__POA"
class MCControlService (PortableServer.Servant):
    _NP_RepositoryId = _0_OpenHRP.MCControlService._NP_RepositoryId


    _omni_op_d = {"EnablePostureController": _0_OpenHRP.MCControlService._d_EnablePostureController, "change_joint": _0_OpenHRP.MCControlService._d_change_joint, "joint_up": _0_OpenHRP.MCControlService._d_joint_up, "joint_down": _0_OpenHRP.MCControlService._d_joint_down, "set_joint_pos": _0_OpenHRP.MCControlService._d_set_joint_pos}

MCControlService._omni_skeleton = MCControlService
_0_OpenHRP__POA.MCControlService = MCControlService
omniORB.registerSkeleton(MCControlService._NP_RepositoryId, MCControlService)
del MCControlService
__name__ = "OpenHRP"

#
# End of module "OpenHRP"
#
__name__ = "MCControlService_idl"

_exported_modules = ( "OpenHRP", )

# The end.
