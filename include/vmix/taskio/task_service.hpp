#ifndef VMIX_TASKIO_TASK_SERVICE_HPP
#define VMIX_TASKIO_TASK_SERVICE_HPP

#include <vmix/taskio/task.hpp>

#include <vector>

namespace vmix::taskio {

class task_storage;

class VMIX_TASKIO_EXPORT task_service final {
 public:
  task_service() = delete;
  task_service(std::unique_ptr<task_storage>&&);
  ~task_service() noexcept;

  task_service(const task_service&) = delete;
  task_service& operator=(const task_service&) = delete;

  task_service(task_service&&) = delete;
  task_service& operator=(task_service&&) = delete;

  task create();
  void update(const task&);
  void remove(int id);
  inline void remove(const task& t) { return remove(t.id()); }
  task find(int id);

  std::vector<task> all();

 private:
  std::unique_ptr<task_storage> storage_;
};

}  // namespace vmix::taskio

#endif  // VMIX_TASKIO_TASK_HPP
