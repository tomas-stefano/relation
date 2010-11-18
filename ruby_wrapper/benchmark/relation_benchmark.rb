bench_dir = File.expand_path(File.dirname(__FILE__))
$LOAD_PATH.unshift(File.join( bench_dir, '..', 'lib'))

require 'benchmark'
require 'relation'

@table = Relation::Table.new('users')

def simple_query!
  @table.select('*').limit(1).to_sql # SELECT * from users LIMIT 1
end

def run(number)
  number.times do
    yield
  end
end

# Little benchmarking (I'll begin to start more seriously benchs when the wrapper is growing )
Benchmark.benchmark do |x|
  x.report("10.000 Queries   ") do
    run(10_000) { simple_query! }
  end
  x.report("100.000 Queries  ") do
    run(100_000)  { simple_query! }
  end
  x.report("1.000.000 Queries") do
    run(1_000_000) { simple_query! }
  end
end

