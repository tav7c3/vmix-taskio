#ifndef VMIX_TASKIO_TASK_STORAGE_HPP
#define VMIX_TASKIO_TASK_STORAGE_HPP

#include <vmix/taskio/export.hpp>

#include <functional>
#include <map>
#include <memory>
#include <vector>

namespace vmix::taskio {

namespace detail {
class task;
}

class task_storage {
 public:
  virtual ~task_storage() = default;
  virtual std::unique_ptr<detail::task> create() = 0;
  virtual void update(const std::unique_ptr<detail::task>&) = 0;
  virtual void remove(int) = 0;
  virtual std::unique_ptr<detail::task> find(int) = 0;
  virtual std::vector<std::unique_ptr<detail::task>> all() = 0;
};

class VMIX_TASKIO_EXPORT task_storage_registry {
 public:
  task_storage_registry(const task_storage_registry&) = delete;
  task_storage_registry& operator=(const task_storage_registry&) = delete;
  task_storage_registry& operator=(task_storage_registry&&) = delete;

  task_storage_registry(task_storage_registry&&) = delete;
  static task_storage_registry& instance() noexcept;

  std::unique_ptr<task_storage> make_storage(std::string_view);

 private:
  task_storage_registry();
  ~task_storage_registry() = default;

  std::map<std::string, std::function<std::unique_ptr<task_storage>()>>
      factories_;
};

}  // namespace vmix::taskio

#endif  // VMIX_TASKIO_TASK_HPP
