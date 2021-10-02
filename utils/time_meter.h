#include <chrono>

class TimeMeter {
 public:
  void Start() {
    start_time_ = std::chrono::high_resolution_clock::now();
  }
  void Stop() {
    stop_time_ = std::chrono::high_resolution_clock::now();
    value_ = std::chrono::duration_cast<std::chrono::nanoseconds>(stop_time_ - start_time_).count();
  }
  size_t GetValue() const {
    return value_;
  }

 private:
  std::chrono::_V2::system_clock::time_point start_time_;
  std::chrono::_V2::system_clock::time_point stop_time_;
  size_t value_ = 0;
};

template <typename T>
auto Average(T container) {
  auto sum = 0.0;
  for(const auto& item : container)
    sum += item;
  return sum / container.size();
}