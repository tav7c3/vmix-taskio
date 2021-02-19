#include <vmix/taskio/task_storage.hpp>

#include <vmix/taskio/detail/in_memory_task_storage.hpp>
#include <vmix/taskio/detail/sqlite_task_storage.hpp>

namespace vmix::taskio {

task_storage_registry::task_storage_registry() {
  factories_["mem"] = [] {
    return std::unique_ptr<task_storage>(new detail::in_memory_task_storage());
  };

  factories_["sqlite"] = [] {
    return std::unique_ptr<task_storage>(new detail::sqlite_task_storage());
  };
}

task_storage_registry& task_storage_registry::instance() noexcept {
  static task_storage_registry instance;
  return instance;
}

std::unique_ptr<task_storage> task_storage_registry::make_storage(
    std::string_view name) {
  return factories_[std::string(name)]();
}

}  // namespace vmix::taskio
