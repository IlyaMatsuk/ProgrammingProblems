#pragma once
#include <list>

template<typename Fn, typename T>
auto Test(Fn fn, T data_list){
  TimeMeter time_meter;
  std::list<size_t> time_measurements;
  for(const auto& data : data_list){
    time_meter.Start();
    fn(data);
    time_meter.Stop();
    time_measurements.push_back(time_meter.GetValue());
  }
  return Average(time_measurements);
}