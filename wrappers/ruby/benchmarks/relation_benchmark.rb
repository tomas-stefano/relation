bench_dir = File.expand_path(File.dirname(__FILE__))
$LOAD_PATH.unshift(File.join( bench_dir, '..', 'lib'))

require 'benchmark'
require 'relation'

@creation_number = 10_000_000
report = "#{@creation_number} times"

# Stupid benchmarking (I'll begin to start more seriously benchs when the wraper is growing )
Benchmark.benchmark do |x|
  x.report("Create Relation Table #{report}\n") do
    @creation_number.times do
      Relation::Table.new('users')
    end
  end
end