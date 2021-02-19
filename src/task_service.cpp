#include <vmix/taskio/detail/task.hpp>
#include <vmix/taskio/task_service.hpp>
#include <vmix/taskio/task_storage.hpp>

namespace vmix::taskio {

task_service::task_service(std::unique_ptr<task_storage>&& storage)
    : storage_(std::move(storage)) {}
task_service::~task_service() noexcept = default;

task task_service::create() {
  return storage_->create();
}

void task_service::update(const task& t) {
  return storage_->update(t.impl_);
}

void task_service::remove(int id) {
  return storage_->remove(id);
}

task task_service::find(int id) {
  return storage_->find(id);
}

std::vector<task> task_service::all() {
  auto tasks_p = storage_->all();
  std::vector<task> tasks;
  tasks.reserve(tasks_p.size());

  for (auto&& tp : tasks_p) {
    tasks.emplace_back(task(std::move(tp)));
  }

  return tasks;
}

}  // namespace vmix::taskio
