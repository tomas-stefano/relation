
TEST_EXECUTABLE = 'sql_relation_test_suite'

SOURCE = FileList['source/*.c']
OBJECT_SOURCE = SOURCE.ext('o')

TEST_UNITS_SOURCE = FileList['tests/*/*.c', 'tests/*.c']
OBJECT_TEST_UNITS_SOURCE = TEST_UNITS_SOURCE.ext('o')

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

  def compile(files, options={}, extra_options='')
    return if files.empty?
    directory = options[:dir]
    files.each do |source_file|
      object_file = source_file.ext('o')
      print Color.light_blue
      sh "cc -g -Wall -I source -c -o #{object_file} #{source_file}"
      print Color.no_color
    end
  end
  
  def compile_source
    compile(SOURCE, :dir => 'source')
  end
  
  def compile_tests
    compile(TEST_UNITS_SOURCE, :dir => 'tests')
  end  
end

namespace :compile do
  desc 'Compile source files'
  task :source do
    include RelationTasks
    compile_source
  end
  
  desc 'Compile test files'
  task :tests => :source do
    include RelationTasks
    compile_tests
  end
end

task :compile_tests do
  sh "cc -Wall -g #{OBJECT_TEST_UNITS_SOURCE} #{OBJECT_SOURCE} -lcgreen -o #{TEST_EXECUTABLE}"
end

task :call_executable do
  sh "./#{TEST_EXECUTABLE}"
end

desc 'Run all Test Suite'
file :test => 'compile:tests' do
  begin
    print Color.light_blue
    Rake::Task["compile_tests"].invoke
    puts
    puts (Color.green + ('=' * 20) + ' Running Tests ' + ("="*20) + Color.no_color)
    puts
    Rake::Task["call_executable"].invoke
  ensure
    puts
    puts (Color.green + ('=' * 20) + ' Done ' + ("=" * 29) + Color.no_color)    
    puts
    puts    
    Rake::Task['clean'].invoke
    Rake::Task['clobber'].invoke
  end
end

require 'rake/clean'
CLEAN.include('tests/*.o', 
              'tests/*/*.o',
              'source/*.o', '*.o'
              )
CLOBBER.include(TEST_EXECUTABLE)

task :default => :test