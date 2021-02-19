#include <vmix/taskio/detail/task.hpp>
#include <vmix/taskio/task.hpp>

namespace vmix::taskio {

task::task() : impl_(new detail::task{.id = -1}) {}

task::task(std::unique_ptr<detail::task>&& other) : impl_(std::move(other)) {}

task::~task() noexcept = default;

task::task(const task& other) : impl_(new detail::task(*other.impl_)) {}

task& task::operator=(const task& other) {
  if (this != std::addressof(other)) {
    task tmp(other);
    impl_.swap(tmp.impl_);
  }

  return *this;
}

task::task(task&& other) noexcept = default;
task& task::operator=(task&& other) noexcept = default;

bool task::operator==(const task& other) const noexcept {
  return impl_->id == other.impl_->id;
}

bool task::operator!=(const task& other) const noexcept {
  return impl_->id != other.impl_->id;
}

int task::id() const noexcept {
  return impl_->id;
}

void task::id(int nid) noexcept {
  impl_->id = nid;
}

std::string_view task::title() const noexcept {
  return std::string_view(impl_->title);
}

void task::title(std::string_view title) {
  impl_->title = title;
}

std::string_view task::description() const noexcept {
  return std::string_view(impl_->description);
}

void task::description(std::string_view description) {
  impl_->description = description;
}

std::string_view task::time() const noexcept {
  return impl_->time;
}

void task::time(std::string_view time) {
  impl_->time = time;
}

bool task::completed() const noexcept {
  return impl_->completed;
}
void task::completed(bool completed) noexcept {
  impl_->completed = completed;
}

bool task::important() const noexcept {
  return impl_->important;
}

void task::important(bool important) noexcept {
  impl_->important = important;
}

}  // namespace vmix::taskio
