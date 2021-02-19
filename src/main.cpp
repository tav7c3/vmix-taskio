#include <vmix/taskio/version.hpp>

namespace vmix::taskio {

int version_major() noexcept {
  return VMIX_TASKIO_VERSION_MAJOR;
}
int version_minor() noexcept {
  return VMIX_TASKIO_VERSION_MINOR;
}
int version_micro() noexcept {
  return VMIX_TASKIO_VERSION_MICRO;
}

}  // namespace vmix::taskio
