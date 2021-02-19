#ifndef VMIX_TASKIO_VERSION_HPP
#define VMIX_TASKIO_VERSION_HPP

#include <vmix/taskio/export.hpp>

#define VMIX_TASKIO_VERSION_MAJOR 1
#define VMIX_TASKIO_VERSION_MINOR 0
#define VMIX_TASKIO_VERSION_MICRO 0

namespace vmix::taskio {

VMIX_TASKIO_EXPORT int version_major() noexcept;
VMIX_TASKIO_EXPORT int version_minor() noexcept;
VMIX_TASKIO_EXPORT int version_micro() noexcept;

}  // namespace vmix::taskio

#endif  // V_MIX_TASKMGR_VERSION_HPP
