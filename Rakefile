
TEST_EXECUTABLE = 'sql_relation_test_suite'
BENCHMARK_EXECUTABLE = 'benchmarks/relation-benchmark'

SOURCE = FileList['source/*.c', 'source/*/*.c', 'source/*/*/*.c']
OBJECT_SOURCE = SOURCE.ext('o')

TEST_UNITS_SOURCE = FileList['tests/*.c', 'tests/*/*.c', 'tests/*/*/*.c']
OBJECT_TEST_UNITS_SOURCE = TEST_UNITS_SOURCE.ext('o')

FLAGS = "-Wall -Wextra -g -I source/lib -I tests -I source"

module Color
  def self.green
    "\033[0;32m"
  end

  def self.red
    "\033[0;31m"
  end

  def self.yellow
    "\033[0;33m"
  end
  
  def self.light_blue
    "\033[0;36m"    
  end
  
  def self.no_color
    "\e[0m"
  end  
end

module RelationTasks

  def compile(files, options={})
    return if files.empty?
    directory = options[:dir]
    extra_options = options[:extra_options]
    files.each do |source_file|
      object_file = source_file.ext('o')
      print Color.light_blue
      sh "cc #{FLAGS} #{extra_options} -c -o #{object_file} #{source_file}"
      print Color.no_color
    end
  end
end

namespace :compile do
  desc 'Compile source files'
  task :source do
    include RelationTasks
    files = [ENV["FILE"]].compact
    files = files.empty? ? SOURCE : files
    compile(files, :dir => 'source')
  end
  
  desc 'Compile test files'
  task :tests => :source do
    include RelationTasks
    files = [ENV["TEST_FILE"]].compact
    files = files.empty? ? TEST_UNITS_SOURCE : files    
    compile(files, :dir => 'tests')
  end
end

task :compile_tests do
  sh "cc #{FLAGS} #{OBJECT_TEST_UNITS_SOURCE} #{OBJECT_SOURCE} -lcgreen -o #{TEST_EXECUTABLE}"
end

task :call_executable do
  sh "./#{TEST_EXECUTABLE}"
end

def fail?
  $!
end

def run_tests
  print Color.light_blue
  Rake::Task["compile_tests"].invoke
  output = (Color.green + ('=' * 20) + ' Running Tests ' + ("="*20) + Color.no_color)
  puts
  puts output
  puts
  Rake::Task["call_executable"].invoke
end

desc 'Run all Test Suite'
file :test => 'compile:tests' do
  begin
    run_tests
  ensure
    verbose(false) # Set rake to false
    output = ('=' * 20) + ' Done ' + ("=" * 29) + Color.no_color
    if fail? 
      puts Color.red + output
    else
      puts Color.green + output
    end
    puts
    puts
  end
end

require 'rake/clean'
CLEAN.include('tests/*.o', 
              'tests/*/*.o',
              'tests/*/*/*.o',
              'source/*.o', '*.o',
              'source/*/*.o', 'source/*/*/*.o'
              )

CLOBBER.include(TEST_EXECUTABLE, BENCHMARK_EXECUTABLE);

task :default => :test