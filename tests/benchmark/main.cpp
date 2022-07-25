#include <hayai/hayai.hpp>
#include <hayai/hayai_benchmarker.hpp>
#include <hayai/hayai_console_outputter.hpp>

int main() 
{
  hayai::ConsoleOutputter BenchmarkResults;

  hayai::Benchmarker::AddOutputter(BenchmarkResults);
   
  hayai::Benchmarker::RunAllTests();

  return 0;
}
