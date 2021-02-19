#ifndef VMIX_TASKIO_TASK_HPP
#define VMIX_TASKIO_TASK_HPP

#include <vmix/taskio/export.hpp>

#include <memory>
#include <string_view>

namespace vmix::taskio {

namespace detail {
class task;
}

class task_service;

class VMIX_TASKIO_EXPORT task final {
 public:
  task();
  ~task() noexcept;

  task(const task&);
  task& operator=(const task&);

  task(task&&) noexcept;
  task& operator=(task&&) noexcept;

  bool operator==(const task&) const noexcept;
  bool operator!=(const task&) const noexcept;

  int id() const noexcept;
  void id(int id) noexcept;

  std::string_view title() const noexcept;
  void title(std::string_view);

  std::string_view description() const noexcept;
  void description(std::string_view);

  std::string_view time() const noexcept;
  void time(std::string_view);

  bool completed() const noexcept;
  void completed(bool) noexcept;

  bool important() const noexcept;
  void important(bool) noexcept;

 private:
  // task_service знает структуру в хранилище
  friend class task_service;
  task(std::unique_ptr<detail::task>&&);

 private:
  // Простой вариант pimpl
  std::unique_ptr<detail::task> impl_;
};

}  // namespace vmix::taskio

#endif  // VMIX_TASKIO_TASK_HPP
