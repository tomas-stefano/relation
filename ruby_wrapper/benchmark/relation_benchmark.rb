bench_dir = File.expand_path(File.dirname(__FILE__))
$LOAD_PATH.unshift(File.join( bench_dir, '..', 'lib'))

require 'benchmark'
require 'relation'

@creation_number = 10_000_000
report = "#{@creation_number} times"

@table = Relation::Table.new('users')

def run(number=10_000_000)
  number.times do
    yield
  end
end

# Stupid benchmarking (I'll begin to start more seriously benchs when the wraper is growing )
Benchmark.benchmark do |x|
  x.report("10.000 Queries   ") do
    run(10_000) do
      @table.select('*').to_sql
    end
  end
  x.report("100.000 Queries  ") do
    run(100_000) do
      @table.select('*').to_sql
    end
  end
  x.report("1.000.000 Queries") do
    run(1_000_000) do
      @table.select('*').to_sql
    end
  end
end