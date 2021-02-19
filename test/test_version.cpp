#include <vmix/taskio/version.hpp>

#include <catch2/catch.hpp>

TEST_CASE("vmix/taskio/version") {
  CHECK(VMIX_TASKIO_VERSION_MAJOR == vmix::taskio::version_major());
  CHECK(VMIX_TASKIO_VERSION_MINOR == vmix::taskio::version_minor());
  CHECK(VMIX_TASKIO_VERSION_MICRO == vmix::taskio::version_micro());
}
